
#import <Foundation/Foundation.h>
#import <ThingSmartCameraBase/ThingSmartCameraBase.h>
#import <ThingSmartCameraBase/ThingSmartCameraType.h>
#import <CoreMedia/CoreMedia.h>

@class ThingSmartCloudVideoPlayer;
@protocol ThingSmartCloudVideoPlayerDelegate <NSObject>

- (void)cloudVideoPlayer:(ThingSmartCloudVideoPlayer *)player didReceivedFrame:(CMSampleBufferRef)frameBuffer videoFrameInfo:(ThingSmartVideoFrameInfo)frameInfo;

- (void)cloudVideoPlayer:(ThingSmartCloudVideoPlayer *)player  didReceivedAudioFrameInfo:(ThingSmartAudioFrameInfo)frameInfo;

- (void)cloudVideoPlayer:(ThingSmartCloudVideoPlayer *)player playbackFragmentDidStart:(ThingSmartPlaybackVideoType)videoType;

- (void)cloudVideoPlayer:(ThingSmartCloudVideoPlayer *)player cloudDataloadFail:(const char *)message;


@end

@interface ThingSmartCloudVideoPlayer : NSObject

@property (nonatomic, strong, readonly) NSString *devId;

@property (nonatomic, assign, getter=isAutoPlay) BOOL autoPlay;

@property (nonatomic, weak) id<ThingSmartCloudVideoPlayerDelegate> delegate;

- (instancetype)initWithDeviceId:(NSString *)devId;

/**
 [^en]
 config cloud data tags.
 [$en]

 */
- (int)configCloudDataTags:(NSString *)jsonCloudDataTags;

- (NSString *)configCloudDataTagsV2:(NSString *)jsonCloudDataTags;

/**
 [^en]
 get cloud  url
 [$en]

 */
- (NSString *)getCloudUrlsWithStartTime:(int)startTime endTime:(int)endTime isEvent:(bool)isEvent authParams:(NSString *)jsonAuthParams encryptKey:(NSString *)encryptKey;

/**
 [^en]
 start play cloud video.
 [$en]

 */
- (int)playCloudDataWithStartTime:(int)nStartTime
                           endTime:(int)nEndTime
                           isEvent:(BOOL)isEvent
                        authParams:(NSString *)jsonAuthParams
                        encryptKey:(NSString *)encryptKey
                        onResponse:(void (^)(int errCode))responseCallback
                          onFinish:(void (^)(int errCode))finishCallBack;
/**
 [^en]
 pause play cloud video.
 [$en]

 @return [^en]error Code, 0 is success.[$en]
 */
- (int)pausePlayCloudVideo;

/**
 [^en]
 resume play cloud video.
 [$en]

 @return [^en]error Code, 0 is success.[$en]
 */
- (int)resumePlayCloudVideo;

/**
 [^en]
 stop play cloud video.
 [$en]

 @return [^en]error Code, 0 is success.[$en]
 */
- (int)stopPlayCloudVideo;

/**
 [^en]
 video frame render view
 [$en]

 
 @return render view
 */
- (UIView<ThingSmartVideoViewType> *)videoView;

/**
 [^en]
 set mute.
 [$en]

 @param mute [^en]mute sound.[$en]
 @param success success call back.
 @param failure failed call back.
 */
- (int)enableMute:(BOOL)mute success:(void(^)(void))success failure:(void (^)(NSError * error))failure;

/**
 [^en]
 get mute state.
 [$en]

 @return [^en]BOOL[$en]
 */
- (BOOL)isMuted;

/**
 [^en]
 start record. video will save to photo album. photo asset collection name is bundle name, "[NSBundle mainBundle].infoDictionary[(__bridge NSString *)kCFBundleNameKey]".
 [$en]

 */
- (int)startRecord;

/**
 [^en]
 start record and the video will save to the file path.
 [$en]


 @param filePath [^en]save path[$en]
 */
- (int)startRecordAtPath:(NSString *)filePath;

/**
 [^en]
 stop record.
 [$en]

 @return [^en]error code. return 0 as record success.[$en]
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
  get a screenshot of the video and save it to file path. if you do not need a thumbnil, set thumbnilPath nil.
 [$en]

 */
- (UIImage *)snapShootAtPath:(NSString *)filePath thumbnilPath:(NSString *)thumbnilPath;

/**
 [^en]
 release resources.
 [$en]

 */
- (void)destroy;

/*
 start download cloud video, saved as mp4
 @param nStartTime Expected start time of the downloaded video
 @param nStopTime Expected end time of the downloaded video
 @param folderPath the folder path to save mp4.
 @param mp4FileName video file name.
 @param callback callback
 @param progressCallBack progressCallBack
 @param finishedCallBack finishedCallBack
*/
- (int)startCloudDataDownloadWithStartTime:(int)startTime stopTime:(int)stopTime folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName authParams:(NSString *)jsonAuthParams encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback onProgress:(void (^)(int errCode, int nPos))progressCallBack onFinish:(void (^)(int errCode))finishedCallBack;

