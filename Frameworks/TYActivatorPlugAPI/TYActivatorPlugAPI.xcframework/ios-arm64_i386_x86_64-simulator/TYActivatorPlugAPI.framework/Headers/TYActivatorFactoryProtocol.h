//
//  TYActivatorFactoryProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/9.
//

#import <Foundation/Foundation.h>
#import "TYActivatorDefineStepHeader.h"
#import "TYActivatorFactoryConfig.h"
#import "TYActivatorLinkModeDefine.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TYActivatorStepProtocol, TYActivatorFactoryProtocol;
@class TuyaSmartDeviceCategoryModel;

typedef id<TYActivatorStepProtocol>_Nonnull(^TYActivatorInitStepBlock)(id<TYActivatorFactoryProtocol>factory, NSString *stepId);

@protocol TYActivatorFactoryProtocol <NSObject>

@property (nonatomic, assign) TYLinkMode currentLinkMode;

@property (nonatomic, strong) NSMutableDictionary *userInfo;

@property (nonatomic, strong) TYActivatorFactoryConfig *config;

@property (nonatomic, strong) TuyaSmartDeviceCategoryModel *categoryModel;

@property (nonatomic, strong) id<TYActivatorStepProtocol> previousStep;

@property (nonatomic, strong) id<TYActivatorStepProtocol> currentStep;

@property (nonatomic, weak) UIViewController *currentVc;

@property (nonatomic, weak) UINavigationController *navigation;

@required
/// 切换步骤
/// @param stepId 步骤id
- (void)switchStep:(NSString *)stepId;

/// 同个品类下切换linkMode
/// @param linkMode 目标linkMode
/// @param stepId 目标步骤ID
/// @discussion 在当前三级品类下切换配网方式，以具体某个步骤开始配网流程
- (void)switchFactoryWithLinkMode:(TYLinkMode)linkMode toStep:(NSString *)stepId;

/// 切换品类
/// @param categoryModel 目标三级品类
/// @discussion 切换到别的三级品类，以三级品类下的第一个linkMode开始配网流程
- (void)switchCategory:(TuyaSmartDeviceCategoryModel *)categoryModel;

/// 退出配网流程
- (void)quitProcess;

/// 配网流程成功
- (void)successProcess;

/// 切换到step对应的view
- (void)pushStepView:(UIView *)stepView animated:(BOOL)animated;

/// 切换到step对应的VC
- (void)pushStepVc:(UIViewController *)stepVc animated:(BOOL)animated;
@end

NS_ASSUME_NONNULL_END
