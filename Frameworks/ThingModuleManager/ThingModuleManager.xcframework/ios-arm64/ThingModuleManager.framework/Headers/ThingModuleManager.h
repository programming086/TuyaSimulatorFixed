
#import <Foundation/Foundation.h>

#import "ThingModule.h"
#import "ThingModuleRouteInterceptor.h"

@interface ThingModuleManager : NSObject

+ (_Nonnull instancetype)sharedInstance;

/**
 * Handles the application's launch process.
 *
 * This method should be called within the application:didFinishLaunchingWithOptions: of your AppDelegate
 * to initialize and configure necessary modules at launch.
 *
 * @param application The singleton app object.
 * @param launchOptions A dictionary indicating the reason the app was launched (if any).
 * @return YES if the launch process was successful, NO otherwise.
 */
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/**
 * Loads the configuration for the module manager.
 *
 * This method should be called to load necessary configurations for module management.
 */
- (void)loadConfig;

/**
 * Initializes the manager for use in an extension or widget.
 *
 * If you need to use ThingModuleManager in an app extension or widget,
 * call this method once before using the manager to ensure proper initialization.
 */
- (void)extensionDidFinishInitial;

@end

