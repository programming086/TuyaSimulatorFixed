
#import <Foundation/Foundation.h>

#import "ThingModuleBaseBlueprint.h"
#import "ThingLaunchTaskProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingModuleLaunchTaskBlueprint <ThingModuleBaseBlueprint>

@property (nonatomic) BOOL enableCircleCheck;   /**< Enables circular dependency check. By default, it is only enabled in DEBUG mode. */

- (void)registLaunchTask:(Class<ThingLaunchTaskProtocol>)taskCls;
- (void)registLaunchTaskFromArray:(NSArray<Class<ThingLaunchTaskProtocol>> *)taskArr;

/**
 * Executes the registered launch tasks.
 *
 * This method first executes serial tasks. After the serial tasks are complete, it executes concurrent tasks 
 * (those that should run asynchronously on the main thread and in the global queue). The method will finish 
 * once these concurrent tasks are initiated.
 */
- (void)executeLaunchTasks;

@end

NS_ASSUME_NONNULL_END
