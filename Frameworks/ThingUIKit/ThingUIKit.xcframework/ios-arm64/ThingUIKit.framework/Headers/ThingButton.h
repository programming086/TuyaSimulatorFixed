
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ThingButtonImageLocationLeft,  ///< [^en]the image is on the left[$en]
    ThingButtonImageLocationRight, ///< [^en]the image is on the right[$en]
    ThingButtonImageLocationTop,   ///< [^en]the image is on the top[$en]
    ThingButtonImageLocationBottom ///< [^en]the image is on the bottom[$en]
} ThingButtonImageLocation;


@interface ThingButton : UIButton

/*
 [^zh]position of the image relative to the button[$zh]
 */
@property (nonatomic) ThingButtonImageLocation thing_imageLocation;

/*
 [^en]space between image and title[$en]
 */
@property (nonatomic) CGFloat thing_imageTitleSpace;

- (void)thing_setBackgroundColor:(UIColor *)color forState:(UIControlState)state;
- (UIColor *)thing_backgroundColorForState:(UIControlState)state;

@end

NS_ASSUME_NONNULL_END
