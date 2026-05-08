
#import <Foundation/Foundation.h>
#import "ThingBLEDevInfo.h"

typedef enum : NSUInteger {
    ThingBLEAdvEncryptAuthkey              = 0,
    ThingBLEAdvEncryptECC                  = 1,
    ThingBLEAdvEncryptPassthrough          = 2, ///
    ThingBLEAdvEncryptCompress             = 3, /// PID 加密 需要压缩 pid （在 4.0 以上协议无效）
    ThingBLEAdvEncryptAdvance              = 4, /// 高级加密
    ThingBLEAdvEncryptQRCode               = 5, /// 只支持扫码配网的基于auth key和device id的一般加密设备
    ThingBLEAdvEncryptAuthkeyWithMac       = 6, /// 基于 auth key 和 device uuid 的一般加密(ID 字段带 FLAG2)
    ThingBLEAdvEncryptAdvanceWithMac       = 7, /// 高级加密(ID 字段带 FLAG2)
    ThingBLEAdvEncryptQRCodeWithMac        = 8, /// 用于扫码配网的基于 auth key 和 device uuid 的一般加密(ID 字段带 FLAG2)
} ThingBLEAdvEncryptMode;

typedef enum : NSUInteger {
    ThingBLEAdvProductId            = 00,
    ThingBLEAdvProductKey           = 01,
} ThingBLEAdvProductType;


@interface FrameControlModel : NSObject

//@property (nonatomic, assign) BOOL               timestampInclude;  /// 是否包含时间戳
//@property (nonatomic, assign) BOOL               dpDataEncrypted;   /// dp data 是否加密
@property (nonatomic, assign) BOOL gatewayConnectModel;
@property (nonatomic, assign) NSUInteger connectivity;

@property (nonatomic, assign) BOOL               dpDataInclude;     ///是否包含 dp data，如果为 1 需同时包含 Frame Counter，如 果加密还需要包含 MIC 字段。
@property (nonatomic, assign) BOOL               idInclude;         /// 是否包含 id 字段
@property (nonatomic, assign) BOOL               requestConnection; /// 是否请求连接
@property (nonatomic, assign) BOOL               sharedFlag;        /// 是否为共享类设备
@property (nonatomic, assign) BOOL               boundFlag;         /// 是否绑定
@property (nonatomic, strong) NSString           *version;          /// 设备版本号
@property (nonatomic, assign) BOOL isExecutedV2Secret;  //execute secret
@property (nonatomic, assign) BOOL isSupportV2Secret;  //support secret

@end

@interface FrameControlModelExt : NSObject
////// Whether the device is support  roam
@property (nonatomic, assign) BOOL              isRoaming;


@end


@interface ThingBLEDevInfoInterpreter : NSObject

/**
 *  解析单点设备的广播包
 */
+ (ThingBLEAdvModel *)getBLEDeviceBroadcastInfo:(ThingBLEPeripheral *)p;

/**
 *  通过设备返回的 data 解析成老协议的设备信息 Model
 */
+ (ThingBLEDevInfo *)getBaseDevInfo:(NSString *)hexStr withUUID:(NSString *)uuid;


+ (ThingBLEDevInfo *)getPlusDevInfo:(NSString *)hexStr withUUID:(NSString *)uuid;

/**
 *  通过设备返回的 data 解析成安全协议的设备信息 Model
 */
+ (ThingBLESecurityDevInfo *)getSecurityDevInfo:(NSString *)hexStr;


/**
 *ThingBLEDevInfoInterpreter
 *  通过设备返回的 data 解析成 PlugPlay 设备信息 Model
 */
+ (ThingBLEPlugPlayDevInfo *)getPlugPlayDeviceInfo:(NSString *)hexStr;


/// 通过设备广播包判断是否支持多用户场景（即共享类设备）
+ (BOOL)deviceSupportMultiUser:(ThingBLEPeripheral *)p;

+ (FrameControlModel *)frameControlResolution:(NSString *)data;

@end
