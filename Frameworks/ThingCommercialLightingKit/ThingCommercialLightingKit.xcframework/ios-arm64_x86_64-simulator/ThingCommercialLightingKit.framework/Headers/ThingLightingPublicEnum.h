//
//  ThingLightingPublicEnum.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#ifndef ThingLightingPublicEnum_h
#define ThingLightingPublicEnum_h

/// Device category
typedef NS_ENUM(NSUInteger, ThingSmartTopCategory) {
    /// Lighting
    ThingSmartTopCategoryZM,
    /// Electrician lighting
    ThingSmartTopCategoryDGZM,
    /// Home appliance
    ThingSmartTopCategoryDJD,
    /// Security sensing
    ThingSmartTopCategoryJJAF,
    /// Energy-saving
    ThingSmartTopCategoryJNNY,
    /// Other
    ThingSmartTopCategoryOther
};


/// Join status of device.
typedef NS_ENUM(NSUInteger, ThingLightingMasterGroupJoinStatus) {
    /// The lighting device is not join to the master group
    ThingLightingMasterGroupJoinStatusNot = 0,
    /// The lighting device is joined to the master group
    ThingLightingMasterGroupJoinStatusNormal,
    /// Non-lighting device is not join to the master group
    ThingLightingMasterGroupJoinStatusNotOter,
};

/// The error type of the device joining the packed group
typedef NS_ENUM(NSUInteger, ThingLightingDeviceJoinGroupError) {
    /// The device joins the packed group timeout
    ThingLightingDeviceJoinGroupTimeout = 1,
    /// The packed group that the device has joined is empty
    ThingLightingDeviceJoinGroupEmpty,
    /// The group that the device has joined is full
    ThingLightingDeviceJoinGroupFull,
    /// Other errors when the device joins the packed group
    ThingLightingDeviceJoinGroupException,
};

typedef NS_ENUM(NSUInteger, ThingLightingUpgradeGroupStatus) {
    ThingLightingGroupNotUpgradeable = 0,
    ThingLightingGroupUpgradeable,
    ThingLightingGroupUpgrading,
    ThingLightingGroupUpgradeSuccessed,
    ThingLightingGroupUpgradeFailed,
    ThingLightingGroupWaitingForUpgrade
};

#endif /* ThingLightingPublicEnum_h */
