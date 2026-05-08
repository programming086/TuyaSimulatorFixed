//
//  ThingSDKNotification.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

@interface ThingSDKNotification : NSObject

+ (void)thingsdk_postNotificationName:(nonnull NSString *)aName;

+ (void)thingsdk_postNotificationName:(nonnull NSString *)aName object:(nullable id)anObject;

+ (void)thingsdk_postNotificationName:(nonnull NSString *)aName object:(nullable id)anObject userInfo:(nullable NSDictionary *)aUserInfo;


@end
