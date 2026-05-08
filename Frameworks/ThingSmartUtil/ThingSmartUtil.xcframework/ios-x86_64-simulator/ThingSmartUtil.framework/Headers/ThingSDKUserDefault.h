//
//  ThingSDKUserDefault.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSDKUserDefault : NSObject

+ (void)thingsdk_setUserDefault:(id)object forKey:(NSString *)aKey;
+ (id)thingsdk_getUserDefault:(NSString *)aKey;
+ (void)thingsdk_removeUserDefault:(NSString *)aKey;

+ (void)thingsdk_setDouble:(double)value forKey:(NSString *)aKey;
+ (double)thingsdk_getDoubleForKey:(NSString *)aKey;

@end

NS_ASSUME_NONNULL_END
