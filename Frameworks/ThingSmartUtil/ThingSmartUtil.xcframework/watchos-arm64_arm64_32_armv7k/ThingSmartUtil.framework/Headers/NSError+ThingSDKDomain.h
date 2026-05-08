//
//  NSError+ThingSDKDomain.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

#define ThingErrorDomain @"com.thing.www"

/**
 *
 * Definitions of error codes
 */
typedef enum {
    
    // The specified network parameter is invalid. The error code cannot be changed.
    THING_NETWORK_ERROR = 1500,
    
    // A common error has occurred.
    THING_COMMON_ERROR,
    
    // Failed to decompress the panel.
    THING_PANEL_DECOMPRESS_ERROR,
    
    // Failed to validate the panel size.
    THING_PANEL_SIZE_ERROR,
    
    // Failed to validate local time.
    THING_TIME_VALIDATE_FAILED,
    
    // The specified device goes offline.
    THING_GW_OFFLINE,
    
    // The specified user has already registered.
    THING_USER_HAS_EXISTS,
    
    // The specified DP is illegal and cannot be sent.
    THING_ILLEGAL_DP_DATA,
    
    // The device has been reset.
    THING_DEVICE_HAS_RESET,
    
    // The user login information is lost.
    THING_USER_SESSION_LOSS,
    
    // The user login information is invalid.
    THING_USER_SESSION_INVALID,
    
    // An error has occurred while recognizing the QR code.
    THING_QR_PROTOCOL_NOT_RECOGNIZED,
    
    // A timeout error has occurred.
    THING_TIMEOUT_ERROR,
    
    // Node IDs are unavailable.
    THING_NO_AVAILABLE_NODE_ID,
    
    // The format of the specified phone number is invalid.
    THING_MOBILE_FORMAT_ERROR,
    
    // The specified phone number is invalid.
    THING_MOBILE_ILLEGAL,
    
    // The specified phone verification code is invalid.
    THING_MOBILE_CODE_ERROR,
    
    // The format of the specified email address is invalid.
    THING_EMAIL_FORMAT_ERROR,
    
    // The specified email address is invalid.
    THING_EMAIL_ILLEGAL,
    
    // The specified email verification code is invalid.
    THING_EMAIL_CODE_ERROR,
    
    // The specified user does not exist.
    THING_USER_NOT_EXISTS,
    
    // Sub-devices of the Zigbee group cannot be empty.
    THING_GROUP_DEVICE_LIST_NOT_EMPTY,
    
    // The LAN is disconnected.
    THING_SOCKET_TCP_DISCONNECT,
    
    // An error has occurred while resolving domain names over the LAN.
    THING_SOCKET_TCP_RESPONSE_ERROR,
    
} ThingSDKErrorCode;

@interface NSError (ThingSDKDomain)

+ (instancetype)thingsdk_errorWithErrorCode:(ThingSDKErrorCode)errorCode errorMsg:(NSString *)errorMsg;

+ (NSError *)thingsdk_errorWithCodeString:(NSString *)codeString errorMsg:(NSString *)errorMsg;

+ (NSError *)thingsdk_errorWithCodeString:(NSString *)codeString errorMsg:(NSString *)errorMsg ext:(NSDictionary *)ext;

@end
