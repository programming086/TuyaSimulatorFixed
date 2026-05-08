
#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>
#import "ThingSmartStreamDefines.h"

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, ThingSmartStreamConnectState) {
    ThingSmartStreamConnectStateIdle           = 0,
    ThingSmartStreamConnectStateConnecting     = 1,
    ThingSmartStreamConnectStateAuthing        = 2,
    ThingSmartStreamConnectStateConnected      = 3,
    ThingSmartStreamConnectStateClosedByServer = 4,
    ThingSmartStreamConnectStateClosed         = 5
};

typedef NS_ENUM(NSUInteger, ThingSmartStreamSessionState) {
    ThingSmartStreamSessionStateCreateSuccess = 0,
    ThingSmartStreamSessionStateCreateFail = 1,
    ThingSmartStreamSessionStateClosedByServer = 2,
    ThingSmartStreamSessionStateAgentTokenExpired = 3
};

typedef void(^ThingSmartStreamSessionCompletion)(ThingStreamSessionInfo * _Nullable result, NSError * _Nullable error);

@class ThingSmartStreamClient;
@protocol ThingSmartStreamClientDelegate <NSObject>
@optional

/// Connection connect state changed
/// - Parameters:
///   - client: stream client object
///   - connectState: connect state
///   - error: error info. when `connectState` == `ThingSmartStreamConnectStateClosedByServer`
- (void)streamClient:(ThingSmartStreamClient *)client
        connectState:(ThingSmartStreamConnectState)connectState
               error:(nullable NSError *)error;

/// Session state changed.
/// - Parameters:
///   - sessionID: session id
///   - sessionState: session state
///   - error: error info. when `connectState` != `ThingSmartStreamSessionStateCreateSuccess`
- (void)streamClientSessionId:(NSString *)sessionID
          changedSessionState:(ThingSmartStreamSessionState)sessionState
                        error:(nullable NSError *)error;

/// Receive video packet. (Not supported at present)
- (void)streamClientDidReceiveVideo:(ThingStreamVideoPacketModel *)packet;

/// Receive audio packet.
- (void)streamClientDidReceiveAudio:(ThingStreamAudioPacketModel *)packet;

/// Receive image packet. (Not supported at present)
- (void)streamClientDidReceiveImage:(ThingStreamImagePacketModel *)packet;

/// Receive file packet. (Not supported at present)
- (void)streamClientDidReceiveFile:(ThingStreamFilePacketModel *)packet;

/// Receive text packet.
- (void)streamClientDidReceiveText:(ThingStreamTextPacketModel *)packet;

/// Receive event packet.
- (void)streamClientDidReceiveEvent:(ThingStreamEventPacketModel *)packet;

/// Session closed by server. [Deprecated]
/// Note: If you implement `-streamClientSessionId:changedSessionState:code`, this method would not be called.
/// - Parameters:
///   - sessionID: session id
///   - code: close reason code
- (void)streamClientSessionDidClose:(NSString *)sessionID
                               code:(ThingStreamAttributeConnectionSessionCode)code __deprecated_msg("please use `-streamClientSessionId:changedSessionState:error:`");

/// debug metrics for eventId
- (void)streamClientMetrics:(NSDictionary *)metrics;
@end

@interface ThingSmartStreamClient : NSObject

@property (nonatomic, assign, readonly) ThingSmartStreamClientType clientType;
@property (atomic, assign, readonly) ThingSmartStreamConnectState state;
@property (nonatomic, strong, readonly) NSString *connectionID;
@property (nonatomic, strong, readonly) NSMutableDictionary<NSString *, ThingStreamSessionInfo *> *sessions;

/// The stream client for AgentDevice.
/// - Parameter devId: Device ID.
+ (nullable instancetype)clientForAgentDevice:(NSString *)devId;

/// The stream client for App
+ (instancetype)clientForApp;

/// The stream client for Industry
+ (instancetype)clientForDeveloper;

#pragma mark - Connection Establish & Close
/// Connect to stream server.
- (void)connect;

/// - Parameter success: calllback `connection id` when connection established.
- (void)connect:(ThingSuccessString)success;

/// Disconnect from stream server.
- (void)disconnect;

/// Destory the stream client. ( Only for AgentDevice client. )
- (void)destory;

/// Adds an Stream client delegate.
/// - Parameter delegate: Delegate
- (void)addDelegate:(id<ThingSmartStreamClientDelegate>)delegate;

/// Removes an Stream client delegate.
/// - Parameter delegate: Delegate
- (void)removeDelegate:(id<ThingSmartStreamClientDelegate>)delegate;

/// Check the connection is connected;
- (BOOL)isConnected;

#pragma mark - Session Establish & Close
/// Query AI agent token.
/// - Parameters:
///   - params: Query params obj.
///   - success: Success handler.
///   - failure: Fail handler.
- (void)queryAgentToken:(ThingStreamQueryAgentTokenParams *)params
                success:(void(^)(ThingStreamAgentTokenInfo *tokenResponse))success
                failure:(ThingFailureError)failure;

