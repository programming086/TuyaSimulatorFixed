//
//  NSObject+ThingNav.h
//  ThingNavigationController
//
//  Created by on 2021/11/19.
//

#import <Foundation/Foundation.h>


@interface NSObject (ThingNav)
+ (void)thing_nav_swizzleSEL:(SEL)oriSel withSEL:(SEL)swiSel;
@end

