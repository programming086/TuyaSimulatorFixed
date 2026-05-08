//
//  TuyaSmartBleGatewayService.h
//  TYSmartBLEModule
//
//  Created by milong on 2021/12/2.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>


NS_ASSUME_NONNULL_BEGIN


typedef enum : NSUInteger {
    TYBleGatewayServiceErrorUnknown = 900,
    TYBleGatewayServiceErrorWrongParam = 901,
    TYBleGatewayServiceErrorNotInWhiteList = 902,
    TYBleGatewayServiceErrorTimeOut = 903,
    TYBleGatewayServiceAddIsRunning = 904,
} TYBleGatewayServiceError;

@protocol TYBleGatewayServiceAddDeviceDelegate <NSObject>

/// Add a device successfully
/// @param deviceId  device id
- (void)onReceiveAddDeviceSuccess:(NSString *)deviceId;


/// Add a device Failed
/// @param error error
/// @param deviceId  device Id
- (void)onReceiveAddDeviceFailure:(NSString *)deviceId error:(NSError *)error;

/// Error adding device
/// @param error error
- (void)onError:(NSError *)error;

/// Add complete
- (void)onReceiveAddDeviceFinish;

@end

@interface TuyaSmartBleGatewayService : NSObject

TYSDK_SINGLETON

/// add device delegate
/// @param delegate delegate
- (void)addDelegate:(id<TYBleGatewayServiceAddDeviceDelegate>)delegate;

///  remove delegate
/// @param delegate  delegate
- (void)removeDelegate:(id<TYBleGatewayServiceAddDeviceDelegate>)delegate;

/// add device to gateway
/// @param gatewayId  gateway id
/// @param devIdList device id list
- (void)addDevices:(NSArray<NSString *> *)devIdList toGateway:(NSString *)gatewayId;

/// remove device from gateway
/// @param deviceId de
/// @param gatewayId gateway Id
/// @param successBlock success block
/// @param failureBlock failure block
- (void)removeDevice:(NSString *)deviceId
        fromGateway:(NSString *)gatewayId
            success:(TYSuccessHandler)successBlock
            failure:(TYFailureError)failureBlock;

/// get device list
/// @param gatewayId gateway id
/// @param successBlock success block
/// @param failureBlock failure block
- (void)deviceListFromGateway:(NSString *)gatewayId success:(nullable void (^)(NSArray <TuyaSmartDeviceModel *> *subDeviceList))successBlock failure:(nullable TYFailureError)failureBlock;

/// connect device id list
/// @param devIdList device list
/// @param gwId  gateway id
- (void)connectDevIdList:(NSArray<NSString *> *)devIdList WithGateWayId:(NSString *)gwId;

/// disconnect device id list
/// @param devIdList device id list
/// @param gwId gateway id
- (void)disconnectDevIdList:(NSArray<NSString *> *)devIdList WithGateWayId:(NSString *)gwId;

/// check heart beat
/// @param gatewayIdList gateway id list
- (void)checkAndSendHeardBeatWithGatewayIdList:(NSArray<NSString *> *)gatewayIdList;

/// stop heart beat
- (void)stopHeartBeat;




@end

NS_ASSUME_NONNULL_END
