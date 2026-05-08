
#import <Foundation/Foundation.h>
#import "ThingSmartCameraDefines.h"
#import "ThingSmartCameraErrorCode.h"
#import "ThingSmartVideoViewType.h"
#import "ThingSmartCameraViewType.h"
#import "ThingSmartCameraAdvancedConfigType.h"
#import "ThingSmartCameraExtraAbilityType.h"
#import "ThingSmartVideoExtInfoType.h"
#import "ThingSmartLocalVideoInfoType.h"
#import "ThingSmartLocalAudioInfoType.h"
#import <CoreMedia/CoreMedia.h>
#import "ThingSmartCameraAudioType.h"
#import "ThingSmartMultiCameraViewType.h"

IPC_EXTERN NSString * const kThingSmartTimeSliceStartDate;

IPC_EXTERN NSString * const kThingSmartTimeSliceStopDate;

IPC_EXTERN NSString * const kThingSmartTimeSliceStartTime;

IPC_EXTERN NSString * const kThingSmartTimeSliceStopTime;

IPC_EXTERN NSString * const kThingSmartTimeSliceRecordType;

IPC_EXTERN NSString * const kThingSmartTimeSliceRecordEventType;

IPC_EXTERN NSString * const kThingSmartTimeSliceRecordEventTypes;

IPC_EXTERN NSString * const kThingSmartTimeSliceRecordAOVType;

typedef NS_ENUM(NSUInteger, ThingSmartCameraConnectMode) {
    ThingSmartCameraConnectAuto,
    ThingSmartCameraConnectFromInternet,
    ThingSmartCameraConnectFromLocal
};

typedef NS_ENUM(NSUInteger, ThingSmartVideoRotateDirection) {
    ThingSmartVideoRotateDirectionUp = 0,
    ThingSmartVideoRotateDirectionRight = 1,
    ThingSmartVideoRotateDirectionDown = 2,
    ThingSmartVideoRotateDirectionLeft = 3
};

typedef NS_ENUM(NSUInteger, ThingSmartVideoMirrorDirection) {
    ThingSmartVideoMirrorDirectionDefault = 0,
    ThingSmartVideoMirrorDirectionHorizontal = 1,
    ThingSmartVideoRotateDirectionVertical = 2
};

typedef NS_ENUM(NSUInteger, ThingSmartPlaybackVideoType) {
    ThingSmartPlaybackVideoTypeNormal = 0,
    ThingSmartPlaybackVideoTypeAOV = 1
};

typedef NS_ENUM(NSUInteger, ThingSmartP2PStateType) {
    ThingSmartP2PStateTypeEmpty = 0,// 完全未连接前 (或者连接失败，调用了p2pclose之后)
    ThingSmartP2PStateTypeConnecting, // 正在连接
    ThingSmartP2PStateTypeConnected, // 连接成功
    ThingSmartP2PStateTypeConnectFailed // 连接失败
};

@protocol ThingSmartCameraType;

@protocol ThingSmartCameraDelegate <NSObject>

@optional

/**
 [^en]
 camera init failed.
 [$en]


 @param errorCode errorCode
 */
- (void)cameraInitFailed:(ThingSmartCameraErrorCode)errorCode;


/**
 [^en]
 the p2p channel did connected.
 [$en]


 @param camera camera
 */
- (void)cameraDidConnected:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 the p2p channel did disconnected.
 [$en]


 @param camera camera
 */
- (void)cameraDisconnected:(id<ThingSmartCameraType>)camera __deprecated_msg("Use cameraDisconnected:specificErrorCode: instead");

/**
 [^en]
 the new p2p channel did disconnected.
 [$en]


 @param camera camera
 @param errorCode [^en]errorCode reference ThingCameraSDK.framework/ThingDefines[$en]
 */
- (void)cameraDisconnected:(id<ThingSmartCameraType>)camera specificErrorCode:(NSInteger)errorCode;

/**
 [^en]
 the playback channel did connected.
 [$en]


 @param camera camera
 */
- (void)cameraDidConnectPlaybackChannel:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 the camera did began play live video.
 [$en]


 @param camera camera
 */
- (void)cameraDidBeginPreview:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 the camera did stop live video.
 [$en]


 @param camera camera
 */
- (void)cameraDidStopPreview:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 the camera did began playback record video in the SD card.
 [$en]


 @param camera camera
 */
- (void)cameraDidBeginPlayback:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 the camera did pause playback record video in the SD card.
 [$en]


 @param camera camera
 */
- (void)cameraDidPausePlayback:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 the camera did resume playback record video in the SD card.
 [$en]


 @param camera camera
 */
