//
//  ThingLightingAreaService.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <ThingSmartBaseKit/ThingSmartBaseKit.h>
#import <ThingCommercialLightingKit/ThingCommercialLightingKit.h>

typedef void(^ThingLightingDevicesTransferHandler)(NSArray<NSString *> * _Nullable successDevIds, NSArray<NSString *> *_Nullable failedDevIds);

NS_ASSUME_NONNULL_BEGIN

@interface ThingLightingAreaService : ThingApiMergeService

@end

@class ThingLightingAreaModel;
@class ThingLightingAreaDevicePurposeModel;

#pragma mark - Area related
@interface ThingLightingAreaService (Area)

/// Get the list of all areas in the project (including sub-areas)
/// @param projectId Project ID
/// @param needUnassignedArea Whether to return unassigned areas
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchAreaLevelsWithProjectId:(long long)projectId
                  needUnassignedArea:(BOOL)needUnassignedArea
                             success:(nullable void(^)(NSArray <ThingLightingAreaModel *> *_Nullable areas, NSInteger totalRoomDeviceCount))success
                             failure:(nullable ThingFailureError)failure;

/// Get the list of all areas in the project (including sub-areas)
/// @param projectId Project ID
/// @param needUnassignedArea Whether to return unassigned areas
/// @param needPublicArea Whether to return public area
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchAreaLevelsWithProjectId:(long long)projectId
                  needUnassignedArea:(BOOL)needUnassignedArea
                      needPublicArea:(BOOL)needPublicArea
                             success:(nullable void(^)(NSArray <ThingLightingAreaModel *> *_Nullable areas, NSInteger totalRoomDeviceCount))success
                             failure:(nullable ThingFailureError)failure;

/// Get the list of sub-areas of a specified area in the project
/// @param projectId Project ID
/// @param areaId Area ID
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchAreaListWithProjectId:(long long)projectId
                            areaId:(long long)areaId
                           success:(nullable void(^)(NSArray <ThingLightingAreaModel *> * _Nullable areas))success
                           failure:(nullable ThingFailureError)failure;

/// Get the list of root spaces for the specified project
/// @param projectId Project ID
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchSimpleAreaListWithProjectId:(long long)projectId
                                 success:(void (^)(NSArray<ThingLightingAreaModel *> * _Nullable))success
                                 failure:(ThingFailureError)failure;

/// Get the data of a specific space in the specified project
/// @param projectId Project ID
/// @param areaId Area ID
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchSimpleAreInfoWithProjectId:(long long)projectId
                                 areaId:(long long)areaId
                                success:(void (^)(ThingLightingAreaModel * _Nullable))success
                                failure:(ThingFailureError)failure;

/// Get current area information and the list of sub-areas
/// @param projectId Project ID
/// @param areaId Area ID
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchSingleAreaListWithProjectId:(long long)projectId
                                  areaId:(long long)areaId
                                 success:(void(^)(ThingLightingAreaModel * _Nullable))success
                                 failure:(nullable ThingFailureError)failure;


/// Get the purpose of the space
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchSpacePurposeListWithSuccess:(void(^)(NSArray<ThingLightingAreaSpacePurposeModel *> *purposeModels))success
                                 failure:(ThingFailureError)failure;


/// Create a new sub-area under the specified area
/// @param projectId Project ID
/// @param areaId Area ID
/// @param name Area name
/// @param roomLevel Area hierarchy: 1 - Park; 2 - Building; 3 - Floor; 4 - Room
/// @param longitude longitude
/// @param latitude latitude
/// @param industryPurpose industry purpose
/// @param spacePurpose area purpose
/// @param address address
/// @param success Success callback
/// @param failure Failure callback
- (void)createAreaWithProjectId:(long long)projectId
                         areaId:(long long)areaId
                           name:(nullable NSString *)name
                      roomLevel:(NSInteger)roomLevel
                      longitude:(double)longitude
                       latitude:(double)latitude
                industryPurpose:(NSString *)industryPurpose
                   spacePurpose:(NSString *)spacePurpose
                        address:(nullable NSString *)address
                        success:(nullable ThingSuccessID)success
                        failure:(nullable ThingFailureError)failure;

/// Delete the specified area
/// @param projectId Project ID
/// @param areaId Area ID
/// @param success Success callback
/// @param failure Failure callback
- (void)removeAreaWithProjectId:(long long)projectId
                         areaId:(long long)areaId
                        success:(nullable ThingSuccessHandler)success
                        failure:(nullable ThingFailureError)failure;

