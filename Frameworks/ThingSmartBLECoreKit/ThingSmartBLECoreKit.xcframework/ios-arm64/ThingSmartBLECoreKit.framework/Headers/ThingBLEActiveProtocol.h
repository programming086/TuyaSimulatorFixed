
#ifndef ThingBLEActiveProtocol_h
#define ThingBLEActiveProtocol_h
#import <ThingSmartUtil/ThingSmartUtil.h>
#import "ThingSmartBLEActiveDelegate.h"

NS_ASSUME_NONNULL_BEGIN

//TODO: wuge 配网失败的error类型可以归纳成enum

@class ThingSmartBLELocalDevice;
typedef void(^ ThingSmartLocalBLEDeviceConnectedHandler)(ThingSmartBLELocalDevice *localDevice);

@protocol ThingBLEActiveProtocol;
@protocol ThingBLEDeviceInfoProtocol;
@protocol ThingSmartBLEActiveDelegate;
@class ThingBLEAdvModel;

@protocol ThingBLEActiveDelegate <NSObject>

@optional

- (void)activeManager:(id<ThingBLEActiveProtocol>)active stage:(NSInteger)stage notConfigStateWithError:(NSError *)error;

//check单点设备是否已经被其他链路激活(网关等)
/// @param active activeManager
/// @param uuid deviceInfo
/// @return Device Model ActiveTime
- (long long)activeManager:(id<ThingBLEActiveProtocol>)active checkBLESubDeviceActivedState:(nonnull NSString *)uuid;

- (void)activeManager:(id<ThingBLEActiveProtocol>)active deviceInfo:(id<ThingBLEDeviceInfoProtocol>)deviceInfo didScanWifiListSuccess:(NSArray *)wifiList failure:(nullable NSError *)error;

/// 配网结果回调
/// @param active activeManager
/// @param deviceInfo deviceInfo
/// @param result result
/// @param error error
- (void)activeManager:(id<ThingBLEActiveProtocol>)active deviceInfo:(id<ThingBLEDeviceInfoProtocol>)deviceInfo didActiveSuccess:(nullable id)result failure:(nullable NSError *)error;

/// 配网失败回调
/// @param active activeManager
/// @param deviceInfo deviceInfo
/// @param result result
/// @param error error
- (void)activeManager:(id<ThingBLEActiveProtocol>)active deviceInfo:(id<ThingBLEDeviceInfoProtocol>)deviceInfo activeFailRes:(nullable NSDictionary *)result failure:(nullable NSError *)error;


@end

/// 激活协议，老的方法目前因为降级的存在，暂时不能挪走，只能一并放在Core中
@protocol ThingBLEActiveProtocol <NSObject>

@optional

@property (nonatomic, weak) id<ThingBLEActiveDelegate> delegate;/// < 配网代理
@property (nonatomic, weak) id<ThingSmartBLEActiveDelegate> handlerDelegate; //!<中间过程要外部补充数据的代理
@property (nonatomic, copy) NSString *miniPairId; //!miniProgram pair id

/// 开始配网（Core）
/// @param deviceInfo   需要配网的设备
/// @param handlerDelegate 用于获取部分补充信息的代理对象
- (void)startActiveWithDevice:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
              handlerDelegate:(nullable id<ThingSmartBLEActiveDelegate>)handlerDelegate;

/// 双模配网预连接（Core）
/// @param deviceInfo   需要配网的设备
- (void)startPreActiveWithDevice:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
                         success:(nullable ThingSuccessID)success
                         failure:(nullable ThingFailureError)failure;

- (void)pairWithToken:(NSString *)token ssid:(NSString *)ssid pwd:(NSString *)pwd ;

- (void)pairWithTokenWithDevice:(id<ThingBLEDeviceInfoProtocol>)deviceInfo token:(NSString *)token ssid:(NSString *)ssid pwd:(NSString *)pwd ;

/// 开始配网（Core）
/// @param deviceInfo   需要配网的设备
/// @param ssid         路由器热点名称
/// @param passwd       路由器热点密码
/// @param token        配网Token
/// @param handlerDelegate 用于获取部分补充信息的代理对象
/// @param success 成功回调
/// @param failure 失败回调
- (void)startActiveWithDevice:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
                         ssid:(NSString *)ssid
                       passwd:(NSString *)passwd
                        token:(NSString *)token
              handlerDelegate:(id<ThingSmartBLEActiveDelegate>)handlerDelegate
                      success:(nullable ThingSuccessID)success
                      failure:(nullable ThingFailureError)failure;

