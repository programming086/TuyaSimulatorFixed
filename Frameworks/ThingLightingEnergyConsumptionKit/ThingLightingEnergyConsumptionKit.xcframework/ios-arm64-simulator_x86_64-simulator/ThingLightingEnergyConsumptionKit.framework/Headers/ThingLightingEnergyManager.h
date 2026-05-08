//
//  ThingLightingEnergyManager.h
//  ThingBuilding
//
//  Copyright (c) 2014-2021 Thing (https://developer.thing.com/)

#import <Foundation/Foundation.h>
#import "ThingLightingEnergyOverviewDataModel.h"
#import "ThingLightingEnergyQuotaStatisticDataModel.h"
#import "ThingLightingEnergyCarbonEmissionDataModel.h"
#import "ThingLightingEnergyDataStatisticModel.h"
#import "ThingLightingEnergyChartFilterModel.h"

NS_ASSUME_NONNULL_BEGIN

/// interface of building energy
@interface ThingLightingEnergyManager : NSObject

- (instancetype)initWithProjectId:(long long)projectId NS_DESIGNATED_INITIALIZER;

/// Overall use of energy consumption
///
/// @param success Called when the task finished successfully
/// @param failure Called when the task is interrupted by an error
- (void)queryEnergyDataStatisticsWithSuccess:(void(^)(ThingLightingEnergyDataStatisticModel *result))success 
                                     failure:(void(^)(NSError *error))failure;

/// Query energy consumption overview data
///
/// @param success Called when the task finished successfully
/// @param failure Called when the task is interrupted by an error
- (void)queryOverviewChartDataWithSuccess:(void(^)(ThingLightingEnergyOverviewDataModel *result))success 
                                  failure:(void(^)(NSError *error))failure;

/// Query quota energy statistic data
///
/// @param success Called when the task finished successfully
/// @param failure Called when the task is interrupted by an error
- (void)queryQuotaEnergyChartDataWithSuccess:(void(^)(ThingLightingEnergyQuotaStatisticDataModel *result))success 
                                     failure:(void(^)(NSError *error))failure;

/// Query carbon emission chart data
///
/// @param success Called when the task finished successfully
/// @param failure Called when the task is interrupted by an error
- (void)queryCarbonEmissionChartDataWithFilter:(ThingLightingEnergyChartFilterModel *)filter 
                                       success:(void(^)(ThingLightingEnergyCarbonEmissionDataModel *result))success 
                                       failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
