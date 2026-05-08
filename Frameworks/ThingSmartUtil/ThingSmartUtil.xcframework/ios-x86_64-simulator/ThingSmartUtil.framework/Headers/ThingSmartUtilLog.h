//
//  ThingSmartUtilLog.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

void ThingSDKLog(NSInteger level, NSString *module, const char *file, const char *function, NSUInteger line, NSString *format, ...);

#undef ThingLog
#undef ThingSDKLogDebug
#undef ThingSDKLogInfo
#undef ThingSDKLogWarn
#undef ThingSDKLogError

#define ThingLog(...) \
    ThingSDKLog(1, @"ThingSmartKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define ThingSDKLogDebug(...) \
    ThingSDKLog(0, @"ThingSmartKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define ThingSDKLogInfo(...) \
    ThingSDKLog(1, @"ThingSmartKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define ThingSDKLogWarn(...) \
    ThingSDKLog(2, @"ThingSmartKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define ThingSDKLogError(...) \
    ThingSDKLog(3, @"ThingSmartKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

@interface ThingSmartUtilLog : NSObject

+ (ThingSmartUtilLog *)sharedInstance;
/// Debug mode, default is false. Verbose log will print into console if opened.
@property (nonatomic, assign) BOOL debugMode;
/// default is false.
@property (nonatomic, assign) BOOL logToThingLogLibrary;

@end

NS_ASSUME_NONNULL_END
