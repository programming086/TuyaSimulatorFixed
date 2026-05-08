
#ifndef ThingBLEConfigProtocol_h
#define ThingBLEConfigProtocol_h

#import "ThingBLECryptologyProtcol.h"
#import "ThingBLEWriteNotifyProtocol.h"
#import "ThingSmartBLEActiveDelegate.h"
#import "ThingSmartBLEConfigPackageNotify.h"
#import "ThingSmartBLEManager.h"

@protocol ThingBLEDeviceInfoProtocol;
@protocol ThingBLECryptologyProtcol;
@protocol ThingBLEWriteNotifyProtocol;
@protocol ThingBLEConfigProtocol;

typedef enum : NSUInteger {
    ThingBLESubPackageStatus_AllSuccess = 0,
    ThingBLESubPackageStatus_CurrentSuccess,
    ThingBLESubPackageStatus_CurrentFailure,
    ThingBLESubPackageStatus_Failure,
} ThingBLESubPackageStatus;


@protocol ThingBLEConfigProtocol <NSObject>

@property (nonatomic, weak, nullable) id<ThingBLEDeviceInfoProtocol>  deviceInfo;
/// 用于对控制命令编解码
@property (nonatomic, strong, nullable) id<ThingBLECryptologyProtcol> cryptologyManager;
/// 用于下发指令
@property (nonatomic, strong, nullable) id<ThingBLEWriteNotifyProtocol> writeNotifyManager;

/// 中间过程要外部补充数据的代理
@property (nonatomic, weak, nullable) id<ThingSmartBLEActiveDelegate> handlerDelegate;

/// 用于向业务层抛出收到的蓝牙包
@property (nonatomic, weak, nullable) id<ThingSmartBLEConfigPackageNotify> packageNotify;

- (void)cancelActiveTimer;

/// 向蓝牙设备发送控制指令
/// @param deviceInfo deviceInfo
/// @param type type
/// @param data 控制指令内容
/// @param success success
/// @param failure failure
- (void)publishCommandWithDeviceInfo:(nullable  id<ThingBLEDeviceInfoProtocol>)deviceInfo
                                type:(ThingBLEConfigType)type
                                data:(nullable NSData *)data
                             success:(__nullable ThingSuccessData)success
                             failure:(__nullable ThingFailureError)failure;



/// 向蓝牙设备发送控制指令
/// @param deviceInfo 设备信息
/// @param type 指令类型
/// @param data 控制指令内容
/// @param timeout 单条指令超时时间，若值小于等于零，则表示不支持超时
/// @param success success
/// @param failure failure
- (void)publishCommandWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                                type:(ThingBLEConfigType)type
                                data:(nullable NSData *)data
                             timeout:(NSTimeInterval)timeout
                             success:(__nullable ThingSuccessData)success
                             failure:(__nullable ThingFailureError)failure;

- (void)publishCommandWithDeviceInfo:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
                                type:(ThingBLEConfigType)type
                                data:(NSData *)data
                             timeout:(NSTimeInterval)timeout
                             needAck:(BOOL)needAck
                             success:(ThingSuccessData)success
                             failure:(ThingFailureError)failure;

/// 向蓝牙设备发送 dp 点
/// @param deviceInfo deviceInfo
/// @param dps dps
/// @param success success
/// @param failure failure
- (void)publishDpsWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                             dps:(nullable NSDictionary *)dps
                        success:(__nullable ThingSuccessHandler)success
                        failure:(__nullable ThingFailureError)failure;

/// 通过父节点向子设备发dp点
/// @param deviceInfo deviceInfo
/// @param childNodeId child device id
/// @param dps dps
/// @param success success
/// @param failure failure
- (void)publishDpsWithDeviceInfo:(id<ThingBLEDeviceInfoProtocol>_Nullable)deviceInfo
                     childNodeId:(nullable NSString *)childNodeId
                             dps:(nullable NSDictionary *)dps
                         success:(__nullable ThingSuccessHandler )success
                         failure:(__nullable ThingFailureError)failure DEPRECATED_MSG_ATTRIBUTE("use `publishDpsWithDeviceInfo:childNodeId:secType:dps:success:failure` instead");