/*
 start download cloud video, saved as mp4
 @param nStartTime Expected start time of the downloaded video
 @param nStopTime Expected end time of the downloaded video
 @param folderPath the folder path to save mp4.
 @param mp4FileName video file name.
 @param callback callback
 @param progressCallBack progressCallBack
 @param finishedCallBack 【Contain the file path，key is 'filePath', success code,key is 'code'】

*/

- (int)startCloudDataDownload:(int)startTime stopTime:(int)stopTime folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName authParams:(NSString *)jsonAuthParams encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback onProgress:(void (^)(int errCode, int nPos))progressCallBack onFinish:(void (^)(NSDictionary *finishInfo))finishedCallBack;

/*
 pause download cloud video
*/
- (int)pauseCloudDataDownloadWithResponse:(void (^)(int))callback;

/*
 resume download cloud video
*/
- (int)resumeCloudDataDownloadWithResponse:(void (^)(int))callback;

/*
 cancel download cloud video
*/
- (int)cancelCloudDataDownloadWithResponse:(void (^)(int))callback;

/**
 [^en] Set cloud storage multiplier playback speed[$en]

 @param speed [^en] multiplier playback speed [$en]
 @return [^en]error code[$en]
 */
- (int)setCloudVideoPlaySpeed:(ThingSmartCameraPlayBackSpeed)speed;

/// Description enable AI play speed for cloud data
/// @param enable enable
/// @param motionSpeed speed of motion [default 1.0]
/// @param noMotionSpeed speed of no motion [default 2.0]
- (int)enablePlayCloudDataAISpeed:(BOOL)enable
                            speed:(ThingSmartCameraPlayBackSpeed)motionSpeed
                    noMotionSpeed:(ThingSmartCameraPlayBackSpeed)noMotionSpeed;

#pragma mark - Video Message

/**
 [^en]
 play encrypt video in detect message
 [$en]

 
 @param url [^en]video path[$en]
 @param nStartTime [^en]Start time to play[$en]
 @param encryptKey [^en]encrypt key[$en]
 @param callback start callback
 @param finihedCallBack finish callback

 @return [^en]error code[$en]
*/
- (int)playVideoMessageWithUrl:(NSString *)url startTime:(int)nStartTime encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finihedCallBack;

/**
 Description Start playing video message with multiple files.
 @param fileInfo An array of video messages, in JSON format,
    *  for example:
    *
    *  { "fileInfo":
    *    [
    *       {
    *            "fileUrl": "xxx.media",
    *             "key": "media key 1",
    *             "videoType" : 0 //0 : normal 1 : aov
    *      },
    *      {
    *          "fileUrl": "xxx.media",
    *            "key": "media key 2",
    *             "videoType" : 0 //0 : normal 1 : aov
    *      },
    *        {
    *          "fileUrl": "xxx.media",
    *          "key": "media key 3",
    *             "videoType" : 0 //0 : normal 1 : aov
    *      }]
    *  }
 @param startTime Start time of the playback.
 @param responseCallback Async result callback.
 @param finishCallBack Completion callback.
 */
- (int)playVideoMessageWithFileInfo:(NSString *)fileInfo startTime:(NSInteger)startTime onResponse:(void (^)(int errCode))responseCallback onFinish:(void (^)(int errCode))finishCallBack;


/**
 Description Start playing cloud video data with multiple files.
 @param fileInfo An array of video messages, in JSON format,
    *  for example:
    *
    *  { "fileInfo":
    *    [
    *       {
    *            "fileUrl": "xxx.media",
    *             "key": "media key 1",
    *             "videoType" : 0 //0 : normal 1 : aov
    *      },
    *      {
    *          "fileUrl": "xxx.media",
    *            "key": "media key 2",
    *             "videoType" : 0 //0 : normal 1 : aov
    *      },
    *        {
    *          "fileUrl": "xxx.media",
    *          "key": "media key 3",
    *             "videoType" : 0 //0 : normal 1 : aov
    *      }]
    *  }
 @param startTime Start time of the playback.
 @param responseCallback Async result callback.
 @param finishCallBack Completion callback.
 */
- (int)playCloudVideoDataWithFileInfo:(NSString *)fileInfo startTime:(NSInteger)startTime onResponse:(void (^)(int errCode))responseCallback onFinish:(void (^)(int errCode))finishCallBack;

- (int)startCloudDataDownloadWithFileInfo:(NSString *)fileInfo folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName thumbnailFileName:(NSString *)thumbnailFileName rotate:(int)rotate success:(void (^)(void))successCallback progress:(void (^)(int))progressCallBack failure:(void (^)(int))failureCallBack;

