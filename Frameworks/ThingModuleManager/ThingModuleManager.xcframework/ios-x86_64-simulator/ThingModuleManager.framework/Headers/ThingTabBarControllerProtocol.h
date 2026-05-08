
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ThingTabItemAttribute;

@protocol ThingTabBarControllerDataSource;
@protocol ThingTabBarControllerDelegate;

@protocol ThingTabBarControllerProtocol <NSObject>

#pragma mark - DataSource & Delegate
@property (nonatomic, weak) id<ThingTabBarControllerDataSource> thing_dataSource;
@property (nonatomic, weak) id<ThingTabBarControllerDelegate> thing_delegate;

#pragma mark - TabBar Attribute
@property (nonatomic) CGFloat tabBarHeight;

@property (nonatomic, strong) UIImage *tabSeparatorImage;   /**<
 If tabSeparatorImage is set, tabBackgroundColor/tabBackgroundImage should also be set. Otherwise, the tab bar will be transparent.
 */

@property (nonatomic, strong) UIColor *tabBackgroundColor;
@property (nonatomic, strong) UIImage *tabBackgroundImage;

@property (nonatomic, assign) CGFloat tabBackgroundAlpha;

@property (nonatomic, assign) UIViewContentMode tabBackgroundImageContentMode;

/**
 Height offset for the background image.
 Defaults to 0, meaning the background image height is the same as the tab bar height.
 */
@property (nonatomic, assign) CGFloat tabBackgroundImageHeightOffset;

/**
 Hides the system background.
 Defaults to NO.
 */
@property (nonatomic,assign) BOOL isHideSystemBackground;

#pragma mark - TabItem Attribute
@property (nonatomic) UIEdgeInsets itemImageInsets;
@property (nonatomic) UIOffset itemTitleOffset;

@property (nonatomic, strong, readonly) NSArray<ThingTabItemAttribute *> *itemAttributes;

- (void)reloadData;

- (ThingTabItemAttribute *)itemAttributeAtIndex:(NSUInteger)index;
- (ThingTabItemAttribute *)itemAttributeOfViewController:(UIViewController *)childController;
- (UIViewController *)childViewControllerAtIndex:(NSUInteger)index;

- (UIControl *)customTabButtonAtIndex:(NSUInteger)index;
- (UIControl *)systemTabButtonAtIndex:(NSUInteger)index;

- (void)selectWithIndex:(NSUInteger)index;

@end
