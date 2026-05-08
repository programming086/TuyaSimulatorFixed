//
// TuyaSmartBLEManager.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import "TYBLEAdvModel.h"
#import "TYBLEWeatherModel.h"
#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import "TYBLEDeviceInfoProtocol.h"
#import "TYBLEFindMacDelegate.h"
#import "TuyaSmartBLEAudioStartModel.h"
#import "TuyaSmartBLEAudioManager.h"

typedef enum : NSUInteger {
    /// Is OTA controllable.
    TuyaSmartBLECapabilityOTAControlled = 0,
    TuyaSmartBLECapabilityLELogitify = 1,
    TuyaSmartBLECapabilityBeaconable = 2,
    TuyaSmartBLECapabilityLink = 3,
    TuyaSmartBLECapabilityExtenModule = 4,
} TuyaSmartBLECapability;


typedef NS_ENUM(NSInteger,TYBLEScanType){
    TYBLEScanTypeNoraml = 1 << 0, //  0001  1
    TYBLEScanTypeQRCode = 1 << 1, //  0010  2
};

NS_ASSUME_NONNULL_BEGIN

typedef void (^TYBLEBigDataProgressBlock)(float progress);

@class TuyaSmartBLEManager;
@class TYBLEWeatherModel;
@class TuyaSmartDeviceModel;

/// The delegate for scanning and notifications of Bluetooth status changes.
@protocol TuyaSmartBLEManagerDelegate <NSObject>

@optional

/// The notification for Bluetooth status changes.
///
/// @param isPoweredOn      Indicates the Bluetooth status. Valid values: `on` and `off`.
- (void)bluetoothDidUpdateState:(BOOL)isPoweredOn;

/// The result of disconnecting the device.
///
/// @param devId        The device ID.
/// @param error        An error occurs while processing the request.
- (void)onCentralDidDisconnectFromDevice:(NSString *)devId error:(NSError *)error;

/// The result of scanning inactive devices.
///
/// @param uuid         The device UUID.
/// @param productKey   The product ID for the device.
/// @deprecated This method is deprecated. Use TuyaSmartBLEManager::didDiscoveryDeviceWithDeviceInfo: instead.
- (void)didDiscoveryDeviceWithUUID:(NSString *)uuid productKey:(NSString *)productKey __deprecated_msg("This method is deprecated, Use TuyaSmartBLEManager::didDiscoveryDeviceWithDeviceInfo: instead");

/// The result of scanning inactive devices.
///
/// @param deviceInfo   The advertisingData model for the inactive device.
- (void)didDiscoveryDeviceWithDeviceInfo:(TYBLEAdvModel *)deviceInfo;

/// The result of activating Bluetooth LE devices.
///
/// @param manager          The class.
/// @param deviceModel      Called when the task is finished. DeviceModel is returned.
/// @param error            Called when the task is interrupted by an error.
- (void)bleManager:(TuyaSmartBLEManager *)manager didFinishActivateDevice:(nullable id)deviceModel error:(nullable NSError *)error;

/// Receives the transmission data from the device.
///
/// @param data     Transmission data that is sent by the device.
/// @param devId    The device ID.
- (void)bleReceiveTransparentData:(NSData *)data devId:(NSString *)devId;


/// Get weather information
/// @param devId  The device ID.
/// @param codes  codes
/// @param whetherUse Whether to request weather information using location information
/// @param completion completion
- (void)getWeatherWithDevId:(NSString *)devId codes:(NSString *)codes useLocation:(BOOL)whetherUse completion:(void(^)(TYBLEWeatherModel * _Nullable weatherModel))completion __deprecated_msg("This method is deprecated, Use newGetWeatherWithDevId:codes:useLocation:completion: instead");

- (void)newGetWeatherWithDevId:(NSString *)devId codes:(NSString *)codes useLocation:(BOOL)whetherUse completion:(void(^)(NSDictionary * _Nullable weatherData))completion;


/// Data source for the device list
- (NSArray <TuyaSmartDeviceModel *>*)bleManagerDeviceListDataSource;

@end

@protocol TuyaSmartBLELocalDataDelegate <NSObject>

@optional

/// Localized data storage
/// @param devId The device ID
/// @param dps dps
- (NSDictionary *)filterUploadServerData:(NSString *)devId dps:(NSDictionary *)dps __deprecated_msg("This method is deprecated, Use filterUploadServerData:dps:dpsTime: instead");

/// According to the scene, the dps and dpsTime will be transparently transmitted and processed and returned
/// @param devId The device ID
/// @param dps  dps
/// @param dpstime dps time
- (NSDictionary *)filterUploadServerData:(NSString *)devId dps:(NSDictionary *)dps dpsTime:(NSString *)dpstime;

