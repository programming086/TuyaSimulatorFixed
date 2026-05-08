
#import <ThingSmartDeviceCoreKit/ThingSmartDevice.h>
#import "ThingSmartLockTempPwdModel.h"
#import "ThingSmartLockRecordModel.h"
#import "ThingSmartLockMemberModel.h"
#import "ThingSmartLockRelationModel.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartLockDevice;
@protocol ThingSmartLockDeviceDelegate <ThingSmartDeviceDelegate>

/// The device receives a remote unlock request and needs to process the request within a certain period of time
///
/// @param device Door lock device
/// @param seconds Remaining processing time
- (void)device:(ThingSmartLockDevice *)device didReceiveRemoteUnlockRequest:(NSInteger)seconds;

@end

@interface ThingSmartLockDevice : ThingSmartDevice

@property (nonatomic, weak, nullable) id<ThingSmartLockDeviceDelegate> delegate;

#pragma mark - Remote door opening

/// Remote door opening response command reply
/// When a remote door opening request is triggered on the door lock, calling this method can realize remote door opening. Normally, if there is no remote door opening request, calling this method has no effect
///
/// @param open Whether to open the door
/// @param success Send reply success callback
/// @param failure Send reply failure callback
- (void)replyRemoteUnlock:(BOOL)open
                  success:(nullable ThingSuccessHandler)success
                  failure:(nullable ThingFailureError)failure;


#pragma mark - dynamic password

/// Get dynamic password
/// get lock dynamic password
///
/// @param success Success callback
/// @param failure Failure callback
- (void)getLockDynamicPasswordWithSuccess:(nullable ThingSuccessString)success
                                  failure:(nullable ThingFailureError)failure;

 
#pragma mark - temporary password

/// Create a temporary password for the door lock
///
/// @param password Temporary password, pure numbers, 7 digits
/// @param name Password identification name
/// @param effectiveDate Password effective date
/// @param invalidDate Password expiration date
/// @param success Success callback
/// @param failure Failure callback
- (void)createLockTempPwd:(NSString *)password
                     name:(NSString *)name
            effectiveDate:(NSDate *)effectiveDate
              invalidDate:(NSDate *)invalidDate
                  success:(nullable ThingSuccessBOOL)success
                  failure:(nullable ThingFailureError)failure;


/// Create a temporary password for the door lock
/// You can choose whether to send SMS. You need to confirm that the owner of the pid has pre-charged the SMS fee, otherwise the creation will fail
///
/// @param password Temporary password, pure numbers, 7 digits
/// @param name Password identifier name
/// @param effectiveDate Password effective date
/// @param invalidDate Password expiration date
/// @param countryCode Country code, such as 86
/// @param phone Mobile phone number. When the creation is successful, the mobile phone user will be notified
/// @param success Success callback
/// @param failure Failure callback
- (void)createLockTempPwd:(NSString *)password
                     name:(NSString *)name
            effectiveDate:(NSDate *)effectiveDate
              invalidDate:(NSDate *)invalidDate
              countryCode:(NSString *)countryCode
                    phone:(NSString *)phone
                  success:(nullable ThingSuccessBOOL)success
                  failure:(nullable ThingFailureError)failure;


/// Get the temporary password list of the door lock
///
/// @param success Success callback
/// @param failure Failure callback
- (void)getLockTempPwdListWithSuccess:(nullable void (^)( NSArray<ThingSmartLockTempPwdModel *> *lockTempPwdModels))success
                              failure:(nullable ThingFailureError)failure;


/// Delete temporary password
///
/// @param tempPwdId Temporary password id
/// @param force Whether to force deletion
/// yes: No need to wait for door lock synchronization, the password list will no longer be returned;
/// no: After the door lock confirms, it is really deleted, and the list will be returned
/// @param success Success callback
/// @param failure Failure callback
- (void)deleteLockTempPwdWithPwdId:(NSInteger)tempPwdId
                             force:(BOOL)force
                           success:(nullable ThingSuccessBOOL)success
                           failure:(nullable ThingFailureError)failure;


#pragma mark - Query door lock records

/// Get door lock hijacking records
///
/// @param dpCodes dpCodes
/// @param offset Number of pages
/// @param limit Number of data items per page
/// @param success Success callback
/// @param failure Failure callback
- (void)getLockHijackRecordListWithDpCodes:(NSArray<NSString *> *)dpCodes
                                    offset:(NSInteger)offset
                                     limit:(NSInteger)limit
                                   success:(void(^)(NSArray<ThingSmartLockRecordModel *> *))success
                                   failure:(nullable ThingFailureError)failure;

