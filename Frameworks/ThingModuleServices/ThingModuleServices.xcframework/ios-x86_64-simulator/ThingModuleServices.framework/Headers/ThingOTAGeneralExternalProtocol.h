//
//  ThingOTAGeneralExternalProtocol.h
//  ThingModuleServices
//
//  Created by jesse on 2020/12/18.
//

@protocol ThingOTAGeneralExternalProtocol <NSObject>


@optional
/// @brief 取消强制升级事件自定义处理
///
/// 1. 强制升级情况，检测升级中，升级弹框点击“取消” 按钮事件。
/// 2. 强制升级情况，点击 navigationBar 返回按钮（有进度情况会有弹框，点击“确定”按钮）。
///
/// @return YES 自定义处理，NO 默认 `[self.navigationController popToRootViewControllerAnimated:YES]`
- (BOOL)didTapCancelForceUpgrade;

/// @brief 检测到升级进行弹窗后，点击升级按钮时自定义处理
/// @return YES 自定义处理，NO 默认进入升级页面
- (BOOL)didTapUpgrade;

@end
