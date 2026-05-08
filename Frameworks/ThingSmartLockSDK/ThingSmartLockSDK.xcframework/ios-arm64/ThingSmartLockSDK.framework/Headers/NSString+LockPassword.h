//
//  LockPassword.h
//  ThingSmartLockKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (LockPassword)

/// 123456 => 010203040506
@property(nonatomic, readonly) NSString *thing_zeroFormat;

/// 23:59 => 23 * 60 + 59
@property(nonatomic, assign, readonly) NSInteger thing_minutesValue;

/// 是否是合法的账号
@property(nonatomic, assign, readonly) BOOL legitimateAccount;

/// 是否是 work day
@property(nonatomic, assign, readonly) BOOL isWorkday;


@property(nonatomic, assign, readonly) BOOL isStartOrEndTime;

/// 二进制转十六进制 "0011101" => 1b
- (NSString *)thing_binaryToHexString;

/// 二进制反转后转十六进制 "1110100" => 5c
- (NSString *)thing_reverseBinaryToHexString;

/// 23:59 => 173b
- (NSString *)thing_timeToHexString;

- (BOOL)isNumeric;

@end

NS_ASSUME_NONNULL_END
