//
//  UIViewController+TabBar.h
//  ThingModuleManager
//
//  Created by Hiraeth on 2024/6/20.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A category on UIViewController to manage tab bar related actions.
 *
 * This wrapper provides a workaround for potential cyclic dependencies in UIKit when interacting with tab bar controllers.
 */
@interface UIViewController (TabBar)

/**
 * Navigates back to the first page of the tab bar's navigation hierarchy.
 *
 * This method animates the transition back to the root view controller of the current tab.
 *
 * @param animated A Boolean value that determines whether the transition is animated.
 * @param completion A block object to be executed when the transition finishes. This block has no return value and takes no parameters.
 */
- (void)tabbar_goBackToFirstPage:(BOOL)animated completion:(dispatch_block_t)completion;

@end

NS_ASSUME_NONNULL_END
