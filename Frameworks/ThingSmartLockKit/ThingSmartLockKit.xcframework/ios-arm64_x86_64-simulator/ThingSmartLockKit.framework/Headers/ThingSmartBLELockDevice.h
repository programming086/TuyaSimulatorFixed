
#import <ThingSmartDeviceCoreKit/ThingSmartDevice.h>
#import "ThingSmartLockRecordModel.h"
#import "ThingSmartBLELockRecordModel.h"
#import "ThingSmartBLELockMemberModel.h"
#import "ThingSmartBLELockOpmodeModel.h"
#import "ThingSmartBLELockOpMessageModel.h"
#import "ThingSmartBLELockPasswordModel.h"
#import "ThingSmartBLELockScheduleModel.h"
#import <ThingSmartDeviceKit/ThingSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingMemberTimeType) {
    ThingMemberTimeTypePermanent = 10,
    ThingMemberTimeTypePhase = 20,
};


@class ThingSmartBLELockDevice;
@class ThingSmartBLELockOpMessageModel;
@protocol ThingSmartBLELockDeviceDelegate <ThingSmartDeviceDelegate>

/// Received a callback message for a new unlocking method
///
/// @param device Door lock device
/// @param opMessage Device operation message
- (void)device:(ThingSmartBLELockDevice *)device didReceiveAddOpMessage:(ThingSmartBLELockOpMessageModel *)opMessage;


/// Received callback information for deleting unlocking mode
///
/// @param device Door lock device
/// @param opMessage Device operation message
- (void)device:(ThingSmartBLELockDevice *)device didReceiveDeleteOpMessage:(ThingSmartBLELockOpMessageModel *)opMessage;


/// Received callback message for modifying unlocking mode
///
/// @param device Door lock device
/// @param opMessage Device operation message
- (void)device:(ThingSmartBLELockDevice *)device didReceiveModifyOpMessage:(ThingSmartBLELockOpMessageModel *)opMessage;

/// Create a temporary password callback message
///
/// @param device Door lock device
/// @param model Create an operation result model
- (void)device:(ThingSmartBLELockDevice *)device didReceiveCreatePasswordMessage:(ThingSmartBLELockPasswordModel *)model;

/// Modify the temporary password callback message
///
/// @param device Door lock device
/// @param model Modify the operation result model
- (void)device:(ThingSmartBLELockDevice *)device didReceiveModifyPasswordMessage:(ThingSmartBLELockPasswordModel *)model;

/// Delete temporary password callback message
///
/// @param device Door lock device
/// @param model Delete operation result model
- (void)device:(ThingSmartBLELockDevice *)device didReceiveDeletePasswordMessage:(ThingSmartBLELockPasswordModel *)model;

@end

@interface ThingSmartBLELockDevice : ThingSmartDevice

@property (nonatomic, weak, nullable) id<ThingSmartBLELockDeviceDelegate> delegate;

#pragma mark - Unlock

/// Get dynamic password
/// get lock dynamic password
///
/// @param success Success callback
/// @param failure Failure callback
- (void)getLockDynamicPasswordWithSuccess:(nullable ThingSuccessString)success
                                  failure:(nullable ThingFailureError)failure;


/// Get members of the current account
/// @param devId device ID
/// @param gid family ID
/// @param success success callback
/// @param failure failure callback
- (void)getCurrentMemberDetailWithDevId:(NSString *)devId
                                    gid:(long long)gid
                                success:(nullable ThingSuccessDict)success
                                failure:(nullable ThingFailureError)failure;

/// Get the members of the current account (Pro door lock)
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)getProCurrentMemberDetailWithDevId:(NSString *)devId
                                   success:(nullable ThingSuccessDict)success
                                   failure:(nullable ThingFailureError)failure;

/// Unlock
///
/// @param lockUserId Lock user ID
/// @param success Success callback
/// @param failure Failure callback
- (void)bleUnlock:(NSString *)lockUserId
          success:(ThingSuccessHandler)success
          failure:(ThingFailureError)failure;

/// Lock
///
/// @param success Success callback
/// @param failure Failure callback
- (void)bleManualLock:(ThingSuccessHandler)success
              failure:(ThingFailureError)failure;

///Remote unlocking
///
/// @param success Success callback
/// @param failure Failure callback
- (void)remoteSwitchLock:(ThingSuccessBOOL)success
                 failure:(ThingFailureError)failure;

///Remote lock
///
/// @param success Success callback
/// @param failure Failure callback
- (void)manualLockWithStatus:(ThingSuccessHandler)success
                     failure:(ThingFailureError)failure;

#pragma mark - Connect State

/// If the connection is not successful or disconnected during use, you can call this method to connect (trigger Bluetooth connection)
- (void)autoConnect;

