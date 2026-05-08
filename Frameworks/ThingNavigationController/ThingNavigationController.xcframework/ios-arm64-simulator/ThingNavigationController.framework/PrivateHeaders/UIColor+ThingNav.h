//
//  UIColor+ThingNav.h
//  ThingNavigationController
//
//  Created by on 2021/11/19.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN UIColor * Thing_Nav_HexColor(uint32_t hex);

/**
 @param hex             [^zh]Hex RGB value of the color，such as  0x00FF00[$zh] [^en]RGB like 0x00FF00[$en]
 @param alpha        [^zh]Color alpha value，alpha ∈ [0, 1][$zh] [^en]alpha value, alpha ∈ [0, 1][$en]
 */
UIKIT_EXTERN UIColor * Thing_Nav_HexAlphaColor(uint32_t hex, CGFloat alpha);

@interface UIColor (ThingNav)

+ (UIColor *)thing_nav_colorWithHex:(uint32_t)hex;

+ (UIColor *)thing_nav_colorWithHex:(uint32_t)hex alpha:(CGFloat)alpha;

@end

NS_ASSUME_NONNULL_END
