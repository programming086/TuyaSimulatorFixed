//
//  TYNotificationsAuthProtocol.h
//  Masonry
//
//  Created by kaier on 2021/12/15.
//

#import <Foundation/Foundation.h>


typedef NS_OPTIONS(NSUInteger, TYUNAuthorizationOptions) {
    TYUNAuthorizationOptionBadge   = (1 << 0),
    TYUNAuthorizationOptionSound   = (1 << 1),
    TYUNAuthorizationOptionAlert   = (1 << 2),
    TYUNAuthorizationOptionCarPlay = (1 << 3),
    TYUNAuthorizationOptionCriticalAlert __API_AVAILABLE(ios(12.0)) = (1 << 4),
    TYUNAuthorizationOptionProvidesAppNotificationSettings __API_AVAILABLE(ios(12.0)) = (1 << 5),
    TYUNAuthorizationOptionProvisional __API_AVAILABLE(ios(12.0)) = (1 << 6),
    TYUNAuthorizationOptionAnnouncement __API_AVAILABLE(ios(13.0)) = (1 << 7),
} ;

typedef NS_ENUM(NSInteger, TYUNAuthorizationStatus) {
    TYUNAuthorizationStatusNotDetermined = 0,
    TYUNAuthorizationStatusDenied,
    TYUNAuthorizationStatusAuthorized,
    TYUNAuthorizationStatusProvisional __API_AVAILABLE(ios(12.0)),
    TYUNAuthorizationStatusEphemeral __API_AVAILABLE(ios(14.0))
};

NS_ASSUME_NONNULL_BEGIN

@protocol TYNotificationsAuthProtocol <NSObject>

/// 单例
+ (instancetype)shared;

- (TYUNAuthorizationStatus)notificationAuthorizationStatus;

- (void)requestNotificationAuthorizationWithCompletionHandler:(void (^)(BOOL granted))completionHandler;

- (void)requestNotificationAuthorizationWithOptions:(TYUNAuthorizationOptions)options
                                  completionHandler:(void (^)(BOOL granted))completionHandler;

+ (TYUNAuthorizationStatus)notificationAuthorizationStatus;

/// 根据来源请求通知权限（触发系统弹窗）
/// @param completionHandler 完成回调
+ (void)requestNotificationAuthorizationWithCompletionHandler:(void (^)(BOOL granted))completionHandler;

/// 根据来源请求通知权限（触发系统弹窗）
/// @param options 选项
/// @param completionHandler 完成回调
+ (void)requestNotificationAuthorizationWithOptions:(TYUNAuthorizationOptions)options
                                  completionHandler:(void (^)(BOOL granted))completionHandler;

/// 根据来源请求通知权限（触发落地页）
/// @param source 来源
/// @param completionHandler 完成回调
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYUNAuthorizationStatus status))completionHandler;

/// 根据来源请求通知权限（触发落地页）
/// @param source 来源
/// @param options 选项
/// @param completionHandler 完成回调
- (void)requestAuthorizationWithSource:(NSString *)source
                               options:(TYUNAuthorizationOptions)options
                     completionHandler:(void(^)(TYUNAuthorizationStatus status))completionHandler;


@end

NS_ASSUME_NONNULL_END
