//
//  ThingSmartUser+UIDLogin.h
//  ThingSmartResidenceKit
//
//  Copyright (c) 2014-2021 Thing Inc. (https://developer.thing.com/)

#import <ThingSmartBaseKit/ThingSmartBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartUser (UIDLogin)


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
                               success:(nullable ThingSuccessID)success
                               failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
