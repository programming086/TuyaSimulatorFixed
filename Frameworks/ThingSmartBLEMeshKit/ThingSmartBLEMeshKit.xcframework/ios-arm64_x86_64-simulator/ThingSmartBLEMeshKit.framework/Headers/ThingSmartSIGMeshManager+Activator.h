
#import <ThingSmartBLEMeshKit/ThingSmartBLEMeshKit.h>

/// @brief The Bluetooth mesh activator category for the Bluetooth mesh manager.
///
/// This API provides multiple functions such as device scanning and activation.
@interface ThingSmartSIGMeshManager (Activator)

/// Starts to scan devices.
/// @param scanType The devices to be scanned are classified into the paired devices and the devices that are not paired. The devices that are not paired are added to the network after they are scanned.
/// @param meshModel The mesh model.
- (void)startScanWithScanType:(ThingSmartSIGScanType)scanType meshModel:(ThingSmartBleMeshModel *)meshModel __deprecated_msg("This method is deprecated, Use startSearch instead");

/// Starts to activate devices.
/// @param devList A list of devices to be activated.
/// @param meshModel The mesh model information.
- (void)startActive:(NSArray<ThingSmartSIGMeshDiscoverDeviceInfo *> *)devList meshModel:(ThingSmartBleMeshModel *)meshModel __deprecated_msg("This method is deprecated, Use startActive: instead");
- (void)startActive:(NSArray<ThingSmartSIGMeshDiscoverDeviceInfo *> *)devList;

- (void)appendActive:(NSArray<ThingSmartSIGMeshDiscoverDeviceInfo *> *)devList;

/// start search.  Activated devices are automatically connected
- (void)startSearch;

/// Connect the low-power nodes in the mesh network
/// @param nodeId Address in mesh network
- (void)connectLowPowerNode:(NSString *)nodeId;

/// Disconnect low-power nodes in the mesh network
- (void)disconnectLowPowerNode;

/// Stops device activation.
- (void)stopActiveDevice;

/// Stops all mesh device scanning.
- (void)stopSerachDevice;

/// Returns the node ID for the current connection.
- (NSString *)currentConnectNodeId;

//Query the online status of devices in the mesh
- (void)getDevicesOnlineStatus;

//Query the online status of offline devices in a mesh
- (void)getOfflineDevicesOnlineStatus;

/// Query the online status of cache advertising devices in a mesh
- (void)queryCachAdvNodeOnlineStatus;

#pragma mark --


@end

