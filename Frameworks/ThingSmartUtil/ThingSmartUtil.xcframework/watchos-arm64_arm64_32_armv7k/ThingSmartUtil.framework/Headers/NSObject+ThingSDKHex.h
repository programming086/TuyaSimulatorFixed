//
//  NSObject+ThingSDKHex.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface NSString (ThingSDKHex)

+ (instancetype)thingsdk_stringFromHexString:(NSString *)hexString;

- (NSString *)thingsdk_hexString;

/// Big or Small Data Transform，like this 510a3b -> 3b0a51
- (NSString *)thingsdk_dataTransformBigSmall;

@end

@interface NSData (ThingSDKHex)

+ (instancetype)thingsdk_dataFromHexString:(NSString *)hexString;

- (NSString *)thingsdk_hexString;


@end