/// Do you need to report big data to the app?
/// @param devId The device ID.
- (BOOL)isBigDataReportApp:(NSString *)devId;

/// Big data reported.
/// @param dic Big data content.
- (void)reportBigDataChannelDic:(NSDictionary *)dic;


@end

@protocol TuyaSmartBLEAlexaAudioDelegate <NSObject>

@optional

- (void)audioStartSpeech:(TuyaSmartBLEAudioStartModel *)model;

- (void)audioProvideSpeech:(TuyaSmartBLEAudioProvideModel *)model;

- (void)audioStopSpeech:(NSString *)dialogId deviceId:(NSString *)deviceId errorCode:(TYAudioErrorCode)error;

- (void)audioData:(NSData *)data deviceId:(NSString *)deviceId audioFormat:(TYAudioAudioFormat)audioFormat;


@end

/// @brief TuyaSmartBLEManager provides methods to manage Bluetooth LE devices by using multiple functions, such as activation, device control, and OTA updates.
///
/// The types of OTA updates: firmware and MCU.
@interface TuyaSmartBLEManager : NSObject

/// The single instance.
+ (instancetype)sharedInstance;

/// A Boolean value that indicates whether the mobile phone's Bluetooth is enabled or disabled.
@property (nonatomic, assign, readonly) BOOL isPoweredOn;

/// Whether to disable bluetooth. Default NO
@property (nonatomic, assign) BOOL disableBLECapability;

/// The delegate for scanning and notifications of Bluetooth status changes.
@property (nonatomic, weak) id<TuyaSmartBLEManagerDelegate> delegate;

@property (nonatomic, weak) id<TuyaSmartBLELocalDataDelegate> localDataDelegate;

@property (nonatomic, weak) id<TuyaSmartBLEAlexaAudioDelegate> alexaAudioDelegate;

// support mac for device
@property (nonatomic, weak) id<TYBLEFindMacDelegate> findMacDelegatel;

@property (nonatomic, copy) TYFailureHandler failureHandler;

typedef void (^TYBLEScanHandler)(id<TYBLEDeviceInfoProtocol> devInfo, BOOL isWillRestoreState);

@property (nonatomic, copy) void (^success)(id deviceModel);


//记录当前会话的
@property (nonatomic, copy) NSString *currentDialogId;

@property (nonatomic, strong) NSMutableDictionary *resultDic;


//扫描回调作为属性，不要每次声明
@property (nonatomic, strong) TYBLEScanHandler scanHandler;




- (BOOL)checkBLEStatus;


/// 开始设备扫描
/// @param cache 是否清理已扫描到的设备
/// @param handler 设备扫描之后需要处理的业务功能
/// @param notify 接收蓝牙业务回调
/// @param scanType 扫描类型
- (void)startListenCore:(BOOL)cache
                handler:(nullable TYBLEScanHandler)handler
           configNotify:(id<TuyaSmartBLEConfigPackageNotify>)notify
               scanType:(TYBLEScanType)scanType;

/// Ble device scan with time out
/// @param interval timeout
/// @param scanHandle 设备扫描之后需要处理的业务功能
/// @param finishHandle failure description
- (void)startScanWithInterval:(NSTimeInterval)interval
                 scanHandler:(TYBLEScanHandler)scanHandle
                finishHandler:(TYSuccessHandler)finishHandle;

- (void)stopListenCore:(BOOL)clearCache;

- (void)setScanDelegate:(id)delegate __deprecated_msg("This method is deprecated, the scan delegate is already set at initialization time");

- (void)connectWithDeviceInfo:(id<TYBLEDeviceInfoProtocol>)deviceInfo localKey:(NSString *)localKey;

- (void)forceDeleteWithDeviceInfo:(id<TYBLEDeviceInfoProtocol>)deviceInfo success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;

- (void)connectWithUUID:(NSString *)uuid
             capability:(NSUInteger)capability
              productId:(NSString *)productId
               localKey:(NSString *)localKey
            configMetas:(NSDictionary *)configMetas
        handlerDelegate:(id<TuyaSmartBLEActiveDelegate>)handlerDelegate
            scanHandler:(nullable TYBLEScanHandler)handler
                success:(nullable TYSuccessHandler)success
                failure:(nullable TYFailureHandler)failure __deprecated_msg("This method is deprecated, Use connectWithDeviceInfo:capability:productId:localKey:configMetas:handlerDelegate:scanHandler:success:failure: instead");;

