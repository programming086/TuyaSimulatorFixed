//
//  UIView+ThingEmptyView.h
//  ThingUIKit
//
//  Created by ThingInc on 2019/5/21.
//

#import <UIKit/UIKit.h>

@class ThingEmptyBaseView;

NS_ASSUME_NONNULL_BEGIN

@interface UIView (ThingEmptyView)

@property (nonatomic, strong) __kindof ThingEmptyBaseView *thing_emptyView;

- (void)thing_showEmptyView:(BOOL)animate;
- (void)thing_hideEmptyView:(BOOL)animate;

@end

NS_ASSUME_NONNULL_END