/// Update the area
/// @param projectId Project ID
/// @param areaId Area ID
/// @param name New area name
/// @param longitude longitude
/// @param latitude latitude
/// @param industryPurpose industry purpose
/// @param spacePurpose area purpose
/// @param address address
/// @param success Success callback
/// @param failure Failure callback
- (void)updateAreaWithProjectId:(long long)projectId
                         areaId:(long long)areaId
                           name:(nonnull NSString *)name
                      longitude:(double)longitude
                       latitude:(double)latitude
                industryPurpose:(ThingLightingAreaSpacePurposeModel *)industryPurpose
                   spacePurpose:(ThingLightingAreaSpacePurposeModel *)spacePurpose
                        address:(nonnull NSString *)address
                        success:(ThingSuccessHandler)success
                        failure:(ThingFailureError)failure;

/// Update the favorite status
/// @param projectId Project ID
/// @param areaId Area ID
/// @param status status
/// @param success Success callback
/// @param failure Failure callback
- (void)updateAreaWithProjectId:(long long)projectId
                         areaId:(long long)areaId
               collectionStatus:(BOOL)status
                        success:(nullable ThingSuccessHandler)success
                        failure:(nullable ThingFailureError)failure;

/// Set switches and quick controls for the area
/// @param projectId Project ID
/// @param areaId Area ID
/// @param status status
/// @param success Success callback
/// @param failure Failure callback
- (void)updateAreaWithProjectId:(long long)projectId
                         areaId:(long long)areaId
              quickSwitchStatus:(BOOL)status
                        success:(nullable ThingSuccessHandler)success
                        failure:(nullable ThingFailureError)failure;

/// Get data for the parent area (including the current area)
/// @param projectId Project ID
/// @param areaId Area ID
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchParentAreaWithProjectId:(long long)projectId
                              areaId:(long long)areaId
                             success:(void(^ _Nullable)(ThingLightingAreaModel  * _Nullable parentAreaModel))success
                             failure:(nullable ThingFailureError)failure;

/// Publish DP (Data Point) to the area
/// @param projectId Project ID
/// @param areaId Area ID
/// @param dps Data Point
/// @param success Success callback
/// @param failure Failure callback
- (void)publishWithProjectId:(long long)projectId
                      areaId:(long long)areaId
                         dps:(NSDictionary *)dps
                     success:(ThingSuccessHandler)success
                     failure:(ThingFailureError)failure;

- (void)getSigmeshGroupInfoWithProjectId:(long long)projectId
                                  areaId:(long long)areaId
                                 success:(ThingSuccessID)success
                                 failure:(ThingFailureError)failure;

@end

#pragma mark - Device-related
@interface ThingLightingAreaService (Device)

/// Get the purposes of all devices in the current area
/// @param projectId Project ID
/// @param areaId Area ID
/// @param topCategory category
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchDevicePurposeListWithProjectId:(long long)projectId
                                     areaId:(long long)areaId
                                topCategory:(NSString *)topCategory
                                    success:(void(^)(NSArray<ThingLightingAreaDevicePurposeModel *> *purposeModels))success
                                    failure:(ThingFailureError)failure;

- (void)updateDevices:(NSArray *)devIds
               areaId:(long long)areaId
      industryPurpose:(NSString *)industryPurpose
        devicePurpose:(NSString *)devicePurpose
              success:(void(^)(NSArray<NSString *> *successDevIds,NSArray<NSString *> *failDevIds))success
              failure:(void(^)(NSError *error))failure;

/// Add device list
/// @param projectId Project ID
/// @param areaId Area ID
/// @param devIds Device ID list
/// @param success Success callback
/// @param failure Failure callback
- (void)addDeviceWithProjectId:(long long)projectId
                        areaId:(long long)areaId
                     deviceIds:(NSArray<NSString *> *)devIds
                       success:(nullable ThingLightingDevicesTransferHandler)success
                       failure:(nullable ThingFailureError)failure;

/// Add the device to a group
/// @param projectId Project ID
/// @param areaId Area ID
/// @param devIds Device ID list
/// @param success Success callback
/// @param failure Failure callback
- (void)joinGroupWithProjectId:(long long)projectId
                        areaId:(long long)areaId
                     deviceIds:(NSArray<NSString *> *)devIds
                       success:(nullable ThingLightingDevicesTransferHandler)success
                       failure:(nullable ThingFailureError)failure;

