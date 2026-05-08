
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingNaviGestureProxy : NSProxy

@property (nonatomic, weak) id<UIGestureRecognizerDelegate> target;
@property (nonatomic, weak) __kindof UINavigationController<UIGestureRecognizerDelegate> *navi;

+ (instancetype)proxyWithTarget:(id<UIGestureRecognizerDelegate>)target navigation:(__kindof UINavigationController *)navi;

@end

NS_ASSUME_NONNULL_END
