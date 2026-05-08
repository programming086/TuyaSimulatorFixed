
#ifdef __OBJC__
    #import <UIKit/UIKit.h>
#else
    #ifndef FOUNDATION_EXTERN
        #if defined(__cplusplus)
            #define FOUNDATION_EXTERN extern "C"
        #else
            #define FOUNDATION_EXTERN extern
        #endif
    #endif

    #ifndef UIKIT_EXTERN
        #ifdef __cplusplus
            #define UIKIT_EXTERN        extern "C" __attribute__((visibility ("default")))
        #else
            #define UIKIT_EXTERN            extern __attribute__((visibility ("default")))
        #endif
    #endif
#endif

#ifndef ThingUIKit_h
#define ThingUIKit_h

#import "ThingUIKitMacro.h"

#import "UINavigationController+ThingCategory.h"
#import "UIViewController+ThingCategory.h"

#import "UIDevice+ThingCategory.h"
#import "UIButton+ThingCategory.h"
#import "UIScreen+ThingCategory.h"
#import "UIColor+ThingCategory.h"
#import "UIImage+ThingCategory.h"
#import "UILabel+ThingCategory.h"
#import "UIView+ThingCategory.h"
#import "UIFont+ThingCategory.h"
#import "UIScrollView+ThingUIKit.h"
#import "UIWindow+ThingSceneDelegate.h"
#import "UITableViewCell+ThingCategory.h"

#import "ThingMenuListViewController.h"
#import "ThingSearchController.h"
#import "ThingSegmentedControl.h"
#import "ThingHierarchyManager.h"
#import "ThingImpactEngine.h"
#import "ThingRippleView.h"
#import "ThingEmptyView.h"
#import "ThingTextView.h"
#import "ThingButton.h"
#import "ThingLabel.h"
#import "ThingSlider.h"
#import "ThingPopupManager.h"
#import "ThingGradientView.h"


#import "ThingAppLifeCycleUtil.h"

#if __has_include(<ThingNavigationController/UIViewController+ThingNavigation.h>)
#import <ThingNavigationController/UIViewController+ThingNavigation.h>
#import <ThingNavigationController/ThingNavigationController.h>
#elif __has_include("UIViewController+TYNavigation.h")
#import "UIViewController+ThingNavigation.h"
#import "ThingNavigationController.h"
#endif

#if __has_include(<ThingAnimationKit/UIView+ThingAnimation.h>)
#import <ThingAnimationKit/UIView+ThingAnimation.h>
#elif __has_include("UIView+TYAnimation.h")
#import "UIView+ThingAnimation.h"
#endif

#endif /* ThingUIKit_h */
