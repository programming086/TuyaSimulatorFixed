//
//  NSError+ThingSmartStream.h
//  ThingSmartStreamChannelKit
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSErrorDomain const ThingSmartStreamErrorDomain;

typedef NS_ENUM(NSUInteger, ThingSmartStreamErrorCode) {
    // Common error
    ThingSmartStreamErrorCodeCommonError = 39001,
    // Invalid Params
    ThingSmartStreamErrorCodeParamsInvalid = 39002,
    // HTTP request fail
    ThingSmartStreamErrorCodeHttpRequestFail = 39003,
    // Connection Not connected
    ThingSmartStreamErrorCodeNotConnected = 39004,
    // Session Invalid
    ThingSmartStreamErrorCodeSessionInvalid = 39005,
    // EventId Invalid
    ThingSmartStreamErrorCodeEventIdInvalid = 39006,
    // Data Channel Invalid
    ThingSmartStreamErrorCodeDataChannelInvalid = 39007,
    // Data packet Invalid
    ThingSmartStreamErrorCodePacketInvalid = 39008,
    // File read error
    ThingSmartStreamErrorCodeFileReadError = 39009,
    // Send data packet error
    ThingSmartStreamErrorCodeSendDataPacketError = 39010,
    // Session break error, detail code is `error.userInfo[NSLocalizedFailureReasonErrorKey]`
    ThingSmartStreamErrorCodeSessionBreak = 39011,
    // Connection break error, detail code is `error.userInfo[NSLocalizedFailureReasonErrorKey]`
    ThingSmartStreamErrorCodeConnectionBreak = 39012,
    // image format error(only for TTT)
    ThingSmartStreamErrorCodeImageFormatError = 39013,
    // recording error(only for TTT)
    ThingSmartStreamErrorCodeRecordingError = 39014,
    // db error(only for TTT)
    ThingSmartStreamErrorCodeDBError = 39015,
    // Connection recovering
    ThingSmartStreamErrorCodeConnectionIsRecovering = 39016,
};

@interface NSError (ThingSmartStream)
+ (instancetype)thing_streamError:(ThingSmartStreamErrorCode)code;
+ (instancetype)thing_streamError:(ThingSmartStreamErrorCode)code msg:(nullable NSString *)msg;

+ (instancetype)thing_streamError:(ThingSmartStreamErrorCode)code underError:(nullable NSError *)error;
+ (instancetype)thing_streamError:(ThingSmartStreamErrorCode)code underError:(nullable NSError *)error msg:(nullable NSString *)msg;

+ (instancetype)thing_streamError:(ThingSmartStreamErrorCode)code underError:(nullable NSError *)error msg:(nullable NSString *)msg reason:(nullable NSString *)reason;
@end

NS_ASSUME_NONNULL_END
