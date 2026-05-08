//
//  ThingLightingAreaManager.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief ThingLightingAreaManager provides methds for developers to create single area.
@interface ThingLightingAreaManager : NSObject

/// Create a new indoor area
/// @param projectId Project ID
/// @param currentAreaId Current area ID(it may be the parent area of the new area or its child area.)
/// @param name Area name
/// @param roomLevel Area level
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
+ (void)createAreaWithProjectId:(long long)projectId
                  currentAreaId:(long long)currentAreaId
                           name:(NSString *)name
                      roomLevel:(NSInteger)roomLevel
                        success:(nullable ThingSuccessID)success
                        failure:(nullable ThingFailureError)failure;

/// Create a new outdoor area
/// @param projectId Project ID
/// @param currentAreaId Current area ID(it may be the parent area of the new area or its child area.)
/// @param name Area name
/// @param roomLevel Area level
/// @param longitude Longitude
/// @param latitude Latitude
/// @param address Area address
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
+ (void)createAreaWithProjectId:(long long)projectId
                  currentAreaId:(long long)currentAreaId
                           name:(NSString *)name
                      roomLevel:(NSInteger)roomLevel
                      longitude:(double)longitude
                       latitude:(double)latitude
                industryPurpose:(NSString *)industryPurpose
                   spacePurpose:(NSString *)spacePurpose
                        address:(nullable NSString *)address
                        success:(nullable ThingSuccessID)success
                        failure:(nullable ThingFailureError)failure;

/// Get simple area list
/// @param projectId Project ID
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
+ (void)getSimpleAreaListWithProjectId:(long long)projectId
                               success:(nullable ThingSuccessList)success
                               failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
