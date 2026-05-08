
#import <Foundation/Foundation.h>
#import "ThingGroupDef.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartDeviceModel;

@protocol ThingGroupServiceProtocol <NSObject>

@optional
#pragma mark Initialization
/// Initialize a group instance based on devId -- Create group
/// @param devId The device ID
- (instancetype)initWithDevId:(NSString *)devId;

/// Initialize a group instance based on groupId -- Edit group
/// @param groupId The group ID
- (instancetype)initWithGroupId:(NSString *)groupId;

/// Set the device list of the current family. Suitable for private Mesh groups, regular SIGMesh groups, and Beacon groups
- (void)setCurrentSpaceDeviceList:(NSArray<ThingSmartDeviceModel*> *)deviceList;

/// Initialize Zigbee remote control instance
/// @param devId The remote control device ID
/// @param localId The local ID
/// @param categoryCode The non-third-level category code, used in the cloud to determine and handle remote control groups. Zigbee remote controls have single group and 8-group differences, single group is 8001, 8-group ranges from 3001-3008
/// @param codes Secondary category codes
- (instancetype)initWithDevId:(NSString *)devId
                      localId:(NSString *)localId
                 categoryCode:(NSString *)categoryCode
                        codes:(NSArray *)codes;

/// Initialize remote control instance -- Old version SIGMesh remote control
/// @param devId The remote control device ID
/// @param localId The local ID
/// @param pccs PCC filtering conditions
- (instancetype)initWithDevId:(NSString *)devId
                      localId:(NSString *)localId
                         pccs:(NSArray *)pccs;

/// Initialize remote control instance -- New version SIGMesh remote control
/// @param devId The remote control device ID
/// @param localId The local ID
/// @param categoryCode Not a third-level category, matches the range 7001-7008 with localId; localId is cloud-assigned with a step size of 8, so one remote control can support up to 8 groups internally. The initial value of localId is incremented by 1, and categoryCode matches incrementally from 7001.
/// @param filterType Type, 0: pccs, 1: codes. The old panel does not have this field and is used as a distinction marker between old and new panels. The old panel follows previous local logic, while the new panel follows cloud logic.
/// @param pccs Mesh category
/// @param codes Secondary category codes
- (instancetype)initWithDevId:(NSString *)devId
                      localId:(NSString *)localId
                 categoryCode:(nullable NSString *)categoryCode
                   filterType:(nullable NSString *)filterType
                         pccs:(NSArray *)pccs
                        codes:(nullable NSArray *)codes;

#pragma mark - Group Creation and Editing
/// Get the list of devices that meet the conditions in the group
/// @param result The device list
/// @param failure Failure callback
- (void)fetchDeviceListWithSuccess:(ThingGroupDevListResult)result
                           failure:(void(^)(NSError *error))failure;

/// Create a group -- add devices to the group. This step is not required for remote control groups
/// @param name The group name
/// @param deviceList The list of devices to be added
/// @param process Progress information {"total":5,"current":1}
/// @param result Success callback {"groupId":"xxx"}
/// @param failure Failure callback {"groupId":"xxxx","failureList":[{"devId":"xxx","errorCode":1},{"devId":"xxx","errorCode":1}],"error":{"errorCode":1,"errorMsg":"xxx"}}. Parse the error information first; if the error does not exist, parse failureList. failureList is the list of failed devices.
- (void)createGroupWithName:(NSString *)name
                 deviceList:(NSArray <NSString *> *)deviceList
                    process:(ThingGroupProcess)process
                    success:(ThingGroupSuccess)result
                    failure:(ThingGroupResultFailure)failure;

/// Update the group
/// @param deviceList The selected device list
/// @param process Progress information {"total":5,"current":1}
/// @param result Success callback {"groupId":"xxx"}
/// @param failure Failure callback {"groupId":"xxxx","failureList":[{"devId":"xxx","errorCode":1},{"devId":"xxx","errorCode":1}],"error":{"errorCode":1,"errorMsg":"xxx"}}. Parse the error information first; if the error does not exist, parse failureList. failureList is the list of failed devices.
- (void)updateGroupWithDeviceList:(NSArray <NSString *> *)deviceList
                             process:(ThingGroupProcess)process
                             success:(ThingGroupSuccess)result
                          failure:(ThingGroupResultFailure)failure;

#pragma mark - Deleting Groups
/// Delete a group (supports both normal and shared groups) --- Not supported by remote control groups
/// @param groupId The group ID
/// @param success Success callback
/// @param failure Failure callback
- (void)removeGroupWithGroupId:(NSString *)groupId
                       success:(void (^)(void))success
                       failure:(void (^)(NSError *error))failure;

@end


NS_ASSUME_NONNULL_END

