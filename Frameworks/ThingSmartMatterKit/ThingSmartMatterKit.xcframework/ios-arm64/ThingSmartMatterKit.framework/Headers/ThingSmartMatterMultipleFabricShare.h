
#import <Foundation/Foundation.h>
#import "ThingSmartMatterMultipleFabricPasscodeModel.h"
#import "ThingSmartMatterFabricShareModel.h"
NS_ASSUME_NONNULL_BEGIN


@interface ThingSmartMatterMultipleFabricInfoModel : NSObject
@property (nonatomic, strong) NSNumber *vendorId;
@property (nonatomic, assign) long long nodeId;
@property (nonatomic, assign) long long fabricId;
@property (nonatomic, assign) NSInteger fabricIndex;
@property (nonatomic, strong, nullable) NSString *label;
@property (nonatomic, assign) BOOL isCurrent;
@end


@interface ThingSmartMatterMultipleFabricShare : NSObject

/// Create a `ThingSmartMatterMultipleFabricShare` object with a `ThingSmartDeviceModel` object.
/// @param deviceModel The object of `ThingSmartDeviceModel`
- (instancetype)initWithDeviceModel:(ThingSmartDeviceModel *)deviceModel;

/// Check the device multiple fabric command communicate channels available or not.
- (BOOL)checkPipelineAvailable;

/// Open commissing  window. (ECM Command)
///
/// - Parameters:
///   - forceRefresh: Force refresh the passcode info.
///   - ssidInfo: The Wi-Fi ssid currently connected to the device.
///   - success: Called when the task is finished.
///   - failure: Called when the task is interrupted by an error.
- (void)sendEnhancedCommissioningMethod:(BOOL)forceRefresh
                         ssidInfo:(nullable void(^)(NSString * __nullable ssid))ssidInfo
                          success:(void(^)(ThingSmartMatterFabricShareModel *shareModel))success
                          failure:(nullable ThingFailureError)failure;

/// Open commissing  window. (ECM Command)
///
/// - Parameters:
///   - forceRefresh: Force refresh the passcode info.
///   - ssidInfo: The Wi-Fi ssid currently connected to the device.
///   - success: Called when the task is finished.
///   - failure: Called when the task is interrupted by an error.
- (void)sendEnhancedCommissioning:(BOOL)forceRefresh
                         ssidInfo:(nullable void(^)(NSString * __nullable ssid))ssidInfo
                          success:(void(^)(NSString *qrCodeStr, NSString *setupCode))success
                          failure:(nullable ThingFailureError)failure __deprecated_msg("Please use `-sendEnhancedCommissioningMethod:ssidInfo:success:failure:`");

/// Read fabric info list.
/// - Parameters:
///   - success: Called when the task is finished.
///   - failure: Called when the task is interrupted by an error.
- (void)readFabricsWithSuccess:(void(^)(NSArray<ThingSmartMatterMultipleFabricInfoModel *> *fabrics))success
                       failure:(nullable ThingFailureError)failure;

/// Remove fabric by fabric index.
/// Notice: CAN'T remove current app fabric index.
/// - Parameters:
///   - fabricIndex: The fabric index.
///   - success: Called when the task is finished.
///   - failure: Called when the task is interrupted by an error.
- (void)removeFabricIndex:(NSInteger)fabricIndex
                  success:(ThingSuccessHandler)success
                  failure:(nullable ThingFailureError)failure;


#pragma mark - deprecate api
/// Open commissing  window. (ECM Command).
/// **Notice**
/// This API is deprecated, `-sendEnhancedCommissioning:ssidInfo:success:failure:` is recommended.
/// If you still want to use, you should use some other API to check before use this API:
///    1. Use `-getConnectedStatusSuccess:` to check device connect status
///    2. Use `-readSupportedFabricsSuccess:failure:` to get the maximum supported fabrics, and use `-readSupportedFabricsSuccess:failure:` to get the used fabrics number, if them equal, you CAN'T continue the flow.
///    3. Use `-revokeCommissioningCommandSuccess:failure:` to precheck the commissioning window.
///    4. Use `-getMultipleFabricPasscodeCompletion:` or `-getMultipleFabricPasscodeForceRefreshCompletion` to Get the passcodeModel.
///
/// - Parameters:
///   - passcodeModel: Use `-getMultipleFabricPasscodeCompletion:` or `-getMultipleFabricPasscodeForceRefreshCompletion` to Get the passcodeModel.
///   - success: Called when the task is finished.
///   - failure: Called when the task is interrupted by an error.
- (void)sendEnhancedCommissioningCommandWithFabricPasscodeModel:(ThingSmartMatterMultipleFabricPasscodeModel *)passcodeModel
                                                        success:(void(^)(NSString *qrCodeStr, NSString *setupCode))success
                                                        failure:(nullable ThingFailureError)failure __deprecated_msg("Please use `-sendEnhancedCommissioning:ssidInfo:success:failure:`");

/// Get matter connected Status.
- (void)getConnectedStatusSuccess:(ThingSuccessHandler)success failure:(nullable ThingFailureError)failure __deprecated_msg("This api is deprecate.");

/// Read supported fabric max count.
- (void)readSupportedFabricsSuccess:(ThingSuccessInt)success failure:(nullable ThingFailureError)failure __deprecated_msg("This api is deprecate.");

/// Read the commisstioned fabric count.
- (void)readCommissionedFabricsSuccess:(ThingSuccessInt)success failure:(nullable ThingFailureError)failure __deprecated_msg("This api is deprecate.");

/// Request the multiple fabric passcode model.
- (void)getMultipleFabricPasscodeCompletion:(void(^)(ThingSmartMatterMultipleFabricPasscodeModel *result, NSError *error))completionBlock __deprecated_msg("This api is deprecate. Please use `- sendEnhancedCommissioning:ssidInfo:success:failure:` directly");

/// Request the multiple fabric passcode model. (Force Refresh)
- (void)getMultipleFabricPasscodeForceRefreshCompletion:(void(^)(ThingSmartMatterMultipleFabricPasscodeModel *result, NSError *error))completionBlock __deprecated_msg("This api is deprecate. Please use `- sendEnhancedCommissioning:ssidInfo:success:failure:` directly");

/// GenerateQrCode
- (NSString *)generateQrCodeWithFabricPasscodeModel:(ThingSmartMatterMultipleFabricPasscodeModel*)passcodeModel __deprecated_msg("This api is deprecate. Please use `- sendEnhancedCommissioning:ssidInfo:success:failure:` directly");

/// Get the Wi-Fi ssid currently connected to the device.
- (void)getWifiDeviceSsid:(ThingSuccessString)success failure:(nullable ThingFailureError)failure;

/// Close commissing window.
- (void)revokeCommissioningCommandSuccess:(ThingSuccessHandler)success failure:(nullable ThingFailureError)failure __deprecated_msg("This api is deprecate.");

@end

NS_ASSUME_NONNULL_END
