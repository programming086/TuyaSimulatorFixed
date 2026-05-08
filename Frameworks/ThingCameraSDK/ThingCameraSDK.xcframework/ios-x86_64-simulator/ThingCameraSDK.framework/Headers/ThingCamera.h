
#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#include "ThingCameraDefines.h"
#import "ThingPlayBackFragmentModel.h"

#import "ThingMediaProcessOption.h"

#import "ThingConnectionParams.h"
@protocol ThingCameraDelegate ;


@interface ThingCamera : NSObject
@property (nonatomic, copy) NSString                *deviceId;               // Device ID
@property (nonatomic,   weak) id<ThingCameraDelegate>  delegate;

- (instancetype)init NS_UNAVAILABLE;

/**
 Description Simple camera initializer.
 
 @param deviceId Device ID.
 @return ThingCamera object.
 */
- (instancetype)initWithDeviceId:(NSString*)deviceId p2pType:(int)p2pType productId:(NSString*) productId NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithDeviceId:(NSString*)deviceId stationId:(NSString*)stationId nodeId:(NSString*)nodeid p2pType:(int)p2pType productId:(NSString*) productId NS_DESIGNATED_INITIALIZER;

/**
 Description Simple Player init with external source.
 
 @param config : init parameters
 @return ThingCamera object.
 */
- (instancetype)initWithConfig:(NSDictionary *)config;

-(int)connectWithUserName:(NSString *)username password:(NSString *)password  serverString:(NSString *)serverString  traceId:(NSString *)traceId ;

-(int)connectWithUserName:(NSString *)username password:(NSString *)password  token:(NSString *)token skills:(NSString *)skills  traceId:(NSString *)traceId forceToLANmode:(BOOL)lanMode ;


/**
    Connect to the camera.
    @param username : Username
    @param password : Password
    @param token : Token
    @param skills : Skills
    @param traceId : Trace ID
    @param lanMode : Force to LAN mode
    @param connectOption : Connect option 0 -- close preconnect, 1 -- open preconnect.
    @return < 0 failed.
 */
-(int)connectWithUserName:(NSString *)username password:(NSString *)password  token:(NSString *)token skills:(NSString *)skills  traceId:(NSString *)traceId forceToLANmode:(BOOL)lanMode connectOption:(int)connectOption ;

-(int)connectWithP2pConnectParams:(ThingConnectionParams *)params;

/**
    Connect to the camera.
    @param username : Username
    @param password : Password
    @param token : Token
    @param skills : Skills
    @param traceId : Trace ID
    @param lanMode : Force to LAN mode
    @param connectOption : Connect option 0 -- close preconnect, 1 -- open preconnect.
    @param  extConfig  json描述p2p的扩展配置
    @return < 0 failed.
 */
-(int)connectWithUserName:(NSString *)username password:(NSString *)password  token:(NSString *)token skills:(NSString *)skills  traceId:(NSString *)traceId forceToLANmode:(BOOL)lanMode connectOption:(int)connectOption extConfg:(NSString *)extConfg;


/**
 
 */
- (int)disconnect;

/**
    Disconnect forced or not.
 */
- (int)disconnectWithForced:(BOOL)forced;
/**
 
 */
- (int)setRemoteOnline;

/**
 Description Get audio params from device (sample rate, bitwidth, channels).

 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)getAudioTalkParams:(void (^)(const char *result, int errCode))onResponse;

/**
 Description Get device current video clarity mode and all support modes.

 @param onResponse Async result onResponse. currentClarity see TRANSFER_VIDEO_CLARITY_TYPE_E. supportClarity see TRANSFER_VIDEO_CLARITY_TYPE_E. errCode see ThingErrCode.
 */
- (int)getVideoClarity:(void (^)(const char* result, int errCode))onResponse;

/*======================================    Preview related           ======================================*/

/**
 Description Set video clarity to device.

 @param clarityMode See TRANSFER_VIDEO_CLARITY_TYPE_E.
 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)setVideoClarity:(int)clarityMode onResponse:(void (^)(const char *msg, int errCode))onResponse;

/**
 Description Startup preview.

 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)startPreviewWithClarityMode:(ThingVideoClarityMode)mode onResponse:(void (^)(const char *msg,int errCode))onResponse;

- (int)startPreviewWithClarityMode:(ThingVideoClarityMode)mode videoOutputFormat:(ThingVideoOutputFormat)videoOutputFormat audioOutputFormat:(ThingAudioOutputFormat)audioOutputFormat onResponse:(void (^)(const char *msg,int errCode))onResponse;
/**
 Description Stop preview.
 
 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)stopPreview:(void (^)(const char *,int errCode))onResponse;

/**
 Description Start preview with external input.
 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)startPlayWithAsyncMode:(ThingSyncMode)sync_mode onResponse:(void (^)(const char *,int errCode))onResponse;

/**
 Description stop external input.
 */
- (int)stopPlay;

- (int)pushVideoWithStreamData:(unsigned char *)data
                 length:(int)length
                 fragmentId:(int)fragmentId
                 codecType:(ThingVideoCodecType)codecType
                 timestamp:(NSTimeInterval)pts
                 attributes:(NSDictionary *)attributes;

- (int)pushAudioWithStreamData:(unsigned char *)data
                 length:(int)length
                 fragmentId:(int)fragmentId
                 codecType:(ThingAudioCodecType)codecType
                 timestamp:(NSTimeInterval)pts
                 sampleRate:(NSInteger)sampleRate
                 channels:(NSInteger)channels
                 bitWidth:(NSInteger)bitWidth
                 attributes:(NSDictionary *)attributes;
                
/*======================================    Audio related interfaces           ======================================*/
/**
 Description Set current mute state.

 @param muted YES: mute, No: not mute.

 */
- (int)setMute:(BOOL)muted ;

