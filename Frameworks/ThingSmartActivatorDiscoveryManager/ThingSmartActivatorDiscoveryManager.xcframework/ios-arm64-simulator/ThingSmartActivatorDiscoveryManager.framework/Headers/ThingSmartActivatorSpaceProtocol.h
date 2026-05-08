//
//  ThingSmartActivatorSpace.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2021/9/3.
//

#import <Foundation/Foundation.h>
@import ThingSmartUtil;

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartDeviceModel;

/// 配网所处的空间，公版是「家庭」
@protocol ThingSmartActivatorSpaceProtocol <NSObject>

@required
/// 获取token
- (void)getTokenWithProductKey:(nullable NSString *)productKey
                       success:(ThingSuccessString)success
                       failure:(ThingFailureError)failure;

/// 获取空间 id (公版:当前家庭ID homeId)
- (long long)spaceId;

/// Binding devices to a specified home.
/// @param devIds Device ID list.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)bindDevicesToSpace:(NSArray <NSString *>*)devIds success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

@optional
/// 获取当前空间下的免密能力的设备
- (nullable NSArray <ThingSmartDeviceModel *> *)autoActiveSupportedDeviceList;

/// 获取当前空间下的融合路由器能力的设备
- (nullable NSArray <ThingSmartDeviceModel *> *)routerActiveDeviceList;

/// Devices supporting Pegasus.
/// @return A list of devices that support Pegasus.
- (nullable NSArray <ThingSmartDeviceModel *> *)pegasusDeviceList;
@end

NS_ASSUME_NONNULL_END
