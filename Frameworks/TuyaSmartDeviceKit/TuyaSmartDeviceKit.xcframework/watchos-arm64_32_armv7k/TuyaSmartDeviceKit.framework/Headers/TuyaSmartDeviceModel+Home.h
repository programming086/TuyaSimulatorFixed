//
//  TuyaSmartDeviceModel+Home.h
//  TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartDeviceModel (Home)

@property (nonatomic, assign) long long homeId;
@property (nonatomic, assign) long long roomId;

@property (nonatomic, assign) NSInteger displayOrder;
@property (nonatomic, assign) NSInteger homeDisplayOrder;

/// 是否是本地直连设备
@property (nonatomic, assign, readonly) BOOL isLocalDevice;

/// 本地直连设备 Wi-Fi 名
@property (nonatomic, copy, readonly) NSString *ssidName;

- (BOOL)isAssociateWithBluetooth;

- (void)addToHome:(long long)homeId;


/// 更新本地设备的时区（配网用，如有缓存，直接调用成功回调）
/// @param devId 设备 ID
/// @param success 更新成功，如果有缓存，直接成功
/// @param failure 更新失败，云端接口失败
- (void)updateLocalDeviceConfigWithDevId:(NSString *)devId
                                success:(TYSuccessDict)success
                                failure:(TYFailureError)failure;
@end

NS_ASSUME_NONNULL_END
