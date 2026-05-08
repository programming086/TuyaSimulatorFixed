//
//  ThingSDKConfig.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSDKConfig : NSObject

@property (nonatomic, assign) BOOL supportPlugplay;

@property (nonatomic, assign) BOOL shouldUseNewUIPanelModel;

/// 1: DPEngine 1st forcely, 2: mqtt 1st forcely, other: communication order
@property (nonatomic, assign) NSUInteger matterDpProprity;

/// DPEngine no response after x sencond, use mqtt to compensate. 0 is no compensate
@property (nonatomic, assign) NSUInteger matterDpCompensateTime;

@property (nonatomic, assign) BOOL hostSameLimit;

@property (nonatomic, assign) BOOL hostSuffixLimit;

@property (nonatomic, assign) BOOL appHostPoolLimit;

@property (nonatomic, assign) BOOL hostPoolAbnormalLimit;

@property (nonatomic, copy, nullable) NSString *dynamicAddHotspots;

@property (nonatomic, assign) NSUInteger multiPairMaxConnection;

@property (nonatomic, assign) BOOL enableMultiPair;

@property (nonatomic, assign) BOOL enableChangeBleBindState;

@property (nonatomic, assign) BOOL isMultiPairing;

@property (nonatomic, assign) BOOL autoPlugPlay;

@property (nonatomic, strong) NSNumber *matterAdminVenderId;

/// YES if and only if the Bluetooth library has not been cropped&&Bluetooth is authorized&&Bluetooth switch is turned on, otherwise NO
@property (nonatomic, assign) BOOL bleState;

@property (nonatomic, assign) BOOL useCacheCB;

+ (instancetype)sharedInstance;

@end

NS_ASSUME_NONNULL_END
