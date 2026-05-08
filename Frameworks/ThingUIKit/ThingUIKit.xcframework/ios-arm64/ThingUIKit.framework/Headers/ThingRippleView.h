
#import <UIKit/UIKit.h>

@class ThingRippleView;

@protocol ThingRippleLayerProtocol <NSObject>

@required
+ (instancetype)layer;
- (CAAnimation *)lifeAnimationForLayer:(CGFloat)lifeTime withRippleView:(ThingRippleView *)rippleView;

@end

@protocol ThingRippleViewDelegateProtocol <NSObject>

- (void)rippleView:(ThingRippleView *)rippleView willLaunchLayer:(CALayer<ThingRippleLayerProtocol> *)layer;

@end

@interface ThingRippleView : UIView

@property (nonatomic, weak) id<ThingRippleViewDelegateProtocol> delegate;

/**
 [^en]
 class of the ripple layer, need to confirm protocol ThingRippleLayerProtocol
 +layer will be call when no more ripple instance
 [$en]
 */
@property (nonatomic, strong) Class<ThingRippleLayerProtocol> rippleLayerClass;

/**
 [^en]
 location of the emitter, default is (0.5, 0.5)
 [$en]
 */
@property (nonatomic) CGPoint emitterLocation;

/**
 [^en]view of the emitter[$en]
 */
@property (nonatomic, strong) UIView *emitterView;

/**
 [^en]ripple display time in seconds, default is 5.0s[$en]
 */
@property (nonatomic) CGFloat lifeTime;

/**
 [^en]ripple emission interval in seconds, default is  lifeTime * 0.7[$en]
 */
@property (nonatomic) CGFloat birthRate;

/**
 [^en]
 count of ripples in a group, default is 0
 emission in groups when groupCount > 0
 time interval between the first one of group 1 and the first one of group 2 is groupDuration
 the single ripple interval in the group is still birthRate
 groupCount == 0, means one by one, and single ripple interval is birthRate
 groupCount == 1, means one by one, but single ripple interval is groupDuration
 [$en]
 */
@property (nonatomic) NSInteger groupCount;
/**
 [^en]
 time interval between the first one of group 1 and the first one of group 2
 requires groupDuration >= birthRate * groupCount
 [$en]
 */
@property (nonatomic) CGFloat groupDuration;

@property (nonatomic, readonly) BOOL isWorking;

- (void)start;
- (void)stop;

@end
