
#import <Foundation/Foundation.h>
#import <ThingSmartCameraBase/ThingSmartCameraBase.h>
#import "ThingSmartCameraMessageModel.h"

@class ThingSmartCameraMessageMediaPlayer;
@protocol ThingSmartCameraMessageMediaPlayerDelegate <NSObject>

@optional
- (void)mediaPlayer:(ThingSmartCameraMessageMediaPlayer *)player didReceivedFrame:(CMSampleBufferRef)frameBuffer videoFrameInfo:(ThingSmartVideoFrameInfo)frameInfo;

- (void)mediaPlayer:(ThingSmartCameraMessageMediaPlayer *)player  didReceivedAudioFrameInfo:(ThingSmartAudioFrameInfo)frameInfo;

@end

@interface ThingSmartCameraMessageMediaPlayer : NSObject

@property (nonatomic, weak) id<ThingSmartCameraMessageMediaPlayerDelegate> delegate;

@property (nonatomic, assign) CGSize videoStretchSize;

- (instancetype)initWithDeviceId:(NSString *)devId;

/**
[^en]
video frame render view
[$en]

@return render view
*/
- (UIView<ThingSmartVideoViewType> *)videoView;

#pragma mark - audio and video

/**
 [^en]
 play attachment in detect message
 [$en]

 
 @param messageModel [^en]message model[$en]
 @param attachmentType [^en]attachment type[$en]
 @param success success callback
 @param failure failure callback
 @param onFinish finish callback
 
*/
- (void)playMessage:(ThingSmartCameraMessageModel *)messageModel attachmentType:(ThingCameraMessageAttachmentType)attachmentType success:(void(^)(void))success failure:(void(^)(int errCode))failure finished:(void(^)(int errCode))onFinish;

/**
 [^en]
 play attachment in detect message
 [$en]

 
 @param attachmentPath [^en]attachment path[$en]
 @param attachmentType [^en]attachment type[$en]
 @param success success callback
 @param failure failure callback
 @param onFinish finish callback
 
*/
- (void)playMessageAttachment:(NSString *)attachmentPath type:(ThingCameraMessageAttachmentType)attachmentType success:(void(^)(void))success failure:(void(^)(int errCode))failure finished:(void(^)(int errCode))onFinish;

/**
 [^en]
 play attachment in detect message
 [$en]

 
 @param attachmentPath  [^en]attachment path[$en]
 @param attachmentType  [^en]attachment type[$en]
 @param startTime       [^en]start time to play[$en]
 @param success success callback
 @param failure failure callback
 @param onFinish finish callback
 
*/
- (void)playMessageAttachment:(NSString *)attachmentPath type:(ThingCameraMessageAttachmentType)attachmentType startTime:(NSInteger)startTime success:(void(^)(void))success failure:(void(^)(int errCode))failure finished:(void(^)(int errCode))onFinish;
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
- (void)playVideoMessageWithFileInfo:(NSString *)fileInfo startTime:(NSInteger)startTime onResponse:(void (^)(int errCode))responseCallback onFinish:(void (^)(int errCode))finishCallBack;


/**
 Description Start playing cloud video data with multiple files.
 @param fileInfo An array of video data, in JSON format,
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
- (void)playCloudVideoDataWithFileInfo:(NSString *)fileInfo startTime:(NSInteger)startTime onResponse:(void (^)(int errCode))responseCallback onFinish:(void (^)(int errCode))finishCallBack;

/// download video
/// @param fileInfo fileInfos
/// @param folderPath local path
/// @param mp4FileName file name
/// @param targetSize size
/// @param useFirstVideoResolution use first video clarity
/// @param rotation rotaion
/// @param onResponse response
/// @param onProgress progeress
/// @param onFinish finish
- (void)startVideoMessageDownloadWithFileInfoImpl:(NSString *)fileInfo
                                       folderPath:(NSString *)folderPath
                                         fileName:(NSString *)mp4FileName
                                       targetSize:(CGSize)targetSize
                          useFirstVideoResolution:(BOOL)useFirstVideoResolution
                                         rotation:(ThingSmartVideoRotateDirection)rotation
                                       onResponse:(void (^)(const char *msg,int errCode))onResponse
                                       onProgress:(void (^)(int errCode, int nPos))onProgress
                                         onFinish:(void (^)(const char *msg,int errCode))onFinish;


/**
 [^en]
 support continuous playback of many videos
 [$en]

 @param fileInfo json string contains an array of video messages
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
 @param success success callback
 @param failure failure callback
 @param onFinish finish callback
*/
- (void)playVideoMessageWithFileInfo:(NSString *)fileInfo startTime:(NSInteger)startTime success:(void(^)(void))success failure:(void(^)(int errCode))failure finished:(void(^)(int errCode))onFinish;


/**
 [^en]
 setup files need to be cached
 [$en]

 @param fileInfo json string contains an array of video messages
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
 @return error code
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
 pause play attachment
 [$en]

 
 @return error code
*/
- (int)pausePlay:(ThingCameraMessageAttachmentType)attachmentType;

/**
 [^en]
 resume play attachment
 [$en]

 
 @return error code
*/
- (int)resumePlay:(ThingCameraMessageAttachmentType)attachmentType;

/**
 [^en]
 stop play attachment
 [$en]


 @return error code
*/
- (int)stopPlay:(ThingCameraMessageAttachmentType)attachmentType;

/**
 [^en]
 set playback spped.
 [$en]

 @param speed [^en]playback speed.[$en]
 @return error code
 */
- (int)setPlaybackSpeed:(ThingSmartCameraPlayBackSpeed)speed;

/**
 [^en]
 set mute.
 [$en]

 @param mute [^en]mute sound.[$en]
 @param success success call back.
 @param failure failed call back.
 */
- (void)enableMute:(BOOL)mute success:(void(^)(void))success failure:(void (^)(NSError * error))failure;

/**
 convert MJPEG video into image files
 @param videoPath video path from message model.
 @param successCallback success call back. the element of imageFiles is NSDictionary
        @{
            @"timestamp": 111111111,
            @"filename": 111111111.jpg,
            @"filepath": temp/videoname/11111111.jpg
        }
 @param failureCallback failed call back.
 */
- (void)convertMJPEGVideoIntoImagesWithVideoPath:(NSString *)videoPath success:(void(^)(NSArray *imageFiles))successCallback failure:(void(^)(int errCode))failureCallback;
/**
 cancel convert MJPEG video into images
 */
- (int)cancelMJPEGVideoConvert;

- (int)setDeviceFeatures:(NSDictionary *)features;

/// change player speed
/// - Parameter speed: speed
- (void)setVideoMessagePlaySpeed:(ThingSmartCameraPlayBackSpeed)speed;

/// get video message fragments
/// - Parameters:
///   - devId: device id
///   - prefixTime: prefix time
///   - success: success callback
///   - fail: failure callback
- (void)getDeviceVideoMessageFragments:(NSString *)devId
                            prefixTime:(NSTimeInterval)prefixTime
                               success:(void(^)(NSArray *files))success
                                  fail:(void(^)(NSError *error))fail;

/// cancel download video message
- (int)cancelVideoMessageDownload;


@end

