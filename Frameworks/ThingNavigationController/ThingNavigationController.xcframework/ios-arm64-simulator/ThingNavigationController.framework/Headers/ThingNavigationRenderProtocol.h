
#import <Foundation/Foundation.h>

#import "ThingNavigationRefreshProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingNavigationRenderProtocol <ThingNavigationRefreshProtocol>

- (NSArray<UIBarButtonItem *> *)thing_leftUIBarItems;
- (NSArray<UIBarButtonItem *> *)thing_rightUIBarItems;
- (UIView *)thing_centerTitleView;

@end

NS_ASSUME_NONNULL_END
