
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingStreamQueryAgentTokenParams : NSObject
/// AI Solution code.
@property (nonatomic, copy) NSString *solutionCode;
/// Owner ID. (aka Home Id)
@property (nonatomic, copy) NSString *ownerId;
/// Extension parameters.
@property (nonatomic, copy) NSDictionary *extParams;
/// API name.
@property (nonatomic, copy) NSString *api;
/// API version.
@property (nonatomic, copy) NSString *apiVerion;
@end

@interface ThingStreamBizConfig : NSObject
/// Bisiness Code.
@property (nonatomic, assign) uint32_t bizCode;
/// Sending data type definition.
@property (nonatomic, copy) NSArray<NSString *> *sendData;
/// Receiving data type definition.
@property (nonatomic, copy) NSArray<NSString *> *revData;
@end

@interface ThingStreamAgentTokenInfo : NSObject
/// AI agent token.
@property (nonatomic, copy) NSString *agentToken;
/// Bisiness config.
@property (nonatomic, strong) ThingStreamBizConfig *bizConfig;
/// Solution code.
@property (nonatomic, copy) NSString *solutionCode;
/// Extension parameters.
@property (nonatomic, copy, nullable) NSDictionary *extParams;
@end

@interface ThingStreamSessionInfo : NSObject
/// Request agent token info.
@property (nonatomic, strong) ThingStreamAgentTokenInfo *agentTokenInfo;
/// Business code.
@property (nonatomic, assign) uint32_t bizCode __deprecated_msg("deprecated, The API will be deleted in the future.");
/// Business tag.
@property (nonatomic, assign) uint64_t bizTag __deprecated_msg("deprecated, The API will be deleted in the future.");
/// Session ID.
@property (nonatomic, copy) NSString *sessionID;
/// Cache receive data base path.
@property (nonatomic, copy, nullable) NSString *cacheBasePath;
/// Send datas channel for this session.
@property (nonatomic, copy) NSArray<NSString *> *sendDataChannels;
/// Receive datas channel for this session.
@property (nonatomic, copy) NSArray<NSString *> *recvDataChannels;
@property (nonatomic, copy) NSDictionary<NSString *, NSNumber *> *sendDataChannelMap;
@property (nonatomic, copy) NSDictionary<NSString *, NSNumber *> *recvDataChannelMap;
@property (nonatomic, copy) NSString *solutionCode;
@end

NS_ASSUME_NONNULL_END
