//
//  NSObject+ThingSDKJSON.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface NSString (ThingSDKJSON)
- (id)thingsdk_objectFromJSONString;
- (id)thingsdk_objectFromJSONString:(NSJSONReadingOptions)serializeOptions error:(NSError **)error;
@end

@interface NSArray (ThingSDKJSON)
- (NSString *)thingsdk_JSONString;
- (NSString *)thingsdk_JSONStringWithOptions:(NSJSONWritingOptions)serializeOptions error:(NSError **)error;
@end

@interface NSDictionary (ThingSDKJSON)
- (NSString *)thingsdk_JSONString;
- (NSString *)thingsdk_JSONStringWithOptions:(NSJSONWritingOptions)serializeOptions error:(NSError **)error;
@end
