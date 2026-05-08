
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import "ThingSmartLockRelationModel.h"
#import <ThingSmartDeviceKit/ThingSmartDeviceKit.h>
#import "ThingSmartZigbeeLockOpmodeModel.h"
#import "ThingSmartBLELockOpMessageModel.h"
#import "ThingSmartZigbeeLockRemotePermissionModel.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartZigbeeLockDevice;
@protocol ThingSmartZigbeeLockDeviceDelegate <ThingSmartDeviceDelegate>

/// Received a callback message for a new unlocking method
/// @param device Door lock device
/// @param opMessage Device operation message
- (void)device:(ThingSmartZigbeeLockDevice *)device didReceiveAddOpMessage:(ThingSmartBLELockOpMessageModel *)opMessage;


/// Received callback information for deleting unlocking mode
/// @param device Door lock device
/// @param opMessage Device operation message
- (void)device:(ThingSmartZigbeeLockDevice *)device didReceiveDeleteOpMessage:(ThingSmartBLELockOpMessageModel *)opMessage;

@end

@interface ThingSmartZigbeeLockDevice : ThingSmartDevice

@property (nonatomic, weak, nullable) id<ThingSmartZigbeeLockDeviceDelegate> delegate;

#pragma mark - Unlock

/// Remote door opening
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)remoteUnlockWithDevId:(NSString *)devId
                      success:(nullable ThingSuccessID)success
                      failure:(nullable ThingFailureError)failure;

/// Remote door opening with password
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)remoteUnlockWithDevId:(NSString *)devId
                     password:(NSString *)password
                      success:(nullable ThingSuccessID)success
                      failure:(nullable ThingFailureError)failure;

/// Remote door closing
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)remoteLockWithDevId:(NSString *)devId
                    success:(nullable ThingSuccessID)success
                    failure:(nullable ThingFailureError)failure;

