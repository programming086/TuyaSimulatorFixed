//
//  TYBLEConfigProtocol.h
//  Pods
//
//  Created by 温明妍 on 2020/1/7.
//

#ifndef TYBLEConfigProtocol_h
#define TYBLEConfigProtocol_h

#import "TYBLECryptologyProtcol.h"
#import "TYBLEWriteNotifyProtocol.h"
#import "TuyaSmartBLEActiveDelegate.h"
#import "TuyaSmartBLEConfigPackageNotify.h"
#import "TuyaSmartBLEManager.h"

@protocol TYBLEDeviceInfoProtocol;
@protocol TYBLECryptologyProtcol;
@protocol TYBLEWriteNotifyProtocol;
@protocol TYBLEConfigProtocol;

typedef enum : NSUInteger {
    TYBLESubPackageStatus_AllSuccess = 0,
    TYBLESubPackageStatus_CurrentSuccess,
    TYBLESubPackageStatus_CurrentFailure,
    TYBLESubPackageStatus_Failure,
} TYBLESubPackageStatus;


@protocol TYBLEConfigProtocol <NSObject>

@property (nonatomic, weak, nullable) id<TYBLEDeviceInfoProtocol>  deviceInfo;
/// 用于对控制命令编解码
@property (nonatomic, strong, nullable) id<TYBLECryptologyProtcol> cryptologyManager;
/// 用于下发指令
@property (nonatomic, strong, nullable) id<TYBLEWriteNotifyProtocol> writeNotifyManager;

/// 中间过程要外部补充数据的代理
@property (nonatomic, weak, nullable) id<TuyaSmartBLEActiveDelegate> handlerDelegate;

/// 用于向业务层抛出收到的蓝牙包
@property (nonatomic, weak, nullable) id<TuyaSmartBLEConfigPackageNotify> packageNotify;


/// 向蓝牙设备发送控制指令
/// @param deviceInfo deviceInfo
/// @param type type
/// @param data 控制指令内容
/// @param success success
/// @param failure failure
- (void)publishCommandWithDeviceInfo:(nullable  id<TYBLEDeviceInfoProtocol>)deviceInfo
                                type:(TYBLEConfigType)type
                                data:(nullable NSData *)data
                             success:(__nullable TYSuccessData)success
                             failure:(__nullable TYFailureError)failure;



/// 向蓝牙设备发送控制指令
/// @param deviceInfo 设备信息
/// @param type 指令类型
/// @param data 控制指令内容
/// @param timeout 单条指令超时时间，若值小于等于零，则表示不支持超时
/// @param success success
/// @param failure failure
- (void)publishCommandWithDeviceInfo:(nullable id<TYBLEDeviceInfoProtocol>)deviceInfo
                                type:(TYBLEConfigType)type
                                data:(nullable NSData *)data
                             timeout:(NSTimeInterval)timeout
                             success:(__nullable TYSuccessData)success
                             failure:(__nullable TYFailureError)failure;

/// 向蓝牙设备发送 dp 点
/// @param deviceInfo deviceInfo
/// @param dps dps
/// @param success success
/// @param failure failure
- (void)publishDpsWithDeviceInfo:(nullable id<TYBLEDeviceInfoProtocol>)deviceInfo
                             dps:(nullable NSDictionary *)dps
                             success:(__nullable TYSuccessHandler)success
                             failure:(__nullable TYFailureError)failure;

///// 接收蓝牙设备上报的控制指令
///// @param deviceInfo deviceInfo
///// @param type TYBLEConfigType
///// @param data 控制指令内容
///// @param success success
///// @param failure failure
//- (void)receiveCommandWithDeviceInfo:(id<TYBLEDeviceInfoProtocol>)deviceInfo
//                                type:(TYBLEConfigType)type
//                                data:(NSData *)data
//                             success:(TYSuccessData)success
//                             failure:(TYFailureError)failure;

/// 连接设备
/// @param deviceInfo deviceInfo
/// @param localKey localKey
/// @param success success
/// @param failure failure
- (void)connectWithDeviceInfo:(nullable id<TYBLEDeviceInfoProtocol>)deviceInfo
                     localKey:(nullable NSString *)localKey
                      success:(__nullable TYSuccessHandler)success
                      failure:(__nullable TYFailureError)failure;

/// 断开连接
/// @param deviceInfo deviceInfo
/// @param success success
/// @param failure failure
- (void)disconnectWithDeviceInfo:(nullable id<TYBLEDeviceInfoProtocol>)deviceInfo
                         success:(__nullable TYSuccessHandler)success
                         failure:(__nullable TYFailureError)failure;


