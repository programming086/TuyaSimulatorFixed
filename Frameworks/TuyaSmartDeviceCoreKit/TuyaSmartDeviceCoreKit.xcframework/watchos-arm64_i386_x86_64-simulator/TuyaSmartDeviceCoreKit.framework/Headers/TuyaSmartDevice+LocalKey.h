//
//  TuyaSmartDevice+LocalKey.h
//  TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartDevice.h"

NS_ASSUME_NONNULL_BEGIN

#define LocalKeySupportKey @"supportLocalKeyChange"

@interface TuyaSmartDevice (LocalKey)

/// Update device local key.
- (void)updateLocalKeySuccess:(nullable TYSuccessHandler)success
                      failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
