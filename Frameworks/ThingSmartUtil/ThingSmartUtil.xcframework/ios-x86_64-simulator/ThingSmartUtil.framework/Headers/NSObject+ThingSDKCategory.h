//
//  NSObject+ThingSDKCategory.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface NSObject (ThingSDKCategory)

/// String or Number to Int.
/// e.g. @"1A" -> 1, @"-10xc" -> -10, @(10) or @"10" -> 10
- (NSInteger)thingsdk_toInt;

/// String or Number to UInt.
/// e.g. @"1A" -> 1, @"-10xc" -> NSUIntegerMax, @(10) or @"10" -> 10
- (NSUInteger)thingsdk_toUInt;

/// Hex string or data to UInt.
/// e.g. @"0x0010" -> 16, @(10) -> 16, NSData bytes 0x0010 -> 16
- (NSUInteger)thingsdk_hexToUInt;

- (NSString *)thingsdk_toString;

- (float)thingsdk_toFloat;

- (double)thingsdk_toDouble;

- (NSArray *)thingsdk_toArray;

- (NSDictionary *)thingsdk_toDictionary;

- (BOOL)thingsdk_toBool;

+ (BOOL)thingsdk_swizzleInstanceMethod:(SEL)originalSel with:(SEL)newSel;

+ (BOOL)thingsdk_swizzleClassMethod:(SEL)originalSel with:(SEL)newSel;

@end
