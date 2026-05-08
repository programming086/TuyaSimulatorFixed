//
//  TYActivatorStepProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/9.
//

#import <Foundation/Foundation.h>
#import "TYActivatorFactoryProtocol.h"
NS_ASSUME_NONNULL_BEGIN

@protocol TYActivatorStepProtocol <NSObject>

@property (nonatomic, weak) id<TYActivatorFactoryProtocol>factory;

@property (nonatomic, strong) NSString *identifier;

@required
/// 进入当前步骤
/// @param reset 是否来自重置配网流程
- (void)stepIn:(BOOL)reset;

@optional
/// 退出当前步骤
- (void)stepOut;

/// 退出配网流程，给当前step一次拦截退出的机会
/// 不实现默认直接退出
- (void)quitProcessInStep:(void(^)(BOOL canQuit))completion;
@end

NS_ASSUME_NONNULL_END
