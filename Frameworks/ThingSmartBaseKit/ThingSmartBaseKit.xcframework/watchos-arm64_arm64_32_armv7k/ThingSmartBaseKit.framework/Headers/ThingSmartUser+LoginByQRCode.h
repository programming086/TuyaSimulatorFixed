
#ifndef ThingSmartUser_LoginByQRCode_h
#define ThingSmartUser_LoginByQRCode_h

#import "ThingSmartUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartUser (LoginByQRCode)

#pragma mark - Scan code to authorize third-party app login

/// Authorizes third-party apps to support login with QR code.
/// @param codeInfo The QR code information.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByQRcode:(NSDictionary *)codeInfo success:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure __attribute__((deprecated("Use -loginByQRcodeV2:success:failure instead")));

/// Authorizes third-party apps to support login with QR code new.
/// @param codeInfo The QR code information.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginByQRcodeV2:(NSDictionary *)codeInfo success:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure;

/// Returns information about third-party apps.
/// @param codeInfo The QR code information.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)userInfo:(NSDictionary *)codeInfo success:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingSmartUser_LoginByQRCode_h */
