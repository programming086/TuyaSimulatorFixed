//
//  ThingSmartPowerToolsOTAConstant.h
//  ThingSmartPowerToolsOTABizBundle
//
//  Created by 尼奥 on 2024/9/10.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartPowerToolsOTAError;

extern NSString *const ThingSmartPowerToolsOTAManagerErrorDomain;

typedef NS_ENUM(NSInteger, ThingSmartPowerToolsOTAManagerErrorCode) {
    ThingSmartPowerToolsOTAManagerErrorCodeInvalidDevId = 1000,
    ThingSmartPowerToolsOTAManagerErrorCodeInvalidURL = 1001,
    ThingSmartPowerToolsOTAManagerErrorCodeBluetoothDisable = 1002,
    ThingSmartPowerToolsOTAManagerErrorCodeDeviceNotExist = 1003,
    ThingSmartPowerToolsOTAManagerErrorCodeInvalidFirmwareUpgradeInfo = 1004,
    ThingSmartPowerToolsOTAManagerErrorCodeInvalidFirmwareUpgradeImage = 1005,
    ThingSmartPowerToolsOTAManagerErrorCodeDevIdInTransit = 1006,
    ThingSmartPowerToolsOTAManagerErrorCodeRequestFailed = 1007, // For details about the error information, see underlyingErrors
    ThingSmartPowerToolsOTAManagerErrorCodeTransferFailed = 1008, // For details about the error information, see underlyingErrors
    ThingSmartPowerToolsOTAManagerErrorCodeDownloadFailed = 1009, // For details about the error information, see underlyingErrors
};

typedef void (^ThingSmartPowerToolsFail)(NSError *error);

/**
 * Error class for OTA operations
 */
@interface ThingSmartPowerToolsOTAError : NSError

/**
 * Create an error with a specific code.
 * @param code The error code.
 * @return A new instance of ThingSmartPowerToolsOTAError.
 */
+ (instancetype)errorWithCode:(ThingSmartPowerToolsOTAManagerErrorCode)code;

/**
 * Create an error with a specific code and additional user info.
 * @param code The error code.
 * @param userInfo Additional user info.
 * @return A new instance of ThingSmartPowerToolsOTAError.
 */
+ (instancetype)errorWithCode:(ThingSmartPowerToolsOTAManagerErrorCode)code userInfo:(nullable NSDictionary<NSErrorUserInfoKey,id> *)userInfo;

@end

/**
 * Constant class for OTA operations
 */
@interface ThingSmartPowerToolsOTAConstant : NSObject

@end

NS_ASSUME_NONNULL_END
