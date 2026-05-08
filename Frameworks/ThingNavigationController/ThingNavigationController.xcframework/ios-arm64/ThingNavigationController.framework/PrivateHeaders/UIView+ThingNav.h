//
//  UIView+ThingNav.h
//  ThingNavigationController
//
//  Created by on 2021/11/19.
//

#import <UIKit/UIKit.h>

@interface UIView (ThingNav)

/**
 * Shortcut for frame.origin.x.
 *
 * Sets frame.origin.x = left
 */
@property (nonatomic) CGFloat thing_nav_left;

/**
 * Shortcut for frame.origin.y
 *
 * Sets frame.origin.y = top
 */
@property (nonatomic) CGFloat thing_nav_top;

/**
 * Shortcut for frame.origin.x + frame.size.width
 *
 * Sets frame.origin.x = right - frame.size.width
 */
@property (nonatomic) CGFloat thing_nav_right;

/**
 * Shortcut for frame.origin.y + frame.size.height
 *
 * Sets frame.origin.y = bottom - frame.size.height
 */
@property (nonatomic) CGFloat thing_nav_bottom;

/**
 * Shortcut for frame.size.width
 *
 * Sets frame.size.width = width
 */
@property (nonatomic) CGFloat thing_nav_width;

/**
 * Shortcut for frame.size.height
 *
 * Sets frame.size.height = height
 */
@property (nonatomic) CGFloat thing_nav_height;

/**
 * Shortcut for center.x
 *
 * Sets center.x = centerX
 */
@property (nonatomic) CGFloat thing_nav_centerX;

/**
 * Shortcut for center.y
 *
 * Sets center.y = centerY
 */
@property (nonatomic) CGFloat thing_nav_centerY;

/**
 * Shortcut for frame.origin
 */
@property (nonatomic) CGPoint thing_nav_origin;

/**
 * Shortcut for frame.size
 */
@property (nonatomic) CGSize thing_nav_size;

- (UIEdgeInsets)thing_nav_hitExtend;

- (void)setThing_nav_hitExtend:(UIEdgeInsets)thing_nav_hitExtend;


/**
 @return iPhone with Notch Screen ? Like iPhoneX
 */
UIKIT_EXTERN BOOL Thing_Nav_IsNotchScreen(void);

#pragma mark - ScreenSize
/**
 @return [UIScreen mainScreen].bounds
 */
UIKIT_EXTERN CGRect Thing_Nav_ScreenBounds(void);
/**
 @return [UIScreen mainScreen].bounds.size.width
 */
UIKIT_EXTERN CGFloat Thing_Nav_ScreenWidth(void);
UIKIT_EXTERN CGFloat Thing_Nav_ScreenRealWidth(void);

UIKIT_EXTERN CGSize Thing_Nav_RealContentSize(void);
/**
 @return [UIScreen mainScreen].bounds.size.height
 */
UIKIT_EXTERN CGFloat Thing_Nav_ScreenHeight(void);

UIKIT_EXTERN CGFloat Thing_Nav_ScreenRealHeight(void);

#pragma mark - SareArea
/**
 @return [UIApplication sharedApplication].keyWindow.safeAreaInsets
 */
UIKIT_EXTERN UIEdgeInsets Thing_Nav_ScreenSafeInsets(void);
/**
 @return [UIApplication sharedApplication].keyWindow.safeAreaInsets.top
 */
UIKIT_EXTERN CGFloat Thing_Nav_ScreenSafeTop(void);
/**
 @return [UIApplication sharedApplication].keyWindow.safeAreaInsets.bottom
 */
UIKIT_EXTERN CGFloat Thing_Nav_ScreenSafeBottom(void);

#pragma mark - NaviBarHeight / StatusBarHeight / TabBarHeight

/**
 [^zh]
 If you need to get the safe height of the top of the controller, it is recommended to use [vc.thing_safeTop]  to get it in real time
 [$zh]
 [^en]
 if you want to get the top of the view controller safe area insets, vc.thing_safeTop will be better
 [$en]
 @return [^zh]return to the top of the screen safe height+44[^zh] [^en]top of window safe area insets plus 44[$en]
 */
UIKIT_EXTERN CGFloat Thing_Nav_NaviBarHeight(void);
UIKIT_EXTERN CGFloat Thing_Nav_StatusBarHeight(void);
UIKIT_EXTERN CGFloat Thing_Nav_TabBarHeight(void);
/**
 * Customize the height of [Thing_TabBarHeight()] and make the change effective globally
 */
UIKIT_EXTERN void Thing_Nav_TabBarCustomHeight(CGFloat height);

#pragma mark - ScreenAdaption

/// [^zh]adaption to screen, standard is375.0[$zh] [^en]adaption to screen, standard is 375.0[$en]
UIKIT_EXTERN CGFloat Thing_Nav_ScreenAdaptionLength(CGFloat length);
/// [^zh]adaption to screen, standard is 375.0[$zh] [^en]adaption to screen, standard is 375.0[$en]
UIKIT_EXTERN CGPoint Thing_Nav_ScreenAdaptionPoint(CGPoint point);
/// [^zh]adaption to screen, standard is 375.0[$zh] [^en]adaption to screen, standard is 375.0[$en]
UIKIT_EXTERN CGSize Thing_Nav_ScreenAdaptionSize(CGSize size);
/// [^zh]adaption to screen, standard is 375.0[$zh] [^en]adaption to screen, standard is 375.0[$en]
UIKIT_EXTERN CGRect Thing_Nav_ScreenAdaptionRect(CGRect rect);

UIKIT_EXTERN BOOL Thing_Nav_IsPad(void);

UIKIT_EXTERN UIViewController * Thing_Nav_TopViewController(void);

UIKIT_EXTERN UIWindow * Thing_Nav_MainWindow(void);

UIKIT_EXTERN CGFloat Thing_Nav_PixelAlignedLength(CGFloat length);
UIKIT_EXTERN CGPoint Thing_Nav_PixelAlignedPoint(CGPoint point);
UIKIT_EXTERN CGSize Thing_Nav_PixelAlignedSize(CGSize size);
UIKIT_EXTERN CGRect Thing_Nav_PixelAlignedRect(CGRect rect);

@end
