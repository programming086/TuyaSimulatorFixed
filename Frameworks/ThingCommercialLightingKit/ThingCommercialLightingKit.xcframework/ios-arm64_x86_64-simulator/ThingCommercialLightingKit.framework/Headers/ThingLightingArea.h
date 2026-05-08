//
//  ThingLightingArea.h
//  ThingSmartCommercialLightingSdk
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

#import <ThingSmartUtil/ThingSmartUtil.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingLightingMeshConnectStatus) {
    ThingLightingMeshConnectStatusNot = 0,
    ThingLightingMeshConnectStatusPart,
    ThingLightingMeshConnectStatusAll,
};


typedef void (^ThingSmartLightingDeviceListResult)(NSArray<ThingSmartDeviceModel *> *devices,
                                                  NSString *nextOffsetKey,
                                                  BOOL end,
                                                  NSUInteger total);

@class ThingSmartDeviceAssignedModel;
@class ThingSmartPackedGroupModel;
@class ThingLightingAreaModel;
@class ThingLightingAreaSpacePurposeModel;
@class ThingLightingDeviceSummaryModel;

/// @brief ThingLightingArea provides methds for developers to manage single area.
@interface ThingLightingArea : NSObject

/// Area model that read from cache
@property (nonatomic, strong, readonly) ThingLightingAreaModel *areaModel;

/// Data point of area.
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


@property (nonatomic, assign, readonly) ThingLightingMeshConnectStatus connectStatus;


- (instancetype)init NS_UNAVAILABLE;


/// Create a new area instance.
/// @param areaId Area ID
/// @param projectId Project ID
/// @return The area instance
- (nullable instancetype)initWithAreaId:(long long)areaId projectId:(long long)projectId NS_DESIGNATED_INITIALIZER;


/// Create a new area instance.
/// @param areaId Area ID
/// @param projectId Project ID
/// @return The area instance
+ (nullable instancetype)areaWithAreaId:(long long)areaId projectId:(long long)projectId;


/// Create a sub-area. (suitable for indoor areas)
/// @param subAreaName Sub area name
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)createSubAreaWithName:(NSString *)subAreaName
                      success:(nullable void(^)(ThingLightingAreaModel *areaModel))success
                      failure:(nullable ThingFailureError)failure;


/// Create a sub-area. (suitable for outdoor areas)
/// @param subAreaName Sub area name
/// @param longitude Longitude
/// @param latitude Latitude
/// @param address Area address
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)createSubAreaWithName:(NSString *)subAreaName
                    longitude:(double)longitude
                     latitude:(double)latitude
              industryPurpose:(NSString *)industryPurpose
                 spacePurpose:(NSString *)spacePurpose
                      address:(nullable NSString *)address
                      success:(nullable void(^)(ThingLightingAreaModel *areaModel))success
                      failure:(nullable ThingFailureError)failure;


/// Create a parent area. (suitable for indoor areas)
/// @param parentAreaName Parent area name
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)createParentAreaWithName:(NSString *)parentAreaName
                         success:(nullable void(^)(ThingLightingAreaModel *areaModel))success
                         failure:(nullable ThingFailureError)failure;


/// Create a parent area. (suitable for outdoor areas)
/// @param parentAreaName Parent area name
/// @param longitude Longitude
/// @param latitude Latitude
/// @param address Area address
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)createParentAreaWithName:(NSString *)parentAreaName
                       longitude:(double)longitude
                        latitude:(double)latitude
                         address:(nullable NSString *)address
                         success:(nullable void(^)(ThingLightingAreaModel *areaModel))success
                         failure:(nullable ThingFailureError)failure;


/// Fetch sub area list in the area.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getSubAreaListWithSuccess:(nullable void(^)(NSArray <ThingLightingAreaModel *> *areas))success
                          failure:(nullable ThingFailureError)failure;


/// Fetch area info from remote, include sub area list.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getAreaInfoWithSuccess:(nullable void(^)(ThingLightingAreaModel *))success
                       failure:(nullable ThingFailureError)failure;


/// Fetch simple area info from remote.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getSimpleAreaInfoWithSuccess:(nullable void(^)(ThingLightingAreaModel *))success
                             failure:(nullable ThingFailureError)failure;


/// Get the parent area corresponding to the current area.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getParentAreaWithSuccess:(nullable void(^)(ThingLightingAreaModel * _Nullable parentAreaModel))success
                         failure:(nullable ThingFailureError)failure;


/// Update area info. (suitable for indoor areas).
/// @param name Area name
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)updateAreaInfoWithName:(NSString *)name
                       success:(nullable ThingSuccessHandler)success
                       failure:(nullable ThingFailureError)failure;


/// Update area info. (suitable for outdoor areas)
/// @param name Area name
/// @param longitude Longitude
/// @param latitude Latitude
/// @param address Area address
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)updateAreaInfoWithName:(NSString *)name
                     longitude:(double)longitude
                      latitude:(double)latitude
               industryPurpose:(nullable ThingLightingAreaSpacePurposeModel *)industryPurpose
                  spacePurpose:(nullable ThingLightingAreaSpacePurposeModel *)spacePurpose
                       address:(nullable NSString *)address
                       success:(nullable ThingSuccessHandler)success
                       failure:(nullable ThingFailureError)failure;



