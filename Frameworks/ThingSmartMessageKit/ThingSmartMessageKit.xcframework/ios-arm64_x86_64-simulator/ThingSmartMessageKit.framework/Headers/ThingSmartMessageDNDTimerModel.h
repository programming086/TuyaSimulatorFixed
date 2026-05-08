
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMessageDNDTimerModel : NSObject


/** Unique identifier for the timer */
@property (nonatomic, assign) long timerId;

/**
 * Start time string
 * For recurring DND: Format is "HH:mm"
 * For one-time DND (loops="0000000"): Format is "yyyy-MM-dd HH:mm"
 */
@property (nonatomic, strong) NSString *startTime;

/**
 * End time string
 * For recurring DND: Format is "HH:mm"
 * For one-time DND (loops="0000000"): Format is "yyyy-MM-dd HH:mm"
 */
@property (nonatomic, strong) NSString *endTime;

/** Array of device IDs affected by this DND timer */
@property (nonatomic, strong) NSArray *devIds;

/**
 * Recurrence pattern for days of week (e.g. "1111111")
 * When set to "0000000", indicates a one-time Do Not Disturb setting
 */
@property (nonatomic, strong) NSString *loops;

/** Timezone identifier (e.g. "Asia/Shanghai") */
@property (nonatomic, strong) NSString *timezoneId;

/** Timezone offset string (e.g. "+08:00") */
@property (nonatomic, strong) NSString *timezone;

/** Flag indicating if timer applies to all devices */
@property (nonatomic, assign) BOOL allDevIds;

/** Start time as timestamp string */
@property (nonatomic, strong) NSString *startTimeStamp;

/** End time as timestamp string */
@property (nonatomic, strong) NSString *endTimeStamp;

/**
 * Returns the start time as NSTimeInterval
 * @return Start timestamp as NSTimeInterval
 */
- (NSTimeInterval)startTS;

/**
 * Returns the end time as NSTimeInterval
 * @return End timestamp as NSTimeInterval
 */
- (NSTimeInterval)endTS;

/**
 * Formats a timestamp into a readable time string (HH:mm)
 * @param timestamp The time value to format
 * @return Formatted time string
 */
- (NSString *)formatTimeFromTimestamp:(NSTimeInterval)timestamp;

/**
 * Determines if the end time occurs on the next day relative to the start time
 * Compares hours and minutes to check if end time is earlier in the day than start time
 * @return YES if end time is on the next day, NO otherwise
 */
- (BOOL)endAtNextDay;

/**
 * Checks if the timer is expired
 * @return YES if the timer is expired, NO otherwise
 */
- (BOOL)expired;

/**
 Determines if the timer is configured as a one-time timer
 
 A one-time timer is identified by its loops property having a value of "0000000",
 indicating that it doesn't repeat on any day of the week.
 
 @return BOOL value indicating if the timer is one-time
         - YES: Timer is one-time (loops = "0000000")
         - NO: Timer is periodic
 */
- (BOOL)isOnceTimer;

/**
 Determines if the timer is configured as a periodic timer
 
 A periodic timer is identified by its loops property having any value other than "0000000",
 indicating that it repeats on at least one day of the week.
 
 @return BOOL value indicating if the timer is periodic
         - YES: Timer is periodic (loops != "0000000")
         - NO: Timer is one-time
 */
- (BOOL)isPeriodTimer;

@end

NS_ASSUME_NONNULL_END
