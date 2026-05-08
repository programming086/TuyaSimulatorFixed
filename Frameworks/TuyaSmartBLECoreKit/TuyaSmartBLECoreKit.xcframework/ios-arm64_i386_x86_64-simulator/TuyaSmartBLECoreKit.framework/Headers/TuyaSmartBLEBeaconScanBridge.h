//
//  TuyaSmartBLEBeaconScanBridge.h
//  TuyaSmartBLECoreKit
//
//  Created by 余豪 on 2021/6/25.
//

#import <Foundation/Foundation.h>
#import <TYBluetooth/TYBluetooth.h>
#import "TYBLEDeviceInfoProtocol.h"



typedef void(^TYBLEBeaconScanCallback)(TYBLEPeripheral * _Nullable p, id<TYBLEDeviceInfoProtocol> _Nullable deviceInfo);

NS_ASSUME_NONNULL_BEGIN
@class TYBLEScan;


@protocol TuyaSmartBLEBeaconScanDelegate <NSObject>
- (void)centralManagerDidUpdatePowerState:(BOOL)isPowerOn;
@end

@interface TuyaSmartBLEBeaconScanBridge : NSObject
@property (nonatomic, strong) TYBLEScan *scan;
@property (nonatomic, weak) id<TuyaSmartBLEBeaconScanDelegate> delegate;

TYSDK_SINGLETON
- (void)startBleBeaconScanWithDeviceId:(NSString *)deviceId uuid:(NSString *)uuid callBack:(TYBLEBeaconScanCallback)callback __deprecated_msg("This method is deprecated, Use `startBleBeaconScanWithDeviceId:uuid:macId:callBack:` instead");

- (void)startBleBeaconScanWithDeviceId:(NSString *)deviceId uuid:(NSString *)uuid macId:(NSString *)macid callBack:(TYBLEBeaconScanCallback)callback;


- (void)startBleBeaconScanning:(TYBLEBeaconScanCallback)callback;

- (void)stopScan __deprecated_msg("This method is deprecated, Use `stopBleBeaconScan` instead");
- (void)stopBeaconScan __deprecated_msg("This method is deprecated, Use `stopBleBeaconScan` instead");
- (void)stopBleBeaconScan;
@end

NS_ASSUME_NONNULL_END
