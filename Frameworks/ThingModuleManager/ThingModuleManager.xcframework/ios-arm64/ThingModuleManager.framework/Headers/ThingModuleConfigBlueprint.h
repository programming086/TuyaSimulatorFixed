
#import <Foundation/Foundation.h>

#import "ThingModuleApplicationBlueprint.h"
#import "ThingModuleServiceRegisterProtocol.h"
#import "ThingModuleTabRegisterProtocol.h"

#import "ThingTabBarControllerProtocol.h"

@protocol ThingModuleConfigBlueprint <ThingModuleBaseBlueprint>

@property (nonatomic, strong, readonly, nonnull) NSDictionary *originalData;

@property (nonatomic, strong, readonly, nullable) Class<ThingModuleApplicationBlueprint> applicationModule;

/**
 * All modules that need to be loaded.
 *
 * A list of module classes conforming to `ThingModuleServiceRegisterProtocol` that need to be instantiated.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<Class<ThingModuleServiceRegisterProtocol>> *buildModules;


/**
 * Modules that need to display on the tab bar.
 *
 * A list of module classes conforming to `ThingModuleTabRegisterProtocol` that are intended to be displayed as tabs.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<Class<ThingModuleTabRegisterProtocol>> *moduleOnTabBar;

/**
 * The default select module on the tab bar.
 *
 * Defines which module should be selected by default when the tab bar is displayed.
 */
@property (nonatomic, strong, readonly, nullable) Class<ThingModuleTabRegisterProtocol> tabSelectedModule;


/**
 map of Mix Mode
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary<NSString *, Class> *mixMapping;


/**
 * Retrieves the value for the specified key path in the original data.
 *
 * This method navigates through the `originalData` dictionary using a key path, which supports dot notation and arrays.
 * Example key paths: "a_path", "a_path.sub_path", "a_path.[2].sub_path"
 *
 * @param keyPath The key path used to search for the value.
 * @return The value found at the specified key path.
 */
- (id)configValueForKeyPath:(NSString *)keyPath;

/**
 * Finds the class for the specified module name.
 *
 * This method resolves and returns the class that corresponds to a given module name.
 * For example, input: `"TestModule"`, it may return `TestModuleImpl` or `TestModule` class.
 *
 * @param moduleName The name of the module.
 * @return The class associated with the given module name, or `nil` if not found.
 */
- (nullable Class)validClassOfConfigClass:(nonnull NSString *)moduleName;

/**
 * Retrieves the class for the specified key path in the original data.
 *
 * Navigates through the `originalData` dictionary similar to `configValueForKeyPath:`, but returns a class type.
 *
 * @param keyPath The key path used to search for the class.
 * @return The class found at the specified key path, or `nil` if not found.
 */
- (nullable Class)validClassOfConfigKeyPath:(nonnull NSString *)keyPath;

@end