/// Whether the device and the phone have established a Bluetooth connection. If it is no, you can call autoConnect to connect
- (BOOL)isBLEConnected;

/// Query the device connection status (to determine whether the gateway is online)
- (BOOL)isOnline;

#pragma mark - Records

/// Get alarm records
///
/// @param offset Number of pages
/// @param limit Number of data items per page
/// @param success Success callback
/// @param failure Failure callback
- (void)getAlarmRecordListWithOffset:(int)offset
                               limit:(int)limit
                             success:(nullable void(^)(NSArray<ThingSmartLockRecordModel *> *records))success
                             failure:(nullable ThingFailureError)failure;

/// Get the door opening record
///
/// @param offset Number of pages
/// @param limit Number of data items per page
/// @param success Success callback
/// @param failure Failure callback
- (void)getUnlockRecordListWithOffset:(int)offset
                                limit:(int)limit
                              success:(nullable void(^)(NSArray<ThingSmartBLELockRecordModel *> *records))success
                              failure:(nullable ThingFailureError)failure;

/// Query log records
///
/// @param devId Device ID
/// @param logCategories Log categories (operation log: operation Opening record: unlock_record Closing record: close_record Alarm record: alarm_record)
/// @param userIds User list to be filtered (list of user IDs, separated by commas. For example, 12,13)
/// @param onlyShowMediaRecord Whether to only display records with pictures or videos, the default is false to display all records
/// @param startTime Start time (in milliseconds)
/// @param endTime End time (in milliseconds)
/// @param lastRowKey Data key of the previous page
/// @param limit Number of data per page
/// @param success Success callback
/// @param failure Failure callback
- (void)getProUnlockRecordListWithDevId:(NSString *)devId
                          logCategories:(NSString *)logCategories
                                userIds:(NSString *)userIds
                    onlyShowMediaRecord:(BOOL)onlyShowMediaRecord
                              startTime:(NSInteger)startTime
                                endTime:(NSInteger)endTime
                             lastRowKey:(NSString *)lastRowKey
                                  limit:(NSInteger)limit
                                success:(ThingSuccessID)success
                                failure:(nullable ThingFailureError)failure;

#pragma mark - Member Manager

