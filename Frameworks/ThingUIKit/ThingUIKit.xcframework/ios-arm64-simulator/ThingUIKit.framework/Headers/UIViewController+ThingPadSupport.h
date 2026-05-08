//
//  UIViewController+ThingPadSupport.h
//  ThingUIKit
//
//  Created by caojw on 2021/8/11.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (ThingPadSupport)

/// Supported direction of rotation
- (UIInterfaceOrientationMask)thing_interfaceOrientationMask;

/// Screen display preferences
- (UIInterfaceOrientation)thing_interfaceOrientationForPresentation;

@end

NS_ASSUME_NONNULL_END
