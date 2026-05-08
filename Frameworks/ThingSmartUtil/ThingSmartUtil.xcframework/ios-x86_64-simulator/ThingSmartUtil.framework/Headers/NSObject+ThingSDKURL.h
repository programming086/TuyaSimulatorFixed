//
//  NSObject+ThingSDKURL.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface NSString (ThingSDKURL)

- (NSString *)thingsdk_urlEncodeString;

- (NSString *)thingsdk_urlDecodeString;

@end

@interface NSURL (ThingSDKQuery)

- (NSDictionary *)thingsdk_queryDict;

@end
