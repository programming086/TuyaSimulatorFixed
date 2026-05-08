//
//  ThingLockFingerprintManager.h
//  ThingSmartLockSDK
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingLockFingerprintModel;

typedef void (^ThingLockFingerprintSuccessList)(NSArray<ThingLockFingerprintModel *> * _Nullable list, NSInteger totalSize);
typedef void (^ThingLockFingerprintSuccess)(ThingLockFingerprintModel * _Nullable model);
typedef void (^ThingLockFingerprintInputCallback)(NSInteger currentCount, NSInteger totalCount);

@interface ThingLockFingerprintManager : NSObject

+ (instancetype)shared;

/// Get a list of fingerprints
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - pageNo: Page number
///   - pageSize: Page size
///   - success: Success callback
///   - failure: Failure callback
- (void)getFingerprintListWithSiteId:(long long)siteId
                            deviceId:(NSString *)deviceId	
                              pageNo:(NSInteger)pageNo
                            pageSize:(NSInteger)pageSize
                             success:(ThingLockFingerprintSuccessList)success
                             failure:(ThingFailureError)failure;


/// Retrieves the details of a specified fingerprint
/// - Parameters:
///   - siteId: The ID of the site where the device is located
///   - deviceId: The ID of the device containing the fingerprint
///   - fingerprintId: The ID of fingerprint to retrieve detail for
///   - success: Success callback
///   - failure: Failure callback
- (void)getFingerprintDetailWithSiteId:(long long)siteId
                              deviceId:(NSString *)deviceId
                         fingerprintId:(NSString *)fingerprintId
                               success:(ThingLockFingerprintSuccess)success
                               failure:(ThingFailureError)failure;


/// Creates a limited-use fingerprint for a specified device
/// - Parameters:
///   - siteId: The ID of the site where the device located
///   - deviceId: The ID of device for which the fingerprint is being to created
///   - fingerprintName: The name of fingerprint to be create
///   - effectiveTimeInterval: Effective time interval
///   - invalidTimeInterval: Invalid time interval
///   - inputCallback: Input callback
///   - success: Success callback
///   - failure: Failure callback
- (void)createLimitFingerprintWithSiteId:(long long)siteId
                                deviceId:(NSString *)deviceId
                         fingerprintName:(NSString *)fingerprintName
                   effectiveTimeInterval:(NSTimeInterval)effectiveTimeInterval
                     invalidTimeInterval:(NSTimeInterval)invalidTimeInterval
                            inputCallback:(ThingLockFingerprintInputCallback)inputCallback
                                 success:(ThingSuccessHandler)success
                                 failure:(ThingFailureError)failure;


/// Create a permanent fingerprint for a specified device
/// - Parameters:
///   - siteId: The ID of the site where the device located
///   - deviceId: The ID of the device for which the fingerprint is being to created
///   - fingerprintName: The name of the fingerprint to be create
///   - inputCallback: Input callback
///   - success: Success callback
///   - failure: Failure callback
- (void)createPermanentFingerprintWithSiteId:(long long)siteId
                                    deviceId:(NSString *)deviceId
                             fingerprintName:(NSString *)fingerprintName
                               inputCallback:(ThingLockFingerprintInputCallback)inputCallback
                                     success:(ThingSuccessHandler)success
                                     failure:(ThingFailureError)failure;

/// Updates the name of a specified fingerprint for a device
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device containing the fingerprint.
///   - fingerprintId: The ID of the fingerprint to be updated.
///   - fingerprintName: The new name for the fingerprint.
///   - success: Success callback
///   - failure: Failure callback
- (void)updateNameWithSiteId:(long long)siteId
                    deviceId:(NSString *)deviceId
               fingerprintId:(NSString *)fingerprintId
             fingerprintName:(NSString *)fingerprintName
                     success:(ThingSuccessHandler)success
                     failure:(ThingFailureError)failure;

/// Removes a specified fingerprint from a device.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device containing the fingerprint.
///   - fingerprintId: The ID of the fingerprint to be removed.
///   - lockId: The ID of the lock associated with the fingerprint.
///   - success: Success callback
///   - failure: Failure callback
- (void)removeFingerprintWithSiteId:(long long)siteId
                           deviceId:(NSString *)deviceId
                      fingerprintId:(NSString *)fingerprintId
                             lockId:(NSString *)lockId
                            success:(ThingSuccessHandler)success
                            failure:(ThingFailureError)failure;


/// Clears all fingerprints from a device.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The ID of the device from which to clear all fingerprints.
///   - success: Success callback
///   - failure: Failure callback
- (void)clearAllFingerprintWithSiteId:(long long)siteId
                             deviceId:(NSString *)deviceId
                              success:(ThingSuccessHandler)success
                              failure:(ThingFailureError)failure;


/// Cancels the fingerprint creation.
/// - Parameters:
///   - siteId: The ID of the site where the device is located.
///   - deviceId: The device ID on which the fingerprint creation is to be canceled.
///   - success: Success callback
///   - failure: Failure callback
- (void)cancelFingerprintCreateWithSiteId:(long long)siteId
                                 deviceId:(NSString *)deviceId
                                  success:(ThingSuccessHandler)success
                                  failure:(ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END
