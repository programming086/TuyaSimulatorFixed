
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartAutoActivator;

@protocol ThingSmartAutoActivatorDelegate <NSObject>

/// Configures the callbacks of network status updates.
/// @param activator The instance.
/// @param deviceModel The device model.
/// @param error An error occurs while processing the request.
- (void)autoActivator:(ThingSmartAutoActivator *)activator didReceiveAutoConfigDevice:(ThingSmartDeviceModel *)deviceModel error:(NSError *)error;

@end

@interface ThingSmartAutoActivator : NSObject

/// Returns the delegate of ThingSmartAutoActivator.
@property (nonatomic, weak) id<ThingSmartAutoActivatorDelegate> delegate;

/// Returns the singleton instance of the class.
+ (instancetype)sharedInstance __attribute__((unavailable("Must use -[[ThingSmartActivator alloc] init] instead.")));

/// Starts to scan for devices.
/// @param devIds A list of device IDs.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverWithDevIds:(NSArray<NSString *> *)devIds
                        timeout:(NSTimeInterval)timeout
                        success:(ThingSuccessHandler)success
                        failure:(ThingFailureError)failure;

/// Returns the pairing token. This token is valid for 10 minutes.
/// @param success Called when the task is finished. ThingSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(ThingSuccessString)success
                failure:(ThingFailureError)failure;

/// Starts to scan for devices.
/// @param devIds A list of device IDs.
/// @param token The pairing token.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverWithDevIds:(NSArray<NSString *> *)devIds
                          token:(NSString *)token
                        timeout:(NSTimeInterval)timeout
                        success:(ThingSuccessHandler)success
                        failure:(ThingFailureError)failure;

/// Starts to scan for gateway routers.
/// @param devIds A list of device IDs.
/// @param type Specifies whether to start scanning. Set the value to `0` to start scanning.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use ThingSmartRouterActivator::startDiscoverRouterWithDevIds:type:timeout:success:failure: instead.
- (void)startDiscoverRouterWithDevIds:(NSArray<NSString *> *)devIds
                                 type:(NSInteger)type
                              timeout:(NSTimeInterval)timeout
                              success:(ThingSuccessHandler)success
                              failure:(ThingFailureError)failure __deprecated_msg("Use -[ThingSmartRouterActivator startDiscoverRouterWithDevIds:type:timeout:success:failure:] instead.");

/// Stops scanning for devices.
- (void)stopDiscover;

@end

NS_ASSUME_NONNULL_END
