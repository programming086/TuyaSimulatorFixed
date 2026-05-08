//
//  UINavigationController+ThingStack.h
//  ThingUIKit
//
//  Created by ThingInc on 2019/10/28.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UINavigationController (ThingStack)

/**
 [^en]Looks for an instance of the vc class in the view controller stack, first matching isMemberOf, then matching isKindOf[$en]
 */
- (__kindof UIViewController * __nullable)thing_viewControllerWithKindOfClass:(Class)vcClass;

/**
 @return [^en]return NO if -thing_viewControllerWithKindOfClass return nil[$en]
 */
- (BOOL)thing_canPopToViewControllerWithKindOfClass:(Class)vcClass;

/**
 [^en]pop to specified kind of view controller[$en]
 @return [^zh]弹出的视图[$zh] [^en]popped view controllers[$en]
 */
- (NSArray<__kindof UIViewController *> * __nullable)thing_popToViewControllerWithKindOfClass:(Class)vcClass animated:(BOOL)animated;

#pragma mark - Top To Bottom
/**
 [^en]Looks for an instance of the vc class in the view controller stack(from top to bottom), first matching isMemberOf, then matching isKindOf[$en]
 */
- (__kindof UIViewController * __nullable)thing_viewControllerFromTopWithKindOfClass:(Class)cls;

#pragma mark - Deprecated
- (BOOL)thing_canPopToSpecificViewController:(Class)vcClass __deprecated_msg("Use -ty_canPopToViewControllerWithKindOfClass: instead");
- (void)thing_popToSpecificViewController:(Class)vcClass animated:(BOOL)animated __deprecated_msg("Use -ty_popToViewControllerWithKindOfClass:animated: instead");

@end

NS_ASSUME_NONNULL_END