- (void)cameraDidResumePlayback:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 the camera did stop playback record video in the SD card.
 [$en]


 @param camera camera
 */
- (void)cameraDidStopPlayback:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 the record video in the SD card playback finished.
 [$en]


 @param camera camera
 */
- (void)cameraPlaybackDidFinished:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 the record video in the SD card playback finished
 [$en]


 @param camera camera
 @param status finished status
 */
- (void)camera:(id<ThingSmartCameraType>)camera playbackDidFinishedWithStatus:(NSInteger)status;

- (void)camera:(id<ThingSmartCameraType>)camera playbackTimeSlice:(NSDictionary *)timeSlice didFinishedWithStatus:(NSInteger)status;


- (void)camera:(id<ThingSmartCameraType>)camera playbackFragmentDidStart:(ThingSmartPlaybackVideoType)videoType;
/**
 [^en]
 receive first video frame
 this method will call when every 'startPreview/startPlayback/resumePlayback' sucess.
 [$en]


 @param camera camera
 @param image  [^en]fisrt frame image[$en]
 */
- (void)camera:(id<ThingSmartCameraType>)camera didReceiveFirstFrame:(UIImage *)image;
- (void)camera:(id<ThingSmartCameraType>)camera didReceiveFirstFrame:(UIImage *)image videoExtInfo:(id<ThingSmartVideoExtInfo>)videoExtInfo;

/**
 [^en]
 local camera receive first video frame
 this method will call when 'startLocalVideoCaptureWithVideoInfo' sucess.
 [$en]

 @param camera camera
 @param image  [^en]fisrt frame image[$en]
 @param localVideoInfo  [^en] local video info [$en]
 */
- (void)camera:(id<ThingSmartCameraType>)camera didReceiveLocalVideoFirstFrame:(UIImage *)image localVideoInfo:(id<ThingSmartLocalVideoInfoType>)localVideoInfo;

/**
 [^en]
 begin talk to the device. will call when 'startAudioTalk' success.
 [$en]


 @param camera camera
 */
- (void)cameraDidBeginTalk:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 talk to the device did stop. will call when 'stopAudioTalk' success.
 [$en]


 @param camera camera
 */
- (void)cameraDidStopTalk:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 The two-way video talk has started.
 [$en]


 @param camera camera
 */
- (void)cameraDidStartVideoTalk:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 The two-way video talk has stopped
 [$en]


 @param camera camera
 */
- (void)cameraDidStopVideoTalk:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 The two-way video talk has paused.
 [$en]


 @param camera camera
 */
- (void)cameraDidPauseVideoTalk:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 The two-way video talk has resumed
 [$en]


 @param camera camera
 */
- (void)cameraDidResumeVideoTalk:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 the video screenshot has saved in the photo album.
 [$en]


 @param camera camera
 */
- (void)cameraSnapShootSuccess:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 video recording did start success.
 [$en]


 @param camera camera
 */
- (void)cameraDidStartRecord:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 video recording did stop sucess, and the video has saved in photo album success.
 [$en]


 @param camera camera
 */
- (void)cameraDidStopRecord:(id<ThingSmartCameraType>)camera;

/**
 [^en]
 did receive definition state. will call when 'getHD' success or the definition has changed.
 [$en]


 @param camera camera
 @param isHd [^en]is high definition[$en]
 */
- (void)camera:(id<ThingSmartCameraType>)camera didReceiveDefinitionState:(BOOL)isHd __deprecated_msg("Use camera:definitionChanged: instead");
- (void)camera:(id<ThingSmartCameraType>)camera definitionChanged:(ThingSmartCameraDefinition)definition;

/**
 [^en]
 called when query data of the playback event list sift success.
 [$en]


 @param camera camera
 @param titles [^en]the array of title，ex: [@(Message left), @"Call"]; [$en]
 @param eventIds [^en]the array of eventIds，ex: [@(1), @"2"]; [$en]
 */
- (void)camera:(id<ThingSmartCameraType>)camera didReceiveEventListSiftData:(NSArray<NSString *> *)titles eventIds:(NSArray<NSNumber *> *)eventIds;

/**
 [^en]
 called when query date of the playback record success.
 [$en]


 @param camera camera
 @param days [^en]the array of days，ex: [@(1), @(2), @(5), @(6), @(31)]; express in this month, 1，2，5，6，31  has video record.[$en]
 */
- (void)camera:(id<ThingSmartCameraType>)camera didReceiveRecordDayQueryData:(NSArray<NSNumber *> *)days;

