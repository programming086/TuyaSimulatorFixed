//
//  TuyaSmartBLEManager+Biz.h
//  TuyaSmartBLEKit
//
//  Created by yuguo on 2021/3/26.
//

#import <TuyaSmartBLEKit/TuyaSmartBLEKit.h>
#import <TuyaSmartBLECoreKit/TuyaSmartBLEManager.h>
#import <TuyaSmartBLEKit/TuyaSmartExtModuleManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBLEManager (Biz)

#define  kNotificationSharedListUpdate          @"kNotificationSharedListUpdate"

/// Starts listening for broadcast packages for Bluetooth LE devices.
///
/// If an inactive device is scanned, the device information is returned by `TuyaSmartBLEManagerDelegate::didDiscoveryDeviceWithDeviceInfo:`.
///
/// If an active device is scanned, the device is automatically connected.
///
/// @param clearCache Specifies whether to clean up the broadcast packets of scanned devices.
- (void)startListening:(BOOL)clearCache;

/// Starts listening for broadcast packages for Bluetooth LE devices.
///
/// If an inactive device is scanned, the device information is returned by `TuyaSmartBLEManagerDelegate::didDiscoveryDeviceWithDeviceInfo:`.
///
/// If an active device is scanned, the device is automatically connected.
/// @param scanType  Specifies whether to scan type. Noraml type is general device. QRCode type is supports code scanning devices.
/// @param clearCache Specifies whether to clean up the broadcast packets of scanned devices.
- (void)startListeningWithType:(TYBLEScanType)scanType cacheStatu:(BOOL)clearCache;

/// Starts listening for broadcast packages for active Bluetooth LE devices during interval
/// @param interval scan time.If interval < 0, set it to the default 40s
/// @param scanHandle called when find ble device broadcast,return devId of find device
/// @param finishHandle  called when the task is finished
- (void)scanActivatedDeviceWithTimeInterval:(NSTimeInterval)interval
                                scanHandler:(TYSuccessString)scanHandle
                              finishHandler:(TYSuccessHandler)finishHandle;

/// Stop listening for broadcast packages for BLE devices.
///
/// @param clearCache Specifies whether to clean up the broadcast packets of scanned devices.
- (void)stopListening:(BOOL)clearCache;

/// Connects to a device.
///
/// @param uuid         The UUID of the device.
/// @param productKey   The product ID of the device.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)connectBLEWithUUID:(NSString *)uuid
                productKey:(NSString *)productKey
                   success:(nullable TYSuccessHandler)success
                   failure:(nullable TYFailureHandler)failure;



/// Disconnects a device.
///
/// @param uuid         The UUID of the device.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)disconnectBLEWithUUID:(NSString *)uuid
                      success:(nullable TYSuccessHandler)success
                      failure:(nullable TYFailureError)failure;



/// Activates the Bluetooth LE device.
/// @param uuid The UUID of the device.
/// @param homeId The ID of the current home.
/// @param productKey The product ID of the device.
/// @param success Called when the task is finished. DeviceModel is returned.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated. Use TuyaSmartBLEManager::activeBLE:homeId:success:failure: instead.
- (void)activeBLEWithUUID:(NSString *)uuid
                   homeId:(long long)homeId
               productKey:(NSString *)productKey
                  success:(nullable void(^)(TuyaSmartDeviceModel *deviceModel))success
                  failure:(nullable TYFailureHandler)failure __deprecated_msg("This method is deprecated, Use TuyaSmartBLEManager::activeBLE:homeId:success:failure instead");

/// Activates the Bluetooth LE device.
///
/// @param deviceInfo       The advertisingData model for the Bluetooth LE device.
/// @param homeId           The ID for the current home.
/// @param success          Called when the task is finished. DeviceModel is returned.
/// @param failure          Called when the task is interrupted by an error.
- (void)activeBLE:(TYBLEAdvModel *)deviceInfo
           homeId:(long long)homeId
          success:(nullable void(^)(TuyaSmartDeviceModel *deviceModel))success
          failure:(nullable TYFailureHandler)failure;

/// Publishes the transmitted data.
///
/// @param devId        The device ID.
/// @param data         The data to be transmitted to the device.
/// @param success      The data that is returned by the device.
/// @param failure      Called when the task is interrupted by an error.
- (void)publishBleTransparentData:(NSString *)devId
                             data:(NSData *)data
                          success:(nullable TYSuccessData)success
                          failure:(nullable TYFailureError)failure;

/// Queries the device DP data through Bluetooth channels.
///
/// @param devId        The device ID.
/// @param dpIds        The array of DP IDs to be queried.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)publishQueryDpCommand:(NSString *)devId
                        dpIds:(NSArray *)dpIds
                      success:(nullable TYSuccessBOOL)success
                      failure:(nullable TYFailureError)failure;

/// Returns the RSSI value of the Bluetooth LE device.
///
/// @param uuid        The UUID of the device.
///
/// @return The RSSI value of the Bluetooth LE device.
- (NSInteger)getPeripheralRSSI:(NSString *)uuid;

/// Returns the local connection status of the Bluetooth LE device by device UUID.
///
/// @param uuid        The UUID of the device.
///
/// @return The local connection status of the Bluetooth LE device.
- (BOOL)deviceStatueWithUUID:(NSString *)uuid;

