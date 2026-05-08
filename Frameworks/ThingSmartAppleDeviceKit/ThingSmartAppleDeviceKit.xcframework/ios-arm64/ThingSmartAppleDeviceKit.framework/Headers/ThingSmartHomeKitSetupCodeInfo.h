
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartHomeKitSetupCodeInfo : NSObject

/// Device identification of the device.
@property (nonatomic, copy) NSString *devId;

/// Device HomeKit Setup Code of the device.
@property (nonatomic, copy) NSString *homeKitSetupCode;


@end

NS_ASSUME_NONNULL_END
