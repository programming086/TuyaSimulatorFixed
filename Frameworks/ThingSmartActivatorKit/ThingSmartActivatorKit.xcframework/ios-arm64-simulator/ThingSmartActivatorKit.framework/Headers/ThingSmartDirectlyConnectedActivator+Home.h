
#import <ThingSmartActivatorCoreKit/ThingSmartDirectlyConnectedActivator.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDirectlyConnectedRequestModel : NSObject
@property (nonatomic, copy) NSString *uuid;
@property (nonatomic, copy) NSString *hotspotName;
@property (nonatomic, assign) long long homeId;
@property (nonatomic, copy) NSString *groupType;
@property (nonatomic, copy, nullable) NSString *pin;
@end

@interface ThingSmartDirectlyConnectedActivator (Home)

/// Activate devices to the cloud
/// @param uuid the uuid of device
/// @param groupId the home id
/// @param groupType the home type
/// @param success the callback of success
/// @param failure the callback of failure
- (void)deviceCloudActivateWithUUID:(NSString *)uuid
                            groupId:(long long)groupId
                          groupType:(NSString *)groupType
                            success:(void (^)(ThingSmartDeviceModel *deviceModel))success
                            failure:(ThingFailureError)failure;

/// Activate devices to the cloud
/// @param requestModel  request parameter
/// @param success the callback of success
/// @param failure the callback of failure
- (void)deviceCloudActivateWithModel:(ThingSmartDirectlyConnectedRequestModel *)requestModel
                             success:(void (^)(ThingSmartDeviceModel *deviceModel))success
                             failure:(ThingFailureError)failure;
@end

NS_ASSUME_NONNULL_END
