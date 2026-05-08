//
// TuyaSmartBLEManager.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,TYBeaconResponseAction) {
    TYBeaconResponseActionAuth = -1,
    TYBeaconResponseActionCheck,
};

typedef NS_ENUM(NSInteger,TYBeaconRequestAction) {
    TYBeaconRequestActionAuth = -1,
    TYBeaconRequestActionCheck,
    TYBeaconRequestActionAbandon,
    TYBeaconRequestActionSubscribe,
    TYBeaconRequestActionSearch,
};

@class TYBLEAdvModel;
@class TuyaSmartBeaconRequestModel;
@class TuyaSmartBeaconResponseModel;
@class TuyaSmartDeviceModel;

@protocol TuyaSmartBeaconManagerDelegate <NSObject>
@optional
- (void)didDiscoveryDeviceWithUUID:(NSString *)uuid productKey:(nullable NSString *)productKey __deprecated_msg("This method is deprecated, Use didDiscoveryDeviceWithDeviceInfo: instead");

- (void)didDiscoveryDeviceWithDeviceInfo:(TYBLEAdvModel *)deviceInfo;

/// beacon device report
/// @param responseAction beacon device response action
/// @param deviceId device id
/// @param responseModel response data model
- (void)didReceiveChannelResponseWithAction:(TYBeaconResponseAction)responseAction deviceId:(NSString *)deviceId responseModel:(TuyaSmartBeaconResponseModel *)responseModel;


- (NSArray <TuyaSmartDeviceModel *>*)deviceListDataSource;
@end


@protocol TuyaSmartBLEManagerDelegate;

@interface TuyaSmartBeaconManager : NSObject
@property (nonatomic, assign, readonly) BOOL isPoweredOn;
@property (nonatomic, weak) id<TuyaSmartBeaconManagerDelegate,TuyaSmartBLEManagerDelegate> delegate;

/// The single instance.
+ (instancetype)sharedInstance;

/// Whether to disable bluetooth capability. Default NO
+ (void)disableBLECapability:(BOOL)disable;

#pragma mark - activate

/// Activates the beacon device. advModel is cached and removed when activated
/// @param advModel The advertisingData model for the beacon device.
/// @param homeId The ID for the current home.
/// @param success Called when the task is finished. DeviceModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)activateBeacon:(TYBLEAdvModel*)advModel homeId:(long long)homeId success:(void (^)(TuyaSmartDeviceModel *deviceModel))success failure:(void(^)(NSError *error))failure;


/// The end of the pairing process.
- (void)stopActivatingBeacons:(NSArray<TYBLEAdvModel*>*)beacons;

/// Stop activating all cached beacon devices
- (void)stopActivatingAllBeacons;


#pragma mark - action

/// Publishes the transmitted data.
/// @param deviceId The device ID for the device.
/// @param dps The DP dictionary.
/// @param success Called when the task is finished.
/// @param failure  Called when the task is interrupted by an error.
- (void)publishDpsWithDevicId:(NSString *)deviceId dps:(nonnull NSDictionary *)dps success:(void(^)(void))success failure:(void(^)(NSError *error))failure;


/// Checks and sets the online status of a device.
/// @param deviceModel The device model.
- (void)checkDeviceOnlineStateWithDevice:(TuyaSmartDeviceModel *)deviceModel;

/// Checks and sets the online status of all beacon devices.
/// @param deviceModelList The device model list.
- (void)checkAllBeaconDeviceOnlineState:(NSArray<TuyaSmartDeviceModel *> *)deviceModelList;

/// Connects to the device and sets the online status of the device.
/// @param deviceId The device ID.
- (void)connectBeaconWithDeviceId:(NSString *)deviceId;


/// Resets the device and enables the pairing status for the device.
/// @param devId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)resetWithDevId:(NSString *)devId success:(void(^)(void))success failure:(void(^)(void))failure;

///  The online status of the beacon device.
/// @param uuid The UUID of the beacon device.
- (BOOL)deviceStatueWithUUID:(NSString *)uuid;


/// Checks gateway online status of the beacon device
/// @param deviceModel The device model.
- (BOOL)gatewayOnlineOfDevice:(TuyaSmartDeviceModel *)deviceModel;


/// publish beacon  command data
/// @param requestAction publish request action
/// @param deviceId device id
/// @param requestModel publish data model
- (void)publishChannelRequestWithAction:(TYBeaconRequestAction)requestAction
                               deviceId:(NSString *)deviceId
                           requestModel:(TuyaSmartBeaconRequestModel *)requestModel;
@end

NS_ASSUME_NONNULL_END
