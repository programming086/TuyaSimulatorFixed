//
//  TYActivatorResultEndStepProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TYActivatorResultEndStepProtocol <NSObject>
@property (nonatomic, weak, nullable) UIViewController *popToVc; //退出配网流程pop到指定VC, 默认回到首页
@end

NS_ASSUME_NONNULL_END