/// Creat a new session.
/// - Parameters:
///   - tokenInfo: Agent token info. (use `-queryAgentToken:success:failure:` to get token info)
///   - bizTag: Biz tag.
///   - reuseDataChannel: Reuse data channel. (Default is NO)
///   - sessionId: Session ID. If `sessionId` is nil, a new session will be created.
///   - cacheBasePath: Cache receive data path.
///   - userData: user data.(use JSON String)
///   - completion: Completion.
- (void)createSessionWithToken:(ThingStreamAgentTokenInfo *)token
                        bizTag:(uint64_t)bizTag
              reuseDataChannel:(BOOL)reuseDataChannel
                     sessionId:(nullable NSString *)sessionId
                 cacheBasePath:(nullable NSString *)cacheBasePath
                      userData:(nullable NSString *)userData
                    completion:(nullable ThingSmartStreamSessionCompletion)completion;

/// Query AI agent token and creat a new session.
/// - Parameters:
///   - params: Query params obj.
///   - reuseDataChannel: reuse data channel. (Default is NO)
///   - cacheBasePath: Cache receive data path. If `cacheBasePath` is nil, won't cache datas.
///   - userData: user data.(use JSON String)
///   - completion: Completion.
- (void)createSessionWithQueryParams:(ThingStreamQueryAgentTokenParams *)params
                    reuseDataChannel:(BOOL)reuseDataChannel
                       cacheBasePath:(nullable NSString *)cacheBasePath
                            userData:(nullable NSString *)userData
                          completion:(nullable ThingSmartStreamSessionCompletion)completion;

/// Close a session
/// - Parameters:
///   - sessionID: session id.
///   - code: close reason.
///   - completion: Completion.
- (void)closeSession:(NSString *)sessionID
            withCode:(ThingStreamAttributeConnectionSessionCode)code
          completion:(nullable ThingSmartStreamCompletion)completion;

/// Get all sessions.
- (NSDictionary<NSString *, ThingStreamSessionInfo *> *)getAllSessions;

/// Get session info for session id.
- (ThingStreamSessionInfo *)getSessionInfoForSessionId:(NSString *)sessionId;

#pragma mark - Packet
#pragma mark Send Video/Audio/Image/Text/File Packet
/// Send video packet.
/// - Parameters:
///   - videoModel: Video packet model.
///   - completion: completion.
- (void)sendVideoData:(ThingStreamVideoPacketModel *)packet completion:(nullable ThingSmartStreamCompletion)completion;

/// Send audio packet.
/// - Parameters:
///   - audioModel: Audio packet model.
///   - completion: completion.
- (void)sendAudioData:(ThingStreamAudioPacketModel *)packet completion:(nullable ThingSmartStreamCompletion)completion;

/// Send text packet.
/// - Parameters:
///   - textModel: text packet model.
///   - completion: completion.
- (void)sendTextData:(ThingStreamTextPacketModel *)packet completion:(nullable ThingSmartStreamCompletion)completion;

/// Send image packet.
/// - Parameters:
///   - imageModel: image packet model.
///   - completion: completion.
- (void)sendImageData:(ThingStreamImagePacketModel *)packet
             progress:(nullable void(^)(int progress))progress
           completion:(nullable ThingSmartStreamCompletion)completion;

/// Send file packet. (Not supported at present)
/// - Parameters:
///   - fileModel: file packet model.
///   - completion: completion.
- (void)sendFileData:(ThingStreamFilePacketModel *)packet
            progress:(nullable void(^)(int progress))progress
          completion:(nullable ThingSmartStreamCompletion)completion;

#pragma mark - Send Event Packet
/// Send event start.
/// - Parameters:
///   - sessionId: Session id.
///   - userData: user data.(use JSON String)
///   - successHandler: Success handler.
///   - failure: Failure handler.
- (void)sendEventStart:(NSString *)sessionId
              userData:(nullable NSString *)userData
               success:(nullable void(^)(NSString *eventId))successHandler
               failure:(nullable ThingFailureError)failure;

/// Send event start.
/// - Parameters:
///   - sessionId: Session id.
///   - eventId: Event id.
///   - userData: user data.(use JSON String)
///   - successHandler: Success handler.
///   - failure: Failure handler.
- (void)sendEventStart:(NSString *)sessionId
               eventId:(nullable NSString *)eventId
              userData:(nullable NSString *)userData
               success:(nullable void(^)(NSString *eventId))successHandler
               failure:(nullable ThingFailureError)failure;

/// Send event end.
/// - Parameters:
///   - eventId: Event ID. Same as event start
///   - sessionId: Session id.
///   - userData: user data.(use JSON String)
///   - completion: Completion.
- (void)sendEventEnd:(NSString *)eventId
           sessionId:(NSString *)sessionId
            userData:(nullable NSString *)userData
          completion:(nullable ThingSmartStreamCompletion)completion ;

