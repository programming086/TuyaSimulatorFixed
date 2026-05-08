//
//  ThingSearchActivatorDeviceListModel.h
//  ThingSearchActivatorModule
//
//  Created by 龙卷 on 2019/6/17.
//
//[{
//    "type" : "",
//    "title": "",
//    "deviceModels":[model, model]
//}]

#import <Foundation/Foundation.h>
#import "ThingSearchActivatorEnum.h"

NS_ASSUME_NONNULL_BEGIN
@class ThingSmartActivatorDeviceModel;
@interface ThingSearchActivatorDeviceListModel : NSObject <NSCopying>

@property (nonatomic, assign) ThingSearchDeviceModelType type; ///< 设备类型
@property (nonatomic, copy) NSString *title; ///< 组名
@property (nonatomic, strong) NSMutableArray<ThingSmartActivatorDeviceModel *> *deviceModels; ///< 设备模型数组
@property (nonatomic, assign) BOOL canAdd; ///< 该组下是否有被选中的，如果有canAdd=YES

@end

NS_ASSUME_NONNULL_END
