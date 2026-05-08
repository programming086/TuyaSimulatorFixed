//
//  ThingGroupError.h
//  ThingGroupHandleModule
//
//  Created by yuheng on 2021/7/8.
//

#import <ThingGroupManagerKit/ThingGroupManagerKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSErrorDomain const ThingGroupErrorDomain;

@interface ThingGroupError : NSObject

/// 标准错误码转化为mesh类设备错误码
/// @param code 标准错误码
+ (NSInteger)meshCodeWithStandardErrorCode:(ThingGroupErrorType)code;

/// 基于失败回调信息解析页面需要的失败列表
/// @param failureInfo  详见失败回调示例
+ (NSDictionary *)parseFailureDevicesWithFailureInfo:(NSDictionary *)failureInfo;

/// 基于失败回调信息解析error
/// @param failureInfo 详见失败回调示例
+ (NSError *)parseFailureErrorWithFailureInfo:(NSDictionary *)failureInfo;

/// 基于失败回调信息解析groupId
/// @param failureInfo 详见失败回调示例
+ (NSString *)parseGroupIdWithFailureInfo:(NSDictionary *)failureInfo;

@end

NS_ASSUME_NONNULL_END
