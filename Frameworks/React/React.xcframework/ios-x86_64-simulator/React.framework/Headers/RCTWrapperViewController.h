/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

@class RCTNavItem;
@class RCTWrapperViewController;

@protocol RCTWrapperViewControllerNavigationListener <NSObject>

- (void)wrapperViewController:(RCTWrapperViewController *)wrapperViewController
didMoveToNavigationController:(UINavigationController *)navigationController;

@end

@interface RCTWrapperViewController : UIViewController

@property (nonatomic, readonly, strong) id<UILayoutSupport> currentTopLayoutGuide;
@property (nonatomic, readonly, strong) id<UILayoutSupport> currentBottomLayoutGuide;

- (instancetype)initWithContentView:(UIView *)contentView NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithNavItem:(RCTNavItem *)navItem;

@property (nonatomic, weak) id<RCTWrapperViewControllerNavigationListener> navigationListener;
@property (nonatomic, strong) RCTNavItem *navItem;

@end
