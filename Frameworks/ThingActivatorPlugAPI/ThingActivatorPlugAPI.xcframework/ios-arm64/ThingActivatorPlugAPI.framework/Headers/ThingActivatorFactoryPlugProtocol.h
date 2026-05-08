
#import <Foundation/Foundation.h>
#import "ThingActivatorFactoryProtocol.h"
#import "ThingActivatorStepProtocol.h"

NS_ASSUME_NONNULL_BEGIN
/*
 * This protocol is implemented by the business side
 */

@protocol ThingActivatorFactoryDataSourcePlugProtocol <NSObject>
@optional

/// Customization based on the standard steps provided by the factory, supporting addition, deletion, and modification
- (void)factory:(id<ThingActivatorFactoryProtocol>)factory customStepsWithStandardSteps:(NSMutableDictionary <NSString *, ThingActivatorInitStepBlock>*)stepsMap;

/// Custom step switching
- (NSString *)factory:(id<ThingActivatorFactoryProtocol>)factory targetStepForProposedStep:(NSString *)nextStepId fromOriginStep:(NSString *)originStepId;
@end

@protocol ThingActivatorFactoryDelegatePlugProtocol <NSObject>
@optional
//Network configuration process exit
- (void)factory:(id<ThingActivatorFactoryProtocol>)factory quitProcessInStep:(id<ThingActivatorStepProtocol>)currentStep;

//Network configuration process succeeded
- (void)factory:(id<ThingActivatorFactoryProtocol>)factory successProcessInStep:(id<ThingActivatorStepProtocol>)currentStep;

//Network configuration process step switch, entering step
- (void)factory:(id<ThingActivatorFactoryProtocol>)factory willEnterStep:(id<ThingActivatorStepProtocol>)step;

//Network configuration process step switch, leaving step
- (void)factory:(id<ThingActivatorFactoryProtocol>)factory didEndStep:(id<ThingActivatorStepProtocol>)step;
@end

NS_ASSUME_NONNULL_END
