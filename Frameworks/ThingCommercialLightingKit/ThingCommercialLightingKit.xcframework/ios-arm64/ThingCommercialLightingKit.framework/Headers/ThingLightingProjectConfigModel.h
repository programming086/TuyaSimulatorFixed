//
//  ThingLightingProjectConfigModel.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingCommercialLightingKit/ThingCLProjectPublicEnum.h>


NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingProjectValidationItemModel : NSObject

/// Min value
@property (nonatomic, assign) NSUInteger min;

/// Max value
@property (nonatomic, assign) NSUInteger max;

@end

@interface ThingLightingProjectSpaceItemModel : NSObject

/// Space name
@property (nonatomic, strong) NSString *name;

/// Space icon url
@property (nonatomic, strong) NSString *iconUrl;

/// Space level
@property (nonatomic, assign) NSInteger roomLevel;

@end

@interface ThingLightingProjectConfigModel : NSObject

@property (nonatomic, assign) BOOL createAble;

/// Project type
@property (nonatomic, assign) ThingLightingProjectType projectType;

/// Project type name
@property (nonatomic, strong) NSString *projectTypeName;

/// Project icon url
@property (nonatomic, strong) NSString *projectIconUrl;

/// Space attributes
@property (nonatomic, strong) NSArray <ThingLightingProjectSpaceItemModel *>*spaceAttributes;

/// Project validation condition that used to valid input
@property (nonatomic, strong) NSDictionary<NSString *, ThingLightingProjectValidationItemModel *> *validationConditions;

@end

NS_ASSUME_NONNULL_END
