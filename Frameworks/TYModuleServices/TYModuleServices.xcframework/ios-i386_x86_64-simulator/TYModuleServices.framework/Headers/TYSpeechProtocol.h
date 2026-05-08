//
//  TYSpeechProtocol.h
//  TYModuleServices
//
//  Created by Lucca on 2019/3/30.
//

#import <Foundation/Foundation.h>

@protocol TYSpeechProtocol <NSObject>

/**
 跳转到语音下发命令控制器
 跳转前会校验是否开启麦克风权限以及登录状态
 使用语音需要配置goolekey、讯飞sdk及sdk， 
 */
- (void)showSpeechController;

/**
 当前登录账号配置，是否满足语音识别入口展示条件
 */
- (BOOL)shouldShowSpeechEntrance;

@end


