
#ifndef ThingSmart_ThingSmartActivator
#define ThingSmart_ThingSmartActivator

#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import <ThingSmartPairingCoreKit/ThingSmartPairingHeader.h>

NS_ASSUME_NONNULL_BEGIN

/// This notification is sent after receiving a broadcast from a wired distribution device. Object is dictionary, @{@"productId":productId, @"gwId":gwId}
extern NSString *const ThingSmartActivatorNotificationFindGatewayDevice;

//typedef enum : NSUInteger {
//    ThingActivatorModeEZ,///< smart config mode
//    ThingActivatorModeAP,///< access point mode
//    ThingActivatorModeQRCode,///< QR Code mode
//    ThingActivatorModeWired, ///< wired mode
//} ThingActivatorMode;
//
//typedef enum : NSUInteger {
//    ThingActivatorStepFound = 1,///< device found
//    ThingActivatorStepRegisted = 2,///< device registered
//    ThingActivatorStepIntialized = 3,///< device initialized
//    ThingActivatorStepTimeOut = 4, ///< device config timeout
//} ThingActivatorStep;


@class ThingSmartActivator;
@class ThingSmartPairingResumeConfigWiFiParam;
@class ThingSmartPairingScanWiFiListParam;
@class ThingSmartPairingWiFiInfo;

@protocol ThingSmartActivatorDelegate<NSObject>

@required

/// Callback for distribution status update, wifi single product, zigbee gateway, zigbee sub device.
/// @param activator instance
/// @param deviceModel deviceModel
/// @param error error
- (void)activator:(ThingSmartActivator *)activator didReceiveDevice:(nullable ThingSmartDeviceModel *)deviceModel error:(nullable NSError *)error;

@optional

/// Callback for device state error
/// @param error error
- (void)deviceStateError:(NSError *)error;

/// Callback for device scan wifi list
/// @param activator instance
/// @param wifiList wifi list
/// @param error error
- (void)activator:(ThingSmartActivator *)activator didDiscoverWifiList:(nullable NSArray *)wifiList error:(nullable NSError *)error;

/// Callback for distribution status update, wifi single product, zigbee gateway, zigbee sub device.
/// @param activator instance
/// @param deviceModel deviceModel
/// @param step activator step
/// @param error error
- (void)activator:(ThingSmartActivator *)activator didReceiveDevice:(nullable ThingSmartDeviceModel *)deviceModel step:(ThingActivatorStep)step error:(nullable NSError *)error;

/// Callback for the wired gateway discovery, wifi gateway, zigbee gateway.
/// @param activator instance
/// @param deviceId the device id
/// @param productId the product id
- (void)activator:(ThingSmartActivator *)activator didFindGatewayWithDeviceId:(nullable NSString *)deviceId productId:(nullable NSString *)productId;

/// Callback for requesting the home id
/// @param activator instance
- (long long)activatorGetHomeId:(ThingSmartActivator *)activator;

/// Callback for the device which has Security Level info, while AP pairing .
/// Notice:
///     When this function called, you can judge whether the SSID of the current phone is the same as the one the user selected before.
///     If the SSID is the same then call the `-continueConfigSecurityLevelDevice` method to continue.
///     If the SSID is different, remind the user to change the same one.
/// @param activator instance
/// @param uuid the uuid
- (void)activator:(ThingSmartActivator *)activator didPassWIFIToSecurityLevelDeviceWithUUID:(NSString *)uuid;

/// Callback for distribution status update mesh gateway, deprecated.
/// @param activator instance
/// @param deviceId devId
/// @param meshId meshId
/// @param error error
/// @deprecated This method is deprecated, Use ThingSmartActivatorDelegate::activator:didReceiveDevice:error: instead `deviceId` is `deviceModel.devId`, `meshId` is `deviceModel.parentId`.
- (void)meshActivator:(ThingSmartActivator *)activator didReceiveDeviceId:(NSString *)deviceId meshId:(NSString *)meshId error:(NSError *)error __deprecated_msg("Use -[ThingSmartActivatorDelegate activator:didReceiveDevice:error:] instead. `deviceId` is `deviceModel.devId`, `meshId` is `deviceModel.parentId`.");
@end

