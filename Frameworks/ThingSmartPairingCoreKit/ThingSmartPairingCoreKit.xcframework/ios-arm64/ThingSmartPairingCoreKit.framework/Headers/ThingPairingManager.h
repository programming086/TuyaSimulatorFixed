
#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>


NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartPairingHandlerDelegate;
@protocol ThingSmartPairConfiguration;
@protocol ThingSmartLogTrackConfiguration;
@class ThingSmartPairingResumeConfigWiFiParam;
@class ThingSmartPairingScanWiFiListParam;
@class ThingSmartPairingWiFiInfo;

@interface ThingPairingManager : NSObject

@property (nonatomic, strong, nullable) NSString *gwId;

@property (nonatomic, strong, nullable) NSString *token;

@property (nonatomic, strong, nullable) NSString *registerString;

@property (nonatomic, assign) ThingActivatorMode mode;

@property (nonatomic, copy, nullable) NSString *type;

@property (nonatomic, copy, nullable) NSString *pairStep;

@property (nonatomic, copy, nullable) NSString *productId;

@property (nonatomic, assign) BOOL hasSuccess;

@property (nonatomic, copy) NSDictionary *dataExt;

@property (nonatomic, copy) NSString *miniPairId;

@property (nonatomic, assign) BOOL isReported;

@property (nonatomic, assign) BOOL isPairing;

@property (nonatomic, weak, nullable) id<ThingSmartLogTrackConfiguration> logTrackConfiguration;

+ (void)getSSID:(ThingSuccessString)success failure:(ThingFailureError)failure;

+ (void)getBSSID:(ThingSuccessString)success failure:(ThingFailureError)failure;

+ (void)connectSSID:(NSString *)ssid pwd:(NSString *)pwd success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

+ (void)connectWifiWithSSID:(NSString *)ssid password:(NSString *)password completionHandler:(void (^)(NSError * error))completionHandler;

+ (void)connectSSIDPrefix:(NSString *)SSIDPrefix pwd:(NSString *)pwd success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

+ (void)connectWifiWithSSIDPrefix:(NSString *)SSIDPrefix password:(NSString *)password completionHandler:(void (^)(NSError * error))completionHandler;

+ (void)disconnectWifiWithSSID:(NSString *)ssid;

#pragma mark - General

- (void)startPairingWithConfiguration:(id<ThingSmartPairConfiguration>)config
                                 mode:(ThingActivatorMode)mode
                             delegate:(id<ThingSmartPairingHandlerDelegate>)delegate;

- (void)resumeAPPlusWithConfiguration:(id<ThingSmartPairConfiguration>)config;


/// Restore the config network, if you encounter router connection failure during the config process, you can use this interface to restore the distribution process.
/// @see `ThingSmartPairingResumeConfigWiFiParam`
/// @param param param
/// @param error error
/// @return 0 success
- (int)resumeConfigWiFi:(ThingSmartPairingResumeConfigWiFiParam*)param error:(NSError**)error;

/// Scanning the list of available wifi
/// @see `ThingSmartPairingScanWiFiListParam`,`ThingSmartPairingWiFiInfo`
/// @param param param
/// @param success success
/// @param failure failure
- (void)scanConnectableWiFiList:(ThingSmartPairingScanWiFiListParam*)param
                        success:(void(^)(NSArray <ThingSmartPairingWiFiInfo*>*_Nullable listArray))success
                        failure:(void(^)(NSError *_Nullable error))failure;

- (void)pairingSubDeviceWithGwId:(NSString *)gwId
                             msg:(NSDictionary *)msg
                        localKey:(NSString *)localKey
                              pv:(double)pv
                         success:(nullable ThingSuccessHandler)success
                         failure:(nullable ThingFailureError)failure;

- (void)publishMqttMsg:(NSDictionary *)msg
              protocol:(NSInteger)protocol
                 devId:(NSString *)devId
              localKey:(NSString *)localKey
                    pv:(double)pv
               success:(nullable ThingSuccessHandler)success
               failure:(nullable ThingFailureError)failure;

- (void)searchDevices;

- (void)stopConfigWiFi;

- (void)stopConfigZigbeeSubDevice;

- (void)stopConfigWifiUnBind;

- (void)continueConfigSecurityLevelDevice;

- (void)resetDevice;

@end

NS_ASSUME_NONNULL_END
