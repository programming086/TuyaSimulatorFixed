
#import <UIKit/UIKit.h>

#import "ThingNavigationControllerProtocol.h"
#import "ThingNavigationTopBarProtocol.h"
#import "UINavigationController+ThingNaviRender.h"

@interface ThingNavigationController : UINavigationController <ThingNavigationControllerProtocol, ThingNavigationRenderProtocol>

/**
 default is [ThingNavigationBarAppearance shareAppearance]
 if you want to modify anything only for one navigation controller, you have to create one with [ThingNavigationBarAppearance new]
 if you want to modify anything for all navigation controller, you need to call like [ThingNavigationBarAppearance shareAppearance].xxx = xxx
 */
@property (nonatomic, strong) ThingNavigationBarAppearance * _Nullable naviApperance __deprecated_msg("Use thing_naviApperance instead");

@end
