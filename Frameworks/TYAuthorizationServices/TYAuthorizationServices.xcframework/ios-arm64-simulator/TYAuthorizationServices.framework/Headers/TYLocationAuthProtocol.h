//
//  TYLocationAuthProtocol.h
//  Masonry
//
//  Created by kaier on 2021/12/15.
//

#import <Foundation/Foundation.h>

/** 定位授权状态
 *
 *  TYLocationAuthorizationStatusUnable：不支持或不可用
 *  TYLocationAuthorizationStatusNotDetermined：用户从未进行过授权等处理，首次访问相应内容会提示用户进行授权
 *  TYLocationAuthorizationStatusRestricted：应用没有相关权限，且当前用户无法改变这个权限，比如:家长控制
 *  TYLocationAuthorizationStatusDenied：用户拒绝
 *  TYLocationAuthorizationStatusAuthorizedAlways：一直允许获取定位
 *  TYLocationAuthorizationStatusAuthorizedWhenInUse：在使用时允许定位
*/
typedef NS_ENUM(NSInteger, TYLocationAuthorizationStatus) {
    TYLocationAuthorizationStatusUnable = -1,
    TYLocationAuthorizationStatusNotDetermined = 0,
    TYLocationAuthorizationStatusRestricted,
    TYLocationAuthorizationStatusDenied,
    TYLocationAuthorizationStatusAuthorizedAlways,
    TYLocationAuthorizationStatusAuthorizedWhenInUse,
};

NS_ASSUME_NONNULL_BEGIN

@protocol TYLocationAuthProtocol <NSObject>

/// 单例
+ (instancetype)shared;

/// 定位状态是否可用
+ (BOOL)available;

/// 检查定位权限状态：仅检查权限，不主动请求权限
+ (TYLocationAuthorizationStatus)locationAuthorizationStatus;

/// 检查定位权限状态：仅检查权限，不主动请求权限
- (TYLocationAuthorizationStatus)locationAuthorizationStatus;

/// 请求定位权限（触发系统弹窗）
/// @param completionHandler completionHandler
+ (void)requestLocationAuthorizationWithCompletionHandler:(void(^)(TYLocationAuthorizationStatus status))completionHandler;

/// 请求定位权限（触发系统弹窗）
/// @param completionHandler completionHandler
- (void)requestLocationAuthorizationWithCompletionHandler:(void(^)(TYLocationAuthorizationStatus status))completionHandler;

/// 根据来源请求定位权限（触发落地页）
/// @param source 来源
/// @param completionHandler 完成回调
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYLocationAuthorizationStatus status))completionHandler;



@end

NS_ASSUME_NONNULL_END
