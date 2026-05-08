//
// TuyaSmartHome+Stage.h
// TuyaSmartDeviceKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import "TuyaSmartHome.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartHome (Stage)

- (void)startStage1WithSuccess:(TYSuccessHandler _Nullable)success
                       failure:(TYFailureError _Nullable)failure;

- (void)startStage2WithSuccess:(TYSuccessHandler _Nullable)success
                       failure:(TYFailureError _Nullable)failure;

@end

NS_ASSUME_NONNULL_END
