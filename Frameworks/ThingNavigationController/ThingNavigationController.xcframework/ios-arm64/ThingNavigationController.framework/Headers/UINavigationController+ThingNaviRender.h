//
//  UINavigationController+ThingNaviRender.h
//  ThingNavigationController
//
//  Created by ThingInc on 2019/9/5.
//

#import <UIKit/UIKit.h>

#import "ThingNavigationRenderProtocol.h"
#import "ThingNavigationBarItem.h"
#import "ThingNavigationBarAppearance.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const kThingNaviItemKey;
FOUNDATION_EXPORT CGFloat ThingNaviItemDefaultEdgeInset(void);

@interface UINavigationController (ThingNaviRender) <ThingNavigationRenderProtocol>

/**
 default is [ThingNavigationBarAppearance shareAppearance]
 if you want to modify anything only for one navigation controller, you have to create one with [ThingNavigationBarAppearance new]
 if you want to modify anything for all navigation controller, you need to call like [ThingNavigationBarAppearance shareAppearance].xxx = xxx
 */
@property (nonatomic, strong) ThingNavigationBarAppearance *thing_naviApperance;

@property (nonatomic, weak, readonly) UIViewController * _Nullable thing_orientationDecisiveVC;

@end

NS_ASSUME_NONNULL_END
