//
//  ThingResidenceSiteModel.h
//  ThingSmartResidenceKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingResidentSiteModelUtils.h"

// 抽取到basickit中避免repeat error
typedef NS_ENUM(NSInteger, ThingSiteAuthStatus);
typedef NS_ENUM(NSInteger, ThingSmartSiteType);
typedef NS_ENUM(NSInteger, ThingSmartSiteAccesssSource);

NS_ASSUME_NONNULL_BEGIN

@interface ThingResidenceSiteModel : NSObject

// The home ID.
@property (nonatomic, assign) long long siteId;

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
@property (nonatomic, assign) ThingSiteRoleType role;

// The state of the deal. Only siteType is valid for ThingSmartSiteType_Home.
@property (nonatomic, assign) ThingSiteStatus dealStatus;

// The inviter's name.
@property (nonatomic, strong) NSString *nickName;

// The dg id.
@property (nonatomic, strong) NSArray<NSNumber *> *dgIds;

// Type of Passenger.
@property (nonatomic, assign) NSInteger accessUserType;

// The group user ID.
@property (nonatomic, assign) long long groupUserId;

// Full name of the property
@property (nonatomic, copy) NSString *spaceFullName;

// Project Name
@property (nonatomic, copy) NSString *projectName;

// Project Address Location
@property (nonatomic, copy) NSString *projectLocation;

// Authorization start time. Only siteType is ThingSmartSiteType_Bisiness and ThingSmartSiteType_Access is valid.
@property (nonatomic, assign) NSTimeInterval authStartTime;

// Authorization end time. Only siteType for ThingSmartSiteType_Bisiness and ThingSmartSiteType_Access is valid.
@property (nonatomic, assign) NSTimeInterval authEndTime;

// Limit the number of members.
@property (nonatomic, assign) NSInteger memberLimit;

// The status of the site for the current user. Only siteType of ThingSmartSiteType_Bisiness and ThingSmartSiteType_Access are valid.
@property (nonatomic, assign) ThingSiteAuthStatus authStatus;

// Whether to authorize the site identifier for the b-side account, true-yes, false-no
@property (nonatomic, assign) BOOL businessAuth;

// Site Type
@property (nonatomic, assign) ThingSmartSiteType siteType;

// 通行家庭类型来源(1代表来源C端家庭,2代表来源B2C家庭,0代表这个家庭是非通行家庭)
@property (nonatomic, assign) ThingSmartSiteAccesssSource accessSiteType;

@end

NS_ASSUME_NONNULL_END
