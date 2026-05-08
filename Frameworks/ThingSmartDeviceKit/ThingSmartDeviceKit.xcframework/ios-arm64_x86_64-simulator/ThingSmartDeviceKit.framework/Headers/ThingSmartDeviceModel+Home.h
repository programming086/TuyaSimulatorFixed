//
//  ThingSmartDeviceModel+Home.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDeviceModel (Home)

@property (nonatomic, assign) long long homeId;
@property (nonatomic, assign) long long roomId;

@property (nonatomic, assign) NSInteger displayOrder;
@property (nonatomic, assign) NSInteger homeDisplayOrder;

/// 是否是本地直连设备
@property (nonatomic, assign, readonly) BOOL isLocalDevice;

/// 本地直连设备 Wi-Fi 名
@property (nonatomic, copy, readonly) NSString *ssidName;

/// 根据DeviceID获取当前的DeviceModel
/// - Parameter deviceID: DeviceID String类型
+ (ThingSmartDeviceModel *)deviceModelWithDeviceID:(NSString *)deviceID;

- (BOOL)isAssociateWithBluetooth;

- (void)addToHome:(long long)homeId;


/// 更新本地设备的时区（配网用，如有缓存，直接调用成功回调）
/// @param devId 设备 ID
/// @param success 更新成功，如果有缓存，直接成功
/// @param failure 更新失败，云端接口失败
- (void)updateLocalDeviceConfigWithDevId:(NSString *)devId
                                success:(ThingSuccessDict)success
                                failure:(ThingFailureError)failure;
@end

NS_ASSUME_NONNULL_END