/// 移除设备
/// @param deviceInfo deviceInfo
/// @param success success
/// @param failure failure
- (void)removeWithDeviceInfo:(nullable id<TYBLEDeviceInfoProtocol>)deviceInfo
                     success:(__nullable TYSuccessHandler)success
                     failure:(__nullable TYFailureError)failure;

/// 恢复出厂设置
/// @param deviceInfo deviceInfo
/// @param success success
/// @param failure failure
- (void)resetWithDeviceInfo:(nullable id<TYBLEDeviceInfoProtocol>)deviceInfo
                    success:(__nullable TYSuccessHandler)success
                    failure:(__nullable TYFailureError)failure;

/// 发送OTA包，升级固件   升级前请务必保证设备已通过蓝牙连接
/// @param deviceInfo  deviceInfo
/// @param otaData     升级固件的数据
/// @param otaType     升级类型
/// @param otaVersion  升级版本
/// @param success     success
/// @param failure     failure
- (void)sendOTAPackWithDeviceInfo:(nullable id<TYBLEDeviceInfoProtocol>)deviceInfo
                          otaData:(nullable NSData *)otaData
                          otaType:(TuyaSmartBLEOTAType)otaType
                       otaVersion:(nullable NSString *)otaVersion
                          success:(__nullable TYSuccessHandler)success
                          failure:(__nullable TYFailureError)failure;

/// 发送OTA包，升级固件   升级前请务必保证设备已通过蓝牙连接
/// @param deviceInfo  deviceInfo
/// @param pid    productId
/// @param otaData     升级固件的数据
/// @param otaType     升级类型
/// @param otaVersion  升级版本
/// @param success     success
/// @param failure     failure
- (void)sendOTAPackWithDeviceInfo:(nullable id<TYBLEDeviceInfoProtocol>)deviceInfo
                              pid:(nullable NSString *)pid
                          otaData:(nullable NSData *)otaData
                          otaType:(TuyaSmartBLEOTAType)otaType
                       otaVersion:(nullable NSString *)otaVersion
                          success:(__nullable TYSuccessHandler)success
                          failure:(__nullable TYFailureError)failure;
                          
/// 强制移除设备
/// @param deviceInfo deviceInfo
/// @param success success
/// @param failure failure
- (void)forceDeleteWithDeviceInfo:(nullable id<TYBLEDeviceInfoProtocol>)deviceInfo
                          success:(__nullable TYSuccessHandler)success
                          failure:(__nullable TYFailureError)failure;


/// 发送透传数据（分包）
/// @param dev  deviceInfo
/// @param type   type
/// @param data   透传数据
/// @param success   success
/// @param failure   failure
- (void)publishIoTTransparentDataWithDeviceInfo:(nullable  id<TYBLEDeviceInfoProtocol>)dev
                                     type:(TYBLEConfigType)type
                                     data:(nullable  NSData *)data
                                  success:(__nullable TYSuccessHandler)success
                                  failure:(__nullable TYFailureError)failure;

/// 发送透传数据（可分包）
/// @param dev  deviceInfo
/// @param data   透传数据
/// @param success   success
/// @param failure   failure
- (void)publishTransparentDataWithDeviceInfo:(nullable  id<TYBLEDeviceInfoProtocol>)dev
                                     data:(nullable  NSData *)data
                                  success:(__nullable TYSuccessHandler)success
                                  failure:(__nullable TYFailureError)failure;



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
- (void)discoverServiceWithDeviceInfo:(id<TYBLEDeviceInfoProtocol>_Nullable)deviceInfo
                     localKey:(nullable NSString *)localKey
                      success:(__nullable TYSuccessHandler)success
                      failure:(__nullable TYFailureError)failure;


/// 文件传输
/// @param deviceInfo 设备 deviceInfo
/// @param fileId 文件 ID，应用层定义。
/// @param fileIdentifier 文件标识符长度。
/// @param fileVersion 文件版本，应用层定义格式。
/// @param fileData 要传输的文件数据
/// @param progressBlock 传输进度
/// @param success 成功回调
/// @param failure 失败回调
- (void)publishFileWithDeviceInfo:(nullable id<TYBLEDeviceInfoProtocol>)deviceInfo
                           fileId:(NSInteger)fileId
                   fileIdentifier:(nullable NSString *)fileIdentifier
                      fileVersion:(NSInteger)fileVersion
                         fileData:(nullable NSData *)fileData
                    progressBlock:(nullable void(^)(float progress))progressBlock
                          success:(__nullable TYSuccessHandler)success
                          failure:(__nullable TYFailureError)failure;

/// 停止文件传输
- (void)stopFileTransfer:(nullable id<TYBLEDeviceInfoProtocol>)deviceInfo;


@end

#endif /* TYBLEConfigProtocol_h */
