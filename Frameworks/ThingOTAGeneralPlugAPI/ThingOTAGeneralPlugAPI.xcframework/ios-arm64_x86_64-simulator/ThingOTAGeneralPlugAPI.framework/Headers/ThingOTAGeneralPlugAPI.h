
#ifndef ThingOTAGeneralPlugAPI_h
#define ThingOTAGeneralPlugAPI_h
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

typedef NS_ENUM(NSUInteger, ThingOTAControllerTheme) {
    ThingOTAControllerWhiteTheme,
    ThingOTAControllerBlackTheme
};

// Status of device upgrades
typedef NS_ENUM(NSUInteger, ThingDeviceUpgradeStatus) {
    ThingDeviceUpgradeStatusNone,      // No upgrade required
    ThingDeviceUpgradeStatusNeed,      // New firmware available
    ThingDeviceUpgradeStatusUpgrading  // Upgrade in progress
};

// Refreshing the firmware upgrade portal cell notification will post on page return
#define ThingOTAEntranceRefreshNotification @"kTYOTAEntranceRefreshNotification"

extern int ThingOTAFinishResultSuccess;
extern int ThingOTAFinishResultFailure;
extern int ThingOTAFinishResultTimeout;

// This notification is sent when the OTA details page upgrade is complete {‘deviceId’: string, ‘result’: int[0 success, 1 failure, 2 timeout]}
extern NSNotificationName const ThingOTAFinishNotificationName;

#import "ThingOTADeviceUpgradeListModel.h"

@class ThingSmartDeviceModel;

typedef void (^ThingSpaceUpgradeDeviceCheckSuccess)(NSArray <ThingOTADeviceUpgradeListModel *> *upgradeDevices);
typedef void (^ThingFailureError)(NSError *error);

@protocol ThingOTAGeneralProtocol <NSObject>
/**
 * Check if the device supports firmware upgrade
 
 * @param deviceModel The device to be checked for firmware upgrade
 * YES: Supported
 * NO: Not supported
 */
- (BOOL)isSupportUpgrade:(ThingSmartDeviceModel *)deviceModel;

/**
 * Detects whether the current home has an upgradeable device (non-space manager hasUpgrade returns NO directly)
 */
- (void)checkCurrentFamilyUpgradeDeviceSuccess:(void (^)(BOOL checkFinished, BOOL hasUpgrade))success failure:(void (^)(NSError * error))failure;

/**
 * Get firmware upgrade status, no upgrade, firmware upgrade, upgrade in progress
 *
 * @param deviceModel The device that needs to be checked for firmware upgrade.
 * @param success Success block
 * @param failure Failure block
 */
- (void)upgradeStatusWithDeviceModel:(ThingSmartDeviceModel *)deviceModel
                             success:(void(^)(ThingDeviceUpgradeStatus status))success
                             failure:(ThingFailureError)failure DEPRECATED_MSG_ATTRIBUTE("use [otaStatusWithDeviceModel:success:failure:] instead");;
/**
 * Start upgrade detection, if upgrade is required then popup prompts
 * @param devId device id
 */
- (void)startUpgradeCheckWithDevId:(NSString *)devId;

/**
 * Detect devices in the space that need to be upgraded
 * @param spaceId space id
 * @param success Detect success
 * @param failure failure
 */
- (void)checkSpaceUpgradeDevicesWithSpaceId:(long long)spaceId
                                    success:(ThingSpaceUpgradeDeviceCheckSuccess)success
                                    failure:(ThingFailureError)failure;

/**
 * Go to the device upgrade page
 * @param devId device id
 */
- (void)gotoDeviceUpgradeControllerWithDevId:(NSString *)devId;


/**
 * Go to the device upgrade page, you can configure the dark UI theme
 * @param devId device id
 * @param theme UI theme
 */
- (void)gotoDeviceUpgradeControllerWithDevId:(NSString *)devId theme:(ThingOTAControllerTheme)theme;

/**
 * Refresh OTA page
 * @param deviceModel device
 * @param theme UI theme
 */
- (void)refreshOTAViewController:(ThingSmartDeviceModel *)deviceModel theme:(ThingOTAControllerTheme)theme;

#pragma mark - DEPRECATED
/**
 Check for device firmware updates, if there is an update it will display a firmware update alert
 
 @param deviceModel The device to be checked for firmware update.
 @param isManual Whether to manually check for updates.
 @param theme theme colour
 YES: manually detect upgrade, pop up loading box when detecting upgrade. When there is a new version of firmware (detect upgrade, force upgrade, remind upgrade), show OTA VC.
 NO: Detect upgrade automatically, no loading box pops up when detecting. When there is a mandatory upgrade or reminder upgrade, the firmware upgrade prompt will pop up, and OTA VC will be displayed after tapping OK.
 */
- (void)checkFirmwareUpgrade:(ThingSmartDeviceModel *)deviceModel isManual:(BOOL)isManual theme:(ThingOTAControllerTheme)theme DEPRECATED_MSG_ATTRIBUTE("use [startUpgradeCheckWithDevId:] or [gotoDeviceUpgradeControllerWithDevId:] instead");

/**
 Check for device firmware updates, if there is an update it will display a firmware update alert
 
 @param deviceModel The device to be checked for firmware update.
 @param isManual Whether to manually check for updates.
 @param theme Theme colour
 @param viewController not strongly referenced, display upgrade popup in this viewController, push in OTA VC in the navigation stack it belongs to. pass nil, automatically find the top VC, it will be displayed on top of the modal popup of the user
 YES: manually detect upgrade, popup loading box when detecting. When there is a new firmware version (detect upgrade, force upgrade, remind upgrade), show OTA VC.
 NO: Detect upgrade automatically, no loading box pops up when detecting. When there is a mandatory upgrade or reminder upgrade, the firmware upgrade prompt will pop up, and OTA VC will be displayed after tapping OK.
 */
- (void)checkFirmwareUpgrade:(ThingSmartDeviceModel *)deviceModel isManual:(BOOL)isManual theme:(ThingOTAControllerTheme)theme viewController:(UIViewController *)viewController DEPRECATED_MSG_ATTRIBUTE("use [startUpgradeCheckWithDevId:] or [gotoDeviceUpgradeControllerWithDevId:] instead");


@optional

//Show and Hide Upgrade In-Panel. These two interfaces are mainly exposed for use by the TRCTPanelManager module to transfer the ThingAlertView dependency to the ThingOTAGeneralModule
- (NSObject *)displayOtaAlertInViewController:(UIViewController *)viewController deviceId:(NSString *)deviceId completedHandle:(void(^)(void))completedHandle;
- (void)hidenOtaAlert:(id)alertView;

// Get firmware upgrade status, status
- (void)otaStatusWithDeviceModel:(ThingSmartDeviceModel *)deviceModel success:(void(^)(ThingSmartDeviceUpgradeStatus status))success failure:(ThingFailureError)failure;


@end

#endif /* ThingOTAGeneralPlugAPI_h */
