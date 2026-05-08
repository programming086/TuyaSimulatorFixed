//
//  TYActivatorVirtualDeviceBindRequestData.h
//  TYActivatorModule
//
//  Created by qisong on 2022/3/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYActivatorVirtualDeviceBindRequestData : NSObject
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *productId;
@property (nonatomic, assign) long long gid;//空间ID, getData
@end

NS_ASSUME_NONNULL_END
