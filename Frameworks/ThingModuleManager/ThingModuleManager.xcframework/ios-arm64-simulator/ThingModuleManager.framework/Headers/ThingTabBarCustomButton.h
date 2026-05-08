
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingTabBarCustomButton : UIButton

@property (nonatomic) CGPoint thing_centerOffset;

/**
 * A hit mask image used to define the clickable area of the button.
 *
 * This image is used to specify a custom hit area for the button. Areas of the mask with an alpha value greater than 
 * 85% are considered clickable. This feature is useful for creating non-rectangular buttons with custom shapes.
 */
@property (nonatomic, strong) UIImage *thing_hitMask; 

@end

NS_ASSUME_NONNULL_END
