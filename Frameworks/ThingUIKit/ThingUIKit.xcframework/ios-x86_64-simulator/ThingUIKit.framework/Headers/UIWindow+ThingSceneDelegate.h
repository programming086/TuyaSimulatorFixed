//
//  UIWindow+ThingSceneDelegate.h
//  ATGestureLockView
//
//  Created by niao on 2024/4/30.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIWindow (ThingSceneDelegate)

/**
 Creates and returns a new UIWindow instance.

 This method creates a new UIWindow instance that can be used to display content on the screen.
 It supports the new UIWindowScene API introduced in iOS 13, which allows for multiple windows
 in applications that support multiple scenes. If the application is running on iOS 13 or later,
 it attempts to find an active UIWindowScene in the foreground and creates the window with it.
 If no active UIWindowScene is found or the application is running on an earlier version of iOS,
 it creates the window using the main screen's bounds.

 @return An instance of UIWindow configured with either a UIWindowScene or the main screen's bounds.
 */
+(instancetype)thing_createWindow;

@end

NS_ASSUME_NONNULL_END