/**
 Description Startup voice talk.

 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)startAudioTalk:(void (^)(const char*msg,int errCode))onResponse;

/**
 Description Send audio data to device.

 @param data Audio data.
 @param length Audio data size.
 */
- (int)sendAudioDataWithPCM:(unsigned char *)data length:(int)length sampleRate:(int)sampleRate ;

/**
 Description Stop audio talk.
 */
- (int)stopAudioTalk;


/**
 Description Start audio recording.
 */
- (int)startAudioRecordWithSampleRate:(int)sampleRate channel:(int) channel ;

/**
 Description Stop audio recording.
 */
-(int) stopAudioRecord ;


/*======================================    Video talk            ======================================*/
/**
    Usage:
    1. startVideoTalk
    2. startVideoCapture
    ...
    3. switchCamera
    ...
    4. stopVideoCapture
    ...
    5. stopVideoTalk
 */
/**
    Start video talk.
    @return Failure < 0, Success: the requestId.
 */
-(int)startVideoTalk:(void (^)(const char*msg,int errCode))onResponse;

/**
    Pause send video talk.
 */
-(int)pauseVideoTalk:(void (^)(const char*msg,int errCode))onResponse;

/**
    Resume send video talk.
        @return requestId
        @param errCode requestId
 */
-(int)resumeVideoTalk:(void (^)(const char*msg,int errCode))onResponse;

/**
    Stop video talk.
 */
-(int)stopVideoTalk;

/**
    Open video capture.
    @param width Video width
    @param height Video height
    @param frameRate Frame rate 15 -- 30 (20 default)
    @param requestId The return value of func startVideoTalk
 */
-(int)startVideoCaptureWithWidth:(int)width height:(int)height frameRate:(int)frameRate ;

/**
    Start encode and send video data to devices.
 */
-(int)startSendVideoTalkDataWithRequestId:(int)requestId ;

/**
    Stop encode, stop send video data.
 */
-(int)stopSendVideoTalkData ;

/**
    Switch camera.
 */
-(int)switchCamera ;

/**
    Close the video capture.
 */
-(int)stopVideoCapture ;

/**
    Enable audio effect.
 */
- (int)enableAudioEffect:(bool)enable ;

/**
    Set the audio effect parameters.
    @param pitch Pitch
    @param scale 1.0, other not supported.
 */
- (int)setAudioEffectParametersWithRobotizationSupported:(bool)robotSupported pitch:(float)pitch time_scale:(float)time_scale norm_scale:(float)normal_amp_scale robot_scale:(float)robot_amp_scale ;

/**
    Enable NS or not.
    @param enable YES or NO
 */
- (int)enableAudioNS:(bool)enable ;

/**
    Enable AGC or not.
    @param enable YES or NO
 */
- (int)enableAudioAGC:(bool)enable ;

/**
    Enable AEC or not.
    @param enable YES or NO
 */
- (int)enableAudioAEC:(bool)enable ;

/**
    Set audio capability of device.
    @param capability 0  -- mic and speaker not supported, 1  -- mic supported only, 2  -- speaker supported only, 3  -- mic and speaker supported
 */

/*======================================    Local data playback related           ======================================*/
/**
 Description Get alarm days in one month.

 @param month Format:"201804"
 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)getSDRecordDaysWithMonth:(NSString *)month onResponse:(void (^)(const char *msg, int errCode))onResponse;

/**
 Description Get alarms by day.

 @param day Format:"20180425"
 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)getSDRecordFragmentsWithDay:(NSString *)day onResponse:(void (^)(const char* msg, int errCode))onResponse;

/**
 Description Get alarms by day. Local data encrypt supported.

 @param day Format:"20180425"
 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)getSDRecordFragmentsV2WithDay:(NSString *)day onResponse:(void (^)(const char* msg, int errCode))onResponse;

/**
 Description Get alarms by day. local data encrypt supported

 @param day Format:"20180425"
 @param isEncrypted false
 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)getSDRecordFragmentsV3WithDay:(NSString *)day isEncrypted:(BOOL)isEncrypted onResponse:(void (^)(const char* msg, int errCode))onResponse;
/**
 Description Get alarms by day and pageId.

 @param pageId >= 0
 @param day Format:"20180425"
 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)getSDRecordFragmentsWithPageId:(int)pageId day:(NSString *)day onResponse:(void (^)(const char* msg, int errCode))onResponse ;

/**
 Description Get events by day and pageId.

 @param pageId >= 0
 @param day Format:"20180425"
 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)getSDEventFragmentsWithPageId:(int)pageId day:(NSString *)day onResponse:(void (^)(const char* msg, int errCode))onResponse ;

/**
 Set encryption info for playback.
 @param jsonEncryption Format:{"deviceId":"xxxxxx", "encryptInfos":[ {"uuid":"xxxx1", "encrypt":"xxxxxxx"}, {"uuid":"xxxx2", "encrypt":"xxxxxxx"} ]}
 */
- (int)setEncryptionInfo:(NSString *)jsonEncryption;

/**
 Description Startup SD card playback.

 @param startTime Alarm fragment start timestamp (unix).
 @param stopTime Alarm fragment end timestamp (unix).
 @param playTime From which time point (unix).
 @param onResponse Async result callback. errCode see ThingErrCode.
 @param onFinish Completion callback.
 */
- (int)startPlayBackWithStartTime:(int)startTime stopTime:(int)stopTime playTime:(int)playTime onResponse:(void (^)(const char *msg,int errCode))onResponse onFinish:(void (^)(int startTime,int stopTime,int errCode))onFinish;


- (int)startPlayBackWithStartTime:(int)startTime stopTime:(int)stopTime playTime:(int)playTime videoOutputFormat:(ThingVideoOutputFormat)videoOutputFormat audioOutputFormat:(ThingAudioOutputFormat)audioOutputFormat onResponse:(void (^)(const char *msg,int errCode))onResponse onFinish:(void (^)(int startTime,int stopTime,int errCode))onFinish;

/**
 Triggered when playback fragment changes.
 */
