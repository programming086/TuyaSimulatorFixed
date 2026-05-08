
#ifndef ThingSmartUser_Region_h
#define ThingSmartUser_Region_h

#import "ThingSmartUser.h"
#import "ThingRegionModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartUser (Region)

/// Returns the region list.
/// @param countryCode The country code.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)regionListWithCountryCode:(NSString *)countryCode
                          success:(void(^)(NSArray<ThingRegionModel *> *regionList))success
                          failure:(ThingFailureError)failure;

/// Returns the default region of the country code. For example,`AY` indicates China, `AZ` indicates America, and `EU` indicates Europe.
/// @param countryCode The country code.
/// @return The default region of the country code.
- (NSString *)getDefaultRegionWithCountryCode:(NSString *)countryCode;

/// Returns the default region.
/// @return The default region of the country code.
- (NSDictionary *)getDefaultDomain;

/// Checks the verification code that is used to register, log in, or reset the password.
/// @param userName The phone number or email address.
/// @param region To complete the required registration, use [ThingSmartUser regionListWithCountryCode:success:failure:] or [ThingSmartUser getDefaultRegionWithCountryCode:] to get the region.
/// @param countryCode The country code.
/// @param code The verification code.
/// @param type Valid values: `1`: Register with the mobile phone verification code. `2`: Log in with the mobile phone verification code. `3`: Reset the mobile phone password.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)checkCodeWithUserName:(NSString *)userName
                       region:(NSString *_Nullable)region
                  countryCode:(NSString *)countryCode
                         code:(NSString *)code
                         type:(NSInteger)type
                      success:(ThingSuccessBOOL)success
                      failure:(ThingFailureError)failure;

/// Registers with the mobile phone or email.
/// @param userName The mobile phone number or email address.
/// @param region The region to register the account. Use [ThingSmartUser regionListWithCountryCode:success:failure:] or [ThingSmartUser getDefaultRegionWithCountryCode:] to get the region.
/// @param countryCode The country code.
/// @param code The verification code.
/// @param password The password.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)registerWithUserName:(NSString *)userName
                      region:(NSString *)region
                 countryCode:(NSString *)countryCode
                        code:(NSString *)code
                    password:(NSString *)password
                     success:(ThingSuccessHandler)success
                     failure:(ThingFailureError)failure;

/// Switches the region of the logged-in user.
/// @warning 1. Switching the user's region is the same as registering in a new account to the region of the user. To comply with GDPR, when the region is switched, the user's device and scene are not taken to the new account. Only the user's information is taken to the new account.
/// @warning 2. When the account is switched to the new region, the earlier account is only reserved for 30 days and then will be deleted.
/// @warning 3. After the region is switched, the new account is logged in.
/// @param region The region to register the account. Use [ThingSmartUser regionListWithCountryCode:success:failure:] or [ThingSmartUser getDefaultRegionWithCountryCode:] to get the region.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)switchUserRegion:(NSString *)region
                 success:(ThingSuccessHandler)success
                 failure:(ThingFailureError)failure;


/**
 *  Returns the whitelist of regions to enable registration with mobile phone numbers.
 *
 *
 *  @param success     Called when the task is finished.
 *  @param failure     Called when the task is interrupted by an error.
 */
- (void)getWhiteListWhoCanSendMobileCodeSuccess:(ThingSuccessString)success
                                        failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingSmartUser_Region_h */
