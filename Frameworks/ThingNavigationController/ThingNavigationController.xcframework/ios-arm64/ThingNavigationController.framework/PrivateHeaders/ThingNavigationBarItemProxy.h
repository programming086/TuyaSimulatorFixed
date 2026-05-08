
#import <Foundation/Foundation.h>

#import "ThingNavigationBarItem.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Used to achieve automatic refresh after setting attributes for item
 Implement logic：
 When the business obtains the item through self.item, a proxy is given without any perception.
 After the business obtains the proxy, it is generally used directly as a local variable
 Any attribute set by the business on the proxy is directly forwarded to the real item to achieve data synchronization
 When the scope ends, the proxy will be released
 You can actively call refresh in the dealloc method
 */
@interface ThingNavigationBarItemProxy : NSProxy

@property (nonatomic, weak) ThingNavigationBarItem *proxyTarget;
@property (nonatomic, weak) UIViewController *proxyVC;
@property (nonatomic) SEL proxySEL;

+ (instancetype)proxyWithTarget:(ThingNavigationBarItem *)target;

@end


FOUNDATION_EXTERN ThingNavigationBarItemProxy * ThingNavigationBarItemProxyMake(ThingNavigationBarItem *target, UIViewController *vc, SEL sel);

NS_ASSUME_NONNULL_END