/**
 [^en]
 called when query video record slice of one day success.
 [$en]


 @param camera camera
 
 @param timeSlices [^en]the array of playback video record information. the element is a NSDictionary, content like this:
 kThingSmartPlaybackPeriodStartDate  ： startTime(NSDate)
 kThingSmartPlaybackPeriodStopDate   ： stopTime(NSDate)
 kThingSmartPlaybackPeriodStartTime  ： startTime(NSNumer, unix timestamp)
 kThingSmartPlaybackPeriodStopTime   ： stopTime(NSNumer, unix timestamp)[$en]
 */
- (void)camera:(id<ThingSmartCameraType>)camera didReceiveTimeSliceQueryData:(NSArray<NSDictionary *> *)timeSlices;

/**
 [^en]
 did receive mute state. will call when 'enableMute:' success. default is YES.
 [$en]


 @param camera camera
 @param isMute [^en]is muted[$en]
 */
- (void)camera:(id<ThingSmartCameraType>)camera didReceiveMuteState:(BOOL)isMute playMode:(ThingSmartCameraPlayMode)playMode;

/**
 [^en]
 the control of camera has occurred an error
 [$en]

 @param camera camera
 @param errCode [^en]reference the ThingCameraErrorCode[$en]
 */
- (void)camera:(id<ThingSmartCameraType>)camera didOccurredError:(ThingCameraErrorCode)errCode __deprecated_msg("Use camera:didOccurredErrorAtStep:specificErrorCode: instead");

/**
 [^en]
 the control of camera has occurred an error with specific reason code
 [$en]

 @param camera camera
 @param errStepCode [^en]reference the ThingCameraErrorCode[$en]
 @param errorCode [^en]errorCode reference ThingCameraSDK.framework/ThingDefines[$en]
 */
- (void)camera:(id<ThingSmartCameraType>)camera didOccurredErrorAtStep:(ThingCameraErrorCode)errStepCode specificErrorCode:(NSInteger)errorCode;

/**
 [^en]
 the control of camera has occurred an error with specific reason code, add detail codes，First priority.
 [$en]

 @param camera camera
 @param errStepCode [^en]reference the ThingCameraErrorCode[$en]
 @param errorCode [^en]errorCode reference ThingCameraSDK.framework/ThingDefines[$en]
 @param extErrorCodeInfo [^en]ext error code info contains the detail error code[$en]
 */
- (void)camera:(id<ThingSmartCameraType>)camera didOccurredErrorAtStep:(ThingCameraErrorCode)errStepCode specificErrorCode:(NSInteger)errorCode extErrorCodeInfo:(id<ThingSmartCameraExtErrorCodeInfo>)extErrorCodeInfo;

/**
 [^en]
 the definition of the video did chagned
 [$en]

 @param camera camera
 @param width video width
 @param height video height
 */
- (void)camera:(id<ThingSmartCameraType>)camera resolutionDidChangeWidth:(NSInteger)width height:(NSInteger)height;
- (void)camera:(id<ThingSmartCameraType>)camera resolutionDidChangeWithVideoExtInfo:(id<ThingSmartVideoExtInfo>)videoExtInfo;

/**
 [^en]
 if 'isRecvFrame' is true, and p2pType is "1", the video data will not decode in the SDK, and could get the orginal video frame data through this method.
 [$en]

 @param camera      camera
 @param frameData   [^en]original video frame data[$en]
 @param size        [^en]video frame data size[$en]
 @param frameInfo   [^en]frame header info[$en]
 */

- (void)camera:(id<ThingSmartCameraType>)camera thing_didReceiveFrameData:(const char *)frameData dataSize:(unsigned int)size frameInfo:(ThingSmartVideoStreamInfo)frameInfo;

/**
 [^en]
 if 'isRecvFrame' is true, and p2pType is greater than 2, could get the decoded YUV frame data through this method.
 [$en]

 @param camera          camera
 @param sampleBuffer    [^en]video frame YUV data[$en]
 @param frameInfo       [^en]frame header info[$en]
 */
- (void)camera:(id<ThingSmartCameraType>)camera thing_didReceiveVideoFrame:(CMSampleBufferRef)sampleBuffer frameInfo:(ThingSmartVideoFrameInfo)frameInfo;

/// audio data
/// @param camera camera
/// @param audioInfo audio infomation
- (void)camera:(id<ThingSmartCameraType>)camera thing_didAudioDataReceived:(id<ThingSmartCameraAudioType>)audioInfo;

