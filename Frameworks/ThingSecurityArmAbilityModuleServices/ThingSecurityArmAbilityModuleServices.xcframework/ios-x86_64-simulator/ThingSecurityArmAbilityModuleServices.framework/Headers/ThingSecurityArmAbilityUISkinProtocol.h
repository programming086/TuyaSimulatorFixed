
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingSecurityArmMode);

@protocol ThingSecurityArmAbilityUISkinProtocol <NSObject>


- (void)gotoSecurityArmRuleSettingViewController:(ThingSecurityArmMode)mode;


- (void)gotoSecurityDelaySettingViewController:(ThingSecurityArmMode)mode notAllowSetResponse:(void(^)(void))handler;


- (void)showSecurityBypassAlertView:(ThingSecurityArmMode)tempMode
                            devices:(NSArray<NSString *> *)devices
               confirmToArmCallBack:(void(^)(void))confirmToArm
                cancelToArmCallBack:(void(^)(void))cancelToArm;


- (void)gotoSecurityBypassViewController:(ThingSecurityArmMode)tempMode
                                 devices:(NSArray<NSString *> *)devices
                    confirmToArmCallBack:(void(^)(void))confirmToArm
                     cancelToArmCallBack:(void(^)(void))cancelToArm __deprecated_msg("This method is deprecated, Use -showSecurityBypassAlertView:devices:confirmToArmCallBack:cancelToArmCallBack: instead");

- (void)gotoSecurityModeSettingViewController;


- (void)gotoSecurityIgnoreDeviceViewControllerWithBypassDatas:(NSArray *)datas;

- (UIImage *)querySecurityArmModeConfigImageByArmMode:(ThingSecurityArmMode)armMode;


- (UIImage *)querySecurityArmModeImageByArmMode:(ThingSecurityArmMode)armMode isSelected:(BOOL)isSelected;

@end

NS_ASSUME_NONNULL_END
