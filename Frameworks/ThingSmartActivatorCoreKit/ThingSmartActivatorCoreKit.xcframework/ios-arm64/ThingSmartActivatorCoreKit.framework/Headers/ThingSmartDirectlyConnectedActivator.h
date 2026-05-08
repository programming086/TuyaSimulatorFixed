
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@class ThingSmartDirectlyConnectedActivator;

@protocol ThingSmartDirectlyConnectedActivatorDelegate <NSObject>

/// Configures the callbacks of network status updates.
/// @param activator The instance.
/// @param deviceModel The device model.
/// @param error An error occurs while processing the request.
- (void)directlyConnectedActivator:(ThingSmartDirectlyConnectedActivator *)activator
        didReceiveAutoConfigDevice:(nullable ThingSmartDeviceModel *)deviceModel
                             error:(nullable NSError *)error;

/// Search result the callbakc of the device.
- (void)activator:(ThingSmartDirectlyConnectedActivator *)activator didDiscoveryDeviceWithActive:(BOOL)isActive;

/// Reset the callback of the device.
- (void)service:(ThingSmartDirectlyConnectedActivator *)service resetDevice:(ThingSmartDeviceModel *)deviceModel __deprecated_msg("This method is deprecated, Use -[ThingSmartDirectlyConnectedActivatorDelegate -  activator:didDiscoveryDeviceWithActive] instead");

@end


@interface ThingSmartDirectlyConnectedActivator : NSObject

@property (nonatomic, weak) id<ThingSmartDirectlyConnectedActivatorDelegate> delegate;

/// Activate directly connected devices
/// @param timeout timeout
- (void)activeDirectlyConnectedDeviceWithDevieId:(NSString *)devId timeout:(NSTimeInterval)timeout;

- (void)stopConfigure;

- (void)startSearchDevice;

- (void)stopSearchDevice;
@end

NS_ASSUME_NONNULL_END
