
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingMiniAppDebugProtocol <NSObject>

/// return latest jssdk version
- (NSString *)getJSSdkVersion;

/// return miniapp container version
- (NSString *)getMiniAppContainerVersion;

/// return current app kit dependencies
- (NSDictionary *)getMiniAppKitsVersion;

/// vConsole debugging switch
/// - Parameter enable: Whether to turn on the debugging switch
- (void)vConsoleDebugEnable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
