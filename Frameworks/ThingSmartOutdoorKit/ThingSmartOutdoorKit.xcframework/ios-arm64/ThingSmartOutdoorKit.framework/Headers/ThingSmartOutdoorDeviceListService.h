
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ProductIconModel)
@interface ThingSmartOutdoorProductIconModel : NSObject

/// product icon 800x800
@property (nonatomic, copy) NSString *icon;

@end

NS_SWIFT_NAME(DeviceHardwareModel)
@interface ThingSmartOutdoorDeviceHardwareModel : NSObject

/// Vehicle Identification Number (VIN)
@property (nonatomic, copy) NSString *chassisNo;
/// device active time
@property (nonatomic, copy) NSString *activeTime;
/// product model identification number
@property (nonatomic, copy) NSString *productModel;

@end

NS_SWIFT_NAME(ExtensionDpInfoModel)
@interface ThingSmartOutdoorExtensionDpInfoModel : NSObject
/// device info
@property (nonatomic, copy) NSDictionary *deviceInfo;
/// product ability
@property (nonatomic, copy) NSArray *productAbility;
@end

NS_SWIFT_NAME(DeviceListService)
@interface ThingSmartOutdoorDeviceListService : NSObject

/// request product icon
/// @param deviceIDList device id list
/// @param success success callback
/// @param failure failure callback
- (void)requestProductIconWithDeviceIDList:(NSSet<NSString *> *)deviceIDList
                                   success:(void(^)(NSDictionary<NSString * /** product ID */, ThingSmartOutdoorProductIconModel *> *productIconMap))success
                                   failure:(void(^__nullable)(NSError * error))failure;

/// request hardware info
/// @param deviceID device ID
/// @param success success callback
/// @param failure failure callback
- (void)requestHardwareWithDeviceID:(NSString *)deviceID
                            success:(void(^)(ThingSmartOutdoorDeviceHardwareModel *hardwareModel))success
                            failure:(void(^)(NSError *error))failure;

/// request extension dp info
/// @param deviceID device ID
/// @param success success callback
/// @param failure failure callback
- (void)requestExtensionDpInfo:(NSString *)deviceID
                       success:(void(^)(NSArray *productAbility))success
                       failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
