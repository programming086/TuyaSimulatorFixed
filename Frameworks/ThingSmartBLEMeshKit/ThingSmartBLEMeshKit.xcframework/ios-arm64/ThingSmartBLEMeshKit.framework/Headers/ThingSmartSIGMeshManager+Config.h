
#import <ThingSmartBLEMeshKit/ThingSmartBLEMeshKit.h>
#import "ThingSIGMeshSceneModel.h"
#import "ThingSIGMeshDCSLinkageConstants.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartDeviceModel;
@class ThingSIGMeshDCSLinkageModel;
@class ThingSIGMeshDCSHashModel;
@class ThingSIGMeshDpActionModel;
@class ThingSIGMeshQueryDpsModel;

/// @brief The Bluetooth mesh activator category for the Bluetooth mesh manager.
///
/// This API provides multiple functions such as device node control and resetting. The core channels are also used to send generic mesh messages.
@interface ThingSmartSIGMeshManager (Config)

/// Resets the node.
/// @param deviceModel The value of ThingSmartDeviceModel.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendNodeResetWithDeviceModel:(ThingSmartDeviceModel *)deviceModel
                             success:(nullable ThingSuccessHandler)success
                             failure:(nullable ThingFailureError)failure;

/// Switch the Proxy State.
/// @param switchState Proxy State
/// @param devId The value of ThingSmartDeviceModel ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)switchProxyState:(BOOL)switchState
             forDeviceID:(NSString *)devId
                 success:(nullable ThingSuccessHandler)success
                 failure:(nullable ThingFailureError)failure;

/// Switch the Relay State.
/// @param switchState Relay State
/// @param devId The value of ThingSmartDeviceModel ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)switchRelayState:(BOOL)switchState
             forDeviceID:(NSString *)devId
                 success:(ThingSuccessHandler)success
                 failure:(ThingFailureError)failure;

/// Controls the switch.
/// @param nodeId The node ID.
/// @param state The switch status.
/// @param useUnacknowledged Specifies whether a response is required. We recommend that you set the value to `no` in the case of group control and `yes` in the case of single-device control.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendOnoffWithNodeId:(NSString *)nodeId
                      state:(BOOL)state
          useUnacknowledged:(BOOL)useUnacknowledged
                    success:(nullable ThingSuccessHandler)success
                    failure:(nullable ThingFailureError)failure;

/// Controls the brightness.
/// @param nodeId The node ID.
/// @param brightValue The brightness value. Valid values: `0` to `65535`.
/// @param useUnacknowledged Specifies whether a response is required. We recommend that you set the value to `no` in the case of group control and `yes` in the case of single-device control.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendLightBrightWithNodeId:(NSString *)nodeId
                      brightValue:(int)brightValue
                useUnacknowledged:(BOOL)useUnacknowledged
                          success:(nullable ThingSuccessHandler)success
                          failure:(nullable ThingFailureError)failure;

/// Controls the heating and cooling functions.
/// @param nodeId The node ID.
/// @param tempValue Specifies the warm and cool temperatures. Valid values: 300 to 20000.
/// @param useUnacknowledged Specifies whether a response is required. We recommend that you set the value to `no` in the case of group control and `yes` in the case of single-device control.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendLightCTLTempeValueWithNodeId:(NSString *)nodeId
                               tempValue:(int)tempValue
                       useUnacknowledged:(BOOL)useUnacknowledged
                                 success:(nullable ThingSuccessHandler)success
                                 failure:(nullable ThingFailureError)failure;

/// Controls the hue, lightness, and saturation (HLS) color model.
/// @param nodeId The node ID.
/// @param aHue The Hue. Valid values: `0` to `65535`.
/// @param aSaturation The saturation. Valid values: `0` to `65535`.
/// @param aLightness The brightness. Valid values: `l` and `v`, `0` to `65535`.
/// @param useUnacknowledged Specifies whether a response is required. We recommend that you set the value to `no` in the case of group control and `yes` in the case of single-device control.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendLightHSLWithNodeId:(NSString *)nodeId
                           hue:(int)aHue
                 andSaturation:(int)aSaturation
                     lightness:(int)aLightness
             useUnacknowledged:(BOOL)useUnacknowledged
                       success:(nullable ThingSuccessHandler)success
                       failure:(nullable ThingFailureError)failure;

/// The setup mode.
/// @param nodeId The node ID.
/// @param alightModel The light model. Valid values: `0`: the white light mode. `1`: the colored light mode.
/// @param useUnacknowledged Specifies whether a response is required. We recommend that you set the value to `no` in the case of group control and `yes` in the case of single-device control.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendLightModelWithNodeId:(NSString *)nodeId
                      lightModel:(int)alightModel
               useUnacknowledged:(BOOL)useUnacknowledged
                         success:(nullable ThingSuccessHandler)success
                         failure:(nullable ThingFailureError)failure;

