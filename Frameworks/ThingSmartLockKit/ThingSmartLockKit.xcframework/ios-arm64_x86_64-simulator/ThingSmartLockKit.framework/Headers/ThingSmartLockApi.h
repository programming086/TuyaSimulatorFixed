
#import <ThingSmartNetworkKit/ThingSmartNetworkKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartLockApi : ThingSmartRequest

/// Get the device rotation angle
///
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)getDeviceRotateWithDevId:(NSString *)devId
                         success:(ThingSuccessID)success
                         failure:(nullable ThingFailureError)failure;

/// Get the album list
///
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)getAlbumListWithDevId:(NSString *)devId
                      success:(ThingSuccessID)success
                      failure:(nullable ThingFailureError)failure;

/// Query the most recent log record
///
/// @param devId Device ID
/// @param userType User system type, 0 is home system 1 is panel user system
/// @param userId User ID
/// @param success Success callback
/// @param failure Failure callback
- (void)getLatestDeviceLogWithDevId:(NSString *)devId
                           userType:(NSInteger)userType
                             userId:(NSString *)userId
                            success:(ThingSuccessID)success
                            failure:(nullable ThingFailureError)failure;

/// Query log records
///
/// @param devId Device ID
/// @param logCategories Log categories
/// @param userIds User list to be filtered
/// @param onlyShowMediaRecord Whether to filter records with images
/// @param startTime Start time
/// @param endTime End time
/// @param lastRowKey Query paging parameters
/// @param userType User system type, empty default is home user system 0 home system 1 panel user system
/// @param userId Panel user number
/// @param limit Number of data per page
/// @param success Success callback
/// @param failure Failure callback
- (void)getDeviceLogsWithDevId:(NSString *)devId
                 logCategories:(NSString *)logCategories
                       userIds:(NSString *)userIds
           onlyShowMediaRecord:(BOOL)onlyShowMediaRecord
                     startTime:(NSInteger)startTime
                       endTime:(NSInteger)endTime
                    lastRowKey:(NSString *)lastRowKey
                      userType:(NSInteger)userType
                        userId:(NSString *)userId
                         limit:(NSInteger)limit
                       success:(ThingSuccessID)success
                       failure:(nullable ThingFailureError)failure;

