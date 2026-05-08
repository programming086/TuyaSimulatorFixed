//
//  TuyaSmartDeviceEventUtil.h
//  TuyaSmartDeviceCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The device category defined by inside rule. Just for event statistics.
typedef NS_ENUM(NSUInteger, TYDeviceOSCategory) {
    TYDeviceOSCategoryDefault       = 9999,
    
    TYDeviceOSCategoryWifiPv2_0     = 1,
    TYDeviceOSCategoryWifiPv2_1     = 2,
    TYDeviceOSCategoryWifiPv2_2     = 3,
    TYDeviceOSCategoryWifiPv2_3     = 4,
    TYDeviceOSCategoryWifiPvUnknown = 5,
    
    TYDeviceOSCategoryGPRS = 200,
    
    TYDeviceOSCategoryNB   = 300,
    
    TYDeviceOSCategoryBle       = 1000,
    TYDeviceOSCategoryBleSub    = 1001,
    TYDeviceOSCategoryBleWifi   = 1002,
    TYDeviceOSCategoryBleCat1   = 1003,
    TYDeviceOSCategoryBlePlugPlayFull  = 1004,
    TYDeviceOSCategoryBlePlugPlayHalf  = 1005,
    TYDeviceOSCategoryBleMultiuser     = 1006,
    TYDeviceOSCategoryBleWifiMultiuser = 1007,
    
    TYDeviceOSCategoryBleMesh    = 1100,
    TYDeviceOSCategoryBleMeshSub = 1101,
    
    TYDeviceOSCategoryZigBeeSub  = 1200,

    TYDeviceOSCategoryInfraredWifi   = 1300,
    TYDeviceOSCategoryInfraredZigBee = 1301,
    
    TYDeviceOSCategory433        = 1400,
    TYDeviceOSCategory433Gateway = 1401,
    
    TYDeviceOSCategorySigMesh           = 1500,
    TYDeviceOSCategorySigMeshSub        = 1501,
    TYDeviceOSCategorySigMeshSingleFire = 1502,
    
    TYDeviceOSCategoryCat1 = 2000,
    
    TYDeviceOSCategoryBeacon    = 2100,
    TYDeviceOSCategoryBeaconSub = 2101,
    
    TYDeviceOSCategoryGatewayWifi  = 9000,
    TYDeviceOSCategoryGatewayCable = 9001,
    TYDeviceOSCategoryGatewaySigMeshElection = 9002,
    
    TYDeviceOSCategoryGroupWifi    = 9100,
    TYDeviceOSCategoryGroupBleMesh = 9101,
    TYDeviceOSCategoryGroupZigBee  = 9102,
    TYDeviceOSCategoryGroupSigMesh = 9103,
    TYDeviceOSCategoryGroupBeacon  = 9104
};

typedef NS_ENUM(NSUInteger, TYEventPipelineType) {
    /// LAN
    TYEventPipelineTypeLAN      = 1,
    
    /// MQTT
    TYEventPipelineTypeMQTT     = 2,
    
    /// HTTP
    TYEventPipelineTypeHTTP     = 3,
    
    /// Single Point Bluetooth
    TYEventPipelineTypeBLE      = 4,
    
    /// Sig Mesh
    TYEventPipelineTypeSIGMesh  = 5,
    
    /// Tuya Private Mesh
    TYEventPipelineTypeBLEMesh  = 6,
    
    /// others
    TYEventPipelineTypeOther    = 9,
};

typedef NS_ENUM(NSUInteger, TYEventDpOptCode) {
    TYEventDpOptCodeNoNextPipeline      = 997,
    
    TYEventDpOptCodePublishUnknownFail  = 998,
    TYEventDpOptCodeReportUnknownFail   = 999,
    
    TYEventDpOptCodeOffline             = 100,
    TYEventDpOptCodePublishApiFail      = 101,
    TYEventDpOptCodePublishVerifyFail   = 102,
    TYEventDpOptCodePublishNoPipeline   = 103,
    TYEventDpOptCodeUpgrading           = 104,
    TYEventDpOptCodeBleMTPFail          = 105,
    TYEventDpOptCodePhoneBleOff         = 106,
    TYEventDpOptCodeLocalKeyFail        = 107,
    TYEventDpOptCodeEncodeFail          = 108,
    
    TYEventDpOptCodeReportVerifyFail    = 200,
    TYEventDpOptCodeReportTimeout       = 201,
    TYEventDpOptCodeReportValueNotSame  = 202,
    TYEventDpOptCodeReportReplayBlock   = 203,
    TYEventDpOptCodeReportDualModeBlock = 204,
};

FOUNDATION_EXPORT NSErrorUserInfoKey const TYErrorDpEventPipelineKey;
FOUNDATION_EXPORT NSErrorUserInfoKey const TYErrorDpEventOptCodeKey;

@interface TuyaSmartDeviceEventHelper : NSObject
+ (TYDeviceOSCategory)osCategoryByGroup:(TuyaSmartGroupModel *)group;
+ (TYDeviceOSCategory)osCategoryByDevice:(TuyaSmartDeviceModel *)device;
@end

@interface TuyaSmartDeviceEventUtil : NSObject

/// The message sending request is successful.
///
/// @param pipelineType The message sending pipeline.
+ (void)successEventWithPipelineType:(TYEventPipelineType)pipelineType;

/// The message sending request failed.
///
/// @param pipelineType The message sending pipeline.
/// @param pv The device protocol version that is used when the message is sent.
/// @param error An error occurs while processing the request.
/// @param extendInfo Detailed error information, in which you can easily check the status of the error and the app condition.
+ (void)failedEventWithPipelineType:(TYEventPipelineType)pipelineType
                                 pv:(double)pv
                              error:(NSError *)error
                         extendInfo:(NSDictionary *)extendInfo;

/// The message for public demend
///
/// @param attribute The attribute dictionary.
+ (void)tysdkControlEventWithAttribute:(NSDictionary *)attribute;

/// The message for lan control. report mqtt status
///
/// @param attribute The attribute dictionary.
+ (void)tysdkLanControlEventWithAttribute:(NSDictionary *)attribute;

+ (void)tysdkThingModelControlWithAttribute:(NSDictionary *)attribute;

/// The message for device publish dp.
/// error code reference to `TYEventDpOptCode`
+ (void)tysdkDpBuriedPublishDevice:(TuyaSmartDeviceModel *)device
                               dps:(NSDictionary *)dps
                          pipeline:(TYCommunicationType)pipeline
                             error:(nullable NSError *)error
                             start:(NSDate *)start
                               end:(NSDate *)end;

/// The message for group publish dp.
/// error code reference to `TYEventDpOptCode`
+ (void)tysdkDpBuriedPublishGroup:(TuyaSmartGroupModel *)group
                              dps:(NSDictionary *)dps
                         pipeline:(TYCommunicationType)pipeline
                            error:(nullable NSError *)error
                            start:(NSDate *)start
                              end:(NSDate *)end;

/// The message for dp update fail.
/// error code reference to `TYEventDpOptCode`
+ (void)tysdkDpBuriedReportFailWithDevId:(nullable NSString *)devId
                               orGroupId:(nullable NSString *)groupId
                                     dps:(NSDictionary *)dps
                                   error:(NSError *)error;


@end

NS_ASSUME_NONNULL_END
