
#import <UIKit/UIKit.h>

@interface ThingNavigationBar : UINavigationBar

@property (nonatomic, strong) UIColor *naviSeparatorColor;
@property (nonatomic, strong) UIImage *naviSeparatorImage;

@property (nonatomic, strong) UIColor *naviBackgroundColor;

@property (nonatomic) CGFloat naviBackgroundAlpha;
@property (nonatomic) CGFloat naviBlurAlpha;
@property (nonatomic) CGFloat naviSeparatorAlpha;

@property (nonatomic) CGFloat naviAlpha;

@property (nonatomic) BOOL naviHitThrough;

- (void)updateBackgroundWith:(UIImage *)img layer:(CALayer *)layer;

@end
