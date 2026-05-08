//
//  TYDeviceKitConfig.h
//  TuyaSmartDeviceKit
//
//  Created by JiaNa on 2021/10/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYDeviceKitConfig : NSObject

TYSDK_SINGLETON;

@property (atomic, copy) void(^requestBLEPermissionAction)(NSString* source, TYSuccessHandler __nullable success, TYFailureHandler __nullable failure);
- (void)requestBLEPermissionWithSource:(NSString*)source Success:(TYSuccessHandler __nullable)success failure:(TYFailureHandler __nullable)failure;

@end

NS_ASSUME_NONNULL_END
