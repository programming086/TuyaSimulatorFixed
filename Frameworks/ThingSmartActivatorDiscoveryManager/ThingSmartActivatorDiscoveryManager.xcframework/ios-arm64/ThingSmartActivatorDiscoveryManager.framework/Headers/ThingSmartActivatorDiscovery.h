//
//  ThingSmartActivatorDiscovery.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2021/8/27.
//

#import <Foundation/Foundation.h>
#import <ThingBluetoothInterface/ThingBluetoothInterface.h>
#import "ThingSmartActivatorType.h"
#import "ThingSmartActivatorDiscoverySerializer.h"
#import "ThingSmartActivatorSpaceProtocol.h"
#import "ThingSmartActivatorHomekitServiceProtocol.h"
#import "ThingSmartActivatorParam.h"

NS_ASSUME_NONNULL_BEGIN
@class ThingSmartActivatorDeviceModel, ThingSmartActivatorErrorModel, ThingSearchActivatorConfig, ThingSmartActivatorDeviceConnectModel;
@protocol ThingSmartActivatorDiscoveryDelegate;

/// 自发现
@interface ThingSmartActivatorDiscovery : NSObject

/// 初始化自发现
/// @param config 配置
/// @param space 配网所处的空间
- (instancetype)initWithConfig:(nullable ThingSearchActivatorConfig *)config
                         space:(id<ThingSmartActivatorSpaceProtocol>)space NS_DESIGNATED_INITIALIZER;
/// 初始化自发现
/// @param space 配网所处的空间
- (instancetype)initWithSpace:(id<ThingSmartActivatorSpaceProtocol>)space;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// 开始搜索
/// @param type type
- (void)startSearch:(ThingSmartActivatorType)type;

/// 开始搜索
/// @param type type
/// @param success success
/// @param failure EZ/Auto/Router 获取 token 的失败
- (void)startSearch:(ThingSmartActivatorType)type
            success:(void(^__nullable)(ThingSmartActivatorType type))success
            failure:(void(^__nullable)(ThingSmartActivatorType type, NSError *error))failure;

/// 停止扫描设备 (蓝牙设备\闪电设备)
/// @param type 配网类型
/// @param clearCache 清除缓存
- (void)stopScan:(ThingSmartActivatorType)type clearCache:(BOOL)clearCache;

/**
 *开始配网 (激活设备)
 */
- (void)startConfig:(NSArray<ThingSmartActivatorDeviceModel *>*)deviceList activatorType:(ThingSmartActivatorType)activatorType;

/**
 *开始配网 (激活设备)  with callback
 */
- (void)startConfig:(NSArray<ThingSmartActivatorDeviceModel *> *)deviceList
      activatorType:(ThingSmartActivatorType)activatorType
            success:(void(^_Nullable)(ThingSmartActivatorType type))success
            failure:(void(^_Nullable)(ThingSmartActivatorType type, NSError *error))failure;

/**
 *开始配网 (激活设备)  传入参数 with callback
 */
- (void)startConfig:(NSArray<ThingSmartActivatorDeviceModel *> *)deviceList
      activatorType:(ThingSmartActivatorType)activatorType
          parameter:(nullable NSDictionary *)parameter
            success:(void(^_Nullable)(ThingSmartActivatorType type))success
            failure:(void(^_Nullable)(ThingSmartActivatorType type, NSError *error))failure;

/// 停止配网 (停止扫描和激活流程)
/// @param type  配网类型
/// @param clearCache 清空缓存。YES: 清空全部搜索到的设备，NO：不清空缓存
///
/// @note clearCache 为 YES，type 包含 ThingSmartActivatorTypeBle，才可以清理蓝牙 SDK 扫描的缓存
- (void)stopConfig:(ThingSmartActivatorType)type clearCache:(BOOL)clearCache;

