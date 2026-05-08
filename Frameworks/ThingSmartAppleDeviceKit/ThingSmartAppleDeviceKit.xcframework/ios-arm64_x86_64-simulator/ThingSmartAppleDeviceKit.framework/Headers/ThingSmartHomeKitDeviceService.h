
#import "ThingSmartHomeKitProductInfoRequestModel.h"
#import "ThingSmartHomeKitProductInfo.h"
#import "ThingSmartHomeKitSetupCodeRequestModel.h"
#import "ThingSmartHomeKitSetupCodeInfo.h"

NS_ASSUME_NONNULL_BEGIN

/// Fetch Thing HomeKit device info.
@interface ThingSmartHomeKitDeviceService : NSObject

/// Featch single device product info Use Request Model.
/// @param requestModel specify the device to request.
/// @param success fetch success.
/// @param failure fetch failure.
+ (void)requestProductInfoWithRequestModel:(ThingSmartHomeKitProductInfoRequestModel *)requestModel
                                   success:(void (^)(ThingSmartHomeKitProductInfo *info))success
                                   failure:(void(^)(NSError *error))failure;

/// Featch device HomeKit Setup Code Use Request Model.
/// @param requestModel specify the device to request.
/// @param success fetch success.
/// @param failure fetch failure.
+ (void)requestDeviceHomeKitSetupCodeWithRequestModel:(ThingSmartHomeKitSetupCodeRequestModel *)requestModel
                                         success:(void (^)(ThingSmartHomeKitSetupCodeInfo *info))success
                                         failure:(void(^)(NSError *error))failure;

/// Featch single device product info.
/// @param productId Identification of equipment categories.
/// @param uuid Unique identification of the device.
/// @param success fetch success.
/// @param failure fetch failure.
+ (void)requestProductInfoWithProductId:(NSString *)productId
                                   uuid:(NSString *)uuid
                                   success:(void (^)(ThingSmartHomeKitProductInfo *info))success
                                failure:(void(^)(NSError *error))failure;

/// Featch device HomeKit Setup Code.
/// @param deviceId identification of the device.
/// @param success fetch success.
/// @param failure fetch failure.
+ (void)requestDeviceHomeKitSetupCodeWithDeviceId:(NSString *)deviceId
                                          success:(void (^)(ThingSmartHomeKitSetupCodeInfo *info))success
                                          failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
