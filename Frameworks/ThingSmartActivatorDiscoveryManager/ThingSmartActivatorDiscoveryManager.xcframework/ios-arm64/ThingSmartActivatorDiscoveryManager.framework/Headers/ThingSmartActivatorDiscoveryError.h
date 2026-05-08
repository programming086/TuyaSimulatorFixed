//
//  ThingSmartActivatorDiscoveryError.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2022/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSErrorDomain const ThingSmartActivatorDiscoveryErrorDomain;

typedef enum : NSUInteger {
    ThingSmartActivatorDiscoveryErrorCode_Default = 1,
    /// 蓝牙单点/双模扫描的广播包过期
    ThingSmartActivatorDiscoveryErrorCode_BleScanExpired
} ThingSmartActivatorDiscoveryErrorCode;


/// 设备连接路由器失败 ErrorDomain
FOUNDATION_EXPORT NSErrorDomain const ThingSmartActivatorDiscoveryConnectWiFiErrorDomain;

typedef enum : NSUInteger {
    ThingSmartActivatorDiscoveryConnectWiFiErrorCode_Success = 0,
    /// 联网信息错误
    ThingSmartActivatorDiscoveryConnectWiFiErrorCode_ErrorConfigInfo = 1,
    /// 路由器找不到；比如 5GHz Wi-Fi
    ThingSmartActivatorDiscoveryConnectWiFiErrorCode_RouterNotFound = 2,
    /// 路由器密码错误
    ThingSmartActivatorDiscoveryConnectWiFiErrorCode_WrongPassword = 3,
    /// 连接路由器失败
    ThingSmartActivatorDiscoveryConnectWiFiErrorCode_FailedToConnectRouter = 4,
    /// DHCP失败
    ThingSmartActivatorDiscoveryConnectWiFiErrorCode_DHCP = 5
} ThingSmartActivatorDiscoveryConnectWiFiErrorCode;

NS_ASSUME_NONNULL_END
