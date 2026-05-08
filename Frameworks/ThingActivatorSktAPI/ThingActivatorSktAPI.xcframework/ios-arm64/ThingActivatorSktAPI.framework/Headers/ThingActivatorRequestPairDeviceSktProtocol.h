//
//  ThingActivatorRequestPairDeviceSktProtocol.h
//  ThingActivatorModule
//
//  Created by qisong on 2022/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ThingActivatorParseQRCodeRequestData, ThingActivatorResetDeviceRequestData, ThingActivatorDeviceBindRequestData, ThingActivatorNBDeviceBindRequestData, ThingActivatorVirtualDeviceBindRequestData, ThingActivatorThingLinkDeviceBindRequestData, ThingActivatorSubDeviceGWRequestData;

@class ThingSmartAScanCodeModel, ThingActivatorResetDeviceResponseData, ThingActivatorDeviceBindResponseData, ThingActivatorNBDeviceBindResponseData, ThingActivatorVirtualDeviceBindResponseData, ThingActivatorThingLinkDeviceBindResponseData, ThingActivatorSubDeviceGWResponseData;

/// @discussion 设备配网相关接口的协议
@protocol ThingActivatorRequestPairDeviceSktProtocol <NSObject>
/*
 * 解析二维码
 */
- (void)requestParseQRCodeWithParam:(ThingActivatorParseQRCodeRequestData *)param success:(void(^)(ThingSmartAScanCodeModel *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 重置设备
 */
- (void)requestResetDeviceWithParam:(ThingActivatorResetDeviceRequestData *)param success:(void(^)(ThingActivatorResetDeviceResponseData *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 红外、gprs设备绑定
 */
- (void)requestDeviceBindWithParam:(ThingActivatorDeviceBindRequestData *)param success:(void(^)(ThingActivatorDeviceBindResponseData *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * NB设备绑定
 */
- (void)requestNBDeviceBindWithParam:(ThingActivatorNBDeviceBindRequestData *)param success:(void(^)(ThingActivatorNBDeviceBindResponseData *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * 添加虚拟设备
 */
- (void)requestVirtualDeviceBindWithParam:(ThingActivatorVirtualDeviceBindRequestData *)param success:(void(^)(ThingActivatorVirtualDeviceBindResponseData *result))success failure:(ThingActivatorCallbackError)failure;

/*
 * ThingLink设备绑定
 */
- (void)requestThingLinkDeviceBindWithParam:(ThingActivatorThingLinkDeviceBindRequestData *)param success:(void(^)(ThingActivatorThingLinkDeviceBindResponseData *result))success failure:(ThingActivatorCallbackError)failure;

/// 获取子设备配网的网关
- (void)requestSubDeviceGatewayWithParam:(ThingActivatorSubDeviceGWRequestData *)param
                                 success:(void(^)(ThingActivatorSubDeviceGWResponseData *result))success
                                 failure:(ThingActivatorCallbackError)failure;

@end

NS_ASSUME_NONNULL_END
