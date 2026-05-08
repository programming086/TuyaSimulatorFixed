
#import <UIKit/UIKit.h>

#import "ThingNavigationBarItem.h"

@interface ThingNavigationBarCustomButton : UIButton

@property (nonatomic, strong, readonly) ThingNavigationBarItem *barItem;

+ (ThingNavigationBarCustomButton *)buttonWithBarItem:(ThingNavigationBarItem *)item;

@end
