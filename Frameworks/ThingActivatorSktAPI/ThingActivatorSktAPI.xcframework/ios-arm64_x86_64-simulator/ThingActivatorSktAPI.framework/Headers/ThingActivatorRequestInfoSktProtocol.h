//
//  ThingActivatorRequestInfoSktProtocol.h
//  ThingActivatorModule
//
//  Created by qisong on 2022/3/4.
//

#import <Foundation/Foundation.h>
#import "ThingActivatorSktDefine.h"

NS_ASSUME_NONNULL_BEGIN
@class ThingActivatorPrimaryCategoryRequestData, ThingActivatorSecondaryCategoryRequestData, ThingActivatorCategoryDetailRequestData, ThingActivatorProductInfoRequestData, ThingActivatorGatewayLeadListRequestData, ThingActivatorCategoryListRequestData, ThingActivatorUserGuideRequestData, ThingActivatorProductGuideRequestData, ThingActivatorFeedbackInfoRequestData,ThingACTEZUnvailabilityRequestData;

@class ThingSmartACategoryModel,
ThingSmartACategoryLevel2Model,
ThingSmartDeviceCategoryModel,
ThingDeviceConfigInfo,
ThingCommonLeadModel,
ThingSmartAProductGuideData,
ThingActivatorFeedbackInfoData,
ThingACTEZUnvailabilityResponseData,
ThingACTLinkmodeUrlResponseData;

/// @discussion 配网页面相关信息的协议
@protocol ThingActivatorRequestInfoSktProtocol <NSObject>

/*
 * 请求一级品类列表
 */
- (void)requestPrimaryCategoryWithParam:(ThingActivatorPrimaryCategoryRequestData *)param success:(void(^)(ThingSmartACategoryModel *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 请求一级品类对应的二级品类列表
 */
- (void)requestSecondaryCategoryWithParam:(ThingActivatorSecondaryCategoryRequestData *)param success:(void(^)( NSArray <ThingSmartACategoryLevel2Model *>*result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 请求三级品类引导详情
 */
- (void)requestCategoryDetailWithParam:(ThingActivatorCategoryDetailRequestData *)param success:(void(^)(ThingSmartDeviceCategoryModel *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 请求产品信息
 */
- (void)requestProductInfoWithParam:(ThingActivatorProductInfoRequestData *)param success:(void(^)(ThingDeviceConfigInfo *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 请求网关配置引导列表
 */
- (void)requestGatewayLeadListWithParam:(ThingActivatorGatewayLeadListRequestData *)param success:(void(^)(NSArray<ThingSmartDeviceCategoryModel *> *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 请求三级品类引导列表，根据pid或者网关id
 */
- (void)requestCategoryListWithParam:(ThingActivatorCategoryListRequestData *)param success:(void(^)(NSArray<ThingSmartDeviceCategoryModel *> *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 请求配网新人引导
 */
- (void)requestUserGuideWithParam:(ThingActivatorUserGuideRequestData *)param success:(void(^)(ThingCommonLeadModel *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 请求产品引导信息
 */
- (void)requestProductGuideWithParam:(ThingActivatorProductGuideRequestData *)param success:(void(^)(ThingSmartAProductGuideData *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 请求失败反馈信息
 */
- (void)requestFeedbackInfoWithParam:(ThingActivatorFeedbackInfoRequestData *)param success:(void(^)(ThingActivatorFeedbackInfoData *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 请求EZ不可用版本信息
 */
- (void)requestEZUnvailabilityInfoWithParam:(ThingACTEZUnvailabilityRequestData *)param success:(void(^)(ThingACTEZUnvailabilityResponseData *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 根据产品信息获取对应小程序配网连接
 */
- (void)requestAppletsUrlWithParam:(ThingActivatorCategoryDetailRequestData *)param success:(void(^)(NSArray<ThingACTLinkmodeUrlResponseData *>*))success
                           failure:(ThingActivatorCallbackError _Nullable)failure;

@end


NS_ASSUME_NONNULL_END
