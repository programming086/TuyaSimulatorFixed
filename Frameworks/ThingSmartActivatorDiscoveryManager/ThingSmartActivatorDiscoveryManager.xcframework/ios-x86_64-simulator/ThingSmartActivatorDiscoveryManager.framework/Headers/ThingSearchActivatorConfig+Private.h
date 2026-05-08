//
//  ThingSearchActivatorConfig+Private.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by 尼奥 on 2022/3/11.
//

#import "ThingSearchActivatorConfig.h"
#import "ThingSmartActivatorType.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingASActivatorServiceAction;

@interface ThingSearchActivatorConfig (Private)

/// 根据类别获取行为
/// @param type 搜索、配网的类别
- (ThingASActivatorServiceAction *)actionWithType:(ThingSmartActivatorType)type;

@end

NS_ASSUME_NONNULL_END
