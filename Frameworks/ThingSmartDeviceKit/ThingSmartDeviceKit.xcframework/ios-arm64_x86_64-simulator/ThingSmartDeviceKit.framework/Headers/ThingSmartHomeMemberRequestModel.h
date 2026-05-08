//
//  ThingSmartHomeMemberRequestModel.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import "ThingSmartHomeModelUtils.h"
#import "ThingSmartHomeCustomRoleListModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartHomeMemberRequestModel : NSObject

/// The member ID. It is a required field.
@property (nonatomic, assign) long long memberId;

/// The member's name. If the value is set to nil, the existing name is not updated.
@property (nonatomic, strong) NSString *name;

/// The member's role. Set the required role type. If you do not want to update the role type, keep the current role type or set it to "ThingHomeRoleType_Unknown".
@property (nonatomic, assign) ThingHomeRoleType role;

/// The member's role ID.
@property (nonatomic, assign) long long roleId;

/// The members' avatars. If the value is set to nil, the existing avatars are not updated.
@property (nonatomic, strong) UIImage *headPic;

@end


@interface ThingSmartHomeResourceRequestModel : NSObject

/// The home ID. It is a required field.
@property (nonatomic, assign) long long homeId;

/// The resource's type. It is a required field.
@property (nonatomic, assign) ThingHomeRoleResourceType resourceType;

/// The resource's roomIds. It is a required field.
@property (nonatomic, strong) NSString *roomIds;

/// The device's categoryIds. It is a required field.
@property (nonatomic, strong) NSString  *categoryIds;

/// The resource's control types. It is a required field. "0" control by device, "1" control by group
@property (nonatomic, strong) NSString *controlTypes;

/// The resource was not assigned room. It is a required field.
/// If it is yes, show all devices and scenes were not assigned rooms.
@property (nonatomic, assign) BOOL notAssignedRoom;

@end

NS_ASSUME_NONNULL_END
