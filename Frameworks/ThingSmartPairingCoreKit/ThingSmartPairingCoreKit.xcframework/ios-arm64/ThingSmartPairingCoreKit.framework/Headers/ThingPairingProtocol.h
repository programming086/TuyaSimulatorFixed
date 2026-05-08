
#import <Foundation/Foundation.h>
#import "ThingPairingManager.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartPairingScanWiFiListParam,ThingSmartPairingWiFiInfo;
@class ThingSmartPairingResumeConfigWiFiParam;

@protocol ThingPairingProtocol <NSObject>

@property (nonatomic, assign) BOOL isRunning;

@property (nonatomic, copy, nullable) NSString *registerString;

@property (nonatomic, copy, nullable) NSString *token;

@property (nonatomic, copy, nullable) NSString *step;

@property (nonatomic, copy, nullable) NSDictionary *dataExt;

@property (nonatomic, weak) id<ThingSmartPairingHandlerDelegate> delegate;

@property (nonatomic, strong) id<ThingSmartPairConfiguration> config;

@property (nonatomic, strong) id<ThingSmartLogTrackConfiguration> logTrack;

@property (nonatomic, copy) NSString *miniPairId;

- (void)pairingWithConfiguration:(id<ThingSmartPairConfiguration>)config;

- (void)pairingWithConfiguration:(id<ThingSmartPairConfiguration>)config
                        logTrack:(nullable id<ThingSmartLogTrackConfiguration>)logTrack;

- (void)stopPairing;

@optional

- (void)searchDevice;

- (void)deviceActive:(NSString *)token;

- (void)deviceStatusCheck:(NSString *)devId;

- (void)continueConfigSecurityLevelDevice;

- (int)resumeConfigWiFi:(ThingSmartPairingResumeConfigWiFiParam*)param error:(NSError**)error;

- (void)resumeWithConfiguration:(id<ThingSmartPairConfiguration>)config;

- (void)scanConnectableWiFiList:(ThingSmartPairingScanWiFiListParam*)param
                        success:(void(^)(NSArray <ThingSmartPairingWiFiInfo*>*_Nullable listArray))success
                        failure:(void(^)(NSError *_Nullable error))failure;

- (void)resetDevice;

- (BOOL)reuseTCPConnection;

@end

NS_ASSUME_NONNULL_END
