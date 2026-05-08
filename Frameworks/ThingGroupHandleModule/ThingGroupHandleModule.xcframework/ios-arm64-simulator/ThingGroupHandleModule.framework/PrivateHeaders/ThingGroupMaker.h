//
//  ThingGroupMaker.h
//  ThingGroupHandleModule
//
//  Created by yuheng on 2021/7/2.
//

#import "ThingGroupUtil.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupMaker : NSObject
/// 非遥控器群组生成页面实例
+ (UIViewController *)groupVCMakerWithBuildQuery:(NSDictionary *)params;
/// 遥控器调用此方法生成页面实例
+ (UIViewController *)remoteControlGroupVCMakerWithBuildQuery:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
