
#import <Foundation/Foundation.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityHomeStateType.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSecurityHomeBaseStateModel : NSObject

@property (nonatomic, assign) ThingSecurityHomeStateType type;

@property (nonatomic, copy) NSString *stateDescription;


@end

NS_ASSUME_NONNULL_END

