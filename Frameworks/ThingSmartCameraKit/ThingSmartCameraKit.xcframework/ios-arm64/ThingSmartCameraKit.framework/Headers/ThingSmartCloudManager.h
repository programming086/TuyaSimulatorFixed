
#import <Foundation/Foundation.h>
#import "ThingSmartCloudModels.h"
#import <CoreMedia/CoreMedia.h>
#import <ThingSmartCameraBase/ThingSmartCameraBase.h>
#import <ThingSmartCameraBase/ThingSmartCameraType.h>
#import "ThingCameraAIDetectConfigModel.h"

typedef NSUInteger ThingDeviceAttributeBitIndex;

FOUNDATION_EXPORT ThingDeviceAttributeBitIndex const ThingDeviceAttributeCloudStorageBitIndex;

typedef NS_ENUM(NSUInteger, ThingSmartCloudState) {
    ThingSmartCloudStateNoService,       // [^en]no cloud service[$en]
    ThingSmartCloudStateNoData,          // [^en]in cloud service but no data[$en]
    ThingSmartCloudStateValidData,       // [^en]in cloud service and has video data[$en]
    ThingSmartCloudStateExpiredNoData,   // [^en]cloud service has being expired and no data[$en]
    ThingSmartCloudStateExpiredData,     // [^en]cloud service has being expired but has video data[$en]
    ThingSmartCloudStateLoadFailed       // [^en]load cloud data failed[$en]
};

typedef void(^DownloadSuccess)(NSString *filePath);
typedef void(^DownloadSuccessHandler)(NSDictionary *info);
typedef void(^DownloadFailure)(NSError *error);
typedef void(^DownloadProgress)(NSUInteger progress);
typedef void (^ThingFetchSecretKeyCompletion)(NSString *result,NSError *error);

@class ThingSmartCloudManager;
@protocol ThingSmartCloudManagerDelegate <NSObject>

@optional

- (void)cloudManager:(ThingSmartCloudManager *)cloudManager didReceivedFrame:(CMSampleBufferRef)frameBuffer videoFrameInfo:(ThingSmartVideoFrameInfo)frameInfo;

- (void)cloudManager:(ThingSmartCloudManager *)player  didReceivedAudioFrameInfo:(ThingSmartAudioFrameInfo)frameInfo;

- (void)cloudManager:(ThingSmartCloudManager *)cloudManager playbackFragmentDidStart:(ThingSmartPlaybackVideoType)videoType;

- (void)cloudManager:(ThingSmartCloudManager *)cloudManager cloudDataloadFail:(const char *)message;


@end

@interface ThingSmartCloudManager : NSObject

/**
 * whether to support cloud storage
 * @param devId get from DeviceModel. Please obtain the device information first
 * @return CloudStorage is supported.
 */
+ (BOOL)isSupportCloudStorage:(NSString *)devId;

/**
 * fetch secret key
 * @param devId
 * @completion return secret key or error.
 */
+ (void)fetchSecretKeyWithDevId:(NSString *)devId completion:(ThingFetchSecretKeyCompletion)completion;

@property (nonatomic, strong) NSString *devId;

@property (nonatomic, assign) BOOL autoRender;

@property (nonatomic, strong, readonly) NSArray<ThingSmartCloudDayModel *> *cloudDays;

@property (nonatomic, weak) id<ThingSmartCloudManagerDelegate> delegate;

@property (nonatomic, strong) NSString *encryptKey;

@property (nonatomic, strong) NSString *authJson;

@property (nonatomic, strong) NSTimeZone *timeZone;

@property (nonatomic, assign) CGSize videoStretchSize;

/**
[^en]
Enable image encryption, which is disabled by default. After opening, the pictures carried in the event model will be encrypted, and you need to use the ThingEncryptImage component to display or download the pictures.
[$en]

*/
@property (nonatomic, assign) BOOL enableEncryptedImage __deprecated_msg("This method is deprecated");

- (instancetype)initWithDeviceId:(NSString *)devId;

