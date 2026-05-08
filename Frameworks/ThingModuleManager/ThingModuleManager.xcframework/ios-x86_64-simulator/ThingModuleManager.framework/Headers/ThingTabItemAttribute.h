
#import <Foundation/Foundation.h>

#import "ThingTabBarCustomButton.h"
#import "ThingTabBarCustomBadgeProtocol.h"

#define ThingTabIndex_NotOnTab NSUIntegerMax

@interface ThingTabItemAttribute : NSObject

@property (nonatomic, strong, readonly) Class moduleClass; /**< The module class automatically filled for the tab item. */

@property (nonatomic, strong) __kindof UIViewController *viewController;

/**
 * Determines if the tab item is the default selected item.
 *
 * This property is effective only for tab items registered under tabSelectModule in the config.
 * A module can have at most one default selected item; if not set, the first item will be selected by default.
 */
@property (nonatomic) BOOL defaultSelected;

@property (nonatomic, copy) NSString *itemTitle;
@property (nonatomic, strong) UIImage *normalImage;
@property (nonatomic, strong) UIImage *selectedImage;

@property (nonatomic, copy) NSString *badgeValue;
@property (nonatomic, strong) UIColor *badgeColor NS_AVAILABLE_IOS(10_0);
@property (nonatomic, strong) NSDictionary<NSAttributedString *, id> *badgeTextAttribute NS_AVAILABLE_IOS(10_0);

@property (nonatomic, copy) NSString *tag;

@property (nonatomic) UIEdgeInsets imageInsets;
@property (nonatomic) UIOffset titleOffset;


@property (nonatomic, strong) __kindof ThingTabBarCustomButton *customButton;  /**< A custom button for the tab item, implemented when a fully custom tab bar button is needed. */
@property (nonatomic, strong) __kindof UIView<ThingTabBarCustomBadgeProtocol> *customBadgeView;  /**< A custom view for the tab badge, if further customization is needed. */

@property (nonatomic, copy) NSString *accessibilityIdentifier;

@property (nonatomic, readonly) NSUInteger tabIndex;   /**< The index position of the tab item in the tab bar. */

@end

