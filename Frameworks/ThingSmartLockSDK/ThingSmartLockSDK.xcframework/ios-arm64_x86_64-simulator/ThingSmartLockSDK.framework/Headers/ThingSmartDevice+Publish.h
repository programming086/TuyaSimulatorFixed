//
//  ThingSmartDevice+Publish.h
//  ThingSmartLockSDK
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDevice (Publish)

- (void)publishDpsAndReportWithSiteId:(long long)siteId
                                  dps:(NSDictionary *)dps
                              success:(nullable ThingSuccessHandler)success
                              failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
