
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceInfoUtils : NSObject

/// Retrieve Matter device information
+ (void)getMatterDeviceInfoWithDeviceId:(NSString *)deviceId success:(void(^)(NSDictionary *dict))success failure:(void(^)(NSError *error))failure;

/// Retrieve hardware information
+ (void)device:(ThingSmartDevice *)device getHardwareInfoSuccess:(void(^)(NSDictionary *dict))success failure:(void(^)(NSError *error))failure;

/// Retrieve hardware information
+ (void)getHardwareInfoWithDeviceId:(NSString *)deviceId Success:(void(^)(NSDictionary *dict))success failure:(void(^)(NSError *error))failure __attribute__((deprecated("use +getHardwareInfoWithDeviceId:success:failure: instead")));;
+ (void)getHardwareInfoWithDeviceId:(NSString *)deviceId success:(void(^)(NSDictionary *dict))success failure:(void(^)(NSError *error))failure;


+ (NSString *)generateUniqueId;

@end

NS_ASSUME_NONNULL_END
