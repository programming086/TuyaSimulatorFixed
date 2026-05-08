
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, ThingDeviceTimerObjectLoopType) {
    /// Weekly cycle
    ThingDeviceTimerObjectLoopTypeWeek = 0,
    /// Day interval
    ThingDeviceTimerObjectLoopTypeDay = 1,
    /// Hour interval
    ThingDeviceTimerObjectLoopTypeHour = 2,
    /// 3: Even-Odd cycle 4: Cron cycle
};

/// [Cloud] Additional information for device timing model
@interface ThingDeviceTimerObjectExtra : NSObject

/// Timer ID
@property (nonatomic, copy) NSString *timerId;
/// Execution date or first execution date
@property (nonatomic, copy) NSString *date;
/// Execution time or first execution time
@property (nonatomic, copy) NSString *time;

@property ThingDeviceTimerObjectLoopType loopType;

@end


@interface ThingDeviceTimerObjectExtra (Date)

/// input: date+time
- (NSDateComponents *)dateComponents;

@end

NS_ASSUME_NONNULL_END
