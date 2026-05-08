
#import <Foundation/Foundation.h>

#import "ThingNavigationBarItem.h"
#import "ThingNavigationTypeDefine.h"

/**
 en^
 thing_topBar means this method/property only effect on current view controller
 getter only return the value that you set, it will be nil if you didn't set
 if you want to get something such as default value, use thing_naviPresentxxx in <ThingNavigationPresentProtocol> insted
 !!! Don't override any accessor method
 en$
 */
@protocol ThingNavigationTopBarProtocol <NSObject>

#pragma mark - NaviItem
@property (nonatomic) BOOL thing_topBarEnableBackItem;     /**< Whether to use the back/cancel button Affects: Current page */
@property (nonatomic, strong) ThingNavigationBarItem *thing_topBarBackItem;   /**< back/cancel button style   Affects: Current page */
@property (nonatomic, strong) ThingNavigationBarItem *thing_topBarLeftItem;   /**< left style  Affects: Current page */
@property (nonatomic, strong) ThingNavigationBarItem *thing_topBarCenterItem; /**< center style  Affects: Current page */
@property (nonatomic, strong) ThingNavigationBarItem *thing_topBarRightItem;  /**< right style Affects: Current page */

/**
 layout from left to right
 Available After ThingSmart 3.9.0+
 */
@property (nonatomic, strong) NSArray<ThingNavigationBarItem *> *thing_topBarLeftItems;

/**
 layout from left to right
 Available After ThingSmart 3.9.0+
 */
@property (nonatomic, strong) NSArray<ThingNavigationBarItem *> *thing_topBarRightItems;

@property (nonatomic, strong) UIColor *thing_topBarItemsNormalTintColor;
@property (nonatomic, strong) UIColor *thing_topBarItemsSelectTintColor;
@property (nonatomic, strong) UIColor *thing_topBarItemsDisableTintColor;

#pragma mark - NaviStyle
@property (nonatomic) BOOL thing_topBarHidden;             /**< Hide navigation bar Affects: Current page */
@property (nonatomic) CGFloat thing_topBarAlpha;           /**< The overall transparency of the navigation bar affects: the current page*/
@property (nonatomic) BOOL thing_topBarUseAlphaInsteadHidden;  /**< When setting the navigation bar to be hidden as a whole, use alpha=0 instead [default: yes] Affects: Current page */

@property (nonatomic) CGFloat thing_topBarBlurAlpha;       /**< Frosted glass effect, Default:0 Affects: Current page */
@property (nonatomic) CGFloat thing_topBarBackgroundAlpha;             /**< Background transparency affects: current page */
@property (nonatomic) CGFloat thing_topBarSeparatorAlpha;              /**< Divider transparency affects: current page */
@property (nonatomic) CGAffineTransform thing_topBarTransform;         /**< Navigation bar transform affects: current page */
@property (nonatomic, strong) UIColor *thing_topBarBackgroundColor;    /**< Background color affects: current page */
@property (nonatomic, strong) UIImage *thing_topBarBackgroundImage;    /**< Background image affects: current page */
@property (nonatomic, strong) CALayer *thing_topBarBackgroundLayer;    /**< Background layer Affects: Current page Available After ThingSmart 3.9.0+ */
@property (nonatomic, strong) UIColor *thing_topBarSeparatorColor;     /**< Divider color affects: current page */

#pragma mark - PopGesture
@property (nonatomic) ThingNavigationPopGestureType thing_topBarPopGestureType;   /**< Back gesture affects: current page*/
@property (nonatomic) BOOL thing_topBarHitThrough; /**< Whether click (when background) can penetrate navi [default: NO] Affects: current page */


#pragma mark - StatusBar
@property (nonatomic) UIStatusBarStyle thing_topBarStatusBarStyle;
@property (nonatomic) BOOL thing_topBarStatusBarHidden;
@property (nonatomic) UIStatusBarAnimation thing_topBarStatusBarAnimation;



#pragma mark - Deprecated
@property (nonatomic) CGFloat thing_topBarSeperatorAlpha __deprecated_msg("Use thing_topBarSeparatorAlpha instead");

@end



@interface UIViewController ()  <ThingNavigationTopBarProtocol>
@end
