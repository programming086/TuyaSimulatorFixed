
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ThingCameraMessageAttachmentType) {
    ThingCameraMessageAttachmentPicture,
    ThingCameraMessageAttachmentVideo,
    ThingCameraMessageAttachmentAudio,
    ThingCameraMessageAttachmentCloudVideo
};

@interface ThingSmartCameraMessageModel : NSObject

/**
 [^en]
 date string
 [$en]

 
*/
@property (nonatomic, copy) NSString *dateTime;

/**
 [^en]
 message type description
 [$en]

 
 */
@property (nonatomic, copy) NSString *msgTypeContent;

/**
 [^en]
 picture path
 [$en]

 
*/
@property (nonatomic, copy) NSString *attachPic;

/**
 [^en]
 video list
 [$en]

 
*/
@property (nonatomic, copy) NSArray *attachVideos;

/**
 [^en]
 audio list
 [$en]

 
*/
@property (nonatomic, copy) NSArray *attachAudios;

/**
 [^en]
 message source id (device id)
 [$en]

 
*/
@property (nonatomic, copy) NSString *msgSrcId;

/**
 [^en]
 message content text
 [$en]

 
*/
@property (nonatomic, copy) NSString *msgContent;

/**
 [^en]
 message title text
 [$en]

 
*/
@property (nonatomic, copy) NSString *msgTitle;

/**
 [^en]
 message id
 [$en]

 
*/
@property (nonatomic, copy) NSString *msgId;

/**
 [^en]
 message code
 [$en]

 
*/
@property (nonatomic, copy) NSString *msgCode;

/**
 [^en]
 date unix stamp
 [$en]

 
*/
@property (nonatomic, assign) NSInteger time;

@property (nonatomic, strong) NSDictionary *extendParams;

@property (nonatomic, assign) BOOL isNeedPullEncryKey;

/// AI msg type ids
@property (nonatomic, copy) NSArray *sourceIds;

@property (nonatomic, strong) NSArray *attachPicList;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

+ (NSArray<ThingSmartCameraMessageModel *> *)messageModesWithDataArray:(NSArray<NSDictionary *> *)datas;

- (void)replaceSourceEncryptKey:(NSString *)encryptKey;

@end


@interface ThingSmartCameraMessageSchemeModel : NSObject

/**
 [^en]
 description text
 [$en]

 
 */
@property (nonatomic, strong) NSString *describe;

/**
 [^en]
 message codes
 [$en]

 
*/
@property (nonatomic, strong) NSArray *msgCodes;

- (instancetype)initWithDictionary:(NSDictionary *)dict;

+ (NSArray<ThingSmartCameraMessageSchemeModel *> *)messageSchemeModesWithDataArray:(NSArray<NSDictionary *> *)datas;

@end
