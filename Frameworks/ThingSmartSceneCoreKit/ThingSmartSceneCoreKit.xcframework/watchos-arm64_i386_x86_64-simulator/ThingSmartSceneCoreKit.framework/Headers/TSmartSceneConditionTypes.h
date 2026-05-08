//
//  TSmartSceneConditionTypes.h
//  ThingSmartSceneCoreKit
//
//  Created by mile on 2023/7/13.
//

#ifndef TSmartSceneConditionTypes_h
#define TSmartSceneConditionTypes_h

/// The five geo fence type. Provide reach, exit, inside, outside and not set type.
typedef NS_ENUM(NSInteger, GeoFenceType) {
    /// The geo fence reach type.
    kGeoFenceTypeReach,
    /// The geo fence exit type.
    kGeoFenceTypeExit,
    /// The geo fence not set type.
    kGeoFenceTypeNotSet,
    /// The geo fence in type.
    kGeoFenceTypeIn,
    /// The geo fence out type.
    kGeoFenceTypeOut
};

/// The two types of expr data model. Provides whether and device types.
typedef NS_ENUM(NSInteger, ExprType) {
    /// The whether expr model type
    kExprTypeWhether,
    /// The device expr model type
    kExprTypeDevice
};

/// The Three types of expr data model. Provides not determine, rise and set types.
typedef NS_ENUM(NSInteger, SunType) {
    /// The sun not determine type
    kSunTypeNotDetermin,
    /// The sun rise
    kSunTypeRise,
    /// The sun set type
    kSunTypeSet
};

#endif /* TSmartSceneConditionTypes_h */