/// Delete area.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)deleteWithSuccess:(nullable ThingSuccessHandler)success
                  failure:(nullable ThingFailureError)failure;


/// Update area collction status.
/// @param status Collection status
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)updateCollctionStatus:(BOOL)status
                      success:(nullable ThingSuccessHandler)success
                      failure:(nullable ThingFailureError)failure;


/// Update area quick status.
/// @param status Quick status
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)updateQuickStatus:(BOOL)status
                  success:(nullable ThingSuccessHandler)success
                  failure:(nullable ThingFailureError)failure;

@end


@interface ThingLightingArea (ThingDevice)

/// Fetch a list of device in the current area.
/// @param offsetKey Page number
/// @param tag Tag, 0 means all, 1 means offline, 2 means to be configured.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getDeviceListWithOffsetKey:(NSString *)offsetKey
                               tag:(NSString *)tag
                           success:(nullable ThingSmartLightingDeviceListResult)success
                           failure:(nullable ThingFailureError)failure;


/// Fetch a list of device in the current area by devId.
/// @param offsetKey Page number
/// @param tag 0 means all，1 means offline，2 means to be configured.
/// @param devId Device ID array
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getDeviceListWithOffsetKey:(NSString *)offsetKey
                               tag:(NSString *)tag
                             devId:(NSString *)devId
                           success:(nullable ThingSmartLightingDeviceListResult)success
                           failure:(nullable ThingFailureError)failure;


/// Search a list of device in the current area by search name.
/// @param offsetKey Page number
/// @param searchName device name for search.
/// @param tag  0 means all，1 means offline，2 means to be configured.
/// @param success Called when the task finishes successfully.
/// @param failure if error occured while adding the task, this block will be called.
- (void)queryDeviceListForSearchWithOffsetKey:(nullable NSString *)offsetKey
                                   searchName:(nullable NSString *)searchName
                                          tag:(nullable NSString *)tag
                                       meshId:(nullable NSString *)meshId
                                      success:(nullable ThingSmartLightingDeviceListResult)success
                                      failure:(nullable ThingFailureError)failure;


/// Add devices to area.
/// @param devIds Device ID array
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)transferDevicesWithDeviceIds:(NSArray<NSString *> *)devIds
                             success:(nullable void(^)(NSArray<NSString *> * successDevIds, NSArray<NSString *> * failedDevIds))success
                             failure:(nullable ThingFailureError)failure;


/// Compensation for devices that have not joined the group.
/// @param devIds Device ID array
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)joinGroupWithDeviceIds:(NSArray<NSString *> *)devIds
                       success:(nullable void(^)(NSArray<NSString *> *successDevIds, NSArray<NSString *> *failedDevIds))success
                       failure:(nullable ThingFailureError)failure;


/// Remove the device from the current area.
/// @param devIds Device ID array
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeDeviceWithDeviceIds:(NSArray<NSString *> *)devIds
                          success:(nullable void(^)(NSArray<NSString *> *successDevIds, NSArray<NSString *> *failedDevIds))success
                          failure:(nullable ThingFailureError)failure;


/// Save the device in unpartitioned.
/// @param devIds Device ID Array
/// @param projectId Project ID
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
+ (void)addDeviceToUnassignedZone:(NSArray<NSString *> *)devIds
                        projectId:(long long)projectId
                          success:(nullable ThingSuccessID)success
                          failure:(nullable ThingFailureError)failure;


/// Fetch device classification information.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)fetchSummaryWithSuccess:(nullable void (^)(NSArray<ThingLightingDeviceSummaryModel *> *summaryList))success
                        failure:(nullable ThingFailureError)failure;


/// Add the device to the area when transferring the device locally (just join the area, the device does not enter the group).
/// @param devIds Device ID array
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)addLocalMeshWithDeviceIds:(NSArray<NSString *> *)devIds
                          success:(nullable ThingSuccessHandler)success
                          failure:(nullable ThingFailureError)failure;


/// Create a Bluetooth Direct Connect Device Group.
/// @param name Group name
/// @param source 0 means area group，1 means custom group
/// @param meshGroupType 0 means normal group，1 means Sub-device group (group with gateway)
/// @param devIds Device ID array
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)createNewLocalMeshGroupWithName:(NSString *)name
                                 source:(NSInteger)source
                          meshGroupType:(NSInteger)meshGroupType
                                 devIds:(NSArray<NSString *> *)devIds
                                success:(nullable void(^)(ThingSmartGroupModel *groupModel))success
                                failure:(nullable ThingFailureError)failure;


- (void)getBizDeviceListWithOffsetKey:(NSString *)offsetKey
                             bizScene:(NSInteger)bizScene
                                devId:(NSString *)devId
                              localId:(NSString *)localId
                                limit:(NSInteger)limit
                              success:(nullable void(^)(NSArray<ThingSmartDeviceModel *> *devices, NSString *nextOffsetKey, BOOL end))success
                              failure:(nullable ThingFailureError)failure;


