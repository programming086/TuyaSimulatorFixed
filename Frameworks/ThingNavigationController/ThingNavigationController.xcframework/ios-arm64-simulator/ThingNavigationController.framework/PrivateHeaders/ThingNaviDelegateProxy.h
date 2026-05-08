
#import <Foundation/Foundation.h>

#import <UIKit/UINavigationController.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Preserves client app's navigation bar state (hidden/visible and alpha) during transitions
 * between client pages and SDK pages to ensure correct restoration when returning to client pages.
 */
extern BOOL gEnablePreserveClientNavigationBarState;

@interface ThingNaviDelegateProxy : NSProxy

@property (nonatomic, weak, readonly) id<UINavigationControllerDelegate> target;

+ (instancetype)proxyWithTarget:(id<UINavigationControllerDelegate>)target;

@end


@interface NSObject (ThingNaviProxy)
- (BOOL)thing_isTYNaviProxy;
@end

@interface NSProxy (ThingNaviProxy)
- (BOOL)thing_isTYNaviProxy;
@end

NS_ASSUME_NONNULL_END
