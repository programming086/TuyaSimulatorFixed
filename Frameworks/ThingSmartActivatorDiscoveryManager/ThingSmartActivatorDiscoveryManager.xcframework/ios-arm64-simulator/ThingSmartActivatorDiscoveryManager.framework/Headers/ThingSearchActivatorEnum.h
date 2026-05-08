//
//  ThingSearchActivatorEnum.h
//  ThingSearchActivatorModule
//
//  Created by huangjj on 2019/6/21.
//

#ifndef ThingSearchActivatorEnum_h
#define ThingSearchActivatorEnum_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 真实的实体设备的类型, 如 双模、zigbee双模、SigMesh、WiFI单品等
typedef enum : NSUInteger {
    ThingSearchDeviceModelTypeUnknow = 0,
    ThingSearchDeviceModelTypeWifi,    // WiFi 设备 （Auto、EZ、router 配 WiFi）
    ThingSearchDeviceModelTypeWired,  // 有线设备（zigbee 有线网关、有线摄像头、低功耗基站、router 有线网关）
    ThingSearchDeviceModelTypeBleMeshSubDevice, // 蓝牙 mesh 子设备
    ThingSearchDeviceModelTypeBleMeshGateway,   // 蓝牙 mesh 网关
    ThingSearchDeviceModelTypeBle,    // 蓝牙单点
    ThingSearchDeviceModelTypeBleWifi,    //蓝牙 Wi-Fi 配网
    ThingSearchDeviceModelTypeBleZigbee,   // 蓝牙 ZigBee 子设备
    ThingSearchDeviceModelTypeHomeKitWifi, // Homekit Wi-Fi 设备
    ThingSearchDeviceModelTypeSigMeshSubDevice, // SIG Mesh 设备
    ThingSearchDeviceModelTypeSubDevice,  // 子设备
    ThingSearchDeviceModelTypePegasus, // 闪电配网
    ThingSearchDeviceModelTypeBleLTE,    //蓝牙 LTE 配网（cat.1）
    ThingSearchDeviceModelTypeBeacon,    //蓝牙 Beacon
    ThingSearchDeviceModelTypeMatterWired,  // Matter 有线
    ThingSearchDeviceModelTypeMatterWifi, // Matter 双模
    ThingSearchDeviceModelTypeMatterThread, // Matter thread 
    ThingSearchDeviceModelTypeEnd, /// ⚠️此处为结束标志，所有要添加的枚举请放在此项之前
} ThingSearchDeviceModelType;

// 配网过程中已知设备具备的能力，一个真实设备实体可能同时具备多个能力类型,如双模设备可能同时具备闪电、HomeKit、PlugPlay等能力
typedef NS_OPTIONS(NSUInteger, ThingActivatorDeviceAbility) {
    ThingActivatorDeviceAbilityUnknown = 0,
    ThingActivatorDeviceAbilityPegasus = (1 << 0),  /** 闪电⚡️能力 */
    ThingActivatorDeviceAbilityHomeKit = (1 << 1),    /** HomeKit能力 */
    ThingActivatorDeviceAbilityPlugPlay = (1 << 2),  /** Plug&Play能力 能进行兜底配网 */
    ThingActivatorDeviceAbilityBlePrior = (1 << 3), /** 蓝牙优先配网能力 */
    ThingActivatorDeviceAbilityBleQRCode = (1 << 4), /** 蓝牙设备，通过扫码配网 */
    ThingActivatorDeviceAbilityMatterBle = (1 << 5), /** Matter Ble 能力*/
    ThingActivatorDeviceAbilityMatterOnNetwork = (1 << 6), /** Matter 有线能力*/
    ThingActivatorDeviceAbilityMatterFabric = (1 << 7), /** Matter Fabirc 能力*/
};

// 设备状态
typedef enum : NSUInteger {
    ThingSearchDeviceStatusNoNetwork,    // 未配网
    ThingSearchDeviceStatusNetwork,   // 已配网
    ThingSearchDeviceStatusRetry,        // 重试状态
    ThingSearchDeviceStatusFailure,    // 失败
} ThingSearchDeviceStatus;


// 配网过程step
typedef enum: NSUInteger {
    ThingActivatorDeviceStepFound = 1,  // < device found
    ThingActivatorDeviceStepRegisted = 2,  // < device registered
    ThingActivatorDeviceStepIntialized = 3, // < device initialized
    ThingActivatorDeviceStepTimeOut = 4,///< device config timeout
} ThingActivatorDeviceStep;

NS_ASSUME_NONNULL_END

#endif /* ThingSearchActivatorEnum_h */
