//
//  TYActivatorBTSearchDeviceStepProtocol.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TYActivatorBTSearchDeviceStepProtocol <NSObject>
@property (nonatomic, assign) NSTimeInterval timeout;//超时，默认120秒
@property (nonatomic, assign) NSTimeInterval preTimeout;//预超时，默认10秒
@property (nonatomic, strong) NSArray *cycleTitles;
@end

NS_ASSUME_NONNULL_END
