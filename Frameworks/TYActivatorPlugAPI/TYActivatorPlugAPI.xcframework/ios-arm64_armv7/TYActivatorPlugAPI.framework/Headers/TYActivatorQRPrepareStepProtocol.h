//
//  TYActivatorQRPrepareStepProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^TYActivatorBindTokenDeviceSuccess)(NSString *devId, NSString *uuid);;
@protocol TYActivatorQRPrepareStepProtocol <NSObject>
@property (nonatomic, assign) BOOL notNeedFeedback; // 绑定失败时是否进入超时反馈页
@property (nonatomic, copy, nullable) TYActivatorBindTokenDeviceSuccess bindDeviceSuccess;
@end

NS_ASSUME_NONNULL_END
