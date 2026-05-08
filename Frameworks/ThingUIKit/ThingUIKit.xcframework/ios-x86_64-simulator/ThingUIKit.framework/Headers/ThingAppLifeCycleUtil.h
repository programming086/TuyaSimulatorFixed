
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingAppLifeCycleUtil : NSObject

/// Delay exiting apps.
/// Will first compensate and send UIApplicationWillTerminateNotification, then exit the app after 2 seconds
/// @note It is recommended to add loading before calling to improve user experience
+ (void)delayExitApplication;

@end

NS_ASSUME_NONNULL_END
