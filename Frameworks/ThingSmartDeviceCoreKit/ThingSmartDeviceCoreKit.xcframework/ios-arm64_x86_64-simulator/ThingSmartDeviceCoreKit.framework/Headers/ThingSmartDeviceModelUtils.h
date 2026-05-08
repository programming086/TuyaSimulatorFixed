//
//  ThingSmartDeviceModelUtils.h
//  ThingSmartDeviceCoreKit
//
//  Copyright (c) 2014-2024.
//

#ifndef ThingSmartDeviceModelUtils_h
#define ThingSmartDeviceModelUtils_h

/// The device update status.
typedef enum : NSUInteger {
    ThingSmartDeviceUpgradeStatusDefault = 0,        ///< Default: No update is required.
    ThingSmartDeviceUpgradeStatusReady = 1,          ///< Ready: The hardware is ready.
    ThingSmartDeviceUpgradeStatusUpgrading = 2,      ///< Upgrading: The update is in progress.
    ThingSmartDeviceUpgradeStatusSuccess = 3,        ///< Success: The update is completed.
    ThingSmartDeviceUpgradeStatusFailure = 4,        ///< Failure: The update has an exception.
    ThingSmartDeviceUpgradeStatusWaitingExectue = 5, ///< NB-IoT devices wait to execute NB-IoT tasks. Device tasks have been sent but not yet executed.
    ThingSmartDeviceUpgradeStatusDownloaded = 6,     ///< NB-IoT devices have downloaded NB-IoT firmware.
    ThingSmartDeviceUpgradeStatusTimeout = 7,        ///< Timeout: The update timed out.
    ThingSmartDeviceUpgradeStatusInQueue = 13,         ///< InQueue: The update is in the queue.
    
    ThingSmartDeviceUpgradeStatusLocalPrepare = 100, ///< LocalPrepare: The app local prepare status. (when the device is linking, switch to sub device, app downloding firmware ....)
} ThingSmartDeviceUpgradeStatus;

/// The device update mode.
typedef NS_ENUM(NSUInteger, ThingSmartDeviceUpgradeMode) {
    /// Generic firmware update. (General update such as MCU, WiFi, BLE and other hardware module firmware in the device.)
    ThingSmartDeviceUpgradeModeNormal   = 0,
    /// Update PID-specific firmware. (General update such as product schema, panel settings, multilingual settings, and shortcut control)
    ThingSmartDeviceUpgradeModePidVersion = 1,
};

#endif /* ThingSmartDeviceModelUtils_h */
