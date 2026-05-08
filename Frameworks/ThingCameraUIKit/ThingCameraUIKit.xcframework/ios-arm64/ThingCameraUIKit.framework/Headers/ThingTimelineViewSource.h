
#import <Foundation/Foundation.h>

@protocol ThingTimelineViewSource <NSObject>

/// the time slice start time, seconds of the day
- (NSTimeInterval)startTimeIntervalSinceDate:(NSDate *)date;

/// the time slice end time, seconds of the day
- (NSTimeInterval)stopTimeIntervalSinceDate:(NSDate *)date;

@optional

- (int)getEventType;

- (int)getRecordType;

@end
