//
//  ThingSmartPackedGroupManager.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>
#import <ThingCommercialLightingKit/ThingLightingPublicEnum.h>

@class ThingSmartPackedGroupModel;

NS_ASSUME_NONNULL_BEGIN

typedef void (^ThingLightingPackedGroupCreateSuccess)(ThingSmartPackedGroupModel *groupModel,
                                                      NSArray<NSString *> *successDevIds,
                                                      NSDictionary<NSString *,NSNumber *> * failedInfos);

@interface ThingSmartPackedGroupManager : NSObject

/// Create a packed group under the specified project
/// @param projectId The project ID.
/// @param areaId The area ID.
/// @param groupPackName The packed group name.
/// @param addDevices Devices that need to be added to the packed group.
/// @param topCategory Need to create the category of packed group.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)createPackedGroupWithProjectId:(long long)projectId
                                areaId:(long long)areaId
                         groupPackName:(NSString *)groupPackName
                            addDevices:(NSArray<NSString *> *)addDevices
                           topCategory:(ThingSmartTopCategory)topCategory
                               success:(nullable ThingLightingPackedGroupCreateSuccess)success
                               failure:(nullable ThingFailureError)failure;


/// Create a packed group under the specified project
/// @param projectId The project ID.
/// @param areaId The area ID.
/// @param deviceId The device ID.
/// @param groupPackName The packed group name.
/// @param addDevices Devices that need to be added to the packed group.
/// @param topCategory Need to create the category of packed group.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)createPackedGroupWithProjectId:(long long)projectId
                                areaId:(long long)areaId
                              deviceId:(NSString *)deviceId
                         groupPackName:(NSString *)groupPackName
                            addDevices:(NSArray<NSString *> *)addDevices
                           topCategory:(ThingSmartTopCategory)topCategory
                               success:(nullable ThingLightingPackedGroupCreateSuccess)success
                               failure:(nullable ThingFailureError)failure;


/// Get packed group list.
/// @param projectId The project ID.
/// @param areaId The area ID.
/// @param limit Number of pages.
/// @param offsetKey Identifier of the current page. The default is @"1"
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)getPackedGroupListWithProjectId:(long long)projectId
                                 areaId:(long long)areaId
                                  limit:(NSInteger)limit
                              offsetKey:(NSString *)offsetKey
                                success:(void (^)(NSArray<ThingSmartPackedGroupModel *> *groups,
                                                  NSString *nextOffsetKey,
                                                  NSInteger total,
                                                  BOOL end))success
                                failure:(nullable ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END