/// 停止配网指定设备
/// @param deviceList 待停止的设备
/// @param activatorType  配网类型
/// @param clearCache 清空缓存。YES: 清空全部搜索到的设备，NO：不清空缓存
///
/// @note 仅beacon配网类型支持
/// TODO : 放到beacon扩展里
- (void)stopConfigDevices:(NSArray<ThingSmartActivatorDeviceModel *> *)deviceList
            activatorType:(ThingSmartActivatorType)activatorType
               clearCache:(BOOL)clearCache;

/**
 *蓝牙多模设备配置 Wi-Fi 通道(蓝牙通道已激活),结果通过回调给出
 *@param activatorType 配网类型, 请使用 ThingSmartActivatorTypeBle
 */
- (void)configMultimodeDeviceDualWifiChannel:(ThingSmartActivatorType)activatorType
                                       model:(ThingSmartActivatorDeviceModel *)deviceModel;

/**
 * 蓝牙多模设备蓝牙激活通道(仅激活蓝牙)
 * @param activatorType 配网类型, 请使用 ThingSmartActivatorTypeBle
 * @param deviceModel deviceModel
 */
- (void)configMultimodeDeviceDualBleChannel:(ThingSmartActivatorType)activatorType
                                      model:(ThingSmartActivatorDeviceModel *)deviceModel;

/// 将设备切换至对应的配网类型，使设备能进行重新激活
/// @param activatorType 目标的配网类型
/// @param devices 待激活设备
/// @param success 成功回调
/// @param failure 失败回调
- (void)activatorType:(ThingSmartActivatorType)activatorType
  switchActivatorType:(ThingSmartActivatorType)switchActivatorType
              devices:(NSArray<ThingSmartActivatorDeviceModel *> *)devices
              success:(ThingSuccessHandler)success
              failure:(ThingFailureError)failure;

/// 重置设备(已经扫描到但是不打算添加的设备需要进行重置，重新进入待配网状态)
/// @param devices 需要进行重置的设备
- (void)resetScanDevices:(NSArray<ThingSmartActivatorDeviceModel *> *)devices;

/// 重新设置配网配置
- (void)setupConfig:(ThingSearchActivatorConfig *)config;

- (void)setupConfig:(ThingSearchActivatorConfig *)config activator:(ThingSmartActivatorType)activator;

/// AP PSK配网第二阶段
- (void)configAPSecurityLevelDevice;

/// 设备扫描附近 Wi-Fi 列表
///
/// @param param 扫描参数
/// @param activatorType 配网类型（支持AP和双模）
/// @param success success
/// @param failure failure
- (void)scanWifiList:(ThingSmartActivatorScanWifiParam *)param
       activatorType:(ThingSmartActivatorType)activatorType
             success:(void(^)(NSArray<ThingSmartActivatorScanWifiModel *> *list))success
             failure:(void(^)(NSError * _Nullable error))failure;

/// 恢复 Wi-Fi 配网
/// @param param 恢复配网参数
/// @param activatorType 配网类型
/// @return 0: success; other: error code
/// - AP: ThingPairingErrorCode
/// - ble: 0:成功 1:参数错误 2:配网对象不存在 3:设备不支持该能力
- (NSInteger)resumeConfigWifi:(ThingSmartActivatorResumeConfigWiFiParam *)param
                activatorType:(ThingSmartActivatorType)activatorType;
    
/// ------------------ Matter  --------------------
///

/// 校验二维码是否为 Matter 设备二维码
/// @param qrString The QRCode string.
/// @return A matter setup model.
- (ThingSmartActivatorDeviceModel *)checkMatterCodeInvalid:(NSString *)qrString;

/// Thing Matter 设备校验
/// @param payload The  matter setup model.
/// @param success call back when is thing device.
/// @param failure call back when is origin matter device.
- (void)checkThingDeviceWithPayload:(ThingSmartActivatorDeviceModel *)payload success:(ThingSuccessID)success failure:(ThingFailureError)failure;

