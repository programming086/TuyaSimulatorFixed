//
//  ThingSmartLockManager.h
//  ThingSmartLockKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLockPasswordModel;

typedef void (^ThingLockPasswordSuccessList)(NSArray<ThingLockPasswordModel *> * _Nullable list, NSInteger totalSize);
typedef void (^ThingLockPasswordSuccess)(ThingLockPasswordModel * _Nullable passwordModel);

@interface ThingLockPasswordManager : NSObject

+ (instancetype)shared;


/// Get the password list of lock device
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - pageNumber: Page number
///   - pageSize: Page size
///   - success: Success callback
///   - failure: Failure callback
- (void)getPasswordListWithSiteId:(long long)siteId
                         deviceId:(NSString *)deviceId
                       pageNumber:(NSInteger)pageNumber
                         pageSize:(NSInteger)pageSize
                          success:(ThingLockPasswordSuccessList)success
                          failure:(ThingFailureError)failure;


/// Get password detail of lock device
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - passwordId: Password ID
///   - success: Success callback
///   - failure: Failure callback
- (void)getPasswordDetailWithSiteId:(long long)siteId
                           deviceId:(NSString *)deviceId
                         passwordId:(NSString *)passwordId
                            success:(ThingLockPasswordSuccess)success
                            failure:(ThingFailureError)failure;

/// Modify the name of password
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - passwordId: Password ID
///   - passwordName: Password name
///   - success: Success callback
///   - failure: Failure callback
- (void)modifyPasswordSiteId:(long long)siteId
                    deviceId:(NSString *)deviceId
                  passwordId:(NSString *)passwordId
                passwordName:(NSString *)passwordName
                     success:(ThingSuccessID)success
                     failure:(ThingFailureError)failure;


/// Create a once offline password
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - name: Password name
///   - success: Success callback
///   - failure: Success callback
- (void)createOnceOfflinePasswordWithSiteId:(long long)siteId
                                   deviceId:(NSString *)deviceId
                                       name:(NSString *)name
                                    success:(ThingSuccessHandler)success
                                    failure:(ThingFailureError)failure;

/// Create a limit offline password
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - name: Password name
///   - effectiveTimeInterval: Effective time interval
///   - invalidTimeInterval: Invalid time interval
///   - success: Success callback
///   - failure: Failure callback
- (void)createLimitOfflinePasswordWithSiteId:(long long)siteId
                                    deviceId:(NSString *)deviceId
                                        name:(NSString *)name
                       effectiveTimeInterval:(NSTimeInterval)effectiveTimeInterval
                         invalidTimeInterval:(NSTimeInterval)invalidTimeInterval
                                     success:(ThingSuccessHandler)success
                                     failure:(ThingFailureError)failure;


/// Create a permanent online password
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - password: Password, Six-digit number
///   - name: Password name
///   - success: Success callback
///   - failure: Failure callback
- (void)createPermanentOnlinePasswordWithSiteId:(long long)siteId
                                       deviceId:(NSString *)deviceId
                                       password:(NSString *)password
                                           name:(NSString *)name
                                        success:(ThingSuccessHandler)success
                                        failure:(ThingFailureError)failure;


/// Create a limit online password
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - password: Password, Six-digit number
///   - name: Password name
///   - effectiveTimeInterval: Effective time interval
///   - invalidTimeInterval: Invalid time interval
///   - workingDay: A weekly cycle pattern, such as "1011111"
///   - startTime: Start time, such as "12:09"
///   - endTime: End time, such as "22:30"
///   - success: Success callback
///   - failure: Failure callback
- (void)createLimitOnlinePasswordWithSiteId:(long long)siteId
                                   deviceId:(NSString *)deviceId
                                   password:(NSString *)password
                                       name:(NSString *)name
                      effectiveTimeInterval:(NSTimeInterval)effectiveTimeInterval
                        invalidTimeInterval:(NSTimeInterval)invalidTimeInterval
                                 workingDay:(NSString *)workingDay
                                  startTime:(NSString *)startTime
                                    endTime:(NSString *)endTime
                                    success:(ThingSuccessHandler)success
                                    failure:(ThingFailureError)failure;


/// Remove a once offline password
/// - Parameters:
///   - siteId: Maintainer
///   - deviceId: Device ID
///   - passwordId: Password ID
///   - success: Success callback
///   - failure: Failure callback
- (void)removeOnceOfflinePasswordWithSiteId:(long long)siteId
                                   deviceId:(NSString *)deviceId
                                 passwordId:(NSString *)passwordId
                                    success:(ThingSuccessHandler)success
                                    failure:(ThingFailureError)failure;


/// Remove a litmit offline password
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - passwordId: Password ID
///   - success: Success callback
///   - failure: Failure callback
- (void)removeLimitOfflinePasswordWithSiteId:(long long)siteId
                                    deviceId:(NSString *)deviceId
                                  passwordId:(NSString *)passwordId
                                     success:(ThingSuccessString)success
                                     failure:(ThingFailureError)failure;



/// Remove an online password, whether it is a litmit online password or a permanent online password one
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - passwordId: Password ID
///   - lockId: Device lock ID
///   - success: Success callback
///   - failure: Failure callback
- (void)removeOnlinePasswordWithSiteId:(long long)siteId
                              deviceId:(NSString *)deviceId
                            passwordId:(NSString *)passwordId
                                lockId:(NSString *)lockId
                               success:(ThingSuccessHandler)success
                               failure:(ThingFailureError)failure;

/// Forces the removal of an online password from a specified device at a site.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device from which to remove the online password.
///   - passwordId: The ID of the online password to be removed.
///   - success: Success callback
///   - failure: Failure callback
- (void)forceRemoveOnlinePasswordWithSiteId:(long long)siteId
                                   deviceId:(NSString *)deviceId
                                 passwordId:(NSString *)passwordId
                                    success:(ThingSuccessID)success
                                    failure:(ThingFailureError)failure;

/// Retries the creation of an online password for a specified device at a site.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device for which to retry creating the online password.
///   - passwordId: The ID of the online password to be retried.
///   - success: Success callback
///   - failure: Failure callback
- (void)retryCreateOnlinePasswordWithSiteId:(long long)siteId
                                   deviceId:(NSString *)deviceId
                                 passwordId:(NSString *)passwordId
                                    success:(ThingSuccessHandler)success
                                    failure:(ThingFailureError)failure;

/// Clears all passwords from a specified device at a site.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device from which to clear all passwords.
///   - success: Success callback
///   - failure: Failure callback
- (void)clearAllPasswordWithSiteId:(long long)siteId
                          deviceId:(NSString *)deviceId
                           success:(ThingSuccessHandler)success
                           failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
