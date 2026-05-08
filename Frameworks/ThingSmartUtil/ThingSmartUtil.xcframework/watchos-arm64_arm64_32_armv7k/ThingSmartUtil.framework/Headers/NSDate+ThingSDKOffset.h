//
//  NSDate+ThingSDKOffset.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface NSDate (ThingSDKOffset)

// Cloud timestamp. Cloud time is synchronized at each startup.
+ (NSTimeInterval)thingsdk_serverTimeIntervalSince1970;

+ (NSString *)thingsdk_timeZone;

@end
