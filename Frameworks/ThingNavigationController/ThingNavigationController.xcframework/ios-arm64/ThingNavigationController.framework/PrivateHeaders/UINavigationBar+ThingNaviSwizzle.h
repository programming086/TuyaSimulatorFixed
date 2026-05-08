//
//  UINavigationBar+ThingNaviSwizzle.h
//  ThingNavigationController
//
//  Created by ThingInc on 2019/9/26.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@protocol ThingNavigationBarDelegate <UINavigationBarDelegate>

- (BOOL)thing_naviBarShouldSetAlpha:(CGFloat)alpha;

@end

NS_ASSUME_NONNULL_BEGIN

@interface UINavigationBar (ThingNaviSwizzle)

@end

NS_ASSUME_NONNULL_END
