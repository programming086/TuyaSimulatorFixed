
#ifndef ThingBLEDeviceInfoProtocol_h
#define ThingBLEDeviceInfoProtocol_h

#import "ThingBLEActiveProtocol.h"
#import "ThingBLEConfigProtocol.h"

#import <ThingBluetooth/ThingBluetooth.h>

typedef void (^ThingBLEBigDataProgressBlock)(float progress);

typedef enum : NSUInteger {
    ThingBLEEncryptTypeNormal = 1, ///< 一般加密
    ThingBLEEncryptTypeAdvanced,   ///< 高级加密
} ThingBLEEncryptType;

typedef enum : NSUInteger {
    ThingSmartBLEDeviceStateUnactive = 1,  ///< 未激活
    ThingSmartBLEDeviceStateUnstable,      ///< 激活中
    ThingSmartBLEDeviceStateActived,       ///< 已激活
    ThingSmartBLEDeviceStateReconnect,     ///< 重连中
    ThingSmartBLEDeviceStateOTA,           ///< OTA中
    ThingSmartBLEDeviceStateOffline,       ///< 已离线
} ThingSmartBLEDeviceState;

typedef enum : NSUInteger {
    ThingSmartBLEBusinessTypeDefault = 0,   ///< 普通设备设备
    ThingSmartBLEBusinessTypeMulitUser,     ///< 共享类设备
} ThingSmartBLEBusinessType;

typedef enum : NSUInteger {
    ThingBLEAdvIDTypeUUID      = 0,
    ThingBLEAdvIDTypeMac       = 1,
} ThingBLEAdvIDType;

@protocol ThingBLEConfigProtocol;
@protocol ThingBLEDeviceInfoProtocol <NSObject>

@property (nonatomic, strong) ThingBLEAgent *agent;

@property (nonatomic, assign) ThingSmartBLEDeviceState state;

@property (nonatomic, strong) NSString            *uuid;
@property (nonatomic, strong) NSString            *mac;
@property (nonatomic, strong) NSString            *devId;
@property (nonatomic, strong) NSString            *pid;
@property (nonatomic, strong) NSString            *pairUuid;

@property (atomic, strong) ThingBLEPeripheral     *peripheral;
@property (nonatomic, strong) ThingBLEAdvModel       *advModel;
@property (nonatomic, assign) ThingBLEAdvIDType      IDType;

@property (nonatomic, assign) int32_t             sn;
@property (nonatomic, assign) int32_t             ack;

@property (nonatomic, strong) NSDictionary        *schemaDict;

@property (nonatomic, strong) ThingBLECharacteristic *notifyCharacteristic;
@property (nonatomic, strong) ThingBLECharacteristic *writeCharacteristic;
@property (nonatomic, strong) ThingBLECharacteristic *otaCharacteristic;

@property (nonatomic, assign) BOOL                bondState;   ///<  NO = 未绑定 YES = 已绑定
@property (nonatomic, assign) BOOL                isSIGMesh;

@property (nonatomic, assign) NSTimeInterval      activeTime;

// bleSecret
//加密方式
@property (nonatomic, assign) ThingBLEEncryptType      encryptType;
//设备业务类型
@property (nonatomic, assign) ThingSmartBLEBusinessType businessType;

@property (nonatomic, strong) NSMutableDictionary *bizExt;

@property (nonatomic, assign) BOOL        certCheck;            ///< 是否需要云端双向验证证书(大于 4.0 的协议)
@property (nonatomic, assign) BOOL        advanceEncrypt;       ///< 是否支持高级加密（即双向认证）(大于 4.0 的协议)
@property (nonatomic, assign) BOOL        isSupportBeaconkey;   ///< 是否需要获取 beaconKey

//==== Plug&Play 双模字段 ======= //
@property (nonatomic, assign) BOOL        isBLEChannelFirst; ///<  蓝牙通道是否是最高优先级
@property (nonatomic, assign) BOOL        isSupportPlugPlay; ///<  设备是否支持 Plug&Play
@property (nonatomic, strong) NSString    *bleMac;    ///<  ble 的 mac
@property (nonatomic, strong) NSString    *zigbeeMac; ///<  zigbee 子设备的 mac
@property (nonatomic, assign) NSInteger networkStatus;//双模设备上报的网络状态

