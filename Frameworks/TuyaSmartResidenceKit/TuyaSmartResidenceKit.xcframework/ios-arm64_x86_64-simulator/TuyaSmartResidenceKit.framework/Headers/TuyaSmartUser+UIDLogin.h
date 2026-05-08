//
//  TuyaSmartUser+UIDLogin.h
//  TuyaSmartResidenceKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)

#import <TuyaSmartBaseKit/TuyaSmartBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartUser (UIDLogin)


/// The user ID that is used to log in or register. Account is registered at the first login.
/// @param countryCode The country code.
/// @param uid The user ID, use email.
/// @param authCode The authCode, Unique identifier.
/// @param createSite Creates the default site.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)loginOrRegisterWithCountryCode:(NSString *)countryCode
                                   uid:(NSString *)uid
                              authCode:(NSString *)authCode
                            createSite:(BOOL)createSite
                               success:(nullable TYSuccessID)success
                               failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END
