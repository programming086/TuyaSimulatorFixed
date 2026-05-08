//
//  TYSearchController.h
//  TYUIKit
//
//  Created by TuyaInc on 2019/1/23.
//

#import <UIKit/UIKit.h>

#if __has_include(<TYNavigationController/UIViewController+TYNavigation.h>)
#import <TYNavigationController/UIViewController+TYNavigation.h>
#elif __has_include("UIViewController+TYNavigation.h")
#import "UIViewController+TYNavigation.h"
#endif

#import "TYSearchBar.h"

#import "TYSearchControllerAppearance.h"

@class TYSearchController;

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    TYSearchControllerStatus_Normal,        // normal data display
    TYSearchControllerStatus_Ready,         // search actived but no input
    TYSearchControllerStatus_Result,        // search result display
} TYSearchControllerStatus;

@protocol TYSearchReadyControllerProtocol <NSObject>

@property (nonatomic, weak) TYSearchController * searchController;

@optional
- (void)viewControllerWillAppearWithAnimation:(BOOL)animate;
- (void)viewControllerWillDisappearWithAnimation:(BOOL)animate;

- (void)viewControllerDidAppear;
- (void)viewControllerDidDisappear;

@end


/*
How to use TYSearchController

Step1:
@interface YourViewController : TYSearchController
@end

Step2:
implement table data source in YourViewController.m

Step3:
Have fun 😉
*/
@interface TYSearchController : UIViewController <UITableViewDelegate, UITableViewDataSource, UISearchBarDelegate, TYSearchBarDelegate>

/**
 [^zh]
 禁用TYSearchControllerAppearance中的searchTableClass，默认NO
 [$zh]
 [^en]
 disable searchTableClass config in TYSearchControllerAppearance, default is NO
 [$en]
 */
@property (nonatomic) BOOL disableApperanceTableClass;

/**
 [^zh]
 内容展示视图，默认 tableView.delegate = self, tableView.dataSource = self
 [$zh]
 [^en]
 normal data display view
 tableView.delegate = self, tableView.dataSource = self
 [$en]
 */
@property (nonatomic, strong, readonly) UITableView *tableView;
@property (nonatomic) UITableViewStyle tableStyle;

/**
 [^zh]
 search bar 会被添加到 tableView 的 header
 默认searbar.delegate = self
 [$zh]
 [^en]
 searbar will add to table header view
 searbar.delegate = self
 [$en]
 */
@property (nonatomic, strong, readonly) TYSearchBar *searchBar;

/// search bar container height
@property (nonatomic, assign, readonly) CGFloat searchContainerHeight;

@property (nonatomic, readonly) TYSearchControllerStatus searchStatus;

/**
 [^zh]
 用来展示待输入状态的控制器
 默认是带有透明度的黑色蒙层，设置为nil可移除
 [$zh]
 [^en]
 view controller which will be used to display for ready status
 default is a view controller with black transparent view, set to nil can remove it
 [$en]
 */
@property (nonatomic, strong) __kindof UIViewController<TYSearchReadyControllerProtocol> * _Nullable searchReadyController;
/**
 [^zh]
 用来展示搜索结果的控制器，默认nil
 如果为nil，则使用 tableView 来展示搜索结果
 [$zh]
 [^en]
 view controller which will be used to display search result, default is nil
 if search result controller is nil, will use self.tableView to display search result
 [$en]
  */
@property (nonatomic, strong) __kindof UIViewController<TYSearchReadyControllerProtocol> * _Nullable searchResultController;


#pragma mark - Callback
/**
 [^zh]
 当搜索状态(searchStatus)变化时，发生回调
 [&zh]
 [^en]
 call back when searchStatus changed
 [$en]
 */
- (void)searchControllerStatusDidChanged;

/**
 [^zh]
 当右侧按钮(例如 取消按钮)初始化完成时，发生回调
 取消按钮只有在将要展示时才会创建
 [$zh]
 [^en]
 call back when search bar right button (like cancel button) init finish
 cancel button will not be created until it will be shown
 [$en]
 */
- (void)searchControllerRightButtonInitial;

/**
 [^zh]
 当tableView初始化完成后，发生回调
 可以在此回调中修改 或 通过kvc重新设置 tableView
 [$zh]
 [^en]
 call back when table init finish
 you can create table by yourself in this method and set with kvc key "_tableView"
 [$en]
 */
- (void)searchControllerTableViewInitial;

/**
 [^zh]
 键盘相关回调
 [$zh]
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
