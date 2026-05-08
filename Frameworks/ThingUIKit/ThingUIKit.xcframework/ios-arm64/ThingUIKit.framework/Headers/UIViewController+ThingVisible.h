//
//  UIViewController+ThingVisible.h
//  ThingActivatorModule
//
//  Created by ThingInc on 2020/8/4.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (ThingVisible)

/// Whether it is visible at the top level
@property (nonatomic, assign, readonly, getter=isThing_visible) BOOL thing_visible;

/// check is home page
- (BOOL)isFirstPage;

/// Subscript in Tabbar
- (NSInteger)visibleTabIndex;

@end

NS_ASSUME_NONNULL_END
