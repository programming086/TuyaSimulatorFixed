//
//  ThingSmartHomeMemberModel.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import "ThingSmartHomeModelUtils.h"

@class ThingSmartHomeCustomRoleModel;

@interface ThingSmartHomeMemberModel : NSObject

// The member ID.
@property (nonatomic, assign) long long memberId;

// The avatars of members.
@property (nonatomic, strong) NSString *headPic;

// The names of members.
@property (nonatomic, strong) NSString *name;

// The role.
@property (nonatomic, assign) ThingHomeRoleType role;

// The home ID.
@property (nonatomic, assign) long long homeId;

// The mobile phone number.
@property (nonatomic, strong) NSString *mobile;

// The username.
@property (nonatomic, strong) NSString *userName;

// The user ID.
@property (nonatomic, strong) NSString *uid;

// The state of the deal.
@property (nonatomic, assign) ThingHomeStatus dealStatus;

// The Custom role model.
@property (nonatomic, strong) ThingSmartHomeCustomRoleModel *customRoleModel;

#pragma mark - deprecated
// Specifies whether the member is an administrator.
@property (nonatomic, assign) BOOL isAdmin __deprecated_msg("The property will be deprecated and remove in a future version. Please use the role");

@end
