//
//  ThingSmartDevice+Home.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDevice (Home)

/// Synchronizes device information.
/// @param devId The device ID.
/// @param homeId The home ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)syncDeviceInfoWithDevId:(NSString *)devId
                         homeId:(long long)homeId
                        success:(nullable ThingSuccessHandler)success
                        failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
