//
//  UIFont+ThingPingFangSC.h
//  ThingUIKit
//
//  Created by ThingInc on 2019/1/16.
//
//  [DOC_IGNORE_FILE]

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIFont (ThingPingFangSC)

+ (UIFont *)thing_pingFangSCRegular:(CGFloat)size __deprecated_msg("Use SystemFont instead");
+ (UIFont *)thing_pingFangSCSemibold:(CGFloat)size __deprecated_msg("Use SystemFont instead");
+ (UIFont *)thing_pingFangSCThin:(CGFloat)size __deprecated_msg("Use SystemFont instead");
+ (UIFont *)thing_pingFangSCLight:(CGFloat)size __deprecated_msg("Use SystemFont instead");
+ (UIFont *)thing_pingFangSCMedium:(CGFloat)size __deprecated_msg("Use SystemFont instead");
+ (UIFont *)thing_pingFangSCUltralight:(CGFloat)size __deprecated_msg("Use SystemFont instead");

@end

NS_ASSUME_NONNULL_END
