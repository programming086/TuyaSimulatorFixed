
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingPanelDynamicContainerDelegate <NSObject>

@optional
- (void)containerViewDidLoad;
- (void)containerViewWillAppear:(BOOL)animated;
- (void)containerViewDidAppear:(BOOL)animated;
- (void)containerViewWillDisappear:(BOOL)animated;
- (void)containerViewDidDisappear:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
