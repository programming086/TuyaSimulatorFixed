
#import <Foundation/Foundation.h>

@interface ThingSmartPlaybackDate : NSObject

@property (nonatomic, assign, readonly) NSInteger year;

@property (nonatomic, assign, readonly) NSInteger month;

@property (nonatomic, assign, readonly) NSInteger day;

@property (nonatomic, strong, readonly) NSDate *date;

@property (nonatomic, assign, readonly) NSTimeInterval timeInterval;

@property (nonatomic, strong) NSTimeZone *timeZone;

+ (instancetype)playbackDateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day;

+ (instancetype)playbackDateWithYear:(NSInteger)year month:(NSInteger)month day:(NSInteger)day timeZone:(NSTimeZone *)timeZone;

+ (instancetype)playbackDateWithDate:(NSDate *)date;

+ (instancetype)playbackDateWithDate:(NSDate *)date timeZone:(NSTimeZone *)timeZone;

+ (BOOL)isToday:(ThingSmartPlaybackDate *)date;

@end
