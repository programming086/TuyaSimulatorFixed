
#ifndef ThingSmartUser_Anonymous_h
#define ThingSmartUser_Anonymous_h

#import "ThingSmartUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartUser (Anonymous)

/// Enables anonymous registration.
/// @param countryCode The country code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)registerAnonymousWithCountryCode:(NSString *)countryCode
                                 success:(nullable ThingSuccessHandler)success
                                 failure:(nullable ThingFailureError)failure;

/// Deletes an anonymous account.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)deleteAnonymousAccountWithSuccess:(ThingSuccessHandler)success
                                  failure:(ThingFailureError)failure;

/// Binds a username.
/// @param countryCode The country code.
/// @param userName The mobile phone number or email address.
/// @param code The verification code.
/// @param password The password.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)usernameBindingWithCountryCode:(NSString *)countryCode
                              userName:(NSString *)userName
                                  code:(NSString *)code
                              password:(NSString *)password
                               success:(nullable ThingSuccessHandler)success
                               failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingSmartUser_Anonymous_h */
