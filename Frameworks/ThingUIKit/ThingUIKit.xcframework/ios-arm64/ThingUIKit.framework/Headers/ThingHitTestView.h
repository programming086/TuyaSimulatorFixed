
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingHitTestView : UIView

/// [^en]callback when hitTest:withEvent: is called[$en]
@property (nonatomic, copy) UIView *(^thing_hitTestBlock)(CGPoint point, UIEvent *event, UIView *defaultResult);

/// [^en]callback when pointInside:withEvent: is called[$en]
@property (nonatomic, copy) BOOL(^thing_pointInsideBlock)(CGPoint point, UIEvent *event, BOOL defaultResult);

@end

NS_ASSUME_NONNULL_END
