
#import <Foundation/Foundation.h>
#import "ThingDeviceTimerBleSyncTask.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceTimerBleSyncTaskManager : NSObject

/// Timeout interval for each task. The default is 0, which means no timeout is set.
@property (nonatomic, assign) NSTimeInterval timeout;

- (instancetype)initWithDevId:(NSString *)devId;

- (void)addWithTask:(ThingDeviceTimerBleSyncTask *)task;

@property (nonatomic, copy) void(^completionHandle)(void);

@end

NS_ASSUME_NONNULL_END
