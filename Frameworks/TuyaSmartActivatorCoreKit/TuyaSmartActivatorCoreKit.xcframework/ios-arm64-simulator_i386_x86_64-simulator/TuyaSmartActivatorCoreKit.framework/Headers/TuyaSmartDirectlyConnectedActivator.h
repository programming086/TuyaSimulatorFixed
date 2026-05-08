//
//  TuyaSmartDirectlyConnectedActivator.h
//  Pods
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@class TuyaSmartDirectlyConnectedActivator;

@protocol TuyaSmartDirectlyConnectedActivatorDelegate <NSObject>

/// Configures the callbacks of network status updates.
/// @param activator The instance.
/// @param deviceModel The device model.
/// @param error An error occurs while processing the request.
- (void)directlyConnectedActivator:(TuyaSmartDirectlyConnectedActivator *)activator
        didReceiveAutoConfigDevice:(nullable TuyaSmartDeviceModel *)deviceModel
                             error:(nullable NSError *)error;

/// Search result the callbakc of the device.
- (void)activator:(TuyaSmartDirectlyConnectedActivator *)activator didDiscoveryDeviceWithActive:(BOOL)isActive;

/// Reset the callback of the device.
- (void)service:(TuyaSmartDirectlyConnectedActivator *)service resetDevice:(TuyaSmartDeviceModel *)deviceModel __deprecated_msg("This method is deprecated, Use -[TuyaSmartDirectlyConnectedActivatorDelegate -  activator:didDiscoveryDeviceWithActive] instead");

@end


@interface TuyaSmartDirectlyConnectedActivator : NSObject

@property (nonatomic, weak) id<TuyaSmartDirectlyConnectedActivatorDelegate> delegate;

/// Activate directly connected devices
/// @param timeout timeout
- (void)activeDirectlyConnectedDeviceWithDevieId:(NSString *)devId timeout:(NSTimeInterval)timeout;

- (void)stopConfigure;

- (void)startSearchDevice;

- (void)stopSearchDevice;
@end

NS_ASSUME_NONNULL_END
