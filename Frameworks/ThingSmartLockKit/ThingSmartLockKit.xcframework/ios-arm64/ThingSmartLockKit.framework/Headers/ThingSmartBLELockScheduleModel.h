
#import <Foundation/Foundation.h>
#import <YYModel/NSObject+YYModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSInteger {
    ScheduleDayOfWeek_MONDAY = 1 << 5,
    ScheduleDayOfWeek_TUESDAY = 1 << 4,
    ScheduleDayOfWeek_WEDNESDAY = 1 << 3,
    ScheduleDayOfWeek_THURSDAY = 1 << 2,
    ScheduleDayOfWeek_FRIDAY = 1 << 1,
    ScheduleDayOfWeek_SATURDAY = 1,
    ScheduleDayOfWeek_SUNDAY = 1 << 6
} ScheduleDayOfWeek;

@interface ThingSmartBLELockScheduleModel : NSObject

@property (nonatomic, assign) BOOL allDay; // Whether it repeats cyclically
@property (nonatomic, assign) NSInteger effectiveTime; // Effective time. For example, if it takes effect at 9 o'clock, then pass in 9 multiplied by 60 = 540
@property (nonatomic, assign) NSInteger invalidTime; // Expiration time. For example, if it expires at 18 o'clock, then pass in 18 multiplied by 60 = 1080
@property (nonatomic, assign) NSInteger workingDay; // Here is a decimal value representation, with a week represented by one byte, bit0 ~ bit6 representing Sunday ~ Saturday respectively

// Convert binary week value to hexadecimal week value, which is required for sending to the device
- (NSString *)convertWorkingDay:(NSMutableSet *)dayOfWeeks isZigbee:(BOOL)isZigbee;

@end

// Required for password distribution interface
@interface ThingSmartBLELockScheduleList : NSObject

@property (nonatomic, strong) NSMutableArray<ThingSmartBLELockScheduleModel *> *scheduleList;

@end

// Required for member validity period change interface
@interface ThingSmartBLELockTimeScheduleInfo : NSObject

@property (nonatomic, assign) NSInteger effectiveTime; // Effective time
@property (nonatomic, assign) NSInteger expiredTime; // Expiration time
@property (nonatomic, assign) BOOL permanent; // Whether it is permanent

@property (nonatomic, strong) NSMutableArray<ThingSmartBLELockScheduleModel *> *scheduleDetails;

@end

NS_ASSUME_NONNULL_END
