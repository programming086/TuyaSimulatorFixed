
#import <Foundation/Foundation.h>

#import "ThingModuleServiceInfo.h"

@protocol ThingModuleServiceRegisterProtocol <NSObject>

@optional
- (NSArray<ThingModuleServiceInfo *> *)registModuleServices;

@end
