//
//  ThingLockDevice.h
//  ThingSmartLockKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

@class ThingEKeyModel;
@class ThingLockActionModel;
@class ThingLockDeviceModel;

typedef void (^ThingLockEKeySuccessList)(NSArray<ThingEKeyModel *> * _Nullable list, NSInteger totalSize);
typedef void (^ThingLockEKeySuccess)(ThingEKeyModel * _Nullable eKeyModel);
typedef void (^ThingLockActionSuccessList)(NSArray<ThingLockActionModel *> * _Nullable list, NSString * _Nullable sortValues);
typedef void (^ThingLockDetailSuccess)(ThingLockDeviceModel * _Nullable lockModel);


NS_ASSUME_NONNULL_BEGIN

@interface ThingLockDevice : NSObject


/// Get lock device detail information
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getLockDetailWithSiteId:(long long)siteId
                        deviceId:(NSString *)deviceId
                         success:(ThingLockDetailSuccess)success
                         failure:(ThingFailureError)failure;


/// Create a one-time e-Eky
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - account: Account
///   - ekeyName: E-Key name
///   - effectiveTimeInterval: Effective time interval
///   - invalidTimeInterval: Invalid time interval
///   - success: Success callback
///   - failure: Failure callback
+ (void)createOnceEKeyWithSiteId:(long long)siteId
                        deviceId:(NSString *)deviceId
                         account:(NSString *)account
                        eKeyName:(NSString *)ekeyName
           effectiveTimeInterval:(NSTimeInterval)effectiveTimeInterval
             invalidTimeInterval:(NSTimeInterval)invalidTimeInterval
                         success:(ThingSuccessID)success
                         failure:(ThingFailureError)failure;

/// Create a permanent E-Key
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - account: Account must be an email
///   - ekeyName: E-Key name
///   - success: Success callback
///   - failure: Failure callback
+ (void)createPermanentEKeyWithSiteId:(long long)siteId
                             deviceId:(NSString *)deviceId
                              account:(NSString *)account
                             eKeyName:(NSString *)ekeyName
                              success:(ThingSuccessID)success
                              failure:(ThingFailureError)failure;


/// Create a limit E-Key
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - account: Account must be an email
///   - ekeyName: E-Key name
///   - effectiveTimeInterval: Effective time interval
///   - invalidTimeInterval: Invalid time interval
///   - workingDay: Working day
///   - startTime: Start time
///   - endTime: End time
///   - success: Success callback
///   - failure: Failure callback
+ (void)createLimitEKeyWithSiteId:(long long)siteId
                         deviceId:(NSString *)deviceId
                          account:(NSString *)account
                         eKeyName:(NSString *)ekeyName
            effectiveTimeInterval:(NSTimeInterval)effectiveTimeInterval
              invalidTimeInterval:(NSTimeInterval)invalidTimeInterval
                       workingDay:(NSString *)workingDay
                        startTime:(NSString *)startTime
                          endTime:(NSString *)endTime
                          success:(ThingSuccessID)success
                          failure:(ThingFailureError)failure;

/// Get the list of device E-Keys
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - pageNo: Page number
///   - pageSize: Page size
///   - success: Success callback
///   - failure: Failure callback
+ (void)getEKeyListWithSiteId:(long long)siteId
                     deviceId:(NSString *)deviceId
                       pageNo:(NSInteger)pageNo
                     pageSize:(NSInteger)pageSize
                      success:(ThingLockEKeySuccessList)success
                      failure:(ThingFailureError)failure;

/// Get the detail information of E-Key
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - eKeyId: E-Key ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)getEKeyDetailWithSiteId:(long long)siteId
                       deviceId:(NSString *)deviceId
                         eKeyId:(NSString *)eKeyId
                        success:(ThingLockEKeySuccess)success
                        failure:(ThingFailureError)failure;




/// Update a limit E-Key
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - eKeyId: E-Key ID
///   - ekeyName: E-Key name
///   - effectiveTimeInterval: Effective time interval
///   - invalidTimeInterval: Invalid time interval
///   - workingDay: A weekly cycle pattern, such as "1011111"
///   - startTime: Start time
///   - endTime: End time
///   - success: Success callback
///   - failure: Failure callback
+ (void)updateLimitEKeyWithSiteId:(long long)siteId
                         deviceId:(NSString *)deviceId
                           eKeyId:(NSString *)eKeyId
                         eKeyName:(NSString *)ekeyName
            effectiveTimeInterval:(NSTimeInterval)effectiveTimeInterval
              invalidTimeInterval:(NSTimeInterval)invalidTimeInterval
                       workingDay:(NSString *)workingDay
                        startTime:(NSString *)startTime
                          endTime:(NSString *)endTime
                          success:(ThingSuccessID)success
                          failure:(ThingFailureError)failure;


