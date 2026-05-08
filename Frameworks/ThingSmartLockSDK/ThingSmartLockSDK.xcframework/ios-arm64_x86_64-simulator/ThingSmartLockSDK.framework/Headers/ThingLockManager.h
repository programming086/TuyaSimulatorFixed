//
//  ThingLockManager.h
//  ThingSmartLockSDK
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingLockManager : NSObject

+ (instancetype)shared;


/// Unlock device
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - success: Success callback
///   - failure: Failure callback
- (void)unLockWithSiteId:(long long)siteId
                deviceId:(NSString *)deviceId
                 success:(ThingSuccessHandler)success
                 failure:(ThingFailureError)failure;


/// Lock device
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - success: Success callback
///   - failure: Failure callback
- (void)lockWithSiteId:(long long)siteId
              deviceId:(NSString *)deviceId
               success:(ThingSuccessHandler)success
               failure:(ThingFailureError)failure;


///  Sets the automatic locking switch for device.
/// - Parameters:
///   - deviceId: Device ID
///   - success: Success callback
///   - failure: Failure callback
- (void)setAutoLockSwitchWithDeviceId:(NSString *)deviceId
                              success:(ThingSuccessHandler)success
                              failure:(ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END
