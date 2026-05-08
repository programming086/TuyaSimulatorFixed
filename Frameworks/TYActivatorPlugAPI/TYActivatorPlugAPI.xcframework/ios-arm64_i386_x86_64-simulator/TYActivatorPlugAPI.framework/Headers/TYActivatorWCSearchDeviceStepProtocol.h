//
//  TYActivatorWCSearchDeviceStepProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TYActivatorWCSearchDeviceStepProtocol <NSObject>
@property (nonatomic, assign) NSTimeInterval timeout;
@property (nonatomic, strong) NSArray *cycleTitles;
@end

NS_ASSUME_NONNULL_END
