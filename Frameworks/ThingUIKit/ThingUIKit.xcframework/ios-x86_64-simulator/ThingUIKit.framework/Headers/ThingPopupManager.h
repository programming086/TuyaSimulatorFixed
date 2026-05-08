
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingPopupStyle) {
    ThingPopupStyleFadeInFadeOut,
    ThingPopupStyleBottomUp,
};

@interface ThingPopupConfig : NSObject
@property (nonatomic, copy) void(^config)(UIView *customViewContainer, UIView *customView);
@property (nonatomic, copy) void(^backgroundConfig)(UIView *backgroundView);
@property (nonatomic, assign) ThingPopupStyle style;
@property (nonatomic, assign) BOOL animated;
@end


@interface ThingPopupItem : NSObject

- (void)hidenAnimated:(BOOL)animated;

- (void)hiden;

@end



@interface ThingPopupManager : NSObject

+ (instancetype)shared;

- (ThingPopupItem *)showView:(UIView *)view config:(ThingPopupConfig *)config;

@end

NS_ASSUME_NONNULL_END
