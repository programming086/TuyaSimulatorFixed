//
// TuyaSmartBLEWifiActivator.h
// TuyaSmartBLEKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartBLECoreKit/TuyaSmartBLEActiveDelegate.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN
@class TuyaSmartBLEWifiActivator;
@class TYBLEWifiConfigModel;
@class TYBLETransportRequest;
@class TYBLEConfigStateModel;


typedef NS_ENUM (NSInteger, TuyaBLEWifiConfigResumeActionType){
    TuyaBLEWifiConfigResumeActionTypeSetWifi = 0,//设置wifi及pwd
    TuyaBLEWifiConfigResumeActionTypePlugPlay,//继续兜底激活
};

typedef void(^TYBLEArrayCallback)(NSArray *_Nullable array, NSError *_Nullable error);


/// The delegate of the activation result for a dual-mode device.
@protocol TuyaSmartBLEWifiActivatorDelegate <NSObject>

/// The result of activating the dual-mode device.
///
/// @param activator        The class.
/// @param deviceModel      Called when the task is finished. DeviceModel is returned.
/// @param error            Called when the task is interrupted by an error.
- (void)bleWifiActivator:(TuyaSmartBLEWifiActivator *)activator didReceiveBLEWifiConfigDevice:(nullable TuyaSmartDeviceModel *)deviceModel error:(nullable NSError *)error;


- (void)bleWifiActivator:(TuyaSmartBLEWifiActivator *)activator
didReceiveConfigMiddleStateModel:(nullable TYBLEConfigStateModel *)configState;

@end

/// @brief TuyaSmartBLEWifiActivator provides methods to implement the activation of dual-mode devices.
///
/// Each dual-mode device that provides both Bluetooth and Wi-Fi chips can publish the activation data through the Bluetooth channel and complete the activation through the Wi-Fi channel.
@interface TuyaSmartBLEWifiActivator : NSObject

/// The delegate of the activation result for a dual-mode device.
@property (nonatomic, weak) id<TuyaSmartBLEWifiActivatorDelegate> bleWifiDelegate;

/// The UUID for the device.
@property (nonatomic, strong) NSString *deviceUUID;

@property (nonatomic, assign) BOOL isNeedBleReset;

/// The single instance.
+ (instancetype)sharedInstance;

/// Activates the dual-mode device.
///
/// @param UUID         The UUID of the device.
/// @param homeId       The ID of the current home.
/// @param productId    The product ID of the device.
/// @param ssid         The name of the router.
/// @param password     The password of the device.
/// @param timeout      The timeout value.
/// @param success      Called when the task is finished.
/// @param failure      Called when the task is interrupted by an error.
- (void)startConfigBLEWifiDeviceWithUUID:(NSString *)UUID
                                  homeId:(long long)homeId
                               productId:(NSString *)productId
                                    ssid:(NSString *)ssid
                                password:(NSString *)password
                                 timeout:(NSTimeInterval)timeout
                                 success:(TYSuccessHandler)success
                                 failure:(TYFailureHandler)failure;

/// Stop polling the actived device.
- (void)stopDiscover;


/// Resume ble-wifi device config
/// @param actionType The type of resume event, see TuyaBLEWifiConfigResumeActionType
/// @param configModel The model of config，see TYBLEWifiConfigModel
/// return 0:成功 1:参数错误 2:配网对象不存在 3:设备不支持该能力
- (int)resumeConfigBLEWifiDeviceWithActionType:(TuyaBLEWifiConfigResumeActionType)actionType
                                    configModel:(TYBLEWifiConfigModel *)configModel;


/// Query wifi list of device scan during the config
/// @param requestModel The model of request
/// @param completion Called when the task is complete,
///                  IF error is not nil,it means the task is interrupted by an error.
///                  IF error is nil,the responseData is  NSArray <TYBLEWifiModel *> *

- (void)queryWifiListForDeviceScan:(TYBLETransportRequest *)requestModel
                        completion:(TYBLEArrayCallback)completion;


@end

NS_ASSUME_NONNULL_END