/**
 [^en]
 the device's local camera capture video streams
 [$en]

 @param camera          camera
 @param sampleBuffer    [^en]video frame YUV data[$en]
 @param localVideoInfo  [^en] local video info [$en]
 */
- (void)camera:(id<ThingSmartCameraType>)camera didReceiveLocalVideoSampleBuffer:(CMSampleBufferRef)sampleBuffer localVideoInfo:(id<ThingSmartLocalVideoInfoType>)localVideoInfo;
/**
 [^en]
 if p2pType is greater than 2, could get audio record data when talking through this method. if yout want change the audio data, must keep the audio data length same，and synchronize,and then call 'sendAudioDataWithPCM:length:sampleRate:' to send custom audio data to the device.
 [$en]

 @param camera           camera
 @param pcm              [^en]audio data[$en]
 @param length           [^en]date length[$en]
 @param sampleRate       [^en]audio sample rate[$en]
*/
- (void)camera:(id<ThingSmartCameraType>)camera thing_didRecieveAudioRecordDataWithPCM:(const unsigned char*)pcm length:(int)length sampleRate:(int)sampleRate;

- (void)camera:(id<ThingSmartCameraType>)camera thing_didSpeedPlayWithSpeed:(ThingSmartCameraPlayBackSpeed)playBackSpeed;

- (void)camera:(id<ThingSmartCameraType>)camera thing_didEventReceivedEventType:(NSInteger)event errorCode:(NSInteger)error intValue:(long long)intValue strValue:(NSString *)strValue;

@end

@protocol ThingSmartCameraType <NSObject>

@property (nonatomic, weak) id<ThingSmartCameraDelegate> delegate;

@property (nonatomic, strong) NSString *devId;

/// [^en]if you want get the original video frame data, set isRecvFrame YES.[$en]
@property (nonatomic, assign) BOOL isRecvFrame;

/* [^en]
with p2p 2.0, could get YUV data with - (void)camera:(id<ThingSmartCameraType>)camera thing_didReceiveVideoFrame:(CMSampleBufferRef)sampleBuffer frameInfo:(ThingSmartVideoFrameInfo)frameInfo; set autoRender NO，you can render the video by yourself.
[$en]

 */
@property (nonatomic, assign) BOOL autoRender;

/**
 [^en]
  The advanced config about the camera.
 [$en]

 */
@property (nonatomic, strong, readonly) id <ThingSmartCameraAdvancedConfig> advancedConfig;

/**
 [^en]
 The extra ability about the camera.
 [$en]

 */
@property (nonatomic, strong, readonly) id <ThingSmartCameraExtraAbility> extraAbility;

/**
 [^en]
  whether needs to clear video when playback end, default YES
 [$en]

 */
@property (nonatomic, assign) BOOL needsClearVideoWhenPlaybackEnd;

/**
 [^en]
 local video info the device reported, call after P2P connected.
 [$en]

 */
@property (nonatomic, strong, readonly) id <ThingSmartLocalVideoInfoType> localVideoInfo;

/**
[^en]
 P2P connect channel, P2P or relay.
[$en]

*/
@property (nonatomic, assign, readonly) ThingCameraConnectionType currentConnectionType;

/**
 [^en]
 destory resources, should call this method when exit the camera panel.
 [$en]

 */
- (void)destory;

/**
 [^en]
 start connect p2p channel
 [$en]

 */
- (int)connect;

/**
 [^en]
 connnect playback channel, call this method before start playback video record.
 [$en]

 */
- (void)enterPlayback;

/**
 [^en]
 disconnect p2p channel,if preconnect is supported, will call suspend automatically.
 [$en]

 */
- (int)disConnect;

/**
 [^en]
 disconnect p2p channel forcedly
 [$en]

 */
- (int)disconnectForcedly;

/**
 [^en]
 get current video width
 [$en]

 
 @return video width
 */
- (CGFloat)getCurViewWidth;

/**
 [^en]
 get current video height
 [$en]

 
 @return video height
 */
- (CGFloat)getCurViewHeight;

/**
 [^en]
 start live video
 [$en]

 */
- (int)startPreview;

/**
[^en]
 start live video
[$en]

*/
- (int)startPreviewWithDefinition:(ThingSmartCameraDefinition)definition;

/**
 [^en]
 stop live video
 [$en]

 */
- (int)stopPreview;

/**
 [^en]
 video frame render view
 [$en]

 
 @return render view
 */
- (UIView<ThingSmartVideoViewType> *)videoView;

/**
 [^en]
local video frame render view
 [$en]

 
 @return render view
 */
- (UIView<ThingSmartVideoViewType> *)localVideoView;