/**
 [^en]
 config cloud data tags. if you want reqeust cloud data for service api by yourself instead of use "loadCloudData:", you shoud call this method before play cloud video.
 [$en]


 @param jsonCloudDataTags [^en]cloud data tags[$en]
 */
- (int)configCloudDataTags:(NSString *)jsonCloudDataTags;

- (NSString *)configCloudDataTagsV2:(NSString *)jsonCloudDataTags;

/**
 [^en]
 fetch cloud storage service state
 [$en]

 @param completion callback
 */
- (void)fetchCloudStorageStateCompletion:(void(^)(ThingSmartCloudState state))completion;

/**
 [^en]
 load cloud data
 [$en]

 @param complete callback
 */
- (void)loadCloudData:(void(^)(ThingSmartCloudState state))complete;

/**
 [^en]
 reload cloud days
 [$en]

 
 @param complete callback
 */
- (void)reLoadCloudDays:(void(^)(NSArray<ThingSmartCloudDayModel *> *cloudDays))complete;

- (void)enableAIDetect:(BOOL)enable
               success:(void (^)(BOOL result))success
               failure:(void (^)(NSError * error))failure;

- (void)queryAIDetectConfigSuccess:(void (^)(ThingCameraAIDetectConfigModel *model))success
                           failure:(void (^)(NSError *error))failure;

- (void)enableAIDetectEventType:(NSString *)type
                         enable:(BOOL)enable
                        success:(void (^)(BOOL result))success
                        failure:(void (^)(NSError *error))failure;

/**
 [^en]
 get time event of the day
 [$en]

 @param cloudDay [^en]target day[$en]
 @param offset [^en]event index offset[$en]
 @param limit  [^en]event count limit, -1 is get all[$en]
 @param aiCodes aiCodes
 @param success success callback
 @param failure failure callback
 */
- (void)timeEventsWithCloudDay:(ThingSmartCloudDayModel *)cloudDay
                        offset:(int)offset
                         limit:(int)limit
                       aiCodes:(NSString *)aiCodes
                       success:(void(^)(NSArray<ThingSmartCloudTimeEventModel *> * timeEvents))success
                       failure:(void(^)(NSError * error))failure;
/**
 [^en]
 get time event of the day
 [$en]

 @param cloudDay [^en]target day[$en]
 @param offset [^en]event index offset[$en]
 @param limit  [^en]event count limit, -1 is get all[$en]
 @param success success callback
 @param failure failure callback
 */
- (void)timeEventsWithCloudDay:(ThingSmartCloudDayModel *)cloudDay
                        offset:(int)offset
                         limit:(int)limit
                       success:(void(^)(NSArray<ThingSmartCloudTimeEventModel *> * timeEvents))success
                       failure:(void(^)(NSError * error))failure;

/**
 [^en]
 get cloud  urls
 [$en]

 */
- (NSArray *)getCloudUrlsWithStartTime:(int)startTime endTime:(int)endTime isEvent:(bool)isEvent;

/**
 [^en]
 get cloud  urls
 [$en]

 */
- (NSArray *)getCloudUrlsWithStartTime:(int)startTime endTime:(int)endTime isEvent:(bool)isEvent failure:(void(^)(NSError * error))failure;


/**
 [^en]
 get time line data of the day
 [$en]

 @param cloudDay [^en]target day[$en]
 @param success success callback
 @param failure failure callback
 */
- (void)timeLineWithCloudDay:(ThingSmartCloudDayModel *)cloudDay
                     success:(void(^)(NSArray<ThingSmartCloudTimePieceModel *> * timePieces))success
                     failure:(void(^)(NSError * error))failure;


/**
 [^en]
 play cloud video
 [$en]


 @param startTime [^en]start time[$en]
 @param endTime [^en]end time. cloud video will auto continue util the last video finished in the day[$en]
 @param isEvent [^en]YES is the time event, NO is the time line video.[$en]
 @param responseCallback [^en]errCode 0 is success, negative is failed.[$en]
 @param finishedCallback [^en]video is finished[$en]
 */
