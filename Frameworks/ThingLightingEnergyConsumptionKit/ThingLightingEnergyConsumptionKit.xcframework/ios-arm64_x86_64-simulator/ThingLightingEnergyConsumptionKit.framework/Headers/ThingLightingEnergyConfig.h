//
//  ThingLightingEnergyConfig.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightingEnergyBuildingAreaModel.h"
#import "ThingLightingEnergyChartConfigModel.h"
#import "ThingLightingEnergyConfigInfoModel.h"
#import "ThingLightingEnergyDefaultConfigModel.h"

NS_ASSUME_NONNULL_BEGIN

/// interface of building energy
@interface ThingLightingEnergyConfig : NSObject

- (instancetype)initWithProjectId:(long long)projectId NS_DESIGNATED_INITIALIZER;

/// query project area configuration
///
/// @param success Called when the task finished successfully
/// @param failure Called when the task is interrupted by an error
- (void)queryEnergyBuildingAreaWithSuccess:(void(^)(ThingLightingEnergyBuildingAreaModel *result))success 
                                   failure:(void(^)(NSError *error))failure;

/// Save project area configuration
///
/// @param buildingArea building area
/// @param hvacArea HVAC area
/// @param success Called when the task finished successfully
/// @param failure Called when the task is interrupted by an error
- (void)saveBuildingAreaConfigWithBuildingArea:(double)buildingArea 
                                      hvacArea:(double)hvacArea 
                                       success:(void(^)(BOOL result))success 
                                       failure:(void(^)(NSError *error))failure;

/// query energy chart configuration, Be sure to call this method before querying chart related interfaces
///
/// @param success Called when the task finished successfully
/// @param failure Called when the task is interrupted by an error
- (void)queryEnergyChartConfigWithSuccess:(void(^)(NSArray<ThingLightingEnergyChartConfigModel *>*result))success 
                                  failure:(void(^)(NSError *error))failure;

/// Save energy consumption quota settings
///
/// @param success Called when the task finished successfully
/// @param failure Called when the task is interrupted by an error
- (void)saveEnergyQuotaConfigWithConfig:(ThingLightingEnergyConfigInfoModel *)config 
                                success:(void(^)(BOOL result))success 
                                failure:(void(^)(NSError *error))failure;

/// Query the default recommended proportion of products
///
/// @param success Called when the task finished successfully
/// @param failure Called when the task is interrupted by an error
- (void)queryDefaultConfigWithSuccess:(void(^)(ThingLightingEnergyDefaultConfigModel *result))success 
                              failure:(void(^)(NSError *error))failure;

@end

@interface ThingLightingEnergyConfig (Cache)

/// Query quota energy chart config from cache by projectId, please call queryEnergyChartConfig method first
- (ThingLightingEnergyConfigInfoModel *)queryQuotaEnergyChartConfigFromCache;

/// clear energy chart config cache
- (void)clearEnergyChartConfigCache;

@end

NS_ASSUME_NONNULL_END
