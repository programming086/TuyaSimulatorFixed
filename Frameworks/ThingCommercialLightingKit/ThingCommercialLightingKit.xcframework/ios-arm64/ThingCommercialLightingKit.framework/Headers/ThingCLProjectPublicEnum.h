//
//  ThingCLProjectPublicEnum.h
//  Pods
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#ifndef ThingCLProjectPublicEnum_h
#define ThingCLProjectPublicEnum_h


/// Project type
typedef NS_ENUM(NSUInteger, ThingLightingProjectType) {
    /// Indoor project
    ThingLightingProjectTypeIndoor = 0,
    /// Outdoor project
    ThingLightingProjectTypeOutdoor,
    /// park project
    ThingLightingProjectTypePark,
};

// project mesh mode
typedef enum : NSUInteger {
    ThingLightingProjectMeshModeNone = 99,  // unknown
    ThingLightingProjectMeshModeSingle = 0, // single mesh
    ThingLightingProjectMeshModeMulti = 1,  // multi mesh
} ThingLightingProjectMeshMode;

#endif /* ThingCLProjectPublicEnum_h */
