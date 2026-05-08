//
//  ThingSmartPackedGroup.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

#import <ThingCommercialLightingKit/ThingLightingPublicEnum.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ThingLightingPackedGroupEditComplete)(NSArray<NSString *> *addSuccessDevIds,
                                                    NSDictionary<NSString *,NSNumber *> * addFailedInfos,
                                                    NSArray<NSString *> *deleteSuccessDevIds,
                                                    NSDictionary<NSString *,NSNumber *> * removeFailedInfos);

@class ThingSmartPackedGroupModel;
@class ThingSmartDeviceModel;

@interface ThingSmartPackedGroup : NSObject

/// Returns the model of packed group information.
@property (nonatomic, strong, readonly) ThingSmartPackedGroupModel *packedGroupModel;

/// Get area dp points.
@property (nonatomic, strong, readonly) NSDictionary *dps;

/// Get switch status.
@property (nonatomic, assign, readonly) BOOL switchStatus;

/// Fetch scene data.
@property (nonatomic, strong, readonly) NSString *sceneStatus;

/// Fetch work mode.
@property (nonatomic, strong, readonly) NSString *workMode;

/// Fetch bright value that is limited to 0 to 100.
@property (nonatomic, assign, readonly) NSInteger brightPercent;

/// Fetch temperature value that is limited to 0 to 100.
@property (nonatomic, assign, readonly) NSInteger temperaturePercent;

/// Fetch colored light data.
@property (nonatomic, strong, readonly) NSString *colorData;


- (instancetype)init NS_UNAVAILABLE;


/// Get ThingSmartPackedGroup instance.
/// @param groupId The packed group ID.
/// @param projectId The project ID.
- (instancetype)initWithGroupId:(NSString *)groupId projectId:(long long)projectId NS_DESIGNATED_INITIALIZER;


/// Returns the ThingSmartPackedGroup instance. If the current user does not have this group, a value of nil is returned.
/// @param groupId The packed group ID.
/// @param projectId The project ID.
+ (nullable instancetype)groupWithGroupId:(NSString *)groupId projectId:(long long)projectId;


+ (NSInteger)currentGroupCountWithProjectId:(long long)projectId;


/// Edit packed group.
/// @param addDevices Devices that need to be added to the packed group.
/// @param deleteDevices Devices that need to be removed to the packed group.
/// @param complete Called when the task is finished.
- (void)editPackedGroupWithAddDevices:(NSArray<NSString *> *)addDevices
                        deleteDevices:(NSArray<NSString *> *)deleteDevices
                             complete:(nullable ThingLightingPackedGroupEditComplete)complete;

/// Dismiss paceked group.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)dismissWithSuccess:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure;


/// Rename packed group
/// @param name The new name.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)renamePackedGroupWithName:(NSString *)name
                          success:(nullable ThingSuccessHandler)success
                          failure:(nullable ThingFailureError)failure;

/// Get packed group details.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getPackedGroupInfoWithSuccess:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;



/// Get the devices that can be added to the packed group, if checked in the packed group, YES is returned
/// @param areaId The area ID.
/// @param topCategory Need to create the category of packed group.
/// @param limit Number of pages.
/// @param offsetKey Identifier of the current page. The default is @"1"
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getAvailableDevices2JoinPackedGroupWithAreaId:(long long)areaId
                                          topCategory:(ThingSmartTopCategory)topCategory
                                                limit:(NSInteger)limit
                                            offsetKey:(NSString *)offsetKey
                                              success:(nullable void(^)(NSArray <ThingSmartDeviceModel *> *devices, NSString *nextOffsetKey, BOOL  end))success
                                              failure:(nullable ThingFailureError)failure;

/// Get devices that can be added to a group, and if they are already checked in the group, return "YES".
/// @param areaId Area ID
/// @param topCategory Top-level category, supporting all categories under "ThingSmartTopCategory".
/// @param limit Number of items per page
/// @param offsetKey Page number key
/// @param deviceId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)getAvailableDevices2JoinPackedGroupWithAreaId:(long long)areaId
                                          topCategory:(ThingSmartTopCategory)topCategory
                                                limit:(NSInteger)limit
                                            offsetKey:(NSString *)offsetKey
                                             deviceId:(NSString *)deviceId
                                              success:(nullable void(^)(NSArray <ThingSmartDeviceModel *> *devices, NSString *nextOffsetKey, BOOL  end))success
                                              failure:(nullable ThingFailureError)failure;