/**
 [^en]
 IPC features video player view
 [$en]

 
 @return camera view include render view
 */
- (UIView<ThingSmartCameraViewType> *)cameraView;

/**
 [^en]
 IPC features multi camera video player view
 [$en]

 @return multi camera view include multi render views
 */
- (UIView<ThingSmartMultiCameraViewType> *)multiCameraView;

/**
 [^en]
 enable mute state, the default is YES
 [$en]

 
 @param mute is mute
 */
- (int)enableMute:(BOOL)mute forPlayMode:(ThingSmartCameraPlayMode)playMode;

/**
 [^en]
 start talk to device
 [$en]

 */
- (int)startTalk  __deprecated_msg("please use startAudioTalk instead");

/**
 [^en]
 stop talk to device.
 [$en]

 */
- (int)stopTalk __deprecated_msg("please use stopAudioTalk instead");

/**
 [^en]
 start audio talk
 [$en]

 */
- (int)startAudioTalk;

/**
 [^en]
 stop audio talk.
 [$en]

 */
- (int)stopAudioTalk;

/**
 start audio record
 audioInfo : sample rate, default is 8000, channel, default is 1, if custom audio info is optional, please set nil.
 */
-(int)startAudioRecordWithAudioInfo:(nullable id<ThingSmartLocalAudioInfoType>)audioInfo;

/**
 start audio record
 */
-(int)stopAudioRecord;

/**
 start video talk
 */
- (int)startVideoTalk;

/**
 stop video talk
 */
-(int)stopVideoTalk;

/**
    pause send video talk
 */
- (int)pauseVideoTalk;

/**
    resume send video talk
 */
- (int)resumeVideoTalk;

/**
 start encode and send video data to devices.
 requestId :  the return value of func startVideoTalk
 */
-(int)startSendingVideoTalkDataWithRequestId:(int)requestId;

/**
 stop encode ,stop send video data.
 */
-(int)stopSendVideoTalkData;

/**
 open local video capture
 videoInfo : frame size, frame rate, if custom video info is optional, please set nil.
 */
-(int)startLocalVideoCaptureWithVideoInfo:(nullable id<ThingSmartLocalVideoInfoType>)videoInfo;

/**
 stop the local video capture.
 */
-(int)stopLocalVideoCapture;

/**
 switch local camera position
 */
-(int)switchLocalCameraPosition;

/**
 [^en]
 start record video, the video record will saved in photo album.
 [$en]

 */
- (int)startRecord;

/**
 [^en]
 stop record video.
 [$en]

 */
- (int)stopRecord;

/**
 [^en]
 get a screenshot of the video and save it to photo album. photo asset collection name is bundle name, "[NSBundle mainBundle].infoDictionary[(__bridge NSString *)kCFBundleNameKey]".
 [$en]

 */
- (UIImage *)snapShoot;

/**
 [^en]
 enbale high definition
 [$en]

 
 @param hd is high definition
 */
- (int)enableHD:(BOOL)hd;

/**
[^en]
set definition
[$en]

@param definition definition
*/
- (int)setDefinition:(ThingSmartCameraDefinition)definition;

/**
 [^en]
 get the definition state
 [$en]

 */
- (int)getHD;

/**
[^en]
get the definition state
[$en]
 
*/
- (int)getDefinition;

/**
[^en]
 query the event list data
[$en]

@param values ex: @"1,2,3,7"
*/
- (void)queryEventListSiftWithEventListsValue:(NSString *)values;

/**
 [^en]
 query the date of video recording in a month.
 [$en]


 @param year ex: 2019
 @param month ex: 1
 */
- (void)queryRecordDaysWithYear:(NSUInteger)year month:(NSUInteger)month;

/**
 [^en]
 query all video record slices for a particular day.
 [$en]

 
 @param year ex: 2019
 @param month ex: 1
 @param day ex: 3
 */
- (void)queryRecordTimeSliceWithYear:(NSUInteger)year month:(NSUInteger)month day:(NSUInteger)day;

/**
 [^en]
 query all video record slices for a particular day to differentiate normal and event record .
 [$en]

 
 @param year ex: 2019
 @param month ex: 1
 @param day ex: 3
 */
- (void)newQueryRecordTimeSliceWithYear:(NSUInteger)year month:(NSUInteger)month day:(NSUInteger)day;

@property (nonatomic, assign, readonly) BOOL isSupportedRecordEventTypes;

///only isSupportedRecordEventTypes is YES, query recor v3, support new event types
- (void)queryRecordTimeSliceV3WithYear:(NSUInteger)year month:(NSUInteger)month day:(NSUInteger)day;