//安全协议版本
@property (nonatomic, assign) int                 bleProtocolV;

@property (nonatomic, assign) NSUInteger          maxMtuLen;

@property (nonatomic, strong) NSString            *pv;

@property (nonatomic, strong) NSString            *dv;  ///< 硬件版本号1：取硬件版本号2的高2位，例如v1.1
@property (nonatomic, strong) NSString            *dv2; ///< 硬件版本号2：例如0x010000代表v1.1.0
@property (nonatomic, strong) NSString            *sv;  ///< 固件版本号1：取固件版本号2的高2位，例如V1.2
@property (nonatomic, strong) NSString            *sv2; ///< 固件版本号2：例如0x010200代表v1.2.0
@property (nonatomic, assign) BOOL                use_sv2;///< 固件版本是否用 sv2？ true = sv2 false = sv
@property (nonatomic, assign) BOOL                use_dv2;///< 硬件版本是否用 dv2？ true = dv2 false = dv
@property (nonatomic, strong) NSString            *mcuDv; ///< mcu 硬件版本号
@property (nonatomic, strong) NSString            *mcuSv; ///< mcu 固件版本号
@property (nonatomic, strong) NSString            *authKey; ///< mcu 固件版本号

@property (nonatomic, strong) NSMutableArray      *channel_modules; //设备支持的通道 modules
@property (nonatomic, strong) NSString            *bleCapability;/// 蓝牙能力
@property (nonatomic, assign) NSUInteger          packetMaxSize; /// 应用层分包的最大长度
@property (nonatomic, assign) BOOL                isLinkEncrypt; /// 当前蓝牙连接是否已经 LINK 层加密
@property (nonatomic, assign) BOOL                isForceLinkDevice; /// 是否需要强制 LINK 层加密
@property (nonatomic, assign) BOOL                isSecurityLevelDevice; /// 是否需要安全级别配置
@property (nonatomic, strong) NSNumber            *slValue;  /// 安全级别
@property (nonatomic, assign) BOOL                isSupportFitting;  /// 是否支持蓝牙配件
@property (nonatomic, strong) NSDictionary        *fittingSchemaDict; //配件的schemaArray

@property (nonatomic, assign) BOOL                isSupportQueryWifiList; /// 是否支持查询wifi列表
@property (nonatomic, assign) BOOL                isSupportReportConfigState; /// 是否支持主动上报配网阶段状态码

@property (nonatomic, assign) BOOL                isSupportUploadDeviceLog; /// 是否支持日志采集传输
///////// Whether the device is support  roam
@property (nonatomic, assign) BOOL              isRoaming; //是否支持漫游协议

@property (nonatomic, assign) BOOL isExecutedV2Secret;  //设备广播包是否已经执行V2指令
@property (nonatomic, assign) BOOL isSupportV2Secret;  //设备广播包是否支持V2指令

@property (nonatomic, assign) BOOL        isSupportMasterSlaveDevice; //是否支持主从一体方案

@property (nonatomic, assign) BOOL isCloudSynch;

//用来标记是否是从系统蓝牙进行的连接
@property (nonatomic, assign) BOOL isFromeSysBle;

//是否支持单区升级
@property (nonatomic, assign) BOOL bootOTASupport;
//是否正在单区升级
@property (nonatomic, assign) BOOL bootOTABeing;




- (void)handlePeripheral:(ThingBLEPeripheral *)peripheral;

/// 更新设备活跃时间
- (void)updateActiveEvent;

- (void)configSchemaDict:(NSString *)json;

- (void)configFittingSchemaDict:(NSString *)json;

@property (nonatomic, strong) id<ThingBLEActiveProtocol> activeManager;

@property (nonatomic, strong) id<ThingBLEActiveProtocol, ThingLocalBLEActiveProtocol> localActiveMgr;

@property (nonatomic, strong) id<ThingBLEConfigProtocol> configManager;

@end


#endif /* ThingBLEDeviceInfoProtocol_h */
