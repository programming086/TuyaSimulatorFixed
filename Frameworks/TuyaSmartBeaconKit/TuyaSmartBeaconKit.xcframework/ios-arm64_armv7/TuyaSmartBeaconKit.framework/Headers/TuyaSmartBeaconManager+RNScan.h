//
//  TuyaSmartBeaconManager+RNScan.h
//  TuyaSmartBLEKit
//
//  Created by Tuya on 2021/8/10.
//

#import "TuyaSmartBeaconManager.h"

NS_ASSUME_NONNULL_BEGIN
@interface TuyaSmartBeaconManager (RNScan)

- (void)scanForSharedBeaconWithDeviceId:(nullable NSString*)deviceId;

- (void)scanForSharedBeaconsWithDeviceIds:(nullable NSArray<NSString*>*)deviceIds;


/// Stop scanning beacon shared devices
- (void)stopShareBeaconScan;


/// Stop scanning the beacon shared device with the specified device id
/// @param deviceId deviceId
- (void)stopScanShareBeaconWithDeviceId:(nullable NSString*)deviceId;


/// Stop scanning for beacon shared devices containing a set of device IDs
/// @param deviceIds @[deviceId,deviceId]
- (void)stopScanSharedBeaconsWithDeviceIds:(nullable NSArray<NSString*>*)deviceIds;

@end

NS_ASSUME_NONNULL_END
