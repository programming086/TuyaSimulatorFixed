//
//  UIFont+ThingAlphanumeric.h
//  ThingUIKit
//
//  Created by niuo on 2021/5/11.
//

#import <UIKit/UIKit.h>
#import "UIFont+ThingCommonFont.h"

NS_ASSUME_NONNULL_BEGIN

@interface UIFont (ThingAlphanumeric)

+ (UIFont *)thing_alphanumericRegular:(CGFloat)size;
+ (UIFont *)thing_alphanumericMedium:(CGFloat)size;
+ (UIFont *)thing_alphanumericBold:(CGFloat)size;

@end

NS_ASSUME_NONNULL_END
