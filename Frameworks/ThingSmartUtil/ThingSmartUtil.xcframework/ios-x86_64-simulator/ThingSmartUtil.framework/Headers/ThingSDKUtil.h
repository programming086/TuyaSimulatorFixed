//
//  ThingSDKUtil.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

void thingsdk_dispatch_async_on_default_global_thread(dispatch_block_t block);
void thingsdk_dispatch_async_on_main_thread(dispatch_block_t block);
void thingsdk_dispatch_sync_on_main_thread(dispatch_block_t block);


extern void __thing_defer__(__strong void (^*operation)(void));

#ifndef thingDefer
#define __thing_defer_var_v__(X, Y) X##Y
#define __thing_defer_var_m__(X, Y) __thing_defer_var_v__(X, Y)
#define thingDefer \
        __strong void(^ __thing_defer_var_m__(_thing_defer_var , __COUNTER__ ))(void) __attribute__((cleanup(__thing_defer__), unused)) = ^
#endif


@interface ThingSDKUtil : NSObject

#if TARGET_OS_IOS

+ (NSString *)thingsdk_currentWifiSSID;

+ (NSString *)thingsdk_currentWifiBSSID;

+ (NSString *)MCCAndMNC;

#endif

+ (BOOL)isDomesticApp:(NSString *)appKey;

+ (BOOL)isThingApp:(NSString *)appKey;

+ (BOOL)isSmartLife:(NSString *)appKey;

+ (uint32_t)thingsdk_getIntValueByHex:(NSString *)str;

+ (NSString *)thingsdk_getISOcountryCode;

+ (BOOL)thingsdk_compareVesionWithDeviceVersion:(NSString *)deviceVersion appVersion:(NSString *)appVersion;

+ (NSData *)thingsdk_xorEncodeData:(NSData *)sourceData keyData:(NSData *)keyData;

@end


extern NSString * const ThingUtilHostAppExtensionString;
extern NSString * const ThingUtilTodayWidgetExtensionString;
extern NSString * const ThingUtilIntentExtensionString;
extern NSString * const ThingUtilIntentUIExtensionString;
extern NSString * const ThingUtilWatchKitExtensionString;

/**
 Recursively removes `NSNull` values from a JSON object.
*/
FOUNDATION_EXPORT id ThingJSONObjectByRemovingKeysWithNullValues(id JSONObject, NSJSONReadingOptions readingOptions);

/**
 *  @category ThingUtil(AppExtension)
 *  Checks the process in which the program runs (App/AppExtension/WatchKitExtension).
 */
@interface ThingSDKUtil (AppSDKExtension)

+ (NSString *)thingsdk_currentExtensionString;

+ (BOOL)thingsdk_isHostApp;

+ (BOOL)thingsdk_isAppExtension;

+ (BOOL)thingsdk_isWatchKitExtension;

@end
