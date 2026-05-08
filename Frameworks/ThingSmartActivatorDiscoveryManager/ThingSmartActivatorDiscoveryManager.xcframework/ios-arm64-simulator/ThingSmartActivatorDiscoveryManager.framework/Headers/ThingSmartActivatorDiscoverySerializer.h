//
//  ThingSmartActivatorDiscoverySerializer.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2021/8/27.
//

#import <Foundation/Foundation.h>
#import "ThingSearchActivatorEnum.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartActivatorDeviceModel;

/// 1. 搜索输入参数处理
/// 2. 搜索结果处理
@protocol ThingSmartActivatorDiscoverySerializer <NSObject>

@optional

/// ==============
///  搜索结果处理
///===============

/// 判断搜索结果是否是需要的设备
/// @param model 搜索结果
- (BOOL)isDeviceModelValid:(ThingSmartActivatorDeviceModel *)model;

/// 搜索结果自定义处理

/// @param model 搜索到的新设备
/// @return 1. 返回处理后的设备 2. 返回 nil，用来去重
- (nullable ThingSmartActivatorDeviceModel *)handleDeviceModel:(ThingSmartActivatorDeviceModel *)model
                                                forDeviceList:(NSArray<ThingSmartActivatorDeviceModel *> *)list;
@end

/// 原始输入输出处理
@interface ThingSmartActivatorDiscoveryRawSerializer : NSObject <ThingSmartActivatorDiscoverySerializer>

+ (instancetype)serializer;

@end
NS_ASSUME_NONNULL_END
