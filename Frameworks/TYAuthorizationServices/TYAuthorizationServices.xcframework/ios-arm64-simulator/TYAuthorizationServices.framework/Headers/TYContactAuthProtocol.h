//
//  TYContactAuthProtocol.h
//  TYAuthorizationServices
//
//  Created by 山鹰 on 2022/2/22.
//

#import <Foundation/Foundation.h>

/** 授权状态
 *  TYContactAuthorizationStatusUnable：不支持或不可用
 *  TYContactAuthorizationStatusNotDetermined：用户从未进行过授权等处理，首次访问通讯录内容会提示用户进行授权
 *  TYContactAuthorizationStatusRestricted：应用没有相关权限，且当前用户无法改变这个权限，比如:家长控制
 *  TYContactAuthorizationStatusDenied：用户拒绝
 *  TYContactAuthorizationStatusAuthorized：已授权
 */
typedef NS_ENUM(NSInteger, TYContactAuthorizationStatus) {
    TYContactAuthorizationStatusUnable = -1,
    TYContactAuthorizationStatusNotDetermined = 0,
    TYContactAuthorizationStatusRestricted,
    TYContactAuthorizationStatusDenied,
    TYContactAuthorizationStatusAuthorized
};

NS_ASSUME_NONNULL_BEGIN

@protocol TYContactAuthProtocol <NSObject>

/// 单例
+ (instancetype)shared;

/// 检查通讯录权限状态：仅检查权限，不主动请求权限
+ (TYContactAuthorizationStatus)contactAuthorizationStatus;

/// 检查通讯录权限状态：仅检查权限，不主动请求权限
- (TYContactAuthorizationStatus)contactAuthorizationStatus;

/// 请求通讯录权限（触发系统弹窗）
/// @param completionHandler completionHandler
+ (void)requestContactAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// 请求通讯录权限（触发系统弹窗）
/// @param completionHandler completionHandler
- (void)requestContactAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// 根据来源请求通讯录权限（触发落地页）
/// @param source 来源
/// @param completionHandler 完成回调
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYContactAuthorizationStatus status))completionHandler;


@end

NS_ASSUME_NONNULL_END
