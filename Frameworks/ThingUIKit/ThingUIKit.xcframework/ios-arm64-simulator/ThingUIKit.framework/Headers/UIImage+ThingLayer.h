//
//  UIImage+ThingLayer.h
//  ThingUIKit
//
//  Created by ThingInc on 2018/11/27.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (ThingLayer)

+ (UIImage *)thing_imageWithLayer:(CALayer *)layer;
+ (UIImage *)thing_imageWithView:(UIView *)view;

@end

NS_ASSUME_NONNULL_END