///download playback event image
- (int)downloadPlayBackImageV2WithStartTime:(NSInteger)startTime stopTime:(NSInteger)stopTime folderPath:(NSString *)folderPath saveFileName:(NSString *)saveFileName onResponse:(void (^)(id result,int errCode))onResponse;

/**
 [^en]
 start playback from a point in time, using unix timestamp
 [$en]

 
 @param playTime [^en]play time[$en]
 @param startTime [^en]start time of a video slice[$en]
 @param stopTime [^en]end time of a video slice[$en]
 */
- (int)startPlayback:(NSInteger)playTime startTime:(NSInteger)startTime stopTime:(NSInteger)stopTime;

/**
 Description Startup sd card playback.
 @param playTime From which time point(unix).
 @mode  play all or fragments defined by jsonFragments
        0 -- play all fragment. (supported only)
 @jsonFragments  the fragments need to play.
  jsonfragments
  {
      "fragments": [
         {
          “start":xxx                                       
          “end”:xxx
         },
          {
           “start":xxx
           “end”:xxx
          },
          {
           “start":xxx
           “end”:xxx
          }]
  }
 */

- (int)startPlayBackWithPlayTime:(NSInteger)playTime mode:(NSInteger)mode jsonFragments:(NSString*)jsonFragments;
/**
 [^en]
 pause playback
 [$en]

 */
- (int)pausePlayback;

/**
 [^en]
 resume play back
 [$en]

 */
- (int)resumePlayback;

/**
 [^en]
 stop play back
 [$en]

 */
- (int)stopPlayback;

@optional

/**
[^en]
 bind/unbind local video render view if need to custom.
[$en]

*/
- (void)bindLocalVideoView:(UIView<ThingSmartVideoViewType> *)videoView;
- (void)unbindLocalVideoView:(UIView<ThingSmartVideoViewType> *)videoView;

/**
[^en]
register/uninstall video render view if need to custom.
[$en]

*/
- (void)registerVideoRenderView:(UIView<ThingSmartVideoViewType> *)videoView;
- (void)uninstallVideoRenderView:(UIView<ThingSmartVideoViewType> *)videoView;


/**
[^en]
register/uninstall multi camera view which contains all video views and the localizer.
[$en]

*/
- (BOOL)registerMultiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView;
- (BOOL)uninstallMultiCameraView:(UIView<ThingSmartMultiCameraViewType> *)multiCameraView;

/**
[^en]
register/uninstall video render view info which contains video view and viewIndex if need to custom.
[$en]

*/
- (BOOL)registerVideoViewIndexPairs:(NSArray<id<ThingSmartVideoViewIndexPair>> *)viewIndexPairs NS_SWIFT_NAME(registerVideoViewIndexPairs(_:));
- (BOOL)uninstallVideoViewIndexPairs:(NSArray<id<ThingSmartVideoViewIndexPair>> *)viewIndexPairs;
/**
[^en]
swap videos by  viewIndex
[$en]

*/
- (BOOL)swapVideoIndex:(ThingSmartVideoIndex)videoIndex forVideoIndex:(ThingSmartVideoIndex)forVideoIndex;

/**
[^en]
connect p2p with specified mode
[$en]

*/
- (void)connectWithMode:(ThingSmartCameraConnectMode)mode;

/**
[^en]
connect p2p with specified mode, add extra params
[$en]
*/
- (void)connectWithMode:(ThingSmartCameraConnectMode)mode extraParams:(nullable NSDictionary *)extraParams;

- (double)getVideoBitRateKBPS;

/**
[^en]
if you want processing the audio data of talking, call this with YES and implement the delegate method:
 - (void)camera: thing_didRecieveAudioRecordDataWithPCM: length: sampleRate:
[$en]

*/
- (void)enableAudioProcess:(BOOL)enable;

/**
 [^en]
 Description Send audio data to device.
 [$en]
 @param data Audio data.
 @param length Audio data size.
 @param sampleRate Audio sample rate.
 */
- (int)sendAudioDataWithPCM:(unsigned char *)data length:(int)length sampleRate:(int)sampleRate;

/**
[^en]
start record video, the video record will saved in filepath
[$en]

*/
- (int)startRecordWithFilePath:(NSString *)filePath;

- (int)startRecordWithRotateDirection:(ThingSmartVideoRotateDirection)direction filePath:(NSString *)filePath;

