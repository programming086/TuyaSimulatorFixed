
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ThingNavigationBarItem;

@protocol ThingNavigationCallbackProtocol <NSObject>

@optional

#pragma mark - Action
// Callback only to the current page, if customView is used, UITapGesture will be automatically added
- (void)thing_naviBackItemAction:(ThingNavigationBarItem *)item;
- (void)thing_naviLeftItemAction:(ThingNavigationBarItem *)item;
- (void)thing_naviCenterItemAction:(ThingNavigationBarItem *)item;
- (void)thing_naviRightItemAction:(ThingNavigationBarItem *)item;

#pragma mark - Transition
- (void)thing_naviTransitionPrepare:(id<UIViewControllerTransitionCoordinator>)coordinator;
- (void)thing_naviTransitioning:(id<UIViewControllerTransitionCoordinatorContext>)context;
- (void)thing_navitransitionFinish:(id<UIViewControllerTransitionCoordinatorContext>)context;

#pragma mark - PopGesture
- (BOOL)thing_naviPopGestureShouldBegin;

@end



@interface UIViewController () <ThingNavigationCallbackProtocol>
@end