@interface ThingSmartActivator : NSObject

/// Returns a singleton of the class.
+ (nullable instancetype)sharedInstance; __attribute__((unavailable("Must use -[[ThingSmartActivator alloc] init] instead.")));

#pragma mark - SSID

/// Get the SSID of the current Wi-Fi.
///
/// Starting with iOS 12, calls to this function will return nil by default, and will only return the correct value if "Access WiFi Information" is enabled in the Xcode project. This function needs to be activated in the App IDs on the developer page in order to use it.
/// Starting with iOS 13, at least one of the following three conditions must also be met.
///   - An app that has been granted Location Services permissions.
///   - A VPN application that is currently enabled.
///   - Use of NEHotspotConfiguration (only Wi-Fi networks configured through the app are supported).
///
/// @see https://developer.apple.com/videos/play/wwdc2019/713/
///
/// @return Wi-Fi SSID
+ (NSString *)currentWifiSSID;

/// Get the BSSID of the current Wi-Fi.
/// @see ThingSmartActivator::currentWifiSSID.
/// @return Wi-Fi BSSID
+ (NSString *)currentWifiBSSID;

/// Get the SSID of the current Wi-Fi asynchronously.
/// @see ThingSmartActivator::currentWifiSSID
/// @param success Called when the task finishes successfully. ThingSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)getSSID:(ThingSuccessString)success failure:(ThingFailureError)failure;

/// Asynchronously get the BSSID of the current Wi-Fi.
/// @param success Called when the task finishes successfully. ThingSuccessString will be returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)getBSSID:(ThingSuccessString)success failure:(ThingFailureError)failure;

#pragma mark - Delegate

@property (nonatomic, weak) id<ThingSmartActivatorDelegate> delegate;

- (void)getDeviceSecurityConfigs:(ThingSuccessDict)success
                         failure:(ThingFailureError)failure;

- (void)startConfigWiFi:(ThingActivatorMode)mode
                   ssid:(NSString *)ssid
               password:(NSString *)password
                  token:(NSString *)token
                regInfo:(nullable NSDictionary *)regInfo
                timeout:(NSTimeInterval)timeout;

/// Start configuration (Wireless config).
/// @param mode Config mode, EZ or AP.
/// @param ssid Name of route.
/// @param password Password of route.
/// @param token Config Token.
/// @param timeout Timeout, default 100 seconds.
- (void)startConfigWiFi:(ThingActivatorMode)mode
                   ssid:(NSString *)ssid
               password:(NSString *)password
                  token:(NSString *)token
                timeout:(NSTimeInterval)timeout;

- (void)startActiveDeviceWithConfigurations:(ThingSmartPairConfiguration *)configurations
                                       mode:(ThingActivatorMode)mode
                                    timeout:(NSTimeInterval)timeout;

/// Start connect wifi
/// @param ssid Name of route.
/// @param password Password of route.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)connectWiFiWithSSID:(NSString *)ssid
                   password:(NSString *)password
                    success:(nullable ThingSuccessHandler)success
                    failure:(nullable ThingFailureError)failure;

/// Start connect wifi with SSID prefix
/// @param SSIDPrefix Route name prefix
/// @param password Password of route.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)connectWifiWithSSIDPrefix:(NSString *)SSIDPrefix
                         password:(NSString *)password
                          success:(nullable ThingSuccessHandler)success
                          failure:(nullable ThingFailureError)failure;

- (void)disconnectWifiWithSSID:(NSString *)ssid;

/// Start connect device and query wifi list
/// @param timeout timeout
- (void)connectDeviceAndQueryWifiListWithTimeout:(NSTimeInterval)timeout;

- (void)connectDeviceAndQueryWifiListWithConfigurations:(ThingSmartPairConfiguration *)configurations timeout:(NSTimeInterval)timeout;