/**
[^en]
get a screenshot of the video and save it to filepah. if you do not need a thumbnil, set thumbnilPath nil.
[$en]

*/
- (UIImage *)snapShootSavedAtPath:(NSString *)filePath thumbnilPath:(NSString *)thumbnilPath;

- (UIImage *)snapShootWithRotateDirection:(ThingSmartVideoRotateDirection)direction savedAtPath:(NSString *)filePath thumbnilPath:(NSString *)thumbnilPath;

/**
 Determine whether the device supports video download from the memory card
 */
- (BOOL)isSupportPlaybackDownload;

/**
 Download video from the memory card, the video start time(timeRange.loc) and the video end time(timeRange.loc+timeRange.len) must in a video timeSlice.
 */
- (int)downloadPlayBackVideoWithRange:(NSRange)timeRange filePath:(NSString *)videoPath success:(void(^)(NSString *filePath))success progress:(void(^)(NSUInteger progress))progress failure:(void(^)(NSError *error))failure;

/**
 Download video from the memory card, the video start time(timeRange.loc) and the video end time(timeRange.loc+timeRange.len) must in a video timeSlice.
 - Parameters:
 - timeRange: start time and end time
 - videoPath: video path
 - success: success callback 【Contain the file path，key is 'filePath', success code,key is 'code'】
 - progress: progeress callback
 - failure: failure callback
 */
- (int)downloadPlayBackVideo:(NSRange)timeRange filePath:(NSString *)videoPath success:(void(^)(NSDictionary *successInfo))success progress:(void(^)(NSUInteger progress))progress failure:(void(^)(NSError *error))failure;

/**
    pause download
 */
- (int)pausePlayBackDownloadWithResponse:(void (^)(int))callback;

/**
    resume download
 */
- (int)resumePlayBackDownloadWithResponse:(void (^)(int))callback;

/**
 Description Stop current sd card playback.
 
 @param callback Async result callback. errCode see ThingErrCode.
 */
- (int)stopPlayBackDownloadWithResponse:(void (^)(int errCode))callback;

/**
 Determine whether the device supports delete videos from the memory card.
 */
- (BOOL)isSupportPlaybackDelete;

/// Whether playback can be deleted by film
- (BOOL)isSupportPlaybackDeleteBySlice;

/**
 Delete the videos from the memory crad of the specified day.
 @param day yyyy-MM-dd
 */
- (int)deletePlayBackDataWithDay:(NSString *)day onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finishedCallBack;

/**
 Delete storage card data by fragments.
 @param json  : the fragments need to delete.
        {"fragments":[{
      *      "startTime":xxx,
      *      "endTime":xxx
      *  },{
      *      "startTime":xxx,
      *      "endTime":xxx
      *  }]}
 @param callback : Async result callback. errCode see ThingErrCode.
 @param finishedCallBack : Async delete result callback. errCode see ThingErrCode
 */
- (int)deletePlayBackDataWithFragments:(NSString *)json onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finishedCallBack;

/**
 Get the playback speed supported by the device.
 */
- (NSArray<NSNumber *> *)getSupportPlaySpeedList;

/**
 set the playback speed.
 */
- (void)speedPlayWithPlayBackSpeed:(ThingSmartCameraPlayBackSpeed)playBackSpeed;

/**
 Enable speaker

 @param enabled Speaker enabled
 @return error code, 0 is success
*/
- (int)enableSpeaker:(BOOL)enabled;

/**
  Get speaker enabled status
*/
- (BOOL)speakerEnabled;

/**
 set audio effect type.
 */
- (int)setAudioEffectType:(ThingCameraAudioEffectType)audioEffectType;

/**
    enable Audio effect.
 */
- (int)enableAudioEffect:(bool)enable __deprecated_msg("Use setAudioEffect: instead");

/**
    set the audio effect parameters .
    pitch :
    time_scale :     1.0 ,other not supported.
 */
- (int)setAudioEffectParametersWithRobotizationSupported:(bool)robotSupported pitch:(float)pitch time_scale:(float)time_scale norm_scale:(float)normal_amp_scale robot_scale:(float)robot_amp_scale __deprecated_msg("Use setAudioEffect: instead");

/**
    enable NS or not
    enable :  YES or NO
 */
- (int)enableAudioNS:(bool)enable;

/**
    enable AGC or not
    enable : YES or NO
 */
- (int)enableAudioAGC:(bool)enable;

/**
    eanble AEC or not
    enable : YES or NO
 */
- (int)enableAudioAEC:(bool)enable;

/**
    json: Binocular Camera Split Infomation
 */
- (int)setVideoSplitInfo:(NSString *)json;


#pragma mark - private, please igore these method