/// 通过父节点向子设备发dp点
/// @param deviceInfo deviceInfo
/// @param childNodeId child device id
/// @param secType 1.fitting 2.masterSlave
/// @param dps dps
/// @param success success
/// @param failure failure
- (void)publishDpsWithDeviceInfo:(id<ThingBLEDeviceInfoProtocol>_Nullable)deviceInfo
                     childNodeId:(nullable NSString *)childNodeId
                        secType:(NSInteger)secType
                             dps:(nullable NSDictionary *)dps
                         success:(__nullable ThingSuccessHandler)success
                         failure:(__nullable ThingFailureError)failure;

/// 下发查询 dps 状态指令（0x0003 / 0x0004 / 0x801E^0x000E）
/// @param deviceInfo deviceInfo
/// @param success success
/// @param failure failure
- (void)publishDpsStateQueryWithDeviceInfo:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
                                     dpIds:(nullable NSArray *)dpIds
                                   success:(ThingSuccessBOOL)success
                                   failure:(ThingFailureError)failure;

/// 通过透传通道下发 dps（需设备支持，0x801E^0x000C）
/// @param deviceInfo deviceInfo
/// @param dps dps
/// @param success success
/// @param failure failure
- (void)publishDpsUseTransportPipeWithDeviceInfo:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
                                             dps:(NSDictionary *)dps
                                         success:(ThingSuccessHandler)success
                                         failure:(ThingFailureError)failure;

- (nullable NSDictionary *)dpsWithDeviceInfo:(id<ThingBLEDeviceInfoProtocol>_Nullable)deviceInfo
                                     dpsData:(nullable NSData *)dpsData
                             isFittingDevice:(BOOL)isFittingDevice;

///// 接收蓝牙设备上报的控制指令
///// @param deviceInfo deviceInfo
///// @param type ThingBLEConfigType
///// @param data 控制指令内容
///// @param success success
///// @param failure failure
//- (void)receiveCommandWithDeviceInfo:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
//                                type:(ThingBLEConfigType)type
//                                data:(NSData *)data
//                             success:(ThingSuccessData)success
//                             failure:(ThingFailureError)failure;

- (void)connectWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                     localKey:(nullable NSString *)localKey
                      success:(__nullable ThingSuccessHandler)success
                      failure:(__nullable ThingFailureError)failure __deprecated_msg("Use connectWithDeviceInfo:localKey:secKey:sign:success:failure:] instead.");

/// 连接设备
/// @param deviceInfo deviceInfo
/// @param localKey localKey
/// @param success success
/// @param failure failure
/// @param secKey secret Key
- (void)connectWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                     localKey:(nullable NSString *)localKey
                       secKey:(nullable NSString *)secKey
                         sign:(nullable NSString *)sign
                      success:(__nullable ThingSuccessHandler)success
                      failure:(__nullable ThingFailureError)failure;



/// 断开连接
/// @param deviceInfo deviceInfo
/// @param success success
/// @param failure failure
- (void)disconnectWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                         success:(__nullable ThingSuccessHandler)success
                         failure:(__nullable ThingFailureError)failure;


/// 移除设备
/// @param deviceInfo deviceInfo
/// @param success success
/// @param failure failure
- (void)removeWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                     success:(__nullable ThingSuccessHandler)success
                     failure:(__nullable ThingFailureError)failure;

/// 恢复出厂设置
/// @param deviceInfo deviceInfo
/// @param success success
/// @param failure failure
- (void)resetWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                    success:(__nullable ThingSuccessHandler)success
                    failure:(__nullable ThingFailureError)failure;

/// 发送OTA包，升级固件   升级前请务必保证设备已通过蓝牙连接
/// @param deviceInfo  deviceInfo
/// @param otaData     升级固件的数据
/// @param otaType     升级类型
/// @param otaVersion  升级版本
/// @param success     success
/// @param failure     failure
- (void)sendOTAPackWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                          otaData:(nullable NSData *)otaData
                          otaType:(ThingSmartBLEOTAType)otaType
                       otaVersion:(nullable NSString *)otaVersion
                          success:(__nullable ThingSuccessHandler)success
                          failure:(__nullable ThingFailureError)failure;