/// Queries the device information before the activation.
///
/// @param uuid         The UUID of the device.
/// @param productKey   The product ID for the device.
/// @param success      Called when the task is finished. The device name string is returned.
/// @param failure      Called when the task is interrupted by an error.
///
/// @deprecated This method is deprecated. Use TuyaSmartBLEManager::queryDeviceInfoWithUUID:productKey:success:failure: instead.
- (void)queryNameWithUUID:(NSString *)uuid
               productKey:(NSString *)productKey
                  success:(nullable void(^)(NSString *name))success
                  failure:(nullable TYFailureError)failure __deprecated_msg("This method is deprecated, Use TuyaSmartBLEManager::queryDeviceInfoWithUUID:productKey:success:failure instead");

/// Queries the device information before activation
///
/// @param uuid         The UUID of the device.
/// @param productId    The product ID for the device.
/// @param success      Called when the task is finished. A dictionary of device information is returned.
/// @param failure      Called when the task is interrupted by an error.
- (void)queryDeviceInfoWithUUID:(NSString *)uuid
                      productId:(NSString *)productId
                        success:(nullable TYSuccessDict)success
                        failure:(nullable TYFailureError)failure;

/// Publish  data  to the BLE device   eg: scene data
/// @param data   data
/// @param devId   The device Id for the device.
/// @param success   When publish successfully, this block will be called success.
/// @param failure   This block will be called if some error occurred.
- (void)publishIoTTransparentData:(NSData *)data
                            devId:(NSString *)devId
                          success:(nullable TYSuccessHandler)success
                          failure:(nullable TYFailureError)failure;

/// Get device capability through Bluetooth channel.
/// @param uuid The device uuid.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)getBLECapabilityWithUUID:(NSString *)uuid
                         success:(nullable TYSuccessString)success
                         failure:(nullable TYFailureError)failure;

/// Get whether Bluetooth is currently being OTA upgraded.
/// @param uuid The device uuid.
- (BOOL)otaUpgradeStatusWithUUID:(NSString *)uuid;


/// start ble beacon scan,the dp data will be reported if scanned.
/// The data of all ble beacon devices in the current account will be scanned.
- (void)startBleBeaconListening;

/// stop ble beacon scan
- (void)stopBleBeaconListening;

/// start ble beacon scan
/// @param deviceId The device id
- (void)startBleBeaconListeningWithDeviceId:(NSString *)deviceId;

/// stop ble beacon scan
/// @param deviceId The device id
- (void)stopBleBeaconListeningWithDeviceId:(NSString *)deviceId;



/// Activates the Bluetooth LE device.
///
/// @param advertisingData      The advertisingData model for the Bluetooth LE device.
/// @param homeId                          The ID for the current home.
/// @param success                        Called when the task is finished. DeviceModel is returned.
/// @param failure                        Called when the task is interrupted by an error.
- (void)activeBLEWithAdvertisingData:(NSData *)advertisingData
                              homeId:(long long)homeId
                             success:(void(^)(TuyaSmartDeviceModel *deviceModel))success
                             failure:(TYFailureHandler)failure;

/// File transfer
/// @param devId The device ID.
/// @param fileId The file ID.
/// @param fileIdentifier The file identifier.
/// @param fileVersion The file version.
/// @param fileData The file data.
/// @param progressBlock The progress callback
/// @param success Called when the task is finished. DeviceModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)publishFileWithDevId:(NSString *)devId
                      fileId:(NSInteger)fileId
              fileIdentifier:(NSString *)fileIdentifier
                 fileVersion:(NSInteger)fileVersion
                    fileData:(NSData *)fileData
               progressBlock:(nullable void(^)(float progress))progressBlock
                     success:(TYSuccessHandler)success
                     failure:(TYFailureError)failure;



/// Stop file transfer
/// @param devId The device ID.
- (void)stopFileTransfer:(NSString *)devId;

/// Send transparent data  (Support  multiple packages).
///
/// @param data          Transparent data.
/// @param devId        The device Id for the device.
/// @param success    Called when the task finishes successfully.
/// @param failure    Called when the task is interrupted by an error.
- (void)publishTransparentData:(NSData *)data devId:(NSString *)devId success:(TYSuccessHandler)success failure:(TYFailureError)failure;


/// Update system time to device
/// @param deviceId   The device id
- (void)publishSystemTimeWithDeviceId:(NSString *)deviceId;



#pragma mark - activate extended module

- (NSInteger)getExtModuleType:(NSString*)devId;

/// Activate the extended module.
/// If it is WiFi, it will return an error because the SSID and password are not entered
/// @param devId device id
/// @param automatic activate mode. If NO, need to wait for the result of MQTT response activation
/// @param success If successfully activated, this block is called.
/// @param failure If activation fails, this block calls back an error
- (void)activateExtendedModule:(NSString*)devId automatic:(BOOL)automatic success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;



/// Activate the extended WiFi module. SSID and password required.
/// @param devId device id
/// @param automatic activate mode. If NO, need to wait for the result of MQTT response activation
/// @param ssid WiFi SSID
/// @param pwd WiFi password
/// @param success If successfully activated, this block is called.
/// @param failure If activation fails, this block calls back an error
- (void)activateExtendedWiFiModule:(NSString*)devId automatic:(BOOL)automatic ssid:(NSString*)ssid password:(NSString*)pwd success:(nullable TYSuccessHandler)success failure:(nullable TYFailureError)failure;
@end

NS_ASSUME_NONNULL_END
