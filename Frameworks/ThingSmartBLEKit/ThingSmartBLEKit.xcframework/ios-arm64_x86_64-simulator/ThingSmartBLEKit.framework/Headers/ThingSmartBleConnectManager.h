
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBleConnectManager : NSObject

/// Enter current device  console
/// @param deviceId device id
- (void)didEnterConsoleConnectWithDeviceId:(NSString *)deviceId;

/// Exit current device console
/// @param deviceId device id
- (void)didExitConsoleConnectWithDeviceId:(NSString *)deviceId;

/// Enter the foreground from the app background
/// @param deviceList device list
- (void)didEnterFrontDeskWithDeviceList:(NSArray<ThingSmartDeviceModel *> *)deviceList;

/// Enter from the app foreground to the background
/// @param deviceList device list
- (void)didEnterBackgroundWithDeviceList:(NSArray<ThingSmartDeviceModel *> *)deviceList;

@end

NS_ASSUME_NONNULL_END