- (int)startPlayBackWithStartTime:(int)startTime stopTime:(int)stopTime playTime:(int)playTime onResponse:(void (^)(const char *msg,int errCode))onResponse onEvent:(void (^)(THING_TASK_EVENT eventType,int info1,int info2,const char *errInfo))onEvent onFinish:(void (^)(int startTime,int stopTime,int errCode))onFinish;

/**
 Description Startup SD card playback.
 @param playTime From which time point (unix).
 @param mode Play all or fragments defined by jsonFragments. 0 -- play all fragments (supported only)
 @param jsonFragments The fragments need to play. JSON format: {"fragments": [{"start": xxx, "end": xxx}, ...]}
 @param onResponse Async result callback. errCode see ThingErrCode.
 @param onFinish Completion callback.
 */
- (int)startPlayBackWithPlayTime:(int)playTime mode:(int)mode jsonFragments:(NSString*)jsonFragments onResponse:(void (^)(const char *msg,int errCode))onResponse onFinish:(void (^)(int startTime,int stopTime,int errCode))onFinish;

/**
 Triggered when playback fragment changes.
 */
- (int)startPlayBackWithPlayTime:(int)playTime mode:(int)mode jsonFragments:(NSString*)jsonFragments onResponse:(void (^)(const char *msg,int errCode))onResponse onEvent:(void (^)(THING_TASK_EVENT eventType,int info1,int info2,const char *errInfo))onEvent onFinish:(void (^)(int startTime,int stopTime,int errCode))onFinish;

/**
 Description Startup SD card playback with local data encryption supported

 @param startTime Alarm fragment start timestamp (unix).
 @param stopTime Alarm fragment end timestamp (unix).
 @param playTime From which time point (unix).
 @param onResponse Async result callback. errCode see ThingErrCode.
 @param onFinish Completion callback.
 */
- (int)startPlayBackV2WithStartTime:(int)startTime stopTime:(int)stopTime playTime:(int)playTime onResponse:(void (^)(const char *msg,int errCode))onResponse onFinish:(void (^)(int startTime,int stopTime,int errCode))onFinish;

- (int)startPlayBackV2WithStartTime:(int)startTime stopTime:(int)stopTime playTime:(int)playTime onResponse:(void (^)(const char *msg,int errCode))onResponse onEvent:(void (^)(THING_TASK_EVENT eventType,int info1,int info2,const char *errInfo))onEvent onFinish:(void (^)(int startTime,int stopTime,int errCode))onFinish;

/**
 Description Pause current SD card playback.

 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)pausePlayBackWithResponse:(void (^)(const char *msg,int errCode))onResponse;

/**
 Description Resume current SD card playback.

 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)resumePlayBackWithResponse:(void (^)(const char *msg,int errCode))onResponse;

/**
 Description Stop current SD card playback.

 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)stopPlayBackWithResponse:(void (^)(const char *msg,int errCode))onResponse;

/**
 Description Set the play speed for SD card playback.
 
 @param speed The play speed.
 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)setPlayBackSpeedWithSpeed:(ThingPlayBackSpeedMode)speed onResponse:(void (^)(const char*msg,int errCode))onResponse;

/**
 Description Set the features for the device.
 @param features JSON format: { "DecPostProcess": { "video": [{"restype": "4", "oldres": "944*1080", "newres": "1920*1080"}, {"restype": "2", "oldres": "944*1080", "newres": "1920*1080"}] "mirror": 0, "rotation" : 2, "message": "1920*1080" }}
 */
- (int)setDeviceFeatures:(NSString *)features;

/**
 Description Set the features for drawing smart rect.
 @param features JSON format: { "SmartRectFeature": { "rgb": 0xFC4747, "shape": 0, "brushWidth": 0, "flashFps": { "drawKeepFrames": 0, "stopKeepFrames": 0 }}}
 */
- (int)setSmartRectFeatures:(NSString *)features;

/**
 Description Set camera configuration.
 */
- (int)setCameraConfig:(NSString *)config ;

/**
 Description Set sub video split info.
 @param json JSON format: { "total_split_num":2, "split_info":[{"type":1,"res_pos":[[0,0,1280,720],[0,0,1920,1080]]}, {"type":2,"res_pos":[[0,720,1280,720],[0,1080,1920,1080]]}]}
 @return 0 -- success, other -- failed
 */
- (int)setVideoSplitInfo:(NSString *)json ;

/**
 Description Enable IVA.
 @param enable Enable/disable
 */
- (int)enableIVA:(BOOL)enable;

/**
 Description Set AOV device.
 @param aov AOV device
 */
- (int)isAOVDevice:(BOOL)aov ;

/**
 Description Get instantaneous bit rate in kBps.
 @return kBps
 */
- (double)getInstantaneousBitRateKBps ;

/**
 Description Start MP4 record.

 @param folderPath Directory path to store MP4 file (not include last "/").
 @param fileName MP4 file name, e.g., "xxxx.mp4".
 */
- (int)startRecordWithFolderPath:(NSString *)folderPath fileName:(NSString *)fileName ;

/**
 Description Start MP4 record.

 @param folderPath Directory path to store MP4 file (not include last "/").
 @param fileName MP4 file name, e.g., "xxxx.mp4".
 @param rotate Video rotate angle while recording MP4 (anti-clockwise).
 */
- (int)startRecordWithFolderPath:(NSString *)folderPath fileName:(NSString *)fileName rotate:(ThingRotateMode)rotate ;

/**
 Description Start MP4 record.

 @param folderPath Directory path to store MP4 file (not include last "/").
 @param fileName MP4 file name, e.g., "xxxx.mp4".
 @param rotate Video rotate angle while recording MP4 (anti-clockwise).
 @param type Sub video index: -1 -- full, 1, 2
 */
- (int)startRecordWithFolderPath:(NSString *)folderPath fileName:(NSString *)fileName rotate:(ThingRotateMode)rotate type:(int)type index:(int)index;

