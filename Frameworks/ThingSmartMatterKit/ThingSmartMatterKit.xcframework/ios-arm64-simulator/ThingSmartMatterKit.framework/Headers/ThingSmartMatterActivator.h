
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartMatterActivatorDelegate <NSObject>

/// Discoveryed Matter Device
/// - Parameters:
///     - isThingDevice: Device is Thing Device or Third Device.
///     - deviceType: Device Type. if is third device,devicetype will be unKnown.
///     - error: Discovery device failed. is error is not nil, isThingDevice or deviceType is useless.
- (void)matterDeviceDiscoveryed:(BOOL)isThingDevice deviceType:(ThingSmartMatterDeviceType)deviceType;

/// Matter device activator failed.
///
/// - Parameters:
///   - payload: setup payload.
///   - error: fail error info.
- (void)matterDevice:(ThingSmartMatterSetupPayload *)payload activatorFailed:(NSError *)error;

/// Matter device activator success.
///
/// - Parameter matterDevice: the success device.
- (void)matterDeviceActivatorSuccess:(ThingSmartMatterDeviceModel *)matterDevice;

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
- (void)matterRoutingComplete:(ThingMatterRoutingType)routingType;

/// Matter commission establish complet, model's type will be known
- (void)matterCommissioningSessionEstablishmentComplete:(ThingSmartMatterDeviceModel *)deviceModel;

/// Status when matter pairing.This API will called many times when pairing.
- (void)matterCommissioningStatusUpdate:(ThingMatterStatus)status;

/// Matter Device scanned available wifi list
- (void)matterDeviceScannedAvailableWIFIList:(NSArray <ThingSmartMatterNetworkScannedModel *> *)list;

@end

@interface ThingSmartMatterActivatorConfig : NSObject

/// Set your `App Groups identify` to share data with `Matter Extension`
///
/// **Notice**
/// 1. Please check the `configKey` must be same as the `App Groups identify` which is both chose it to `Matter Extension Target` and your  `App Main Target`.
/// 2. Please call this API before start pairing, Usually this api is called after the App is started and before the matter device activator starts.
///
/// - Parameter configKey: The App Groups identify.
+ (void)setMatterConfigKey:(NSString *)configKey;

+ (void)setMatterControllerAdminVendorID:(NSNumber *)adminVendorID;

@end

@interface ThingSmartMatterActivator : NSObject

@property (nonatomic, weak) id<ThingSmartMatterActivatorDelegate> delegate;

@property (nonatomic, strong, readonly) ThingSmartMatterDeviceModel *currentDeviceModel;

/// shareInstance
ThingSDK_SINGLETON


/// Check the matter code is legal or not. Returns nil if it is invalid.
///
/// - Parameter matterCode: The matter QRCode string or Manual Code string.
- (nullable ThingSmartMatterSetupPayload *)parseSetupCode:(NSString *)matterCode;


/// Start connect the matter device.
///
/// - Parameters:
///   - payload: The matter setup model.
///   - token: Thing activator token.
///   - spaceId: The homeId
- (void)connectDeviceWithConnectDeviceBuilder:(ThingSmartConnectDeviceBuilder *)builder timeout:(NSTimeInterval)timeout;


/// Continue pair WIFI or Thread matter device when session establishment completed.
///
/// **Notice:** There are some rules before use this api to continue pair the matter device.
/// 1. Can only be used after the `- matterCommissioningSessionEstablishmentComplete:`
/// 2. The `routingType` must be equal to `ThingMatterRoutingTypeThing`.  (`routingType` can be known by `-matterRoutingComplete:`)
/// 3. If you are pairing thread device and want to set gateway device, you can set gwid in ThingSmartMatterCommissionModel and use this api after the `- matterCommissioningSessionEstablishmentComplete:`
///  - Parameters:
///    - deviceModel: the matter devicemodel.
///    - commissionModel: commissionSetupModel
- (void)commissionDevice:(nonnull ThingSmartMatterDeviceModel *)deviceModel commissionModel:(ThingSmartMatterCommissionModel *)commissionModel;

/// Continue the pairing or NOT.
///
/// **Notice:** Can only be used after the `-matterDeviceAttestation:error:` delegate callback.
///
/// - Parameters:
///   - device: It MUST BE the device object through the `-matterDeviceAttestation:error:` delegate callback.
///   - ignoreAttestationFailure: Ignore the attestation fail or NOT.  `YES` - continue pairing,  `NO` - interrupt pairing.
///   - error: the error info.
- (void)continueCommissioningDevice:(void *)device
           ignoreAttestationFailure:(BOOL)ignoreAttestationFailure
                              error:(NSError * __autoreleasing *)error;

/// scan device acvailable wifi list.
- (void)startScanAvailableWIFI;


/// Cancel current activator.
- (void)cancelActivator;

@end

NS_ASSUME_NONNULL_END