/// 批量配网（Core）
/// @param deviceInfo   需要配网的设备
/// @param ssid         路由器热点名称
/// @param passwd       路由器热点密码
/// @param token        配网Token
/// @param handlerDelegate 用于获取部分补充信息的代理对象
/// @param success 成功回调
/// @param failure 失败回调
- (void)multiActiveWithDevice:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
                         ssid:(NSString *)ssid
                       passwd:(NSString *)passwd
                        token:(NSString *)token
              handlerDelegate:(id<ThingSmartBLEActiveDelegate>)handlerDelegate
                      success:(nullable ThingSuccessID)success
                      failure:(nullable ThingFailureError)failure;

/// Zigbee 双模子设备蓝牙配对（Core）
/// （包括蓝牙连接、获取子设备信息、配对操作）
/// @param deviceInfo  需要配网的设备
/// @param success     成功回调
/// @param failure     失败回调
- (void)pairZigbeeSubDeviceWithBleChannel:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
                                  success:(nullable ThingSuccessID)success
                                  failure:(nullable ThingFailureError)failure;

/// 下发网关信息给 Zigbee 双模子设备
/// @param deviceInfo  需要配网的设备
/// @param gatewayInfo  网关信息
/// @param success     成功回调
/// @param failure     失败回调
- (void)publishGatewayInfoWithBleChannel:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
                             gatewayInfo:(NSDictionary *)gatewayInfo
                                 success:(ThingSuccessBOOL)success
                                 failure:(ThingFailureError)failure;


/// 连接设备（双模、PlugPlay）（Core）
/// @param dev 需要配网的设备
/// @param success 成功回调
/// @param failure 失败回调
- (void)connectToDevice:(id<ThingBLEDeviceInfoProtocol>)dev
                success:(ThingSuccessHandler)success
                failure:(ThingFailureError)failure;


/// 兜底激活（PlugPlay）（Core）
/// @param dev 需要配网的设备
/// @param success 成功回调
/// @param failure 失败回调
- (void)activeBLEBackUp:(id<ThingBLEDeviceInfoProtocol>)dev
                  token:(NSString *)token
                success:(nullable ThingSuccessID)success
                failure:(ThingFailureError)failure;

/// 双模激活（PlugPlay）（Core）
/// @param devId 设备id
/// @param result result
/// @param ssid 路由器热点名称
/// @param password 路由器热点密码
/// @param callback 状态回调
/// @param failure 失败回调
- (void)activeDualDeviceWifiChannel:(NSString *)devId
                             result:(id)result
                               ssid:(NSString *)ssid
                           password:(NSString *)password
                        listenState:(void(^)(void))callback
                            failure:(ThingFailureError)failure;

/// 清除重连设备数据
- (void)cleanReconnectDevice:(NSString *)uuid;

/// 结束配网
- (void)stopActive;

/// Cancel the ongoing activation process.
- (void)cancelActive;

/// 下发配网信息（ble+wifi双模配网）支持多次下发配网信息
/// @param ssid The ssid of router
/// @param passwd The password of router
/// @param token The token of config
- (void)sendConfigWifiInfoWithSsid:(NSString *)ssid
                            passwd:(NSString *)passwd
                             token:(NSString *)token;

- (void)queryStateWithDevice:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
             handlerDelegate:(id<ThingSmartBLEActiveDelegate>)handlerDelegate
                     success:(nullable ThingSuccessID)success
                     failure:(nullable ThingFailureError)failure;

@end


@protocol ThingLocalBLEActiveProtocol <NSObject>

@optional

@property (nonatomic, assign) BOOL isLocalConnecting;

/// local device  connect
/// - Parameters:
///   - deviceInfo: deviceInfo
///   - success: success
///   - failure: failure
- (void)connectDevice:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
        schemaHandler:(nullable ThingSuccessDict)schemaHandler
              success:(nullable ThingSmartLocalBLEDeviceConnectedHandler)success
              failure:(nullable ThingFailureError)failure;

- (void)configMachineKey:(NSString *)machineKey;

- (void)configSchema:(NSDictionary *)schema;

- (void)receiveDevicePubKey:(NSData *)keyData;

- (void)receiveDeviceMachineKeyCheckResult:(NSData *)data;

- (void)receiveDeviceSchemaCheckResult:(NSData *)data;

- (void)receiveDeviceSchema:(NSData *)data;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingBLEActiveProtocol_h */