- (int)playCloudVideoWithStartTime:(long)startTime
                            endTime:(long)endTime
                            isEvent:(BOOL)isEvent
                         onResponse:(void(^)(int errCode))responseCallback
                         onFinished:(void(^)(int errCode))finishedCallback;


- (int)playCloudVideoWithTargetSegments:(NSString *)prefix
                       videoSegmentSize:(int)videoSegmentSize
                               segments:(NSArray *)segmentes
                             onResponse:(void(^)(int errCode))responseCallback
                             onFinished:(void(^)(int errCode))finishedCallback;


/**
 [^en]
 pause play
 [$en]


 @return [^en]errCode 0 is success[$en]
 */
- (int)pausePlayCloudVideo;


/**
 [^en]
 resume play
 [$en]


 @return [^en]errCode 0 is success[$en]
 */
- (int)resumePlayCloudVideo;


/**
 [^en]
 stop play
 [$en]


 @return [^en]errCode 0 is success[$en]
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

 @return BOOL
 */
- (BOOL)isMuted;

/**
 [^en]
 start record.
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
  stop record. video will save to photo album. photo asset collection name is bundle name, "[NSBundle mainBundle].infoDictionary[(__bridge NSString *)kCFBundleNameKey]".
 [$en]

 @return [^en]error code. return 0 as record success.[$en]
 */
- (int)stopRecord;

/**
 [^en]
 get a screenshot of th video and save it to photo album. photo asset collection name is bundle name, "[NSBundle mainBundle].infoDictionary[(__bridge NSString *)kCFBundleNameKey]".
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
 destory resource
 [$en]

 */
- (void)destroy;

/*
 [^en] download a cloud video [$en]

 
 @param timeRange   [^en] Time period of the video you want to download. [$en]
 @param videoPath   [^en] file path to save video, ex: "folderPath/fileName.mp4". [$en]
 @param success     [^en] download success callback. [$en]
 @param progress    [^en] download progress callback, progress is an integer from 1 to 100. [$en]
 @param failure     [^en] download failed callback. [$en]
*/
- (int)downloadCloudVideoWithRange:(NSRange)timeRange
                           filePath:(NSString *)videoPath
                            success:(DownloadSuccess)success
                           progress:(DownloadProgress)progress
                            failure:(DownloadFailure)failure;

/*
 [^en] download a cloud video [$en]

 
 @param timeRange   [^en] Time period of the video you want to download. [$en]
 @param videoPath   [^en] file path to save video, ex: "folderPath/fileName.mp4". [$en]
 @param success     [^en] download success callback.[contain filePath、code] [$en]
 @param progress    [^en] download progress callback, progress is an integer from 1 to 100. [$en]
 @param failure     [^en] download failed callback. [$en]
*/
- (int)downloadCloudVideo:(NSRange)timeRange
                 filePath:(NSString *)videoPath
                  success:(DownloadSuccessHandler)success
                 progress:(DownloadProgress)progress
                  failure:(DownloadFailure)failure;


- (void)petCloudVideoDownloadSegments:(int)prefix
                    videoSegmentSize:(int)videoSegmentSize
                            segments:(NSArray *)segmentes
                             filePath:(NSString *)videoPath
                              success:(DownloadSuccess)success
                             progress:(DownloadProgress)progress
                              failure:(DownloadFailure)failure;
/**
 [^en] pause cloud video download task [$en]

*/
- (int)pauseDownloadCloudVideo;

/**
 [^en] resume cloud video download task [$en]

 
 @param failure [^en] resume success callback. [$en]
*/
- (int)resumeDownloadCloudVideo:(DownloadFailure)failure;

/**
 [^en] cancel cloud video download task [$en]

*/
- (int)cancelDownloadCloudVideo;

/**
 [^en] delete current device's cloud video which during the time range [$en]

 @param timeRange [^en] the time range to delete [$en]
 @param success success callback
 @param failure failure callback
*/
- (void)deleteCloudVideoWithRange:(NSRange)timeRange success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

