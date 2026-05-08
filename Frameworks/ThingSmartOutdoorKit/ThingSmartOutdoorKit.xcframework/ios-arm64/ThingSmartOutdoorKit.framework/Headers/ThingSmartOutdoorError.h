
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSInteger ThingSmartOutdoorErrorCode NS_SWIFT_NAME(ErrorCode);
/// The application is not authorized to use the Bluetooth Low Energy role.
FOUNDATION_EXTERN ThingSmartOutdoorErrorCode const ThingSmartOutdoorErrorCodeBLEUnauthorized NS_SWIFT_NAME(ErrorCodeBLEUnauthorized);
/// Bluetooth is currently powered off.
FOUNDATION_EXTERN ThingSmartOutdoorErrorCode const ThingSmartOutdoorErrorCodeBLEPoweredOff NS_SWIFT_NAME(ErrorCodeBLEPoweredOff);
/// BLE Device offline
FOUNDATION_EXTERN ThingSmartOutdoorErrorCode const ThingSmartOutdoorErrorCodeBLEOffline NS_SWIFT_NAME(ErrorCodeBLEOffline);


FOUNDATION_EXTERN NSErrorDomain const ThingSmartOutdoorErrorDomain NS_SWIFT_NAME(ErrorDomain);

NS_SWIFT_NAME(Error);
@interface ThingSmartOutdoorError : NSObject

/// error structure
/// @param code error code
/// @param message userInfo key:NSLocalizedDescriptionKey value:message
+ (NSError *)errorWithCode:(NSInteger)code message:(nullable NSString *)message;

@end

NS_ASSUME_NONNULL_END
