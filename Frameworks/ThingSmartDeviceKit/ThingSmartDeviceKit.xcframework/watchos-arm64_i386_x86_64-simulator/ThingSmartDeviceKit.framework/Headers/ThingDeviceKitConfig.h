//
//  ThingDeviceKitConfig.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceKitConfig : NSObject

+ (instancetype)sharedInstance;

@property (atomic, copy) void(^requestBLEPermissionAction)(NSString* source, ThingSuccessHandler __nullable success, ThingFailureHandler __nullable failure);
- (void)requestBLEPermissionWithSource:(NSString*)source Success:(ThingSuccessHandler __nullable)success failure:(ThingFailureHandler __nullable)failure;

@end

NS_ASSUME_NONNULL_END