/// Send event chat break.
/// Note: You can break either during sending or during receiving
/// - Parameters:
///   - eventId: Event ID. Same as event start
///   - sessionId: Session id.
///   - completion: Completion.
- (void)sendEventChatBreak:(NSString *)eventId
                 sessionId:(NSString *)sessionId
                completion:(nullable ThingSmartStreamCompletion)completion;

/// Send event packet.
/// - Parameters:
///   - packet: `EventStart/EventEnd/ChatBreak` packet model.
///   - completion: Completion.
- (void)sendEventPacket:(ThingStreamEventPacketModel *)packet
             completion:(nullable ThingSmartStreamCompletion)completion;

@end

@interface ThingSmartStreamClient (Deprecate)
/// Creat a new session. **(Deprecate)**
/// The userdata now use JSON string, please use `-createSessionWithQueryParams:reuseDataChannel:cacheBasePath:userData:completion:`. The API will be deleted in the future.
- (void)createSessionWithToken:(ThingStreamAgentTokenInfo *)token
                        bizTag:(uint64_t)bizTag
              reuseDataChannel:(BOOL)reuseDataChannel
                     sessionId:(nullable NSString *)sessionId
                 cacheBasePath:(nullable NSString *)cacheBasePath
                     userDatas:(nullable NSArray<ThingStreamAttribute *> *)userDatas
                    completion:(nullable ThingSmartStreamSessionCompletion)completion __deprecated_msg("Deprecated api, the userdata now use JSON string, please use `-createSessionWithToken:bizTag:reuseDataChannel:sessionId:cacheBasePath:userData:completion:`, The API will be deleted in the future.");

/// Query AI agent token and creat a new session. **(Deprecate)**
/// The userdata now use JSON string, please use `-createSessionWithQueryParams:reuseDataChannel:cacheBasePath:userData:completion:`. The API will be deleted in the future.
- (void)createSessionWithQueryParams:(ThingStreamQueryAgentTokenParams *)params
                    reuseDataChannel:(BOOL)reuseDataChannel
                       cacheBasePath:(nullable NSString *)cacheBasePath
                           userDatas:(nullable NSArray<ThingStreamAttribute *> *)userDatas
                          completion:(nullable ThingSmartStreamSessionCompletion)completion __deprecated_msg("Deprecated api, the userdata now use JSON string, please use `-createSessionWithQueryParams:reuseDataChannel:cacheBasePath:userData:completion:`. The API will be deleted in the future.");

/// Send event start. **(Deprecate)**
/// The userdata now use JSON string, please use `-sendEventStart:userData:success:failure:`. The API will be deleted in the future.
- (void)sendEventStart:(NSString *)sessionId
             userDatas:(nullable NSArray<ThingStreamAttribute *> *)userDatas
               success:(nullable void(^)(NSString *eventId))successHandler
               failure:(nullable ThingFailureError)failure __deprecated_msg("Deprecated api, the userdata now use JSON string, please use `-sendEventStart:userData:success:failure:`. The API will be deleted in the future.");

/// Send event start. **(Deprecate)**
/// The userdata now use JSON string, please use `-sendEventStart:eventId:userData:success:failure:`. The API will be deleted in the future.
- (void)sendEventStart:(NSString *)sessionId
               eventId:(nullable NSString *)eventId
             userDatas:(nullable NSArray<ThingStreamAttribute *> *)userDatas
               success:(nullable void(^)(NSString *eventId))successHandler
               failure:(nullable ThingFailureError)failure __deprecated_msg("Deprecated api, the userdata now use JSON string, please use `-sendEventStart:eventId:userData:success:failure:`. The API will be deleted in the future.");

/// Send event payloads end. **(Deprecate)**
/// This api no needs to be called, its always return success, you can remove it.
- (void)sendEventPayloadsEnd:(NSString *)eventId
                   sessionId:(NSString *)sessionId
                 dataChannel:(NSString *)dataChannel
                   userDatas:(nullable NSArray<ThingStreamAttribute *> *)userDatas
                  completion:(nullable ThingSmartStreamCompletion)completion __deprecated_msg("Deprecated api, this api no needs to be called, its always return success, you can remove it.");

/// Send event end. **(Deprecate)**
/// The userdata now use JSON string, please use `-sendEventEnd:sessionId:userData:completion:`. The API will be deleted in the future.
- (void)sendEventEnd:(NSString *)eventId
           sessionId:(NSString *)sessionId
           userDatas:(nullable NSArray<ThingStreamAttribute *> *)userDatas
          completion:(nullable ThingSmartStreamCompletion)completion __deprecated_msg("Deprecated api, the userdata now use JSON string, please use `-sendEventEnd:sessionId:userData:completion:`. The API will be deleted in the future.");
@end

NS_ASSUME_NONNULL_END
