
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import <ThingSmartCameraBase/ThingSmartCameraType.h>
#import "ThingSmartLockKit.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartWiFiLockDevice;

@protocol ThingSmartWiFiLockDeviceDelegate <ThingSmartDeviceDelegate,ThingSmartCameraDelegate>

@optional

/// Device image data reporting dp212
///
/// @param device door lock device
/// @param message data reported by the device
- (void)onLockMessageArrived:(ThingSmartWiFiLockDevice *)device
                     message:(NSDictionary *)message;

/// Real-time video reporting callback dp63
///
/// @param device Door lock device
/// @param model Data reported by the device
- (void)onVideoRequestRealtime:(ThingSmartWiFiLockDevice *)device
                         model:(NSString *)model;

/// Remote door opening request image report dp9
///
/// @param device Door lock device
/// @param time Countdown data
- (void)unlockRequestCountdown:(ThingSmartWiFiLockDevice *)device
                          time:(NSInteger)time;

/// Alarm request image report dp45
///
/// @param device Door lock device
/// @param time Countdown data
- (void)alarmRequestCountdown:(ThingSmartWiFiLockDevice *)device
                         time:(NSInteger)time;

/// Remote door opening reply report dp50
///
/// @param device door lock device
- (void)onRemoteUnlockReport:(ThingSmartWiFiLockDevice *)device;

/// Forced anti-lock reply report dp13
///
/// @param device Door lock device
- (void)onForceLockUpReport:(ThingSmartWiFiLockDevice *)device;

/// Received callback information for add/deleting unlocking mode
/// @param device Door lock device
/// @param opMessage Device operation message
- (void)device:(ThingSmartWiFiLockDevice *)device didReceiveAddOpMessage:(ThingSmartBLELockOpMessageModel *)opMessage;

- (void)device:(ThingSmartWiFiLockDevice *)device didReceiveDeleteOpMessage:(ThingSmartBLELockOpMessageModel *)opMessage;

@end

@interface ThingSmartWiFiLockDevice : ThingSmartDevice

@property (nonatomic, strong, readonly) id<ThingSmartCameraType> cameraType;
@property (nonatomic, weak, nullable) id<ThingSmartWiFiLockDeviceDelegate> delegate;

- (instancetype)initWithDeviceId:(NSString *)devId;

/// Retake photo interface, do not call repeatedly within 15 seconds of anti-shake processing
///
/// @param needTake whether to take photo again
/// @param success success callback
/// @param failure failure callback
- (void)reTakePhoto:(BOOL)needTake
            success:(ThingSuccessHandler)success
            failure:(ThingFailureError)failure;

/// Forced anti-lock interface
///
/// @param needLock Whether to force anti-lock
/// @param success Success callback
/// @param failure Failure callback
- (void)enforceLock:(BOOL)needLock
            success:(ThingSuccessHandler)success
            failure:(ThingFailureError)failure;

/// Remote door opening and closing interface
///
/// @param devId Device ID
/// @param open Remote door opening: YES Remote door closing: NO
/// @param confirm Confirmation: YES Rejection: NO
/// @param success Success callback
/// @param failure Failure callback
- (void)remoteLockWithDevId:(NSString *)devId
                       open:(BOOL)open
                    confirm:(BOOL)confirm
                    success:(nullable ThingSuccessBOOL)success
                    failure:(nullable ThingFailureError)failure;

/// Query the cover image address
///
/// @param devId Device ID
/// @param bucket The warehouse to which the file belongs
/// @param filePath Cover image path
/// @param success Success callback
/// @param failure Failure callback
- (void)getPopupPictureAddressWithDevId:(NSString *)devId
                                 bucket:(NSString *)bucket
                               filePath:(NSString *)filePath
                               success:(nullable ThingSuccessID)success
                               failure:(nullable ThingFailureError)failure;

/// Get the most recent photo cover
///
/// @param devId Device ID
/// @param fileType File type 1. Remote door opening, 2. Alarm
/// @param success Success callback
/// @param failure Failure callback
- (void)getLatestPopupInfoWithDevId:(NSString *)devId
                           fileType:(NSInteger)fileType
                            success:(nullable ThingSuccessID)success
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

