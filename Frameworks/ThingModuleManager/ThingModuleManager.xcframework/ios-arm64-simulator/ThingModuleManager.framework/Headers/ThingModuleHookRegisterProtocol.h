
#import <Foundation/Foundation.h>

#import "ThingModuleHookInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingModuleHookRegisterProtocol <NSObject>

- (NSArray<ThingModuleHookInfo *> *)registModuleHooks;

@end

NS_ASSUME_NONNULL_END
