//
//  UIView+ThingCorner.h
//  ThingUIKit
//
//  Created by jindu on 2020/7/30.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (ThingCorner)

/**
 *  Set partial rounded corners (absolute layout)
 *
 *  @param corners Corners that need to be rounded. UIRectCornerTopLeft | UIRectCornerTopRight | UIRectCornerBottomLeft | UIRectCornerBottomRight | UIRectCornerAllCorners
 *  @param radii   The rounded corner size that needs to be set, for example CGSizeMake(20.0f, 20.0f)
 */
- (void)addRoundedCorners:(UIRectCorner)corners
                withRadii:(CGSize)radii;
/**
 *  Set partial rounded corners (Relative Layout)
 *
 *  @param corners Corners that need to be rounded. UIRectCornerTopLeft | UIRectCornerTopRight | UIRectCornerBottomLeft | UIRectCornerBottomRight | UIRectCornerAllCorners
 *  @param radii   The rounded corner size that needs to be set, for example CGSizeMake(20.0f, 20.0f)
 *  @param rect    The rect of the rounded view that needs to be set
 */
- (void)addRoundedCorners:(UIRectCorner)corners
                withRadii:(CGSize)radii
                 viewRect:(CGRect)rect;


@end

NS_ASSUME_NONNULL_END
