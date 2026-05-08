//
// TuyaSmartUser+Anonymous.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import "TuyaSmartUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartUser (Highway)

/// Get highway gateway access token
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)requestHighwayTokenWithSuccess:(TYSuccessID)success
                               failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
