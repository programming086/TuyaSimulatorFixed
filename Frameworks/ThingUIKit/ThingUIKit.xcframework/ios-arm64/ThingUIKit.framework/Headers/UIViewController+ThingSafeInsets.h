//
//  UIViewController+ThingSafeInsets.h
//  ThingUIKit
//
//  Created by ThingInc
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (ThingSafeInsets)

/**
 [^en]
 Safe height at the top of the current page
 FullScreen modal: if there is a navigation bar, return the bottom position of the navigation bar, otherwise return the bottom position of the status bar
 PageSheet modal: if there is a navigation bar, return the bottom position of the navigation bar, otherwise return 0
 [$en]
 */
@property (nonatomic, readonly) CGFloat thing_safeTop;


@end

NS_ASSUME_NONNULL_END
