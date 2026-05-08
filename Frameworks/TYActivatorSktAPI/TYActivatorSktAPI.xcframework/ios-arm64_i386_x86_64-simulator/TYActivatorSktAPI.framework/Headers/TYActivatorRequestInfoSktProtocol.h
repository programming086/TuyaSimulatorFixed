//
//  TYActivatorRequestInfoSktProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class TYActivatorPrimaryCategoryRequestData, TYActivatorSecondaryCategoryRequestData, TYActivatorCategoryDetailRequestData, TYActivatorProductInfoRequestData, TYActivatorGatewayLeadListRequestData, TYActivatorCategoryListRequestData, TYActivatorUserGuideRequestData, TYActivatorProductGuideRequestData, TYActivatorFeedbackInfoRequestData;

@class TuyaSmartACategoryModel,
TuyaSmartACategoryLevel2Model,
TuyaSmartDeviceCategoryModel,
TYDeviceConfigInfo,
TYCommonLeadModel,
TuyaSmartAProductGuideData,
TYActivatorFeedbackInfoData;

/// @discussion 配网页面相关信息的协议
@protocol TYActivatorRequestInfoSktProtocol <NSObject>

/*
 * 请求一级类目
 */
- (void)requestPrimaryCategoryWithParam:(TYActivatorPrimaryCategoryRequestData *)param success:(void(^)(TuyaSmartACategoryModel *result))success failure:(void(^)(NSError *error))failure;

/*
 * 请求二级类目
 */
- (void)requestSecondaryCategoryWithParam:(TYActivatorSecondaryCategoryRequestData *)param success:(void(^)( NSArray <TuyaSmartACategoryLevel2Model *>*result))success failure:(void(^)(NSError *error))failure;

/*
 * 请求三级类目引导详情
 */
- (void)requestCategoryDetailWithParam:(TYActivatorCategoryDetailRequestData *)param success:(void(^)(TuyaSmartDeviceCategoryModel *result))success failure:(void(^)(NSError *error))failure;

/*
 * 获取产品信息
 */
- (void)requestProductInfoWithParam:(TYActivatorProductInfoRequestData *)param success:(void(^)(TYDeviceConfigInfo *result))success failure:(void(^)(NSError *error))failure;

/*
 * 获取网关配置引导列表
 */
- (void)requestGatewayLeadListWithParam:(TYActivatorGatewayLeadListRequestData *)param success:(void(^)(NSArray<TuyaSmartDeviceCategoryModel *> *result))success failure:(void(^)(NSError *error))failure;

/*
 * 根据pid或者网关id获取三级类目引导列表
 */
- (void)requestCategoryListWithParam:(TYActivatorCategoryListRequestData *)param success:(void(^)(NSArray<TuyaSmartDeviceCategoryModel *> *result))success failure:(void(^)(NSError *error))failure;

/*
 * 获取配网新人引导
 */
- (void)requestUserGuideWithParam:(TYActivatorUserGuideRequestData *)param success:(void(^)(TYCommonLeadModel *result))success failure:(void(^)(NSError *error))failure;

/*
 * 获取产品引导信息
 */
- (void)requestProductGuideWithParam:(TYActivatorProductGuideRequestData *)param success:(void(^)(TuyaSmartAProductGuideData *result))success failure:(void(^)(NSError *error))failure;

/*
 * 获取失败反馈信息
 */
- (void)requestFeedbackInfoWithParam:(TYActivatorFeedbackInfoRequestData *)param success:(void(^)(TYActivatorFeedbackInfoData *result))success failure:(void(^)(NSError *error))failure;
@end


NS_ASSUME_NONNULL_END
