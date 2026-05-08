//
//  TYBLEDevInfo.h
//  TuyaSmartKit
//
//  Created by 冯晓 on 2017/2/9.
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//


@interface TYBLEDevInfo : NSObject

/**
 *  老协议的设备信息 model
 */
@property (nonatomic, strong, nullable) NSString *  uuid;
@property (nonatomic, strong, nullable) NSString *sv;
@property (nonatomic, strong, nullable) NSString *pv;
@property (nonatomic, strong, nullable) NSString *authKey;
@property (nonatomic, strong, nullable) NSString *randomHex;
@property (nonatomic, strong, nullable) NSString *random;

@end

/**
 *  安全协议的设备信息 model
 */
@interface TYBLESecurityDevInfo : NSObject

@property (nonatomic, strong, nullable) NSString    *uuid;
@property (nonatomic, strong, nullable) NSString    *dv;  //硬件版本号1：取硬件版本号2的高2位，例如v1.1
@property (nonatomic, strong, nullable) NSString    *dv2; //硬件版本号2：例如0x010000代表v1.1.0
@property (nonatomic, strong, nullable) NSString    *sv;  //固件版本号1：取固件版本号2的高2位，例如V1.2
@property (nonatomic, strong, nullable) NSString    *sv2; //固件版本号2：例如0x010200代表v1.2.0
@property (nonatomic, assign) BOOL        use_sv2;//固件版本是否用 sv2？ true = sv2 false = sv
@property (nonatomic, assign) BOOL        use_dv2;//硬件版本是否用 dv2？ true = dv2 false = dv
@property (nonatomic, strong, nullable) NSString    *pv;  //协议版本
@property (nonatomic, strong, nullable) NSString    *flag;
@property (nonatomic, strong, nullable) NSString    *bleType;
@property (nonatomic, assign) BOOL        bond;
@property (nonatomic, strong, nullable) NSString    *srand;
@property (nonatomic, strong, nullable) NSString    *authKey;//实际是从云端获取的 authKey 对应的 secretKey
@property (nonatomic, strong, nullable) NSString    *ability;//通讯能力
@property (nonatomic, strong, nullable) NSString    *devId;//设备虚拟 id
@property (nonatomic, strong, nullable) NSString    *mcuDv; //mcu 硬件版本号
@property (nonatomic, strong, nullable) NSString    *mcuSv; //mcu 固件版本号
@property (nonatomic, strong, nullable) NSString    *bleMac; //ble 的 mac
@property (nonatomic, strong, nullable) NSString    *zigbeeMac; //zigbee 子设备的 mac
@property (nonatomic, strong, nullable) NSMutableArray    *channel_modules; //设备支持的通道 modules
@property (nonatomic, assign) BOOL        isSupportRegisterKey;//是否支持 registerKey
@property (nonatomic, assign) BOOL        isSupportPlugPlay;//是否支持 Plug&Play
@property (nonatomic, assign) BOOL        certCheck;/// 是否需要云端双向验证证书(大于 4.0 的协议)
@property (nonatomic, assign) BOOL        advanceEncrypt;/// 是否支持高级加密（即双向认证）(大于 4.0 的协议)
@property (nonatomic, assign) BOOL        isSupportBeaconkey;/// 是否需要获取 beaconKey
@property (nonatomic, strong, nullable) NSString    *bleCapability;/// 蓝牙能力
@property (nonatomic, assign) NSInteger   packetMaxSize; /// 应用层分包的最大长度
@property (nonatomic, assign) BOOL        isLinkEncrypt; /// 当前蓝牙连接是否已经 LINK 层加密
@property (nonatomic, assign) BOOL        isForceLinkDevice; /// 是否需要强制 LINK 层加密
@property (nonatomic, assign) BOOL        isSecurityLevelDevice; /// 是否需要安全级别配置
@property (nonatomic, strong, nullable) NSNumber    *slValue; /// 安全级别
@end


@interface TYBLEPlugPlayDevInfo : NSObject

/**
 *  支持 PlugPlay 的设备信息 model
 */
@property (nonatomic, strong, nullable) NSString      *version;               /// 指令版本号
@property (nonatomic, strong, nullable) NSString      *protocolVer;           /// wifi 协议版本
@property (nonatomic, assign) NSUInteger    devAttribute;           /// 设备能力
@property (nonatomic, strong, nullable) NSString      *baselineVer;           /// 基线版本
@property (nonatomic, strong, nullable) NSString      *softVer;               /// 固件版本号
@property (nonatomic, strong, nullable) NSString      *cadVer;                /// cad 版本
@property (nonatomic, strong, nullable) NSString      *cdVer;
@property (nonatomic, strong, nullable) NSString      *modules_softVer;       /// mcu 软件版本
@property (nonatomic, assign) NSUInteger    modules_otaChannel;     /// mcu 升级通道
@property (nonatomic, assign) BOOL          modules_online;         /// 线上，1 个字节，0 – false , 1 – true
@property (nonatomic, assign) BOOL          options_isFK;           /// 是否 OEM，1 个字节， 0 – false , 1 – true
@property (nonatomic, assign) NSUInteger    options_otaChannel;     /// wifi 固件升级通道
@property (nonatomic, strong, nullable) NSString      *options_udf;           /// wifi 固件升级通道
@property (nonatomic, assign) BOOL          isSupportSchema;        /// bit0 是否需要 schema, 0 – 不需要，1 – 需要
@property (nonatomic, assign) int           packetMaxSize;          /// 发送设备激活信息时，分包的最大长度
@property (nonatomic, strong, nullable) NSString      *productkey;            /// 产品 ID
@property (nonatomic, strong, nullable) NSString      *productkeyStr;         /// 固件 key
@property (nonatomic, strong, nullable) NSString      *devId;                 /// 设备 ID
@property (nonatomic, strong, nullable) NSString      *hid;                   /// mac 地址
@property (nonatomic, strong, nullable) NSString      *uuid;                  /// 设备 uuid
@property (nonatomic, strong, nullable) NSString      *communicatePriority;   /// 优先级

@end
