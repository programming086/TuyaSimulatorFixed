//
//  ThingSearchActivatorTypeData.h
//  ThingSearchActivatorModule
//
//  Created by huangjj on 2019/6/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingASActivatorServiceAction;

@interface ThingSearchActivatorConfig : NSObject
/// EZ need
@property (nonatomic, copy) NSString * _Nullable ssid;
/// EZ need
@property (nonatomic, copy) NSString * _Nullable password;
/// zigbee网关id，用于搜索当前网关下的zigbee子设备
@property (nonatomic, copy) NSString *gwDevId;
/// Router/auto/EZ/EZSearch need
@property (nonatomic, copy) NSString *token;
/// 支持闪电配网的设备 作为Server发闪电配网包 为空时默认选择当前家庭下的可用server(路由器优先)
@property (nonatomic, copy) NSArray<NSString *> *pegasusServerDevIDs;
/// 超时时间
@property (nonatomic, assign) NSTimeInterval timeOut;

/// 在发现设备、激活配网前、完成配网后步骤中插入扩展行为
/// @param actions 字典格式 {@(Any ThingSmartActivatorType) : action }
@property (nonatomic, copy) NSMutableDictionary<NSNumber *, ThingASActivatorServiceAction *> *actions;

@end

NS_ASSUME_NONNULL_END
