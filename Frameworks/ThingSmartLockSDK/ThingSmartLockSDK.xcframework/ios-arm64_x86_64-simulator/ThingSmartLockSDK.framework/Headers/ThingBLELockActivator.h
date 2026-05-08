//
//  ThingBLELockActivator.h
//  ThingSmartLockKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartBLEKit/ThingSmartBLEKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingBLEAdvModel;

@interface ThingBLELockActivator : NSObject

+ (instancetype)shared;


/// Activates the Bluetooth LE lock device.
///
/// @param deviceInfo       The advertisingData model for the Bluetooth LE lock device.
/// @param siteId           The ID for the current site.
/// @param success          Success callback
/// @param failure          Failure callback
- (void)activeBLELock:(ThingBLEAdvModel *)deviceInfo
               siteId:(long long)siteId
              success:(nullable void(^)(ThingSmartDeviceModel *deviceModel))success
              failure:(nullable ThingFailureHandler)failure;

@end

NS_ASSUME_NONNULL_END
