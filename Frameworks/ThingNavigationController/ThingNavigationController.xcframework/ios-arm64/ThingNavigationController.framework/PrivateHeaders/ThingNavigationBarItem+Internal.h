
#import "ThingNavigationBarItem.h"

@class ThingNavigationBarItemAppearance;
@class ThingNavigationBarItemProxy;

@interface ThingNavigationBarItem ()

@property (nonatomic, weak) UIView *barItemView;

@property (nonatomic, weak) ThingNavigationBarItemProxy *proxy;

- (void)_mergeWithAppearance:(ThingNavigationBarItemAppearance *)appearance;

@end
