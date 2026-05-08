//
//  TYSecurityArmAbilityProtocol.h
//  Pods
//
//  Created by Tuya.Inc on 2021/4/13.
//

#import <Foundation/Foundation.h>
#import <TYSecurityArmAbilityModuleServices/TYSecurityArmDelayTimeModel.h>
#import <TYSecurityArmAbilityModuleServices/TYSecuritSaveModeDeviceRuleModel.h>
#import <TYSecurityArmAbilityModuleServices/TYSecurityArmAbilityDelegate.h>
#import <TYSecurityArmAbilityModuleServices/TYSecurityHomeArmDevicesModel.h>
#import <TYSecurityArmAbilityModuleServices/TYSecurityArmAbilityEnum.h>
#import <TYSecurityArmAbilityModuleServices/TuyaSecurityHomeBaseStateModel.h>
#import <TYSecurityArmAbilityModuleServices/TuyaSecurityAbnormalDeviceModel.h>
#import <TYSecurityArmAbilityModuleServices/TuyaSecurityAlarmMessageModel.h>
#import <TYSecurityArmAbilityModuleServices/TuyaSecurityModeSettingDeviceModel.h>
#import <TYSecurityArmAbilityModuleServices/TuyaSecurityAlarmDetailModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TYSecurityArmMode);
typedef NS_ENUM(NSInteger, TYSecurityHomeInitType);

typedef void(^TYSecurityGetArmModeHandler)(TYSecurityArmMode mode,NSError * _Nullable error);

@protocol TYSecurityArmAbilityProtocol <NSObject>

#pragma mark - 初始化
/// 安防打标(其他业务线使用安防布撤防能力时，需要调用该接口)
/// @param securityType 业务类型
- (void)securityHomeInitialize:(TYSecurityHomeInitType)securityType;

#pragma mark - 布撤防
/// 注册代理
///
/// @param delegate 代理
- (void)registerSecurityModeDelegate:(id<TYSecurityArmAbilityDelegate>)delegate;

/// 销毁代理
- (void)unregisterDelegate:(id<TYSecurityArmAbilityDelegate>)delegate;

/// 更新安防网关白名单(添加设备、移除设备时需要调用)
- (void)updateSecurityWhiteGatewayList;

/// 家庭下是否有支持布撤防的设备 (校验某个模式下是否有选中的网关，如果没有则不允许切换安防模式)
/// @param mode 布撤防模式
/// @param success 成功回调
/// @param failure 失败回调
- (void)hasArmAbilityWith:(TYSecurityArmMode)mode
                  success:(void(^)(NSArray<NSString *> *result))success
                  failure:(void(^)(NSError *error))failure;

/// 获取家庭当前布防模式(接口获取，从block回调)
/// @param handler 回调
- (void)getLocationCurrentMode:(TYSecurityGetArmModeHandler)handler;

/// 获取家庭当前布防模式(接口获取，从delegate回调)
- (void)getHomeArmMode;

/// 获取当前布撤防模式(缓存)
- (TYSecurityArmMode)getCurretnModeFromCache;

///获取家庭初始化信息(当前布撤防模式、是否离线、是否正在报警、是否处于布防倒计时中、是否处于布防倒计时中)
///
/// @param success callback for successful request.
/// @param failure callback for failed request.
- (void)getHomeStateSuccess:(void(^)(TuyaSecurityHomeBaseStateModel *result))success
                    failure:(void(^)(NSError *error))failure;

/// 切换布撤防
///
/// @param mode 模式
- (void)updateArmedStateWithMode:(TYSecurityArmMode)mode;

/// 获取忽略设备(布防前要检测布防模式下是否有设备异常)
///
/// @param mode target mode
/// @param success 成功回调
/// @param failure 失败回调
- (void)getIrregularDevice:(TYSecurityArmMode)mode
                   success:(void(^)(NSArray<NSString *> *devices))success
                   failure:(void(^)(NSError *error))failure;

