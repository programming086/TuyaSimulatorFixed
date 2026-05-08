
#import <Foundation/Foundation.h>

#import "ThingNavigationBarItem.h"
#import "ThingNavigationTypeDefine.h"

/**
 en^
 thing_naviBarxxx means this method/property will effect on current view controller and the view controller that pushed by current view controller
 getter only return the value that you set, it will be nil if you didn't set
 if you want to get something such as default value, use thing_naviPresentxxx in <ThingNavigationPresentProtocol> insted
 !!! Don't override any accessor method
 en$
 */
@protocol ThingNavigationNaviBarProtocol <NSObject>

#pragma mark - NaviItem
@property (nonatomic) BOOL thing_naviBarEnableBackItem;     /**< Whether to use the back/cancel button Affects: current page & push page */
@property (nonatomic, strong) ThingNavigationBarItem *thing_naviBarBackItem;      /**< Back/cancel button style Affects: current page & push page */
@property (nonatomic, strong) ThingNavigationBarItem *thing_naviBarLeftItem;      /**< Left style affects: current page & push page*/
@property (nonatomic, strong) ThingNavigationBarItem *thing_naviBarCenterItem;    /**< Center style affects: current page & push page */
@property (nonatomic, strong) ThingNavigationBarItem *thing_naviBarRightItem;     /**< right style affects: current page & push page*/

/**
 layout from left to right
 Available After ThingSmart 3.9.0+
 */
@property (nonatomic, strong) NSArray<ThingNavigationBarItem *> *thing_naviBarLeftItems;

/**
 layout from left to right
 Available After ThingSmart 3.9.0+
 */
@property (nonatomic, strong) NSArray<ThingNavigationBarItem *> *thing_naviBarRightItems;

@property (nonatomic, strong) UIColor *thing_naviBarItemsNormalTintColor;
@property (nonatomic, strong) UIColor *thing_naviBarItemsSelectTintColor;
@property (nonatomic, strong) UIColor *thing_naviBarItemsDisableTintColor;

#pragma mark - NaviStyle
@property (nonatomic) BOOL thing_naviBarHidden;             /**< Hide navigation bar Affects: current page & push page */
@property (nonatomic) CGFloat thing_naviBarAlpha;           /**< The overall transparency of the navigation bar affects: the current page & push page */
@property (nonatomic) BOOL thing_naviBarUseAlphaInsteadHidden;   /**< When setting the navigation bar to be hidden as a whole, use alpha=0 instead [default: yes] Affects: current page & push page*/

@property (nonatomic) CGFloat thing_naviBarBlurAlpha;      /**< Frosted glass effect Default: 0 Affects: current page & push page */
@property (nonatomic) CGFloat thing_naviBarBackgroundAlpha;            /**< Background transparency affects: current page & push page */
@property (nonatomic) CGFloat thing_naviBarSeparatorAlpha;             /**< Dividing line transparency affects: current page & push page */
@property (nonatomic) CGAffineTransform thing_naviBarTransform;        /**< Navigation bar transform affects: current page & push page */
@property (nonatomic, strong) UIColor *thing_naviBarBackgroundColor;   /**< Background color affects: current page & push page */
@property (nonatomic, strong) UIImage *thing_naviBarBackgroundImage;   /**< Background image affects: current page & push page */
@property (nonatomic, strong) CALayer *thing_naviBarBackgroundLayer;    /**< Background layer Affects: current page & push page Available After ThingSmart 3.9.0+*/
@property (nonatomic, strong) UIColor *thing_naviBarSeparatorColor;    /**< Dividing line color affects: current page & push page */

#pragma mark - PopGesture
@property (nonatomic) ThingNavigationPopGestureType thing_naviBarPopGestureType;   /**< Back gesture affects: current page & push page */
@property (nonatomic) BOOL thing_naviBarHitThrough; /**< Whether clicking (when background) can penetrate navi Impact: current page & push page*/

#pragma mark - StatusBar
// thing_naviBarStatusBarxxx Available After ThingSmart 3.9.0+
@property (nonatomic) UIStatusBarStyle thing_naviBarStatusBarStyle;     /**< Status bar style affects: current page & push page */
@property (nonatomic) BOOL thing_naviBarStatusBarHidden;   /**< Hide status bar default:NO Affects: current page & push page */
@property (nonatomic) UIStatusBarAnimation thing_naviBarStatusBarAnimation;

@end



@interface UIViewController () <ThingNavigationNaviBarProtocol>
@end

