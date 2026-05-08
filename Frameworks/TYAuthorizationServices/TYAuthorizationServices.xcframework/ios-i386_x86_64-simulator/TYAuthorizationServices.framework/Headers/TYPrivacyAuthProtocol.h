//
//  TYPrivacyAuthProtocol.h
//  Pods
//
//  Created by kaier on 2022/1/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TYPrivacyAuthProtocol <NSObject>

/// 是否需要触发权限校验落地页
/// @param type 权限类型
/// @param source 权限来源
- (BOOL)isShowPrivacy:(TYPrivacyAuthType)type source:(NSString *)source;

/// 权限标题
/// @param type 权限类型
/// @param source 权限来源
- (NSString *)titleWithType:(TYPrivacyAuthType)type source:(NSString *)source;

/// 权限描述
/// @param type 权限类型
/// @param source 权限来源
- (NSString *)descWithType:(TYPrivacyAuthType)type source:(NSString *)source;

@end

NS_ASSUME_NONNULL_END
