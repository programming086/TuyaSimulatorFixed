
#import <Foundation/Foundation.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityModeType.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityHomeBaseStateModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSecurityHomeStateModel : ThingSecurityHomeBaseStateModel

/// Home current mode
@property (nonatomic, assign) ThingSecurityModeType armedMode;

/// Whether the home is alarming
@property (nonatomic, assign) BOOL isAlarming;

/// Home alarm countdown
@property (nonatomic, assign) long long alarmCountdown;

/// Home online state
@property (nonatomic, assign) NSInteger onlineState;

/// armed mode enter time
@property (nonatomic, assign) long long armedCountdown;


@end

NS_ASSUME_NONNULL_END

