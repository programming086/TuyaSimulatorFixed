
#import <UIKit/UIKit.h>

#if __has_include(<ThingNavigationController/UIViewController+ThingNavigation.h>)
#import <ThingNavigationController/UIViewController+ThingNavigation.h>
#elif __has_include("UIViewController+TYNavigation.h")
#import "UIViewController+ThingNavigation.h"
#endif

#import "ThingSearchBar.h"

#import "ThingSearchControllerAppearance.h"

@class ThingSearchController;

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ThingSearchControllerStatus_Normal,        // normal data display
    ThingSearchControllerStatus_Ready,         // search actived but no input
    ThingSearchControllerStatus_Result,        // search result display
} ThingSearchControllerStatus;

@protocol ThingSearchReadyControllerProtocol <NSObject>

@property (nonatomic, weak) ThingSearchController * searchController;

@optional
- (void)viewControllerWillAppearWithAnimation:(BOOL)animate;
- (void)viewControllerWillDisappearWithAnimation:(BOOL)animate;

- (void)viewControllerDidAppear;
- (void)viewControllerDidDisappear;

@end


/*
How to use ThingSearchController

Step1:
@interface YourViewController : ThingSearchController
@end

Step2:
implement table data source in YourViewController.m

Step3:
Have fun 😉
*/
@interface ThingSearchController : UIViewController <UITableViewDelegate, UITableViewDataSource, UISearchBarDelegate, ThingSearchBarDelegate>

/**
 [^en]
 disable searchTableClass config in ThingSearchControllerAppearance, default is NO
 [$en]
 */
@property (nonatomic) BOOL disableApperanceTableClass;

/**
 [^en]
 normal data display view
 tableView.delegate = self, tableView.dataSource = self
 [$en]
 */
@property (nonatomic, strong, readonly) UITableView *tableView;
@property (nonatomic) UITableViewStyle tableStyle;

/**
 [^en]
 searbar will add to table header view
 searbar.delegate = self
 [$en]
 */
@property (nonatomic, strong, readonly) ThingSearchBar *searchBar;

/// search bar container height
@property (nonatomic, assign, readonly) CGFloat searchContainerHeight;

@property (nonatomic, readonly) ThingSearchControllerStatus searchStatus;

/**
 [^en]
 view controller which will be used to display for ready status
 default is a view controller with black transparent view, set to nil can remove it
 [$en]
 */
@property (nonatomic, strong) __kindof UIViewController<ThingSearchReadyControllerProtocol> * _Nullable searchReadyController;
/**
 [^en]
 view controller which will be used to display search result, default is nil
 if search result controller is nil, will use self.tableView to display search result
 [$en]
  */
@property (nonatomic, strong) __kindof UIViewController<ThingSearchReadyControllerProtocol> * _Nullable searchResultController;


#pragma mark - Callback
/**
 [^en]
 call back when searchStatus changed
 [$en]
 */
- (void)searchControllerStatusDidChanged;

/**
 [^en]
 call back when search bar right button (like cancel button) init finish
 cancel button will not be created until it will be shown
 [$en]
 */
- (void)searchControllerRightButtonInitial;

/**
 [^en]
 call back when table init finish
 you can create table by yourself in this method and set with kvc key "_tableView"
 [$en]
 */
- (void)searchControllerTableViewInitial;

/**
 [^en]
 you can use keyboard notification to adjust your view controller contentInset
 [$en]
 */
- (void)searchControllerKeyboardWillShow:(NSNotification *)notif;
- (void)searchControllerKeyboardDidShow:(NSNotification *)notif;
- (void)searchControllerKeyboardWillHide:(NSNotification *)notif;
- (void)searchControllerKeyboardDidHide:(NSNotification *)notif;


#pragma mark - Methods Need Super
// if you override these methods in subclass, you have to call super

- (void)observeValueForKeyPath:(nullable NSString *)keyPath ofObject:(nullable id)object change:(nullable NSDictionary<NSKeyValueChangeKey, id> *)change context:(nullable void *)context NS_REQUIRES_SUPER;

- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate NS_REQUIRES_SUPER;

- (BOOL)searchBarShouldBeginEditing:(UISearchBar *)searchBar NS_REQUIRES_SUPER;
- (void)searchBarCancelButtonClicked:(UISearchBar *)searchBar NS_REQUIRES_SUPER;
- (void)searchBar:(UISearchBar *)searchBar textDidChange:(NSString *)searchText NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END
