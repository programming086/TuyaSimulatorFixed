//
//  ThingSmartHomeModel.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import "ThingSmartHomeModelUtils.h"
#import "ThingSmartHomeCustomRoleListModel.h"

@interface ThingSmartHomeModel : NSObject

// The home ID.
@property (nonatomic, assign) long long homeId;

// The home name.
@property (nonatomic, strong) NSString *name;

// The home geographic location.
@property (nonatomic, strong) NSString *geoName;

// The latitude.
@property (nonatomic, assign) double latitude;

// The longitude.
@property (nonatomic, assign) double longitude;

// The home background pictures.
@property (nonatomic, strong) NSString *backgroundUrl;

// The order.
@property (nonatomic, assign) NSInteger displayOrder;

// The role type.
@property (nonatomic, assign) ThingHomeRoleType role;

// The state of the deal.
@property (nonatomic, assign) ThingHomeStatus dealStatus;

// Whether there are administrator rights restrictions
@property (nonatomic, strong) NSNumber * managementStatus;

// The inviter's name.
@property (nonatomic, strong) NSString *nickName;

// Custom Role
@property (nonatomic, strong) ThingSmartHomeCustomRoleModel *customRoleModel;

#pragma mark - deprecated
// Specifies whether the member is an administrator.
@property (nonatomic, assign) BOOL admin __deprecated_msg("This property is deprecated, Use role property");

+ (ThingSmartHomeModel *)homeModelWithHomeID:(long long)homeId;

@end

