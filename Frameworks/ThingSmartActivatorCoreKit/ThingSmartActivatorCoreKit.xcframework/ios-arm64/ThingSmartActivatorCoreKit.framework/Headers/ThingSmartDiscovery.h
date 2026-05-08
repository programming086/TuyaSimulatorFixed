
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartDiscovery;

@protocol ThingSmartDiscoveryDelegate<NSObject>

@required

/// The callback of device discovery.
/// @param discovery The instance of the ThingSmartDiscovery class.
/// @param deviceModel The device model in Thing Smart.
/// @param error The NSError object.
- (void)discovery:(ThingSmartDiscovery *)discovery didDiscoveryDevice:(ThingSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

@interface ThingSmartDiscovery : NSObject

@property (nonatomic, weak) id<ThingSmartDiscoveryDelegate> delegate;

/// Returns the pairing token. This token is valid for 10 minutes.
/// @param success Called when the task is finished. ThingSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(ThingSuccessString)success
                failure:(ThingFailureError)failure;

/// Starts to scan for devices.
/// @param ssid The name of the router.
/// @param password The password of the router.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoveryWithSsid:(NSString *)ssid
                     password:(NSString *)password
                      timeout:(NSTimeInterval)timeout
                      success:(ThingSuccessHandler)success
                      failure:(ThingFailureError)failure;

/// Starts to scan for devices by using a token.
/// @param ssid The name of the router.
/// @param password The password of the router.
/// @param token The pairing token.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoveryWithSsid:(NSString *)ssid
                     password:(NSString *)password
                         token:(NSString *)token
                      timeout:(NSTimeInterval)timeout
                      success:(ThingSuccessHandler)success
                      failure:(ThingFailureError)failure;

/// Stops scanning for devices.
- (void)stopDiscovery;

@end

NS_ASSUME_NONNULL_END
