//
//  UINavigationController+ThingNaviSwizzle.h
//  ThingNavigationController
//
//  Created by ThingInc on 2019/9/11.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UINavigationController (ThingNaviSwizzle)

///Mark the backButton state of the non-graffiti vc
@property (nonatomic, assign) BOOL hidesBackButtonNotThing;
@property (nonatomic, strong) UINavigationItem *navigationItemNotThing;

@end

NS_ASSUME_NONNULL_END
