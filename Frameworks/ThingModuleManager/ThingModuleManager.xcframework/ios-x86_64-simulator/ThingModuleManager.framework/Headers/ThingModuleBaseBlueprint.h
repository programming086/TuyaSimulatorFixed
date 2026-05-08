
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingModuleBaseBlueprint <NSObject>

@optional
/**
 * Returns an instance of the module.
 *
 * If this method is not implemented, the default behavior is to automatically call +new.
 *
 * For modules that need singleton behavior, there are two suggested approaches:
 * 1. Implement this method to return the singleton instance directly.
 * 2. Set ThingModuleServiceInfo.singleton to YES during registration. This allows moduleService to retain the instance.
 *
 * It is recommended to prioritize the use of approach 2, as singletons can have issues with inheritance.
 * All foundational components are implemented based on approach 2.
 *
 * @return An instance of the module.
 */
+ (instancetype)oneInstance;

@end

NS_ASSUME_NONNULL_END
