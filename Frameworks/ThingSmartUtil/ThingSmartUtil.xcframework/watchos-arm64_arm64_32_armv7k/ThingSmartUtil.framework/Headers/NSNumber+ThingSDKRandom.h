//
//  NSNumber+ThingSDKRandom.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface NSNumber (ThingSDKRandom)

+ (NSInteger)thingsdk_randomIntBetweenMin:(NSInteger)minValue andMax:(NSInteger)maxValue;

+ (float)thingsdk_randomFloat;

+ (float)thingsdk_randomFloatBetweenMin:(float)minValue andMax:(float)maxValue;

@end
