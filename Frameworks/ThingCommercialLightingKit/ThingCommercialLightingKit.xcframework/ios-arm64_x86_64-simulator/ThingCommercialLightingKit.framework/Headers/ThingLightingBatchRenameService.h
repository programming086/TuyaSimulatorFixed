//
//  ThingLightingBatchRenameService.h
//  AFNetworking
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingBatchRenameSortModel : NSObject

@property (nonatomic, strong) NSString *deviceMac;
@property (nonatomic, strong) NSString *preMac;
@property (nonatomic, strong) NSString *nextMac;

@end

@interface ThingLightingBatchRenameUpdateModel : NSObject

@property (nonatomic, strong) NSString *deviceMac;
@property (nonatomic, strong) NSString *deviceName;

@end

@class ThingSmartDeviceModel;

@interface ThingLightingBatchRenameService : NSObject

/// Add the MAC address of the renamed device
/// @param areaId area ID
/// @param mac mac address
/// @param success Success callback
/// @param failure Success callback
- (void)requestAddMacWithAreaId:(long long)areaId
                            mac:(NSString *)mac
                        success:(void(^)(ThingSmartDeviceModel *deviceModel))success
                        failure:(void(^)(NSError *error))failure;

/// Get the recorded devices
/// @param areaId Area ID
/// @param page Page number
/// @param pageSize Number of items per page
/// @param success Success callback
/// @param failure Success callback
- (void)requestMacDeviceListWithAreaId:(long long)areaId
                                  page:(NSInteger)page
                              pageSize:(NSInteger)pageSize
                               success:(void(^)(NSArray<NSDictionary *> *list, NSInteger total))success
                               failure:(void(^)(NSError *error))failure;

/// Delete devices by MAC address, if MAC address is not provided, it will clear all devices.
/// @param areaId area ID
/// @param mac mac address
/// @param success Success callback
/// @param failure Success callback
- (void)requestDeleteAllDeviceWithAreaId:(long long)areaId
                                     mac:(NSString *)mac
                                 success:(void(^)(void))success
                                 failure:(void(^)(NSError *error))failure;

/// Update device order and names
/// @param areaId area ID
/// @param sortModels Order models
/// @param updateData Name models
/// @param success Success callback
/// @param failure Success callback
- (void)requestUpdateSortsWithAreaId:(long long)areaId
                            sortData:(NSArray<ThingLightingBatchRenameSortModel *> *)sortModels
                          updateData:(NSArray<ThingLightingBatchRenameUpdateModel *> *)updateData
                             success:(void(^)(void))success
                             failure:(void(^)(NSError *error))failure;


/// Update the name of unconfigured devices
/// @param areaId Area ID
/// @param mac mac address
/// @param name name
/// @param success Success callback
/// @param failure Success callback
- (void)requestRenameDeviceWithAreaId:(long long)areaId
                                  mac:(NSString *)mac
                                 name:(NSString *)name
                              success:(nullable ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END
