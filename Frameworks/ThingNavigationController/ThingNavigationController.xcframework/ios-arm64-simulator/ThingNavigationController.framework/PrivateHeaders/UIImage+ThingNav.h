//
//  UIImage+ThingNav.h
//  ThingNavigationController
//
//  Created by on 2021/11/19.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (ThingNav)

/**
 [^en]Create image with color[$en]
 */
+ (UIImage *)thing_nav_imageWithColor:(UIColor *)color;

/**
[^en]Create image with color and size[$en]
*/
+ (UIImage *)thing_nav_imageWithColor:(UIColor *)color size:(CGSize)size;

/**
 [^en]Create gradient image with colors[$en]
 */
+ (UIImage *)thing_nav_imageWithGradient:(CAGradientLayerType)type colors:(NSArray<UIColor *> *)colors locations:(NSArray<NSNumber *> *)locations startPoint:(CGPoint)start endPoint:(CGPoint)end size:(CGSize)size;

/// Create image with corner.
/// @param radius corner radius.
/// @param size image size.
/// @param backgroundColor image color.
+ (nullable UIImage *)thing_nav_imageWithCornerRadius:(CGFloat)radius size:(CGSize)size backgroundColor:(UIColor *)backgroundColor;

+ (UIImage *)thing_nav_imageWithLayer:(CALayer *)layer;
+ (UIImage *)thing_nav_imageWithView:(UIView *)view;

- (UIImage *)thing_nav_imageApplyingAlpha:(CGFloat)alpha;

@end

NS_ASSUME_NONNULL_END
