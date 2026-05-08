
#ifndef ThingMatterShareInterfaceAPI_h
#define ThingMatterShareInterfaceAPI_h

#import "ThingMatterMultipleFabricPasscodeModel.h"
#import "ThingMatterMultipleFabricInfoModel.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ThingSuccessHandler)(void);
typedef void (^ThingSuccessInt)(int result);
typedef void (^ThingSuccessString)(NSString *result);

typedef void (^ThingFailureHandler)(void);
typedef void (^ThingFailureError)(NSError * _Nonnull error);


@protocol ThingMatterShareInterfaceProtocol <NSObject>


/// get matter connected Status 
/// @param devid           devid
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)getConnectedStatusSuccessWithDevid:(NSString *)devid success:(ThingSuccessHandler)success failure:(ThingFailureError)failure __deprecated_msg("This api is deprecate.");

/// readSupportedFabrics 
/// @param devid           devid
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
/// 
- (void)readSupportedFabricsWithDevid:(NSString *)devid success:(ThingSuccessInt)success failure:(ThingFailureError)failure __deprecated_msg("This api is deprecate.");

/// readCommissionedFabrics
/// @param devid           devid
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)readCommissionedFabricsWithDevid:(NSString *)devid success:(ThingSuccessInt)success failure:(ThingFailureError)failure __deprecated_msg("This api is deprecate.");

//passcode

/// getMultipleFabricPasscode
/// @param devid           devid
/// @param completionBlock      Called when the task is finished.
- (void)getMultipleFabricPasscodeWithDevid:(NSString *)devid completion:(void(^)(ThingMatterMultipleFabricPasscodeModel *passcodeModel, NSError *error))completionBlock __deprecated_msg("This api is deprecate. Please use `-sendEnhancedCommissioningWithDevid:forceRefresh:ssidInfo:success:failure:` directly");


/// getMultipleFabricPasscode
/// @param devid           devid
/// @param completionBlock      Called when the task is finished.
- (void)getMultipleFabricPasscodeForceRefreshWithDevid:(NSString *)devid completion:(void(^)(ThingMatterMultipleFabricPasscodeModel *passcodeModel, NSError *error))completionBlock __deprecated_msg("This api is deprecate. Please use `-sendEnhancedCommissioningWithDevid:forceRefresh:ssidInfo:success:failure:` directly");

//- (NSString *)generateQrCodeWithDevid:(NSString *)devid multipleFabricPasscodeModel:(ThingSmartMatterMultipleFabricPasscodeModel*)passcodeModel;

/// generateQrCode
/// @return QrCode
- (NSString *)generateQrCodeWithDevid:(NSString *)devid fabricPasscodeModel:(ThingMatterMultipleFabricPasscodeModel*)passcodeModel __deprecated_msg("This api is deprecate. Please use `-sendEnhancedCommissioningWithDevid:forceRefresh:ssidInfo:success:failure:` directly");

/// open commissing  window 
/// @param devid           devid
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)sendEnhancedCommissioningCommandWithDevid:(NSString *)devid fabricPasscodeModel:(ThingMatterMultipleFabricPasscodeModel *)passcodeModel success:(void(^)(NSString *qrCode,NSString *setupCode))success failure:(ThingFailureError)failure __deprecated_msg("This api is deprecate. Please use `-sendEnhancedCommissioningWithDevid:forceRefresh:ssidInfo:success:failure:` directly");

/// close commissing  window 
/// @param devid           devid
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.

//- (void)revokeCommissioningCommandWithdevid:(NSString *)devid success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;
- (void)revokeCommissioningCommandWithDevid:(NSString *)devid success:(ThingSuccessHandler)success failure:(ThingFailureError)failure __deprecated_msg("This api is deprecate.");

///  Wifi 
/// @param devid           devid
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.

- (void)getWifiDeviceSsidWithDevid:(NSString *)devid success:(ThingSuccessString)success failure:(ThingFailureError)failure;

/// writeAccessControlList 
///
/// @param devId           devId
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)writeAccessControlListWithDevId:(NSString *)devId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// ACL
///
/// @param devId           devId
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)notifyAccessControlListWithDevId:(NSString *)devId success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Read fabric list.  Fabirc 
/// - Parameters:
///   - devId: devId
///   - success:  Called when the task is finished.
///   - failure: Called when the task is interrupted by an error.
- (void)readFabricsWithDevid:(NSString *)devid
                     success:(void(^)(NSArray<ThingMatterMultipleFabricInfoModel *> *fabrics))success
                       failure:(ThingFailureError)failure;


/// Remove Fabric by Fabric index.
/// - Parameters:
///   - devId: devId
///   - faibricIndex: The fabric index.
///   - success: Called when the task is finished.
///   - failure: Called when the task is interrupted by an error.
- (void)removeFabricDevid:(NSString *)devid
                    Index:(NSInteger)fabricIndex
                  success:(ThingSuccessHandler)success
                  failure:(ThingFailureError)failure;

/// Check the device multiple fabric command communicate channels avaliable or not.
- (BOOL)checkPipelineAvailableWithDevid:(NSString *)devid;

/// Open commissing  window. (ECM Command)
/// - Parameters:
///   - devId: devId
///   - forceRefresh: Force refresh the passcode info.
///   - ssidInfo: The Wi-Fi ssid currently connected to the device.
///   - success: Called when the task is finished.
///   - failure: Called when the task is interrupted by an error.
- (void)sendEnhancedCommissioningWithDevid:(NSString *)devid
                              forceRefresh:(BOOL)forceRefresh
                                  ssidInfo:(nullable void(^)(NSString * __nullable ssid))ssidInfo
                                   success:(void(^)(NSString *qrCodeStr, NSString *setupCode))success
                                   failure:(nullable ThingFailureError)failure;

/// Open commissing  window. (ECM Command)
/// - Parameters:
///   - devId: devId
///   - forceRefresh: Force refresh the passcode info.
///   - ssidInfo: The Wi-Fi ssid currently connected to the device.
///   - success: Called when the task is finished.
///   - failure: Called when the task is interrupted by an error.
- (void)sendEnhancedCommissioningMethodWithDevid:(NSString *)devid
                                    forceRefresh:(BOOL)forceRefresh
                                        ssidInfo:(nullable void(^)(NSString * __nullable ssid))ssidInfo
                                         success:(void(^)(NSString *qrCodeStr, NSString *setupCode, long long duration))success
                                         failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingMatterShareInterfaceAPI_h */
