//
//  TYMixColdWarmColorPanel.h
//  TYUIKit
//
//  Created by TuyaInc on 2021/1/11.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYMixColdWarmColorPanel : UIControl

/**
 * 构造方法，回调返回百分比
 *
 * @param bubbleWidth 取色器宽度
 * @param touchingCompletion 滑动手势变化的回调
 * @param endCompletion  滑动手势停止时的回调
 */
+ (instancetype)coldWarmPercentWithBubbleWidth:(CGFloat)bubbleWidth
                            touchingCompletion:(void (^)(NSInteger percent))touchingCompletion
                                 endCompletion:(void (^)(NSInteger percent))endCompletion;

/// 初始冷暖度
@property (nonatomic, assign) NSInteger anchorPercent;

@end

NS_ASSUME_NONNULL_END
