//
//  TYOTAGeneralPlugAPI.h
//  Pods
//
//  Created by 萧然 on 2022/4/2.
//

#ifndef TYOTAGeneralPlugAPI_h
#define TYOTAGeneralPlugAPI_h

typedef NS_ENUM(NSUInteger, TYOTAControllerTheme) {
    TYOTAControllerWhiteTheme,
    TYOTAControllerBlackTheme
};

// 设备升级的状态
typedef NS_ENUM(NSUInteger, TYDeviceUpgradeStatus) {
    TYDeviceUpgradeStatusNone,      // 不需要升级
    TYDeviceUpgradeStatusNeed,      // 有新固件
    TYDeviceUpgradeStatusUpgrading  // 正在升级中
};

// 刷新固件升级入口cell的通知，会在页面返回时post
#define TYOTAEntranceRefreshNotification @"kTYOTAEntranceRefreshNotification"

#import "TYOTADeviceUpgradeListModel.h"

@class TuyaSmartDeviceModel;

typedef void (^TYSpaceUpgradeDeviceCheckSuccess)(NSArray <TYOTADeviceUpgradeListModel *> *upgradeDevices);
typedef void (^TYFailureError)(NSError *error);

@protocol TYOTAGeneralProtocol <NSObject>
/**
 检查设备是否支持固件升级
 
 @param deviceModel 需要检查固件升级的设备
 YES: 支持
 NO: 不支持
 */
- (BOOL)isSupportUpgrade:(TuyaSmartDeviceModel *)deviceModel;

/// 检测当前家庭是否有可升级的设备（非空间管理员 hasUpgrade 直接返回 NO）
- (void)checkCurrentFamilyUpgradeDeviceSuccess:(void (^)(BOOL checkFinished, BOOL hasUpgrade))success failure:(void (^)(NSError * error))failure;

/**
 *  获取固件升级状态，无升级、有固件升级、正在升级中
 *
 *  @param deviceModel 需要检查固件升级的设备
 *  @param success Success block
 *  @param failure Failure block
 */
- (void)upgradeStatusWithDeviceModel:(TuyaSmartDeviceModel *)deviceModel
                             success:(void(^)(TYDeviceUpgradeStatus status))success
                             failure:(TYFailureError)failure;

/// 开始升级检测，如果需要升级则弹窗提示
/// @param devId 设备 id
- (void)startUpgradeCheckWithDevId:(NSString *)devId;

/// 检测空间内需升级的设备
/// @param spaceId 空间 id
/// @param success 检测成功
/// @param failure 检测失败
- (void)checkSpaceUpgradeDevicesWithSpaceId:(long long)spaceId
                                    success:(TYSpaceUpgradeDeviceCheckSuccess)success
                                    failure:(TYFailureError)failure;

/// 进入设备升级页
/// @param devId 设备 id
- (void)gotoDeviceUpgradeControllerWithDevId:(NSString *)devId;

/// 进入设备升级页，可配置暗黑UI主题
/// @param devId 设备 id
/// @param theme UI主题
- (void)gotoDeviceUpgradeControllerWithDevId:(NSString *)devId theme:(TYOTAControllerTheme)theme;

/// 刷新OTA页面
/// @param deviceModel 设备
/// @param theme UI主题
- (void)refreshOTAViewController:(TuyaSmartDeviceModel *)deviceModel theme:(TYOTAControllerTheme)theme;

#pragma mark - DEPRECATED
/**
 检查设备固件更新，如果有更新会显示展示出固件更新提示
 
 @param deviceModel 需要检查固件升级的设备
 @param isManual 是否手动检测升级
 @param theme 主题色
 YES: 手动检测升级，检测时弹出loading框。当有固件新版本时(检测升级、强制升级、提醒升级)，显示OTA VC。
 NO: 自动检测升级, 检测时不弹出loading框。当有强制升级时、提醒升级时，弹出固件升级提示，点确定后显示OTA VC。
 */
- (void)checkFirmwareUpgrade:(TuyaSmartDeviceModel *)deviceModel isManual:(BOOL)isManual theme:(TYOTAControllerTheme)theme DEPRECATED_MSG_ATTRIBUTE("use [startUpgradeCheckWithDevId:] or [gotoDeviceUpgradeControllerWithDevId:] instead");

/**
 检查设备固件更新，如果有更新会显示展示出固件更新提示
 
 @param deviceModel 需要检查固件升级的设备
 @param isManual 是否手动检测升级
 @param theme 主题色
 @param viewController 不强引用，在该 viewController 展示升级弹窗，在所属导航栈推入 OTA VC。传 nil，自动寻找顶部 VC，会展示在用户的 modal 弹窗上面
 YES: 手动检测升级，检测时弹出loading框。当有固件新版本时(检测升级、强制升级、提醒升级)，显示OTA VC。
 NO: 自动检测升级, 检测时不弹出loading框。当有强制升级时、提醒升级时，弹出固件升级提示，点确定后显示OTA VC。
 */
- (void)checkFirmwareUpgrade:(TuyaSmartDeviceModel *)deviceModel isManual:(BOOL)isManual theme:(TYOTAControllerTheme)theme viewController:(UIViewController *)viewController DEPRECATED_MSG_ATTRIBUTE("use [startUpgradeCheckWithDevId:] or [gotoDeviceUpgradeControllerWithDevId:] instead");

@end

#endif /* TYOTAGeneralPlugAPI_h */