/// Get the door unlock record
///
/// @param offset number of pages
/// @param limit number of data per page
/// @param success success callback
/// @param failure failure callback
- (void)getUnlockRecordList:(NSInteger)offset
                      limit:(NSInteger)limit
                    success:(nullable void(^)(NSArray<ThingSmartLockRecordModel *> *lockRecordModels))success
                    failure:(nullable ThingFailureError)failure;

/// Get door lock record
///
/// @param dpCodes dpCodes
/// @param offset Number of pages
/// @param limit Number of data items per page
/// @param success Success callback
/// @param failure Failure callback
- (void)getLockRecordListWithDpCodes:(NSArray<NSString *> *)dpCodes
                              offset:(NSInteger)offset
                               limit:(NSInteger)limit
                             success:(nullable void(^)(NSArray<ThingSmartLockRecordModel *> *lockRecordModels))success
                             failure:(nullable ThingFailureError)failure;

#pragma mark - Door lock member operation

/// Add a door lock member
///
/// @param userName User name
/// @param avatarImage User avatar image
/// @param unlockRelations Door lock password association array
/// @param success Success callback
/// @param failure Failure callback
- (void)addLockNormalUserWithUserName:(NSString *)userName
                          avatarImage:(nullable UIImage *)avatarImage
                      unlockRelations:(nullable NSArray<ThingSmartLockRelationModel *> *)unlockRelations
                              success:(nullable ThingSuccessString)success
                              failure:(nullable ThingFailureError)failure;


/// Update door lock member information
///
/// @param userId User id
/// @param userName User name, if nil, do not modify
/// @param avatarImage User avatar image, if nil, do not modify
/// @param unlockRelations Door lock password association array, if nil, do not modify
/// @param success Success callback
/// @param failure Failure callback
- (void)updateLockNormalUserWithUserId:(NSString *)userId
                              userName:(nullable NSString *)userName
                           avatarImage:(nullable UIImage *)avatarImage
                       unlockRelations:(nullable NSArray<ThingSmartLockRelationModel *> *)unlockRelations
                               success:(nullable ThingSuccessBOOL)success
                               failure:(nullable ThingFailureError)failure;


/// Delete door lock member user
///
/// @param userId user id
/// @param success success callback
/// @param failure failure callback
- (void)deleteLockUserWithUserId:(NSString *)userId
                         success:(nullable ThingSuccessBOOL)success
                         failure:(nullable ThingFailureError)failure;


/// Get the door lock member list
///
/// @param success Success callback
/// @param failure Failure callback
- (void)getLockMemberListWithSuccess:(nullable void(^)(NSArray<ThingSmartLockMemberModel *> *lockMemberModels))success
                             failure:(nullable ThingFailureError)failure;

#pragma mark - hijack

/// Set anti-hijack
///
/// @param devId Device ID
/// @param dpId dp point
/// @param dpValue dp value
/// @param success Success callback
/// @param failure Failure callback
- (void)setHijackingConfigWithDevId:(NSString *)devId
                               dpId:(NSString *)dpId
                            dpValue:(NSString *)dpValue
                            success:(ThingSuccessBOOL)success
                            failure:(nullable ThingFailureError)failure;

/// Remove anti-hijacking settings
///
/// @param devId device ID
/// @param dpId dp point
/// @param dpValue dp value
/// @param success success callback
/// @param failure failure callback
- (void)removeHijackingConfigWithDevId:(NSString *)devId
                                  dpId:(NSString *)dpId
                               dpValue:(NSString *)dpValue
                               success:(ThingSuccessID)success
                               failure:(nullable ThingFailureError)failure;

/// Query the speaker password activation status
///
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchRemoteVoiceUnlockWithDevId:(NSString *)devId
                                success:(ThingSuccessID)success
                                failure:(nullable ThingFailureError)failure;

/// Set or cancel the speaker password
///
/// @param devId Device ID
/// @param open Switch status
/// @param pwd Password
/// @param success Success callback
/// @param failure Failure callback
- (void)setRemoteVoiceUnlockWithDevId:(NSString *)devId
                                 open:(BOOL)open
                                  pwd:(NSString *)pwd
                              success:(ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
