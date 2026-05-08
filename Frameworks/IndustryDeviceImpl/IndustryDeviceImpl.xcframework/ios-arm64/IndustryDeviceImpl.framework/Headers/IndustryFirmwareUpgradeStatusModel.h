//
//  IndustryFirmwareUpgradeStatusModel.h
//  IndustryDeviceImpl
//
//  Created by ChenKun on 2023/5/11.
//

#import <Foundation/Foundation.h>
@import IndustryDeviceKit;

NS_ASSUME_NONNULL_BEGIN

@interface IndustryFirmwareUpgradeStatusModel : NSObject<IFirmwareUpgradeStatusModel>

/// The firmware update status.
@property (nonatomic, assign) DeviceUpgradeStatus upgradeStatus;
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
@property (nonatomic, assign) DeviceUpgradeMode upgradeMode;
/// The firmware update error info.
@property (nonatomic, strong, nullable) NSError *error;

@end

NS_ASSUME_NONNULL_END
