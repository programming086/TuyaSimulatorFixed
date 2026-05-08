
#import <Foundation/Foundation.h>
#import "ThingSIGMeshConfigModel.h"

NS_ASSUME_NONNULL_BEGIN

/// The type of Bluetooth mesh manager for inactive and active devices.
typedef NS_ENUM(NSUInteger, ThingSmartSIGScanType) {
    /// Scans devices that are not paired.
    ScanForUnprovision,
    /// Scans paired devices.
    ScanForProxyed,
};

@class ThingSmartSIGMeshManager;
@class ThingSIGMeshFittingMsgModel;
@class ThingSmartSIGMeshDiscoverDeviceInfo;
@class ThingMeshLogEventService;

/// The delegate of the Bluetooth mesh manager. The delegate is instantiated when the Bluetooth mesh manager processes messages.
@protocol ThingSmartSIGMeshManagerDelegate <NSObject>

@optional;

/// The callback that is used when a sub-device is activated.
/// @param manager The value of ThingSmartSIGMeshManager.
/// @param device The value of ThingSmartSIGMeshDiscoverDeviceInfo.
/// @param devId The device ID.
/// @param error An error occurs while activating the sub-device. The values of `name' and 'deviceid' are empty in the response.
- (void)sigMeshManager:(ThingSmartSIGMeshManager *)manager didActiveSubDevice:(ThingSmartSIGMeshDiscoverDeviceInfo *)device devId:(NSString *)devId error:(NSError *)error;

/// The callback that is used when a device failed to be activated.
/// @param manager The value of ThingSmartSIGMeshManager.
/// @param device The value of ThingSmartSIGMeshDiscoverDeviceInfo.
/// @param error An error occurs while activating the device.
- (void)sigMeshManager:(ThingSmartSIGMeshManager *)manager didFailToActiveDevice:(ThingSmartSIGMeshDiscoverDeviceInfo *)device error:(NSError *)error;

/// The callback that is used when the activation is completed.
- (void)didFinishToActiveDevList;
- (void)didFinishToActiveDevList:(ThingSmartSIGMeshManager *)manager;

/// The callback that is used when a device is disconnected.
- (void)notifyCentralManagerDidDisconnectPeripheral;
- (void)notifyCentralManagerDidDisconnectPeripheral:(ThingSmartSIGMeshManager *)manager;

- (void)didProxyAndRelayStatusUpdated:(NSString *)devId;

/// Scans a device for pairing.
/// @param manager The value of ThingSmartSIGMeshManager.
/// @param device The value of ThingSmartSIGMeshDiscoverDeviceInf.
- (void)sigMeshManager:(ThingSmartSIGMeshManager *)manager didScanedDevice:(ThingSmartSIGMeshDiscoverDeviceInfo *)device;


/// Scans a device for actived
/// @param manager The value of ThingSmartSIGMeshManager.
/// @param device The value of ThingSmartSIGMeshDiscoverDeviceInf.
- (void)sigMeshManager:(ThingSmartSIGMeshManager *)manager provisionedSIGMeshDevice:(ThingSmartSIGMeshDiscoverDeviceInfo *)device;

/// Completes the group operation.
/// @param manager The value of ThingSmartSIGMeshManager.
/// @param groupAddress The group mesh address in the hexadecimal format.
/// @param nodeId The device mesh node address in the hexadecimal format.
/// @param error An error occurs while processing the request.
- (void)sigMeshManager:(ThingSmartSIGMeshManager *)manager didHandleGroupWithGroupAddress:(NSString *)groupAddress deviceNodeId:(NSString *)nodeId error:(NSError *)error;

- (void)newSigMeshManager:(ThingSmartSIGMeshManager *)manager didHandleGroupWithGroupAddress:(NSString *)groupAddress deviceNodeId:(NSString *)nodeId error:(NSError *)error;

/// Queries a list of device groups.
/// @param manager The value of ThingSmartSIGMeshManager.
/// @param groupList A list of group addresses.
/// @param deviceModel The device model.
/// @param error An error occurs while processing the request.
- (void)sigMeshManager:(ThingSmartSIGMeshManager *)manager
        queryGroupList:(NSArray<NSString *> *)groupList
           deviceModel:(ThingSmartDeviceModel *)deviceModel
                 error:(NSString * _Nullable)error;

/// The notification of login success. This parameter is required for an update.
- (void)notifySIGLoginSuccess:(BOOL)success;
- (void)notifySIGLoginSuccess;
- (void)notifySIGLoginSuccess:(BOOL)success manager:(ThingSmartSIGMeshManager *)manager;

/// The callback that is used when a mesh network is connected. This enables subsequent local communication.
- (void)didConnectMeshNodeAndLoginMesh;
- (void)didConnectMeshNodeAndLoginMesh:(ThingSmartSIGMeshManager *)manager;

- (void)sigMeshManager:(ThingSmartSIGMeshManager *)manager queryDeviceModel:(ThingSmartDeviceModel *)deviceModel groupAddress:(uint32_t)groupAddress;

// Returns the values of `opCode` and `payload`.
- (void)sigMeshManager:(ThingSmartSIGMeshManager *)manager didReceivedCustomOpCodeData:(NSData *)opCode payload:(NSData *)payload;

// A list of model IDs to be managed over the mesh network.
- (NSArray<NSNumber *> *)listOfCustomModelIdWithSigMeshManager:(ThingSmartSIGMeshManager *)manager;

/// Called when a message is received from a Fitting.
/// - Parameters:
///   - manager: manager
///   - message: Fitting's message
- (void)sigMeshManager:(ThingSmartSIGMeshManager *)manager receivedFittingMessage:(ThingSIGMeshFittingMsgModel *)message;

/// Optional parameters to register the device with the cloud.
- (NSDictionary *)OptionalParametersToRegisterDeviceWithTheCloud;

@end


@class MeshStateManager;
/// @brief The Bluetooth mesh manager supports common Bluetooth mesh management classes and enables multiple functions. For example, the classes can be called to create groups, send control commands, and remove devices.
///
/// A large number of extension APIs are available to support various methods and scenarios.
/// 
@interface ThingSmartSIGMeshManager : NSObject

+ (instancetype)sharedInstance __deprecated_msg("This method is deprecated, Use ThingSmartBleMesh::initSIGMeshManager:ttl:nodeIds: instead");

/// Whether the current network is connected
@property (nonatomic, assign, readonly) BOOL isLogin;
/// Indicates the Bluetooth status of the system.
@property (nonatomic, assign) BOOL isPoweredOn;

@property (nonatomic, strong) ThingSmartBleMesh *sigMesh;

@property (nonatomic, weak) id<ThingSmartSIGMeshManagerDelegate> delegate;

@property (nonatomic, copy) NSString *otaTargetNodeId; /// The node ID of the updated device.

@property (nonatomic, strong) NSArray<NSData *> *nodeIds;//已知的nodeId列表

@property (nonatomic, strong) MeshStateManager *meshState;

@property (nonatomic, strong) ThingMeshLogEventService *groupEventService;

@property (nonatomic, strong)NSMutableArray *nodeList;

@property (nonatomic, strong) NSMutableArray *onlineNodeList;

@property (nonatomic, copy, nullable) void (^isConnectOTAAddress)(BOOL isSuccess);


- (void)setConfig:(ThingSIGMeshConfigModel *)configModel;

- (void)offlineSIGMeshNetwork;

- (BOOL)isLowPowerNode:(ThingSmartDeviceModel *)model;

@end

NS_ASSUME_NONNULL_END
