//
//  ThingLightingRegionManager.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingRegionModel;

/// @brief ThingLightingRegionManager provides methds for developers to get region list.
@interface ThingLightingRegionManager : NSObject

/// Get a list of countries and first-level administrative regions
/// @param success Called when the task finishes successfully.
/// @param failure  If error occurred while adding the task, this block will be called.
- (void)getRegionListWithSuccess:(nullable void(^)(NSArray<ThingLightingRegionModel *> *regionList))success
                         failure:(nullable void(^)(NSError *error))failure;

@end

@interface ThingLightingRegionManager (ThingLightingCache)

/// Get the country list cache, if there is no data, please call the getRegionListWithRegionCode:success:failure: method first
/// @return Region list
- (NSArray<ThingLightingRegionModel *> *)getFirstLevelRegionListFromCache;

/// Get the lower level administrative region list cache, if there is no data, please call the getRegionListWithRegionCode:success:failure: method first
/// @param locationId Location ID
/// @return Region list
//- (NSArray<ThingLightingRegionModel *> *)getSubRegionListFromCacheWithLocationId:(NSString *)locationId;

@end

NS_ASSUME_NONNULL_END