- (void)connectWithDeviceInfo:(id<TYBLEDeviceInfoProtocol>)deviceInfo
                   capability:(NSUInteger)capability
                    productId:(NSString *)productId
                     localKey:(NSString *)localKey
                  configMetas:(NSDictionary *)configMetas
              handlerDelegate:(id<TuyaSmartBLEActiveDelegate>)handlerDelegate
                  scanHandler:(nullable TYBLEScanHandler)scanHandler
                      success:(nullable TYSuccessHandler)success
                      failure:(nullable TYFailureHandler)failure;

/// Disconnect device
///
/// @param uuid         The UUID for the device.
/// @param success      When disconnect successfully, this block will be called success.
/// @param failure      This block will be called if some error occurred.
- (void)disconnectWithUUID:(NSString *)uuid
                   success:(nullable TYSuccessHandler)success
                   failure:(nullable TYFailureError)failure __deprecated_msg("This method is deprecated, Use disconnectWithDeviceInfo:success:failure: instead");

/// Disconnect device
///
/// @param deviceInfo        The deviceInfo.
/// @param success              When disconnect successfully, this block will be called success.
/// @param failure              This block will be called if some error occurred.
- (void)disconnectWithDeviceInfo:(id<TYBLEDeviceInfoProtocol>)deviceInfo
                         success:(nullable TYSuccessHandler)success
                         failure:(nullable TYFailureError)failure;

/// Active device
- (void)activeBLEWithDevice:(id<TYBLEDeviceInfoProtocol>)deviceInfo
            handlerDelegate:(id<TuyaSmartBLEActiveDelegate>)handlerDelegate;

/// Publish the transmitted data.
///
/// @param uuid         The UUID for the device.
/// @param data         Data to be transmitted to the device.
/// @param success      Transmission data returned by the device.
/// @param failure      This block will be called if some error occurred.
- (void)publishBleTransparentDataWithUUID:(NSString *)uuid
                                     data:(NSData *)data
                                  success:(nullable TYSuccessData)success
                                  failure:(nullable TYFailureError)failure __deprecated_msg("This method is deprecated, Use publishBleTransparentDataWithDeviceInfo:data:success:failure: instead");

/// Publish the transmitted data.
///
/// @param deviceInfo        The deviceInfo.
/// @param data         Data to be transmitted to the device.
/// @param success      Transmission data returned by the device.
/// @param failure      This block will be called if some error occurred.
- (void)publishBleTransparentDataWithDeviceInfo:(id<TYBLEDeviceInfoProtocol>)deviceInfo
                                           data:(NSData *)data
                                        success:(nullable TYSuccessData)success
                                        failure:(nullable TYFailureError)failure;

/// Query device dp data by Bluetooth channel.
///
/// @param uuid             The UUID for the device.
/// @param dpsData      Array of dpId's to be queried.
/// @param success      When query successfully, this block will be called.
/// @param failure      This block will be called if some error occurred.
- (void)publishQueryDpCommandWithUUID:(NSString *)uuid
                              dpsData:(NSMutableData *)dpsData
                              success:(nullable TYSuccessBOOL)success
                              failure:(nullable TYFailureError)failure __deprecated_msg("This method is deprecated, Use publishQueryDpCommandWithDeviceInfo:dpsData:success:failure: instead");


/// Query device dp data by Bluetooth channel.
///
/// @param deviceInfo        The deviceInfo.
/// @param dpsData      Array of dpId's to be queried.
/// @param success      When query successfully, this block will be called.
/// @param failure      This block will be called if some error occurred.
- (void)publishQueryDpCommandWithDeviceInfo:(id<TYBLEDeviceInfoProtocol>)deviceInfo
                                    dpsData:(NSMutableData *)dpsData
                                    success:(nullable TYSuccessBOOL)success
                                    failure:(nullable TYFailureError)failure;

/// Get Bluetooth device capability value.This method is used to analyze the Bluetooth capability of the device.
/// @param i Enumeration value of Bluetooth capability to be obtained
/// @param hex The ability to analyze
- (BOOL)bleCapabilityIsSupport:(TuyaSmartBLECapability)i hex:(NSString *)hex;


- (void)sendPacketInfoWithDev:(id<TYBLEDeviceInfoProtocol>)dev
                         data:(NSData *)data
                         type:(TYBLEConfigType)type
               packageMaxSize:(NSInteger)maxSize
                      success:(nullable TYSuccessHandler)success
                      failure:(nullable TYFailureError)failure;

- (BOOL)pairBLEAdvertisingData:(NSData *)advertisingData;




@end

NS_ASSUME_NONNULL_END
