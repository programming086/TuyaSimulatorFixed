
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingSecurityArmMode);
typedef NS_ENUM(NSUInteger, ThingSecurityLocationLineState);

@protocol ThingSecurityConfigArmViewProcotol <NSObject>

@required


- (void)startArmCountDown:(NSInteger)currentDelayTime maxDelayTime:(NSInteger)maxDelayTime;


- (void)locationAlarmed:(NSInteger)countDownTime maxTime:(NSInteger)maxTime;

- (void)didReceiveBypassDevices:(NSArray *)datas;


- (void)updateArmMode:(ThingSecurityArmMode)mode;

@optional;


- (void)celarPreventViewProgressLayer;


- (void)stopAlarmAnimation;


- (void)updateAlarmAnimation;


- (void)configGetewayDeviceStatusDesc:(ThingSecurityLocationLineState)state;


- (void)removeAddGatewayTips;


- (void)locationOffline;

- (void)showLoading;


- (void)dismissLoading;


- (void)updateWeatherInfo:(NSDictionary *)dict;
    

@end

NS_ASSUME_NONNULL_END
