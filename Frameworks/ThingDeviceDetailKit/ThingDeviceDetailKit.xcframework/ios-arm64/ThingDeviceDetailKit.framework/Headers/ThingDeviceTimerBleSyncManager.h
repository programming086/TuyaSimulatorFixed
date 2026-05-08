
#import <Foundation/Foundation.h>
#import "ThingDeviceTimerBleSyncTask.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceTimerBleSyncManager : NSObject

+ (instancetype)sharedInstance;

- (void)requestWithTask:(ThingDeviceTimerBleSyncTask *)task;

@end

NS_ASSUME_NONNULL_END
