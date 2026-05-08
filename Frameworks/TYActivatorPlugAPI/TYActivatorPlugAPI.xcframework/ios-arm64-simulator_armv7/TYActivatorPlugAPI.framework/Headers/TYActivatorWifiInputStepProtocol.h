//
//  TYActivatorWifiInputStepProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TYActivatorWifiInputStepProtocol <NSObject>
@property (nonatomic, assign) NSUInteger maxPasswordLength;
@property (nonatomic, assign) NSUInteger ssidLimitLength;
@property (nonatomic, assign) NSUInteger passwordLimitLength;
@end

NS_ASSUME_NONNULL_END