/// 给配件发送OTA包，升级前务必保证设备已经蓝牙连接
/// @param deviceInfo 广播对象
/// @param childNodeId  子设备 node Id
/// @param childPid  子设备 pid
/// @param otaData 升级固件数据
/// @param otaType otaType
/// @param otaVersion 升级版本
/// @param success success
/// @param failure failure

- (void)sendOTAPackWithDeviceInfo:(id<ThingBLEDeviceInfoProtocol>)deviceInfo
                       childNodeId:(NSString *)childNodeId
                         childPid:(NSString *)childPid
                       childDevid:(NSString *)devId
                          otaData:(NSData *)otaData
                          otaType:(ThingSmartBLEOTAType)otaType
                       otaVersion:(NSString *)otaVersion
                          success:(ThingSuccessHandler)success
                          failure:(ThingFailureError)failure;

/// 发送OTA包，升级固件   升级前请务必保证设备已通过蓝牙连接
/// @param deviceInfo  deviceInfo
/// @param pid    productId
/// @param otaData     升级固件的数据
/// @param otaType     升级类型
/// @param otaVersion  升级版本
/// @param success     success
/// @param failure     failure
- (void)sendOTAPackWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                              pid:(nullable NSString *)pid
                          otaData:(nullable NSData *)otaData
                          otaType:(ThingSmartBLEOTAType)otaType
                       otaVersion:(nullable NSString *)otaVersion
                          success:(__nullable ThingSuccessHandler)success
                          failure:(__nullable ThingFailureError)failure;


/// 扫码解绑
/// @param deviceInfo deviceInfo
/// @param random random
/// @param resetKey resetKey
/// @param success success
/// @param failure failure
- (void)resetDeviceWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                           random:(nullable NSString *)random
                         resetKey:(nullable NSString *)resetKey
                          success:(__nullable ThingSuccessHandler)success
                          failure:(__nullable ThingFailureError)failure;


/// 强制移除设备
/// @param deviceInfo deviceInfo
/// @param success success
/// @param failure failure
- (void)forceDeleteWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                          success:(__nullable ThingSuccessHandler)success
                          failure:(__nullable ThingFailureError)failure;


/// 发送透传数据（分包）
/// @param dev  deviceInfo
/// @param type   type
/// @param data   透传数据
/// @param success   success
/// @param failure   failure
- (void)publishIoTTransparentDataWithDeviceInfo:(nullable  id<ThingBLEDeviceInfoProtocol>)dev
                                     type:(ThingBLEConfigType)type
                                     data:(nullable  NSData *)data
                                  success:(__nullable ThingSuccessHandler)success
                                  failure:(__nullable ThingFailureError)failure;

/// 发送透传数据（可分包）
/// @param dev  deviceInfo
/// @param data   透传数据
/// @param success   success
/// @param failure   failure
- (void)publishTransparentDataWithDeviceInfo:(nullable  id<ThingBLEDeviceInfoProtocol>)dev
                                     data:(nullable  NSData *)data
                                  success:(__nullable ThingSuccessHandler)success
                                  failure:(__nullable ThingFailureError)failure;



/// 处理 dp 上报
- (void)handleDpData:(nullable NSData *)data
             ackData:(nullable NSData *)ackData
                type:(int)type
             dpsTime:(nullable NSString *)dpsTime
          reportMode:(NSUInteger)mode;

/// 处理带时间戳的 dp 上报
- (void)handleDPTimeRequest:(nullable NSString *)dataHexString
                    ackData:(nullable NSData *)ackData
            withCommandType:(int)type
                 reportMode:(NSUInteger)mode;


/// IoT数据通道
- (void)handleIoTTransparentData:(nullable NSData *)data
                    businessData:(nullable NSData *)businessData;


- (void)handleTransparentData:(nullable NSData *)data;



/// 处理link 加密
/// @param isLinkEncrypt link enctypt
- (void)handleDeviceLinkEncryptState:(Boolean)isLinkEncrypt;

