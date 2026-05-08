
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingNavigationRefreshProtocol <NSObject>

- (void)thing_refreshBackAndLeftItems;
- (void)thing_refreshCenterItem;
- (void)thing_refreshRightItem;

- (void)thing_refreshBarAlpha;
- (void)thing_refreshHidden;
- (void)thing_refreshTransform;
- (void)thing_refreshBackground;
- (void)thing_refreshSeparator;
- (void)thing_refreshPopGesture;

@end

NS_ASSUME_NONNULL_END
