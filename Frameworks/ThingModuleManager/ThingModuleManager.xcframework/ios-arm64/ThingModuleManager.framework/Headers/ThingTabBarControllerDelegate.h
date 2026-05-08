
#import <Foundation/Foundation.h>

@protocol ThingTabBarControllerDelegate <NSObject>

@optional

- (NSUInteger)thing_defaultTabIndex;

/**
 Sets the style attributes for the title of a tab item.

 @param state The control state for which the title attributes are to be set.
 @return A dictionary containing the attributes to be applied to the tab item title for the specified state.
 */
- (NSDictionary<NSAttributedStringKey,id> *)thing_tabItemTitleTextAttributesForState:(UIControlState)state;

/**
 Called before a view controller is added to the tab bar.

 @param tabController The tab bar controller handling the event.
 @param childController The view controller that is about to be added.
 @param attr The attribute associated with the tab item.
 */
- (void)thing_tabBar:(UITabBarController<ThingTabBarControllerProtocol> *)tabController willAdd:(UIViewController *)childController withItemAttribute:(ThingTabItemAttribute *)attr;

/**
 Determines whether a tab item can be selected.

 This method is only called if the default selection is invalid.
 If you implement this method, please refrain from handling business logic within this callback.
 Be sure to only return YES/NO.
 By default, selection is determined by ThingTabItemAttribute.viewController.

 @param tabController The tab bar controller handling the event.
 @param childController The view controller associated with the tab.
 @param attr The attribute associated with the tab item.
 @return YES if the tab item can be selected; NO otherwise.
 */
- (BOOL)thing_tabBar:(UITabBarController<ThingTabBarControllerProtocol> *)tabController childControllerCanBeSelected:(__kindof UIViewController *)childController withItemAttribute:(ThingTabItemAttribute *)attr;

/**
 Determines whether a view controller can be shown when a tab is clicked.

 @param controller The tab bar controller handling the event.
 @param childController The view controller associated with the tab.
 @param attr The attribute associated with the tab item.
 @return YES if the view controller can be shown; NO otherwise.
 */
- (BOOL)thing_tabBar:(UITabBarController<ThingTabBarControllerProtocol> *)controller shouldShow:(UIViewController *)childController withItemAttribute:(ThingTabItemAttribute *)attr;

/**
 Called when a tab item is selected.

 @param tabController The tab bar controller handling the event.
 @param childController The selected view controller.
 @param attr The attribute associated with the selected tab item.
 */
- (void)thing_tabBar:(UITabBarController<ThingTabBarControllerProtocol> *)tabController didSelect:(UIViewController *)childController withItemAttribute:(ThingTabItemAttribute *)attr;

/**
 Called when a tab item is unselected.

 @param tabController The tab bar controller handling the event.
 @param childController The unselected view controller.
 @param attr The attribute associated with the unselected tab item.
 */
- (void)thing_tabBar:(UITabBarController<ThingTabBarControllerProtocol> *)tabController didUnselect:(UIViewController *)childController withItemAttribute:(ThingTabItemAttribute *)attr;

/**
 Determines whether a badge can be set on a tab item.

 @param tabController The tab bar controller handling the event.
 @param value The badge value to be set.
 @param childController The view controller associated with the tab.
 @param attr The attribute associated with the tab item.
 @return YES if the badge can be set; NO otherwise.
 */
- (BOOL)thing_tabBar:(UITabBarController<ThingTabBarControllerProtocol> *)tabController shouldSetBadge:(NSString *)value withViewController:(UIViewController *)childController itemAttribute:(ThingTabItemAttribute *)attr;


@end
