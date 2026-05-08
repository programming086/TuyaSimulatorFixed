//
//  TuyaSmartDevice+OTA.h
//  TuyaSmartDeviceCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>
#import "TuyaSmartFirmwareUpgradeModel.h"
#import "TuyaSmartFirmwareUpgradeStatusModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartDevice (OTA)

/// Returns firmware upgrade information. ( for general device.)
/// Notice:
///     equal to `checkFirmwareUpgradeWithExtraInfo:nil success:success failure:failure`
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)checkFirmwareUpgrade:(void (^)(NSArray<TuyaSmartFirmwareUpgradeModel *> *firmwares))success
                     failure:(nullable TYFailureError)failure;


/// Returns firmware upgrade information. ( for general device and some special device. )
/// Exta info's ussage:
///     1. extra info = nil
///         For most general device.
///     2. extra info =  {"types": "0,1, ....", "versions": "0.0.1,0.0.2, ...."}.
///         For the AP Directly device, which used local lan to upgrade.
///         You can use `-getDeviceLocalFirmwareInfo:failure:` to get and cached the info `type` & `currentVersion`.
/// @param extraInfo Some special device need extra info to check firmwares.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)checkFirmwareUpgradeWithExtraInfo:(nullable NSDictionary *)extraInfo
                                  success:(void (^)(NSArray<TuyaSmartFirmwareUpgradeModel *> *firmwares))success
                                  failure:(nullable TYFailureError)failure;

/// Start device firmware upgrade. ( for general device and some special device. )
/// Notice:
///     1. You can use the TuyaSmartDevice's delegate ( `- device:otaUpdateStatusChanged:` ) to receive the status and progress.
///     2. Please use `-checkFirmwareUpgrade:failure:` or `-checkFirmwareUpgradeWithExtraInfo:success:failure` before call this.
/// @param firmwares firmwares from `-checkFirmwareUpgrade:failure:` or `-checkFirmwareUpgradeWithExtraInfo:success:failure`
- (void)startFirmwareUpgrade:(NSArray<TuyaSmartFirmwareUpgradeModel *> *)firmwares;

/// Confirm continue or not when a upgrading task callback the warning error ` TYOTAErrorCodeSignalStrengthNotSatisfy  `.
/// @param isContinue continue or not.
- (void)confirmWarningUpgradeTask:(BOOL)isContinue;

/// Cancel firmware upgrade
/// Notice: it only support for the task status equal to ` TuyaSmartDeviceUpgradeStatusWaitingExectue `
- (void)cancelFirmwareUpgrade:(TYSuccessHandler)success
                      failure:(nullable TYFailureError)failure;

/// Fetch the firmware upgrading task's status or progress. ( progress maybe 0 )
/// Notice: it only support for the task status equal to `TuyaSmartDeviceUpgradeStatusUpgrading` or `TuyaSmartDeviceUpgradeStatusWaitingExectue`
/// @param success Called when the task's status/progress can provide
/// @param failure Called when the task's status/progress can't provide
- (void)getFirmwareUpgradingStatus:(void (^)(TuyaSmartFirmwareUpgradeStatusModel *status))success
                           failure:(nullable TYFailureError)failure;


/// Fetch the device's local firmware version info. ( now only used for the AP Directly device )
/// Notice:
///     1. The device need link to app by the LAN.
///     2. get avaliable infos from the `model.type` and `model.currentVersion` properties.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getDeviceLocalFirmwareInfo:(void (^)(NSArray<TuyaSmartFirmwareUpgradeModel *> *infos))success
                           failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