- (void)resumeAPPlusWithSSID:(NSString *)ssid
                    password:(NSString *)password
                       token:(NSString *)token
                     timeout:(NSTimeInterval)timeout;

- (void)resumeAPPlusWithSSID:(NSString *)ssid
                    password:(NSString *)password
                       token:(NSString *)token
                     timeout:(NSTimeInterval)timeout
                         reg:(NSDictionary *)reg;

/// If the device fails to connect to WiFi, call it to help you resume pairing. Only ap mode is supported.
/// @see <i>activator:didReceiveDevice:step:error:</i> If this callback is received, the step is `ThingActivatorStepFound`, and `ThingSmartPairingConnectWiFiFailedErrorDomain` is returned.\
/// Check the errorcode to do something
///      0 connect wifi success
///      1 error wifi config info
///      2 router not found
///      3 wrong password
///      4 Failed to connect to router
///      5 config DHCP failed
/// @see `ThingSmartPairingConnectWiFiFailedErrorDomain`、`ThingSmartPairingResumeConfigWiFiParam` in {ThingSmartPairingCoreKit}.
/// @see `ThingPairingErrorCode` in {ThingSmartPairingCoreKit}.
/// @param param `ssid` is required and `mode` needs to be `ThingActivatorModeAP`.
/// @param error resume failed, check this error
/// @return 0 success. resume failed,  for the returned error code, please refer to the definition of the enum `ThingPairingErrorCode`
- (int)resumeConfigWiFi:(ThingSmartPairingResumeConfigWiFiParam*)param error:(NSError**)error;


/// Scan the WiFi list by the device you're pairing. Only ap mode is supported.
/// @param param Set the `limit` parameter to limit the number of wifi scanned, or set `timeInterval` to limit the maximum scan duration.
/// @see `ThingSmartPairingScanWiFiListParam`,`ThingSmartPairingWiFiInfo` in {ThingSmartPairingCoreKit}.
/// @see `ThingPairingErrorCode` in {ThingSmartPairingCoreKit}.
/// @param success Returns an array of scanned WiFi objects
/// @param failure If it fails, check the error information
- (void)scanConnectableWiFiList:(ThingSmartPairingScanWiFiListParam*)param
                        success:(nullable void(^)(NSArray <ThingSmartPairingWiFiInfo*>  * _Nullable listArray))success
                        failure:(nullable void(^)(NSError * _Nullable error))failure;


/// Start configuration (Wired config).
/// @param token Token
/// @param timeout Timeout, default 100 seconds.
- (void)startConfigWiFiWithToken:(NSString *)token
                         timeout:(NSTimeInterval)timeout __deprecated_msg("Use - [activeGatewayDeviceWithGwId:productId:token:timeout:] instead.");

/// Start configuring the network to activate only one category of devices (Wired config).
/// @param token Config Token.
/// @param productId ProductId of device.
/// @param timeout Timeout, default 100 seconds.
- (void)startConfigWiFiWithToken:(NSString *)token
                       productId:(NSString *)productId
                         timeout:(NSTimeInterval)timeout __deprecated_msg("Use - [activeGatewayDeviceWithGwId:productId:token:timeout:] instead.");

/// Start EZ mode multi-device configuration network
/// @param ssid Name of route.
/// @param password Password of route.
/// @param token Config Token.
/// @param timeout Timeout, default 100 seconds.
- (void)startEZMultiConfigWiFiWithSsid:(NSString *)ssid
                              password:(NSString *)password
                                 token:(NSString *)token
                               timeout:(NSTimeInterval)timeout;

/// Stop configuring the network.
- (void)stopConfigWiFi;

/// Continue config the device witch has security level.
/// Notice: before calling this method, please make sure that the SSID is the same as the one the user selected at the beginning.
- (void)continueConfigSecurityLevelDevice;

#pragma mark - active 4G gateway

