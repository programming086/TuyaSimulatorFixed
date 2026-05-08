
#import <Foundation/Foundation.h>
#import "ThingSmartMessageUtils.h"

NS_ASSUME_NONNULL_BEGIN

/// The model of a message list request in the message center.
@interface ThingSmartMessageListRequestModel : NSObject

/// The type of message.
@property (nonatomic, assign) ThingMessageType msgType;

/// The maximum number of messages that can be requested.
@property (nonatomic, assign) NSInteger limit;

/// The total number of requested messages.
@property (nonatomic, assign) NSInteger offset;

@end

// The model of a message list request in the message center.
@interface ThingSmartMessageListRequestModelV1 : NSObject

/// The maximum number of messages that can be requested.
@property (nonatomic, assign) NSInteger limit;

/// The total number of requested messages.
@property (nonatomic, assign) NSInteger offset;

/// The start time
@property (nonatomic, assign) long long startTime;

/// The end time
@property (nonatomic, assign) long long endTime;

@end

/// The model of a message detail list request in the message center.
@interface ThingSmartMessageDetailListRequestModel : NSObject

/// The type of message. Currently, only ThingMessageTypeAlarm is supported.
@property (nonatomic, assign) ThingMessageType msgType;

/// The maximum number of messages that can be requested.
@property (nonatomic, assign) NSInteger limit;

/// The total number of requested messages.
@property (nonatomic, assign) NSInteger offset;

/// The ID of the device that sends messages.
@property (nonatomic, copy) NSString *msgSrcId;

@end

@interface ThingSmartMessageListDeleteRequestModel : NSObject
/// The type of message.
@property (nonatomic, assign) ThingMessageType msgType;

/// The ID of the message.
@property (nonatomic, copy) NSArray<NSString *> *msgIds;

/// The ID of the device that sends messages.
@property (nonatomic, copy) NSArray<NSString *> *msgSrcIds;

@end

@interface ThingSmartMessageListReadRequestModel : NSObject

/// The type of message. Currently, only ThingMessageTypeAlarm is supported.
@property (nonatomic, assign) ThingMessageType msgType;

/// The ID of the message.
@property (nonatomic, copy) NSArray<NSString *> *msgIds;

@end

#pragma mark - setting

/// Day of week enum for DND settings
typedef NS_OPTIONS(NSUInteger, ThingSmartMessageDNDDay) {
    ThingSmartMessageDNDDayNone      = 0,
    ThingSmartMessageDNDDayMonday    = 1 << 0,  // 0000001
    ThingSmartMessageDNDDayTuesday   = 1 << 1,  // 0000010
    ThingSmartMessageDNDDayWednesday = 1 << 2,  // 0000100
    ThingSmartMessageDNDDayThursday  = 1 << 3,  // 0001000
    ThingSmartMessageDNDDayFriday    = 1 << 4,  // 0010000
    ThingSmartMessageDNDDaySaturday  = 1 << 5,  // 0100000
    ThingSmartMessageDNDDaySunday    = 1 << 6,  // 1000000
    ThingSmartMessageDNDDayAll       = 0x7F     // 1111111
};

/// The model of the Do Not Disturb (DND) request for devices.
@interface ThingSmartMessageSettingDNDRequestModel : NSObject

/// The start time.
@property (nonatomic, copy) NSString *startTime;

/// The end time.
@property (nonatomic, copy) NSString *endTime;

/// A list of device IDs.
@property (nonatomic, copy) NSArray<NSString *> *devIDs;

/// The weekly cycle in which the DND mode is enabled or disabled. Each bit of the string value specifies the day on which the DND mode is disabled or disabled.
///
/// Valid values: `0` means that the DND mode is disabled on the day. `1` means that the DND mode is enabled on the day. @"0000111" means that the DND mode is enabled from Friday to Sunday within a week.
///
@property (nonatomic, copy) NSString *loops DEPRECATED_MSG_ATTRIBUTE("Use setDNDDaysWithFlags: and getDNDDaysFlags instead");

/// Set DND days using flag-based day settings
/// @param days Combination of ThingSmartMessageDNDDay flags
- (void)setDNDDaysWithFlags:(ThingSmartMessageDNDDay)days;

/// Get current DND days as flag-based settings
/// @return ThingSmartMessageDNDDay flags combination
- (ThingSmartMessageDNDDay)getDNDDaysFlags;

/// Convert loops string to flag-based day settings
/// @param loopsString The loops string to convert (e.g. "0000111")
/// @return ThingSmartMessageDNDDay flags combination
+ (ThingSmartMessageDNDDay)dndDaysFromLoopsString:(NSString *)loopsString;

/// Convert flag-based day settings to loops string
/// @param days ThingSmartMessageDNDDay flags combination
/// @return The loops string representation (e.g. "0000111")
+ (NSString *)loopsStringFromDNDDays:(ThingSmartMessageDNDDay)days;

/// Specifies whether all devices support the DND mode.
///
/// 'devIDs' is not required when 'isAllDevIDs' is set to `True`.
@property (nonatomic, assign) BOOL isAllDevIDs;


@end

/// The model of a authorization Request.
@interface ThingSmartMessageAuthorizationRequestModel : NSObject

/// The  status of marketing push.
@property (nonatomic, assign) BOOL marketingPush;

/// The  status of data authorization.
@property (nonatomic, assign) BOOL dataAuthorization;

@end

/// The modelof encrypt Request.
@interface ThingSmartMessageEncryptRequestModel : NSObject

/// The message number.
@property (nonatomic, copy) NSString *businessNo;

/// The device id, such as msgSrcId.
@property (nonatomic, copy) NSString *deviceId;

/// The home id, data from ThingSmartMessageListModel
@property (nonatomic, assign) long long homeId;

/// The timestamp of a message.
@property (nonatomic, assign) NSInteger time;

@end

NS_ASSUME_NONNULL_END
