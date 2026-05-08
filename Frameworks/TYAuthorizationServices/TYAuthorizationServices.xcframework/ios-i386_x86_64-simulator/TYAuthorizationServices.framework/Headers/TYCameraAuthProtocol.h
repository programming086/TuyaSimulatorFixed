//
//  TYCameraAuthProtocol.h
//  TYModuleServices
//
//  Created by kaier on 2021/12/15.
//

#import <Foundation/Foundation.h>

/** 授权状态
 *  TYCameraAuthorizationStatusUnable：不支持或不可用
 *  TYCameraAuthorizationStatusNotDetermined：用户从未进行过授权等处理，首次访问相应内容会提示用户进行授权
 *  TYCameraAuthorizationStatusRestricted：应用没有相关权限，且当前用户无法改变这个权限，比如:家长控制
 *  TYCameraAuthorizationStatusDenied：用户拒绝
 *  TYCameraAuthorizationStatusAuthorized：已授权
 */
typedef NS_ENUM(NSInteger, TYCameraAuthorizationStatus) {
    TYCameraAuthorizationStatusUnable = -1,
    TYCameraAuthorizationStatusNotDetermined = 0,
    TYCameraAuthorizationStatusRestricted,
    TYCameraAuthorizationStatusDenied,
    TYCameraAuthorizationStatusAuthorized
};

NS_ASSUME_NONNULL_BEGIN

@protocol TYCameraAuthProtocol <NSObject>

/// 单例
+ (instancetype)shared;

/// 检查相机权限状态：仅检查权限，不主动请求权限
+ (TYCameraAuthorizationStatus)cameraAuthorizationStatus;

/// 检查相机权限状态：仅检查权限，不主动请求权限
- (TYCameraAuthorizationStatus)cameraAuthorizationStatus;

/// 请求相机权限（触发系统弹窗）
/// @param completionHandler completionHandler
+ (void)requestCameraAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// 请求相机权限（触发系统弹窗）
/// @param completionHandler completionHandler
- (void)requestCameraAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// 根据来源请求相机权限（触发落地页）
/// @param source 来源
/// @param completionHandler 完成回调
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYCameraAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
