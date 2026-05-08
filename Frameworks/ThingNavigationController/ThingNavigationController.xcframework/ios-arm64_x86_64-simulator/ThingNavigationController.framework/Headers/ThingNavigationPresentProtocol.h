
#import <Foundation/Foundation.h>

#import "ThingNavigationBarItem.h"
#import "ThingNavigationTypeDefine.h"

/**
 method has prefix thing_naviPresent only used to get current status of view controller
 
 NaviPresent Rule:
 - (id)thing_naviPresentxxx {
     if (vc.thing_naviBarxxx) {
        return vc.thing_naviBarxxx
     } else if (navi.topVC == vc && vc.thing_topBarxxx) {
        return vc.thing_topBarxxx
     } else if (vc.idx_in_navi_stack == 0) {
        return defaultValue
     } else {
        last_vc = navi.stack[vc.idx_in_navi_stack - 1]
        return last_vc.thing_naviPresentxxx
     }
 }
 
 */
@protocol ThingNavigationPresentProtocol <NSObject>

#pragma mark - NaviItem
@property (nonatomic, readonly) BOOL thing_naviPresentEnableBackItem;
@property (nonatomic, weak, readonly) ThingNavigationBarItem *thing_naviPresentBackItem;
/**
 return the first obj in thing_naviPresentLeftItems after ThingSmart 3.9.0+
 */
@property (nonatomic, weak, readonly) ThingNavigationBarItem *thing_naviPresentLeftItem;
/**
 return the first obj in thing_naviPresentRightItems after ThingSmart 3.9.0+
 */
@property (nonatomic, weak, readonly) ThingNavigationBarItem *thing_naviPresentRightItem;

/**
 Available After ThingSmart 3.9.0+
 */
@property (nonatomic, weak, readonly) NSArray<ThingNavigationBarItem *> *thing_naviPresentLeftItems;
/**
 Available After ThingSmart 3.9.0+
 */
@property (nonatomic, weak, readonly) NSArray<ThingNavigationBarItem *> *thing_naviPresentRightItems;

@property (nonatomic, weak, readonly) ThingNavigationBarItem *thing_naviPresentCenterItem;


@property (nonatomic, weak, readonly) UIColor *thing_naviPresentItemsNormalTintColor;
@property (nonatomic, weak, readonly) UIColor *thing_naviPresentItemsSelectTintColor;
@property (nonatomic, weak, readonly) UIColor *thing_naviPresentItemsDisableTintColor;

#pragma mark - NaviStyle
@property (nonatomic, readonly) BOOL thing_naviPresentHidden;
@property (nonatomic, readonly) CGFloat thing_naviPresentAlpha;
@property (nonatomic, readonly) BOOL thing_naviPresentUseAlphaInsteadHidden;
@property (nonatomic, readonly) CGFloat thing_naviPresentBlurAlpha;
@property (nonatomic, readonly) CGFloat thing_naviPresentBackgroundAlpha;
@property (nonatomic, readonly) CGFloat thing_naviPresentSeparatorAlpha;
@property (nonatomic, readonly) CGAffineTransform thing_naviPresentTransform;
@property (nonatomic, readonly) UIColor *thing_naviPresentBackgroundColor;
@property (nonatomic, readonly) UIImage *thing_naviPresentBackgroundImage;
@property (nonatomic, readonly) CALayer *thing_naviPresentBackgroundLayer; /**< Available After ThingSmart 3.9.0+ */
@property (nonatomic, readonly) UIColor *thing_naviPresentSeparatorColor;

#pragma mark - Gesture
@property (nonatomic, readonly) ThingNavigationPopGestureType thing_naviPresentPopGestureType;
@property (nonatomic, readonly) BOOL thing_naviPresentHitThrough;

#pragma mark - StatusBar
@property (nonatomic, readonly) UIStatusBarStyle thing_naviPresentStatusBarStyle;
@property (nonatomic, readonly) BOOL thing_naviPresentStatusBarHidden;
@property (nonatomic, readonly) UIStatusBarAnimation thing_naviPresentStatusBarAnimation;

@end



@interface UIViewController ()  <ThingNavigationPresentProtocol>
@end
