
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSchemaModel (ThingSmartOutdoor)
/// DP value (convert from dps)
@property (nonatomic, strong) id tsod_DPValue;

@end


@interface ThingSmartDeviceModel (ThingSmartOutdoor)

/// get schema model with code
/// @param code DP code
- (nullable ThingSmartSchemaModel *)tsod_schemaMWithCode:(NSString *)code;

@end

NS_ASSUME_NONNULL_END