/**
 Description Start playing video message with multiple files.
 @param fileInfo An array of video messages, in JSON format,
 *  for example:
 *
 *  { "fileInfo":
 *    [
 *       {
 *          "fileUrl": "xxxx.media",
 *          "key": "media key 1",
            "startTimestamp": 1684847822,
            "duration": 5000,
 *      },
 *      {
 *          "fileUrl": "xxxx.media",
 *          "key": "media key 2",
            "startTimestamp": 1684852822,
            "duration": 5000
 *      },
 *        {
 *          "fileUrl": "xxxx.media",
 *          "key": "media key 3",
            "startTimestamp": 1684857822,
            "duration": 5000
 *      }]
 *  }
 @return [^en]error code[$en]
 */
- (int)setVideoMessageFileInfo:(NSString *)fileInfo;


/**
 [^en]
 set cache settings as default is all called by `setVideoMessageFileInfo`
 [$en]

 @param frontSize [^en]max cache nums before current playing[$en]
 @param tailSize [^en]max cache nums after current playing[$en]
 @return [^en]error code[$en]
*/
- (int)setVideoMessageCacheTargetWithFrontSize:(NSInteger)frontSize tailSize:(NSInteger)tailSize;


/**
 [^en]
 pause play video
 [$en]

 
 @return [^en]error code[$en]
*/
- (int)pausePlayVideoMessage;

/**
 [^en]
 resume play video
 [$en]

 
 @return [^en]error code[$en]
*/
- (int)resumePlayVideoMessage;

/**
 [^en]
 stop play video
 [$en]

 
 @return [^en]error code[$en]
*/
- (int)stopPlayVideoMessage;

/**
 [^en]
 play encrypt audio in detect message
 [$en]

 
 @param url [^en]audio path[$en]
 @param nStartTime [^en]Start time to play[$en]
 @param encryptKey [^en]encrypt key[$en]
 @param callback start callback
 @param finihedCallBack finish callback

 @return [^en]error code[$en]
*/
- (int)playAudioMessageWithUrl:(NSString *)url startTime:(int)nStartTime encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finihedCallBack;

- (int)startVideoMessageDownloadWithUrl:(NSString *)url encryptKey:(NSString *)encryptKey filePath:(NSString *)filePath rotateDirection:(ThingSmartVideoRotateDirection)rotateDirection success:(void (^)(void))successCallback progress:(void (^)(int))progressCallBack failure:(void (^)(int))failureCallBack;

- (void)startVideoMessageDownloadWithFileInfoImpl:(NSString *)fileInfo folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName targetSize:(CGSize)targetSize useFirstVideoResolution:(BOOL)useFirstVideoResolution rotation:(ThingSmartVideoRotateDirection)rotation onResponse:(void (^)(const char *msg,int errCode))onResponse onProgress:(void (^)(int errCode, int nPos))onProgress onFinish:(void (^)(const char *msg,int errCode))onFinish;

/**
 [^en]
 pause play audio
 [$en]

 
 @return [^en]error code[$en]
*/
- (int)pausePlayAudioMessage;

/**
 [^en]
 resume play audio
 [$en]

 
 @return [^en]error code[$en]
*/
- (int)resumePlayAudioMessage;

/**
 [^en]
 stop play audio
 [$en]

 
 @return [^en]error code[$en]
*/
- (int)stopPlayAudioMessage;

/*
 start download audio or video in message
 @param url
 @param encryptKey
 @param folderPath
 @param mp4FileName
 @param callback
 @param progressCallBack
 @param finishedCallBack
*/
- (int)startVideoMessageDownloadWithUrl:(NSString *)url encryptKey:(NSString *)encryptKey filePath:(NSString *)filePath success:(void(^)(void))successCallback progress:(void (^)(int progress))progressCallBack failure:(void (^)(int errCode))failureCallBack;

/*
 pause download
*/
- (int)pauseVideoMessageDownload:(void (^)(int errCode))callback;

/*
 resume download
*/
- (int)resumeVideoMessageDownload:(void (^)(int errCode))callback;

/*
 cancel download
*/
- (int)cancelVideoMessageDownload;

/*
 convert MJPEG video into multiple images
 @param urlPath MJPEG video url path
 @param encryptKey
 @param directoryPath local directory path to save image files
 @param successCallback success callback
 @param failureCallback failure callback
*/
- (int)convertMJPEGVideoToImagesWithUrl:(NSString *)urlPath encryptKey:(NSString *)encryptKey imageFileDirectory:(NSString *)directoryPath success:(void(^)(NSArray *imageFiles))successCallback failure:(void(^)(int errCode))failureCallback;

/*
 cancel convert MJPEG video into images
*/
- (int)cancelMJPEGVideoConvert;

- (int)setDeviceFeatures:(NSDictionary *)features;

@end
