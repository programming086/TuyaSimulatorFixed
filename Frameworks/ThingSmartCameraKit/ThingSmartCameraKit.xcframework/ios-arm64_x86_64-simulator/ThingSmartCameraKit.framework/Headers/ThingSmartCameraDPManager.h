
#import <Foundation/Foundation.h>
#import <ThingSmartCameraBase/ThingSmartCameraBase.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

typedef NSString * ThingSmartCameraDPKey NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * ThingSmartCameraNightvision NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * ThingSmartCameraPIR NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * ThingSmartCameraMotion NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * ThingSmartCameraDecibel NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * ThingSmartCameraRecordMode NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * ThingSmartCameraPTZDirection NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * ThingSmartCameraPowerMode NS_EXTENSIBLE_STRING_ENUM;
typedef NSString * ThingSmartCameraIPConfig NS_EXTENSIBLE_STRING_ENUM;

/// [^en]basic setting dp[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraBasicIndicatorDPName;      // [^en]indicator light switch, Value is BOOL[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraBasicFlipDPName;           // [^en]video flip vertical switch, Value is BOOL[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraBasicOSDDPName;            // [^en]time watermark switch, Value is BOOL[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraBasicPrivateDPName;        // [^en]private mode switch, Value is BOOL[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraBasicNightvisionDPName;    // [^en]nightvision state, Value is ThingSmartCameraNightvision[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraBasicPIRDPName;            // [^en]PIR sensitivity[$en]

/// [^en]motion detecting alarm[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraMotionDetectDPName;        // [^en]motion detecting switch, Value is BOOL[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraMotionSensitivityDPName;   // [^en]motion detecting sensitivity state, value is ThingSmartCameraMotion[$en]

/// [^en]decibel detecting alarm[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraDecibelDetectDPName;       // [^en]decibel detecting switch, value is BOOL[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraDecibelSensitivityDPName;  // [^en]decibel detecting sensitivity, value is ThingSmartCameraDecibel[$en]

/// [^en]SD card[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraSDCardStatusDPName;        // [^en]sd card status, value is ThingSmartCameraSDCardStatus, just for read[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraSDCardStorageDPName;       // [^en]sd card capacity state, Value is String, just for read[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraSDCardFormatDPName;        // [^en]sd card format command, Value is YES, just for publish[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraSDCardUnmountDPName;       // [^en]sd card unmount command, Value is YES, just for publish[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraSDCardFormatStateDPName;   // [^en]sd card format state, Value is long : 0 - 100. if negative，is error[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraSDCardRecordDPName;        // [^en]sd card record switch, value is BOOL[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraSDCardMuteRecordDPName;        // [^en]sd card MuteRecord switch, value is BOOL[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraRecordModeDPName;          // [^en]sd card record mode, value is ThingSmartCameraRecordMode[$en]

/// ptz
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraPTZControlDPName;          // [^en]start ptz, value is ThingSmartCameraPTZDirection, just for publish[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraPTZStopDPName;             // [^en]stop ptz, value is BOOL, just for publish[$en]

/// wireless
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraWirelessElectricityDPName; // [^en]device electricity, value is long 0 - 100, just for read[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraWirelessPowerModeDPName;   // [^en]power supply mode, value is ThingSmartCameraPowerMode[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraWirelessLowpowerDPName;    // [^en]lowpower alarm threshold, value is long 0 - 100, just for publish. if the electricity is lower than this value, app will receive a push notification[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraWirelessBatteryLockDPName; // [^en]battery lock switch, value is BOOL[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraWirelessAwakeDPName;       // [^en]awake state, value is BOOL[$en]

/// [^en]nightvision state values[$en]
IPC_EXTERN ThingSmartCameraNightvision const ThingSmartCameraNightvisionAuto;
IPC_EXTERN ThingSmartCameraNightvision const ThingSmartCameraNightvisionOff;
IPC_EXTERN ThingSmartCameraNightvision const ThingSmartCameraNightvisionOn;

/// [^en]iptype config values[$en]
IPC_EXTERN ThingSmartCameraIPConfig const ThingSmartCameraIPConfigDynamic;
IPC_EXTERN ThingSmartCameraIPConfig const ThingSmartCameraIPConfigStatic;

/// [^en]PIR state values[$en]
IPC_EXTERN ThingSmartCameraPIR const ThingSmartCameraPIRStateOff;
IPC_EXTERN ThingSmartCameraPIR const ThingSmartCameraPIRStateLow;
IPC_EXTERN ThingSmartCameraPIR const ThingSmartCameraPIRStateMedium;
IPC_EXTERN ThingSmartCameraPIR const ThingSmartCameraPIRStateHigh;
IPC_EXTERN ThingSmartCameraPIR const ThingSmartCameraPIRStateOn;

/// [^en]motion detecting sensitivity values[$en]
IPC_EXTERN ThingSmartCameraMotion const ThingSmartCameraMotionLow;
IPC_EXTERN ThingSmartCameraMotion const ThingSmartCameraMotionMedium;
IPC_EXTERN ThingSmartCameraMotion const ThingSmartCameraMotionHigh;

