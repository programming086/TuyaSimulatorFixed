//
//  ThingLoadingAnimationView.h
//  ThingGroupHandleModule
//
//  Created by 尼诺 on 2021/7/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupEditHUDLoadingAnimationViewBuilder : NSObject

@property (nonatomic, assign) CGFloat radius;

@property (nonatomic, strong) UIColor *lineColor;

@end

@interface ThingGroupEditHUDLoadingAnimationView : UIView

- (instancetype)initWithBuilder:(ThingGroupEditHUDLoadingAnimationViewBuilder *)builder;

- (void)beginAnimation;

- (CGFloat)width;

- (CGFloat)height;

@end

NS_ASSUME_NONNULL_END
