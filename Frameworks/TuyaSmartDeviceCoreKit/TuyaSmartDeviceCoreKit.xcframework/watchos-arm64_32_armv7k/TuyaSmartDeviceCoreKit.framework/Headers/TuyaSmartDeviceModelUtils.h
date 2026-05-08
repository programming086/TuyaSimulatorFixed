//
// TuyaSmartDeviceModelUtils.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartDeviceModelUtils_h
#define TuyaSmartDeviceModelUtils_h

/// The device update status.
typedef enum : NSUInteger {
    TuyaSmartDeviceUpgradeStatusDefault = 0,        ///< Default: No update is required.
    TuyaSmartDeviceUpgradeStatusReady = 1,          ///< Ready: The hardware is ready.
    TuyaSmartDeviceUpgradeStatusUpgrading = 2,      ///< Upgrading: The update is in progress.
    TuyaSmartDeviceUpgradeStatusSuccess = 3,        ///< Success: The update is completed.
    TuyaSmartDeviceUpgradeStatusFailure = 4,        ///< Failure: The update has an exception.
    TuyaSmartDeviceUpgradeStatusWaitingExectue = 5, ///< NB-IoT devices wait to execute NB-IoT tasks. Device tasks have been sent but not yet executed.
    TuyaSmartDeviceUpgradeStatusDownloaded = 6,     ///< NB-IoT devices have downloaded NB-IoT firmware.
    TuyaSmartDeviceUpgradeStatusTimeout = 7,        ///< Timeout: The update timed out.
    
    TuyaSmartDeviceUpgradeStatusLocalPrepare = 100, ///< LocalPrepare: The app local prepare status. (when the device is linking, switch to sub device, app downloding firmware ....)
} TuyaSmartDeviceUpgradeStatus;

/// The device update mode.
typedef NS_ENUM(NSUInteger, TuyaSmartDeviceUpgradeMode) {
    /// Normal upgrade
    TuyaSmartDeviceUpgradeModeNormal   = 0,
    /// Pid ( prouduct id ) version upgrade
    TuyaSmartDeviceUpgradeModePidVersion = 1,
};

#endif /* TuyaSmartDeviceModelUtils_h */
