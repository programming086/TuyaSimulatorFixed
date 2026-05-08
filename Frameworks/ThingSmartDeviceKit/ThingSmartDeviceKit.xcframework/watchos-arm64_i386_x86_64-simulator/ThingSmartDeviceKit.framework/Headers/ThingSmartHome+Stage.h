//
//  ThingSmartHome+Stage.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import "ThingSmartHome.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartHome (Stage)
//首页专用接口，首页下拉刷新
- (void)startAllWithSuccess:(ThingSuccessHandler)success
                    failure:(ThingFailureError)failure;

- (void)startStage1WithSuccess:(ThingSuccessHandler _Nullable)success
                       failure:(ThingFailureError _Nullable)failure;

- (void)startStage2WithSuccess:(ThingSuccessHandler _Nullable)success
                       failure:(ThingFailureError _Nullable)failure;

@end

NS_ASSUME_NONNULL_END
