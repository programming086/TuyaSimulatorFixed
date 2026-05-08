//
//  NSError+TYOTA.h
//  TuyaSmartDeviceCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define TYOTAErrorDomain @"com.ota.www"

typedef NS_ENUM(NSUInteger, TYOTAErrorCode) {
    /// Device's all firmwares is latest.
    TYOTAErrorCodeAllLatest = 5000,
    /// Checked no firmware.
    TYOTAErrorCodeCheckNoFirmware = 5001,
    /// Only one device can upgrade same time. (BLE device, BleMesh Sub device, SigMesh Sub device)
    TYOTAErrorCodeOnlyOneCanUpgradeSameTime = 5002,
    /// App download firmware fail. (BLE device, BleMesh Sub device, SigMesh Sub device)
    TYOTAErrorCodeDownloadFail = 5003,
    /// Fetch device if need signal limit fail.  ( can't continue )
    TYOTAErrorCodeFetchIfNeedSignalLimitFail = 5004,
    /// The device signal strength not satisfy the limit.（ alert continue or not, let user confirm, then call function `- confirmWarningUpgradeTask:`）
    TYOTAErrorCodeSignalStrengthNotSatisfy = 5005,
    /// Link to the device failed.  (BLE device, BleMesh Sub device, SigMesh Sub device)
    TYOTAErrorCodeLinkDeviceFail = 5006,
    /// Switch BLE device
    TYOTAErrorCodeBLESubSwitchTimeOut = 5007,
    /// The downloaded firmware's MD5 checked failed.
    TYOTAErrorCodeDownloadCheckMD5Error = 5009,
    /// Send firmware to device failed.  (BLE device, BleMesh Sub device, SigMesh Sub device)
    TYOTAErrorCodeSendUpgradePackageError = 5010,
    /// The device is  offline.
    TYOTAErrorCodeDeviceOffline = 5012,
    /// The pre verify before upgrade failed.
    TYOTAErrorCodeDeivcePreVerifyFail = 5013,
    /// Phone's bluetooth is not open.
    TYOTAErrorCodeBluetoothNotOpen = 5014,
    /// Failed when check the device need upgrade firmware list.
    TYOTAErrorCodeCheckUpdateFail = 5015,
    /// The general OTA failed.
    TYOTAErrorCodeCommonError = 5099,
};


@interface NSError (TYOTA)

+ (instancetype)tysdk_OTAErrorWithCode:(TYOTAErrorCode)code msg:(nullable NSString *)msg;

+ (instancetype)tysdk_OTADefaultErrorWithCode:(TYOTAErrorCode)code;

@end

NS_ASSUME_NONNULL_END
