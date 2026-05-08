//
//  UIViewController+TYPadSupport.h
//  TYUIKit
//
//  Created by caojw on 2021/8/11.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (TYPadSupport)

/// 支持旋转的方向
- (UIInterfaceOrientationMask)ty_interfaceOrientationMask;

/// 屏幕显示的首选项
- (UIInterfaceOrientation)ty_interfaceOrientationForPresentation;

@end

NS_ASSUME_NONNULL_END