/// Bind history records to people
///
/// @param devId device ID
/// @param userId user ID
/// @param unlockIds unlock method list
/// @param success success callback
/// @param failure failure callback
- (void)bindHistoryLogToUserWithDevId:(NSString *)devId
                               userId:(NSString *)userId
                            unlockIds:(NSArray *)unlockIds
                              success:(ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

/// Set anti-hijacking
///
/// @param devId device ID
/// @param dpId dpId
/// @param dpValue dp value
/// @param success success callback
/// @param failure failure callback
- (void)setHijackingConfigWithDevId:(NSString *)devId
                               dpId:(NSString *)dpId
                            dpValue:(NSString *)dpValue
                            success:(ThingSuccessBOOL)success
                            failure:(nullable ThingFailureError)failure;

/// Remove anti-hijacking settings
///
/// @param devId device ID
/// @param dpId dpId
/// @param dpValue dp value
/// @param success success callback
/// @param failure failure callback
- (void)removeHijackingConfigWithDevId:(NSString *)devId
                                  dpId:(NSString *)dpId
                               dpValue:(NSString *)dpValue
                               success:(ThingSuccessID)success
                               failure:(nullable ThingFailureError)failure;

/// device supports cloud storage
///
/// @param devId device ID
/// @param success success callback
/// @param failure failure callback
- (void)isDeviceSupportsCloudStorageWithDevId:(NSString *)devId
                                      success:(ThingSuccessBOOL)success
                                      failure:(nullable ThingFailureError)failure;

/**
************************************************************************************************************************
********************************************************************************************************************
* Offline password interface
****************************************************************************************************************
********************************************************************************************************************
*/

/// Determine whether the current type of password can continue to be obtained
///
/// @param devId device ID
/// @param pwdType password type
/// @param success success callback
/// @param failure failure callback
- (void)isCurrentOfflinePasswordAvailableWithDevId:(NSString *)devId
                                           pwdType:(NSInteger)pwdType
                                           success:(ThingSuccessID)success
                                           failure:(nullable ThingFailureError)failure;

/// Get offline password list
///
/// @param devId device ID
/// @param pwdType password type
/// @param status password status
/// @param offset page number
/// @param limit number of records (default 50)
/// @param success success callback
/// @param failure failure callback
- (void)getOfflinePasswordListWithDevId:(NSString *)devId
                                pwdType:(NSString *)pwdType
                                 status:(NSInteger)status
                                 offset:(NSInteger)offset
                                  limit:(NSInteger)limit
                                success:(ThingSuccessID)success
                                failure:(nullable ThingFailureError)failure;

/// Get the unlimited offline password that can be assigned
///
/// @param devId device ID
/// @param success success callback
/// @param failure failure callback
- (void)getReavailableOfflinePasswordWithDevId:(NSString *)devId
                                       success:(ThingSuccessID)success
                                       failure:(nullable ThingFailureError)failure;

/// Add offline temporary password
///
/// @param devId device ID
/// @param pwdType password type
/// @param gmtStart start time
/// @param gmtExpired end time
/// @param pwdName password name
/// @param countryCode mobile phone number country code
/// @param mobile mobile phone number
/// @param success success callback
/// @param failure failure callback
- (void)addPhotoLockOfflinePasswordWithDevId:(NSString *)devId
                                     pwdType:(NSString *)pwdType
                                    gmtStart:(NSInteger)gmtStart
                                  gmtExpired:(NSInteger)gmtExpired
                                     pwdName:(NSString *)pwdName
                                 countryCode:(NSString *)countryCode
                                      mobile:(NSString *)mobile
                                     success:(ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure;

/// Set offline password name
///
/// @param devId device ID
/// @param pwdId password number
/// @param pwdName password name
/// @param mobile mobile phone number
/// @param success success callback
/// @param failure failure callback
- (void)setPhotoLockOfflinePasswordNameWithDevId:(NSString *)devId
                                           pwdId:(NSInteger )pwdId
                                         pwdName:(NSString *)pwdName
                                          mobile:(NSString *)mobile
                                         success:(ThingSuccessID)success
                                         failure:(nullable ThingFailureError)failure;

/// Get the clear code of a temporary offline password
///
/// @param devId device ID
/// @param pwdId password number
/// @param success success callback
/// @param failure failure callback
- (void)getPhotoLockOfflineEmptyCodeWithDevId:(NSString *)devId
                                        pwdId:(NSInteger )pwdId
                                      success:(ThingSuccessID)success
                                      failure:(nullable ThingFailureError)failure;

/// Add offline temporary password
///
/// @param devId device ID
/// @param pwdType password type
/// @param gmtStart start time
/// @param gmtExpired end time
/// @param pwdName password type (0. multiple times 1. single time 9. clear password)
/// @param countryCode mobile country code
/// @param mobile mobile phone number
/// @param success success callback
/// @param failure failure callback
- (void)addVideoLockOfflinePasswordWithDevId:(NSString *)devId
                                     pwdType:(NSString *)pwdType
                                    gmtStart:(NSInteger)gmtStart
                                  gmtExpired:(NSInteger)gmtExpired
                                     pwdName:(NSString *)pwdName
                                 countryCode:(NSString *)countryCode
                                      mobile:(NSString *)mobile
                                     success:(ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure;


/// Set offline password name
///
/// @param devId Device ID
/// @param unlockBindingId Password number
/// @param pwdName Password name
/// @param success Success callback
/// @param failure Failure callback
- (void)setVideoLockOfflinePasswordNameWithDevId:(NSString *)devId
                                 unlockBindingId:(NSInteger )unlockBindingId
                                         pwdName:(NSString *)pwdName
                                         success:(ThingSuccessID)success
                                         failure:(nullable ThingFailureError)failure;

/// Get the clear code of a temporary offline password
///
/// @param devId Device ID
/// @param unlockBindingId Password authorization number
/// @param name Offline deletion password name
/// @param success Success callback
/// @param failure Failure callback
- (void)getVideoLockOfflineEmptyCodeWithDevId:(NSString *)devId
                              unlockBindingId:(NSInteger )unlockBindingId
                                         name:(NSString *)name
                                      success:(ThingSuccessID)success
                                      failure:(nullable ThingFailureError)failure;

/**
 ****************************************************************************************************************
 ****************************************************************************************************************
 *                  Online Password Interface
 ****************************************************************************************************************
 ****************************************************************************************************************
 */

/// Get the online temporary password list
///
/// @param devId device ID
/// @param success success callback
/// @param failure failure callback
- (void)getPhotoLockTemporaryPasswordWithDevId:(NSString *)devId
                                       success:(ThingSuccessID)success
                                       failure:(nullable ThingFailureError)failure;

/// Get the video intercom door lock sn
///
/// @param devId device ID
/// @param dpId door opening method dpId
/// @param success success callback
/// @param failure failure callback
- (void)getVideoLockSnNumberWithDevId:(NSString *)devId
                                 dpId:(NSInteger)dpId
                              success:(ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

- (void)getVerifyCodeSendWithDevId:(NSString *)account
                              success:(ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

- (void)getOpmodeVerifyWithDevId:(NSString *)devId
                                      userId:(NSString *)userId
                                    unlockId:(NSString *)unlockId
                                  unlockName:(NSString *)unlockName
                                  unlockAttr:(NSInteger )unlockAttr
                                  notifyInfo:(NSString *)notifyInfo
                                unlockDetail:(NSString *)unlockDetail
                              success:(ThingSuccessID)success
                         failure:(nullable ThingFailureError)failure;

- (void)getLockMemberListWithDevId:(NSString *)devId
                                dpIds:(NSString *)dpIds
                              success:(ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

- (void)getLockMaxMemberListWithDevId:(NSString *)devId
                              dpCodes:(NSString *)dpCodes
                              keyword:(NSString *)keyword
                               offset:(NSInteger )offset
                                limit:(NSInteger )limit
                              success:(ThingSuccessID)success
                              failure:(nullable ThingFailureError)failure;

- (void)getDeviceMemberDetailListWithDevId:(NSString *)devId
                                     dpIds:(NSString *)dpIds
                                   keyword:(NSString *)keyword
                                    targetUserType:(NSString *)targetUserType
                                    offset:(NSInteger)offset
                                     limit:(NSInteger)limit
                                   success:(ThingSuccessID)success
                                   failure:(nullable ThingFailureError)failure;

- (void)removeUnlockOpmodeForMemberWithDevId:(NSString *)devId
                                    opmodeId:(long long)opmodeId
                                     success:(nullable ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure;

- (void)addUnlockOpModeForMemberWithCloud:(NSString *)devId
                                      userId:(NSString *)userId
                                    unlockId:(NSString *)unlockId
                                  unlockName:(NSString *)unlockName
                                  unlockAttr:(NSInteger )unlockAttr
                                  notifyInfo:(NSString *)notifyInfo
                                unlockDetail:(NSString *)unlockDetail
                                     success:(ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure;

- (void)getUnlockOpModeDetailWithDevId:(NSString *)devId
                                            opModeId:(NSString *)opModeId
                                             success:(ThingSuccessID)success
                                             failure:(nullable ThingFailureError)failure;

- (void)modifyUnlockOpModeForMemberWithDevId:(NSString *)devId
                                       opModeId:(NSString *)opModeId
                                     unlockName:(NSString *)unlockName
                                     unlockAttr:(NSInteger )unlockAttr
                                     notifyInfo:(NSString *)notifyInfo
                                   unlockDetail:(NSString *)unlockDetail
                                        success:(ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure;

/// Get the online temporary password list
///
/// @param devId Device ID
/// @param authTypes Query authorization type
/// @param success Success callback
/// @param failure Failure callback
- (void)getVideoLockTemporaryPasswordWithDevId:(NSString *)devId
                                     authTypes:(NSArray *)authTypes
                                       success:(ThingSuccessID)success
                                       failure:(nullable ThingFailureError)failure;

/// Add online temporary password
///
/// @param devId Device ID
/// @param name Password name
/// @param phone Phone number
/// @param effectiveTime Effective time
/// @param invalidTime Expiration time
/// @param password Password
/// @param schedule Cycle
/// @param countryCode Phone country code
/// @param availTime Available times
/// @param success Success callback
/// @param failure Failure callback
- (void)addPhotoLockTemporaryPasswordWithDevId:(NSString *)devId
                                          name:(NSString *)name
                                         phone:(NSString *)phone
                                 effectiveTime:(NSInteger)effectiveTime
                                   invalidTime:(NSInteger)invalidTime
                                      password:(NSString *)password
                                      schedule:(NSString *)schedule
                                   countryCode:(NSString *)countryCode
                                     availTime:(NSInteger)availTime
                                       success:(ThingSuccessID)success
                                       failure:(nullable ThingFailureError)failure;

/// Add online temporary password
///
/// @param devId Device ID
/// @param name Password name
/// @param password Password content
/// @param effectiveTime Effective time
/// @param invalidTime Expiration time
/// @param availTime Available times
/// @param sn Temporary password number
/// @param schedule Cycle
/// @param symbolic Whether dp needs to be sent down, composite communication door lock takes effect
/// @param dpTunnel If dp needs to be sent down, the dp sending channel currently needs to be used, and the composite communication door lock takes effect
/// @param success Success callback
/// @param failure Failure callback
- (void)addVideoLockTemporaryPasswordWithDevId:(NSString *)devId
                                          name:(NSString *)name
                                      password:(NSString *)password
                                 effectiveTime:(NSInteger)effectiveTime
                                   invalidTime:(NSInteger)invalidTime
                                     availTime:(NSInteger)availTime
                                            sn:(NSInteger)sn
                                      schedule:(NSString *)schedule
                                      symbolic:(BOOL)symbolic
                                      dpTunnel:(NSInteger)dpTunnel
                                       success:(ThingSuccessID)success
                                       failure:(nullable ThingFailureError)failure;

/// Update temporary password name
///
/// @param devId device ID
/// @param pwdId password number
/// @param name name
/// @param success success callback
/// @param failure failure callback
- (void)updatePhotoLockTemporaryPasswordNameWithDevId:(NSString *)devId
                                                pwdId:(NSInteger )pwdId
                                                 name:(NSString *)name
                                              success:(ThingSuccessID)success
                                              failure:(nullable ThingFailureError)failure;

/// Update temporary password name
///
/// @param devId Device ID
/// @param unlockBindingId Temporary password serial number
/// @param name Name
/// @param success Success callback
/// @param failure Failure callback
- (void)updateVideoLockTemporaryPasswordNameWithDevId:(NSString *)devId
                                      unlockBindingId:(NSInteger )unlockBindingId
                                                 name:(NSString *)name
                                              success:(ThingSuccessID)success
                                              failure:(nullable ThingFailureError)failure;

/// Delete temporary password
///
/// @param devId device ID
/// @param pwdId password number
/// @param success success callback
/// @param failure failure callback
- (void)deletePhotoLockTemporaryPasswordWithDevId:(NSString *)devId
                                            pwdId:(NSInteger )pwdId
                                          success:(ThingSuccessID)success
                                          failure:(nullable ThingFailureError)failure;

/// Delete temporary password
///
/// @param devId Device ID
/// @param unlockBindingId Temporary password serial number
/// @param symbolic Whether dp needs to be sent down, composite communication door lock takes effect
/// @param dpTunnel If dp needs to be sent down, the dp sending channel currently needs to be used, and the composite communication door lock takes effect
/// @param success Success callback
/// @param failure Failure callback
- (void)deleteVideoLockTemporaryPasswordWithDevId:(NSString *)devId
                                  unlockBindingId:(NSInteger )unlockBindingId
                                         symbolic:(BOOL)symbolic
                                         dpTunnel:(NSInteger)dpTunnel
                                          success:(ThingSuccessID)success
                                          failure:(nullable ThingFailureError)failure;

/**
 ****************************************************************************************************************
 ****************************************************************************************************************
 *                  Member Management Interface
 ****************************************************************************************************************
 ****************************************************************************************************************
 */

/// Count the number of members
///
/// @param devId Device ID
/// @param success Success callback
/// @param failure Failure callback
- (void)getPhotoLockMemberCountWithDevId:(NSString *)devId
                                 success:(ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

/// Query panel member list
///
/// @param devId device ID
/// @param success success callback
/// @param failure failure callback
- (void)getPhotoLockMemberPanelListWithDevId:(NSString *)devId
                                     success:(ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure;

/// Add panel members
///
/// @param devId Device ID
/// @param name User name
/// @param avatar Avatar information
/// @param sex Gender (0 unknown 1 male 2 female)
/// @param birthday Birthday (timestamp)
/// @param height Height
/// @param weight Weight
/// @param localHeightUnit App unit (CM centimeters INCH inches)
/// @param success Success callback
/// @param failure Failure callback
- (void)addPhotoLockPanelMemberWithDevId:(NSString *)devId
                                    name:(NSString *)name
                                  avatar:(NSString *)avatar
                                     sex:(NSString *)sex
                                birthday:(NSInteger)birthday
                                  height:(NSInteger)height
                                  weight:(NSInteger)weight
                         localHeightUnit:(NSString *)localHeightUnit
                                 success:(ThingSuccessID)success
                                 failure:(nullable ThingFailureError)failure;

/// Update panel member information
///
/// @param devId device ID
/// @param userId user ID
/// @param userName user name
/// @param avatar avatar information
/// @param success success callback
/// @param failure failure callback
- (void)updatePhotoLockPanelMemberWithDevId:(NSString *)devId
                                     userId:(NSString *)userId
                                   userName:(NSString *)userName
                                     avatar:(NSString *)avatar
                                    success:(ThingSuccessID)success
                                    failure:(nullable ThingFailureError)failure;

/// Delete panel member information
///
/// @param devId device ID
/// @param userId user ID
/// @param success success callback
/// @param failure failure callback
- (void)deletePhotoLockPanelMemberWithDevId:(NSString *)devId
                                     userId:(NSString *)userId
                                    success:(ThingSuccessID)success
                                    failure:(nullable ThingFailureError)failure;

/// Get panel member details
///
/// @param devId device ID
/// @param userId user ID
/// @param success success callback
/// @param failure failure callback
- (void)getPhotoLockPanelMemberDetailWithDevId:(NSString *)devId
                                        userId:(NSString *)userId
                                       success:(ThingSuccessID)success
                                       failure:(nullable ThingFailureError)failure;


#pragma mark - BLE API

/// Whether the user can open the door remotely
///
/// @param devId device ID
/// @param success success callback
/// @param failure failure callback
- (void)remoteUnlockAvailableWithDevId:(NSString *)devId
                               success:(ThingSuccessID)success
                               failure:(ThingFailureError)failure;


/// Update custom password temporary password information
///
/// @param devId Device ID
/// @param name Password name
/// @param password Password content
/// @param unlockBindingId Password number
/// @param effectiveTime Effective time
/// @param invalidTime Invalid time
/// @param phase 2. Normal 4. Freeze
/// @param schedule Cycle
/// @param symbolic Whether dp needs to be sent down, composite communication door lock takes effect
/// @param dpTunnel If dp needs to be sent down, the dp sending channel currently needs to be used, and the composite communication door lock takes effect
/// @param success Success callback
/// @param failure Failure callback
- (void)updateBLELockTemporaryPasswordWithDevId:(NSString *)devId
                                           name:(NSString *)name
                                       password:(NSString *)password
                                unlockBindingId:(NSInteger )unlockBindingId
                                  effectiveTime:(NSInteger)effectiveTime
                                   invalidTime:(NSInteger)invalidTime
                                          phase:(NSInteger)phase
                                      schedule:(NSString *)schedule
                                      symbolic:(BOOL)symbolic
                                      dpTunnel:(NSInteger)dpTunnel
                                       success:(ThingSuccessID)success
                                       failure:(nullable ThingFailureError)failure;

/// Temporary password parameter validity check
///
/// @param devId Device ID
/// @param name Password name
/// @param phone Phone number
/// @param unlockBindingId Password number
/// @param effectiveTime Effective time
/// @param invalidTime Expiration time
/// @param password Password
/// @param schedule Cycle
/// @param countryCode Phone country code
/// @param success Success callback
/// @param failure Failure callback
- (void)validateBLELockTemporaryPasswordWithDevId:(NSString *)devId
                                             name:(NSString *)name
                                            phone:(NSString *)phone
                                  unlockBindingId:(NSInteger)unlockBindingId
                                    effectiveTime:(NSInteger)effectiveTime
                                      invalidTime:(NSInteger)invalidTime
                                         password:(NSString *)password
                                         schedule:(NSString *)schedule
                                      countryCode:(NSString *)countryCode
                                          success:(ThingSuccessID)success
                                          failure:(nullable ThingFailureError)failure;

/// Report operation log record
///
/// @param devId Device ID
/// @param logType Log type
/// @param data Business parameter
/// @param success Success callback
/// @param failure Failure callback
- (void)uploadBLELockOperationLogWithDevId:(NSString *)devId
                                   logType:(NSString *)logType
                                      data:(NSString *)data
                                   success:(ThingSuccessID)success
                                   failure:(nullable ThingFailureError)failure;



@end

NS_ASSUME_NONNULL_END
