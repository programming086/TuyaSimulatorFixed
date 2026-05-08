//
//  TuyaSmartActivatorService.h
//  TuyaSmartActivatorExtraBizBundle
//
//  Created by Hemin Won on 2021/5/7.
//

#import <Foundation/Foundation.h>
#import <TYActivatorSktAPI/TYActivatorSktAPI.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartActivatorService : NSObject

/// 获取配网列表一级品类数据
/// @param success 成功回调
/// @param failure 失败回调
- (void)requestLevelOneListWithSuccess:(void(^)(TuyaSmartACategoryModel * _Nullable model))success
                               failure:(void(^)(NSError *error))failure;

/// 获取配网列表二级品类数据
/// @param levelOneCode 一级类目Code值
/// @param type 一级类目type类型
/// @param success 成功回调
/// @param failure 失败回调
- (void)requestLevelSecondListWithLevelOneCode:(NSString *)levelOneCode
                                          type:(NSString *)type
                                       success:(void(^)(NSArray<TuyaSmartACategoryLevel2Model *> * _Nullable modelList))success
                                       failure:(void(^)(NSError *error))failure;

/// 获取配网列表三级品类详情数据
/// @param PID 产品ID
/// @param category 品类
/// @param success 成功回调
/// @param failure 失败回调
- (void)requestCategoryDetailWithPID:(NSString * _Nullable)PID
                            category:(NSString * _Nullable)category
                             success:(void(^)(TuyaSmartDeviceCategoryModel * _Nullable model))success
                             failure:(void(^)(NSError *error))failure;
@end

NS_ASSUME_NONNULL_END
