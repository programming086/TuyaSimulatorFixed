
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const ThingUpgradeErrorDomain;

typedef NS_ENUM(NSUInteger, ThingUpgradeErrorCode) {
    ThingUpgradeErrorDeviceNotExists = 10000,
    ThingUpgradeErrorApDirectlyUnsupport = 10001,
    ThingUpgradeErrorGetUpgradeInfoFail = 10002,
    ThingUpgradeErrorGetUpgradeStatusFail = 10003,
};

typedef NS_ENUM(NSUInteger, ThingUpgradeNoticeType) {
    ThingUpgradeNoticeTypeDetection = 0,
    ThingUpgradeNoticeTypeRemind = 1,
    ThingUpgradeNoticeTypeForced = 2,
};

typedef NS_ENUM(NSUInteger, ThingUpgradeStatus) {
    ThingUpgradeStatusNone = ThingSmartDeviceUpgradeStatusReady,
    ThingUpgradeStatusPrepare = ThingSmartDeviceUpgradeStatusLocalPrepare,
    ThingUpgradeStatusWaiting = ThingSmartDeviceUpgradeStatusWaitingExectue,
    ThingUpgradeStatusDownloaded = ThingSmartDeviceUpgradeStatusDownloaded,
    ThingUpgradeStatusInQueue = ThingSmartDeviceUpgradeStatusInQueue,
    ThingUpgradeStatusUpgrading = ThingSmartDeviceUpgradeStatusUpgrading,
};

@interface ThingUpgradeInfo : NSObject

// Initializes the ThingUpgradeInfo with a list of firmware models.
- (instancetype)initWithFirmwares:(NSArray<ThingSmartFirmwareUpgradeModel *> *)firmwares;

// Array of firmware upgrade models.
@property (nonatomic, strong, readonly) NSArray<ThingSmartFirmwareUpgradeModel *> *firmwares;

// Indicates whether an upgrade is needed.
@property (nonatomic, assign, readonly) BOOL needUpgrade;

// List of firmware that needs upgrading.
@property (nonatomic, strong, readonly) NSArray<ThingSmartFirmwareUpgradeModel *> *needUpgradeFirmwares;

// Indicates whether an upgrade is currently in progress.
@property (nonatomic, assign, readonly) BOOL isUpgrading;

// Status of the upgrade.
@property (nonatomic, assign, readonly) ThingUpgradeStatus upgradeStatus;

// Mode of the upgrade.
@property (nonatomic, assign, readonly) ThingSmartDeviceUpgradeMode upgradeMode;

// Type of upgrade notice.
@property (nonatomic, assign, readonly) ThingUpgradeNoticeType noticeType;

// Indicates whether the device is controllable during the upgrade.
@property (nonatomic, assign, readonly) BOOL controllableDudringUpgrade;

// Indicates whether the conditions for an upgrade are met.
@property (nonatomic, assign, readonly) BOOL matchUpgradeCondition;

// Reason why the upgrade conditions are not met, if applicable.
@property (nonatomic, strong, readonly, nullable) NSString *mismatchReason;

@end




@interface ThingUpgradeListInfo : NSObject

// Device ID
@property (nonatomic, copy) NSString *devId;

// Device icon
@property (nonatomic, copy) NSString *icon;

// Device name
@property (nonatomic, copy) NSString *name;

// Gateway ID
@property (nonatomic, copy) NSString *gwId;

// Gateway name
@property (nonatomic, copy) NSString *gwName;

// Product ID of the device
@property (nonatomic, copy) NSString *productId;

// List of firmware upgrades
@property (nonatomic, strong) NSArray<ThingSmartFirmwareUpgradeModel *> *upgradeList;

@end



@interface ThingUpgradeBatchOTADeviceInfo : NSObject

// Device ID
@property (nonatomic, copy) NSString *devId;

// Device name
@property (nonatomic, copy) NSString *name;

@end


@interface ThingUpgradeBatchOTAInfo : NSObject

// Indicates whether group upgrades are supported
@property (nonatomic, assign) BOOL supportGroup;

// ID of the group upgrade
@property (nonatomic, copy) NSString *group;

// List of devices included in the batch upgrade
@property (nonatomic, strong) NSArray<ThingUpgradeBatchOTADeviceInfo *> *deviceList;

// List of firmware upgrades
@property (nonatomic, strong) NSArray<ThingSmartFirmwareUpgradeModel *> *upgradeList;

@end
NS_ASSUME_NONNULL_END
