
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingMixBrightnessSliderType) {
    ThingMixBrightnessSliderColdWarmType,  // Mixed light warm and cold brightness
    ThingMixBrightnessSliderColorType, // Mixed light brightness
};

@interface ThingMixBrightnessSlider : UIView

/**
 * Constructor, callback returns brightness value
 *
 * @param type Slider type (vertical slider: ThingBrightnessSliderPortraitType, horizontal slider: ThingBrightnessSliderLandscapeType)
 * @param touchingCompletion Callback for sliding gesture changes
 * @param endCompletion  Callback when the sliding gesture stops
 */
+ (instancetype)brightnessPercent:(ThingMixBrightnessSliderType)type
                   touchingHandle:(void (^)(NSInteger percent))touchingCompletion
                   touchEndHandle:(void (^)(NSInteger percent))endCompletion;

/// Minimum brightness
@property (nonatomic, assign) NSInteger minPercent;
/// Initial brightness
@property (nonatomic, assign) NSInteger anchorPercent;
/// switch
@property (nonatomic, assign) BOOL sliderEnabled;
/// Regulator bottom view rounded corners
@property (nonatomic, assign) CGFloat backgroundCornerRadius;
/// Regulator bottom view color
@property (nonatomic, strong) UIColor *backgroundColor;
/// Adjuster view foreground color
@property (nonatomic, strong) UIColor *frontColor;
/// Brightness icon
@property (nonatomic, strong) UIImage *customImage;
/// Whether to display percentage
@property (nonatomic, assign) BOOL shouldShowPercent;
/// percent label
@property (nonatomic, strong) UILabel *percentLabel;

@end

NS_ASSUME_NONNULL_END
