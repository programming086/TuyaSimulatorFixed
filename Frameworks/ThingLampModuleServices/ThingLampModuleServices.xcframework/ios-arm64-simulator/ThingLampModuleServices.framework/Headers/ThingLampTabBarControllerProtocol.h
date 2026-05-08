//
//  ThingLampTabBarControllerProtocol.h
//  ThingLampModuleServices
//
//  Created by 凌晨 on 2022/9/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLampTabBarController;
@class ThingMenuListViewController;

@protocol ThingLampTabBarControllerDataSource <NSObject>

@optional;

///  是否要显示编辑 item
/// - Parameter tabBarController: tabBarController
- (BOOL)showEditMenuItemForTabBarController:(ThingLampTabBarController *)tabBarController;


/// 是否需要显示设备用途
/// - Parameter tabBarController: tabBarController
- (BOOL)showDevicePurposeItemForTabBarController:(ThingLampTabBarController *)tabBarController;


/// 是否要显示批量命名入口
/// - Parameter tabBarController: tabBarController
- (BOOL)showBatchRenameItemForTabBarController:(ThingLampTabBarController *)tabBarController;

/// 是否要显示群组配置下发
/// - Parameter tabBarController: tabBarController
- (BOOL)showGroupConfigDeliveryItemForTabBarController:(ThingLampTabBarController *)tabBarController;

@end


@protocol ThingLampTabBarControllerDelegate <NSObject>

/// tabcontroller 导航栏上两个 menu list 的弹窗选择
/// - Parameter indexPath: 位置
- (void)menuList:(ThingMenuListViewController *)menuListVC didSelectRowAtIndexPath:(NSIndexPath *)indexPath;

@end

NS_ASSUME_NONNULL_END
