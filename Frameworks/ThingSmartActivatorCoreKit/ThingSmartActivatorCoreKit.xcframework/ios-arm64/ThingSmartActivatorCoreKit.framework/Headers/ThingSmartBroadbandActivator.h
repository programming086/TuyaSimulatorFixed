
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartBroadbandActivator;

@protocol ThingSmartBroadbandActivatorDelegate <NSObject>

/// The callback of finding router device.
/// @param activator The activator instance.
/// @param deviceInfo The device id.
- (void)broadbandActivator:(ThingSmartBroadbandActivator *)activator
      didFindDeviceInfo:(NSDictionary *)deviceInfo;

/// The callback of getting the broadConnType.
/// @param activator The activator instance.
/// @param types The broadConnType.
/// @param error The error message.
- (void)broadbandActivator:(ThingSmartBroadbandActivator *)activator
    supportConnectTypes:(nullable NSArray<NSString *> *)types
                  error:(nullable NSError *)error;

/// Callback for setting the broadConnType.
/// @param activator The activator instance.
/// @param error The error message.
- (void)broadbandActivatorConfigConnectType:(nonnull ThingSmartBroadbandActivator *)activator
                                   error:(nullable NSError *)error;

@end

@interface ThingSmartBroadbandActivator : NSObject

/// Returns the delegate of ThingSmartBroadbandActivator.
@property (nonatomic, weak) id<ThingSmartBroadbandActivatorDelegate> delegate;

/// Starts to scan for devices.
/// @param timeout The timeout value. Unit: seconds. Default value: 100.
- (void)startDiscoverRouterWithTimeout:(NSTimeInterval)timeout;

/// Start connect router
/// @param devId Gateway Id
- (void)connectToDevice:(NSString *)devId;

/// Set Router Connectting Type
/// @param devId Gateway Id
/// @param connectInfo the connecting info
/// /// @param timeout The timeout value. Unit: seconds. Default value: 100.
- (void)setupConnectWithDevId:(NSString *)devId connectInfo:(NSDictionary *)connectInfo timeout:(NSTimeInterval)timeout;

/// Stop config for router device.
- (void)stopConfigRouter;

@end

NS_ASSUME_NONNULL_END
