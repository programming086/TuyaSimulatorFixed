
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingSmartDeviceModelGatewayBindType) {
    ThingSmartDeviceModelGatewayBindTypeDefault,
    ThingSmartDeviceModelGatewayBindTypeManualOnly,
};

@interface ThingSmartDeviceModel (PerformanceGateway)

- (BOOL)canBeBindSubDevice;

- (BOOL)canBeBindGateway;

- (BOOL)canBeBind;

- (ThingSmartDeviceModelGatewayBindType)gatewayBindType;

@end

NS_ASSUME_NONNULL_END
