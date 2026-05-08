//
//  TYActivatorRequestPairDeviceSktProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class TYActivatorParseQRCodeRequestData, TYActivatorResetDeviceRequestData, TYActivatorDeviceBindRequestData, TYActivatorNBDeviceBindRequestData, TYActivatorVirtualDeviceBindRequestData, TYActivatorTuyaLinkDeviceBindRequestData;

@class TuyaSmartAScanCodeModel, TYActivatorResetDeviceResponseData, TYActivatorDeviceBindResponseData, TYActivatorNBDeviceBindResponseData, TYActivatorVirtualDeviceBindResponseData, TYActivatorTuyaLinkDeviceBindResponseData;

/// @discussion 设备配网相关接口的协议
@protocol TYActivatorRequestPairDeviceSktProtocol <NSObject>
/*
 * 解析二维码
 */
- (void)requestParseQRCodeWithParam:(TYActivatorParseQRCodeRequestData *)param success:(void(^)(TuyaSmartAScanCodeModel *result))success failure:(void(^)(NSError *error))failure;

/*
 * 重置设备
 */
- (void)requestResetDeviceWithParam:(TYActivatorResetDeviceRequestData *)param success:(void(^)(TYActivatorResetDeviceResponseData *result))success failure:(void(^)(NSError *error))failure;

/*
 * 红外、gprs设备绑定
 */
- (void)requestDeviceBindWithParam:(TYActivatorDeviceBindRequestData *)param success:(void(^)(TYActivatorDeviceBindResponseData *result))success failure:(void(^)(NSError *error))failure;

/*
 * NB设备绑定
 */
- (void)requestNBDeviceBindWithParam:(TYActivatorNBDeviceBindRequestData *)param success:(void(^)(TYActivatorNBDeviceBindResponseData *result))success failure:(void(^)(NSError *error))failure;

/*
 * 添加虚拟设备
 */
- (void)requestVirtualDeviceBindWithParam:(TYActivatorVirtualDeviceBindRequestData *)param success:(void(^)(TYActivatorVirtualDeviceBindResponseData *result))success failure:(void(^)(NSError *error))failure;

/*
 * TuyaLink设备绑定
 */
- (void)requestTuyaLinkDeviceBindWithParam:(TYActivatorTuyaLinkDeviceBindRequestData *)param success:(void(^)(TYActivatorTuyaLinkDeviceBindResponseData *result))success failure:(void(^)(NSError *error))failure;
@end

NS_ASSUME_NONNULL_END
