//
//  ThingGroupEditHUD.h
//  ThingGroupHandleModule
//
//  Created by 尼诺 on 2021/7/26.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingGroupEditHUD : UIView

@property (nonatomic, strong) UILabel *progressLabel;

- (void)showProcess;
- (void)showLoading;

@end

NS_ASSUME_NONNULL_END
