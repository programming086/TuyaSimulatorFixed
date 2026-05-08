//
//  NSObject+ThingUIKitSwizzler.h
//  ThingUIKit
//
//  Created by ThingInc on 2019/3/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (ThingUIKitSwizzler)

+ (void)thing_uikit_swizzleSEL:(SEL)oriSel withSEL:(SEL)swiSel;
+ (void)thing_uikit_swizzleSEL:(SEL)oriSel withSEL:(SEL)swiSel fromClass:(Class)cls;

@end

NS_ASSUME_NONNULL_END
