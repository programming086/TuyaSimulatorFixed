
#ifndef ThingSmartBLEActiveDelegate_h
#define ThingSmartBLEActiveDelegate_h

#import "ThingBLEDeviceInfoProtocol.h"
#import "ThingBLEAdvModel.h"
#import <ThingSmartUtil/ThingSmartUtil.h>
#import "ThingSmartBLECoreEnums.h"
#import "ThingBLEDevInfo.h"

typedef NS_ENUM(NSUInteger, ThingSmartBLEEncKeyType) {
    ThingSmartBLEEncKeyTypeActive = 1, //!< 激活时秘钥
    ThingSmartBLEEncKeyTypeRemove, //!< 移除时秘钥
};

NS_ASSUME_NONNULL_BEGIN

@protocol ThingBLEDeviceInfoProtocol;
/// 用于处理解耦后的BLEKitCore在激活/解绑阶段想要的一些数据回调，比如秘钥、注册的gid等等，回头要拆到public里
@protocol ThingSmartBLEActiveDelegate <NSObject>

@optional

/// 激活、解绑过程传递秘钥给 SDK
/// @param advModel 设备信息
/// @param encKeyType 激活、解绑
/// @param handler 业务层使用handler传递秘钥给SDK
/// @param error error
- (void)transEncKeyWithAdvModel:(ThingBLEAdvModel *)advModel
                     encKeyType:(ThingSmartBLEEncKeyType)encKeyType
                        handler:(nullable void(^)(id _Nullable key))handler
                        failure:(nullable ThingFailureError)error;

/// 注册设备到云端
- (void)registerToServe:(NSString *)uuid devId:(nullable NSString *)devId encryptedAuthKey:(NSString *)encryptedAuthKey productKey:(NSString *)productKey pv:(NSString *)pv sv:(NSString *)sv mac:(nullable NSString *)mac isRegisterKey:(BOOL)isRegisterKey isShare:(BOOL)isShare options:(NSDictionary *)options success:(ThingSuccessDict)success failure:(ThingFailureError)failure;


- (NSInteger)getExtModuleType:(NSString*)devId;

- (void)activateExtendedModule:(NSString*)devId automatic:(BOOL)automatic success:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;

- (void)activateExtendedWiFiModule:(NSString*)devId automatic:(BOOL)automatic ssid:(NSString*)ssid password:(NSString*)pwd success:(nullable ThingSuccessHandler)success failure:(nullable ThingFailureError)failure;


- (void)validateBLEBeaconCapability:(nullable ThingBLESecurityDevInfo *)devInfo;

/// 激活流程加签
/// @param deviceInfo 设备信息
/// @param success success
/// @param failure failure
- (void)handleChipEncrypt:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
                  success:(ThingSuccessHandler)success
                  failure:(ThingFailureError)failure;

/// 同步设备信息，业务根据 devId 获取 device 并处理后传递给 SDK
/// @param devId devId
/// @param handler 业务层使用 handler 传递 device 给SDK
/// @param error error
- (void)syncDeviceInfo:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
                 devId:(NSString *)devId
               handler:(nullable ThingSuccessID)handler
               failure:(nullable ThingFailureError)error;

/// 激活失败
/// @param devId 设备id
- (void)activeFailed:(NSString *)devId;

/// 设备解绑
/// @param deviceInfo 设备信息
/// @param handler handler
/// @param error error
- (void)unbindDevice:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
             handler:(nullable ThingSuccessHandler)handler
             failure:(nullable ThingFailureError)error;

/// 更新设备信息
/// @param deviceInfo 设备信息
- (void)updateDeviceInfo:(id<ThingBLEDeviceInfoProtocol>)deviceInfo;

/// 上报dp点
- (void)reportDps:(NSDictionary *)dps devId:(NSString *)devId dpsTime:(NSString *)dpsTime mode:(NSUInteger)mode reportType:(NSUInteger)type;

/// 上报dp点(无devId本地类型设备)
- (void)reportDps:(NSDictionary *)dps mac:(NSString *)mac dpsTime:(NSString *)dpsTime mode:(NSUInteger)mode reportType:(NSUInteger)type;

/// 上报dp点，time 是个 map
- (void)reportDps:(NSDictionary *)dps devId:(NSString *)devId dpsTimeMap:(NSDictionary *)dpsTimeMap mode:(NSUInteger)mode reportType:(NSUInteger)type;

/// 更新OTA信息
/// @param deviceInfo 设备信息
/// @param otaType OTA类型
/// @param otaVersion OTA版本
- (void)updateOTAVersion:(id<ThingBLEDeviceInfoProtocol>)deviceInfo otaType:(ThingSmartBLEOTAType)otaType otaVersion:(NSString *)otaVersion;

/// 更新设备在线状态
/// @param deviceInfo 设备信息
/// @param isOnline 是否在线
- (void)updateBLEOnlineStatus:(id<ThingBLEDeviceInfoProtocol>)deviceInfo isOnline:(BOOL)isOnline;

/// 发现大数据通道
/// @param deviceInfo 设备信息
/// @param services services
- (void)discoverBleChannel:(id<ThingBLEDeviceInfoProtocol>)deviceInfo services:(NSArray *)services;

/// 传递 psk 信息
/// @param SL 安全级别
/// @param handler 回调
/// @param error failure
- (void)transferPSKInfoWithSL:(NSNumber *)SL
                      handler:(nullable ThingSuccessDict)handler
                      failure:(nullable ThingFailureError)error;

- (void)didScanWifiListSuccess:(NSArray *)wifiList
                       failure:(nullable NSError *)error;

- (void)queryDeviceProductInfo:(NSString *)uuid productKey:(NSString *)productKey success:(ThingSuccessID)success failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingSmartBLEActiveDelegate_h */
