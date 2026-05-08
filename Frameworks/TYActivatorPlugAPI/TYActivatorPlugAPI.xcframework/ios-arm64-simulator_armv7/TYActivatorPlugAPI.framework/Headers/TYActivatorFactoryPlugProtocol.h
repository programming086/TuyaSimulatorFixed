//
//  TYActivatorFactoryPlugProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/9.
//

#import <Foundation/Foundation.h>
#import "TYActivatorFactoryProtocol.h"
#import "TYActivatorStepProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TYActivatorFactoryDataSourcePlugProtocol <NSObject>

/// 基于factory提供的标准step定制，支持增删改
- (void)factory:(id<TYActivatorFactoryProtocol>)factory customStepsWithStandardSteps:(NSMutableDictionary <NSString *, TYActivatorInitStepBlock>*)stepsMap;

/// 自定义step切换
- (NSString *)factory:(id<TYActivatorFactoryProtocol>)factory targetStepForProposedStep:(NSString *)nextStepId fromOriginStep:(NSString *)originStepId;
@end

@protocol TYActivatorFactoryDelegatePlugProtocol <NSObject>

//配网流程退出
- (void)factory:(id<TYActivatorFactoryProtocol>)factory quitProcessInStep:(id<TYActivatorStepProtocol>)currentStep;

//配网流程成功
- (void)factory:(id<TYActivatorFactoryProtocol>)factory successProcessInStep:(id<TYActivatorStepProtocol>)currentStep;

//配网流程step切换,进入step
- (void)factory:(id<TYActivatorFactoryProtocol>)factory willEnterStep:(id<TYActivatorStepProtocol>)step;

//配网流程step切换,离开step
- (void)factory:(id<TYActivatorFactoryProtocol>)factory didEndStep:(id<TYActivatorStepProtocol>)step;
@end

NS_ASSUME_NONNULL_END
