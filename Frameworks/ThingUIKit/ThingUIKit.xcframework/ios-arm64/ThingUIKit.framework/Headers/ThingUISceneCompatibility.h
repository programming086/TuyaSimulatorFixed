
#import <Foundation/Foundation.h>


API_AVAILABLE(ios(13.0))
typedef NS_OPTIONS(NSUInteger, ThingUISceneCompatibilityOption){
    /// Compatibility for using UIScene, as AppDelegate no longer has a window property, which may cause "[AppDelegate window]: unrecognized selector sent to instance" error
    /// @discussion Adds a window property to UIApplication's delegate. Hooks the method to return the window of the UIScene passed to enableWithUIScene:. If not available, returns the content of [UIApplication sharedApplication].windows.
    ThingUISceneCompatibilityOfAppDelegate NS_SWIFT_NAME(appDelegate)  = 1 << 0,
    /// Resolves the issue where UIWindow is not created through UIWindowScene and thus cannot determine which screen to display on, causing it not to be displayed.
    /// @discussion Hooks the init and initWithFrame methods of UIWindow. When called, they will be converted to initWithWindowScene: and use the UIScene passed to enableWithUIScene:. If UIScene is not available, the original method will be called.
    ThingUISceneCompatibilityOfWindow NS_SWIFT_NAME(window) = 1 << 1,
    
    /// all of compatibility option
    ThingUISceneCompatibilityOptionAll NS_SWIFT_NAME(all) =  ThingUISceneCompatibilityOfAppDelegate | ThingUISceneCompatibilityOfWindow,
};


NS_ASSUME_NONNULL_BEGIN
API_AVAILABLE(ios(13.0))
@interface ThingUISceneCompatibility : NSObject
/// Enables UIScene compatibility
/// @warning Not supported for multiple UIWindowSceneSessionRoleApplication type UIScenes. Once compatibility is enabled, opening a new UIWindowSceneSessionRoleApplication type UIScene will trigger an assertion.
/// @warning Not thread-safe
/// @param scene The UIWindowScene used to start the SDK. Used for compatibility with three target processes.
+ (void)enableWithUIScene:(nonnull UIWindowScene *)scene;

/// Enables UIScene compatibility
/// @warning Not thread-safe
/// @note Uses the first UIWindowScene from connectedScenes for subsequent compatibility.
+ (void)enable DEPRECATED_MSG_ATTRIBUTE("use +enableWithUIScene:compatibilityOption:");

@end

NS_ASSUME_NONNULL_END
