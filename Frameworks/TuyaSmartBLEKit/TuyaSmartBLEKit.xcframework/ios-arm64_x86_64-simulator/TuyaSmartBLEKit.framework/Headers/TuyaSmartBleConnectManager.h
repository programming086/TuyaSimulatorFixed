//
//  TuyaSmartBleConnectManager.h
//  TuyaSmartBLEKit
//
//  Created by milong on 2021/12/22.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBleConnectManager : NSObject

/// Enter current device  console
/// @param deviceId device id
- (void)didEnterConsoleConnectWithDeviceId:(NSString *)deviceId;

/// Exit current device console
/// @param deviceId device id
- (void)didExitConsoleConnectWithDeviceId:(NSString *)deviceId;

/// Enter the foreground from the app background
/// @param deviceList device list
- (void)didEnterFrontDeskWithDeviceList:(NSArray<TuyaSmartDeviceModel *> *)deviceList;

/// Enter from the app foreground to the background
/// @param deviceList device list
- (void)didEnterBackgroundWithDeviceList:(NSArray<TuyaSmartDeviceModel *> *)deviceList;

@end

NS_ASSUME_NONNULL_END
