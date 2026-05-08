//
//  TYSecurityArmAbilityDelegate.h
//  TYSecurityArmAbilityBizKit
//
//  Created by Tuya.Inc on 2021/4/13.
//

#import <Foundation/Foundation.h>
#import <TYSecurityArmAbilityModuleServices/TYSecurityArmAbilityEnum.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TYSecurityArmAbilityDelegate <NSObject>

@optional

/// home will alarm after delay time.
///
/// @param delayTime delay time
- (void)homeWillAlarmWithDelayTime:(long long)delayTime;

/// home open alarm
- (void)homeDidAlarm;

/// home calcel alarm
- (void)homeDidCancelAlarm;

/// home enter mode
///
/// @param mode target model
/// @param delayTime delay time
- (void)homeDidEnterModeWithMode:(TYSecurityArmMode)mode
                       delayTime:(long long)delayTime;

/// request failure call back
///
/// @param errorType error type
/// @param errorMessage error message
/// @param error error 
- (void)operationErrorWithErrorType:(TYSecurityArmAbilityErrorCode)errorType
                       errorMessage:(NSString *)errorMessage
                              error:(NSError *)error;

/// alarm voice changed
/// @param onlineType online state
- (void)hasSecurityGatewayOnlineState:(TYSecurityGatewayDeviceOnlineType)onlineType;

/// should update irregular devices
- (void)shouldUpdateIrregularDevices;

/// should update abnormal devices
- (void)shouldUpdateAbnormalDevices;

/// home online state changed
- (void)homeOnlineStateDidChangeWithOnline:(BOOL)online;

/// should update home alarm detail info
- (void)shouldUpdateAlarmDetailInfo;

/// @param open voice open or close
- (void)alarmVoiceDidChangedWithOpen:(BOOL)open;

/// hasArmAbility
/// @param securityGatewayDeviceIds gateway device ids
- (void)hasArmAbility:(NSArray<NSString *> *)securityGatewayDeviceIds;

/// gateway device armed result
/// @param targetMode arm mode
/// @param deviceId gateway device id
/// @param success arm success
/// @param isFirstUpload is first result report
- (void)gatewayDeviceArmedResult:(TYSecurityArmMode)targetMode
                        deviceId:(NSString *)deviceId
                         success:(BOOL)success isFirstUpload:(BOOL)isFirstUpload;

/// update security banner info
/// @param bannerInfo banner info
- (void)shouldUpdateSecurityBannerInfo:(NSArray<NSString *> *)bannerInfo;

@end

NS_ASSUME_NONNULL_END