/**
 Description Take a snapshot and save to file.

 @param absoluteFileName Absolute file name.
 @param rotate Snapshot rotate angle (anti-clockwise).
 */
- (int)snapShotWithFileName:(NSString*)absoluteFileName rotate:(ThingRotateMode)rotate ;

/**
 Description Take a snapshot and save to file.

 @param absoluteFileName Absolute file name.
 @param rotate Snapshot rotate angle (anti-clockwise).
 @param type Sub video index.
 @param index Sub video index value.
 */
- (int)snapShotWithFileName:(NSString*)absoluteFileName rotate:(ThingRotateMode)rotate type:(int)type index:(int)index;

/**
 Description Take a snapshot and save to file.

 @param absoluteFileName Absolute file name.
 @param rotate Snapshot rotate angle (anti-clockwise).
 @param type Sub video index.
 @param index Sub video index value.
 @param width Snapshot width.
 @param height Snapshot height.
 */
- (int)snapShotWithFileName:(NSString*)absoluteFileName rotate:(ThingRotateMode)rotate type:(int)type index:(int)index width:(int)width height:(int)height;

/**
 Description Stop MP4 recording.
 @return errCode see ThingErrCode.
 */
- (int)stopRecord;

/**
 Description Stop MP4 recording.
 @param type Sub video index.
 @param index Sub video index value.
 @return errCode see ThingErrCode.
 */
- (int)stopRecordWithType:(int)type index:(int)index;;

/*======================================    Playback download related          ======================================*/

/**
 Description Start SD card playback download. Can download multiple fragments each time.
 @param startTime Alarm fragment start timestamp (unix).
 @param stopTime Alarm fragment end timestamp (unix).
 @param folderPath Directory path to store MP4 file (not include last "/").
 @param mp4FileName MP4 file name, e.g., "xxxx.mp4".
 @param rotate Video rotate angle.
 @param callback Async result callback. errCode see ThingErrCode..
 @param progressCallBack Download progress callback.
 @param onFinish Completion callback.
 */
- (int)startPlayBackDownloadWithStartTime:(int)startTime stopTime:(int)stopTime FolderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName rotate:(ThingRotateMode)rotate onResponse:(void (^)(const char *msg,int errCode))callback onProgress:(void (^)( int nPos,int errCode))progressCallBack onFinish:(void (^)(const char *msg,int errCode))onFinish;

/**
 Description Start SD card playback download. Can download multiple fragments each time. Local data encrypt supported.
 @param startTime Alarm fragment start timestamp (unix).
 @param stopTime Alarm fragment end timestamp (unix).
 @param folderPath Directory path to store MP4 file (not include last "/").
 @param mp4FileName MP4 file name, e.g., "xxxx.mp4".
 @param rotate Video rotate angle.
 @param callback Async result callback. errCode. errCode see ThingErrCode..
 @param progressCallBack Download progress callback.
 @param onFinish Completion callback.
 */
- (int)startPlayBackDownloadV2WithStartTime:(int)startTime stopTime:(int)stopTime FolderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName rotate:(ThingRotateMode)rotate onResponse:(void (^)(const char *msg,int errCode))callback onProgress:(void (^)( int nPos,int errCode))progressCallBack onFinish:(void (^)(const char *msg,int errCode))onFinish;

/**
    Pause download.
 */
- (int)pausePlayBackDownloadWithResponse:(void (^)(const char *msg,int errCode))onResponse;

/**
    Resume download.
 */
- (int)resumePlayBackDownloadWithResponse:(void (^)(const char *msg,int errCode))onResponse;

/**
 Description Stop current SD card playback download.
 
 @param onResponse Async result callback. errCode see ThingErrCode.
 */
- (int)stopPlayBackDownloadWithResponse:(void (^)(const char *msg,int errCode))onResponse;

/**
 Description Stop current SD card playback.
 @param day The day to delete.
 @param onResponse Async result callback. errCode see ThingErrCode.
 @param finishedCallBack Async delete result callback. errCode see ThingErrCode
 */
- (int)deletePlayBackDataWithDay:(NSString *)day onResponse:(void (^)(const char *msg,int errCode))onResponse onFinish:(void (^)(const char*msg,int errCode))finishedCallBack;

/**
 Description Stop current SD card playback.
 @param json The fragments to delete, formatted as {"fragments":[{"startTime":xxx,"endTime":xxx},{"startTime":xxx,"endTime":xxx}]}
 @param onResponse Async result callback. errCode see ThingErrCode.
 @param finishedCallBack Async delete result callback. errCode see ThingErrCode
 */
- (int)deletePlayBackDataWithFragments:(NSString *)json onResponse:(void (^)(const char *msg,int errCode))onResponse onFinish:(void (^)(const char*msg,int errCode))finishedCallBack;

/**
 Description Download the playback event image.
 @param startTime           fragment start timestamp(unix).
 @param stopTime            fragment end timestamp(unix).
 @param folder              the local folder u need to save it.
 @param saveFileName        the local file name u need to save it .
 @param onResponse Async result callback. errCode see ThingErrCode..
*/

- (int)downloadPlayBackImageWithStartTime:(int)startTime stopTime:(int)stopTime FolderPath:(NSString *)folderPath saveFileName:(NSString *)saveFileName onResponse:(void (^)(const char *msg,int errCode))onResponse ;

/**
 Description                download the playback event image.
 @param startTime           fragment start timestamp(unix).
 @param stopTime            fragment end timestamp(unix).
 @param encrypt             1: open encrypt 0:close encrypt.
 @param folderPath              the local folder u need to save it.
 @param saveFileName        the local file name u need to save it .
 @param onResponse Async result callback. errCode see ThingErrCode..
*/
- (int)downloadPlayBackImageV2WithStartTime:(int)startTime stopTime:(int)stopTime encrypt:(int)encrypt FolderPath:(NSString *)folderPath saveFileName:(NSString *)saveFileName onResponse:(void (^)(const char *msg,int errCode))onResponse;

