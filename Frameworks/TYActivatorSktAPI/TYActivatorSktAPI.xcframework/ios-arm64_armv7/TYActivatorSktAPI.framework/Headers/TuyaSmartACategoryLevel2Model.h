//
//  TuyaSmartACategoryLevel2Model.h
//  TYActivatorSktAPI
//
//  Created by qisong on 2022/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class TuyaSmartACategoryLevel3Model;
@interface TuyaSmartACategoryLevel2Model : NSObject
@property (nonatomic, copy) NSString *name; ///< 父类名称
@property (nonatomic, copy) NSString *tagCode; ///< 父类code
@property (nonatomic, strong) NSArray<TuyaSmartACategoryLevel3Model *> *level3Items; ///< 类目3数组
@end

NS_ASSUME_NONNULL_END