/// Get the door lock member list
///
/// @param devId device ID
/// @param success success callback
/// @param failure failure callback
- (void)getProLockMemberListWithDevId:(NSString *)devId
                              success:(ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

/// Create a door lock family member
///
/// @param homeId Family ID
/// @param requestModel Add member request model
/// @param success Success callback
/// @param failure Failure callback
- (void)createProLockMemberWithHomeId:(long long)homeId
                         requestModel:(ThingSmartHomeAddMemberRequestModel *)requestModel
                              success:(ThingSuccessDict)success
                              failure:(ThingFailureError)failure;

/// Delete a single door lock member
///
/// @param userId User ID
/// @param isAdmin Whether it is an administrator
/// @param success Success callback
/// @param failure Failure callback
- (void)removeProLockMemberWithUserId:(NSString *)userId
                              isAdmin:(BOOL)isAdmin
                              success:(ThingSuccessHandler)success
                              failure:(nullable ThingFailureError)failure;


/// Update door lock family members
///
/// @param memberRequestModel Family member request model
/// @param success Success callback
/// @param failure Failure callback
- (void)updateProLockMemberInfoWithRequestModel:(ThingSmartHomeMemberRequestModel *)memberRequestModel
                                        success:(ThingSuccessHandler)success
                                        failure:(ThingFailureError)failure;

/// Modify the validity period of a single member
///
/// @param devId Device ID
/// @param memberId User ID
/// @param offlineUnlock Whether offline unlocking is supported
/// @param isAdmin Whether it is an administrator
/// @param effectiveDate Effective date
/// @param invalidDate Expiration date
/// @param scheduleInfo Time information
/// @param success Success callback
/// @param failure Failure callback
- (void)updateProLockMemberTimeWithDevId:(NSString *)devId
                                memberId:(NSString *)memberId
                           offlineUnlock:(BOOL)offlineUnlock
                                 isAdmin:(BOOL)isAdmin
                           effectiveDate:(nullable NSDate *)effectiveDate
                             invalidDate:(nullable NSDate *)invalidDate
                                schedule:(ThingSmartBLELockTimeScheduleInfo *)scheduleInfo
                                 success:(ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

/// Add a new door lock member
///
/// @param userName Member name
/// @param allowUnlock Whether to allow Bluetooth unlocking
/// @param timeType Timeliness, permanent or time period
/// @param effectiveDate Effective time
/// @param invalidDate Expiration time
/// @param success Success callback
/// @param failure Failure callback
- (void)addMemberWithUserName:(NSString *)userName
                  allowUnlock:(BOOL)allowUnlock
                     timeType:(ThingMemberTimeType)timeType
                effectiveDate:(NSDate *)effectiveDate
                  invalidDate:(NSDate *)invalidDate
                      success:(nullable ThingSuccessBOOL)success
                      failure:(nullable ThingFailureError)failure;


/// Update door lock member information
///
/// @param userName member name
/// @param memberId member id
/// @param allowUnlock whether to allow Bluetooth unlocking
/// @param timeType timeliness, permanent or time period
/// @param effectiveDate effective date
/// @param invalidDate invalid date
/// @param success success callback
/// @param failure failure callback
- (void)updateMemberWithUserName:(NSString *)userName
                        memberId:(NSString *)memberId
                     allowUnlock:(BOOL)allowUnlock
                        timeType:(ThingMemberTimeType)timeType
                   effectiveDate:(NSDate *)effectiveDate
                     invalidDate:(NSDate *)invalidDate
                         success:(nullable ThingSuccessBOOL)success
                         failure:(nullable ThingFailureError)failure;


/// Delete member
///
/// @param memberId member id
/// @param success success callback
/// @param failure failure callback
- (void)removeMemberWithMemberId:(NSString *)memberId
                         success:(nullable ThingSuccessBOOL)success
                         failure:(nullable ThingFailureError)failure;


/// Get the door lock member list
///
/// @param success Success callback
/// @param failure Failure callback
- (void)getMemberListWithSuccess:(nullable void(^)(NSArray<ThingSmartBLELockMemberModel *> *members))success
                         failure:(ThingFailureError)failure;



#pragma mark - password manager

/// Get door lock synchronization data
///
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)getSyncBatchDataWithDevId:(NSString *)devId
                          success:(ThingSuccessID)success
                          failure:(nullable ThingFailureError)failure;

/// Send synchronization data (only need to call once)
///
/// @param success Success callback
/// @param failure Failure callback
- (void)publishSyncBatchDataSuccess:(ThingSuccessHandler)success
                            failure:(ThingFailureError)failure;

/// Get panel configuration information, password type
///
/// @param productId product ID
/// @param options query items (uiContent, cloudDp, powerCode)
/// @param success success callback
/// @param failure failure callback
- (void)getLockDeviceConfigWithProductId:(NSString *)productId
                                 options:(NSString *)options
                                 success:(ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

/// Add unlimited password, single password, clear code (clear all)
///
/// @param devId device ID
/// @param pwdType password type (0. multiple times 1. single time 9. clear password)
/// @param gmtStart start time (non-multiple passwords temporarily pass 0)
/// @param gmtExpired end time (non-multiple passwords temporarily pass 0)
/// @param pwdName password name
/// @param success success callback
/// @param failure failure callback
- (void)getOfflinePasswordWithDevId:(NSString *)devId
                            pwdType:(NSString *)pwdType
                           gmtStart:(NSInteger)gmtStart
                         gmtExpired:(NSInteger)gmtExpired
                            pwdName:(NSString *)pwdName
                            success:(ThingSuccessID)success
                            failure:(nullable ThingFailureError)failure;

/// Add time-limited password, one-time password, clear code (clear all)
///
/// @param devId device ID
/// @param pwdType password type (0. multiple times 1. single time 9. clear password)
/// @param gmtStart start time
/// @param gmtExpired end time
/// @param pwdName password name
/// @param success success callback
/// @param failure failure callback
- (void)getProOfflinePasswordWithDevId:(NSString *)devId
                               pwdType:(NSString *)pwdType
                              gmtStart:(NSInteger)gmtStart
                            gmtExpired:(NSInteger)gmtExpired
                               pwdName:(NSString *)pwdName
                               success:(ThingSuccessID)success
                               failure:(nullable ThingFailureError)failure;

/// Add clear code (clear single)
///
/// @param devId device ID
/// @param pwdId password number
/// @param success success callback
/// @param failure failure callback
- (void)getSingleRevokeOfflinePasswordWithDevId:(NSString *)devId
                                          pwdId:(NSInteger )pwdId
                                        success:(ThingSuccessID)success
                                        failure:(nullable ThingFailureError)failure;

/// Add clear code (clear single)
///
/// @param devId device ID
/// @param unlockBindingId password authorization number
/// @param name offline deletion password name
/// @param success success callback
/// @param failure failure callback
- (void)getProSingleRevokeOfflinePasswordWithDevId:(NSString *)devId
                                   unlockBindingId:(NSInteger )unlockBindingId
                                              name:(NSString *)name
                                           success:(ThingSuccessID)success
                                           failure:(nullable ThingFailureError)failure;

/// Temporary password parameter validity check
///
/// @param devId Device ID
/// @param name Password name
/// @param effectiveTime Effective time
/// @param invalidTime Expiration time
/// @param password Password
/// @param schedule Cycle
/// @param success Success callback
/// @param failure Failure callback
- (void)validateCustomPasswordWithDevId:(NSString *)devId
                                   name:(NSString *)name
                          effectiveTime:(NSInteger)effectiveTime
                            invalidTime:(NSInteger)invalidTime
                               password:(NSString *)password
                               schedule:(ThingSmartBLELockScheduleList *)schedule
                                success:(ThingSuccessID)success
                                failure:(nullable ThingFailureError)failure;

/// Temporary password parameter validity check
///
/// @param devId Device ID
/// @param name Password name
/// @param unlockBindingId Temporary password number (must be passed when updating)
/// @param effectiveTime Effective time
/// @param invalidTime Expiration time
/// @param password Password
/// @param schedule Cycle
/// @param success Success callback
/// @param failure Failure callback
- (void)validateProCustomPasswordWithDevId:(NSString *)devId
                                      name:(NSString *)name
                           unlockBindingId:(NSInteger)unlockBindingId
                             effectiveTime:(NSInteger)effectiveTime
                               invalidTime:(NSInteger)invalidTime
                                  password:(NSString *)password
                                  schedule:(NSString *)schedule
                                   success:(ThingSuccessID)success
                                   failure:(nullable ThingFailureError)failure;

/// Add a custom password
///
/// @param devId Device ID
/// @param name Password name
/// @param effectiveTime Effective time
/// @param invalidTime Expiration time
/// @param password Password
/// @param schedule Cycle
/// @param availTime Available times. 0: Permanent 1: One-time
/// @param sn Temporary password number
/// @param success Success callback
/// @param failure Failure callback
- (void)getCustomOnlinePasswordWithDevId:(NSString *)devId
                                    name:(NSString *)name
                           effectiveTime:(NSInteger)effectiveTime
                             invalidTime:(NSInteger)invalidTime
                                password:(NSString *)password
                                schedule:(ThingSmartBLELockScheduleList *)schedule
                               availTime:(NSInteger)availTime
                                      sn:(NSInteger)sn
                                 success:(ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

/// Add a custom password
///
/// @param devId Device ID
/// @param name Password name
/// @param password Password content
/// @param effectiveTime Effective time
/// @param invalidTime Expiration time
/// @param availTime Available times
/// @param sn Temporary password number
/// @param schedule Cycle
/// @param success Success callback
/// @param failure Failure callback
- (void)getProCustomOnlinePasswordWithDevId:(NSString *)devId
                                       name:(NSString *)name
                                   password:(NSString *)password
                              effectiveTime:(NSInteger)effectiveTime
                                invalidTime:(NSInteger)invalidTime
                                  availTime:(NSInteger)availTime
                                         sn:(NSInteger)sn
                                   schedule:(ThingSmartBLELockScheduleList *)schedule
                                    success:(ThingSuccessID)success
                                    failure:(nullable ThingFailureError)failure;

/// Online temporary password list
///
/// @param devId Device ID
/// @param availTime Number of times available
/// @param success Success callback
/// @param failure Failure callback
- (void)getOnlinePasswordListWithDevId:(NSString *)devId
                             availTime:(NSInteger)availTime
                               success:(ThingSuccessID)success
                               failure:(nullable ThingFailureError)failure;

/// Offline temporary password list
///
/// @param devId Device ID
/// @param pwdType Password type, 0. Multiple-use password 1. Single-use password 8. Delete a single password 9. Clear code
/// @param status Password status, 1. Valid 0. Invalid
/// @param offset Page number
/// @param limit Number of records (default 50)
/// @param success Success callback
/// @param failure Failure callback
- (void)getOfflinePasswordListWithDevId:(NSString *)devId
                                pwdType:(NSString *)pwdType
                                 status:(NSInteger)status
                                 offset:(NSInteger)offset
                                  limit:(NSInteger)limit
                                success:(ThingSuccessID)success
                                failure:(nullable ThingFailureError)failure;

/// Temporary password list
///
/// @param devId Device ID
/// @param authTypes Authorization type
/// @param success Success callback
/// @param failure Failure callback
- (void)getProPasswordListWithDevId:(NSString *)devId
                          authTypes:(NSArray *)authTypes
                            success:(ThingSuccessID)success
                            failure:(nullable ThingFailureError)failure;

/// Get the list of offline unlimited passwords that can be assigned
///
/// @param devId device ID
/// @param success success callback
/// @param failure failure callback
- (void)getSingleRevokePasswordListWithDevId:(NSString *)devId
                                     success:(ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure;

/// Delete online temporary password
///
/// @param devId device ID
/// @param pwdId password number
/// @param sn hardware ID
/// @param success success callback
/// @param failure failure callback
- (void)deleteOnlinePasswordWithDevId:(NSString *)devId
                                pwdId:(NSInteger )pwdId
                                   sn:(NSInteger)sn
                              success:(ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

/// Delete online temporary password
///
/// @param devId Device ID
/// @param unlockBindingId Temporary password serial number
/// @param sn Hardware ID
/// @param success Success callback
/// @param failure Failure callback
- (void)deleteProOnlinePasswordWithDevId:(NSString *)devId
                         unlockBindingId:(NSInteger )unlockBindingId
                                      sn:(NSInteger)sn
                                 success:(ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

/// Modify the information of online password (time limit)
///
/// @param devId device ID
/// @param name password name
/// @param pwdId password number
/// @param effectiveTime effective time
/// @param invalidTime expiration time
/// @param password password
/// @param schedule cycle
/// @param availTime available times
/// @param sn hardware ID
/// @param success success callback
/// @param failure failure callback
- (void)updateOnlinePasswordWithDevId:(NSString *)devId
                                 name:(NSString *)name
                             password:(NSString *)password
                                pwdId:(NSInteger )pwdId
                        effectiveTime:(NSInteger)effectiveTime
                          invalidTime:(NSInteger)invalidTime
                             schedule:(ThingSmartBLELockScheduleList *)schedule
                                   sn:(NSInteger)sn
                            availTime:(NSInteger)availTime
                              success:(ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

/// Modify online password information (time limit)
///
/// @param devId Device ID
/// @param name Password name
/// @param password Password content
/// @param unlockBindingId Password number
/// @param effectiveTime Effective time
/// @param invalidTime Expiration time
/// @param phase 2. Normal 4. Freeze
/// @param schedule Cycle
/// @param success Success callback
/// @param failure Failure callback
- (void)updateProOnlinePasswordWithDevId:(NSString *)devId
                                    name:(NSString *)name
                                password:(NSString *)password
                         unlockBindingId:(NSInteger )unlockBindingId
                           effectiveTime:(NSInteger)effectiveTime
                             invalidTime:(NSInteger)invalidTime
                                   phase:(NSInteger)phase
                                schedule:(ThingSmartBLELockScheduleList *)schedule
                                      sn:(NSInteger)sn
                                 success:(ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

/// Get the common password list
///
/// @param success Success callback
/// @param failure Failure callback
- (void)getPasswordListWithSuccess:(nullable void(^)(NSArray<ThingSmartBLELockOpmodeModel *> *models))success
                           failure:(nullable ThingFailureError)failure;


/// Add a common password, unlimited use by default, unlimited times
///
/// @param memberId The ID of the member to be added
/// @param password Password
/// @param unlockName Password name
/// @param needHijacking Whether to set anti-hijacking
/// @param success Success callback
/// @param failure Failure callback
- (void)addPasswordForMemberWithMemberId:(NSString *)memberId
                                password:(NSString *)password
                              unlockName:(NSString *)unlockName
                           needHijacking:(BOOL)needHijacking
                                 success:(nullable ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

/// Delete common password
///
/// @param opmodeModel password model
/// @param success success callback
/// @param failure failure callback
- (void)removePasswordForMemberWithOpmodeModel:(ThingSmartBLELockOpmodeModel *)opmodeModel
                                       success:(ThingSuccessHandler)success
                                       failure:(ThingFailureError)failure;


#pragma mark - finger print manager

/// Add fingerprint
///
/// @param memberId The member ID to be added,
/// @param unlockName Password name
/// @param needHijacking Whether to set anti-hijacking
/// @param success Success callback
/// @param failure Failure callback
- (void)addFingerPrintForMemberWithMemberId:(NSString *)memberId
                                 unlockName:(NSString *)unlockName
                              needHijacking:(BOOL)needHijacking
                                    success:(ThingSuccessID)success
                                    failure:(ThingFailureError)failure;

/// Get the fingerprint unlock password list
///
/// @param success Success callback
/// @param failure Failure callback
- (void)getFingerPrintListWithSuccess:(nullable void(^)(NSArray<ThingSmartBLELockOpmodeModel *> *models))success
                              failure:(nullable ThingFailureError)failure;

/// Delete fingerprint password
///
/// @param opmodeModel password model
/// @param success success callback
/// @param failure failure callback
- (void)removeFingerPrintForMemberWithOpmodeModel:(ThingSmartBLELockOpmodeModel *)opmodeModel
                                          success:(ThingSuccessHandler)success
                                          failure:(ThingFailureError)failure;

/// Cancel fingerprint entry
///
/// @param isAdmin Is it an administrator?
/// @param lockUserId Lock user ID
/// @param success Success callback
/// @param failure Failure callback
- (void)cancelUnlockOpmodeForFingerWithAdmin:(BOOL)isAdmin
                                  lockUserId:(int)lockUserId
                                     success:(nullable ThingSuccessBOOL)success
                                     failure:(nullable ThingFailureError)failure;

#pragma mark - card manager

/// Set the card unlocking method
///
/// @param memberId member id
/// @param unlockName unlock name
/// @param needHijacking whether to set anti-hijacking
/// @param success success callback
/// @param failure failure callback
- (void)addCardForMemberWithMemberId:(NSString *)memberId
                          unlockName:(NSString *)unlockName
                       needHijacking:(BOOL)needHijacking
                             success:(ThingSuccessID)success
                             failure:(ThingFailureError)failure;

/// Get the card unlock password list
///
/// @param success Success callback
/// @param failure Failure callback
- (void)getCardListWithSuccess:(nullable void(^)(NSArray<ThingSmartBLELockOpmodeModel *> *models))success
                       failure:(nullable ThingFailureError)failure;

/// Delete card password
///
/// @param opmodeModel password model
/// @param success success callback
/// @param failure failure callback
- (void)removeCardForMemberWithOpmodeModel:(ThingSmartBLELockOpmodeModel *)opmodeModel
                                   success:(ThingSuccessHandler)success
                                   failure:(ThingFailureError)failure;

#pragma mark - op mode manager

/// Add password verification for unlocking method
///
/// @param devId device id
/// @param password unlocking information
/// @param success success callback
/// @param failure failure callback
- (void)validateOpModePasswordWithDevId:(NSString *)devId
                               password:(NSString *)password
                                success:(ThingSuccessID)success
                                failure:(nullable ThingFailureError)failure;

/// Added unlocking method
///
/// @param memberId The member ID to be added,
/// @param isAdmin Whether it is an administrator
/// @param unlockDpCode The dp code corresponding to the unlocking method, please refer to the product definition for details
/// @param unlockOpType Unlocking method
/// @param unlockName Unlocking name
/// @param effectiveDate Effective time
/// @param invalidDate Expiration time
/// @param times Use times 0: Permanently valid, 0x01- 0xFE: xx times valid, 0xFF: Invalid
/// @param dataLength Data length, generally 1
/// @param dataContent Data content, generally @"1", length and content length must be consistent
/// @param timeout Timeout, the device may not fully respond, and block callback will be performed after a certain time
/// @param needHijacking Whether to set anti-hijacking
/// @param success Success callback
/// @param failure Failure callback
- (void)addUnlockOpmodeForMemberWithMemberId:(NSString *)memberId
                                     isAdmin:(BOOL)isAdmin
                                unlockDpCode:(NSString *)unlockDpCode
                                unlockOpType:(ThingUnlockOpType)unlockOpType
                                  unlockName:(NSString *)unlockName
                               effectiveDate:(nullable NSDate *)effectiveDate
                                 invalidDate:(nullable NSDate *)invalidDate
                                       times:(int)times
                                  dataLength:(int)dataLength
                                 dataContent:(NSString *)dataContent
                                     timeout:(NSTimeInterval)timeout
                               needHijacking:(BOOL)needHijacking
                                     success:(nullable ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure;

/// Added unlocking method (Pro doorlock)
///
/// @param memberId The member ID to be added,
/// @param isAdmin Whether it is an administrator
/// @param unlockDpCode The dp code corresponding to the unlocking method, please refer to the product definition for details
/// @param unlockOpType Unlocking method
/// @param unlockName Unlocking name
/// @param effectiveDate Effective time
/// @param invalidDate Expiration time
/// @param times Use times 0: Permanently valid, 0x01- 0xFE: xx times valid, 0xFF: Invalid
/// @param dataLength Data length, generally 1
/// @param dataContent Data content, generally @"1", length and content length must be consistent
/// @param timeout Timeout, the device may not fully respond, and block callback will be performed after a certain time
/// @param needHijacking Whether to set anti-hijacking
/// @param appSend Whether to send app notification
/// @param success Success callback
/// @param failure Failure callback
- (void)addProUnlockOpModeForMemberWithMemberId:(NSString *)memberId
                                        isAdmin:(BOOL)isAdmin
                                   unlockDpCode:(NSString *)unlockDpCode
                                   unlockOpType:(ThingUnlockOpType)unlockOpType
                                     unlockName:(NSString *)unlockName
                                  effectiveDate:(nullable NSDate *)effectiveDate
                                    invalidDate:(nullable NSDate *)invalidDate
                                          times:(int)times
                                     dataLength:(int)dataLength
                                    dataContent:(NSString *)dataContent
                                        timeout:(NSTimeInterval)timeout
                                  needHijacking:(BOOL)needHijacking
                                        appSend:(BOOL)appSend
                                        success:(nullable ThingSuccessID)success
                                        failure:(nullable ThingFailureError)failure;

/// Modify the unlocking method (involving interaction with hardware)
///
/// @param memberId The member id to be modified,
/// @param opmodeId The model id of the unlocking method
/// @param isAdmin Is it an administrator?
/// @param firmwareId Hardware id
/// @param unlockDpCode The dp code corresponding to the unlocking method, please refer to the product definition for details
/// @param unlockOpType Unlocking method
/// @param unlockName Unlocking name
/// @param effectiveDate Effective time
/// @param invalidDate Invalid time
/// @param times Use times 0: Permanently valid, 0x01- 0xFE: xx times valid, 0xFF: Invalid
/// @param dataLength Data length, generally 1
/// @param dataContent Data content, generally @"1", length and content length must be consistent
/// @param timeout timeout, the device may not fully respond, and a block callback will be performed after a certain period of time
/// @param needHijacking whether to set anti-hijacking
/// @param success success callback
/// @param failure failure callback
- (void)modifyUnlockOpmodeForMemberWithMemberId:(NSString *)memberId
                                       opmodeId:(NSString *)opmodeId
                                        isAdmin:(BOOL)isAdmin
                                     firmwareId:(int)firmwareId
                                   unlockDpCode:(NSString *)unlockDpCode
                                   unlockOpType:(ThingUnlockOpType)unlockOpType
                                     unlockName:(NSString *)unlockName
                                  effectiveDate:(nullable NSDate *)effectiveDate
                                    invalidDate:(nullable NSDate *)invalidDate
                                          times:(int)times
                                     dataLength:(int)dataLength
                                    dataContent:(NSString *)dataContent
                                        timeout:(NSTimeInterval)timeout
                                  needHijacking:(BOOL)needHijacking
                                        success:(nullable ThingSuccessBOOL)success
                                        failure:(nullable ThingFailureError)failure;

/// Modify the unlocking method (Pro doorlock)
///
/// @param memberId The member id to be modified,
/// @param opmodeId The model id of the unlocking method
/// @param isAdmin Is it an administrator?
/// @param firmwareId Hardware id
/// @param unlockDpCode The dp code corresponding to the unlocking method, please refer to the product definition for details
/// @param unlockOpType Unlocking method
/// @param unlockName Unlocking name
/// @param effectiveDate Effective time
/// @param invalidDate Invalid time
/// @param times Use times 0: Permanently valid, 0x01- 0xFE: xx times valid, 0xFF: Invalid
/// @param dataLength Data length, generally 1
/// @param dataContent Data content, generally @"1", length and content length must be consistent
/// @param timeout Timeout period, the device may not fully respond, and a block callback will be performed after a certain period of time
/// @param needHijacking Whether to set anti-hijacking
/// @param appSend Whether to send app notifications
/// @param success Success callback
/// @param failure Failure callback
- (void)modifyProUnlockOpModeForMemberWithMemberId:(NSString *)memberId
                                          opmodeId:(NSString *)opmodeId
                                           isAdmin:(BOOL)isAdmin
                                        firmwareId:(int)firmwareId
                                      unlockDpCode:(NSString *)unlockDpCode
                                      unlockOpType:(ThingUnlockOpType)unlockOpType
                                        unlockName:(NSString *)unlockName
                                     effectiveDate:(nullable NSDate *)effectiveDate
                                       invalidDate:(nullable NSDate *)invalidDate
                                             times:(int)times
                                        dataLength:(int)dataLength
                                       dataContent:(NSString *)dataContent
                                           timeout:(NSTimeInterval)timeout
                                     needHijacking:(BOOL)needHijacking
                                           appSend:(BOOL)appSend
                                           success:(nullable ThingSuccessBOOL)success
                                           failure:(nullable ThingFailureError)failure;

/// Modify basic unlocking information (no hardware interaction involved)
///
/// @param memberId member id
/// @param opmodeId unlocking method id
/// @param unlockName unlocking information
/// @param success success callback
/// @param failure failure callback
- (void)updateMemberOpmodeWithMemberId:(NSString *)memberId
                              opmodeId:(NSString *)opmodeId
                            unlockName:(NSString *)unlockName
                               success:(nullable ThingSuccessBOOL)success
                               failure:(nullable ThingFailureError)failure;

/// Modify basic information of unlocking method (no hardware interaction involved, Pro door lock)
///
/// @param devId device id
/// @param opModeId unlocking method id
/// @param unlockName unlocking method name
/// @param needHijacking whether to set to anti-hijacking
/// @param appSend whether to send app notification
/// @param success success callback
/// @param failure failure callback
- (void)updateProMemberOpmodeWithDevId:(NSString *)devId
                              opModeId:(NSString *)opModeId
                            unlockName:(NSString *)unlockName
                         needHijacking:(BOOL )needHijacking
                               appSend:(BOOL)appSend
                               success:(ThingSuccessID)success
                               failure:(nullable ThingFailureError)failure;

/// Delete unlocking method
///
/// @param opmodeModel Unlocking mode
/// @param isAdmin Is it an administrator?
/// @param unlockDpCode The dp code corresponding to the unlocking method, please refer to the product definition for details
/// @param unlockOpType Unlocking method
/// @param timeout Timeout, the device may not fully respond, and a block callback will be performed after a certain time
/// @param success Success callback
/// @param failure Failure callback
- (void)removeUnlockOpmodeForMemberWithOpmodeModel:(ThingSmartBLELockOpmodeModel *)opmodeModel
                                           isAdmin:(BOOL)isAdmin
                                      unlockDpCode:(NSString *)unlockDpCode
                                      unlockOpType:(ThingUnlockOpType)unlockOpType
                                           timeout:(NSTimeInterval)timeout
                                           success:(ThingSuccessHandler)success
                                           failure:(ThingFailureError)failure;

/// Delete unlocking method (Pro doorlock)
///
/// @param opmodeModel Unlocking mode
/// @param isAdmin Is it an administrator?
/// @param unlockDpCode The dp code corresponding to the unlocking method, please refer to the product definition for details
/// @param unlockOpType Unlocking method
/// @param timeout Timeout, the device may not fully respond, and a block callback will be performed after a certain time
/// @param success Success callback
/// @param failure Failure callback
- (void)removeProUnlockOpModeForMemberWithOpmodeModel:(ThingSmartBLELockOpmodeModel *)opmodeModel
                                              isAdmin:(BOOL)isAdmin
                                         unlockDpCode:(NSString *)unlockDpCode
                                         unlockOpType:(ThingUnlockOpType)unlockOpType
                                              timeout:(NSTimeInterval)timeout
                                              success:(ThingSuccessHandler)success
                                              failure:(ThingFailureError)failure;

/// Get the details of a single unlocking method
///
/// @param devId Device ID
/// @param opModeId Unlocking method serial number
/// @param success Success callback
/// @param failure Failure callback
- (void)getProUnlockOpModeDetailWithDevId:(NSString *)devId
                                 opModeId:(NSString *)opModeId
                                  success:(ThingSuccessID)success
                                  failure:(nullable ThingFailureError)failure;

/// Initiate the unlocking method of synchronized door locks
///
/// @param devId device ID
/// @param dpIds list of unlocking method types to be synchronized (array of numbers)
/// @param success success callback
/// @param failure failure callback
- (void)syncDataWithDevId:(NSString *)devId
                    dpIds:(NSArray<NSString *> *)dpIds
                  success:(ThingSuccessID)success
                  failure:(nullable ThingFailureError)failure;

/// Determine whether there is an unlocking method that needs to be assigned
///
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)isProNeedAllocUnlockOpModeWithDevId:(NSString *)devId
                                    success:(ThingSuccessID)success
                                    failure:(nullable ThingFailureError)failure;

/// Get the list of unlocking methods bound to the member
///
/// @param devId device ID
/// @param userId member ID
/// @param success success callback
/// @param failure failure callback
- (void)getProBoundUnlockOpModeListWithDevId:(NSString *)devId
                                      userId:(NSString *)userId
                                     success:(ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure;
/// Get the list of unlocking methods that are not bound to members
///
/// @param devId device ID
/// @param success success callback
/// @param failure failure callback
- (void)getProUnboundUnlockOpModeListWithDevId:(NSString *)devId
                                       success:(ThingSuccessID)success
                                       failure:(nullable ThingFailureError)failure;

/// Unlocking method assigned to a person
///
/// @param devId device ID
/// @param userId member ID
/// @param unlockIds unlocking method id
/// @param success success callback
/// @param failure failure callback
- (void)allocProUnlockOpModeWithDevId:(NSString *)devId
                               userId:(NSString *)userId
                            unlockIds:(NSString *)unlockIds
                              success:(ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

#pragma mark - Setting

/// Query the remote door switch status
///
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)fetchRemoteUnlockTypeWithDevId:(NSString *)devId
                               success:(nullable ThingSuccessID)success
                               failure:(nullable ThingFailureError)failure;

/// Set the remote door opener
///
/// @param devId device ID
/// @param propKvs key-value pair, key: UNLOCK_PHONE_REMOTE
/// @param success success callback
/// @param failure failure callback
- (void)setRemoteUnlockTypeWithDevId:(NSString *)devId
                             propKvs:(NSString *)propKvs
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

/// Set anti-hijacking
///
/// @param devId device ID
/// @param dpId dp point
/// @param dpValue dp value
/// @param success success callback
/// @param failure failure callback
- (void)addHijackingConfigWithDevId:(NSString *)devId
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

@end

NS_ASSUME_NONNULL_END