/// The generic vendor protocol.
/// @param nodeId The node ID.
/// @param vendorData The data content.
/// @param isisQuery Specifies whether a query command is sent.
/// @param useUnacknowledged Specifies whether a response is required. We recommend that you set the value to `no` in the case of group control and `yes` in the case of single-device control.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendVendorDataWithNodeId:(NSString *)nodeId
                      vendorData:(NSData *)vendorData
                         isQuery:(BOOL)isisQuery
               useUnacknowledged:(BOOL)useUnacknowledged
                         success:(nullable ThingSuccessHandler)success
                         failure:(nullable ThingFailureError)failure;

/// The custom channel that is enabled with the vendor commands.
/// @param nodeId The node ID.
/// @param opCode The operation code.
/// @param payload The metadata.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)sendCustomDataWithNodeId:(NSString *)nodeId
                          opCode:(int)opCode
                         payload:(NSData *)payload
                         success:(nullable ThingSuccessHandler)success
                         failure:(nullable ThingFailureError)failure;

/// Sends DPs to a single device.
/// @param nodeId The node ID.
/// @param schemaArray The array of DP information.
/// @param dps The DPs.
/// @param pcc The size class label of the product.
/// @param useUnacknowledged Specifies whether a response is required. 
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)publishDpsWithNodeId:(NSString *)nodeId
                 schemaArray:(NSArray<ThingSmartSchemaModel *> *)schemaArray
                         dps:(NSDictionary *)dps
                         pcc:(NSString *)pcc
           useUnacknowledged:(BOOL)useUnacknowledged
                     success:(nullable ThingSuccessHandler)success
                     failure:(nullable ThingFailureError)failure;

/// Returns the status of a device.
/// @param deviceModel The device model.
- (void)getDeviceStatusWithDeviceModel:(ThingSmartDeviceModel *)deviceModel;

/// Queries the device DPs.
/// @param deviceModel The device model.
/// @param dpIds The group of DP IDs to be queries.
- (void)queryDpsWithDeviceModel:(ThingSmartDeviceModel *)deviceModel dpIds:(NSArray<NSString *> *)dpIds;

/// Send vendor message with scene data to device
/// @param model scene model
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)startSceneDataTransfer:(ThingSIGMeshSceneModel *)model success:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;

/// Add/Config the linkage
/// @param nodeId The node ID.
/// @param model The linkage model
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)addLinkageWithNodeId:(NSString *)nodeId linkageModel:(ThingSIGMeshDCSLinkageModel *)model success:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;


/// Delete the linkage
/// @param nodeId The node ID.IF nodeID is ThingSIGMeshBroadCastNode,it indicates the broadcast address, and the callback(sucess/failure) result will not be returned.
/// @param automathionId The automathion ID
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)deleteLinkageWithNodeId:(NSString *)nodeId automationId:(int)automathionId success:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;

/// Operate the linkage of opType
/// @param nodeId The node ID.IF nodeID is ThingSIGMeshBroadCastNode,it indicates the broadcast address, and the callback(sucess/failure) result will not be returned.
/// @param automathionId The automathion ID
/// @param opType The operator type
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)operateLinkageWithNodeId:(NSString *)nodeId
                    automationId:(int)automathionId
                    operatorType:(ThingSIGMeshDCSLinkageOperatorType)opType
                         success:(nullable ThingSuccessHandler)success
                         failure:(nullable ThingFailureError)failure;

/// Query hash of device
/// @param nodeId The node ID.IF nodeID is ThingSIGMeshBroadCastNode,it indicates the broadcast address, and the callback(sucess/failure) result will not be returned.
/// @param automathionId The automathion ID
/// @param success Called when the task is finished.Return NSArray <ThingSIGMeshDCSHashModel *> *
/// @param failure Called when the task is interrupted by an error.
- (void)queryHashWithNodeId:(NSString *)nodeId automationId:(int)automathionId success:(nullable ThingSuccessList)success failure:(nullable ThingFailureError)failure;

/// Compare Hash
/// @param nodeId The node ID
/// @param hashModel The device hashModel
/// @param model The model of linkage
/// @return The result of comparison
- (BOOL)compareHashWithNodeId:(NSString *)nodeId hashModel:(ThingSIGMeshDCSHashModel *)hashModel linkageModel:(ThingSIGMeshDCSLinkageModel *)model;

/// Batch sending dp
/// @param dpActions dp
/// @param retryCount retryCount
- (void)batchPublishDps:(NSArray <ThingSIGMeshDpActionModel *>*)dpActions retryCount:(NSInteger)retryCount;

/// Batch querying device's dp.
/// @discussion  Calls {@link ThingSmartDeviceDelegate's  device:dpsUpdate:} when receiving the device reply.
/// @param dps dps
/// @param force If the value is NO, the SDK has received the dpId data to be queried and ignores the query. If the value is YES, the query is forced. The recommended setting is NO.
- (void)batchQueryDps:(NSArray <ThingSIGMeshQueryDpsModel*>*)dps forceQuery:(BOOL)force;

/// Send a message to the fitting
/// @param message message
- (void)sendFittingMessage:(ThingSIGMeshFittingMsgModel *)message;

@end

NS_ASSUME_NONNULL_END