- (int)setDeviceFeatures:(NSDictionary *)features;

- (void)getSupportedDefinitions:(void(^)(NSArray *definitions))success failure:(void(^)(NSError *error))failure;

//- (void)getDefinition:(void(^)(ThingSmartCameraDefinition definitions))success failure:(void(^)(NSError *error))failure;

//- (void)setDefinition:(ThingSmartCameraDefinition)definition success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (int)setOutLineEnable:(BOOL)enable;

- (int)setSmartRectFeatures:(NSString *)features;

- (int)switchChannel:(int)channel success:(void (^)(void))success failure:(void(^)(int errCode))failure;

- (int)queryAlbumFileIndexWithAlbumName:(NSString *)albumName success:(void(^)(NSDictionary *index))success failure:(void(^)(int errCode))failure;

- (int)startDownloadAlbumFileWithAlbumName:(NSString *)albumName
                                     folder:(NSString *)folder
                                   fileList:(NSArray *)fileList
                                isThumbnail:(BOOL)isThumbnail
                          onOverAllProgress:(void(^)(int progress))overallProgress
                             onFileProgress:(void(^)(NSString *fileName, int progress, BOOL finished))fileProgress
                              onFileFailure:(void(^)(NSString *filename, int errCode))fileFailure
                                 onFinished:(void(^)(int errCode))finished;

-(int)cancelDownloadAlbumFile;

-(int)deleteAlbumFileWithAlbumName:(NSString*)albumName fileList:(NSArray *)fileList success:(void(^)(void))success failure:(void(^)(int errCode))failure;

- (void)setPlayBackEncryption:(BOOL)encryption;

- (void)setSupportAov:(BOOL)support;

/*
 Description start play album file.
 @param startTime   :   the start time expect to play(The value ranges from 0 to video duration).
 @param albumName   :   the name of album.
 @param fileName    :   the name of file.
 @param thumbnail   :   the file we download is thumbnail or not. if the thumbnail is true ,the suffix of the file must be jpg.
 @param reponse     :   the response for p2p message
 @param onFileDownloadFinish    :   the callback for all file download finished.
*/
-(int)startPlayAlbumFileWithStartTime:(int)startTime albumName:(NSString*)albumName fileName:(NSString*)fileName  thumbnail:(BOOL)thumbnail onResponse:(void (^)(const char *msg,int errCode))onResponse onFileDownloadFinish:(void (^)(const char* filename,int index ,int errCode))onFileFinished;

/*
 Description cancel download album file.
 @param onResponse  : the response for p2p message
*/
-(int)cancelPlayAlbumFileWithCallback:(void (^)(const char* msg,int errCode))onResponse;

/*
 Description cancel download album file.
 @param onResponse  : the response for p2p message
*/
-(int)stopPlayAlbumFileWithCallback:(void (^)(const char* msg,int errCode))onResponse;

/*
 Description cancel download album file.
 @param onResponse  : the response for p2p message
*/
-(int)pausePlayAlbumFileWithCallback:(void (^)(const char* msg,int errCode))onResponse;

/*
 Description cancel download album file.
 @param onResponse  : the response for p2p message
*/
-(int)resumePlayAlbumFileWithCallback:(void (^)(const char* msg,int errCode))onResponse;


/// get p2p state
- (ThingSmartP2PStateType)getP2pStatus;

/*
  Description query biz skills.
  @param onResponse: the response for p2p biz skills
 */
- (int)queryBizSkillsWithCallback:(void (^)(NSString *message, int errCode))onResponse;

/*
  Description start p2p biz actions.
  @param action: the p2p biz actions.
  {
    "cmd":"biz_action",
    "motor_id":1,
    "action_cnt":2,
    "actions":[
        {"id":0, "rotate" : {"angle" : 60, "speed": 1, "time" : 400}},
        {"id":1, "move" : {"angle" : 0, "speed": 1, "time" : 400, "distance": 20}}
    ]
  }
  @param onResponse: the response for p2p actions.
    * {"cmd" :"resp", "result":0, "cmd_id":101}
  @return the cmdId
 */
- (int)startBizAction:(NSString *)action onResponse:(void (^)(NSString *message, int errCode))onResponse onFinish:(void (^)(NSString *result, int errCode))onFinish;

/*
  Description cancel p2p biz actions.
  @param cmdId: the cmdId when start biz actions.
  @param onResponse: the response for cancel biz actions.
 */
- (int)cancelBizActionWithCmdId:(int)cmdId onResponse:(void (^)(NSString *message, int errCode))onResponse;

@end