/// [^en]decibel detecting sensitivity values[$en]
IPC_EXTERN ThingSmartCameraDecibel const ThingSmartCameraDecibelLow;
IPC_EXTERN ThingSmartCameraDecibel const ThingSmartCameraDecibelHigh;
IPC_EXTERN ThingSmartCameraDecibel const ThingSmartCameraDecibelMid;

/// [^en]sd card record mode values[$en]
IPC_EXTERN ThingSmartCameraRecordMode const ThingSmartCameraRecordModeEvent;
IPC_EXTERN ThingSmartCameraRecordMode const ThingSmartCameraRecordModeAlways;
IPC_EXTERN ThingSmartCameraRecordMode const ThingSmartCameraRecordModedTime;

/// [^en]ptz direction values[$en]
IPC_EXTERN ThingSmartCameraPTZDirection const ThingSmartCameraPTZDirectionUp;
IPC_EXTERN ThingSmartCameraPTZDirection const ThingSmartCameraPTZDirectionRight;
IPC_EXTERN ThingSmartCameraPTZDirection const ThingSmartCameraPTZDirectionDown;
IPC_EXTERN ThingSmartCameraPTZDirection const ThingSmartCameraPTZDirectionLeft;

/// [^en]Wireless device power mode values[$en]
IPC_EXTERN ThingSmartCameraPowerMode const ThingSmartCameraPowerModeBattery;
IPC_EXTERN ThingSmartCameraPowerMode const ThingSmartCameraPowerModePlug;

/// [^en]Object outline[$en]
IPC_EXTERN ThingSmartCameraDPKey const ThingSmartCameraOutlineDPName;

/// [^en]sd card state[$en]
typedef NS_ENUM(NSUInteger, ThingSmartCameraSDCardStatus) {
    ThingSmartCameraSDCardStatusNormal = 1,
    ThingSmartCameraSDCardStatusException = 2,
    ThingSmartCameraSDCardStatusMemoryLow = 3,
    ThingSmartCameraSDCardStatusFormatting = 4,
    ThingSmartCameraSDCardStatusNone = 5, // not detected sd card
    ThingSmartCameraSDCardStatusLoading = 7 // loading
};

@class ThingSmartCameraDPManager;

@protocol ThingSmartCameraDPObserver <NSObject>

@optional

/**
 [^en]
 device dps data did update
 [$en]


 @param manager dpManger
 @param dpsData @{dpName: dpValue}
 */
- (void)cameraDPDidUpdate:(ThingSmartCameraDPManager *)manager dps:(NSDictionary *)dpsData;

@end

@protocol ThingSmartCameraDPDataSource <NSObject>

/// min is 10.
- (NSInteger)timeoutOfDPProcess:(ThingSmartCameraDPKey)dpKey;

/// default is 132.
- (NSArray<ThingSmartCameraDPKey> *)dpsOfLongTimeout;

@end

@interface ThingSmartCameraDPManager : NSObject

@property (nonatomic, strong, readonly) NSString *deviceId;

@property (nonatomic, strong, readonly) NSArray *observers;

@property (nonatomic, strong, readonly) ThingSmartDevice *device;

- (instancetype)initWithDevice:(ThingSmartDevice *)device __deprecated_msg("Use initWithDeviceId: instead");

- (instancetype)initWithDeviceId:(NSString *)devId;

- (void)addObserver:(id<ThingSmartCameraDPObserver>)observer;

- (void)removeObserver:(id<ThingSmartCameraDPObserver>)observer;

@property (nonatomic, weak) id <ThingSmartCameraDPDataSource> dataSource;

/**
 [^en]
 does the device support this dp
 [$en]


 @param dpName dpName
 @return BOOL
*/
- (BOOL)isSupportDP:(ThingSmartCameraDPKey)dpName;

/**
 [^en]
 get the value of dp, if support the dp, else return nil.
 [$en]


 @param dpName dpName
 @return dp value
 */
- (id)valueForDP:(ThingSmartCameraDPKey)dpName;


/**
 [^en]
 will publish query command to device for the dp,
 [$en]


 @param dpName dpName
 @param success success callback
 @param failure failure callback
 */
- (void)valueForDP:(ThingSmartCameraDPKey)dpName success:(ThingSuccessID)success failure:(ThingFailureError)failure;

/**
[^en]
set the value of dp, if support the dp, else return nil
[$en]

 @param value value
 @param dpName [^en]dpName[$en]
 @param success success callback
 @param failure failure callback
*/
- (void)setValue:(id)value forDP:(ThingSmartCameraDPKey)dpName success:(ThingSuccessID)success failure:(ThingFailureError)failure;

#pragma mark - Offline Device DP Support

- (void)updateCachedDPs:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (void)pushDpValueWithHttp:(id)value dpName:(ThingSmartCameraDPKey)dpName success:(ThingSuccessID)success failure:(ThingFailureError)failure;

#pragma mark - Deprecated

- (BOOL)isSurpportDP:(ThingSmartCameraDPKey)dpName __deprecated_msg("Use isSupportDP instead");

@end