/*======================================    Album related           ======================================*/

/**
 Description Switch channel.
 @param channel Channel ID.
 @param onResponse Async result callback. errCode see ThingErrCode.
 */
-(int)switchChannelWithChannel:(int)channel onResponse:(void (^)(const char *msg,int errCode))callback ;

/**
 Description Query all files by album name.
 @param albumName The name of album. The album name's max length is 48.
 @param onResponse Response for p2p message.
 */
-(int)queryAlbumFileIndexWithAlbumName:(NSString*)albumName onResponse:(void (^)(const char *jsonindex, int errCode))onResponse ;

/**
 Description Start downloading album file.
 @param albumName The name of the album. The album name's max length is 48.
 @param jsonfiles Files to be downloaded, in JSON format: {"files":["xxx.jpg","xxx.mp4"]} or {"files":[]}.
 @param thumbnail Whether to download thumbnail or not; if true, file suffix must be jpg.
 @param onResponse Response for p2p message.
 @param onAllProgressCallBack Progress of downloading all files.
 @param onSingleFileProgress Progress of downloading a single file.
 @param onFileDownloadFinish Callback when all files download is finished.
 */
-(int)startDownloadAlbumFileWithAlbumName:(NSString*)albumName folder:(NSString*)folder jsonfiles:(NSString*)jsonfiles thumbnail:(Boolean)thumbnail onResponse:(void (^)(const char* msg,int errCode))onResponse onAllProgress:(void (^)(int progress,int errCode))onAllProgressCallBack onSingleFileProgress:(void (^)(const char *filename,int progress,int errCode))onSingleFileProgress onFileDownloadFinish:(void (^)(const char* filename,int index ,int errCode))finishedCallBack;

/**
 Description Cancel download of album file.
 @param onResponse Response for p2p message.
 */
-(int)cancelDownloadAlbumFileWithCallback:(void (^)(const char*msg, int errCode))onResponse ;

/**
 Description Delete the album file. Thumbnail file will also be deleted.
 @param albumName The name of album. The album name's max length is 48.
 @param jsonfiles Files to be deleted, in JSON format: {"files":["xxx.jpg","xxx.mp4"]} or {"files":[]}.
 @param onResponse Response for p2p message.
 @param onFinish Callback for all file deletion finished.
 */
-(int)deleteAlbumFileWithAlbumName:(NSString*)albumName jsonfiles:(NSString*)jsonfiles onResponse:(void (^)(const char*msg,int errCode))onResponse onFinish:(void (^)(const char*msg,int errCode))finishedCallBack;

/**
 Description Start playing album file.
 @param startTime The start time expect to play (ranges from 0 to video duration).
 @param albumName The name of album. The album name's max length is 48.
 @param fileName The name of file. The file name's max length is 48.
 @param thumbnail Whether to play thumbnail; if true, file suffix must be jpg.
 @param onResponse Response for p2p message.
 @param onFileFinished Callback when file play is finished.
 */
-(int)startPlayAlbumFileWithStartTime:(int)startTime albumName:(NSString*)albumName fileName:(NSString*)fileName thumbnail:(Boolean)thumbnail onResponse:(void (^)(const char *msg,int errCode))onResponse onFileDownloadFinish:(void (^)(const char* filename,int index ,int errCode))onFileFinished;

/**
 Description Cancel playing album file.
 @param onResponse Response for p2p message.
 */
-(int)cancelPlayAlbumFileWithCallback:(void (^)(const char* msg,int errCode))onResponse;

/**
 Description Stop playing album file.
 @param onResponse Response for p2p message.
 */
-(int)stopPlayAlbumFileWithCallback:(void (^)(const char* msg,int errCode))onResponse;

/**
 Description Pause playing album file.
 @param onResponse Response for p2p message.
 */
-(int)pausePlayAlbumFileWithCallback:(void (^)(const char* msg,int errCode))onResponse;

/**
 Description Resume playing album file.
 @param onResponse Response for p2p message.
 */
-(int)resumePlayAlbumFileWithCallback:(void (^)(const char* msg,int errCode))onResponse;

/*======================================    Cloud storage playback related           ======================================*/

/**
 Description Configure cloud data tags.
 
 @param jsonCloudDataTags Cloud data tags in JSON format, obtained from HTTP server.
 */
- (int)configCloudDataTags:(NSString *)jsonCloudDataTags;

/**
 Description Configure cloud data tags (Microsoft Cloud).
 
 @param jsonCloudDataTags Cloud data tags in JSON format, obtained from HTTP server.
 @return Array.
 */
- (NSString *)configCloudDataTagsV2:(NSString*)jsonCloudDataTags;

/**

    Description Config cloud data tags (ali cloud).
    @param jsonCloudDataTags Cloud data tags, json get from http server.
 */
- (int)configCloudDataTagsV3:(NSString*)jsonCloudDataTags;



/* @param startTime Start time.
 @param endTime End time.
 @param isEvent Whether it is an event.
 @param jsonAuthParams Auth data in JSON format.
 @param encryptKey Encrypt key.
 @return Array of URLs.
 */
- (char*)getCloudUrlsWithStartTime:(int)startTime endTime:(int)endTime isEvent:(bool)isEvent authParams:(NSString *)jsonAuthParams encryptKey:(NSString *)encryptKey ;


/**
 Description Start playing cloud data.

 @param startTime The start time expect to play (unix time in seconds).
 @param endTime The end time expect to stop (unix time in seconds).
 @param isEvent Whether it is an event.
 @param jsonAuthParams Auth data in JSON format, obtained from HTTP server.
 @param encryptKey Encrypt key to decrypt media data.
 @param onResponse Async result callback. errCode see ThingErrCode..
 @param onFinish Completion callback.
 */
