
#import "ThingSmartBleMesh.h"
#import "ThingSmartSIGMeshManager.h"

NS_ASSUME_NONNULL_BEGIN

/// @brief The category of the Bluetooth mesh information.
@interface ThingSmartBleMesh (SIGMesh)

+ (void)createSIGMeshWithHomeId:(long long)homeId
                        success:(void(^)(ThingSmartBleMeshModel *meshModel))success
                        failure:(ThingFailureError)failure;

/// init SIGMeshManager by meshModel 、 ttl and nodeIds
/// @param meshModel meshModel
/// @param ttl Number of times messages are forwarded on the network default is 8
/// @param nodeIds All  nodeId in the mesh network (Does not contain low-power nodeIds)
+ (ThingSmartSIGMeshManager * _Nullable)initSIGMeshManager:(ThingSmartBleMeshModel *)meshModel
                                                      ttl:(NSInteger)ttl
                                                  nodeIds:(NSArray<NSData *> * _Nullable)nodeIds;

/// get SIGMeshManager by meshId
/// @param meshId meshId
+ (ThingSmartSIGMeshManager * _Nullable)getSIGMeshManager:(NSString *)meshId;

/// remove sigmesh network
/// @param meshId meshId
+ (void)deleteSIGMeshManager:(NSString *)meshId;

/// Set the maximum number of supported sigmesh networks
/// @param count count default is 3
+ (void)setSIGMeshNetworkMaxCount:(NSInteger)count;

+ (NSInteger)getSIGMeshNetworkMaxCount;

+ (NSArray <ThingSmartSIGMeshManager *>*)getAllSIGMeshManager;

/// Get the unactive device information
/// @param productId The productId of device
/// @param mac The mac of device
/// @param success  Called when the task is finished. A dictionary of device information is returned.
/// @param failure Called when the task is interrupted by an error.
+ (void)getUnActiceDeviceInfo:(NSString *)productId
                          mac:(NSString *)mac
                      success:(ThingSuccessDict)success
                      failure:(ThingFailureError)failure;

/// Reports the result of the successful pairing between a Bluetooth sub-device and the app to the cloud. The `productKey` and `mac` parameters are included in the report. Then, the cloud returns the product ID (PID) based on both parameters.
/// @param uuid The short address identification of the Bluetooth sub-device.
/// @param devKey The device key.
/// @param nodeId The node ID.
/// @param productKey The product key.
/// @param ver The version.
/// @param mac The MAC address of the device.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addSIGMeshSubDeviceWithUuid:(NSString *)uuid
                             devKey:(NSString *)devKey
                             nodeId:(NSString *)nodeId
                         productKey:(NSString *)productKey
                                ver:(NSString *)ver
                                mac:(NSString *)mac
                            success:(void (^)(NSString *devId, NSString *name))success
                            failure:(ThingFailureError)failure;

/// Reports information about the paired Bluetooth device to the cloud after the device is connected to the network. The product key and MAC address are included in the report. The cloud returns the PID based on the reported information. This applies when a third-party device is paired.
/// @param uuid The short address identification of the Bluetooth sub-device.
/// @param devKey The device key.
/// @param nodeId The node ID.
/// @param productKey The product key.
/// @param ver The version.
/// @param mac The MAC address of the device.
/// @param companyId The company ID of the Bluetooth mesh device.
/// @param venderId This parameter is required to add a third-party device to the app. Lighting devices, switches, and other low-power devices are supported.
/// @param success  Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addSIGMeshSubDeviceWithUuid:(NSString *)uuid
                             devKey:(NSString *)devKey
                             nodeId:(NSString *)nodeId
                         productKey:(NSString *)productKey
                                ver:(NSString *)ver
                                mac:(NSString *)mac
                          companyId:(nonnull NSString *)companyId
                           venderId:(nonnull NSString *)venderId
                            success:(void (^)(NSString *devId, NSString *name))success
                            failure:(ThingFailureError)failure;

/// Binds a PID to a Bluetooth device before the network is connected.
/// @param uuid The short address identification of the Bluetooth sub-device.
/// @param devKey The device key.
/// @param nodeId The node ID.
/// @param productId The product ID.
/// @param ver The version.
/// @param mac The MAC address of the device.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addSIGMeshSubDeviceWithUuid:(NSString *)uuid
                             devKey:(NSString *)devKey
                             nodeId:(NSString *)nodeId
                          productId:(NSString *)productId
                                ver:(NSString *)ver
                                mac:(NSString *)mac
                            success:(void (^)(NSString *devId, NSString *name))success
                            failure:(ThingFailureError)failure;

/// The Bluetooth device is bound with a PID before the network is connected. This applies when a third-party device is paired.
/// @param uuid The short address identification of the Bluetooth sub-device.
/// @param devKey The device key.
/// @param nodeId The node ID.
/// @param productId The product ID.
/// @param ver The version.
/// @param mac The MAC address of the device.
/// @param companyId The company ID.
/// @param venderId This parameter is required to add a third-party device to the app. Lighting devices, switches, and other low-power devices are supported.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addSIGMeshSubDeviceWithUuid:(NSString *)uuid
                             devKey:(NSString *)devKey
                             nodeId:(NSString *)nodeId
                          productId:(NSString *)productId
                                ver:(NSString *)ver
                                mac:(NSString *)mac
                          companyId:(nullable NSString *)companyId
                           venderId:(nullable NSString *)venderId
                            success:(void (^)(NSString *devId, NSString *name))success
                            failure:(ThingFailureError)failure;

/// Assigns the node ID of Bluetooth mesh from the cloud. In each request, the node ID is incremented by `0000 0111` or `8`.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getSIGMeshNodeAddressFromServerWithSuccess:(ThingSuccessInt)success
                                           failure:(ThingFailureError)failure;

/// Returns multiple node IDs of Bluetooth mesh in a call.
/// @param number The number of assigned node IDs.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getMultiNodeAddressFromServerWithNumber:(NSInteger)number
                                        success:(ThingSuccessList)success
                                        failure:(ThingFailureError)failure;

/// Removes a Bluetooth mesh sub-device from the gateway to which the sub-device is connected.
/// @param gatewayId The gateway ID.
/// @param subDeviceId The sub-device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)removeMeshSubDeviceWithGatewayId:(NSString *)gatewayId
                             subDeviceId:(NSString *)subDeviceId
                                 success:(ThingSuccessHandler)success
                                 failure:(ThingFailureError)failure;

- (void)removeMeshSubDeviceWithMeshId:(NSString *)meshId
                             deviceId:(NSString *)deviceId
                              success:(ThingSuccessHandler)success
                              failure:(ThingFailureError)failure;

/// Assigns the terminal source ID of Bluetooth mesh from the cloud.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)getSIGMeshSourceAddressFromServerWithSuccess:(ThingSuccessInt)success
                                             failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
