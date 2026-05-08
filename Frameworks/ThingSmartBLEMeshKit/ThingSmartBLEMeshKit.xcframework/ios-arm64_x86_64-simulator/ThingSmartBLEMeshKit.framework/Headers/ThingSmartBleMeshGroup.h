
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartBleMeshGroup;

/// The Bluetooth mesh group delegate. The delegate is instantiated when a gateway is used to add a device to a group.
@protocol ThingSmartBleMeshGroupDelegate <NSObject>

/// The group response that is returned when the Bluetooth mesh device joins the gateway.
/// @param group The Thing Smart Bluetooth mesh group.
/// @param responseCode Valid values: `1`: exceeds the maximum number of scenes. `2`: sub-device timeout. `3`: specifies a value out of range. `4`: file writing error. `5`: other errors.
- (void)meshGroup:(ThingSmartBleMeshGroup *)group addResponseCode:(NSArray <NSNumber *> *)responseCode;

/// The group response that is returned when a Bluetooth mesh device is removed.
/// @param group The Thing Smart Bluetooth mesh group.
/// @param responseCode Valid values: `1`: exceeds the maximum number of scenes. `2`: sub-device timeout. `3`: specifies a value out of range. `4`: file writing error. `5`: other errors.
- (void)meshGroup:(ThingSmartBleMeshGroup *)group removeResponseCode:(NSArray <NSNumber *> *)responseCode;
  
@end

/// @brief The Thing Bluetooth mesh device groups allow you to create and update groups and add devices to the groups.
///
/// You can create a group of mesh devices with the same functions and simultaneously control them with a single command.
///
@interface ThingSmartBleMeshGroup : NSObject

@property (nonatomic, weak, nullable) id<ThingSmartBleMeshGroupDelegate> delegate;

@property (nonatomic, strong, readonly) ThingSmartGroupModel *meshGroupModel;

/// Returns the mesh group object.
/// @param groupId The group ID.
+ (instancetype)meshGroupWithGroupId:(NSInteger)groupId;

/// Returns the mesh group object.
/// @param groupId The group ID.
- (instancetype)initWithGroupId:(NSInteger)groupId NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/// Assigns a group ID from the cloud.
/// @param meshId The mesh ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)getBleMeshGroupAddressFromCluondWithMeshId:(NSString *)meshId
                                           success:(ThingSuccessInt)success
                                           failure:(ThingFailureError)failure;

/// Creates a mesh group.
/// @param groupName The mesh group name.
/// @param meshId The mesh ID.
/// @param localId The local short address of the group.
/// @param pcc The size class label of each group device.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)createMeshGroupWithGroupName:(NSString *)groupName
                              meshId:(NSString *)meshId
                             localId:(NSString *)localId
                                 pcc:(NSString *)pcc
                             success:(ThingSuccessInt)success
                             failure:(ThingFailureError)failure;

+ (NSInteger)getBleMeshGroupAddress;

+ (NSInteger)getBleMeshGroupCount;

- (void)deleteBleMeshGroupAddress:(NSInteger)address;

/// Modifies the mesh group name.
/// @param meshGroupName The mesh group name.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)updateMeshGroupName:(NSString *)meshGroupName success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Deletes the mesh group.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeMeshGroupWithSuccess:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Adds a device.
/// @param deviceId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addDeviceWithDeviceId:(NSString *)deviceId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Modifies multiple devices in a call.
/// @param deviceList The device list.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)editDeviceWithDeviceList:(NSArray *)deviceList success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Removes the device.
/// @param deviceId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeDeviceWithDeviceId:(NSString *)deviceId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Returns a list of devices from the group.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getDeviceListInfoWithSuccess:(void (^)(NSArray <ThingSmartDeviceModel *> *deviceList))success failure:(ThingFailureError)failure;

/// Returns a list of devices from the group.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use ThingSmartBleMeshGroup getDeviceListInfoWithSuccess:failure: instead.
- (void)getDeviveListInfoWithSuccess:(void (^)(NSArray <ThingSmartDeviceModel *> *deviceList))success failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartBleMeshGroup getDeviceListInfoWithSuccess:failure:] instead");

@end

#pragma mark - SIG Mesh

/// @brief You can use a gateway to send commands to a group and add devices to the group.
@interface ThingSmartBleMeshGroup (SIGMesh)

/// Adds a Bluetooth mesh sub-device group through the Bluetooth mesh gateway.
/// The sub-devices must belong to the Bluetooth mesh gateway.
/// @param subList The gateway sub-device to be managed.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addSubDeviceWithSubList:(NSArray<ThingSmartDeviceModel *> * _Nonnull )subList success:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;

/// Adds a Bluetooth mesh sub-device group through the Bluetooth mesh gateway.
/// The sub-devices must belong to the Bluetooth mesh gateway.
/// @param subList The gateway sub-device to be managed.
/// @param localId mesh groupId
/// @param devId remote control's devId
/// @param categoryCode remote control's categoryCode
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addSubDeviceWithSubList:(NSArray<ThingSmartDeviceModel *> * _Nonnull )subList localId:(NSString *)localId mainDevId:(nullable NSString *)devId categoryCode:(nullable NSString *)categoryCode success:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;


/// Deletes a Bluetooth mesh sub-device group through the Bluetooth mesh gateway.
/// The sub-devices must belong to the Bluetooth mesh gateway.
/// @param subList The gateway sub-device to be managed.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeSubDeviceWithSubList:(NSArray<ThingSmartDeviceModel *> * _Nonnull )subList success:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;

/// Deletes a Bluetooth mesh sub-device group through the Bluetooth mesh gateway.
/// The sub-devices must belong to the Bluetooth mesh gateway.
/// @param subList The gateway sub-device to be managed.
/// @param localId  mesh groupId
/// @param devId remote control's devId
/// @param categoryCode remote control's categoryCode
/// @param success Called when the task is finished.
/// @param failure  Called when the task is interrupted by an error.
- (void)removeSubDeviceWithSubList:(NSArray<ThingSmartDeviceModel *> * _Nonnull )subList localId:(NSString *)localId mainDevId:(nullable NSString *)devId categoryCode:(nullable NSString *)categoryCode success:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;

- (void)publishDps:(NSDictionary *)dps success:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;

/// Publishes custom parameters.
/// @param params param:dictionary  { "localId":"c050" ,"dps":{"1":true}  "pcc":"1510"}
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDpsWithParams:(NSDictionary *)params success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END