/// DNS 发现服务
/// @param payload The  matter setup model.
- (void)startDiscoveryBonjourServices:(ThingSmartActivatorDeviceModel *)payload timeout:(NSTimeInterval)timeout success:(ThingSuccessID _Nullable)success failure:(ThingFailureError _Nullable)failure;

/// 蓝牙配对
/// @param payload The  matter setup model.
- (void)pairDeviceWithSetupPayload:(ThingSmartActivatorDeviceModel *)payload timeout:(NSTimeInterval)timeout success:(ThingSuccessID _Nullable)success failure:(ThingFailureError _Nullable)failure;


/// check 设备授权验证
- (void)checkThingDeviceAttestation:(void (^)(void *_Nullable device,NSError *_Nullable error))attestation;

/// 验证结束,继续 commissioning 流程
- (void)continueCommissioningDevice:(void *)device
           ignoreAttestationFailure:(BOOL)ignoreAttestationFailure
                              error:(NSError * __autoreleasing *)error;



/// ------------------ Matter  End --------------------


/// 自发现参数
@property (nonatomic, readonly, nullable) ThingSearchActivatorConfig *activatorConfig;
@property (nonatomic, weak, nullable) id<ThingSmartActivatorDiscoveryDelegate> delegate;

/// 配网所处空间
@property (nonatomic, readonly) id<ThingSmartActivatorSpaceProtocol> space;

/// 输入/输出处理
@property (nonatomic) id<ThingSmartActivatorDiscoverySerializer> serializer;

/// HomeKit 实现
/// @note 搜索类型包含 `ThingSmartActivatorTypeHomeKit` 必须提供实现
@property (nonatomic, nullable) id<ThingSmartActivatorHomekitServiceProtocol> homeKitImpl;

@property (nonatomic, assign) BOOL noNeedChangeDeviceStatus;

/// 默认 NO， 当 YES 时停止配网会继续设备扫描
@property (nonatomic, assign) BOOL stopConfigKeepScan;

@end

@protocol ThingSmartActivatorDiscoveryDelegate <NSObject>

@optional
/// 搜索到设备
/// @param discovery 搜索实例
/// @param device 发现的设备
/// @param errorModel 发现设备的错误，若有错误，device 为 nil
- (void)activatorDiscovery:(ThingSmartActivatorDiscovery *)discovery
             didFindDevice:(nullable ThingSmartActivatorDeviceModel *)device
                     error:(nullable ThingSmartActivatorErrorModel *)errorModel;

/// 不同通道再次搜索到设备
/// @param discovery 搜索实例
/// @param device 再次发现的设备
- (void)activatorDiscovery:(ThingSmartActivatorDiscovery *)discovery
           didUpdateDevice:(ThingSmartActivatorDeviceModel *)device;

// 配网成功结果
- (void)activatorDiscovery:(ThingSmartActivatorDiscovery *)discovery
             activatorType:(ThingSmartActivatorType)type
         didReceiveDevices:(NSArray<ThingSmartActivatorDeviceModel *> *)devices
                     error:(nullable NSError *)error;

// 蓝牙Mesh设备重连成功
- (void)activatorDiscovery:(ThingSmartActivatorDiscovery *)discovery bluetoothMangerDidConnectMeshNodeAndLoginMeshSuccessLoginWithType:(ThingBluetoothDeviceType)deviceType;

/// 设备返回的应答信息
/// @param discovery 配网实例
/// @param response 设备返回的信息
///  Wi-Fi 联网错误:
///  - response: ThingSmartActivatorConfigResponse
///     - response.response: ThingSmartActivatorConfigResponseConfigWifi
/// @param error 设备返回的错误
- (void)activatorDiscovery:(ThingSmartActivatorDiscovery *)discovery
        didReceiveResponse:(id __nullable)response
                     error:(NSError * __nullable)error;

/// 仅beacon回调，批量配网完成
- (void)beaconServiceDidFinishConfigAllDevices;

@end

NS_ASSUME_NONNULL_END
