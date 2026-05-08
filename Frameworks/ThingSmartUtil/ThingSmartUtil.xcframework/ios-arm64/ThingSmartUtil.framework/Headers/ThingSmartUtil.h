//
//  ThingSmartUtil.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#ifndef ThingSmartUtil_h
#define ThingSmartUtil_h

#import <Foundation/Foundation.h>

#import "NSDate+ThingSDKOffset.h"
#import "NSError+ThingSDKDomain.h"
#import "NSNumber+ThingSDKRandom.h"
#import "NSObject+ThingSDKHex.h"
#import "NSObject+ThingSDKJSON.h"
#import "NSObject+ThingSDKURL.h"
#import "NSObject+ThingSDKEncrypt.h"
#import "NSObject+ThingSDKCategory.h"
#import "NSBundle+ThingSDKLanguage.h"
#import "NSMutableDictionary+ThingSDKCategory.h"

#import "ThingSDKUtil.h"
#import "ThingSDKConfig.h"
#import "ThingSDKDevice.h"
#import "ThingSDKUserDefault.h"
#import "ThingSDKSafeMutableArray.h"
#import "ThingSDKSafeMutableDictionary.h"
#import "ThingSDKNotification.h"
#import "ThingSDKLogUtils.h"
#import "ThingSDKFile.h"
#import "ThingSDKLocalNetworkManager.h"
#import "ThingSDKOpenSSLHelper.h"
#import "ThingSmartUtilLog.h"
#import "ThingSmartNetworkInfoUtil.h"

#if TARGET_OS_IOS
#import "ThingSmartMbedTLS.h"
#import "ThingSmartReachability.h"
#import "ThingNetworkStatusListener.h"
#import "ThingSmartYuNetModuleProtocol.h"
#endif

#define ThingSDK_SINGLETON \
+ (instancetype)sharedInstance;

#define ThingSDK_DEF_SINGLETON \
+ (instancetype)sharedInstance { \
    static id instance; \
    static dispatch_once_t once; \
    dispatch_once(&once, ^{ \
        instance = [[self alloc] init]; \
    }); \
    return instance; \
}

#define WEAKSELF_ThingSDK __weak __typeof(&*self)weakSelf_ThingSDK = self;

#import "ThingAntiReplayModel.h"
#import "ThingAntiReplayService.h"
#import "ThingSmartModuleProtocol.h"
#import "ThingSmartModuleRouter.h"
#import "ThingSmartWeakProxy.h"
#import "ThingECDHService.h"


typedef void (^ThingSuccessHandler)(void);
typedef void (^ThingSuccessDict)(NSDictionary *dict);
typedef void (^ThingSuccessString)(NSString *result);
typedef void (^ThingSuccessList)(NSArray *list);
typedef void (^ThingSuccessBOOL)(BOOL result);
typedef void (^ThingSuccessID)(id result);
typedef void (^ThingSuccessInt)(int result);
typedef void (^ThingSuccessLongLong)(long long result);
typedef void (^ThingSuccessData)(NSData *data);

typedef void (^ThingFailureHandler)(void);
typedef void (^ThingFailureError)(NSError *error);

#endif /* ThingSmartUtil_h */
