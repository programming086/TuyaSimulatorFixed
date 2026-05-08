//
//  UIView+ThingColor.h
//  ThingUIKit
//
//  Created by ThingInc on 2021/11/30.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (ThingColor)

/*
 Returns the color of the view corresponding to a point
 
 @param point point
 */
- (UIColor *)colorOfPoint:(CGPoint)point;

@end

NS_ASSUME_NONNULL_END
