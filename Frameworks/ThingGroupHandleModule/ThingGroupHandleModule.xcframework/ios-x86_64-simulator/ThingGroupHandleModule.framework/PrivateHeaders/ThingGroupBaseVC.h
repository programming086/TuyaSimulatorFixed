//
//  ThingGroupBaseVC.h
//  ThingGroupHandleModule
//
//  Created by jesse on 2021/5/18.
//

#import <ThingSmartBusinessLibrary/TPBaseTableViewController.h>
#import "ThingGroupSelectListDeviceCell.h"
#import "ThingGroupUtil.h"
#import <ThingGroupManagerKit/ThingGroupManagerKit.h>
#import "ThingGroupHandleModuleConstants.h"

NS_ASSUME_NONNULL_BEGIN

/// 群组添加/编辑页面的 View
@interface ThingGroupBaseView : UIView

/// 群组是否是编辑状态，区别在于显示的文案
/// 如果是编辑状态设为 YES，添加状态设为 NO
/// 默认为 NO
@property (nonatomic) BOOL editing;

/// 顶部显示一些提示信息和帮助入口的按钮等，container view
@property (nonatomic, strong) UIView *topView;
/// 帮助入口的按钮
@property (nonatomic, strong) UIButton *tipButton;
/// 顶部提示文案
@property (nonatomic, strong) UILabel *tipsLabel;
/// 展示设备列表的 tableView
@property (nonatomic, strong) UITableView *tableView;

/// 显示没有设备的界面
/// @param title 显示的文案
- (void)showEmptyViewWithTitle:(NSString *)title;

/// 隐藏没有设备的界面
- (void)hideEmptyView;

/// 显示双模未连云激活提示
- (void)showWarning;

/// 隐藏双模未连云激活提示
- (void)hideWarning;

@end


@interface ThingGroupBaseVCData : NSObject
@property (nonatomic, strong) NSArray<NSString *> *selectDevices;
@property (nonatomic, strong) NSArray <NSString *> *unSelectDevices;
@end

/// The reuse identifier for the default cell, which is  `ThingBleMeshAddGroupDeviceCell`
extern NSString const *ThingGroupBaseViewControllerTableViewCellIdentifier;

/// 群组添加/编辑页面（ 新样式，圆角 TableView）
///
/// 可以通过继承来实现自定义群组页面行为
/// 或者直接使用 `ThingGroupBaseView`，但需要自己实现 `UITableViewDelegate` 来实现圆角 TableView 效果
@interface ThingGroupBaseVC : TPBaseViewController <UITableViewDataSource, UITableViewDelegate>


/// ThingGroupBaseViewController 自身的 view
///
/// 默认实现 view.tipButton 的点击事件
@property (nonatomic) ThingGroupBaseView *view;
///群组能力接口
@property (nonatomic, strong) id<ThingGroupServiceProtocol> groupService;

@property (nonatomic, strong, readonly) ThingGroupBaseVCData *data;
- (void)reloadTableViewWithData:(ThingGroupBaseVCData *)data;
- (void)reloadTableView;

- (ThingGroupSelectListDeviceCellModel *)cellModelForDeviceModel:(ThingSmartDeviceModel *)model;

- (void)didSelectCellModel:(ThingGroupSelectListDeviceCellModel *)cellModel;
@end

NS_ASSUME_NONNULL_END
