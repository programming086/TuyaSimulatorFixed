//
//  ThingLightingAreaModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

@class ThingSmartGroupModel, ThingSmartSchemaModel;

/// Area type.
typedef NS_ENUM(NSUInteger, ThingLightingAreaType) {
    ThingLightingAreaTypeNormal  = 1,    // User-created area
    ThingLightingAreaTypeUnZoned = 2,    // Unzoned area
    ThingLightingAreaTypePublic  = 3     // Public area
};

/// Ability to create area.
typedef NS_ENUM(NSUInteger, ThingLightingAreaCreateStatus) {
    ThingLightingAreaCreateStatusUnable  = 0,        // Unable create
    ThingLightingAreaCreateStatusNext    = 1,        // Only create lower area
    ThingLightingAreaCreateStatusPre     = 2,        // Only create upper area
    ThingLightingAreaCreateStatusBoth    = 3         // Can create upper and lower area
};

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingAreaSpacePurposeModel;

/// @brief Area model
@interface ThingLightingAreaModel : NSObject

/// Project ID. (G ID of the root area.)
@property (nonatomic, assign) long long projectId;

/// G ID of current area.
@property (nonatomic, assign) long long gId;

/// Mesh ID of current area.
@property (nonatomic, strong) NSString * meshId;

/// Area ID
@property (nonatomic, assign) long long areaId;

/// Area name
@property (nonatomic, strong) NSString *name;


@property (nonatomic, strong) NSString *fullName;

/// Upper area ID
@property (nonatomic, assign) long long parentAreaId;

/// ThingLightingAreaType enum
@property (nonatomic, assign) ThingLightingAreaType roomSource;

/// Read only
@property (nonatomic, assign) BOOL readOnly;

/// Total number of devices in the area
@property (nonatomic, strong) NSNumber *clientCount;

/// Number of offline devices in the area and corresponding sub-area
@property (nonatomic, strong) NSNumber *offlineCount;

@property (nonatomic, strong) NSNumber *bluetoothOfflineCount;

/// Number of lighting devices in the area and corresponding sub-area
@property (nonatomic, strong) NSNumber *lightingClientCount;

/// The number of sub-areas under this area that is used by the APP to determine whether the floor is a display area list or a device list.
@property (nonatomic, strong) NSNumber *nextLevelAreaCount;

/// Whether to display the shortcut switch
@property (nonatomic, strong) NSNumber *quickSwitchStatus;

/// Whether to collected
@property (nonatomic, strong) NSNumber *collectionStatus;

/// The parent area where the area is located (A•12 floor), currently only returned in the collect list interface.
@property (nonatomic, strong) NSString *tag;

/// Area level, the specific value is obtained according to the config interface, corresponding to the id field it returns.
@property (nonatomic, assign) NSInteger roomLevel;

/// The ability to create area: 0 means that it cannot be created, 1 means that only lower-level areas can be created, 2 means that only upper-level areas can be created, 3 means that lower-level and upper-level areas can be created
@property (nonatomic, strong) NSNumber *canCreateStatus;

/// Area dp list
@property (nonatomic, strong) NSDictionary *dps;

/// Sub area list
@property (nonatomic, strong, readonly) NSArray <ThingLightingAreaModel *> *areaList;

/// Longitude
@property (nonatomic, assign) double longitude;

/// Latitude
@property (nonatomic, assign) double latitude;

/// Address
@property (nonatomic, strong) NSString *address;

@property (nonatomic, strong, nullable) ThingLightingAreaSpacePurposeModel *industryPurpose;
@property (nonatomic, strong, nullable) ThingLightingAreaSpacePurposeModel *spacePurpose;

@property (nonatomic, strong) NSArray<ThingLightingAreaModel *> *areas;


@end


/// @brief Area info model
@interface ThingLightingAreaInfoModel : NSObject

/// Total number of devices in the area
@property (nonatomic, assign) NSInteger totalRoomDeviceCount;

/// Area list
@property (nonatomic, strong) NSArray<ThingLightingAreaModel *> *list;

@end

NS_ASSUME_NONNULL_END