/// Security protection days
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)getSecurityGuardDaysWithDevId:(NSString *)devId
                              success:(nullable ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

/// Get panel configuration information, password type
/// @param productId product ID
/// @param options query items (uiContent, cloudDp, powerCode)
/// @param success success callback
/// @param failure failure callback
- (void)getLockDeviceConfigWithProductId:(NSString *)productId
                                 options:(NSString *)options
                                 success:(ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

#pragma mark - Records

/// Alarm unread
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)getUnreadAlarmNumberWithDevId:(NSString *)devId
                              success:(nullable ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

/// Alarm message
/// @param devId device ID
/// @param dpIds alarm message dp point set
/// @param offset number of pages
/// @param limit number of data items per page
/// @param success success callback
/// @param failure failure callback
- (void)getAlarmRecordListWithDevId:(NSString *)devId
                              dpIds:(NSArray *)dpIds
                             offset:(int)offset
                              limit:(int)limit
                            success:(nullable ThingSuccessID)success
                            failure:(nullable ThingFailureError)failure;

/// Door opening record
/// @param devId Device ID
/// @param dpIds Door opening record dpId collection
/// @param startTime Start time
/// @param endTime End time
/// @param offset Number of pages
/// @param limit Number of data items per page
/// @param success Success callback
/// @param failure Failure callback
- (void)getUnlockRecordListWithDevId:(NSString *)devId
                               dpIds:(NSArray *)dpIds
                           startTime:(NSInteger)startTime
                             endTime:(NSInteger)endTime
                              offset:(int)offset
                               limit:(int)limit
                             success:(nullable ThingSuccessID)success
                             failure:(nullable ThingFailureError)failure;

#pragma mark - opmode manager

/// User unlocking method list
/// @param devId device ID
/// @param userId user ID
/// @param success success callback
/// @param failure failure callback
- (void)getMemberOpmodeListWithDevId:(NSString *)devId
                              userId:(NSString *)userId
                             success:(nullable void(^)(NSArray<ThingSmartZigbeeLockOpmodeModel *> *models))success
                             failure:(nullable ThingFailureError)failure;

/// Get the unassigned unlocking method
/// @param devId device ID
/// @param success success callback
/// @param failure failure callback
- (void)getUnallocOpModeWithDevId:(NSString *)devId
                          success:(nullable ThingSuccessID)success
                          failure:(nullable ThingFailureError)failure;

/// Assign the unlocking method to the person
/// @param devId device ID
/// @param userId member ID
/// @param unlockIds unlocking method id
/// @param success success callback
/// @param failure failure callback
- (void)allocUnlockOpModeWithDevId:(NSString *)devId
                            userId:(NSString *)userId
                         unlockIds:(NSString *)unlockIds
                           success:(ThingSuccessID)success
                           failure:(nullable ThingFailureError)failure;

/// Bind door opening record to user
/// @param devId Device ID
/// @param userId User ID
/// @param unlockIds Unlock method list
/// @param success Success callback
/// @param failure Failure callback
- (void)bindUnlockOpModeWithDevId:(NSString *)devId
                           userId:(NSString *)userId
                        unlockIds:(NSString *)unlockIds
                          success:(ThingSuccessID)success
                          failure:(nullable ThingFailureError)failure;

/// Add unlock
/// @param devId Device ID
/// @param isAdmin Is it an administrator?
/// @param unlockOpType Unlock method
/// @param unlockDpCode dp code corresponding to the unlock method, see product definition for details
/// @param lockUserId lock user ID
/// @param userId user id
/// @param unlockName unlock method name
/// @param needHijacking whether to set anti-hijacking
/// @param success success callback
/// @param failure failure callback
- (void)addUnlockOpmodeForMemberWithDevId:(NSString *)devId
                                  isAdmin:(BOOL)isAdmin
                             unlockOpType:(ThingUnlockOpType)unlockOpType
                             unlockDpCode:(NSString *)unlockDpCode
                               lockUserId:(int)lockUserId
                                   userId:(NSString *)userId
                               unlockName:(NSString *)unlockName
                            needHijacking:(BOOL)needHijacking
                                  success:(nullable ThingSuccessID)success
                                  failure:(nullable ThingFailureError)failure;

/// Add unlocking method (directly send with password)
/// @param devId Device ID
/// @param isAdmin Is it an administrator?
/// @param password Password
/// @param lockUserId Lock user ID
/// @param userId User ID
/// @param unlockName Unlocking method name
/// @param needHijacking Is it set to anti-hijacking?
/// @param success Success callback
/// @param failure Failure callback
- (void)addPasswordOpmodeForMemberWithDevId:(NSString *)devId
                                    isAdmin:(BOOL)isAdmin
                                   password:(NSString *)password
                                 lockUserId:(int)lockUserId
                                     userId:(NSString *)userId
                                 unlockName:(NSString *)unlockName
                              needHijacking:(BOOL)needHijacking
                                    success:(nullable ThingSuccessID)success
                                    failure:(nullable ThingFailureError)failure;

/// Update unlock method (only supports updating name)
/// @param devId device ID
/// @param opmodeId unlock method ID
/// @param unlockName unlock method name
/// @param success success callback
/// @param failure failure callback
- (void)modifyUnlockOpmodeForMemberWithDevId:(NSString *)devId
                                    opmodeId:(NSString *)opmodeId
                                  unlockName:(NSString *)unlockName
                                     success:(nullable ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure;

/// Delete unlock method
/// @param devId Device ID
/// @param isAdmin Is it an administrator?
/// @param lockUserId Lock user ID
/// @param opmodeId Unlock method ID
/// @param firmwareId Device hardware ID
/// @param unlockDpCode dp code corresponding to the unlock method, please refer to the product definition for details
/// @param unlockOpType Unlock method
/// @param success Success callback
/// @param failure Failure callback
- (void)removeUnlockOpmodeForMemberWithDevId:(NSString *)devId
                                     isAdmin:(BOOL)isAdmin
                                  lockUserId:(int)lockUserId
                                    opmodeId:(NSString *)opmodeId
                                  firmwareId:(NSString *)firmwareId
                                unlockDpCode:(NSString *)unlockDpCode
                                unlockOpType:(ThingUnlockOpType)unlockOpType
                                     success:(nullable ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure;

/// Cancel fingerprint entry
/// @param isAdmin Is it an administrator?
/// @param lockUserId Lock user ID
/// @param unlockOpType Unlock mode
/// @param success Success callback
/// @param failure Failure callback
- (void)cancelUnlockOpmodeWithAdmin:(BOOL)isAdmin
                         lockUserId:(int)lockUserId
                       unlockOpType:(ThingUnlockOpType)unlockOpType
                            success:(nullable ThingSuccessBOOL)success
                            failure:(nullable ThingFailureError)failure;

/// Set anti-hijacking
/// @param devId Device ID
/// @param dpId dp point
/// @param unlockId Unlock mode number
/// @param success Success callback
/// @param failure Failure callback
- (void)addHijackingConfigWithDevId:(NSString *)devId
                               dpId:(NSString *)dpId
                           unlockId:(NSString *)unlockId
                            success:(nullable ThingSuccessBOOL)success
                            failure:(nullable ThingFailureError)failure;

/// Remove anti-hijacking settings
/// @param devId device ID
/// @param dpId dp point
/// @param unlockId unlock method number
/// @param success success callback
/// @param failure failure callback
- (void)removeHijackingConfigWithDevId:(NSString *)devId
                                  dpId:(NSString *)dpId
                              unlockId:(NSString *)unlockId
                               success:(nullable ThingSuccessID)success
                               failure:(nullable ThingFailureError)failure;

#pragma mark - Member Manager

/// Family member list
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)getMemberListWithDevId:(NSString *)devId
                       success:(nullable ThingSuccessID)success
                       failure:(nullable ThingFailureError)failure;

/// Create a door lock family member
/// @param homeId Home ID
/// @param requestModel Add member request model
/// @param success Success callback
/// @param failure Failure callback
- (void)addMemberWithHomeId:(long long)homeId
               requestModel:(ThingSmartHomeAddMemberRequestModel *)requestModel
                    success:(ThingSuccessDict)success
                    failure:(ThingFailureError)failure;

/// Delete a single door lock member (including all unlocking methods under the member)
/// @param memberId User ID
/// @param isAdmin Is it an administrator?
/// @param lockUserId Lock user ID
/// @param success Success callback
/// @param failure Failure callback
- (void)removeMemberWithMemberId:(NSString *)memberId
                         isAdmin:(BOOL)isAdmin
                      lockUserId:(int)lockUserId
                         success:(ThingSuccessHandler)success
                         failure:(nullable ThingFailureError)failure;

/// Update door lock family members
/// @param memberRequestModel Family member request model
/// @param success Success callback
/// @param failure Failure callback
- (void)updateMemberWithRequestModel:(ThingSmartHomeMemberRequestModel *)memberRequestModel
                             success:(ThingSuccessHandler)success
                             failure:(ThingFailureError)failure;

/// Get member details
/// @param devId device ID
/// @param userId user ID
/// @param success success callback
/// @param failure failure callback
- (void)getMemberInfoWithDevId:(NSString *)devId
                        userId:(NSString *)userId
                       success:(nullable ThingSuccessID)success
                       failure:(nullable ThingFailureError)failure;

#pragma mark - password
/// Get a list of valid temporary passwords
/// @param devId Device ID
/// @param offset Number of pages
/// @param limit Number of data items per page
/// @param success Success callback
/// @param failure Failure callback
- (void)getPasswordListWithDevId:(NSString *)devId
                          offset:(int)offset
                           limit:(int)limit
                         success:(nullable ThingSuccessID)success
                         failure:(nullable ThingFailureError)failure;

/// Get a list of invalid temporary passwords
/// @param devId Device ID
/// @param offset Number of pages
/// @param limit Number of data items per page
/// @param success Success callback
/// @param failure Failure callback
- (void)getInvalidPasswordListWithDevId:(NSString *)devId
                                 offset:(int)offset
                                  limit:(int)limit
                                success:(nullable ThingSuccessID)success
                                failure:(nullable ThingFailureError)failure;

/// Clear invalid passwords
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)removeInvalidPasswordWithDevId:(NSString *)devId
                               success:(nullable ThingSuccessID)success
                               failure:(nullable ThingFailureError)failure;

/// Get dynamic password
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)getDynamicPasswordWithDevId:(NSString *)devId
                            success:(nullable ThingSuccessID)success
                            failure:(nullable ThingFailureError)failure;

/// Add a temporary password
/// @param devId Device ID
/// @param name Password name
/// @param effectiveTime Effective time
/// @param invalidTime Expiration time
/// @param password Password
/// @param schedule Cycle
/// @param oneTime Is it a one-time password (0 No 1 Yes)
/// @param success Success callback
/// @param failure Failure callback
- (void)addTemporaryPasswordWithDevId:(NSString *)devId
                                 name:(NSString *)name
                        effectiveTime:(NSTimeInterval)effectiveTime
                          invalidTime:(NSTimeInterval)invalidTime
                             password:(NSString *)password
                             schedule:(NSString *)schedule
                              oneTime:(NSInteger)oneTime
                              success:(nullable ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

/// Password rename
/// @param devId device ID
/// @param pwdId password ID
/// @param name password name
/// @param success success callback
/// @param failure failure callback
- (void)updateTemporaryPasswordWithDevId:(NSString *)devId
                                   pwdId:(NSInteger)pwdId
                                    name:(NSString *)name
                                 success:(nullable ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

/// Modify password validity (hardware interaction)
/// @param devId device ID
/// @param pwdId password id
/// @param name password name
/// @param effectiveTime effective time
/// @param invalidTime expiration time
/// @param schedule cycle
/// @param oneTime one-time password (0 no 1 yes)
/// @param success success callback
/// @param failure failure callback
- (void)modifyTemporaryPasswordWithDevId:(NSString *)devId
                                   pwdId:(NSInteger)pwdId
                                    name:(NSString *)name
                           effectiveTime:(NSTimeInterval)effectiveTime
                             invalidTime:(NSTimeInterval)invalidTime
                                schedule:(NSString *)schedule
                                 oneTime:(NSInteger)oneTime
                                 success:(nullable ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

/// Delete temporary password
/// @param devId device ID
/// @param pwdId password id
/// @param name password name
/// @param effectiveTime effective time
/// @param invalidTime expiration time
/// @param oneTime one-time password (0 no 1 yes)
/// @param success success callback
/// @param failure failure callback
- (void)removeTemporaryPasswordWithDevId:(NSString *)devId
                                   pwdId:(NSInteger)pwdId
                                    name:(NSString *)name
                           effectiveTime:(NSTimeInterval)effectiveTime
                             invalidTime:(NSTimeInterval)invalidTime
                                 oneTime:(NSInteger)oneTime
                                 success:(nullable ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

/// Freeze temporary password
/// @param devId device ID
/// @param pwdId password id
/// @param name password name
/// @param effectiveTime effective time
/// @param invalidTime expiration time
/// @param oneTime one-time password (0 no 1 yes)
/// @param success success callback
/// @param failure failure callback
- (void)freezeTemporaryPasswordWithDevId:(NSString *)devId
                                   pwdId:(NSInteger)pwdId
                                    name:(NSString *)name
                           effectiveTime:(NSTimeInterval)effectiveTime
                             invalidTime:(NSTimeInterval)invalidTime
                                 oneTime:(NSInteger)oneTime
                                 success:(nullable ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

/// Unfreeze temporary password
/// @param devId device ID
/// @param pwdId password id
/// @param name password name
/// @param effectiveTime effective time
/// @param invalidTime expiration time
/// @param oneTime one-time password (0 no 1 yes)
/// @param success success callback
/// @param failure failure callback
- (void)unfreezeTemporaryPasswordWithDevId:(NSString *)devId
                                     pwdId:(NSInteger)pwdId
                                      name:(NSString *)name
                             effectiveTime:(NSTimeInterval)effectiveTime
                               invalidTime:(NSTimeInterval)invalidTime
                                   oneTime:(NSInteger)oneTime
                                   success:(nullable ThingSuccessID)success
                                   failure:(nullable ThingFailureError)failure;

#pragma mark - Setting

/// Query the remote door switch status
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchRemoteUnlockTypeWithDevId:(NSString *)devId
                               success:(nullable ThingSuccessID)success
                               failure:(nullable ThingFailureError)failure;

/// Set the remote door opening switch
/// @param devId Device ID
/// @param open Switch status
/// @param success Success callback
/// @param failure Failure callback
- (void)setRemoteUnlockTypeWithDevId:(NSString *)devId
                                open:(BOOL)open
                             success:(nullable ThingSuccessID)success
                             failure:(nullable ThingFailureError)failure;

/// Get remote unlocking permission
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)getRemoteUnlockPermissionValueWithDevId:(NSString *)devId
                                        success:(nullable void(^)(ThingSmartZigbeeLockRemotePermissionModel *model))success
                                        failure:(nullable ThingFailureError)failure;

/// Set remote unlocking permission
/// @param devId Device ID
/// @param remotePermissionType Permission type
/// @param success Success callback
/// @param failure Failure callback
- (void)setRemoteUnlockPermissionValueWithDevId:(NSString *)devId
                           remotePermissionType:(ThingRemotePermissionType)remotePermissionType
                                        success:(nullable ThingSuccessID)success
                                        failure:(nullable ThingFailureError)failure;

/// Query the speaker password activation status
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchRemoteVoiceUnlockWithDevId:(NSString *)devId
                                success:(ThingSuccessID)success
                                failure:(nullable ThingFailureError)failure;

/// Set or cancel the speaker password
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
