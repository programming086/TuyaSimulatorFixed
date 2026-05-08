
#import <Foundation/Foundation.h>

FOUNDATION_EXTERN void MQTTSendBlcok(BOOL isLANMode, NSString *remoteId, NSString *signal);
FOUNDATION_EXTERN void httpRequest(NSString *api, NSString *devId, NSDictionary *postData);

typedef NS_ENUM(NSUInteger, ThingSmartP2pConnectMode) {
    ThingSmartP2pConnectModeInternet,
    ThingSmartP2pConnectModeLAN,
};

@class ThingSmartDeviceModel;
@interface ThingSmartP2pChannel : NSObject

@property (nonatomic, assign) NSInteger readDataTimeOut;
@property (nonatomic, assign) NSInteger sendDataTimeOut;

@property (nonatomic, copy, readonly) NSString *p2pVersion;
@property (nonatomic, copy, readonly) NSArray *detailErrorCodes;

+ (instancetype)sharedInstance;

///init configs, add msg observing
- (void)initSDKWithUid:(NSString *)uid;

///reset configs, remove msg observing
- (void)deInitSDK;
- (void)destroy __deprecated_msg("Use -[ThingSmartP2pChannel deInitSDK] instead");

///init P2P SDK, only call when login
- (void)initP2PSDKWithUid:(NSString *)uid;

///deInit P2P SDK, only call when logout
- (void)deInitP2PSDK;


/// create p2p channel new -- optimize error code
/// @param devId device id
/// @param mode connect mode
/// @param timeout timeout, set 0 will use default value, Lan Mode: 3000 ms, Internet Mode: 15000 ms
/// @param success success callback, and parameter is the p2p session handle
/// @param failure failure callback, Note: errCode -3 split info more error codes,eg:-33，-38，-39, -40 and so on.
/// @return trace id, break connecting must use trace id to specify p2p session
- (NSString *)connectWithDevId:(NSString *)devId mode:(ThingSmartP2pConnectMode)mode timeout:(NSInteger)timeout success:(void(^)(int p2pHandle))success failure:(void(^)(NSInteger errCode))failure;

/// create p2p channel
/// @param devId device id
/// @param mode connect mode
/// @param timeout timeout, set 0 will use default value, Lan Mode: 3000 ms, Internet Mode: 15000 ms
/// @param success success callback, and parameter is the p2p session handle
/// @param failure failure callback
/// @return trace id, break connecting must use trace id to specify p2p session
- (NSString *)connectWithDeviceId:(NSString *)devId mode:(ThingSmartP2pConnectMode)mode timeout:(NSInteger)timeout success:(void(^)(int p2pHandle))success failure:(void(^)(NSInteger errCode))failure;

/// create p2p channel【only support sweeper】
/// @param devId device id
/// @param mode connect mode
/// @param timeout timeout, set 0 will use default value, Lan Mode: 3000 ms, Internet Mode: 15000 ms
/// @param success success callback, and parameter is the p2p session handle
/// @param failure failure callback
/// @return trace id, break connecting must use trace id to specify p2p session
- (NSString *)sweeper_connectWithDeviceId:(NSString *)devId mode:(ThingSmartP2pConnectMode)mode timeout:(NSInteger)timeout success:(void(^)(int p2pHandle))success failure:(void(^)(NSInteger errCode))failure;

/// create p2p channel
/// @param devId device id
/// @param token p2p token
/// @param traceId trace id for link, and break a connecting session must use the trace id to specify the p2p session
/// @param mode connect mode
/// @param success connect success callback, and parameter is the p2p session handle
/// @param failure connect failure callback
/// @return trace id, if param `traceId` is nil, there well create one
- (NSString *)connectWithDeviceId:(NSString *)devId token:(NSString *)token traceId:(NSString *)traceId mode:(ThingSmartP2pConnectMode)mode success:(void(^)(int p2pHandle))success failure:(void(^)(NSError *))failure __deprecated_msg("Use connectWithDeviceId:mode:timeout:success:failure: instead");

/// break connecting session
/// @param traceId trace id
- (int)breakConnectWithTraceId:(NSString *)traceId;

/// disconnect p2p
/// @param handle p2p session handle
- (int)disconnectWithP2pHandle:(int)handle;

/// read data from p2p channel
/// @param handle p2p session handle
/// @param channel p2p channel
/// @param buffer buffer ponter
/// @return the length of read data. if -0, means error. -3 is timeout, and others means session did disconnected
- (int)readDataWithP2pHandle:(int)handle channel:(int)channel buffer:(unsigned char*)buffer;

/// read data from p2p channel
/// @param handle p2p session handle
/// @param channel p2p channel
/// @param buffer buffer ponter
/// @return the length of read data. if -0, means error. -3 is timeout, and others means session did disconnected
- (int)readDataWithP2pHandle:(int)handle channel:(int)channel buffer:(unsigned char*)buffer timeout:(int)timeout;


/// send data by p2p channel
/// @param handle p2p session handle
/// @param channel p2p channel
/// @param buffer buffer pointer
/// @param len length of buffer
/// @return the length of send data successfull. if -0, means error. -3 is timeout, and others means session did disconnected
- (int)sendDataWithP2pHandle:(int)handle channel:(int)channel buffer:(unsigned char*)buffer length:(int)len;

/// send data by p2p channel
/// @param handle p2p session handle
/// @param channel p2p channel
/// @param buffer buffer pointer
/// @param len length of buffer
/// @return the length of send data successfull. if -0, means error. -3 is timeout, and others means session did disconnected
- (int)sendDataWithP2pHandle:(int)handle channel:(int)channel buffer:(unsigned char*)buffer length:(int)len timeout:(int)timeout;


/// resend p2p connect offer
/// @param deviceId device id
- (int)resendOffer:(NSString *)deviceId;

/// notify p2p SDK the device is online, for the low-power device
/// @param deviceId device id
- (int)onDeviceOnline:(NSString *)deviceId __deprecated_msg("Use resendOffer: instead");


/// check the p2p session active or not
/// @param p2pHandle p2p session handle
- (BOOL)isP2pActive:(int)p2pHandle __deprecated_msg("Use activeCheckWithHandle: instead");

/// check the p2p session status, return a negative number to indicate that the connection has been disconnected
/// @param p2pHandle p2p session handle
- (int)activeCheckWithHandle:(int)p2pHandle;

/// returnValue >= 0 , success
/// @param devId device id
- (int)startPreConnectWithDeviceId:(NSString *)devId;

/// returnValue >= 0 , success
/// @param devId device id
- (int)closePreConnectWithDeviceId:(NSString *)devId;

///close connects and preConnects.
- (int)closeAllSessions;

+ (void)enableLogReport:(BOOL)enabled;

@end

