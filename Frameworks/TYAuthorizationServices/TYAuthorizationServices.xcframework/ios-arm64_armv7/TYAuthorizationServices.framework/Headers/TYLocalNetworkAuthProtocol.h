//
//  TYLocalNetworkAuthProtocol.h
//  Masonry
//
//  Created by kaier on 2021/12/15.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, TYLocalNetworkAuthorizationStatus) {
    
    // 用户未作出选择
    // not yet made a choice
    TYLocalNetworkAuthorizationStatusNotDetermined,
    
    // 本地网络没有连接（无线网卡无法获取IP地址）
    // Local network not connected (Wi-Fi adapter can't get IP address)
    TYLocalNetworkAuthorizationStatusNotConnected,
    
    // 用户已经禁止此应用使用“本地网络”权限
    // User has explicitly denied authorization for this application
    TYLocalNetworkAuthorizationStatusDenied,
    
    // 用户已经允许此应用使用“本地网络”权限
    // User has granted authorization to use their local network only while they are using your app.
    TYLocalNetworkAuthorizationStatusAuthorized,
};

NS_ASSUME_NONNULL_BEGIN

@protocol TYLocalNetworkAuthProtocol <NSObject>

/// 单例
+ (instancetype)shared;

+ (TYLocalNetworkAuthorizationStatus)localNetworkAuthorizationStatus;

- (TYLocalNetworkAuthorizationStatus)localNetworkAuthorizationStatus;

/**
    获取“本地网络”的授权状态（beta）
    Returns the current authorization status of the calling application (beta).
 */
+ (void)getLocalNetworkAuthorizationStatusWithCompletionHandler:(void (^)(TYLocalNetworkAuthorizationStatus status))completionHandler;

- (void)getLocalNetworkAuthorizationStatusWithCompletionHandler:(void (^)(TYLocalNetworkAuthorizationStatus status))completionHandler;

/**
    申请“本地网络”授权（beta）
 
    在 Wi-Fi 已连接的前提下，调用此方法会触发“本地网络”的授权弹窗。弹窗只会出现一次，直到 App 卸载重装。
    目前没有办法获取此次触发的状态变更回调。
 
    Request "Local Network" authorization (beta)
 
    When Wi-Fi is connected, calling this method will start the process of requesting "Local Network" authorization from the user. The authorization prompt will only appear once until App uninstalled.
    Currently we can't get authorization change callback for this request.
 */

/// 根据来源请求本地网络权限（触发系统弹窗）
+ (void)requestLocalNetworkAuthorization;

/// 根据来源请求本地网络权限（触发系统弹窗）
- (void)requestLocalNetworkAuthorization;

/// 根据来源请求本地网络权限（触发落地页）
/// @param source 来源
/// @param completionHandler 完成回调
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYLocalNetworkAuthorizationStatus status))completionHandler;


@end

NS_ASSUME_NONNULL_END
