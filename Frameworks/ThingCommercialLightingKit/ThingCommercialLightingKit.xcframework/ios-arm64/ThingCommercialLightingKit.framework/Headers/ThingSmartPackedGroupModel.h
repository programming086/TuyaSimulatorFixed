//
//  ThingSmartPackedGroupModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingCommercialLightingKit/ThingLightingPublicEnum.h>

typedef NS_ENUM(NSUInteger, ThingSmartPackedGroupType) {
    ThingSmartPackedGroupEmptyType = 1, // empty group type
    ThingSmartPackedGroupStandardType = 2, // standard group type
    ThingSmartPackedGroupMixedType = 3, // mixed group type
};

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartGroupModel;
@class ThingSmartSchemaModel;

@interface ThingSmartPackedGroupModel : NSObject

/// The project ID.
@property (nonatomic, assign) long long projectId;

/// The packed group ID.
@property (nonatomic, strong) NSString *groupPackageId;

/// The area ID.
@property (nonatomic, assign) long long areaId;

/// The packed group name.
@property (nonatomic, strong) NSString *name;

/// Number of devices in the packed group.
@property (nonatomic, assign) NSInteger deviceNum;

/// Category of group
@property (nonatomic, assign) ThingSmartTopCategory topCategory;

/// Normal group within packed group.
@property (nonatomic, strong, readonly) NSArray<ThingSmartGroupModel*> *joinedGroupArray;

/// Type of group
@property (nonatomic, assign) ThingSmartPackedGroupType type;

/// data point of packed group.
@property (nonatomic, strong) NSDictionary *dps;

/// schema array of packed group.
@property (nonatomic, strong, readonly) NSArray <ThingSmartSchemaModel *> *schemaArray;

@end

NS_ASSUME_NONNULL_END

