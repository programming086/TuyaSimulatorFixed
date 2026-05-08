//
//  TYPrivacyAuthCheckProtocol.h
//  Pods
//
//  Created by kaier on 2022/1/4.
//

#import <Foundation/Foundation.h>
#import "TYPrivacyAuthConfig.h"

@protocol TYPrivacyAuthCheckProtocol <NSObject>

/// 单例
+ (instancetype)shared;

/// 权限请求降级方案，通过配置中心字段控制 https://wiki.tuya-inc.com:7799/page/1466253746303418386
@property (atomic, copy) BOOL(^isRestorePermissionRequestAction)(void);

/// 隐私权限校验
/// @param config 权限配置
/// @param completionBlock 校验完成回调（可能会触发多次）
- (void)checkWithAuthConfig:(TYPrivacyAuthConfig *)config
            completionBlock:(TYPrivacyAuthCheckCompletionBlock)completionBlock;

- (void)dismiss;

@end
