
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingCameraTheme) {
    ThingCameraThemeDefault,
    ThingCameraThemeBlack,
    ThingCameraThemeWhite
};

@protocol ThingSmartCameraTheme <NSObject>

@property (nonatomic, assign) ThingCameraTheme theme;

@property (nonatomic, strong, readonly) UIColor *backgroundColor;

@property (nonatomic, strong, readonly) UIColor *themeColor;

@property (nonatomic, strong, readonly) UIColor *contentColor;

@property (nonatomic, strong, readonly) UIColor *textColor;

@property (nonatomic, strong, readonly) UIColor *subTextColor;

@property (nonatomic, strong, readonly) UIColor *separateLineColor;

@property (nonatomic, assign, readonly) NSInteger naviTitleFontSize;

@property (nonatomic, assign, readonly) NSInteger naviItemFontSize;

@property (nonatomic, assign, readonly) NSInteger leftTextFontSize;

@property (nonatomic, assign, readonly) NSInteger rightTextFontSize;

@property (nonatomic, assign, readonly) NSInteger bottomTextFontSize;

@property (nonatomic, assign, readonly) NSInteger sectionHeaderFontSize;

@property (nonatomic, assign, readonly) NSInteger sectionFooterFontSize;

@property (nonatomic, strong, readonly) UIFont *naviTitleFont;

@property (nonatomic, strong, readonly) UIFont *naviItemFont;

@property (nonatomic, strong, readonly) UIFont *leftTextFont;

@property (nonatomic, strong, readonly) UIFont *rightTextFont;

@property (nonatomic, strong, readonly) UIFont *bottomTextFont;

@property (nonatomic, strong, readonly) UIFont *sectionHeaderFont;

@property (nonatomic, strong, readonly) UIFont *sectionFooterFont;

- (BOOL)isWhiteTheme;

@end

NS_ASSUME_NONNULL_END
