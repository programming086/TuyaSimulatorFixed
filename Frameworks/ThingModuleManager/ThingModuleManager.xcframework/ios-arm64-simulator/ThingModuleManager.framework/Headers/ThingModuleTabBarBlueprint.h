
#import <Foundation/Foundation.h>

@class ThingTabItemAttribute;

NS_ASSUME_NONNULL_BEGIN

@protocol ThingModuleTabBarBlueprint <NSObject>

@property (nonatomic, strong, nullable) NSArray<ThingTabItemAttribute *> *tabItemAttributes;
@property (nonatomic, strong) Class defaultSelectModule;

@property (nonatomic, strong, nullable) UIColor *titleColorForNormal;
@property (nonatomic, strong, nullable) UIColor *titleColorForSelect;

- (__kindof UITabBarController *)tabBarController;
- (__kindof UITabBar *)tabBar;

- (NSUInteger)indexOfModule:(Class)moduleCls tag:(nullable NSString *)tag;
- (UIViewController *)viewControllerOfModule:(Class)moduleCls;

- (void)clearTabs;
- (void)reloadTabItemAttributesIfNil;

- (void)reloadTabs;
- (void)reloadTabsWithSelectIndex:(NSUInteger)index;
- (void)reloadTabsWithSelectModule:(nullable Class)moduleCls;
- (void)reloadTabsWithSelectModule:(nullable Class)moduleCls tag:(nullable NSString *)tag;

- (void)showTabWithIndex:(NSUInteger)index;
- (void)showTabWithIndex:(NSUInteger)index animated:(BOOL)animated;
- (void)showTabWithModule:(Class)moduleCls;
- (void)showTabWithModule:(Class)moduleCls tag:(nullable NSString *)tag;

- (void)setBadgeForIndex:(NSUInteger)index badge:(nullable NSString *)badge;
- (void)setBadgeForModule:(Class)moduleCls badge:(nullable NSString *)badge;
- (void)setBadgeForModule:(Class)moduleCls tag:(nullable NSString *)tag badge:(nullable NSString *)badge;
- (void)cleanAllBadge;

// Sets the tab separator image. Use nil for the default system image, or [UIImage new] to remove the separator.
- (void)setTabSeparatorImage:(UIImage *)image;

// Sets the background properties for the tab bar
- (void)setTabBackgroundColor:(UIColor *)color;
- (void)setTabBackgroundImage:(UIImage *)image;
- (void)setTabBackgroundImageHeightOffset:(CGFloat)heightOffset;
- (void)setTabBackgroundAlpha:(CGFloat)tabBackgroundAlpha;
- (void)setTabBackgroundImageContentMode:(UIViewContentMode)tabBackgroundImageContentMode;
- (void)setIsHideSystemBackground:(BOOL)isHideSystemBackground;

// Retrieves the system TabBarButton
- (__kindof UIControl *)systemTabButtonForIndex:(NSUInteger)idx;
- (__kindof UIControl *)systemTabButtonForModule:(Class)moduleCls;
- (__kindof UIControl *)systemTabButtonForModule:(Class)moduleCls tag:(nullable NSString *)tag;

// Retrieves the custom TabBarButton
- (__kindof UIControl *)customTabButtonForIndex:(NSUInteger)idx;
- (__kindof UIControl *)customTabButtonForModule:(Class)moduleCls;
- (__kindof UIControl *)customTabButtonForModule:(Class)moduleCls tag:(nullable NSString *)tag;

@end

NS_ASSUME_NONNULL_END
