//
//  NSBundle+ThingSDKLanguage.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

#define ThingSDKLocalizedString(key, comment) \
    [NSBundle thingsdk_localizedStringForKey:(key) value:@"" table:nil]

@interface NSBundle (ThingSDKLanguage)

+ (NSBundle *)thingsdk_bundle;

+ (NSString *)thingsdk_getAppleLanguages;

+ (NSString *)thingsdk_localizedStringForKey:(NSString *)key value:(NSString *)value table:(NSString *)tableName;

@end
