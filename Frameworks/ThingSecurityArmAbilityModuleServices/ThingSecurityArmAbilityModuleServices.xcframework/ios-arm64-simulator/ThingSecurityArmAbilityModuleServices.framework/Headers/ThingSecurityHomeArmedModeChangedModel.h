
#import <Foundation/Foundation.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityModeType.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSecurityHomeArmedModeChangedModel : NSObject

/// current mode
@property (nonatomic, assign) ThingSecurityModeType mode;

/// switch mode unique identification
@property (nonatomic, strong) NSString *uid;

/// switch mode result state
@property (nonatomic, strong) NSString *stage;

/// arm mode countdown time
@property (nonatomic, assign) long long enterTime;


@end

NS_ASSUME_NONNULL_END

