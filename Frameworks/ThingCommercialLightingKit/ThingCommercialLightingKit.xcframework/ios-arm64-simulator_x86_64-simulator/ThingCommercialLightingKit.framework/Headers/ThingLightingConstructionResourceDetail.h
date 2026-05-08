//
//  ThingLightingConstructionResourceDetail.h
//  ThingCommercialLightingKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import "ThingLightingResourcePoolModel.h"
#import "ThingLightingMeshModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingConstructionResourceDetail : NSObject

@property (nonatomic, strong) NSString *alias;
@property (nonatomic, assign) long long gid;
@property (nonatomic, strong) ThingLightingMeshModel *mesh;
@property (nonatomic, strong) NSArray<NSString *> *defaultGroups;
@property (nonatomic, strong) ThingLightingResourcePoolModel *resources;

@end

NS_ASSUME_NONNULL_END
