
#import <Foundation/Foundation.h>

#import "ThingNavigationRefreshProtocol.h"

@protocol ThingNavigationControllerProtocol <ThingNavigationRefreshProtocol>

#pragma mark - Refresh
- (void)thing_refreshBlurAlpha;
- (void)thing_refreshHitThrough;


@end