- (int)playCloudDataWithStartTime:(int)startTime endTime:(int)endTime isEvent:(bool)isEvent authParams:(NSString *)jsonAuthParams encryptKey:(NSString *)encryptKey onResponse:(void (^)(const char*msg,int errCode))onResponse onFinish:(void (^)(const char*msg,int errCode))onFinish;

/**
 Triggered when playback fragment changes.
 */
- (int)playCloudDataWithStartTime:(int)startTime endTime:(int)endTime isEvent:(bool)isEvent authParams:(NSString *)jsonAuthParams encryptKey:(NSString *)encryptKey onResponse:(void (^)(const char*msg,int errCode))onResponse onEvent:(void (^)(THING_TASK_EVENT eventType,int info1,int info2,const char *errInfo))onEvent onFinish:(void (^)(const char*msg,int errCode))onFinish;

/**
 Description Start playing clouddata with fileinfos.
 @param fileInfo An array of cloud data urls, in JSON format. Required fields:
    - fileUrl: Media file URL
    - key: Encryption key
    - vType: Video codec type
    - vWide: Video width
    - vHigh: Video height
    - vFps: Video frame rate
    - aType: Audio codec type
    - aSampling: Audio sample rate
    - aChannels: Audio channels
    - aBitwide: Audio bit width
    - cloudProvider: Cloud storage provider (s3/oss/cos) - required if not set externally
    *
    *  Example:
    *  { "fileInfo":
    *    [
    *       {
    *           "fileUrl": "xxxx.media",
    *           "key": "media key 1",
    *           "vType": 4,
    *           "vWide": 1920,
    *           "vHigh": 1080,
    *           "vFps": 25,
    *           "aType": 101,
    *           "aSampling": 8000,
    *           "aChannels": 1,
    *           "aBitwide": 16,
    *           "cloudProvider": "s3"
    *      }]
    *  }
 @param startTime Start time of the playback.
 @param onResponse Async result callback.
 @param onEvent Event callback.
 @param onFinish Completion callback.
 */
- (int)playCloudDataWithFileInfo:(NSString *)fileInfo startTime:(int)startTime onResponse:(void (^)(const char* msg,int errCode))onResponse  onEvent:(void (^)(THING_TASK_EVENT eventType,int info1,int info2,const char *errInfo))onEvent onFinish:(void (^)(const char*msg,int errCode))onFinish;

/**
 Description Set the play speed for cloud data.
 
 @param speed The play speed.
 */
- (int)setPlayCloudDataSpeedWithSpeed:(ThingPlayBackSpeedMode)speed;

/**
 Description Pause current cloud data playback.

 @return errCode see ThingErrCode.
 */
- (int)pausePlayCloudData;

/**
 Description Resume current cloud data playback.

 @return errCode see ThingErrCode.
 */
- (int)resumePlayCloudData;

/**
 Description Stop current cloud data playback.

 @return errCode see ThingErrCode.
 */
- (int)stopPlayCloudData;

/**
 Description enable AI play speed for cloud data.
 
 @param enable 是否启用
 @param motionSpeed 检测到移动时的倍速（默认1.0x）
 @param noMotionSpeed 无移动时的倍速（默认2.0x）
 */
- (int)enablePlayCloudDataAISpeed:(BOOL)enable motionSpeed:(ThingPlayBackSpeedMode)motionSpeed noMotionSpeed:(ThingPlayBackSpeedMode)noMotionSpeed;

/*======================================    Cloud storage download related           ======================================*/

/**
 Description Start cloud data download.
 @param startTime Cloud storage video start time.
 @param stopTime Cloud storage video end time.
 @param folderPath Directory path to store MP4 file (not include last "/").
 @param mp4FileName MP4 file name.
 @param jsonAuthParams Auth data in JSON format.
 @param encryptKey Encrypt key.
 @param onResponse Async result callback. errCode see ThingErrCode..
 @param progressCallBack Download progress callback.
 @param onFinish Completion callback.
 */
- (int)startCloudDataDownloadWithStartTime:(int)startTime stopTime:(int)stopTime folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName authParams:(NSString *)jsonAuthParams encryptKey:(NSString *)encryptKey onResponse:(void (^)(const char *msg,int errCode))onResponse onnProgress:(void (^)(int errCode, int nPos))progressCallBack onFinish:(void (^)(const char *msg,int errCode))finishedCallBack;

/**
 Start cloud data download with video rotation.
 */
- (int)startCloudDataDownloadWithStartTime:(int)startTime stopTime:(int)stopTime folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName authParams:(NSString *)jsonAuthParams encryptKey:(NSString *)encryptKey rotate:(ThingRotateMode)rotate onResponse:(void (^)(const char *msg,int errCode))onResponse onnProgress:(void (^)(int errCode, int nPos))progressCallBack onFinish:(void (^)(const char *msg,int errCode))finishedCallBack;

/**
 Start cloud data download with file info.
 
 @param fileInfo Cloud data file information array in JSON format. Required fields:
    - fileUrl: Media file URL
    - key: Encryption key
    - videoType: Video type
    - vType: Video codec type
    - vWide: Video width
    - vHigh: Video height
    - vFps: Video frame rate
    - aType: Audio codec type
    - aSampling: Audio sample rate
    - aChannels: Audio channels
    - aBitwide: Audio bit width
    - cloudProvider: Cloud storage provider (s3/oss/cos)
    - version: Protocol version (optional)
 @param folderPath Folder path for saving downloaded file.
 @param mp4FileName MP4 file name.
 @param thumbnailFileName Thumbnail file name.
 @param rotate Video rotation mode.
 @param onResponse Async result callback.
 @param progressCallBack Download progress callback.
 @param finishedCallBack Completion callback.
 @return Error code, see ThingErrCode.
 */
