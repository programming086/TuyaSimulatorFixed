//
//  TuyaSmartACategoryModel.h
//  TYActivatorSktAPI
//
//  Created by qisong on 2022/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class TuyaSmartACategoryLevel1Model, TuyaSmartACategoryLevel2Model, TuyaSmartACategoryLevel3Model, TuyaSmartDeviceCategoryModel;
@interface TuyaSmartACategoryModel : NSObject
@property (nonatomic, copy) NSString *superName; ///< 名称
@property (nonatomic, strong) NSArray<TuyaSmartACategoryLevel1Model *> *level1List; ///< 类目一数组
@property (nonatomic, strong) NSArray<TuyaSmartACategoryLevel2Model *> *defaultLevel2List; ///< 类目一对应的类目二数组
@property (nonatomic, strong) NSArray<TuyaSmartDeviceCategoryModel *> *defaultWglist; ///< 网关模型数组
@end

NS_ASSUME_NONNULL_END
