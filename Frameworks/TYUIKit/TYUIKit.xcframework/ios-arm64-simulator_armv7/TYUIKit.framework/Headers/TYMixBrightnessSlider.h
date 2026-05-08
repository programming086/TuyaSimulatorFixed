//
//  TYMixBrightnessSlider.h
//  TYUIKit
//
//  Created by TuyaInc on 2021/1/11.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TYMixBrightnessSliderType) {
    TYMixBrightnessSliderColdWarmType,  // 混光冷暖亮度
    TYMixBrightnessSliderColorType, // 混光彩光亮度
};

@interface TYMixBrightnessSlider : UIView

/**
 * 构造方法，回调返回亮度值
 *
 * @param type 调节器类型（纵向调节器：TYBrightnessSliderPortraitType、横向调节器：TYBrightnessSliderLandscapeType）
 * @param touchingCompletion 滑动手势变化的回调
 * @param endCompletion  滑动手势停止时的回调
 */
+ (instancetype)brightnessPercent:(TYMixBrightnessSliderType)type
                   touchingHandle:(void (^)(NSInteger percent))touchingCompletion
                   touchEndHandle:(void (^)(NSInteger percent))endCompletion;

/// 最低亮度
@property (nonatomic, assign) NSInteger minPercent;
/// 初始亮度
@property (nonatomic, assign) NSInteger anchorPercent;
/// 开关
@property (nonatomic, assign) BOOL sliderEnabled;
/// 调节器底部视图圆角
@property (nonatomic, assign) CGFloat backgroundCornerRadius;
/// 调节器底部视图颜色
@property (nonatomic, strong) UIColor *backgroundColor;
/// 调节器视图前景色
@property (nonatomic, strong) UIColor *frontColor;
/// 亮度小图标
@property (nonatomic, strong) UIImage *customImage;
/// 是否显示百分比
@property (nonatomic, assign) BOOL shouldShowPercent;
/// 百分比标签
@property (nonatomic, strong) UILabel *percentLabel;

@end

NS_ASSUME_NONNULL_END