/// 获取已经忽略的设备(忽略设备 + dp异常设备)
///
/// @param success 成功回调
/// @param failure 失败回调
- (void)getAbnormalDevicesWithSuccess:(void(^)(NSArray<TuyaSecurityAbnormalDeviceModel *>*result))success
                              failure:(void(^)(NSError *error))failure;

/// 更新安防异常设备信息(安防首页banner，设备dp点变化时需要调用。无异常信息展示需求时 可以忽略)
- (void)updateSecurityProductDpDescription;

/// 获取当前家庭下在家、离家防区是否有勾选设备
/// @param success 成功回调
/// @param failure 失败回调
- (void)getHomeArmDeviceSuccess:(void(^)(TYSecurityHomeArmDevicesModel *result))success
                          failure:(void(^)(NSError *error))failure;

/// 获取布撤防联动规则列表
/// @param mode 模式
/// @param success 成功回调
/// @param failure 失败回调
- (void)getDevicesInRuleByMode:(TYSecurityArmMode)mode
                       success:(void (^)(TuyaSecurityModeSettingDeviceModel *model))success
                       failure:(void (^)(NSError *error))failure;

/// 保存布撤防联动规则
/// @param mode 模式
/// @param datas 联动数据
/// @param success 成功回调
/// @param failure 失败回调
- (void)saveDeviceListWithMode:(TYSecurityArmMode)mode
                         datas:(NSArray<TYSecuritSaveModeDeviceRuleModel *> *)datas
                       success:(void(^)(BOOL result))success
                       failure:(void(^)(NSError *error))failure;

/// 获取延迟信息
/// @param success 成功回调
/// @param failure 失败回调
- (void)getModeDelayInfo:(void(^)(NSArray<TYSecurityArmDelayTimeModel *> *result))success
                 failure:(void(^)(NSError *error))failure;

/// 保存布防延迟
/// @param mode 布防模式
/// @param delayTime 延迟时间
/// @param success 成功回调
/// @param failure 失败回调
- (void)saveArmedDelayTime:(TYSecurityArmMode)mode
                 delayTime:(NSInteger)delayTime
                   success:(void(^)(BOOL result))success
                   failure:(void(^)(NSError *error))failure;

/// 保存报警延迟
/// @param mode 布防模式
/// @param delayTime 延迟时间
/// @param success 成功回调
/// @param failure 失败回调
- (void)saveAlarmDelayTime:(TYSecurityArmMode)mode
                 delayTime:(NSInteger)delayTime
                   success:(void(^)(BOOL result))success
                   failure:(void(^)(NSError *error))failure;

/// 家庭是否离线(所有网关离线)
- (BOOL)locationOffline;

/// 切换家庭时候调用(无异常信息展示需求时 可以忽略)
- (void)didSwitchSecurityLocation;

#pragma mark - 报警
/// 触发主动报警
/// @param alarmType 主动报警类型
/// @param success 成功回调
/// @param failure 失败回调
- (void)triggerAlarmAlarmType:(TYHSGatewaySOSType)alarmType
                       success:(void(^)(BOOL result))success
                       failure:(void(^)(NSError *error))failure;

/// 获取报警信息
/// @param success 成功回调
/// @param failure 失败回调
- (void)getAlarmInfoWithSuccess:(void(^)(TuyaSecurityAlarmDetailModel *result))success
                        failure:(void(^)(NSError *error))failure;

/// 更新报警状态
/// @param action 状态
/// @param success 成功回调
/// @param failure 失败回调
- (void)updateAlarmActionWithAction:(TYHSGatewayStateUpdateType)action
                            success:(void(^)(BOOL result))success
                            failure:(void(^)(NSError *error))failure;

/// 发送接警中心
/// @param alarmIds 报警ids
/// @param success 成功回调
/// @param failure 失败回调
- (void)sendAlarmToPlatformWithAlarmIds:(NSArray<NSString *> *)alarmIds
                                success:(void(^)(BOOL result))success
                                failure:(void(^)(NSError *error))failure;

/// 开启网关报警声音
- (void)enableAlarmVoice;

/// 关闭网关报警声音
- (void)disableAlarmVoice;

@end

NS_ASSUME_NONNULL_END
