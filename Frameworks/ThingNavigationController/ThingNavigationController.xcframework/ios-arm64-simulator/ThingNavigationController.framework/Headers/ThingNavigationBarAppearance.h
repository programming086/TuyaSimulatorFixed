
#import <Foundation/Foundation.h>

#import "ThingNavigationTypeDefine.h"
#import "ThingNavigationBarItem.h"


@interface ThingNavigationBarItemAppearance : NSObject

@property (nonatomic, strong) UIFont *titleFont;

@property (nonatomic, strong) NSDictionary<NSAttributedStringKey, id> *normalTitleAttribute;
@property (nonatomic, strong) NSDictionary<NSAttributedStringKey, id> *selectTitleAttribute;
@property (nonatomic, strong) NSDictionary<NSAttributedStringKey, id> *disableTitleAttribute;

@property (nonatomic, strong) UIColor *normalTintColor;
@property (nonatomic, strong) UIColor *selectTintColor;
@property (nonatomic, strong) UIColor *disableTintColor;

@property (nonatomic) CGFloat leftEdge;
@property (nonatomic) CGFloat rightEdge;

@property (nonatomic) UIEdgeInsets hitExtend;   /**< Click area expansion Positive outward Negative inward */

@end



/**
 Default configuration for navigationBar
 Modification does not mean immediate effect
 */
@interface ThingNavigationBarAppearance : NSObject

+ (instancetype)appearance __deprecated_msg("Use +shareAppearance instead");
+ (instancetype)shareAppearance;

#pragma mark - Items
@property (nonatomic, strong) ThingNavigationBarItemAppearance *naviBarBackItem;      /**< back style */
@property (nonatomic, strong) ThingNavigationBarItemAppearance *naviBarLeftItem;      /**< left style */
@property (nonatomic, strong) ThingNavigationBarItemAppearance *naviBarCenterItem;    /**< center style */
@property (nonatomic, strong) ThingNavigationBarItemAppearance *naviBarRightItem;     /**< right style */

/**
 left edge to screen for the first left item (left items include back item)
 if value < 0, will use naviBarLeftItem.leftEdge insted
 default value is 16
 if back item exist, this value won't wrok, and naviBarLeftItem.leftEdge will work
 Available After ThingSmart 3.9.0+
 */
@property (nonatomic) CGFloat leftEdgeForFirstLeftItem;
/**
 right edge to screen for the last right item
 if value < 0, will use naviBarLeftItem.leftEdge insted
 default value is 16
 Available After ThingSmart 3.9.0+
 */
@property (nonatomic) CGFloat rightEdgeForLastRightItem;

#pragma mark - NaviStyle
@property (nonatomic) BOOL naviBarHidden;                           /**< Hide navigation bar */
@property (nonatomic) CGFloat naviBarAlpha;                         /**< Navigation bar overall transparency */
@property (nonatomic) BOOL naviBarUseAlphaInsteadHidden;            /**< Use alpha=0 instead of hiding the navigation bar */
@property (nonatomic) CGFloat naviBarBlurAlpha;                     /**< frosted glass effect */
@property (nonatomic) CGFloat naviBarBackgroundAlpha;               /**< background transparency */
@property (nonatomic) CGFloat naviBarSeparatorAlpha;                /**< Split line transparency*/
@property (nonatomic) CGAffineTransform naviBarTransform;           /**< Navigation bar transform */
@property (nonatomic, strong) UIColor *naviBarBackgroundColor;      /**< background color */
@property (nonatomic, strong) UIImage *naviBarBackgroundImage;      /**< Background image */
@property (nonatomic, strong) CALayer *naviBarBackgroundLayer;      /**< Background layer Available After ThingSmart 3.9.0+ */
@property (nonatomic, strong) UIColor *naviBarSeparatorColor;       /**< dividing line color */

#pragma mark - PopGesture
@property (nonatomic) ThingNavigationPopGestureType naviBarPopGestureType;     /**< back gesture */
@property (nonatomic) BOOL naviBarHitThrough;                               /**< Click (background) to penetrate the navi */

#pragma mark - StatusBar
@property (nonatomic) UIStatusBarStyle statusBarStyle;
@property (nonatomic) BOOL statusBarHidden;
@property (nonatomic) UIStatusBarAnimation statusBarAnimation;

@end
