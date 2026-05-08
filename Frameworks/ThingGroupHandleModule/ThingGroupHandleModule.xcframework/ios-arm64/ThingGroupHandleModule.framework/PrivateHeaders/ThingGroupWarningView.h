//
//  ThingGroupWarningView.h
//  ThingGroupHandleModule
//
//  Created by yuheng on 2022/12/8.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupWarningView : UIView

/// 未连云激活提示（红底）
- (void)setWarningInfo:(NSString *)warningInfo;

/// 文本颜色
@property (nonatomic, strong) UIColor *textColor;

/// 图标
@property (nonatomic, strong) NSString *iconName;

@end

NS_ASSUME_NONNULL_END
