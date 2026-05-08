
#import <Foundation/Foundation.h>
#import "ThingActivatorLinkModeDefine.h"

NS_ASSUME_NONNULL_BEGIN
@protocol ThingActivatorFactoryProtocol;
@class ThingSmartDeviceCategoryModel,ThingActivatorFactoryConfig,ThingActivatorFactorySwitchIntent;

@protocol ThingActivatorFactoryContextProtocol <NSObject>

@property (nonatomic, strong) ThingSmartDeviceCategoryModel *categoryModel; //third category

@property (nonatomic, strong) ThingActivatorFactoryConfig *config;

@property (nonatomic, weak) UIViewController *rootVc; //Entry page to the pairing process

/// End of pairing process
- (void)exitProcess;

/// Switching from current factory to target LinkMode
- (id<ThingActivatorFactoryProtocol>)switchFromFactory:(id<ThingActivatorFactoryProtocol>)factory toLinkMode:(ThingLinkMode)linkMode intent:(ThingActivatorFactorySwitchIntent *)intent;

/// Switch the three-level category and start the pairing process with the pairing mode corresponding to the first linkmode
- (void)switchToCagetoryModel:(ThingSmartDeviceCategoryModel *)categoryModel;

@end

NS_ASSUME_NONNULL_END
