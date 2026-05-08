
#import <UIKit/UIKit.h>

@class ThingSlider;

@protocol ThingSliderDelegate <NSObject>

@required
- (void)onSliderValueChanged:(ThingSlider *)slider;
- (void)onSlidingComplete:(ThingSlider *)slider;

@end

@interface ThingSlider : UISlider

@property (nonatomic, weak) id <ThingSliderDelegate> delegate;
@property (nonatomic, assign) float step;
@property (nonatomic, strong) UIImage *minimumTrackImage;
@property (nonatomic, strong) UIImage *maximumTrackImage;
@property (nonatomic, strong) UIImage *thumbImage;
@property (nonatomic, assign) CGFloat trackHeight;

- (void)resizeTrackImageView;
- (void)removeAllTrackImage;

@end
