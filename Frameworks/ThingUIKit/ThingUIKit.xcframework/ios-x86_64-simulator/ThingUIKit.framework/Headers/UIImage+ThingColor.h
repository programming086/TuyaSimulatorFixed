//
//  UIImage+ThingColor.h
//  ThingUIKit
//
//  Created by ThingInc on 2018/11/27.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (ThingColor)

/**
 [^en]Create image with color[$en]
 */
+ (UIImage *)thing_imageWithColor:(UIColor *)color;

/**
[^en]Create image with color and size[$en]
*/
+ (UIImage *)thing_imageWithColor:(UIColor *)color size:(CGSize)size;

/**
 [^en]Create gradient image with colors[$en]
 */
+ (UIImage *)thing_imageWithGradient:(CAGradientLayerType)type colors:(NSArray<UIColor *> *)colors locations:(NSArray<NSNumber *> *)locations startPoint:(CGPoint)start endPoint:(CGPoint)end size:(CGSize)size;

/// Create image with corner.
/// @param radius corner radius.
/// @param size image size.
/// @param backgroundColor image color.
+ (nullable UIImage *)thing_imageWithCornerRadius:(CGFloat)radius size:(CGSize)size backgroundColor:(UIColor *)backgroundColor;

@end

NS_ASSUME_NONNULL_END
