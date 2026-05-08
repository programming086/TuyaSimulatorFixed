
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface ThingTimeoutTask : NSObject
@property (nonatomic, strong, readonly) NSString *taskId;
@property (nonatomic, strong) NSDictionary *userInfo;

- (instancetype)initWithTaskId:(NSString *)taskId userInfo:(NSDictionary *_Nullable)userInfo;
+ (instancetype)taskWithTaskId:(NSString *)taskId userInfo:(NSDictionary *_Nullable)userInfo;
@end


@protocol ThingTimeoutTaskManagerDelagate <NSObject>
@required
- (void)timeoutTaskManagerFinishedTask:(ThingTimeoutTask *)task;
@end


/// Manages task timeouts; supports thread safety
@interface ThingTimeoutTaskManager : NSObject

// Indicates if the task with the same taskId should only complete once; default is NO
@property (nonatomic, assign) BOOL onceTask;

// Initializer method that accepts a timeout in seconds as a parameter
- (instancetype)initWithTimeoutSeconds:(NSInteger)seconds;

// Callback when a task times out
@property (nonatomic, weak) id<ThingTimeoutTaskManagerDelagate> delegate;

// Method to check if there's a running task for the given task ID
- (BOOL)isRunningTaskId:(NSString *)taskId;

// List of running task IDs
- (NSArray<NSString *> *)runningTaskId;

// Method to start a task, accepting a task ID as a parameter
- (void)startTaskWithTaskId:(NSString *)taskId;

- (void)startTaskWithTask:(ThingTimeoutTask *)task;


// Method to finish a task, accepting a task ID as a parameter
- (void)finishTaskWithTaskId:(NSString *)taskId;


// Pauses the timer; after pausing, calling startTaskWithTaskId: will discard the task
- (void)pause;

// Resumes the timer; resets the timeout for already timing tasks, recalculating the timeout duration
- (void)resume;

@end

NS_ASSUME_NONNULL_END
