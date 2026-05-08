
#import <Foundation/Foundation.h>
#import "ThingActivatorFactoryContextProtocol.h"
#import "ThingActivatorDefineStepHeader.h"
#import "ThingActivatorFactoryConfig.h"
#import "ThingActivatorLinkModeDefine.h"
#import "ThingActivatorFactorySwitchIntent.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingActivatorStepProtocol, ThingActivatorFactoryProtocol;
@class ThingSmartDeviceCategoryModel;

typedef id<ThingActivatorStepProtocol>_Nonnull(^ThingActivatorInitStepBlock)(id<ThingActivatorFactoryProtocol>factory, NSString *stepId);

@protocol ThingActivatorFactoryProtocol <NSObject>
/*
 * Factory context
 */
@property (nonatomic, weak) id<ThingActivatorFactoryContextProtocol> factoryContext;

/*
 * Custom data
 */
@property (nonatomic, strong) NSMutableDictionary *userInfo;

/*
 * Necessary parameters for network configuration
 */
@property (nonatomic, strong) ThingActivatorFactoryConfig *config;

/*
 * Start step ID for network configuration
 */
@property (nonatomic, copy) NSString *startStepId;

/*
 * Current network configuration type
 */
@property (nonatomic, assign) ThingLinkMode currentLinkMode;

/*
 * Network category detail data, from the cloud
 */
@property (nonatomic, strong) ThingSmartDeviceCategoryModel *categoryModel;

/*
 * Previous step
 */
@property (nonatomic, strong) id<ThingActivatorStepProtocol> previousStep;

/*
 * Current step
 */
@property (nonatomic, strong) id<ThingActivatorStepProtocol> currentStep;

/*
 * Record current VC, need to call pushStepVc:
 */
@property (nonatomic, weak) UIViewController *currentVc;

/*
 * Record the VC before entering network configuration
 */
@property (nonatomic, weak) UIViewController *rootVc;

/*
 * Navigation stack
 */
@property (nonatomic, weak) UINavigationController *navigation;

@required
/// Initialize factory
- (instancetype)initWithContext:(id<ThingActivatorFactoryContextProtocol>)context linkMode:(ThingLinkMode)linkMode;

/// Switch steps
/// @param intent Switching purpose
- (void)switchStep:(ThingActivatorFactorySwitchIntent *)intent;

@optional
/// Switch link mode within the same category
/// @param linkMode Target link mode
/// @param intent Switching purpose
/// @discussion Switch network configuration method within the current third-level category to start the network configuration process with a specific step
- (void)switchFactoryWithLinkMode:(ThingLinkMode)linkMode toStep:(ThingActivatorFactorySwitchIntent *)intent;

/// Switch category
/// @param categoryModel Target third-level category
/// @discussion Switch to another third-level category to start the network configuration process with the first link mode under the third-level category
- (void)switchCategory:(ThingSmartDeviceCategoryModel *)categoryModel;

/// Exit network configuration process
- (void)quitProcess;

/// Network configuration process succeeded
- (void)successProcess;

/// Switch to the view corresponding to the step
- (void)pushStepView:(UIView *)stepView animated:(BOOL)animated;

/// Switch to the VC corresponding to the step
- (void)pushStepVc:(UIViewController *)stepVc animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
