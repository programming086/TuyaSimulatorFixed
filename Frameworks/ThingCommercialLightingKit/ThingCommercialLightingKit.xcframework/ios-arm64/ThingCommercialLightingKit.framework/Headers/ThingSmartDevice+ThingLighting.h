//
//  ThingSmartDevice+ThingLighting.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLightingDevLocationModel;

@interface ThingSmartDevice (ThingLighting)

/// Synchronizes device information.
/// @param devId The device ID.
/// @param homeId The home ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)syncDeviceInfoWithDevId:(NSString *)devId
                         homeId:(long long)homeId
                        success:(nullable ThingSuccessHandler)success
                        failure:(nullable ThingFailureError)failure;

/// Get a list of incremental device information in batches.
/// @param projectId The project ID.
/// @param devIds Array of device IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)getBatchDevicesIncrementInfoListWithProjectId:(long long)projectId
                                            deviceIds:(NSArray<NSString *> *)devIds
                                              success:(nullable void(^)(NSArray<ThingSmartDeviceModel *> *list))success
                                              failure:(nullable ThingFailureError)failure;

/// Synchronize devices informations
/// @param devIds The device IDs
/// @param projectId The projectId
/// @param success Called when the task is finished
/// @param failure  Called when the task is interrupted by an error.
+ (void)syncDevicesInfosWithDevIds:(NSArray<NSString*>*)devIds
                         projectId:(long long)projectId
                           success:(nullable ThingSuccessHandler)success
                           failure:(nullable ThingFailureError)failure;


/// Get whether the device product supports distributed functionality
/// @param pid Product ID
/// @param projectId Project ID
/// @param success Success callback
/// @param failure Failure callback
+ (void)fetchDistributedAbilityWithProductId:(NSString *)pid
                                   projectId:(long long)projectId
                                     success:(nullable ThingSuccessBOOL)success
                                     failure:(nullable ThingFailureError)failure;

@end

@interface ThingSmartDevice (ThingLightingLoction)

+ (void)fetchDeviceLocationWithProjectId:(long long)projectId
                        devId:(NSString *)devId
                         success:(nullable void(^)(ThingLightingDevLocationModel *locationModel))success
                         failure:(nullable ThingFailureError)failure;


+ (void)saveDeviceLocationWithProjectId:(long long)projectId
                                  devId:(NSString *)devId
                               latitude:(NSString *)latitude
                              longitude:(NSString *)longitude
                                address:(NSString *)address
                                success:(nullable ThingSuccessHandler)success
                                failure:(nullable ThingFailureError)failure;

+ (void)fetchGatewayInfoWithProjectId:(long long)projectId
                                  devId:(NSString *)devId
                                   success:(nullable ThingSuccessDict)success
                                   failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
