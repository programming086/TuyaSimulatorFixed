//
//  TYActivatorLinkModeDefine.h
//  Pods
//
//  Created by qisong on 2022/3/25.
//

#ifndef TYActivatorLinkModeDefine_h
#define TYActivatorLinkModeDefine_h

/*
 根据配网方式， 1000 ～ 1003 是在 TYLinkModeBT 的基础上开出的更细的类型，选用 1000 是为了避免于新增的类型重复
 */
typedef NS_ENUM(NSInteger, TYLinkMode) {
    TYLinkModeDefault = 0,
    TYLinkModeEZ = 1,
    TYLinkModeAP = 2,
    /// Zigbee 子设备配网
    TYLinkModeZIGSUB = 3,
    /// 二维码配网（app 提供，包含 Wi-Fi 信息）
    TYLinkModeQRCode = 4,
    TYLinkModeNB = 5,
    TYLinkModeGPRS = 6,
    /// 蓝牙配网
    TYLinkModeBT = 7,
    /// 有线配网
    TYLinkModeWC = 8,
    /// 433 子设备配网
    TYLinkMode433SUB = 9,
    /// 二维码扫码配网（内部按步骤引导扫码/手输 uuid，请求得到 token）
    TYLinkModeCaptureDevice2 = 10,
    /// 二维码蜂窝配网（app 提供二维码，不包含 Wi-Fi 信息）
    TYLinkModeQRCode2 = 11,
    /// 协助配网
    TYLinkModeAssistAssesory = 12,
    /// 蓝牙扫码配网
    TYLinkModeBLEQRCode = 13,
    
    /// 二维码扫码配网（外部扫一扫功能，扫码后得到 uuid，请求token；token 作为入参传入）
    TYLinkModeCaptureDevice = 1000,
    /// TuyaLink设备 (扫一扫后获取uuid，传入homeId，绑定设备)
    TYLinkModeTuyaLink = 1001,
    /// 免配网设备（扫一扫）
    TYLinkModeApDirectly = 1002,
    
    /// 自发现
    TYLinkModeAutoSearch = 1101,
    /// 弹窗配网
    TYLinkModePopup = 1102,
    /// 网关面板配子设备
    TYLinkModeSUBPanel = 1103,
    /// 闪电路由器面板配子设备
    TYLinkModePegasusPanel = 1104,
   
    TYLinkModeEnd
};

FOUNDATION_EXTERN NSString*NSStringFromTYLinkMode(TYLinkMode value);

#endif /* TYActivatorLinkModeDefine_h */
