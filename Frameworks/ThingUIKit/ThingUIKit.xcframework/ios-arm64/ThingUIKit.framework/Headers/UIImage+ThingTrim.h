//
//  UIImage+ThingTrim.h
//  ThingUIKit
//
//  Created by ThingInc on 2018/12/20.
//

#import <UIKit/UIKit.h>

@interface UIImage (ThingTrim)

#pragma mark - Resize
/**
 [^en]resize image with scale[^en]
 */
- (UIImage *)thing_imageApplyingScale:(CGFloat)scale;
/**
[^en]resize image[^en]
*/
- (UIImage *)thing_imageApplyingSize:(CGSize)newSize;
/**
[^en]resize image with content mode[^en]
*/
- (UIImage *)thing_imageApplyingSize:(CGSize)newSize withContentMode:(UIViewContentMode)contentMode;

#pragma mark - Crop
/**
 [^en]crop image[$en]
 */
- (UIImage *)thing_imageApplyingCropRect:(CGRect)rect;

#pragma mark - Corner/Border
/**
 [^en]re-render image with corner[$en]
 */
- (UIImage *)thing_imageApplyingCornerRadius:(CGFloat)radius;
- (UIImage *)thing_imageApplyingCornerRadius:(CGFloat)radius withBorderWidth:(CGFloat)borderWidth borderColor:(UIColor *)borderColor;

#pragma mark - Rotation
/**
[^en]flip image horizontally[$en]
*/
- (UIImage *)thing_imageApplyingHorizontalFlip;
/**
[^en]flip image vertically[$en]
*/
- (UIImage *)thing_imageApplyingVerticalFlip;

#pragma mark - TintColor
/**
 [^en]re-render image with tint color[$en]
 */
- (UIImage *)thing_imageApplyingTintColor:(UIColor *)color;

#pragma mark - Alpha
/**
 [^zh]re-render image with alpha[$zh]
 */
- (UIImage *)thing_imageApplyingAlpha:(CGFloat)alpha;


/// Rotate the picture
/// - Parameter degrees: ` > 0 and < 360`
- (UIImage *)thing_imageRotatedByDegrees:(CGFloat)degrees;

@end
