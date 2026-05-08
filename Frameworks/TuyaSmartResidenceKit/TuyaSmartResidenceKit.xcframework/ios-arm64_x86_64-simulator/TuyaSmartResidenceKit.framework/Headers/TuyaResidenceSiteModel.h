//
//  TuyaResidenceSiteModel.h
//  TuyaSmartResidenceKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <Foundation/Foundation.h>
#import "TuyaResidentSiteModelUtils.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaResidenceSiteModel : NSObject

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
@property (nonatomic, assign) TYSiteRoleType role;

// The state of the deal. Only siteType is valid for TYSmartSiteType_Home.
@property (nonatomic, assign) TYSiteStatus dealStatus;

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

// Authorization start time. Only siteType is TYSmartSiteType_Bisiness and TYSmartSiteType_Access is valid.
@property (nonatomic, assign) NSTimeInterval authStartTime;

// Authorization end time. Only siteType for TYSmartSiteType_Bisiness and TYSmartSiteType_Access is valid.
@property (nonatomic, assign) NSTimeInterval authEndTime;

// Limit the number of members.
@property (nonatomic, assign) NSInteger memberLimit;

// The status of the site for the current user. Only siteType of TYSmartSiteType_Bisiness and TYSmartSiteType_Access are valid.
@property (nonatomic, assign) TYSiteAuthStatus authStatus;

// Whether to authorize the site identifier for the b-side account, true-yes, false-no
@property (nonatomic, assign) BOOL businessAuth;

// Site Type
@property (nonatomic, assign) TYSmartSiteType siteType;

@end

NS_ASSUME_NONNULL_END
