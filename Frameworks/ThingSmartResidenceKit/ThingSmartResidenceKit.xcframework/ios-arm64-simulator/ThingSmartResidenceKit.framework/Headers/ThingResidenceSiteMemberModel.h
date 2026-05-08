//
//  ThingResidenceSiteMemberModel.h
//  ThingSmartResidenceKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingResidentSiteModelUtils.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingResidenceSiteMemberModel : NSObject

// The member ID.
@property (nonatomic, assign) long long memberId;

// The avatars of members.
@property (nonatomic, strong) NSString *headPic;

// The names of members.
@property (nonatomic, strong) NSString *name;

// The role.
@property (nonatomic, assign) ThingSiteRoleType role;

// The site ID.
@property (nonatomic, assign) long long siteId;

// The mobile phone number.
@property (nonatomic, strong) NSString *mobile;

// The username.
@property (nonatomic, strong) NSString *userName;

// The user ID.
@property (nonatomic, strong) NSString *uid;

// The state of the deal.
@property (nonatomic, assign) ThingSiteStatus dealStatus;

#pragma mark - deprecated
// Specifies whether the member is an administrator.
@property (nonatomic, assign) BOOL isAdmin __deprecated_msg("The property will be deprecated and remove in a future version. Please use the role");


@end

NS_ASSUME_NONNULL_END
