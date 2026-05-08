
#import <Foundation/Foundation.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityArmAbilityEnum.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSecurityLocaitonStateModel : NSObject

@property (nonatomic, assign) BOOL alarmState;
@property (nonatomic, assign) ThingSecurityLocationLineState onlineState;
@property (nonatomic, assign) NSInteger alarmCountdown;


@end

NS_ASSUME_NONNULL_END
