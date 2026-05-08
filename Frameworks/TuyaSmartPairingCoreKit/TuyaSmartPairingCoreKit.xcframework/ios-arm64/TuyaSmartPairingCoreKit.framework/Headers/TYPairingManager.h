//
//  TYPairingManager.h
//  TuyaSmartPairingCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TuyaSmartPairingHandlerDelegate;
@protocol TuyaSmartPairConfiguration;
@protocol TuyaSmartLogTrackConfiguration;

@interface TYPairingManager : NSObject

@property (nonatomic, strong, nullable) NSString *gwId;

@property (nonatomic, strong, nullable) NSString *token;

@property (nonatomic, strong, nullable) NSString *registerString;//2位地区码+8位token+4位secret

@property (nonatomic, assign) TYActivatorMode mode;

@property (nonatomic, copy, nullable) NSString *type;

@property (nonatomic, copy, nullable) NSString *pairStep;

@property (nonatomic, copy, nullable) NSString *productId;//只为某一特定的设备类型配网

@property (nonatomic, assign) BOOL hasSuccess;

@property (nonatomic, weak, nullable) id<TuyaSmartLogTrackConfiguration> logTrackConfiguration;

+ (void)getSSID:(TYSuccessString)success failure:(TYFailureError)failure;

+ (void)getBSSID:(TYSuccessString)success failure:(TYFailureError)failure;

#pragma mark - General

- (void)startPairingWithConfiguration:(id<TuyaSmartPairConfiguration>)config
                                 mode:(TYActivatorMode)mode
                             delegate:(id<TuyaSmartPairingHandlerDelegate>)delegate;

- (void)pairingSubDeviceWithGwId:(NSString *)gwId
                             msg:(NSDictionary *)msg
                        localKey:(NSString *)localKey
                              pv:(double)pv
                         success:(nullable TYSuccessHandler)success
                         failure:(nullable TYFailureError)failure;

- (void)publishMqttMsg:(NSDictionary *)msg
              protocol:(NSInteger)protocol
                 devId:(NSString *)devId
              localKey:(NSString *)localKey
                    pv:(double)pv
               success:(nullable TYSuccessHandler)success
               failure:(nullable TYFailureError)failure;

- (void)searchDevices;

- (void)stopConfigWiFi;

- (void)stopConfigZigbeeSubDevice;

- (void)stopConfigWifiUnBind;

- (void)continueConfigSecurityLevelDevice;

@end

NS_ASSUME_NONNULL_END