/// Add the device to the unassigned area
/// @param projectId Project ID
/// @param devIds Device ID list
/// @param success Success callback
/// @param failure Failure callback
+ (void)addDeviceToUnassignedZoneWithProjectId:(long long)projectId
                                     deviceIds:(NSArray<NSString *> *)devIds
                                       success:(ThingSuccessID)success
                                       failure:(ThingFailureError)failure;

/// Get the list of devices
/// @param projectId Project ID
/// @param areaId Area ID
/// @param offsetKey Page key
/// @param tag Filter criteria
/// @param keyword search key word
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchDeviceListWithProjectId:(long long)projectId
                              areaId:(long long)areaId
                           offsetKey:(nullable NSString *)offsetKey
                                 tag:(nullable NSString *)tag
                             keyword:(nullable NSString *)keyword
                              meshId:(nullable NSString *)meshId
                             success:(void (^)(NSArray<ThingSmartDeviceModel *> * _Nullable devices, NSString *nextOffsetKey, BOOL end, NSUInteger total))success
                             failure:(nullable ThingFailureError)failure;


/// Get the list of devices
/// @param industryPurpose Primary purpose
/// @param devicePurpose Device purpose
/// @param topCagegory category
- (void)fetchDeviceListWithProjectId:(long long)projectId
                              areaId:(long long)areaId
                           offsetKey:(nullable NSString *)offsetKey
                                 tag:(nullable NSString *)tag
                               devId:(NSString *)devId
                             keyword:(nullable NSString *)keyword
                              meshId:(nullable NSString *)meshId
                     industryPorpose:(nullable NSString *)industryPurpose
                       devicePurpose:(nullable NSString *)devicePurpose
                         topCategory:(nullable NSString *)topCagegory
                             success:(void (^)(NSArray<ThingSmartDeviceModel *> * _Nullable devices, NSString *nextOffsetKey, BOOL end, NSUInteger total))success
                             failure:(nullable ThingFailureError)failure;

/// Get the list of replaceable devices
/// @param projectId Project ID
/// @param areaId Area ID
/// @param offsetKey Page key
/// @param tag Filter criteria
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchReplaceableDeviceListWithProjectId:(long long)projectId
                                         areaId:(long long)areaId
                                      offsetKey:(NSString *)offsetKey
                                            tag:(NSString *)tag
                                          devId:(NSString *)devId
                                        success:(nullable void (^)(NSArray<ThingSmartDeviceModel *> * _Nullable devices, NSString *nextOffsetKey, BOOL end, NSUInteger total))success
                                        failure:(nullable ThingFailureError)failure;

/// Get device filter criteria
/// @param projectId Project ID
/// @param areaId Area ID
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchDeviceFilterConditionWithProjectId:(long long)projectId
                                         areaId:(long long)areaId
                                        success:(nullable ThingSuccessList)success
                                        failure:(nullable ThingFailureError)failure;

/// Update device filter criteria
/// @param projectId Project ID
/// @param areaId Area ID
/// @param success Success callback
/// @param failure Failure callback
- (void)updateDeviceFilterConditionWithProjectId:(long long)projectId
                                          areaId:(long long)areaId
                                         success:(nullable ThingSuccessList)success
                                         failure:(nullable ThingFailureError)failure;

/// Bulk add devices to the current area
/// @param projectId Project ID
/// @param areaId Area ID
/// @param devIds Device ID list
/// @param success Success callback
/// @param failure Failure callback
- (void)batchAddDevicesWithProjectId:(long long)projectId
                              areaId:(long long)areaId
                           deviceIds:(NSArray<NSString *> *)devIds
                             success:(nullable ThingSuccessHandler)success
                             failure:(nullable ThingFailureError)failure;


@end

#pragma mark - DeviceMesh
@interface ThingLightingAreaService (DeviceMesh)

/// When transferring local devices to another room, filter out Bluetooth direct-connected devices in the cloud and group them.
/// @param projectId Project ID
/// @param areaId Area ID
/// @param devIds Device ID list
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchLocalMeshDeviceListWithProjectId:(long long)projectId
                                       areaId:(long long)areaId
                                       devIds:(NSArray<NSString *> *)devIds
                                      success:(nullable void (^)(NSArray<ThingSmartDeviceAssignedModel *> *_Nullable array))success
                                      failure:(nullable ThingFailureError)failure;
@end

#pragma mark - Group-related
@interface ThingLightingAreaService (Group)

