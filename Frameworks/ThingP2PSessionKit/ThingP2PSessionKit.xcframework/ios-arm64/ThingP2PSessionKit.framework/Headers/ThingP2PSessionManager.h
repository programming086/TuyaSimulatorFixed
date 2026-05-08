
#import <Foundation/Foundation.h>

#import "ThingP2PSessionProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingP2PSessionConfiguration : NSObject

//default 10000.
@property (nonatomic, assign) NSUInteger maxSessionCount;

/**
timeout,unit:ms，Internet:15000ms， Lan:3000ms
*/
@property (nonatomic, assign) NSInteger lanConnectTimeout;
@property (nonatomic, assign) NSInteger internetConnectTimeout;

@property (class, nonatomic, strong, readonly) ThingP2PSessionConfiguration *defaultConfiguration;

@end

@interface ThingP2PSessionManager : NSObject

@property (class, nonatomic, strong, readonly) ThingP2PSessionManager *sharedManager;

//default is user id.
- (void)initSDKWithLocalId:(nullable NSString *)localId;
- (void)deInitSDK;

//call firstly if needed.
- (void)customGlobalConfiguration:(ThingP2PSessionConfiguration *)globalConfiguration;

///strong references required, otherwise release automatically.
- (nullable id<ThingP2PSession>)createP2PSessionWithDevId:(NSString *)devId error:(NSError * _Nullable *)error;

- (void)clearAllSessions;

- (BOOL)validateSessionWithHandleId:(NSString *)handleId error:(NSError * _Nullable *)error;

@end

NS_ASSUME_NONNULL_END
