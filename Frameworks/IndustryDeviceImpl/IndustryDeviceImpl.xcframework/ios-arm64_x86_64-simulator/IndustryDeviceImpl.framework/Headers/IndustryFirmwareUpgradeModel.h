//
//  IndustryFirmwareUpgradeModel.h
//  IndustryDeviceImpl
//
//  Created by ChenKun on 2023/5/11.
//

#import <Foundation/Foundation.h>
@import IndustryDeviceKit;

NS_ASSUME_NONNULL_BEGIN


@interface IndustryFirmwareUpgradeModel : NSObject<IFirmwareUpgradeModel>

/// The update copywriting.
@property (nonatomic, copy) NSString  *desc;

/// The device type copywriting.
@property (nonatomic, copy) NSString *typeDesc;

/// Valid values: `0`: no later version. `1`: a later version available. `2`: updating. `5`: waiting for the device to wake up.
@property (nonatomic, assign) DeviceUpgradeStatus upgradeStatus;

/// The firmware version that is used in the later version.
@property (nonatomic, copy) NSString  *version;

/// The current firmware version in use.
@property (nonatomic, copy) NSString  *currentVersion;

/// The update timeout. Unit: seconds.
@property (nonatomic, assign) NSInteger timeout;

/// 0: app update notification. 2: app forced update. 3: update detection.
@property (nonatomic, assign) NSInteger upgradeType;

/// The firmware type.
@property (nonatomic, assign) NSInteger type;

// The device type. 0: normal device. 1: low-power non-keep-alive device.
@property (nonatomic, assign) NSInteger devType;

/// The download URL of the update firmware for Bluetooth devices.
@property (nonatomic, copy) NSString *url;

/// The firmware MD5 message-digest algorithm.
@property (nonatomic, copy) NSString *md5;

/// The size of the firmware package. Unit: bytes.
@property (nonatomic, copy) NSString *fileSize;

/// Firmware sign.
@property (nonatomic, copy) NSString *sign;

/// The last update time of the DP.
@property (nonatomic, assign) long long lastUpgradeTime;

/// The firmware release date.
@property (nonatomic, assign) long long firmwareDeployTime;

/// Indicates whether the update device is controllable. `1` : controllable. `0` : not controllable.
@property (nonatomic, assign) BOOL controlType;

/// The description of waiting for device wake-up. The low-power non-keep-alive device is in the state of "waiting for device wake-up" before an update.
@property (nonatomic, copy) NSString *waitingDesc;

/// The notification text in the firmware update.
@property (nonatomic, copy) NSString *upgradingDesc;

/// if the device has the ability to upgrade.can not upgrade like low power. It will be nil when device has not dp check.
@property (nonatomic, strong) NSNumber *canUpgrade;

/// the remind when device can not upgrade.Value can be nil.
@property (nonatomic, copy) NSString *remind;

/// the firmware sign hmac
@property (nonatomic, copy) NSString *hmac;

/// the firmware support differential packet or not
@property (nonatomic, assign) BOOL diffOta;

/// The firmware's local file path for upgrade used lan way.
@property (nonatomic, copy) NSString *filePath;

/// The firmware upgrade mode. (normal upgrade, pid version upgrade, ... )
@property (nonatomic, assign) DeviceUpgradeMode upgradeMode;

@end

NS_ASSUME_NONNULL_END
