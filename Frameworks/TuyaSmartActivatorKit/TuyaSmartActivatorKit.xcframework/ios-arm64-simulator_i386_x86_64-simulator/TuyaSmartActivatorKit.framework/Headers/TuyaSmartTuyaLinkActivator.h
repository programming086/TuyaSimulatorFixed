//
// TuyaSmartTuyaLinkActivator.h
// TuyaSmartActivatorKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>
#import <TuyaSmartDeviceKit/TuyaSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartTuyaLinkActivator : NSObject

/// Bind the TuyaLink Device to home.
/// @param code The TuyaLink Device QRCode content string.
/// @param homeId The home ID
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)bindTuyaLinkDeviceWithQRCode:(NSString *)code
                              homeId:(long long)homeId
                             success:(void (^)(TuyaSmartDeviceModel *deviceModel))success
                             failure:(TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
