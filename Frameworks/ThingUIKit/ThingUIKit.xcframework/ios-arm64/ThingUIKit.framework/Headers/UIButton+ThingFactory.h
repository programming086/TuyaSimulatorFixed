//
//  UIButton+ThingFactory.h
//  ThingUIKit
//
//  Created by ThingInc on 2019/5/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (ThingFactory)

+ (instancetype)thing_buttonWithFont:(UIFont * _Nullable)font textColor:(UIColor * _Nullable)textColor;
+ (instancetype)thing_buttonWithFont:(UIFont * _Nullable)font textColor:(UIColor * _Nullable)textColor backgroundColor:(UIColor * _Nullable)backgroundColor;
+ (instancetype)thing_buttonWithFont:(UIFont * _Nullable)font textColor:(UIColor * _Nullable)textColor backgroundColor:(UIColor * _Nullable)backgroundColor frame:(CGRect)frame;

@end

NS_ASSUME_NONNULL_END
