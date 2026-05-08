
#import <Foundation/Foundation.h>

#import "ThingLaunchTaskProtocol.h"

@protocol ThingModuleLaunchTaskRegisterProtocol <NSObject>

@optional
- (NSArray<Class<ThingLaunchTaskProtocol>> *)registLaunchTasks;

@end
