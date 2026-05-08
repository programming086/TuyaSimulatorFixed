//
//  ThingLightingEnergyService.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)
//

#import <ThingSmartBaseKit/ThingSmartBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingEnergyAreaDetailModel,ThingLightingEnergySubentryDetailModel,ThingLightingEnergyDeviceCategoryModel;

@interface ThingLightingEnergyService : ThingSmartRequest

/// Get list of the regional energy consumption ranking.
/// @param projectId    Project ID
/// @param areaId       Area ID
/// @param targetType   The time of target(1.Day 2.Month 3.Year)
/// @param time         The start time in time.
/// @param success      Called when the task finishes successfully.
/// @param failure      If error occurred while adding the task, this block will be called.
- (void)requestEnergyAreaRank:(long long)projectId
                       areaId:(long long)areaId
                   targetType:(NSInteger)targetType
                         time:(long long)time
                      success:(nullable void(^)(NSArray *energyRankList))success
                      failure:(nullable void(^)(NSError *error))failure;

/// Get list of the regional sub-item energy consumption ranking.
/// @param projectId    Project ID
/// @param areaId       Area ID
/// @param targetType   The time of target(1.Day 2.Month 3.Year)
/// @param time         The start time in time.
/// @param success      Called when the task finishes successfully.
/// @param failure      If error occurred while adding the task, this block will be called.
- (void)requestEnergySubentryRank:(long long)projectId
                           areaId:(long long)areaId
                       targetType:(NSInteger)targetType
                             time:(long long)time
                          success:(nullable void(^)(NSArray *energyRankList))success
                          failure:(nullable void(^)(NSError *error))failure;

/// Get list of the regional sub-item energy consumption ranking preview.
/// @param projectId    Project ID
/// @param targetType   The time of target(1.Day 2.Month 3.Year)
/// @param time         The start time in time.
/// @param success      Called when the task finishes successfully.
/// @param failure      If error occurred while adding the task, this block will be called.
- (void)requestEnergySubentryPreview:(long long)projectId
                          targetType:(NSInteger)targetType
                                time:(long long)time
                             success:(nullable void(^)(NSArray *energyRankList))success
                             failure:(nullable void(^)(NSError *error))failure;

/// Get the charts data of sub-item energy consumption.
/// @param projectId    Project ID
/// @param targetType   The time of target(1.Day 2.Month 3.Year)
/// @param time         The start time in time.
/// @param purposeCode  The purpose code of sub-item energy.
/// @param success      Called when the task finishes successfully.
/// @param failure      If error occurred while adding the task, this block will be called.
- (void)requestEnergySubentryDetail:(long long)projectId
                         targetType:(NSInteger)targetType
                               time:(long long)time
                        purposeCode:(NSInteger)purposeCode
                            success:(nullable void(^)(ThingLightingEnergySubentryDetailModel *model))success
                            failure:(nullable void(^)(NSError *error))failure;

/// Get the count of energy consumption count.
/// @param projectId    Project ID
/// @param success      Called when the task finishes successfully.
/// @param failure      If error occurred while adding the task, this block will be called.
- (void)requestEnergyReportDeviceSize:(long long)projectId
                              success:(nullable void(^)(NSInteger deviceSize))success
                              failure:(nullable void(^)(NSError *error))failure;

/// Get a list of the energe consumption purposes in selected areas.
/// @param projectId    Project ID
/// @param areaIds      The area IDs(0 - All areas).
/// @param success      Called when the task finishes successfully.
/// @param failure      If error occurred while adding the task, this block will be called.
- (void)requestEnergySubentryDetail:(long long)projectId
                            areaIds:(NSString *)areaIds
                            success:(nullable void(^)(NSArray *energyPurposeList))success
                            failure:(nullable void(^)(NSError *error))failure;

/// Query a list of device energy consumption.
/// @param projectId    Project ID
/// @param startTime    The start time(The first millisecond of the day).
/// @param endTime      The end time(The last millisecond of the day).
/// @param areaIds      The area IDs(0 - All areas).
/// @param purposeCodes  The purpose codes of sub-item energy(Empty string means all sub-item).
/// @param pageNo       The page number from 1.
/// @param pageSize     The count per page.
/// @param success      Called when the task finishes successfully.
/// @param failure      If error occurred while adding the task, this block will be called.
- (void)requestEnergyReportDevices:(long long)projectId
                         startTime:(long long)startTime
                           endTime:(long long)endTime
                           areaIds:(NSString *)areaIds
                      purposeCodes:(NSString *)purposeCodes
                            pageNo:(NSInteger)pageNo
                          pageSize:(NSInteger)pageSize
                           success:(nullable void(^)(NSInteger total, NSArray *energyReportDeviceList))success
                           failure:(nullable void(^)(NSError *error))failure;

/// Get engerty consumption detail data by area in period.
/// @param projectId    Project ID
/// @param targetType   The time of target(1.Day 2.Month 3.Year)
/// @param startTime    The start time(The first millisecond of the day).
/// @param endTime      The end time(The last millisecond of the day).
/// @param areaId       The area ID(0 - All areas).
/// @param success      Called when the task finishes successfully.
/// @param failure      If error occurred while adding the task, this block will be called.
- (void)requestEnergyAreaDetail:(long long)projectId
                     targetType:(NSInteger)targetType
                      startTime:(long long)startTime
                        endTime:(long long)endTime
                         areaId:(long long)areaId
                        success:(nullable void(^)(ThingLightingEnergyAreaDetailModel *model))success
                        failure:(nullable void(^)(NSError *error))failure;

/// Get energy device category info
/// @param projectId Project ID
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)fetchDeviceCategoryModel:(long long)projectId
                         success:(void (^)(ThingLightingEnergyDeviceCategoryModel *))success
                         failure:(void (^)(NSError *))failure;

/// Get energy consumption detail data by area list in period.
/// @param projectId Project ID
/// @param targetType The time of target(1.Day 2.Month 3.Year)
/// @param startTime  The start time(The first millisecond of the day).
/// @param endTime The end time(The last millisecond of the day).
/// @param areaIds The area ID list(0 - All areas).
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)fetchLineChartModel:(long long)projectId
                 targetType:(NSInteger)targetType
                  startTime:(long long)startTime
                    endTime:(long long)endTime
                    areaIds:(NSString *)areaIds
                    success:(void (^)(NSArray<ThingLightingEnergyAreaDetailModel *> *))success
                    failure:(void (^)(NSError *))failure;

/// Get device classification data
/// @param projectId Project ID
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)fetchDeviceCategoryModelWithProjectId:(long long)projectId
                                      success:(void (^)(ThingLightingEnergyDeviceCategoryModel *))success
                                      failure:(void (^)(NSError *))failure;

@end

NS_ASSUME_NONNULL_END
