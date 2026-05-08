//
//  UIViewController+ThingNavigation.h
//  ThingNavigationController
//
//  Created by ThingInc on 2018/11/13.
//

#import <UIKit/UIKit.h>

#import "ThingNavigationControllerProtocol.h"

#import "UIViewController+ThingStatusBar.h"

#import "ThingNavigationTopBarProtocol.h"
#import "ThingNavigationCallbackProtocol.h"
#import "ThingNavigationPresentProtocol.h"

FOUNDATION_EXPORT void ThingSetNaviDisablePrefixList(NSString *);

@protocol ThingNavigationNaviBarProtocol;

/*
 en^
 prefix thing_topBarxxx means this method/property only effect on current view controller, all thing_topBarxxx method/property are in <ThingNavigationTopBarProtocol>
 
 prefix thing_naviBarxxx means this method/property will effect on current view controller and the view controller that pushed by current view controller, all thing_naviBarxxx method/property are in <ThingNavigationNaviBarProtocol>
 if you need thing_naviBarxxx, you have to import header file ThingNavigationNaviBarProtocol.h
 
 !!! Don't override any accessor method
 en$
 */
@interface UIViewController (ThingNavigation)

/**
 override get method in sub view controller if need
 or set value to the property in init method
 */
@property (nonatomic) BOOL thing_enableTYNaviRender;

@property (nonatomic, strong, readonly) __kindof UINavigationController<ThingNavigationControllerProtocol> *navigationController;

/**
 Only navigationController.topViewController will be call
 */
- (void)thing_naviWillPushViewController:(UIViewController *)viewController;

@end