/// Get devices that can be added to a group, and if they are already checked in the group, return "YES".
/// @param areaId Area ID
/// @param topCategory Top-level category, supporting all categories under "ThingSmartTopCategory".
/// @param limit Number of items per page
/// @param offsetKey Page number key
/// @param deviceId Device ID
/// @param queryParams Search field
/// @param success Success callback
/// @param failure Failure callback
- (void)getAvailableDevices2JoinPackedGroupWithAreaId:(long long)areaId
                                          topCategory:(ThingSmartTopCategory)topCategory
                                                limit:(NSInteger)limit
                                            offsetKey:(NSString *)offsetKey
                                             deviceId:(NSString *)deviceId
                                          queryParams:(NSString *)queryParams
                                              success:(nullable void(^)(NSArray <ThingSmartDeviceModel *> *devices, NSString *nextOffsetKey, BOOL  end))success
                                              failure:(nullable ThingFailureError)failure;


/// Returns a sub-device list of the current packed group.
/// @param limit number of pages.
/// @param offsetKey offsetKey for next page.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getDevicesInPackedGroupWithLimit:(NSInteger)limit
                               offsetKey:(NSString *)offsetKey
                                 success:(nullable void(^)(NSArray <ThingSmartDeviceModel *> *devices, NSString *nextOffsetKey, BOOL  end))success
                                 failure:(nullable ThingFailureError)failure;



/// Set switch.
/// @param switchValue Open or close
/// @param success Success callback
/// @param failure Failure callback
- (void)publishSwitchStatus:(BOOL)switchValue
                    success:(nullable ThingSuccessID)success
                    failure:(nullable ThingFailureError)failure;



/// Set scene data.
/// @param sceneStatus Scene Data
/// @param success Success callback
/// @param failure Failure callback
- (void)publishSceneStatus:(NSString *)sceneStatus
                   success:(nullable ThingSuccessID)success
                   failure:(nullable ThingFailureError)failure;


/// Set work mode.
/// @param workMode Work mode
/// @param success Success callback
/// @param failure Failure callback
- (void)publishWorkMode:(NSString *)workMode
                success:(nullable ThingSuccessID)success
                failure:(nullable ThingFailureError)failure;


/// Set  bright value and temp value.
/// @param brightPercent Bright value
/// @param temperaturePercent Temperature value
/// @param success Success callback
/// @param failure Failure callback
- (void)publishBrightPercent:(NSInteger)brightPercent
          temperaturePercent:(NSInteger)temperaturePercent
                     success:(nullable ThingSuccessID)success
                     failure:(nullable ThingFailureError)failure;


/// Set colored light data.
/// @param colors Colored light data
/// @param success Success callback
/// @param failure Failure callback
- (void)publishColors:(NSString *)colors
              success:(nullable ThingSuccessID)success
              failure:(nullable ThingFailureError)failure;

/// Get top-level categories in the space
/// @param areaId Area ID, not required, but either it or the big group ID must be filled in.
/// @param success Success callback
/// @param failure Failure callback
- (void)getDeviceTopCategorysWithAreaId:(long long)areaId
                                success:(nullable void(^)(NSArray *categorys))success
                                failure:(nullable ThingFailureError)failure;

/// Device drag and drop sorting interface
/// @param sortIndexs Position information of devices after drag and drop
/// @param success Success callback
/// @param failure Failure callback
- (void)deviceMoveSortWithSortIndexs:(NSDictionary *)sortIndexs
                             success:(nullable ThingSuccessHandler)success
                             failure:(nullable ThingFailureError)failure;

/// Group drag and drop sorting interface
/// @param sortIndexs Position information of groups after drag and drop
/// @param success Success callback
/// @param failure Failure callback
+ (void)groupMoveSortWithSortIndexs:(NSArray<NSDictionary *> *)sortIndexs
                             areaId:(long long)areaId
                             success:(nullable ThingSuccessHandler)success
                             failure:(nullable ThingFailureError)failure;

/// Clean up invalid data
/// @param success Success callback
/// @param failure Failure callback
+ (void)invalidCleanWithAreaId:(long long)areaId
                     projectId:(NSString *)projectId
                       success:(nullable ThingSuccessHandler)success
                       failure:(nullable ThingFailureError)failure;

/// Bulk delete groups
/// @param groupIds Group ID list
/// @param projectId  projectId
/// @param success Success callback
/// @param failure Failure callback
+ (void)deleteGroupIds:(NSArray<NSString *> *)groupIds
             projectId:(NSString *)projectId
               success:(nullable ThingSuccessID)success
               failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