/// Create a new group
/// @param projectId Project ID
/// @param areaId Area ID
/// @param name group name
/// @param source Group source: 0 - Area group; 1 - Custom group
/// @param meshGroupType Group mesh type: 0 - Single product group; 1 - Sub-device group
/// @param devIds Device ID list
/// @param success Success callback
/// @param failure Failure callback
- (void)createNewLocalMeshGroupWithProjectId:(long long)projectId
                                      areaId:(long long)areaId
                                        name:(NSString *)name
                                      source:(NSInteger)source
                               meshGroupType:(NSInteger)meshGroupType
                                      devIds:(NSArray<NSString *> *)devIds
                                     success:(void (^)(ThingSmartGroupModel *groupModel))success
                                     failure:(ThingFailureError)failure;


- (void)getBizDeviceListWithProjectId:(long long)projectId
                               areaId:(long long)areaId
                            offsetKey:(NSString *)offsetKey
                             bizScene:(NSInteger)bizScene
                                devId:(NSString *)devId
                              localId:(NSString *)localId
                                limit:(NSInteger)limit
                              success:(nullable void(^)(NSArray<ThingSmartDeviceModel *> *devices, NSString *nextOffsetKey, BOOL end))success
                              failure:(nullable ThingFailureError)failure;



- (void)getRemoteControlDeviceListWithProjectId:(long long)projectId
                                          devId:(NSString *)devId
                                         areaId:(long long)areaId
                                      offsetKey:(NSString *)offsetKey
                                   categoryCode:(NSString *)categoryCode
                              queryExtendParams:(NSDictionary *)queryExtendParams
                                          limit:(NSInteger)limit
                                        success:(nullable ThingSmartLightingDeviceListResult)success
                                        failure:(nullable ThingFailureError)failure;


/// Get the list of devices for adding actions to a scene
/// @param projectId Project ID
/// @param areaId Area ID
/// @param page Page number
/// @param limit Number of items per page
/// @param keyword Search word
/// @param success Success callback
/// @param failure Failure callback
- (void)getSceneDeviceListWithProjectId:(long long)projectId
                                 areaId:(long long)areaId
                                   page:(NSInteger)page
                                  limit:(NSInteger)limit
                                keyword:(NSString *)keyword
                                success:(nullable ThingSmartLightingDeviceListResult)success
                                failure:(nullable ThingFailureError)failure;

/// Get the list of devices for adding actions to local timers
/// @param projectId Project ID
/// @param areaId Area ID
/// @param page Page number
/// @param limit Number of items per page
/// @param keyword Search word
/// @param success Success callback
/// @param failure Failure callback
- (void)getLocalRTCDeviceListWithProjectId:(long long)projectId
                                    areaId:(long long)areaId
                                      page:(NSInteger)page
                                     limit:(NSInteger)limit
                                   keyword:(NSString *)keyword
                                   success:(nullable ThingSmartLightingDeviceListResult)success
                                   failure:(nullable ThingFailureError)failure;


- (void)getCollectionAreaListWithProjectId:(long long)projectId
                                   success:(nullable void (^)(NSArray<ThingLightingAreaModel *> * _Nullable areaList))success
                                   failure:(void(^)(NSError *error))failure;


@end


@interface ThingLightingAreaService (DistributedSceneDevice)
/// Get distributed linkage execution devices (executing devices)
/// @param page Page number
/// @param limit Number of items per page
/// @param keyword sesarch word
/// @param success Success callback
/// @param failure Failure callback
- (void)getDistributedSceneExecutorDeviceListWithPage:(NSInteger)page
                                                limit:(NSInteger)limit
                                               areaId:(long long)areaId
                                            projectId:(long long)projectId
                                              keyword:(NSString *)keyword
                                              success:(nullable ThingSmartLightingDeviceListResult)success
                                              failure:(nullable ThingFailureError)failure;

/// Get the list of distributed scene dimming devices (executing devices)
/// @param page Page number
/// @param limit Number of items per page
/// @param keyword Sesarch word
/// @param success Success callback
/// @param failure Failure callback
- (void)getDistributedSceneDimmingDeviceListWithPage:(NSInteger)page
                                               limit:(NSInteger)limit
                                              areaId:(long long)areaId
                                           projectId:(long long)projectId
                                             keyword:(NSString *)keyword
                                             success:(nullable ThingSmartLightingDeviceListResult)success
                                             failure:(nullable ThingFailureError)failure;

@end
NS_ASSUME_NONNULL_END
