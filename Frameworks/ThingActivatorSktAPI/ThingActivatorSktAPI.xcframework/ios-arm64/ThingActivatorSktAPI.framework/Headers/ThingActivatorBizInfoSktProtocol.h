//
//  ThingActivatorCategorySktProtocol.h
//  ThingActivatorSktAPI
//
//  Created by qisong on 2022/4/15.
//

#import <Foundation/Foundation.h>
#import "ThingActivatorSktDefine.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ThingActivatorCategoryModelsBlock)(NSArray<ThingSmartDeviceCategoryModel*> * gwModels);

typedef void (^ThingActivatorCategoryModelBlock)(ThingSmartDeviceCategoryModel * _Nullable model);

@class ThingSmartACategoryLevel1Model,ThingACTLinkmodeUrlResponseData;

@protocol ThingActivatorBizInfoSktProtocol<NSObject>
/*
 * 从云端获取一级品类列表
 */
- (void)getPrimaryCategoryWithParam:(nullable ThingActivatorPrimaryCategoryRequestData *)param
                            success:(void(^)(ThingSmartACategoryModel *model))success
                            failure:(ThingActivatorCallbackError _Nullable)failure;

/*
 * 从云端获取一级品类对应的二级品类列表
 */
- (void)getSecondaryCategoryWithParam:(ThingActivatorSecondaryCategoryRequestData *)param
                              success:(void(^)( NSArray <ThingSmartACategoryLevel2Model *>*level2Models))success
                              failure:(ThingActivatorCallbackError _Nullable)failure;
/*
 * 从云端获取三级品类详情
 */
- (void)getCategoryDetailWithParam:(ThingActivatorCategoryDetailRequestData *)param
                           success:(void(^)(ThingSmartDeviceCategoryModel *categoryModel))success
                           failure:(ThingActivatorCallbackError _Nullable)failure;

/*
 * 从缓存获取一级品类列表
 */
- (void)getPrimaryCategoryFromDisk:(void(^)(NSArray<ThingSmartACategoryLevel1Model *> *level1Models))success;

/*
 * 从缓存获取一级品类对应的二级品类列表
 */
- (void)getSecondaryCategoryFromDiskWithLevelOneCode:(NSString *)levelOneCode
                                             success:(void(^)( NSArray <ThingSmartACategoryLevel2Model *>*level2Models))success;
/*
 * 从缓存获取三级品类详情
 */
- (void)getCategoryDetailFromDiskWithBizValue:(NSString *)bizValue
                                      success:(void(^)(ThingSmartDeviceCategoryModel *categoryModel))success;

/*
 * 从云端获取网关配置引导列表
 */
- (void)getGatewayLeadListWithParam:(nullable ThingActivatorGatewayLeadListRequestData *)param
                            success:(ThingActivatorCategoryModelsBlock)success
                            failure:(ThingActivatorCallbackError _Nullable)failure;

/*
 * 从缓存获取网关配置引导列表
 */
- (void)getGatewayModelsFromDisk:(ThingActivatorCategoryModelsBlock)success;

/*
 * 从缓存获取无线网关引导模型
 */
- (void)getWirelessGWModelFromDisk:(ThingActivatorCategoryModelBlock)success;

/*
 * 从缓存获取有线网关引导模型
 */
- (void)getCableGWModelFromDisk:(ThingActivatorCategoryModelBlock)success;

/*
 * 从缓存获取无线and有线网关引导模型
 */
- (void)getWirelessAndCableGWModelFromDisk:(void(^)(ThingSmartDeviceCategoryModel *wirelessModel, ThingSmartDeviceCategoryModel *cableModel))success;

/*
 * 缓存网关引导模型
 */
- (void)saveGatewayModelsInDisk:(NSArray <ThingSmartDeviceCategoryModel *>*)gatewayModelList;

/*
 * 清除所有接口缓存
 */
- (void)clearCache;

/*
 * 获取 LinkMode 对应小程序连接
 */
- (void)getAppletsUrlWithSecondaryCategory:(ThingActivatorCategoryDetailRequestData *)param
                                   success:(void(^)(NSArray<ThingACTLinkmodeUrlResponseData *>*list))success
                                   failure:(ThingActivatorCallbackError _Nullable)failure;
@end

NS_ASSUME_NONNULL_END
