
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingEmptyViewProtocol <NSObject>

@optional
- (void)thing_emptyViewDidAddToSuperView;
- (void)thing_emptyViewShouldLayout;
- (void)thing_emptyViewWillShow;
- (void)thing_emptyViewDidShow;
- (void)thing_emptyViewWillHide;
- (void)thing_emptyViewDidHide;

- (void)thing_emptyViewShowAnimation:(void (^ __nullable)(BOOL finished))completion;
- (void)thing_emptyViewHideAnimation:(void (^ __nullable)(BOOL finished))completion;

@end


NS_ASSUME_NONNULL_END
