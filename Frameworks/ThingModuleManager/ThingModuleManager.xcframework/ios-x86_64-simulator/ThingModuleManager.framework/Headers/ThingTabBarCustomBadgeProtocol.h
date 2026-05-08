
#import <Foundation/Foundation.h>

@class ThingTabItemAttribute;

@protocol ThingTabBarCustomBadgeProtocol <NSObject>

@required
- (void)thing_setBadgeValue:(NSString *)value withItemAttribute:(ThingTabItemAttribute *)attr;

@optional
/** 
 * The origin location of the badge's top-left corner in relation to the bar button, represented as a proportional position.
 * This property allows customizing the precise position of the badge on the tab bar item.
 */
@property (nonatomic) CGPoint originLocation;

/**
 * An offset applied to the originLocation to further adjust the badge's position.
 * This property allows for fine-tuning the placement of the badge beyond the initial origin location.
 */
@property (nonatomic) CGSize offset;

@end

