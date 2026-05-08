//
//  TYSpaceInfoEntity.h
//  TYSpaceInfomationModule
//
//  Created by Hiraeth on 2022/3/16.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSObject<NSCopying>* SpaceID;

typedef NS_ENUM(NSInteger, NodeType) {
    NodeTypeDevice = 0,
    NodeTypeGroup
};

/// 屏蔽 GroupModel 与 DeviceModel 的差异的封装类
@protocol TYSINode <NSObject>

// 展示的数据内容
- (id)cellModel;

/// deviceModel 或 GroupModel，具体类型通过 nodeType 判断
- (id)model;

/// Model 类型
- (NodeType)nodeType;

/// devID 或者 GroupID
- (NSString *)nodeID;

- (NSString *)name;
- (NSString *)iconUrl;

#pragma mark - 产品属性

- (NSDictionary<NSString*, id> *) dps;

- (NSDictionary<NSString*, TuyaSmartSchemaModel*> *) schemaModelDic;

- (NSDictionary *)meta;

#pragma mark - OTA 属性

- (BOOL)isUpgrading;
- (TuyaSmartDeviceOTAModel *)otaModel;

#pragma mark - 快捷控制

/// 快捷显示的 dpID 列表
- (NSArray<NSNumber *> *)displayDps;

/// 快捷控制的 dpID 列表
- (NSArray<NSNumber *> *)quickOpDps;

/// 快捷开关的 dpID 列表
- (NSArray<NSNumber *> *)switchDps;

/// switchDps 的或运算结果
- (BOOL)switchDpsValue;

#pragma mark - 显示控制

- (NSInteger)displayOrder;
- (NSInteger)homeDisplayOrder;

#pragma mark - Tuya 智能设备属性 https://wiki.tuya-inc.com:7799/page/36876766

/// 是否为蓝牙设备。
- (BOOL)isBluetooth;

/// 是否支持 蓝牙能力，包括 BLE、sig mesh 和 tuya mesh
- (BOOL)ishasBluetoothCapability;

/// 是否支持 单点蓝牙能力
- (BOOL)isHasBLECapability;

/// 是否支持 Sig Mesh 能力
- (BOOL)isHasSigmeshCapability;

/// 是否支持 Tuya Mesh 能力
- (BOOL)isHasTuyaMeshCapbility;

/// 是否支持 Beacon 能力
- (BOOL)isHasBeaconCapbility;

/// 是否为 mesh 子设备，包括 sig mesh 和 tuya mesh
- (BOOL)isBLEMesh;

/// 是否是 Mesh 网关
- (BOOL)isMeshGateway;

/// 是否为 ble+x 双模拓展设备
- (BOOL)isBluetoothExt;

/// 是否支持连接路由器 Wi-Fi 和 Cable
- (BOOL)isHasWifiOrCableCapability;

/// 是否为联网设备（Wi-Fi 和 Cable），且不是网关
- (BOOL)isNeedRouter;

/// 是否为网关
- (BOOL)isGateway;

/// 是否在网关下。注意当前设备为子设备时，这个属性才有意义
- (BOOL)isUnderGateway;

/// 子设备网关是否在线。注意当前设备为子设备时，这个属性才有意义
- (BOOL)isGatewayOnline;

/// 是否能通过路由器连接，Wi-Fi 和 Cable
- (BOOL)isRouterOnline;

/// 是否云端在线。通过 mqtt 判断，云端下发，Tuya Mesh 需要特殊判断。
- (BOOL)isCloudOnline;

/// 蓝牙模块是否在线。包括单点、mesh、beacon
- (BOOL)isBluetoothOnline;

/// 蓝牙单点能力设备是否本地在线
- (BOOL)isBLEOnline;

/// mesh 能力设备是否本地在线
- (BOOL)isMeshOnline;

/// Beacon 能力设备是否本地在线
- (BOOL)isBeaconOnline;

/// 是否局域网在线。
- (BOOL)isLANOnine;

/// 是否支持手机和设备直接通讯。仅 局域网在线 和 蓝牙本地在线
- (BOOL)isLocalOnine;

/// 任何一种在线都算在线。群组默认在线，设备升级中不在线。
- (BOOL)isOnline;

@end

NS_ASSUME_NONNULL_END
