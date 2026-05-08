//
//  ThingSmartActivatorScanWifiParam.h
//  ThingSmartActivatorDiscoveryManager
//
//  Created by Jesse Zhou on 2022/8/16.
//

#import <Foundation/Foundation.h>
#import <ThingSmartActivatorCoreKit/ThingSmartActivatorCoreKit.h>
#import <ThingBluetoothInterface/ThingBluetoothInterface.h>
#import "ThingSmartActivatorType.h"
#import "ThingSmartActivatorDiscoveryError.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartActivatorConfigResponseConfigWifi : NSObject
/// 配网阶段
///
/// 2: 联网阶段
@property (nonatomic, assign) int configStage;

/// 阶段结果
///
/// configState == 2, status: ThingSmartActivatorDiscoveryConnectWiFiErrorCode
@property (nonatomic, assign) int status;

@end

@interface ThingSmartActivatorConfigResponse : NSObject

@property (nonatomic) ThingSmartActivatorType activatorType;

@property (nullable, nonatomic, copy) NSString *uniqueId;
@property (nullable, nonatomic) id response;
@property (nullable, nonatomic) NSError *error;

@end

@interface ThingSmartActivatorScanWifiParam : NSObject

/// 请求的 Wi-Fi 最大数量
@property (nonatomic, assign) NSInteger limit;
/// 超时时间
@property (nonatomic, assign) NSTimeInterval timeInterval;

/// Ble+Wi-Fi
@property (nullable, nonatomic, copy) NSString *uuid;

/// limit: 10, timeInterval: 5
+ (instancetype)defaultParam;

@end

/// 扫描到的 Wi-Fi 结果
@interface ThingSmartActivatorScanWifiModel : NSObject

@property (nonatomic, copy) NSString *ssid;
@property (nonatomic, strong) NSNumber *rssi;
/// 0: 未加密
@property (nonatomic, strong) NSNumber *sec;

@end

@interface ThingSmartActivatorResumeConfigWiFiParam : NSObject

@property (nonatomic, copy) NSString *ssid;
@property (nullable, nonatomic, copy) NSString *password;

/// Wi-Fi
@property (nonatomic, assign) ThingActivatorMode mode;

/// Ble+Wi-Fi
/// - 恢复配网是兜底激活: 需要uuid
/// - 恢复配网是双模：需要uuid和ssid,password(可选)
@property (nullable, nonatomic, copy) NSString *uuid;
@property (nonatomic) ThingBluetoothBleWifiConfigModelResumeActionType bleWifiActionType;

@end

NS_ASSUME_NONNULL_END
