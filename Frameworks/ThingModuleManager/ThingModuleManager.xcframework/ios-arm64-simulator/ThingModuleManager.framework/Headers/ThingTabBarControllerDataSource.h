
#import <Foundation/Foundation.h>

#import "ThingTabItemAttribute.h"

@protocol ThingTabBarControllerDataSource <NSObject>

@required
- (NSArray<ThingTabItemAttribute *> *)thing_tabItemAttributes;

@end
