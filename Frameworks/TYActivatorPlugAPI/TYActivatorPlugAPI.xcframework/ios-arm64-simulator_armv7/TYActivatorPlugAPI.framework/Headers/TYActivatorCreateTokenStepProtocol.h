//
//  TYActivatorCreateTokenStepProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TYActivatorCreateTokenStepProtocol <NSObject>
@property (nonatomic, copy, nullable) NSString *productKey; // 创建token使用的pid
@end

NS_ASSUME_NONNULL_END
