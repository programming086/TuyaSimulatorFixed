//
//  UIScreen+ThingFrame.h
//  ThingUIKit
//
//  Created by ThingInc on 2018/12/20.
//

#import <UIKit/UIKit.h>

#pragma mark - NotchScreen
/**
 @return iPhone with Notch Screen ? Like iPhoneX
 */
UIKIT_EXTERN BOOL Thing_IsNotchScreen(void);
UIKIT_EXTERN BOOL Thing_IsFloatTabbar(void);

#pragma mark - ScreenSize
/**
 @return [UIScreen mainScreen].bounds
 */
UIKIT_EXTERN CGRect Thing_ScreenBounds(void);
/**
 @return [UIScreen mainScreen].bounds.size.width
 */
UIKIT_EXTERN CGFloat Thing_ScreenWidth(void);
UIKIT_EXTERN CGFloat Thing_ScreenRealWidth(void);

UIKIT_EXTERN CGSize Thing_RealContentSize(void);
/**
 @return [UIScreen mainScreen].bounds.size.height
 */
UIKIT_EXTERN CGFloat Thing_ScreenHeight(void);

UIKIT_EXTERN CGFloat Thing_ScreenRealHeight(void);

#pragma mark - SareArea
/**
 @return [UIApplication sharedApplication].keyWindow.safeAreaInsets
 */
UIKIT_EXTERN UIEdgeInsets Thing_ScreenSafeInsets(void);
/**
 @return [UIApplication sharedApplication].keyWindow.safeAreaInsets.top
 */
UIKIT_EXTERN CGFloat Thing_ScreenSafeTop(void);
/**
 @return [UIApplication sharedApplication].keyWindow.safeAreaInsets.bottom
 */
UIKIT_EXTERN CGFloat Thing_ScreenSafeBottom(void);

#pragma mark - NaviBarHeight / StatusBarHeight / TabBarHeight

/**
 [^en]
 if you want to get the top of the view controller safe area insets, vc.thing_safeTop will be better
 [$en]
 @return [^en]top of window safe area insets plus 44[$en]
 */
UIKIT_EXTERN CGFloat Thing_NaviBarHeight(void);
UIKIT_EXTERN CGFloat Thing_StatusBarHeight(void);
UIKIT_EXTERN CGFloat Thing_TabBarHeight(void);
/**
 * Customize the height of Thing_TabBarHeight() and make the change effective globally
 */
UIKIT_EXTERN void Thing_TabBarCustomHeight(CGFloat height);

#pragma mark - ScreenAdaption

/// [^en]adaption to screen, standard is 375.0[$en]
UIKIT_EXTERN CGFloat Thing_ScreenAdaptionLength(CGFloat length);
/// [^en]adaption to screen, standard is 375.0[$en]
UIKIT_EXTERN CGPoint Thing_ScreenAdaptionPoint(CGPoint point);
/// [^en]adaption to screen, standard is 375.0[$en]
UIKIT_EXTERN CGSize Thing_ScreenAdaptionSize(CGSize size);
/// [^en]adaption to screen, standard is 375.0[$en]
UIKIT_EXTERN CGRect Thing_ScreenAdaptionRect(CGRect rect);