/**
 [^en] delete cloud video which during the time range [$en]

 @param devId [^en] specified device id [$en]
 @param timeRange [^en] the time range to delete [$en]
 @param extParams [^en] ext params [$en]
 @param success success callback
 @param failure failure callback
*/
- (void)deleteCloudVideoWithDevId:(NSString *)devId timeRange:(NSRange)timeRange extParams:(NSDictionary *)extParams success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

/**
 [^en] delete current device's cloud video which during the time range [$en]

 @param timeRange [^en] the time range to delete [$en]
 @param success success callback
 @param failure failure callback
*/
- (void)deleteAllDayCloudVideoWithRange:(NSRange)timeRange success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

/**
 [^en] delete cloud video which during the time range [$en]

 @param devId [^en] specified device id [$en]
 @param timeRange [^en] the time range to delete [$en]
 @param extParams [^en] ext params [$en]
 @param success success callback
 @param failure failure callback
*/
- (void)deleteAllDayCloudVideoWithDevId:(NSString *)devId timeRange:(NSRange)timeRange extParams:(NSDictionary *)extParams success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

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

/// Set the video rotation
- (int)setVideoDirection:(ThingSmartVideoRotateDirection)direction horizontalMirror:(BOOL)horizontalMirror;

/// Set the video rotation and mirror
- (int)setVideoDirection:(ThingSmartVideoRotateDirection)direction mirror:(ThingSmartVideoMirrorDirection)mirror;

#pragma mark - deprecated

/**
 [^en]
 play encrypt video in detect message
 [$en]

 
 @param url [^en]video path[$en]
 @param nStartTime [^en]Start time to play[$en]
 @param encryptKey [^en]encrypt key[$en]
 @param callback start callback
 @param finihedCallBack finish callback

 @return error code
*/
- (int)playVideoMessageWithUrl:(NSString *)url startTime:(int)nStartTime encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finihedCallBack __deprecated_msg("Use -[ThingSmartCameraMessageMediaPlayer playMessage:attachmentType:success:failure:finished:] instead");

/**
 [^en]
 pause play video
 [$en]

 
 @return error code
*/
- (int)pausePlayVideoMessage __deprecated_msg("Use -[ThingSmartCameraMessageMediaPlayer pausePlay:] instead");

/**
 [^en]
 resume play video
 [$en]

 
 @return error code
*/
- (int)resumePlayVideoMessage __deprecated_msg("Use -[ThingSmartCameraMessageMediaPlayer resumePlay:] instead");

/**
 [^en]
 stop play video
 [$en]

 
 @return error code
*/
- (int)stopPlayVideoMessage __deprecated_msg("Use -[ThingSmartCameraMessageMediaPlayer stopPlay:] instead");

/**
 [^en]
 play encrypt audio in detect message
 [$en]

 
 @param url [^en]audio path[$en]
 @param nStartTime [^en]Start time to play[$en]
 @param encryptKey [^en]encrypt key[$en]
 @param callback start callback
 @param finihedCallBack finish callback

 @return error code
*/
- (int)playAudioMessageWithUrl:(NSString *)url startTime:(int)nStartTime encryptKey:(NSString *)encryptKey onResponse:(void (^)(int errCode))callback onFinish:(void (^)(int errCode))finihedCallBack __deprecated_msg("Use -[ThingSmartCameraMessageMediaPlayer playMessage:attachmentType:success:failure:finished:] instead");;

/**
 [^en]
 pause play audio
 [$en]

 
 @return error code
*/
- (int)pausePlayAudioMessage __deprecated_msg("Use -[ThingSmartCameraMessageMediaPlayer pausePlay:] instead");

/**
 [^en]
 resume play audio
 [$en]

 
 @return error code
*/
- (int)resumePlayAudioMessage __deprecated_msg("Use -[ThingSmartCameraMessageMediaPlayer resumePlay:] instead");

/**
 [^en]
 stop play audio
 [$en]

 
 @return error code
*/
- (int)stopPlayAudioMessage __deprecated_msg("Use -[ThingSmartCameraMessageMediaPlayer stopPlay:] instead");

@end

