//
//  TYSecurityConfigArmViewProcotol.h
//  TYSecurityArmAbilityUISkin
//
//  Created by Tuya.Inc on 2021/4/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TYSecurityArmMode);
typedef NS_ENUM(NSUInteger, TYSecurityLocationLineState);

@protocol TYSecurityConfigArmViewProcotol <NSObject>

@required

/// 开始布防倒计时
/// @param currentDelayTime 当前倒计时
/// @param maxDelayTime 倒计时总时间
- (void)startArmCountDown:(NSInteger)currentDelayTime maxDelayTime:(NSInteger)maxDelayTime;

/// 开始报警倒计时
/// @param countDownTime 倒计时
/// @param maxTime 报警倒计时总时间
- (void)locationAlarmed:(NSInteger)countDownTime maxTime:(NSInteger)maxTime;

///收到忽略异常设备
- (void)didReceiveBypassDevices:(NSArray *)datas;

/// 更新布撤防模式
/// @param mode 当前模式
- (void)updateArmMode:(TYSecurityArmMode)mode;

@optional;


/// 网关倒计时结束之后移除进度条
- (void)celarPreventViewProgressLayer;

/// 停止倒计时动画
- (void)stopAlarmAnimation;

/// 更新报警倒计时动画
- (void)updateAlarmAnimation;

/// 配置布防网关设备状态文案描述
- (void)configGetewayDeviceStatusDesc:(TYSecurityLocationLineState)state;

/// 移除添加网关提示语
- (void)removeAddGatewayTips;

/// 离线
- (void)locationOffline;

/// (报警倒计时过程中，不允许切换布防，为了解耦，所以这里把显示加载框的逻辑放到View层，ViewMode通过改协议调用显示加载框)
- (void)showLoading;

///移除加载框
- (void)dismissLoading;

/// 更新天气信息
- (void)updateWeatherInfo:(NSDictionary *)dict;
    

@end

NS_ASSUME_NONNULL_END