- (void)getRemoteControlDeviceListWithDevId:(NSString *)devId
                                  offsetKey:(NSString *)offsetKey
                               categoryCode:(NSString *)categoryCode
                          queryExtendParams:(NSDictionary *)queryExtendParams
                                      limit:(NSInteger)limit
                                    success:(nullable ThingSmartLightingDeviceListResult)success
                                    failure:(nullable ThingFailureError)failure;


- (void)getSceneDeviceListWithPage:(NSInteger)page
                             limit:(NSInteger)limit
                           keyword:(NSString *)keyword
                           success:(nullable ThingSmartLightingDeviceListResult)success
                           failure:(nullable ThingFailureError)failure;

- (void)getLocalRTCDeviceListWithPage:(NSInteger)page
                                limit:(NSInteger)limit
                              keyword:(NSString *)keyword
                              success:(nullable ThingSmartLightingDeviceListResult)success
                              failure:(nullable ThingFailureError)failure;

@end


#pragma mark - Device control
@interface ThingLightingArea (ThingDeviceControl)


/// Issue dp command.
/// @param dps Dp dictionary
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)publishDps:(NSDictionary *)dps
           success:(nullable ThingSuccessHandler)success
           failure:(nullable ThingFailureError)failure;


/// Set switch.
/// @param switchStatus Open or close
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)publishSwitchStatus:(BOOL)switchStatus
                    success:(nullable ThingSuccessID)success
                    failure:(nullable ThingFailureError)failure;


/// Set scene data.
/// @param sceneStatus Scene Data
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)publishSceneStatus:(NSString *)sceneStatus
                   success:(nullable ThingSuccessID)success
                   failure:(nullable ThingFailureError)failure;


/// Set work mode.
/// @param workMode Work mode
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)publishWorkMode:(NSString *)workMode
                success:(nullable ThingSuccessID)success
                failure:(nullable ThingFailureError)failure;


/// Set the brightness.
/// @param brightPercent Bright value
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)publishBrightPercent:(NSInteger)brightPercent
                     success:(nullable ThingSuccessID)success
                     failure:(nullable ThingFailureError)failure;


/// Set the color temperature.
/// @param temperaturePercent Temperature value
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)publishTemperaturePercent:(NSInteger)temperaturePercent
                          success:(nullable ThingSuccessID)success
                          failure:(nullable ThingFailureError)failure;


/// Set  bright value and temp value.
/// @param brightPercent Bright value
/// @param temperaturePercent Temperature value
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)publishBrightPercent:(NSInteger)brightPercent
          temperaturePercent:(NSInteger)temperaturePercent
                     success:(nullable ThingSuccessID)success
                     failure:(nullable ThingFailureError)failure;


/// Set colored light data.
/// @param colors Colored light data
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)publishColors:(NSString *)colors
              success:(nullable ThingSuccessID)success
              failure:(nullable ThingFailureError)failure;

- (void)getAreaSigMeshGroupsInfoWithSuccess:(nullable ThingSuccessHandler)success
                               failure:(nullable ThingFailureError)failure;

@end

@interface ThingLightingArea (Deprecated)


/// Update device classification information.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)updateSummaryWithSuccess:(nullable ThingSuccessList)success
                         failure:(nullable ThingFailureError)failure __deprecated_msg("This method is deprecated, Use fetchSummaryWithSuccess:failure: instead");


/// Filter out the local Bluetooth devices directly connected.
/// @param devIds Device ID array
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)fetchLocalMeshDeviceListWithDevIds:(NSArray<NSString *> *)devIds
                                   success:(nullable void(^)(NSArray<ThingSmartDeviceAssignedModel *> *array))success
                                   failure:(nullable ThingFailureError)failure __deprecated_msg("This method is deprecated.");

@end

@interface ThingLightingArea (DisributedDevices)

/// Get the list of distributed scene dimming devices (executing devices).
/// @param page Page number
/// @param limit Number of items per page
/// @param keyword search word
/// @param success Success callback
/// @param failure Failure callback
- (void)getDistributedSceneDimmingDeviceListWithPage:(NSInteger)page
                                               limit:(NSInteger)limit
                                             keyword:(NSString *)keyword
                                             success:(nullable ThingSmartLightingDeviceListResult)success
                                             failure:(nullable ThingFailureError)failure;

/// Get distributed linkage execution devices (executing devices)
/// @param page Page number
/// @param limit Number of items per page
/// @param keyword search word
/// @param success Success callback
/// @param failure Failure callback
- (void)getDistributedSceneExecutorDeviceListWithPage:(NSInteger)page
                                                limit:(NSInteger)limit
                                              keyword:(NSString *)keyword
                                              success:(nullable ThingSmartLightingDeviceListResult)success
                                              failure:(nullable ThingFailureError)failure;

@end
NS_ASSUME_NONNULL_END
