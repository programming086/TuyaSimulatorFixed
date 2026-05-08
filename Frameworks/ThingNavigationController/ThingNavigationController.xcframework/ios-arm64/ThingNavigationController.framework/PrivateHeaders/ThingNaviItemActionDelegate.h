
#import <Foundation/Foundation.h>

#import "UINavigationController+ThingNaviRender.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingNaviItemAction <NSObject>

/**
 thing_xxxItemAction:  method can be override in category or subclass
 but super will not work when override in category
 */
- (void)thing_backItemAction:(ThingNavigationBarItem *)item;
- (void)thing_leftItemAction:(ThingNavigationBarItem *)item;
- (void)thing_rightItemAction:(ThingNavigationBarItem *)item;
- (void)thing_centerItemAction:(ThingNavigationBarItem *)item;

@end


/// Used to undertake some methods that are not easy to implement directly in the navigation bar

@interface ThingNaviItemActionDelegate : NSObject <ThingNaviItemAction>

@property (nonatomic, weak) __kindof UINavigationController *thing_navi;

@end

NS_ASSUME_NONNULL_END
