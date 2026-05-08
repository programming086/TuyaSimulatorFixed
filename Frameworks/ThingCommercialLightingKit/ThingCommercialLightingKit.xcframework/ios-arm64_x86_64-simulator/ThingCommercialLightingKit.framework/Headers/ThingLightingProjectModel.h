//
//  ThingLightingProjectModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingCommercialLightingKit/ThingCLProjectPublicEnum.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const Thing_SMART_PROJECT_CONTROL_SMART;
FOUNDATION_EXPORT NSString *const Thing_SMART_PROJECT_CONTROL_LOCAL;
FOUNDATION_EXPORT NSString *const Thing_SMART_PROJECT_CONTROL_REMOTE;


typedef NS_ENUM(NSInteger, ThingLightingProjectRole) {
    ThingLightingProjectRole_Unknown = -999,  /**< Invalid role */
    ThingLightingProjectRole_Custom  = -1,  /**< Customized role */
    ThingLightingProjectRole_Member  = 0,   /**< General project member */
    ThingLightingProjectRole_Admin,         /**< Project administrator, no add delete other administrator privileges. */
    ThingLightingProjectRole_Owner,         /**< Project super administrator, owner */
};

@interface ThingLightingProjectModel : NSObject

@property (nonatomic, assign) long long projectId;

/// Is multi SigMesh prject or not.
@property (nonatomic, assign) ThingLightingProjectMeshMode networkType;

/// project name
@property (nonatomic, copy) NSString *name;

/// project geographic location
@property (nonatomic, copy) NSString *geoName;

/// latitude
@property (nonatomic, assign) double latitude;

/// longitude
@property (nonatomic, assign) double longitude;

/// project background pictures
@property (nonatomic, copy) NSString *backgroundUrl;

/// project leader name
@property (nonatomic, copy) NSString *leaderName;

/// project leader mobile or email
@property (nonatomic, copy) NSString *leaderMobile;

/// all device count
@property (nonatomic, assign) NSInteger clientCount;


/// energy consumption
@property (nonatomic, copy) NSString *power;

/// project detail address
@property (nonatomic, copy) NSString *detail;

/// project type
@property (nonatomic, assign) ThingLightingProjectType projectType;

/// project region location id
@property (nonatomic, copy) NSString *regionLocationId;

/// project type name
@property (nonatomic, copy) NSString *projectTypeName;

/// project icon url
@property (nonatomic, copy) NSString *projectIconUrl;

/// The display order
@property (nonatomic, assign) NSInteger displayOrder;

/// The state of deal
@property (nonatomic, assign) NSInteger dealStatus;

/// The role type
@property (nonatomic, assign) ThingLightingProjectRole role;


@property (nonatomic, assign) BOOL isFamilyPlus;

@property (nonatomic, assign) BOOL isTrial;

#pragma mark - deprecated
// admin or not
@property (nonatomic, assign) BOOL admin __deprecated_msg("This property is deprecated, Use role property");

@end

NS_ASSUME_NONNULL_END
