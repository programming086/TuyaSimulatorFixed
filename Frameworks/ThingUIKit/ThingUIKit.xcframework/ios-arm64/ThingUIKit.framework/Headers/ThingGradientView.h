
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingGradientView : UIView

@property(nullable, copy) NSArray *colors;

@property(nullable, copy) NSArray<NSNumber *> *locations;

@property CGPoint startPoint;
@property CGPoint endPoint;

@property(copy) CAGradientLayerType type;

@end

NS_ASSUME_NONNULL_END