/// Start configuration 4G gateway by AP.
/// - Parameters:
///   - oper: operator
///   - apn: apn
///   - username: username
///   - password: password
///   - token: token
///   - regInfo: regInfo
///   - timeout: Timeout, default 100 seconds
- (void)startConfig4GGatewayByAP:(NSString *)oper
                             apn:(NSString *)apn
                        username:(NSString *)username
                        password:(NSString *)password
                           token:(NSString *)token
                         regInfo:(NSDictionary *)regInfo
                         timeout:(NSTimeInterval)timeout;

#pragma mark - active sub device

/// Activate sub-devices e.g. zigbee, Wi-Fi sub-devices.
/// @param gwId     Gateway Id
/// @param timeout  Timeout, default 100 seconds
- (void)activeSubDeviceWithGwId:(NSString *)gwId timeout:(NSTimeInterval)timeout;

- (void)activeSubDeviceWithGwId:(NSString *)gwId timeout:(NSTimeInterval)timeout extensions:(nullable NSDictionary *)extensions;

/// Activate zigbee sub-devices with installCode
/// @param gwId Gateway Id
/// @param mac mac
/// @param installCode installCode
/// @param timeout Timeout, default 100 seconds
- (void)activeSubDeviceWithGwId:(NSString *)gwId
                            mac:(NSString *)mac
                    installCode:(NSString *)installCode
                        timeout:(NSTimeInterval)timeout;

/// Activate zigbee sub-devices with installCode(QRCode)
/// @param gwId Gateway Id
/// @param installCodes @[@{@"installcode": "", @"mac": @"", @"manufaturer_info": @"none"}]
/// @param timeout Timeout, default 100 seconds
///
/// @note values keyed by @"installCode", @"mac" MUST be lowercase
- (void)activeSubDeviceWithGwId:(NSString *)gwId
                   installCodes:(NSArray<NSDictionary *> *)installCodes
                        timeout:(NSTimeInterval)timeout;

/// Stop activate sub device with gateway ID.
/// @param gwId Gateway Id
- (void)stopActiveSubDeviceWithGwId:(NSString *)gwId;

#pragma mark - optimize Activator
/// Activates wired gateway
/// @param gwId      The gateway ID.
/// @param productId The gateway PID
/// @param token     The pairing token.
/// @param timeout   The timeout value. Unit: seconds. Default value: 100
- (void)activeGatewayDeviceWithGwId:(NSString *)gwId
                          productId:(NSString *)productId
                              token:(NSString *)token
                            timeout:(NSTimeInterval)timeout;

- (void)resetDeviceWithUUID:(NSString *)uuid;

#pragma mark - pairing token

/// Returns the pairing token by home ID. This token is valid for 10 minutes.
/// @param homeId The home ID.
/// @param success Called when the task is finished. ThingSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithHomeId:(long long)homeId
                   success:(ThingSuccessString)success
                   failure:(ThingFailureError)failure;


/// Returns the pairing token by product ID. This token is valid for 10 minutes.
/// @param productKey The product ID.
/// @param homeId The home ID.
/// @param success Called when the task is finished. ThingSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithProductKey:(NSString *)productKey
                        homeId:(long long)homeId
                       success:(ThingSuccessString)success
                       failure:(ThingFailureError)failure;

/// Returns the pairing token by UUID. This token is valid for 10 minutes.
/// @param uuid The device UUID.
/// @param homeId The home ID.
/// @param success Called when the task is finished. ThingSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenWithUUID:(NSString *)uuid
                  homeId:(long long)homeId
                 success:(ThingSuccessString)success
                 failure:(ThingFailureError)failure;

/// Returns the parsed QR Code from device

/// @param content QR Code content
/// @param success Called when the task is finished. ThingSuccessId is returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)parseQRCode:(NSString *)content
            success:(ThingSuccessID)success
            failure:(ThingFailureError)failure;

/// Renewal the pairing token by token. This token is valid for 10 minutes.
/// @param token The token
/// @param success Called when the task is finished. ThingSuccessBool is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)renewalToken:(NSString *)token
             success:(ThingSuccessBOOL)success
             failure:(ThingFailureError)failure;

/// check token when cancel.
- (void)resumeToken:(NSString *)token;             
             
@end
#endif

NS_ASSUME_NONNULL_END