- (void)getUnlockWaitAssignWithDevId:(NSString *)devId
                                    success:(ThingSuccessID)success
                             failure:(nullable ThingFailureError)failure;

- (void)getUnlockAssignListWithDevId:(NSString *)devId
                                       success:(ThingSuccessID)success
                             failure:(nullable ThingFailureError)failure;

- (void)unlockAllocateWithDevId:(NSString *)devId
                            userId:(NSString *)userId
                         unlockIds:(NSString *)unlockIds
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

/// Establish P2P connection
- (void)p2pConnect;

/// Disconnect P2P connection
- (void)p2pDisConnect;

/// Is P2P connected?
- (BOOL)isP2pConnected;

/// Is P2P connected?
- (BOOL)isP2pConnecting;

/// Start preview (set definition)
///
/// @param definition Set definition. 0x2: SD 0x4: HD
- (void)startPreviewWithDefinition:(ThingSmartCameraDefinition)definition;

/// Stop preview
- (void)stopPreview;

/// Is the preview successful?
- (BOOL)isPreviewOn;

/// Start recording
///
/// @param direction Rotation angle
/// @param filePath Specify storage directory
- (void)startRecordWithRotateDirection:(ThingSmartVideoRotateDirection)direction
                              filePath:(NSString *)filePath;

/// Stop recording and return the path and cover image data of the recorded file
- (void)stopRecordAndFetchPath;

/// Is recording in progress?
- (BOOL)isRecording;

/// Take a screenshot and return the file storage path and thumbnail
///
/// @param direction Rotation angle
/// @param filePath specifies the storage directory
/// @param thumbnilPath thumbnail
- (UIImage *)snapShootWithRotateDirection:(ThingSmartVideoRotateDirection)direction
                              savedAtPath:(NSString *)filePath
                             thumbnilPath:(NSString *)thumbnilPath;

/// Turn mute on and off
///
/// @param mute mute
- (void)enableMute:(BOOL)mute;

/// Is it muted?
- (BOOL)isMuting;

/// Turn on intercom
- (void)startTalk;

/// Turn off intercom
- (void)stopTalk;

/// Is the device in intercom?
- (BOOL)isTalking;

/// Does the device support intercom?
- (BOOL)isSupportedTalk;

/// Whether the device supports sound pickup
- (BOOL)isSupportedSound;

/// The intercom mode supported by the device by default
- (ThingSmartCameraTalkbackMode)supportedAudioMode;

/// Added unlocking method (video doorlock)
- (void)addProUnlockOpModeForMemberWithDevice:(NSString *)memberId
                                     isAdmin:(BOOL)isAdmin
                                  lockUserId:(int)lockUserId
                                unlockDpCode:(NSString *)unlockDpCode
                                unlockOpType:(ThingUnlockOpType)unlockOpType
                                  unlockName:(NSString *)unlockName
                               effectiveDate:(nullable NSDate *)effectiveDate
                                 invalidDate:(nullable NSDate *)invalidDate
                                       times:(int)times
                                  dataLength:(int)dataLength
                                 dataContent:(NSString *)dataContent
                                          sn:(int)sn
                                     timeout:(NSTimeInterval)timeout
                                     appSend:(BOOL)appSend
                                     success:(nullable ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure ;

- (void)removeUnlockOpmodeForMember:(BOOL)isAdmin
                                  lockUserId:(int)lockUserId
                           opmodeId:(long long)opmodeId
                                unlockId:(int)unlockId
                                unlockDpCode:(NSString *)unlockDpCode
                                unlockOpType:(ThingUnlockOpType)unlockOpType
                                timeout:(NSTimeInterval)timeout
                                     success:(nullable ThingSuccessID)success
                                     failure:(nullable ThingFailureError)failure;

- (NSString *)getDpIdWithDpCode:(NSString *)code;

@end

NS_ASSUME_NONNULL_END
