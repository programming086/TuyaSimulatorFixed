//
//  ThingSmartActivatorDeviceModel.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by huangjj on 2019/3/14.
//

#import <Foundation/Foundation.h>
#import <ThingBluetoothInterface/ThingBluetoothInterface.h>
#import "ThingSearchActivatorEnum.h"
#import "ThingSmartActivatorType.h"

NS_ASSUME_NONNULL_BEGIN

// 有线配网默认名称
FOUNDATION_EXPORT NSString *const ThingSmartActivatorDiscoveryWiredServiceDefaultName;

/// 发现模型
@interface ThingSmartActivatorDeviceModel : NSObject

/// 设备唯一标识
@property (nonatomic, readonly, copy) NSString *uniqueID;

/// 设备虚拟 ID , 与 uniqueID 非等价关系, devId 为设备配网完成后云端所分配虚拟id, 配网前为空
@property (nonatomic, copy) NSString *devId;

/// 真实的实体设备的类型, 如 双模、zigbee双模、SigMesh、WiFI单品等
@property (nonatomic, assign) ThingSearchDeviceModelType deviceModelType;
/// 设备配网类型
@property (nonatomic, assign) ThingSmartActivatorType activatorType;
/// 设备支持的能力
@property (nonatomic, assign) ThingActivatorDeviceAbility deviceAbility;
/// 设备配网状态
@property (nonatomic, assign) ThingSearchDeviceStatus  deviceStatus;
/// 设备名称
@property (nonatomic, copy) NSString *name;
/// 设备图标 URL
@property (nonatomic, copy, nullable) NSString *iconUrl;
/// 产品id
@property (nonatomic, copy, nullable) NSString *productId;

/// 配网失败错误信息:设备被他人绑走的信息展示 双向绑
@property (nonatomic, strong, nullable) NSError *error;

/// 是否支持5G
@property (nonatomic, assign) BOOL isSupport5G;

@property (nonatomic, strong, nullable) NSMutableArray<ThingSmartActivatorDeviceModel *> *deviceLists;

@property (nonatomic, assign) BOOL isThingDevice;

/**
 * 设备连接路由器信息, 非所有设备类型具有, WiFi 模块设备需要
 */
@property (nonatomic, copy) NSString *ssid;
@property (nonatomic, copy) NSString *password;

/// 各配网方式额外携带的信息
@property (nonatomic, copy, nullable) NSDictionary *userInfo;

/// The product category code (PCC) value of the `Powered by Tuya` device node.
@property (nonatomic, strong) NSString *type;

/// 信号强度，只支持 sigmesh 设备
@property (nonatomic, assign) NSInteger RSSI;

/// mac 地址
@property (nonatomic, copy) NSString *mac;

- (instancetype)initWithUniqueID:(NSString *)uniqueId;

/// 当前设备是否需要有 WiFi 认证信息才才能继续进行配对
/// @disucssion  `ssid` 不为空时才可能为 YES
- (BOOL)needInputWiFiAuthentication;

/// 当前设备配备依赖Wi-Fi认证信息
/// @disucssion 与`needInputWiFiAuthentication`不同， 与 `ssid` 无关
- (BOOL)needWiFiAuthentication;

- (BOOL)supportAbilityPlugPlay;

- (BOOL)supportAbilityPagesus;

- (BOOL)supportAbilityHomeKit;

- (BOOL)supportAbilityBleZigbee;

- (BOOL)supportAbilityBlePrior;

- (BOOL)supportAbilityBleQRCode;

- (BOOL)supportAbilityMatter;

- (BOOL)supportAbilityMatterFabric;

/// 如果配网失败,可查询是否是强绑定\双向绑定错误,需要配合 error 一起查看
- (BOOL)bindingFailed;


@end

NS_ASSUME_NONNULL_END

