
#import <Foundation/Foundation.h>
#import "ThingDeviceTimerOperator.h"

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName const ThingDeviceTimerAddNotificationName;
extern NSNotificationName const ThingDeviceTimersChangeNotificationName;
extern NSNotificationName const ThingDeviceTimerUpdateNotificationName;

@interface ThingDeviceTimerManager : NSObject <ThingDeviceTimerOperator>

@end

NS_ASSUME_NONNULL_END
