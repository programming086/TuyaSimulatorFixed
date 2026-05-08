//
//  TYSecurityArmAbilityUISkinProtocol.h
//  TYSecurityArmAbilityUISkin
//
//  Created by Tuya.Inc on 2021/4/27.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TYSecurityArmMode);

@protocol TYSecurityArmAbilityUISkinProtocol <NSObject>

/// 跳转到规则设置页面
/// @param mode 布防模式
- (void)gotoSecurityArmRuleSettingViewController:(TYSecurityArmMode)mode;

/// 跳转到延迟设置页面
/// @param mode 布防模式
/// @param handler 回调
- (void)gotoSecurityDelaySettingViewController:(TYSecurityArmMode)mode notAllowSetResponse:(void(^)(void))handler;

/// 弹出忽略设备弹框
/// @param tempMode 布防模式
/// @param devices 布撤防过程中的忽略设备id
/// @param confirmToArm 继续布防回调
/// @param cancelToArm 取消布防回调
- (void)showSecurityBypassAlertView:(TYSecurityArmMode)tempMode
                            devices:(NSArray<NSString *> *)devices
               confirmToArmCallBack:(void(^)(void))confirmToArm
                cancelToArmCallBack:(void(^)(void))cancelToArm;

/// 跳转忽略设备页面
/// @param tempMode 布防模式
/// @param devices 布撤防过程中的忽略设备id
/// @param confirmToArm 继续布防回调
/// @param cancelToArm 取消布防回调
- (void)gotoSecurityBypassViewController:(TYSecurityArmMode)tempMode
                                 devices:(NSArray<NSString *> *)devices
                    confirmToArmCallBack:(void(^)(void))confirmToArm
                     cancelToArmCallBack:(void(^)(void))cancelToArm __deprecated_msg("This method is deprecated, Use -showSecurityBypassAlertView:devices:confirmToArmCallBack:cancelToArmCallBack: instead");

/// 跳转到布防模式设置页面
- (void)gotoSecurityModeSettingViewController;

/// 跳转到异常设备列表页面
/// @param datas 异常设备列表
- (void)gotoSecurityIgnoreDeviceViewControllerWithBypassDatas:(NSArray *)datas;

///根据布撤防状态返回对应状态的设置小图标
- (UIImage *)querySecurityArmModeConfigImageByArmMode:(TYSecurityArmMode)armMode;

///根据布撤防状态返回对应状态的大图标
/// @param isSelected 是否是选中状态的图标
- (UIImage *)querySecurityArmModeImageByArmMode:(TYSecurityArmMode)armMode isSelected:(BOOL)isSelected;

@end

NS_ASSUME_NONNULL_END
