//
//  ThingSmartHomeCustomRoleRequestModel.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import "ThingSmartHomeModelUtils.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartHomeCustomRoleRequestModel : NSObject

/// The home ID. It is a required field.
@property (nonatomic, assign) long long homeId;

/// The role's name. The name cannot be empty during creation.
@property (nonatomic, strong) NSString *roleName;

/// The role's type. Set the required role type.
@property (nonatomic, assign) ThingHomeRoleType role;

/// The role ID. The roldId cannot be empty during Modification.
@property (nonatomic, assign) long long roleId;

/// The role' resource. Enter the format(JSON String format) of the parameters:
/// [ {"resId":"deviceId","resType":0}, {"resId":"automationId","resType":1} ].
/// When resType is 0, it represents the device and resId represents the device ID.
/// When resType is 1, it represents the automation and resId represents the automation ID.
/// When resType is 2, it represents the One-click execution and resId represents the One-click execution ID.
@property (nonatomic, strong) NSString *permissionStr;


@end

NS_ASSUME_NONNULL_END
