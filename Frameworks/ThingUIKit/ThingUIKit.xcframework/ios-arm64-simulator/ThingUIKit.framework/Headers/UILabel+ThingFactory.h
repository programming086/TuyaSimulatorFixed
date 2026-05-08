//
//  UILabel+ThingFactory.h
//  ThingUIKit
//
//  Created by ThingInc on 2019/5/14.
//

#import <UIKit/UIKit.h>

@interface UILabel (ThingFactory)

+ (instancetype)thing_labelWithText:(NSString *)text font:(UIFont *)font textColor:(UIColor *)color;
+ (instancetype)thing_labelWithText:(NSString *)text font:(UIFont *)font textColor:(UIColor *)color frame:(CGRect)frame;

+ (instancetype)thing_labelWithText:(NSString *)text font:(UIFont *)font textColor:(UIColor *)color widthMax:(CGFloat)width;

@end
