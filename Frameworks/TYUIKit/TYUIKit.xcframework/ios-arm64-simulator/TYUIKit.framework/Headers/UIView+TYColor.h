//
//  UIView+TYColor.h
//  TYUIKit
//
//  Created by TuyaInc on 2021/11/30.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (TYColor)

/*
 返回某点所在视图对应的颜色
 
 @param point 指定点
 */
- (UIColor *)colorOfPoint:(CGPoint)point;

@end

NS_ASSUME_NONNULL_END
