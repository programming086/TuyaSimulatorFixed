
#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>
#import "ThingMatterDeviceModel.h"
#import "ThingMatterSetupPayload.h"
#import "ThingConnectDeviceBuilder.h"
#import "ThingActivatorMatterNetworkScannedModel.h"


NS_ASSUME_NONNULL_BEGIN

@protocol ThingActivatorMatterInterfaceDelegate<NSObject>

- (void)discoveryedDevice:(ThingMatterDeviceModel *)model;


/// Discoveryed Matter Device
/// - Parameters:
///     - isThingDevice: Device is Thing Device or Third Device.
///     - deviceType: Device Type. if is third device,devicetype will be unKnown.
///     - error: Discovery device failed. is error is not nil, isThingDevice or deviceType is useless.
- (void)matterDeviceDiscoveryed:(BOOL)isThingDevice deviceType:(ThingMatterDeviceType)deviceType;

/// Matter device activator failed.
///
/// - Parameters:
///   - payload: setup payload.
///   - error: fail error info.
- (void)matterDevice:(ThingMatterSetupPayload *)payload activatorFailed:(NSError *)error;

/// Matter device activator success.
///
/// - Parameter matterDevice: the success device.
- (void)matterDeviceActivatorSuccess:(ThingMatterDeviceModel *)matterDevice;

/// Matter device attestation fail, use `-continueCommissioningDevice:ignoreAttestationFailure:error:` to continue OR interrupt.
///
/// **Notice**
/// Usually app will display a alert view to user, allowing the user to judge whether to ignore the attestation fail.
///
/// - Parameters:
///   - device: the failure device.
///   - error: the failure error info.
- (void)matterDeviceAttestation:(void *)device error:(NSError * _Nonnull)error;

/// System matter support operation complete.
///
/// - Parameter gatewayName: gateway device name.
- (void)matterSupportComplete:(NSString *)gatewayName;

/// Route tunnel of matter pairing
- (void)matterRoutingComplete:(ThingSmartMatterRoutingType)routingType;

/// Matter commission establish complet, model's type will be known
- (void)matterCommissioningSessionEstablishmentComplete:(ThingMatterDeviceModel *)deviceModel;

/// Status when matter pairing.This API will called many times when pairing.
- (void)matterCommissioningStatusUpdate:(ThingMatterDeviceStatus)status;

/// Matter Device scanned available wifi list
- (void)matterDeviceScannedAvailableWIFIList:(NSArray <ThingActivatorMatterNetworkScannedModel *> *)list;

@end

@protocol ThingActivatorMatterInterfaceProtocol <NSObject>

@property (nonatomic, weak) id<ThingActivatorMatterInterfaceDelegate> delegate;

/// Check the QRCode is available,and return the matter setup model.
/// @param qrString The QRCode string.
/// @return A matter setup model.
- (ThingMatterSetupPayload *)parseSetupCode:(NSString *)qrString;


/// Continue commissioning device with attestation.
/// @param device the point of device, must get from matterDeviceAttestation delagte.
/// @param ignoreAttestationFailure is ignore attestation fail
/// @param error error info
- (void)continueCommissioningDevice:(void *)device
           ignoreAttestationFailure:(BOOL)ignoreAttestationFailure
                              error:(NSError * __autoreleasing *)error;


/// Pair the matter device with ble mode.
/// @param builder The  matter setup info.
/// @param timeout Timeout
- (void)connectDeviceWithConnectDeviceBuilder:(ThingConnectDeviceBuilder *)builder timeout:(NSTimeInterval)timeout;

/// Cancel current activator.
- (void)cancelActivator;


- (void)setMatterConfigKey:(NSString *)key;

- (void)setGatewayDeviceBeforePairing:(ThingMatterDeviceModel *)deviceModel devId:(NSString *)devId;

- (ThingSmartMatterDeviceBoardingType)getBroadingType;

- (void)continueCommissionDevice:(ThingMatterDeviceModel *)deviceModel WithSSID:(NSString *)ssid password:(NSString *)password;


/// Auto-discovery search
- (void)startDiscovery;

/// Stop discovery 
- (void)stopDiscovery;

/// scan device acvailable wifi list.
- (void)startScanAvailableWIFI;

/// pair device into homekit
- (void)pairDeviceInHomeKit:(NSString *)matterCode success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
