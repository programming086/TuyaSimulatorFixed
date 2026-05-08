
#import <UIKit/UIKit.h>

#import "ThingEmptyViewProtocol.h"
#import "UIView+ThingEmptyView.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingEmptyBaseView : UIView<ThingEmptyViewProtocol>

@property (nonatomic, readonly) BOOL isShowing;

@end

NS_ASSUME_NONNULL_END
