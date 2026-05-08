
#import <Foundation/Foundation.h>
#import <ThingSmartMessageKit/ThingSmartDeviceAlarmServiceInfoEntity.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Enum representing the type of message push switch.
 */
typedef NS_ENUM(NSUInteger, ThingSmartMessagePushSwitchType) {
    ThingSmartMessagePushSwitchTypeDeviceAlarm = 0,  // Device alarm push switch
    ThingSmartMessagePushSwitchTypeFamily = 1,       // Family-related push switch
    ThingSmartMessagePushSwitchTypeNotice = 2,       // Notice-related push switch
    ThingSmartMessagePushSwitchTypeMarketing = 4,    // Marketing-related push switch
};

/**
 *  Enum representing the push channel for device alarms.
 */
typedef NS_ENUM(NSUInteger, ThingSmartDeviceAlarmPushChannel) {
    ThingSmartDeviceAlarmPushChannelSystem = 0,  // System notifications
    ThingSmartDeviceAlarmPushChannelPhone = 9,   // Phone calls
    ThingSmartDeviceAlarmPushChannelSMS = 10,    // SMS messages
    ThingSmartDeviceAlarmPushChannelAll = 11,    // All channels
};

/**
 *  Model representing a request to switch the message push settings.
 */
@interface ThingSmartMessagePushSwitchRequestModel : NSObject
/// The status of push switch
@property (nonatomic, assign) BOOL open;
/// The type of push message
@property (nonatomic, assign) ThingSmartMessagePushSwitchType type;
@end

/**
 *  Model representing a request to switch the device alarm push settings.
 */
@interface ThingSmartDeviceAlarmSwitchRequestModel : NSObject
/// The status of device alarm
@property (nonatomic, assign) BOOL open;
/// Specifies the push channel for the alarm.
@property (nonatomic, assign) ThingSmartDeviceAlarmPushChannel pushChannel;
@end

/**
 *  Model representing a request to set the throttle time for device alarms.
 */
@interface ThingSmartDeviceAlarmThrottleTimeRequestModel : NSObject
/// Throttle Time
@property (nonatomic, assign) NSInteger minute;
/// Specifies the push channel for the alarm.
@property (nonatomic, assign) ThingSmartDeviceAlarmPushChannel pushChannel;
@end

/**
 *  Model representing a request to get service information for device alarms.
 */
@interface ThingSmartDeviceAlarmServiceRequestModel : NSObject
/// The device Id
@property (nonatomic, copy) NSString *deviceId;
/// The family Id
@property (nonatomic, assign) long long homeId;
/// Specifies the push channel for the alarm.
@property (nonatomic, assign) ThingSmartDeviceAlarmPushChannel pushChannel;
@end

/**
 *  Model representing a request to update service information for device alarms.
 */
@interface ThingSmartDeviceAlarmServiceUpdateRequestModel : NSObject
/// The device Id
@property (nonatomic, copy) NSString *deviceId;
/// The family Id
@property (nonatomic, assign) long long homeId;
/// Specifies the push channel for the alarm.
@property (nonatomic, assign) ThingSmartDeviceAlarmPushChannel pushChannel;
/// Specifies an array of device alarm configuration
@property (nonatomic, copy) NSArray *configIds;
/// List of alarm services
@property (nonatomic, copy) NSArray<ThingSmartDeviceAlarmServiceInfoEntity *> *alarmServices;  
@end

/**
 *  Model representing a request to get a list of device alarms.
 */
@interface ThingSmartDeviceAlarmListRequestModel : NSObject
/// The page number
@property (nonatomic, assign) NSInteger pageNumber;
/// The page size
@property (nonatomic, assign) NSInteger pageSize;
/// The family Id
@property (nonatomic, assign) long long homeId;
/// Specifies the push channel for the alarm.
@property (nonatomic, assign) ThingSmartDeviceAlarmPushChannel pushChannel;
@end

NS_ASSUME_NONNULL_END
