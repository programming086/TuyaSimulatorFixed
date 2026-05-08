//
//  TYHomeKitAuthProtocol.h
//  Masonry
//
//  Created by kaier on 2021/12/15.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, TYHMHomeManagerAuthorizationStatus) {
    TYHMHomeManagerAuthorizationStatusNotDetermined,
    TYHMHomeManagerAuthorizationStatusDenied,
    TYHMHomeManagerAuthorizationStatusAuthorized,
} ;

/// granted:bool
/// manager:HMHomeManager
typedef void(^TYHomeAccessCompletionHandler)(BOOL granted);

NS_ASSUME_NONNULL_BEGIN

@protocol TYHomeKitAuthProtocol <NSObject>

/// 单例
+ (instancetype)shared;

+ (void)getHomeAuthorizationStatusWithCompletionHandler:(void(^)(TYHMHomeManagerAuthorizationStatus status))completionHandler;

- (void)getHomeAuthorizationStatusWithCompletionHandler:(void(^)(TYHMHomeManagerAuthorizationStatus status))completionHandler;

+ (TYHMHomeManagerAuthorizationStatus)homeManagerAuthorizationStatus;

- (TYHMHomeManagerAuthorizationStatus)homeManagerAuthorizationStatus;

/// 请求家庭权限（触发系统弹窗）
/// @param completionHandler completionHandler
+ (void)requestHomeAccessWithCompletionHandler:(TYHomeAccessCompletionHandler)completionHandler;

/// 请求家庭权限（触发系统弹窗）
/// @param completionHandler completionHandler
- (void)requestHomeAccessWithCompletionHandler:(TYHomeAccessCompletionHandler)completionHandler;

/// 根据来源请求家庭数据权限（触发落地页）
/// @param source 来源
/// @param completionHandler 完成回调
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYHMHomeManagerAuthorizationStatus status))completionHandler;


@end

NS_ASSUME_NONNULL_END
