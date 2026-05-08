//
//  ThingSmartActivatorErrorModel.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2021/9/24.
//

#import <Foundation/Foundation.h>
#import "ThingSearchActivatorEnum.h"
#import "ThingSmartActivatorType.h"

NS_ASSUME_NONNULL_BEGIN

/// 【发现】错误模型
/// 发生错误时，ThingSmartActivatorDeviceModel 可能没有 uniqueId，所以需要额外的错误模型
@interface ThingSmartActivatorErrorModel : NSObject

@property (nonatomic, assign) ThingSearchDeviceModelType deviceModelType;
@property (nonatomic, assign) ThingSmartActivatorType activatorType;
@property (nonatomic) NSError *error;

@property (nonatomic, copy, nullable) NSDictionary *userInfo;

@end

NS_ASSUME_NONNULL_END
