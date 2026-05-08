//
//  UIColor+ThingHex.h
//  ThingUIKit
//
//  Created by ThingInc on 2018/12/17.
//

#import <UIKit/UIKit.h>

/**
 @param hex     [^en]RGB like 0x00FF00, or ARGB like 0xFF00FF00[$en]
 */
UIKIT_EXTERN UIColor * Thing_HexColor(uint32_t hex);

/**
 @param hex          [^en]RGB like 0x00FF00[$en]
 @param alpha      [^en]alpha value, alpha ∈ [0, 1][$en]
 */
UIKIT_EXTERN UIColor * Thing_HexAlphaColor(uint32_t hex, CGFloat alpha);


@interface UIColor (ThingHex)

/**
 @param hex           [^en]RGB like 0x00FF00, or ARGB like 0xFF00FF00[$en]
 */
+ (UIColor *)thing_colorWithHex:(uint32_t)hex;
/**
 @param hex             [^en]RGB like 0x00FF00[$en]
 @param alpha         [^en]alpha value, alpha ∈ [0, 1][$en]
 */
+ (UIColor *)thing_colorWithHex:(uint32_t)hex alpha:(CGFloat)alpha;

/**
 @param hexStr         [^en]RGB like 0x00FF00, or ARGB like 0xFF00FF00[$en]
 @return [^en]return nil if hexStr is illegal[$en]
 */
+ (UIColor *)thing_colorWithHexString:(NSString *)hexStr;
/**
 @param hexStr          [^en]RGB like 0x00FF00, or ARGB like 0xFF00FF00[$en]
 @param alpha            [^en]alpha value, alpha ∈ [0, 1][$en]
 @return [^en]return nil if hexStr is illegal[$en]
 */
+ (UIColor *)thing_colorWithHexString:(NSString *)hexStr alpha:(CGFloat)alpha;

/**
 @return [^en]ARGB like @"#FF00FF00"[$en]
 */
- (NSString *)thing_ARGBHexString;
/**
 @return [^en]RGB hex string like "#00FF00", alpha will be ignore[$en]
 */
- (NSString *)thing_RGBHexString;

@end
