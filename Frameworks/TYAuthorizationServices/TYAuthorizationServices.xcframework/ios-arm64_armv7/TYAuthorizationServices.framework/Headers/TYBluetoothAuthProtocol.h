//
//  TYBluetoothAuthProtocol.h
//  Masonry
//
//  Created by kaier on 2021/12/15.
//

#import <Foundation/Foundation.h>

/** 蓝牙权限状态
 *
 *  TYCBAuthorizationStateUnknown：未知状态
 *  TYCBAuthorizationStateResetting：正在重置，与系统服务暂时丢失
 *  TYCBAuthorizationStateUnsupported：不支持蓝牙
 *  TYCBAuthorizationStateUnauthorized：未授权
 *  TYCBAuthorizationStatePoweredOff：关闭
 *  TYCBAuthorizationStatePoweredOn：开启并可用
 */
typedef NS_ENUM(NSInteger, TYCBAuthorizationState) {
    TYCBAuthorizationStateUnknown = 0,
    TYCBAuthorizationStateResetting,
    TYCBAuthorizationStateUnsupported,
    TYCBAuthorizationStateUnauthorized,
    TYCBAuthorizationStatePoweredOff,
    TYCBAuthorizationStatePoweredOn
};

typedef NS_ENUM(NSInteger, TYCBAuthorizationStatus) {
    TYCBAuthorizationStatusUnable = -1,
    TYCBAuthorizationStatusNotDetermined = 0,
    TYCBAuthorizationStatusRestricted,
    TYCBAuthorizationStatusDenied,
    TYCBAuthorizationStatusAllowedAlways
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^TYBLEPowerStateChangedBlock)(TYCBAuthorizationState state);

@protocol TYBluetoothAuthProtocol <NSObject>

/// 单例
+ (instancetype)shared;

/// 获取系统蓝牙开关状态
///
/// 此状态不稳定，只存储了一份系统状态，
/// 准确的状态获取应该通过 addObserver:bleStateChanged: 方法
///
/// 注意：当 APP 蓝牙权限状态为 AllowedAlways 时，此状态才可能返回 PoweredOff 或 PoweredOn;
/// APP 蓝牙权限状态为 NotDetermined 或 Denied 时，此状态返回 Unauthorized；
/// 注意使用 单例 调用
- (TYCBAuthorizationState)systemPowerStatus;

/// 获取系统蓝牙开关状态
+ (TYCBAuthorizationState)systemPowerStatus;

/// 获取 APP 蓝牙权限状态
/// 注意使用 单例 调用
- (TYCBAuthorizationStatus)authorizationState;

/// 获取 APP 蓝牙权限状态
+ (TYCBAuthorizationStatus)authorizationState;

/// 是否启用以 UI 弹窗进行权限说明的能力
/// 注意使用 单例 调用
- (void)setEnableUI;

/// 是否启用以 UI 弹窗进行权限说明的能力
+ (void)setEnableUI;

/// 请求蓝牙权限（触发系统弹窗）
/// 注意使用 单例 调用
- (void)requestBluetoothAuthorizationWithCompletionHandler:(void(^)(TYCBAuthorizationState state))completionHandler;

/// 请求蓝牙权限（触发系统弹窗）
+ (void)requestBluetoothAuthorizationWithCompletionHandler:(void(^)(TYCBAuthorizationState state))completionHandler;

/// 根据来源请求蓝牙权限（触发落地页）
///
/// 注意使用 单例 调用
/// @param source 来源
/// @param completionHandler 完成回调
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYCBAuthorizationState state, TYCBAuthorizationStatus status))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYCBAuthorizationState state, TYCBAuthorizationStatus status))completionHandler;

/// 注意使用 单例 调用
- (void)addObserver:(id)observer bleStateChanged:(TYBLEPowerStateChangedBlock)callback;
+ (void)addObserver:(id)observer bleStateChanged:(TYBLEPowerStateChangedBlock)callback;

#pragma mark - deprecated

/// 检查蓝牙权限
- (TYCBAuthorizationState)bluetoothAuthorizationState; __deprecated_msg("This method is deprecated, Use systemPowerStatus: instead");

/// 检查蓝牙权限
+ (TYCBAuthorizationState)bluetoothAuthorizationState; __deprecated_msg("This method is deprecated, Use systemPowerStatus: instead");

/// 检查蓝牙权限
- (TYCBAuthorizationStatus)bluetoothAuthorizationStatus; __deprecated_msg("This method is deprecated, Use authorizationState: instead");

/// 检查蓝牙权限
+ (TYCBAuthorizationStatus)bluetoothAuthorizationStatus; __deprecated_msg("This method is deprecated, Use authorizationState: instead");

/// 获取蓝牙权限
/// @param completionHandler completionHandler
- (void)getBluetoothAuthorizationStatusWithCompletionHandler:(void(^)(TYCBAuthorizationStatus status))completionHandler; __deprecated_msg("This method is deprecated, Use authorizationState: instead");

/// 获取蓝牙权限
/// @param completionHandler completionHandler
+ (void)getBluetoothAuthorizationStatusWithCompletionHandler:(void(^)(TYCBAuthorizationStatus status))completionHandler; __deprecated_msg("This method is deprecated, Use authorizationState: instead");

/// 获取蓝牙权限
/// @param completionHandler completionHandler
- (void)getBluetoothAuthorizationStateWithCompletionHandler:(void(^)(TYCBAuthorizationState state))completionHandler; __deprecated_msg("This method is deprecated, Use systemPowerStatus: instead");

/// 获取蓝牙权限
/// @param completionHandler completionHandler
+ (void)getBluetoothAuthorizationStateWithCompletionHandler:(void(^)(TYCBAuthorizationState state))completionHandler; __deprecated_msg("This method is deprecated, Use systemPowerStatus: instead");

@end

NS_ASSUME_NONNULL_END
