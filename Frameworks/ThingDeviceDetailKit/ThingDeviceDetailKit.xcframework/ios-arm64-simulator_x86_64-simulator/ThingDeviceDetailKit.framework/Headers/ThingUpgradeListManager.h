
#import <Foundation/Foundation.h>
#import "ThingUpgradeConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingUpgradeListManager : NSObject

+ (instancetype)sharedInstance;

/// Retrieve firmware upgrade information for devices in the current family.
/// - Parameter familyId: The ID of the family.
/// - Parameter success: A callback that is invoked with an array of `ThingUpgradeListInfo` objects upon success.
/// - Parameter failure: A callback that is invoked with an `NSError` if the operation fails.
- (void)getUpgradeDevicesInFamily:(long long)familyId success:(void (^)(NSArray<ThingUpgradeListInfo *> * list))success failure:(void (^)(NSError *error))failure;


/// Retrieve batch OTA information for a specific device.
/// - Parameter deviceId: The ID of the device.
/// - Parameter success: A callback that is invoked with a `ThingSmartFirmwareCheckResult` object upon success.
/// - Parameter failure: A callback that is invoked with an `NSError` if the operation fails.
- (void)getDeviceBatchOTAInfo:(NSString *)deviceId success:(void (^)(ThingSmartFirmwareCheckResult * result))success failure:(void (^)(NSError *error))failure;

/// Perform a batch upgrade on multiple devices.
/// - Parameter devIds: An array of device IDs to be upgraded.
/// - Parameter success: A callback that is invoked with a `ThingSmartBatchFirmwareConfirmResult` object upon successful completion of the upgrade.
/// - Parameter failure: A callback that is invoked with an `NSError` if the operation fails.
- (void)batchUpgradeWithDevIds:(NSArray<NSString *> *)devIds success:(void (^)(ThingSmartBatchFirmwareConfirmResult * result))success failure:(void (^)(NSError *error))failure;


@end

NS_ASSUME_NONNULL_END
