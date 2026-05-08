
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingMixColdWarmColorPanel : UIControl

/**
 * Constructor, callback returns percentage
 *
 * @param bubbleWidth Color picker width
 * @param touchingCompletion Callback for sliding gesture changes
 * @param endCompletion  Callback when the sliding gesture stops
 */
+ (instancetype)coldWarmPercentWithBubbleWidth:(CGFloat)bubbleWidth
                            touchingCompletion:(void (^)(NSInteger percent))touchingCompletion
                                 endCompletion:(void (^)(NSInteger percent))endCompletion;

/// Initial temperature
@property (nonatomic, assign) NSInteger anchorPercent;

@end

NS_ASSUME_NONNULL_END