- (int)startCloudDataDownloadWithFileInfo:(NSString *)fileInfo folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName thumbnailFileName:(NSString *)thumbnailFileName rotate:(ThingRotateMode)rotate onResponse:(void (^)(const char *msg,int errCode))onResponse onnProgress:(void (^)(int errCode, int nPos))progressCallBack onFinish:(void (^)(const char *msg,int errCode))finishedCallBack;

/**
 Pause cloud data download.
 */
- (int)pauseCloudDataDownload ;

/**
 Resume cloud data download.
 */
- (int)resumeCloudDataDownload;

/**
 Cancel cloud data download.
 */
- (int)cancelCloudDataDownload ;

/*======================================    Video message download related ======================================*/

/**
 Description Start video message download.
 @param url URL of the video message.
 @param encryptKey Encrypt key.
 @param folderPath Folder path.
 @param mp4FileName MP4 File name.
 @param onResponse Async result callback.
 @param onProgress Download progress callback.
 @param onFinish Completion callback.
 */
- (int)startVideoMessageDownloadWithUrl:(NSString *)url encryptKey:(NSString *)encryptKey folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName onResponse:(void (^)(const char*msg,int errCode))onResponse onProgress:(void (^)(int nPos,int errCode))onProgress onFinish:(void (^)(const char*msg,int errCode))onFinish;

/**
 Start video message download with video rotation.
 */
- (int)startVideoMessageDownloadWithUrl:(NSString *)url encryptKey:(NSString *)encryptKey folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName rotate:(ThingRotateMode)rotate onResponse:(void (^)(const char *msg,int errCode))onResponse onProgress:(void (^)(int nPos,int errCode))onProgress onFinish:(void (^)(const char *msg,int errCode))onFinish;

/**
 Description Start video message download with multiple files.
 @param fileInfo An array of video messages, in JSON format.
 @param folderPath Folder path to save the video.
 @param mp4FileName MP4 file name.
 @param option Media process options.
 @param onResponse Async result callback.
 @param onProgress Download progress callback.
 @param onFinish Completion callback.
 */
- (int)startVideoMessageDownloadWithFileInfo:(NSString *)fileInfo folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName ThingMediaProcessOption:(ThingMediaProcessOption*)option onResponse:(void (^)(const char *msg,int errCode))onResponse onProgress:(void (^)(int nPos,int errCode))onProgress onFinish:(void (^)(const char *msg,int errCode))onFinish;

/**
 Description Pause video message download.
 */
- (int)pauseVideoMessageDownload;

/**
 Description Resume video message download.
 */
- (int)resumeVideoMessageDownload;

/**
 Description Cancel video message download.
 */
- (int)cancelVideoMessageDownload;

/*======================================    Video message playback related ======================================*/

/**
 Description Start playing video message.
 @param url URL of the video message.
 @param startTime Start time of the playback.
 @param encryptKey Encrypt key.
 @param onResponse Async result callback.
 @param onFinish Completion callback.
 */
- (int)playVideoMessageWithUrl:(NSString *)url startTime:(int)startTime encryptKey:(NSString *)encryptKey onResponse:(void (^)(const char* msg,int errCode))onResponse onFinish:(void (^)(const char*msg,int errCode))onFinish;

/**
 Description Start playing video message with multiple files.
 @param fileInfo An array of video messages, in JSON format,
    *  for example:
    *
    *  { "fileInfo":
    *    [
    *       {
    *           "fileUrl": "xxxx.media",
    *           "key": "media key 1",
    *           "videoType" : 0, //0 : normal 1 : aov
    *           "startTimestamp": 1684847822, // optional
    *           "duration": 5000 // optional
    *      },
    *      {
    *           "fileUrl": "xxxx.media",
    *           "key": "media key 2",
    *           "videoType" : 0, //0 : normal 1 : aov
    *           "startTimestamp": 1684852822, // optional
    *           "duration": 5000 // optional
    *      },
    *      {
    *           "fileUrl": "xxxx.media",
    *           "key": "media key 3",
    *           "videoType" : 0, //0 : normal 1 : aov
    *           "startTimestamp": 1684857822, // optional
    *           "duration": 5000, // optional
    *      }]
    *  } 
 @param startTime Start time of the playback.
 @param onResponse Async result callback.
 @param onEvent Event callback.
 @param onFinish Completion callback.
 */
- (int)playVideoMessageWithFileInfo:(NSString *)fileInfo startTime:(int)startTime onResponse:(void (^)(const char* msg,int errCode))onResponse  onEvent:(void (^)(THING_TASK_EVENT eventType,int info1,int info2,const char *errInfo))onEvent onFinish:(void (^)(const char*msg,int errCode))onFinish;

/**
 Description Set video message fileinfos for file cache.
 @param fileInfo An array of video messages, in JSON format
*/
- (int)setVideoMessageFileInfo:(NSString *)fileInfo;

/**
 Description Configure video message cache target.
 @param frontSize Front cache size.
 @param tailSize Tail cache size.
 */
- (int)configVideoMessageCacheTarget:(int)frontSize tailSize:(int)tailSize;

/**
 Description Pause video message playback.
 */
- (int)pausePlayVideoMessage;

/**
 Description Resume video message playback.
 */
- (int)resumePlayVideoMessage;

/**
 Description Stop video message playback.
 */
- (int)stopPlayVideoMessage;

/*======================================    Audio message playback related ======================================*/

/**
 Start playing audio message.
 @param url URL of the audio message.
 @param startTime Start time of the playback.
 @param encryptKey Encrypt key.
 @param onResponse Async result callback.
 @param onFinish Completion callback.
 */
- (int)startPlayAudioMessageWithUrl:(NSString *)url startTime:(int)startTime encryptKey:(NSString *)encryptKey onResponse:(void (^)(const char*msg,int errCode))onResponse  onFinish:(void (^)(const char*msg,int errCode))onFinished ;

/**
 Pause audio message playback.
 */
- (int)pausePlayAudioVideoMessage ;

/**
 Resume audio message playback.
 */
- (int)resumePlayAudioMessage;

