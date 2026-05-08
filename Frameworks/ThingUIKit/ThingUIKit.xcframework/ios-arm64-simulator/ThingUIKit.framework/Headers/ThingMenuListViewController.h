
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingMenuListViewController;

@protocol ThingMenuListDataProtocol <NSObject>

@optional
- (NSString *)menuReusableCellIdentifier;

@end

@protocol ThingMenuListCellProtocol <NSObject>

- (void)setupMenuWithData:(id)data;

@optional
+ (CGFloat)menuCellHeightForData:(id)data;
+ (NSString *)menuCellIdentifier;

@end

@protocol ThingMenuListViewControllerDelegate <NSObject>

/**
 [^en]Callback when background is clicked[$en]
 */
- (void)thing_menuListBackgroundTapAction:(ThingMenuListViewController *)menuListVC;

- (void)thing_menuList:(ThingMenuListViewController *)menuListVC didSelectRowAtIndexPath:(NSIndexPath *)indexPath;

@end


@interface ThingMenuListViewController : UIViewController

@property (nonatomic, weak) id<ThingMenuListViewControllerDelegate> delegate;

@property (nonatomic, strong, readonly) UIView *backgroundView;
/**
 [^en]parent view of menu view and indicator view[$en]
 */
@property (nonatomic, strong, readonly) UIView *containerView;

@property (nonatomic, strong) UITableView *menuView;

/**
 [^en]adjust the height of the menu view to display all the cells[$en]
 */
@property (nonatomic) BOOL automaticMenuHeight;

@property (nonatomic) NSArray<Class<ThingMenuListCellProtocol>> *menuCellClassArr;
@property (nonatomic, copy) NSArray<id<ThingMenuListDataProtocol>> *menuDataArr;

@property (nonatomic, strong) UIView *indicatorView;

/**
 [^en]adjust the anchor point of the container view to the center point of the indicator view[$en]
 */
@property (nonatomic) BOOL makeAnchorPointFollowIndicator;

#pragma mark - StatusBar
@property (nonatomic) BOOL statusBarHidden;
@property (nonatomic) UIStatusBarStyle statusBarStyle;
@property (nonatomic) UIStatusBarAnimation statusBarAnimation;

#pragma mark - Orientation
/**
 [^en]shouldAutorotate default-NO[$en]
 */
@property (nonatomic) BOOL autorotate;

/**
[^en]supportedInterfaceOrientations default-portrait[$en]
*/
@property (nonatomic) UIInterfaceOrientationMask supportedOrientations;

@end

NS_ASSUME_NONNULL_END