/// Update a permanent E-Key
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - eKeyId: E-Key ID
///   - ekeyName: E-Key name
///   - success: Success callback
///   - failure: Failure callback
+ (void)updatePermanentEKeyWithSiteId:(long long)siteId
                             deviceId:(NSString *)deviceId
                               eKeyId:(NSString *)eKeyId
                             eKeyName:(NSString *)ekeyName
                              success:(ThingSuccessID)success
                              failure:(ThingFailureError)failure;



/// Update a one-time E-Key
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - eKeyId: E-Key ID
///   - ekeyName: E-Key name
///   - effectiveTimeInterval: Effective time interval
///   - invalidTimeInterval: Invalid time interval
///   - success: Scuccess callback
///   - failure: Failure callback
+ (void)updateOnceEKeyWithSiteId:(long long)siteId
                        deviceId:(NSString *)deviceId
                          eKeyId:(NSString *)eKeyId
                        eKeyName:(NSString *)ekeyName
           effectiveTimeInterval:(NSTimeInterval)effectiveTimeInterval
             invalidTimeInterval:(NSTimeInterval)invalidTimeInterval
                         success:(ThingSuccessID)success
                         failure:(ThingFailureError)failure;


/// Remove a E-Key
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - eKeyId: E-Key ID
///   - success: Success callback
///   - failure: Failure callback
+ (void)removeEKeyWithSiteId:(long long)siteId
                    deviceId:(NSString *)deviceId
                      eKeyId:(NSString *)eKeyId
                     success:(ThingSuccessID)success
                     failure:(ThingFailureError)failure;


/// Get operation record of lock device
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - sortValues: Sort values, like page number
///   - pageSize: Page size
///   - success: Success callback
///   - failure: Failure callback
+ (void)getOperateRecordsWithSiteId:(long long)siteId
                           deviceId:(NSString *)deviceId
                         sortValues:(NSString *)sortValues
                           pageSize:(NSInteger)pageSize
                            success:(ThingLockActionSuccessList)success
                            failure:(ThingFailureError)failure;

/// Get opening records of lock device
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - sortValues: Sort values, like page number
///   - pageSize: Page size
///   - success: Success callback
///   - failure: Failure callback
+ (void)getOpenRecordsWithSiteId:(long long)siteId
                        deviceId:(NSString *)deviceId
                      sortValues:(NSString *)sortValues
                        pageSize:(NSInteger)pageSize
                         success:(ThingLockActionSuccessList)success
                         failure:(ThingFailureError)failure;


/// Get alarm records of lock device
/// - Parameters:
///   - siteId: Site ID
///   - deviceId: Device ID
///   - sortValues: Sort values, like page number
///   - pageSize: Page size
///   - success: Success callback
///   - failure: Failure callback
+ (void)getAlarmRecordsWithSiteId:(long long)siteId
                         deviceId:(NSString *)deviceId
                       sortValues:(NSString *)sortValues
                         pageSize:(NSInteger)pageSize
                          success:(ThingLockActionSuccessList)success
                          failure:(ThingFailureError)failure;



/// Activates callbacks for specified devices at a site.
/// - Parameters:
///   - siteId: The ID of the site where the devices are located.
///   - devIds: A list of IDs for the devices to activate the callbacks for.
///   - success: Success callback
///   - failure: Failure callback
+ (void)activeCallbackWithSiteId:(long long)siteId
                          devIds:(NSArray<NSString *> *)devIds
                         success:(ThingSuccessID)success
                         failure:(ThingFailureError)failure;

/// Removes the device and unbinds the device from the current user.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)deleteWithDeviceId:(NSString *)devId
                 success:(ThingSuccessHandler)success
                 failure:(ThingFailureError)failure;


/// Force removes the device and unbinds the device from the current user.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
+ (void)forceDeleteWithDeviceId:(NSString *)devId
                        success:(ThingSuccessHandler)success
                        failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
