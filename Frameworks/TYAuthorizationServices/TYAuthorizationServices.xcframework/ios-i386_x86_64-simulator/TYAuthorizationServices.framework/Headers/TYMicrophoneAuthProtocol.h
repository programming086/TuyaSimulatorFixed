//
//  TYMicrophoneAuthProtocol.h
//  TYModuleServices
//
//  Created by kaier on 2021/12/15.
//

#import <Foundation/Foundation.h>

/** 授权状态
 *  TYMicrophoneAuthorizationStatusUnable：不支持或不可用
 *  TYMicrophoneAuthorizationStatusNotDetermined：用户从未进行过授权等处理，首次访问相应内容会提示用户进行授权
 *  TYMicrophoneAuthorizationStatusRestricted：应用没有相关权限，且当前用户无法改变这个权限，比如:家长控制
 *  TYMicrophoneAuthorizationStatusDenied：用户拒绝
 *  TYMicrophoneAuthorizationStatusAuthorized：已授权
 */
typedef NS_ENUM(NSInteger, TYMicrophoneAuthorizationStatus) {
    TYMicrophoneAuthorizationStatusUnable = -1,
    TYMicrophoneAuthorizationStatusNotDetermined = 0,
    TYMicrophoneAuthorizationStatusRestricted,
    TYMicrophoneAuthorizationStatusDenied,
    TYMicrophoneAuthorizationStatusAuthorized
};

NS_ASSUME_NONNULL_BEGIN

@protocol TYMicrophoneAuthProtocol <NSObject>

/// 单例
+ (instancetype)shared;

/// 检查麦克风权限状态：仅检查权限，不主动请求权限
+ (TYMicrophoneAuthorizationStatus)microphoneAuthorizationStatus;

/// 检查麦克风权限状态：仅检查权限，不主动请求权限
- (TYMicrophoneAuthorizationStatus)microphoneAuthorizationStatus;

/// 请求麦克风权限（触发系统弹窗）
/// @param completionHandler completionHandler
+ (void)requestMicrophoneAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// 请求麦克风权限（触发系统弹窗）
/// @param completionHandler completionHandler
- (void)requestMicrophoneAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// 根据来源请求麦克风权限（触发落地页）
/// @param source 来源
/// @param completionHandler 完成回调
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYMicrophoneAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