/// 重新发现服务
/// @param deviceInfo deviceInfo
/// @param localKey localKey
/// @param success success
/// @param failure failure
- (void)discoverServiceWithDeviceInfo:(id<ThingBLEDeviceInfoProtocol>_Nullable)deviceInfo
                     localKey:(nullable NSString *)localKey
                      success:(__nullable ThingSuccessHandler)success
                      failure:(__nullable ThingFailureError)failure;


/// 文件传输
/// @param deviceInfo 设备 deviceInfo
/// @param fileId 文件 ID，应用层定义。
/// @param fileIdentifier 文件标识符长度。
/// @param fileVersion 文件版本，应用层定义格式。
/// @param fileData 要传输的文件数据
/// @param progressBlock 传输进度
/// @param success 成功回调
/// @param failure 失败回调
- (void)publishFileWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                           fileId:(NSInteger)fileId
                   fileIdentifier:(nullable NSString *)fileIdentifier
                      fileVersion:(NSInteger)fileVersion
                         fileData:(nullable NSData *)fileData
                    progressBlock:(nullable void(^)(float progress))progressBlock
                          success:(nullable ThingSuccessHandler)success
                          failure:(nullable ThingFailureError)failure;

/// 文件传输
/// @param deviceInfo 设备 deviceInfo
/// @param fileId 文件 ID，应用层定义。
/// @param fileIdentifier 文件标识符长度。
/// @param fileVersion 文件版本，应用层定义格式。
/// @param fileData 要传输的文件数据
/// @param fileType 要传输的文件类型，默认为0
/// @param progressBlock 传输进度
/// @param success 成功回调
/// @param failure 失败回调
- (void)publishFileWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
                           fileId:(NSInteger)fileId
                   fileIdentifier:(nullable NSString *)fileIdentifier
                      fileVersion:(NSInteger)fileVersion
                         fileData:(nullable NSData *)fileData
                         fileType:(unsigned int)fileType
                    progressBlock:(nullable void(^)(float progress))progressBlock
                          success:(nullable ThingSuccessHandler)success
                          failure:(nullable ThingFailureError)failure;

/// 停止文件传输

- (void)stopFileTransfer:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo;

- (void)stopFileTransfer:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo;


//reset all parameters
- (void)resetAllparameters;


//combo wifi透传通道下行数据透传
- (void)publishWifiTransportDataWithDeviceInfo:(nullable id<ThingBLEDeviceInfoProtocol>)dev
                                          data:(nullable NSData *)data
                                       success:(nullable ThingSuccessHandler)success
                                       failure:(nullable ThingFailureError)failure;
////combo wifi透传通道上行数据透传处理
//- (void)handleComboWifiTransportData:(NSData *)businessData;


/// handle fitting device with time
/// @param data business data not contain time
/// @param fitttingDevId fitting devid
/// @param ackData ack data
/// @param type type
/// @param dpsTime dpsTime
/// @param mode model
- (void)handleDpData:(nullable NSData *)data
        fittingDevId:(nullable NSString *)fitttingDevId
             ackData:(nullable NSData *)ackData
                type:(int)type
             dpsTime:(nullable NSString *)dpsTime
          reportMode:(NSUInteger)mode;


/// handle fitting device  time and data contain time
/// @param data data contain time
/// @param fitttingDevId fitting devid
/// @param ackData ack data
/// @param type type
/// @param dpsTime dpsTime
/// @param mode model
- (void)handleDpWithTimeData:(nullable NSData *)data
                fittingDevId:(nullable NSString *)fitttingDevId
                     ackData:(nullable NSData *)ackData
                        type:(int)type
                     dpsTime:(nullable NSString *)dpsTime
                  reportMode:(NSUInteger)mode;

- (void)queryFittingInfo:(nullable id<ThingBLEDeviceInfoProtocol>)deviceInfo
             activeQuery:(BOOL)isActive
                 success:(nullable ThingSuccessData)success
                 failure:(nullable ThingFailureError)failure;

- (void)publishSplitCommandWithDeviceInfo:(id<ThingBLEDeviceInfoProtocol>)dev
                                     type:(ThingBLEConfigType)type
                                     head:(NSData *)head
                                     data:(NSData *)data
                                  success:(ThingSuccessHandler)success
                                  failure:(ThingFailureError)failure;

@end

#endif /* ThingBLEConfigProtocol_h */
