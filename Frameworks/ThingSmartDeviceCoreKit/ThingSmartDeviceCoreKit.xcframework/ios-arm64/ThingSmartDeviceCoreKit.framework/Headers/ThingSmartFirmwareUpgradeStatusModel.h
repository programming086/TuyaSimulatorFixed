//
//  ThingSmartFirmwareUpgradeStatusModel.h
//  ThingSmartDeviceCoreKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import "ThingSmartDeviceModelUtils.h"
#import "NSError+ThingOTA.h"

NS_ASSUME_NONNULL_BEGIN

/// The device firmware update status.
@interface ThingSmartFirmwareUpgradeStatusModel : NSObject

/// The firmware update status.
@property (nonatomic, assign) ThingSmartDeviceUpgradeStatus upgradeStatus;
/// The firmware type.
@property (nonatomic, assign) NSInteger type;
/// The firmware update description.
@property (nonatomic, copy, nullable) NSString *statusText;
/// The title of the firmware update description.
@property (nonatomic, copy, nullable) NSString *statusTitle;
/// The group ota's task id.  When single device update, its value is <= 0.
@property (nonatomic, assign) long groupId;

/// The firmware update progress. ( sometime can be -1, please ignore when < 0. )
@property (nonatomic, assign) NSInteger progress;
/// The upgrade mode (normal, pid version, ... etc)
@property (nonatomic, assign) ThingSmartDeviceUpgradeMode upgradeMode;
/// The firmware update error info.
@property (nonatomic, strong, nullable) NSError *error;
/// Firmware upgrade remaining time
@property (nonatomic, assign) NSInteger remainTime;
@end

NS_ASSUME_NONNULL_END
