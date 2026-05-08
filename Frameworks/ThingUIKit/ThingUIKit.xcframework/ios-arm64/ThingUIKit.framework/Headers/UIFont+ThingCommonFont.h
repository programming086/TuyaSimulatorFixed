//
//  UIFont+ThingCommonFont.h
//  ThingUIKit
//
//  Created by nuo on 2021/5/12.
//

#import <UIKit/UIKit.h>
#import "UIFont+ThingAlphanumeric.h"

NS_ASSUME_NONNULL_BEGIN

@interface UIFont (ThingCommonFont)

+ (BOOL)thing_registerFont:(NSString *)path;

@end

NS_ASSUME_NONNULL_END
