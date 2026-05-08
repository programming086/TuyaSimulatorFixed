
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

/// the network type of the device
typedef NS_ENUM(NSUInteger, ThingDeviceNetworkInfoType) {
    ThingDeviceNetworkInfoTypeWifi = 0,
    ThingDeviceNetworkInfoTypeWire = 1,
    ThingDeviceNetworkInfoType4G = 2,
};

/// the network info of the device
@interface ThingDeviceNetworkInfo : NSObject
@property (nonatomic, assign) ThingDeviceNetworkInfoType network;  // 0 for wireless, 1 for wired, 2 for 4G
@property (nonatomic, copy) NSString *ssid; // SSID
@property (nonatomic, assign) NSInteger signal; // Signal strength
@property (nonatomic, assign) NSInteger flags; // Flags
@property (nonatomic, copy) NSString *ssidHash;
@end


@interface ThingDeviceNetworkManager : NSObject

- (instancetype)initWithDeviceId:(NSString *)deviceId;


/// Support WiFi backup network or not.
+ (BOOL)supportWifiBackupNetwork:(NSString *)deviceId;

/// Support WiFi backup network or not.
- (BOOL)supportWifiBackupNetwork;


/// Obtain the current network information of the device
/// - Parameters:
///   - success: success callback with ThingDeviceNetworkInfo
///   - failure: failure callback with error
- (void)getCurrentNetworkInfoWithSuccess:(void(^)(ThingDeviceNetworkInfo *info))success failure:(void(^)(NSError *error))failure;



/// Obtain the current list of WiFi backup networks for the device.
/// - Parameters:
///   - success: success callback with the list of ThingSmartBackupWifiModel and the max count of backup WiFis the device support
///   - failure: failure callback with error
- (void)getBackupWifiNetworksWithSuccess:(void(^)(NSArray<ThingSmartBackupWifiModel *> *backWifiInfos, NSInteger maxNum))success failure:(void(^)(NSError *error))failure;


/// Generate a backup network model through the WiFi name and password.
/// You should generate a ThingSmartBackupWifiModel via  'generateBackupWifiModelWithSSID:pwd:' and then update the backup WiFi network of the device if went.
/// - Parameters:
///   - ssid: the name of WiFi
///   - pwd: the password of WiFi
- (ThingSmartBackupWifiModel *)generateBackupWifiModelWithSSID:(NSString *)ssid pwd:(NSString *)pwd;


/// Determine whether the device can currently update the WiFi backup network. True if can otherwise false
/// - Parameter info: the ThingDeviceNetworkInfo get from 'getCurrentNetworkInfoWithSuccess:failure:'
- (BOOL)canUpdateWifiBackupNetwork:(ThingDeviceNetworkInfo *)info;

/// Update the WiFi backup networks of the device.
/// You should call 'canUpdateWifiBackupNetwork:' firstly to determine whether the device can currently update the WiFi backup network.
/// - Parameters:
///   - infos: the list of ThingSmartBackupWifiModel. The device does not support individual updates, only full coverage is supported. So you must list all the WiFi backup networks into the 'infos'.
///   - success: success callback
///   - failure: failure callback with error
- (void)updateBackupWifiNetworks:(NSArray<ThingSmartBackupWifiModel *> *)infos success:(void(^)(void))success failure:(void(^)(NSError *error))failure;



/// Determine whether the device can currently switch WiFi networks. True if can otherwise false
/// - Parameter info: the ThingDeviceNetworkInfo get from 'getCurrentNetworkInfoWithSuccess:failure:'
- (BOOL)canSwitchWifiNetwork:(ThingDeviceNetworkInfo *)info;


/// Switch the network of device to the specified WiFi backup network using hash value. You can do this if the WiFi backup network has been updated to the device.
/// You should call 'canSwitchWifiNetwork:' firstly to determine whether the device can currently switch WiFi networks.
/// - Parameters:
///   - hash: the hash value of the WiFi backup network
///   - success: success callback
///   - failure: failure callback with error
- (void)switchBackupWifiNetworkWithHash:(NSString *)hash success:(void(^)(void))success failure:(void(^)(NSError *error))failure;


/// Switch the network of device to the specified WiFi backup network using WIFI name and password. You can do this if the WiFi backup network hasn't been updated to the device.
/// You should call 'canSwitchWifiNetwork:' firstly to determine whether the device can currently switch WiFi networks.
/// - Parameters:
///   - ssid: the name of the WiFi backup network
///   - pwd: the password of the WiFi backup network
///   - success: success callback
///   - failure: failure callback with error
- (void)switchBackupWifiNetworkWithSSID:(NSString *)ssid pwd:(NSString *)pwd success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
