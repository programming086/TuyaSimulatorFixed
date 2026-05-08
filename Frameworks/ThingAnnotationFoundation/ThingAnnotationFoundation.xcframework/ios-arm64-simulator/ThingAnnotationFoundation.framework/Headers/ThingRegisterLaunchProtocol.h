
#import "ThingBaseAnnotation.h"


typedef enum : NSUInteger {
    ThingLaunchTaskRunMode_AsyncOnGlobal   = 0,      /**< Asynchronous execution to the global queue */
    ThingLaunchTaskRunMode_AsyncOnMain     = 1,      /**< Asynchronous execution to the main queue */
    // In the main thread serial because of the greater impact on the startup time, for internal reservation type, please call if you need
} ThingLaunchTaskRunMode;

typedef enum : NSUInteger {
    ThingLaunchTaskPriority_Low = 250,
    ThingLaunchTaskPriority_Default = 750,
    ThingLaunchTaskPriority_Hight = 1000,
} ThingLaunchTaskPriority;


@protocol ThingRegisterLaunchProtocol <NSObject>

@optional

//Routing priority, default is EAnnotationPriorityBase (0)
//+ (NSNumber *)launchPriority;
//+ (void)launchAnnotationTask;


@required
/*
 Start execution. Please write the tasks to be executed under this callback
 */
- (void)start;

@optional

/// Set the task, call it in the main thread, and execute all tasks together. Here we only recommend necessary initialization and monitoring registration operations.

- (void)setupTask;

/*
 Execution mode [Default: ThingLaunchTaskRunMode_AsyncOnGlobal]
 */
+ (ThingLaunchTaskRunMode)runMode;

/**
 Priority, default is ThingLaunchTaskPriority_Default
 */
+ (ThingLaunchTaskPriority)priority;

@end
