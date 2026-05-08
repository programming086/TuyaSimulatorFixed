
#import <Foundation/Foundation.h>
#import "ThingSmartCameraMessageModel.h"
#import <ThingSmartCameraM/ThingSmartCameraM.h>

@interface ThingSmartCameraMessage : NSObject

/**
 [^en]
 default is [NSTimeZone systemTimeZone]
 [$en]

 */
@property (nonatomic, strong) NSTimeZone *timeZone;

/**
[^en]
Enable image encryption, which is disabled by default. After opening, the pictures carried in the message will be encrypted, and you need to use the ThingEncryptImage component to display or download the pictures.
[$en]

*/
@property (nonatomic, assign) BOOL enableEncryptedImage __deprecated_msg("This method is deprecated");

- (instancetype)initWithDeviceId:(NSString *)devId timeZone:(NSTimeZone *)timeZone;


/**
 [^en]
 get day list which has messages
 [$en]

 

 @param year [^en]year[$en]
 @param month [^en]month[$en]
 @param success callback
 @param failure callback
 */
- (void)messageDaysForYear:(NSInteger)year
                     month:(NSInteger)month
                   success:(void (^)(NSArray<NSString *> *result))success
                   failure:(void (^)(NSError *error))failure;

/**
 [^en]
 get message list
 [$en]

 

 @param msgCodes msgCodes
 @param offset [^en]offset[$en]
 @param limit [^en]page size[$en]
 @param startTime [^en]pass 0 for no time limit[$en]
 @param endTime [^en]end time[$en]
 @param success callback
 @param failure callback
 */
- (void)messagesWithMessageCodes:(NSArray *)msgCodes
                          Offset:(NSInteger)offset
                           limit:(NSInteger)limit
                       startTime:(NSInteger)startTime
                         endTime:(NSInteger)endTime
                         success:(void (^)(NSArray<ThingSmartCameraMessageModel *> *result))success
                         failure:(void (^)(NSError *error))failure;

/**
 [^en]
 get message list new
 [$en]

 

 @param msgCodes msgCodes
 @param offset [^en]offset[$en]
 @param limit [^en]page size[$en]
 @param startTime [^en]pass 0 for no time limit[$en]
 @param endTime [^en]end time[$en]
 @param customParams [^en]custom params[$en]
 @param success callback
 @param failure callback
 */
- (void)messagesWithMessageCodes:(NSArray *)msgCodes
                          offset:(NSInteger)offset
                           limit:(NSInteger)limit
                       startTime:(NSInteger)startTime
                         endTime:(NSInteger)endTime
                    customParams:(NSDictionary *)customParams
                         success:(void (^)(NSArray<ThingSmartCameraMessageModel *> *result))success
                         failure:(void (^)(NSError *error))failure;

/**
[^en]
remove messages by message id list
[$en]

 @param msgIds [^en] message id array whitch need removed [$en]
 @param success callback
 @param failure callback
*/
- (void)removeMessagesWithMessageIds:(NSArray *)msgIds
                             success:(void (^)(void))success
                             failure:(void (^)(NSError *))failure;

/**
 [^en]
 get message schemes list
 [$en]

 
 @param success callback
 @param failure callback
 */
- (void)getMessageSchemes:(void (^)(NSArray<ThingSmartCameraMessageSchemeModel *> *result))success
                  failure:(void (^)(NSError *error))failure;

/**
 [^en]
 start download attachment of message
 [$en]

 @param messageModel [^en]message model[$en]
 @param type [^en]attachment type[$en]
 @param filePath [^en]file path to save attachment[$en]
 @param successCallback [^en]success callbak[$en]
 @param progressCallBack [^en]progress callbak[$en]
 @param failureCallBack [^en]failure callbak[$en]
*/
- (void)startDownloadMessageAttachmentWithMeesageModel:(ThingSmartCameraMessageModel *)messageModel attachType:(ThingCameraMessageAttachmentType)type filePath:(NSString *)filePath success:(void(^)(void))successCallback progress:(void (^)(int progress))progressCallBack failure:(void (^)(int errCode))failureCallBack;

/**
 [^en]
 start download attachment of message
 [$en]

 @param attachPath [^en]attachment path[$en]
 @param type [^en]attachment type[$en]
 @param filePath [^en]file path to save attachment[$en]
 @param successCallback [^en]success callbak[$en]
 @param progressCallBack [^en]progress callbak[$en]
 @param failureCallBack [^en]failure callbak[$en]
*/
- (void)startDownloadMessageAttachmentWithUrl:(NSString *)attachPath attachType:(ThingCameraMessageAttachmentType)type filePath:(NSString *)filePath success:(void(^)(void))successCallback progress:(void (^)(int progress))progressCallBack failure:(void (^)(int errCode))failureCallBack;

- (void)startDownloadMessageAttachmentWithUrl:(NSString *)attachPath attachType:(ThingCameraMessageAttachmentType)type filePath:(NSString *)filePath rotateDirection:(ThingSmartVideoRotateDirection)rotateDirection success:(void (^)(void))successCallback progress:(void (^)(int))progressCallBack failure:(void (^)(int))failureCallBack;

- (void)startVideoMessageDownloadWithFileInfo:(NSString *)fileInfo folderPath:(NSString *)folderPath fileName:(NSString *)mp4FileName targetSize:(CGSize)targetSize useFirstVideoResolution:(BOOL)useFirstVideoResolution rotation:(ThingSmartVideoRotateDirection)rotation onResponse:(void (^)(const char *msg,int errCode))onResponse onProgress:(void (^)(int errCode, int nPos))onProgress onFinish:(void (^)(const char *msg,int errCode))onFinish;

- (void)startDownloadMessageImageOrVideoWithUrl:(NSString *)attachPath attachType:(ThingCameraMessageAttachmentType)type filePath:(NSString *)filePath rotateDirection:(ThingSmartVideoRotateDirection)rotateDirection mirrorDirection:(ThingSmartVideoMirrorDirection)mirrorDirection success:(void (^)(void))successCallback progress:(void (^)(int))progressCallBack failure:(void (^)(int))failureCallBack;

- (void)getLatestMessageImage:(NSString *)devIds
                      success:(void (^)(NSArray<NSDictionary *> *result))success
                      failure:(void (^)(NSError *error))failure;


/**
 [^en]
 cancel download
 [$en]
*/
- (void)cancelDownloadMessageAttachment:(ThingCameraMessageAttachmentType)type;

@end