/**
 Stop audio message playback.
 */
- (int)stopPlayAudioMessage ;

/*======================================    Extract jpeg images from video message related ======================================*/

/**
 Description Start converting I-frames to images from the video message.
 @param url URL of the video message.
 @param encryptKey Encrypt key.
 @param folderPath Folder path to save images.
 @param onFinish Completion callback.
 */
- (int)startConvertIFrameToImageForVideoMessageWithUrl:(NSString *)url encryptKey:(NSString *)encryptKey folderPath:(NSString *)folderPath  onFinish:(void (^)(const char *result, int errCode))onFinish;

/**
 Description Cancel converting I-frames to images.
 */
- (int)cancelConvertIFrameToImageForVideoMessage ;

/**
 Description Link sub-device to NVR.
 @param index NVR sub-device index.
 @param session_id Session ID.
 @param username Username.
 @param password Password.
 @param onResponse Response callback.
 */
- (int)linkToNvrWithIndex:(NSInteger)index session_id:(NSInteger)session_id username:(NSString *)username password:(NSString *)password onResponse:(void (^)(const char* msg,int errCode))onResponse;

/**
 Description Get connection mode.
 @return Connection mode. < 0 for error.
 */
- (int)getConnectionMode;


-(int)bizSkillQueryWithResponse:(void (^)(const char*msg,int errCode))onResponse;

/**
 action :
     {
       "cmd":"biz_action",
       "motor_id":1,
       "action_cnt":1,
       "actions":[
         {"id":0, "rotate" : {"direction" : "left", "speed": 1, "time" : 400}}
       ]
     }
    return cmdId .
 */
-(int)bizActionControlWithAction:(NSString*)action onResponse:(void (^)(const char*msg,int errCode))onResponse onFinish:(void (^)(const char *result, int errCode))onFinish;

/**
    
 */
-(int)bizActionCancelWithCmdId:(int)cmdId onResponse:(void (^)(const char*msg,int errCode))onResponse ;

/*
 value return:
    typedef enum{
        kThingP2pStatusStep_Empty,                                   // 完全未连接前 (或者连接失败，调用了p2pclose之后)
        kThingP2pStatusStep_Connecting,                              // 正在连接
        kThingP2pStatusStep_Connected,                               // 连接成功
        kThingP2pStatusStep_ConnectFailed,                           // 连接失败
    }ThingP2pStatus;
 */
- (int)getP2pStatus;

@end

@protocol ThingCameraDelegate<NSObject>
@optional

/**
 Description The decoded image data callback.
 
 @param device Which camera the data belongs to.
 @param sampleBuffer A CMSampleBufferRef containing one decoded image data.
 @param videoFrameInfo Video frame metadata, see ThingVideoFrameInfo.
 */
- (void)device:(ThingCamera *)device didVideoFrameRecvedWithSampleBuffer:(CMSampleBufferRef)sampleBuffer videoFrameInfo:(ThingVideoFrameInfo *)videoFrameInfo;

/**
 Description Local video data received callback.
 */
- (void)device:(ThingCamera *)device didLocalVideoRecvedWithSampleBuffer:(CMSampleBufferRef)sampleBuffer width:(int)width height:(int)height ;

/**
 Description Callback for receiving event information.
 
 @param device Which camera the data belongs to.
 @param event Camera event type, defined in THING_EVENT_TYPE_E.
 @param error Error code, defined in THING_EVENT_ERROR_CODE_E.
 @param intValue Integer value associated with the event.
 @param strValue String value associated with the event.
 */
- (void)device:(ThingCamera *)device didEventReceivedEventType:(THING_EVENT_TYPE_E)event errorCode:(int)error intValue:(long long)intValue strValue:(NSString*)strValue;

/**
 Description Callback for received decoded audio data.
 
 @param device Which camera the data belongs to.
 @param pcm PCM data.
 @param PCMLength PCM data size.
 @param audioInfo Audio metadata, see ThingAudioFrameInfo.
 */
- (void)device:(ThingCamera *)device didAudioDataRecvedWithPCM:(const unsigned char *)pcm length:(unsigned int)PCMLength audioFrameInfo:(ThingAudioFrameInfo *)audioInfo;

/**
 Description Callback for audio playback.
 
 @param device Which camera the data belongs to.
 @param audioInfo Audio metadata, see ThingAudioFrameInfo.
 */
- (void)device:(ThingCamera *)device didAudioPlayWithAudioInfo:(ThingAudioFrameInfo *)audioInfo;

/**
 Description Callback for session status changes.
 
 @param device Which camera.
 @param status Current session status.
 */
- (void)device:(ThingCamera *)device didSessionStatusChangedWithStatus:(NSInteger)status;

/**
 Description Audio record data received callback.
 
 @param device Which camera the data belongs to.
 @param pcm The audio data.
 @param length The PCM data size in bytes.
 @param samplRate The sample rate of the audio data.
 @param channel Number of audio channels.
 */
- (void)device:(ThingCamera *)device didAudioRecordDataReceiveWithPCM:(const unsigned char*)pcm length:(int)length sampleRate:(int)samplRate channel:(int)channel;

/**
 Description Remote request received callback.
 
 @param device Which camera the request belongs to.
 @param operation The type of operation requested.
 @param requestId The ID of the request.
 */
- (int)device:(ThingCamera *)device didRemoteRequestReceivedWithType:(ThingRequestType)operation requestId:(int)requestId ;


- (int)device:(ThingCamera *)device didVideoPacketRecvWithCodec:(Thing_AV_CODEC_ID)codec stream:(unsigned char*)stream streamLength:(int)streamLength iframe:(int)iframe ;


- (int)device:(ThingCamera *)device didAudioPacketRecvWithCodec:(Thing_AV_CODEC_ID)codec stream:(unsigned char*)stream streamLength:(int)streamLength sampleRate:(int)sampleRate channel:(int)channel;
@end
