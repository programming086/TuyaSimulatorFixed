
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartFirmwareUpgradeModel.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDevice.h>

typedef enum : NSUInteger {
    ThingOTADeviceUpgradeListDeviceStatusDefault,
    ThingOTADeviceUpgradeListDeviceStatusUpgrading,
    ThingOTADeviceUpgradeListDeviceStatusRetry,
    ThingOTADeviceUpgradeListDeviceStatusSuccess,
    ThingOTADeviceUpgradeListDeviceStatusInQueue,
    ThingOTADeviceUpgradeListDeviceStatusPrepare,
} ThingOTADeviceUpgradeListDeviceStatus;

NS_ASSUME_NONNULL_BEGIN

@interface ThingOTADeviceUpgradeListModel : NSObject

/// Device id
@property (nonatomic, copy) NSString *devId;

/// Device icon
@property (nonatomic, copy) NSString *icon;

/// Device name
@property (nonatomic, copy) NSString *name;

/// Upgrade Firmware List
@property (nonatomic, strong) NSArray<ThingSmartFirmwareUpgradeModel *> *upgradeList;

/// Corresponding homepage caching device (for local use)
@property (nonatomic, strong) ThingSmartDevice *device;

/// There are new versions of the firmware List
@property (nonatomic, strong) NSMutableArray<ThingSmartFirmwareUpgradeModel *> *needUpgradeFirmwares;

/// DP does not satisfy the prompt
@property (nonatomic, copy) NSString *dpRemind;

/// Does DP meet the upgrade
@property (nonatomic, assign) BOOL dpEnable;



/// Upgrade List Update Button Status
@property (nonatomic, assign) ThingOTADeviceUpgradeListDeviceStatus upgradeButtonStatus;

/// Reason for upgrade failure
@property (nonatomic, copy) NSString *upgradeFailedReason;

@end

NS_ASSUME_NONNULL_END
