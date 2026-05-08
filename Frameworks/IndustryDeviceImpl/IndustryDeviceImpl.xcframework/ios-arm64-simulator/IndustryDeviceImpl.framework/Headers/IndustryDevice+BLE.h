//
//  IndustryDevice+BLE.h
//  IndustryDeviceImpl
//
//  Created by ChenKun on 2023/6/2.
//

#import "IndustryDevice.h"

NS_ASSUME_NONNULL_BEGIN

@interface IndustryDevice (BLE)

// 查询设备蓝牙是否本地连接
- (BOOL)deviceOnlineStatus;

// 连接设备
- (void)connectBLE:(void(^)(void))success failure:(void(^)(void))failure;

// 断开已连接的设备
- (void)disconnectBLE:(void(^)(void))success failure:(void(^)(NSError *))failure;

// 查询设备名称
- (void)queryDeviceInfo:(void(^)(NSDictionary *))success failure:(void(^)(NSError *))failure;

@end

NS_ASSUME_NONNULL_END
