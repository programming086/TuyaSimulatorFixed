
#import <Foundation/Foundation.h>

@class ThingTabItemAttribute;

@protocol ThingModuleTabBarStyleProtocol <NSObject>

@optional
- (void)tabBarDidLoad;

- (Class)tabBarModuleForDefaultSelected;

- (NSDictionary<NSAttributedStringKey, id> *)tabBarItemTitleAttributesForState:(UIControlState)state withNativeResult:(NSDictionary<NSAttributedStringKey, id> *)nativeResult;

- (void)customTabBarStyleWithItemAttributes:(NSMutableArray<ThingTabItemAttribute *> *)attrArr;

- (void)tabBarWillLoadModule:(Class)moduleCls withAttributes:(NSMutableArray<ThingTabItemAttribute *> *)attrArr;

/**
 * Called when a tab bar item is about to be added.
 *
 * @param controller The view controller associated with the tab bar item.
 * @param attribute The attribute for the tab bar item.
 * @return YES if the event should propagate to the native code implementation; NO otherwise.
 */
- (BOOL)tabBarWillAdd:(nullable UIViewController *)controller withItemAttribute:(nonnull ThingTabItemAttribute *)attribute;

/**
 * Determines whether a tab bar item can be selected.
 *
 * This method is only called if the default selection is invalid. If implemented,
 * ensure to return only YES or NO.
 *
 * @param controller The view controller associated with the tab bar item.
 * @param attribute The attribute for the tab bar item.
 * @param nativeResult The default result provided by the native implementation.
 * @return YES if the item can be selected; NO otherwise. This method's priority is higher than native.
 */
- (BOOL)tabBarCanSelect:(nullable UIViewController *)controller withItemAttribute:(ThingTabItemAttribute *)attribute nativeResult:(BOOL)nativeResult;

/**
 * Determines whether the view controller corresponding to a tapped tab should be shown.
 *
 * @param controller The tapped view controller.
 * @param attribute The attribute for the tab bar item.
 * @param nativeResult The default result provided by the native implementation.
 * @return YES if the view controller should be shown; NO otherwise.
 */
- (BOOL)tabBarShouldShow:(nullable UIViewController *)controller withItemAttribute:(ThingTabItemAttribute *)attribute nativeResult:(BOOL)nativeResult;

/**
 * Called when a tab bar item is selected.
 *
 * @param controller The selected view controller.
 * @param attribute The attribute for the tab bar item.
 * @return YES if the event should propagate to the native code implementation; NO otherwise.
 */
- (BOOL)tabBarDidSelect:(nullable UIViewController *)controller withItemAttribute:(ThingTabItemAttribute *)attribute;

/**
 * Called when a tab bar item is unselected.
 *
 * @param controller The unselected view controller.
 * @param attribute The attribute for the tab bar item.
 * @return YES if the event should propagate to the native code implementation; NO otherwise.
 */
- (BOOL)tabBarDidUnselect:(nullable UIViewController *)controller withItemAttribute:(ThingTabItemAttribute *)attribute;

/**
 * Determines whether a badge can be set on a tab bar item.
 *
 * @param badge The badge value to set.
 * @param attribute The attribute for the tab bar item.
 * @param nativeResult The default result provided by the native implementation.
 * @return YES if the badge can be set; NO otherwise.
 */
- (BOOL)tabBarShouldSetBadge:(nullable NSString *)badge withItemAttribute:(ThingTabItemAttribute *)attribute nativeResult:(BOOL)nativeResult;

@end
