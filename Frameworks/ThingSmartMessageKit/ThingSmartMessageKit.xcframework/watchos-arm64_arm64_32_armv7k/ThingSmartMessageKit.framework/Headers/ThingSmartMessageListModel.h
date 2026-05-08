
#import <Foundation/Foundation.h>
#import "ThingSmartMessageUtils.h"

NS_ASSUME_NONNULL_BEGIN
/// The model of a message attachment.
@interface ThingSmartMessageAttachModel : NSObject

/// Specifies whether the attachment is a video file, such as MP4 files.
@property (nonatomic, assign) BOOL isVideo;

/// The URL of the attachment.
@property (nonatomic, strong) NSString *url;

/// The thumbnail of the attachment.
@property (nonatomic, strong) NSString *thumbUrl;

@end


typedef NS_ENUM(NSInteger, ThingSmartMessageAttachPicDirection) {
    ThingSmartMessageAttachPicDirectionInvalid = -1,
    ThingSmartMessageAttachPicDirectionUp = 0,
    ThingSmartMessageAttachPicDirectionRight = 90,//90
    ThingSmartMessageAttachPicDirectionDown = 180,//180
    ThingSmartMessageAttachPicDirectionLeft = 270//270
};

@interface ThingSmartMessageMarketing : NSObject

@end

@interface ThingSmartMessageListModelExtend : NSObject

@property (nonatomic, assign) ThingSmartMessageAttachPicDirection rotate;

/**
 *  A property representing a marketing message.
 *
 *  This property holds an instance of `ThingSmartMessageMarketing` which
 *  describes a marketing-related message.
 */
@property (nonatomic, strong, nullable) ThingSmartMessageMarketing *marketing;

/// Inspection message report id
@property (nonatomic, copy, nullable) NSString *inspectionReportId;

/// Whether it is an inspection report message
@property (nonatomic, assign) BOOL isInspectionReportMessage;

/// Whether it is an multi videos message
@property (nonatomic, assign) BOOL supportMultiFragments;

/// bird name
@property (nonatomic, copy, nullable) NSString *birdName;

/// Pet feeding time
@property (nonatomic, assign) NSTimeInterval eventTime;

/// Motion detection time
@property (nonatomic, assign) NSTimeInterval prefixTime;

@end


/// The model of a message list.
@interface ThingSmartMessageListModel : NSObject

/// The identifier of a message.
@property (nonatomic, strong) NSString *msgId;

/// The title of a message.
@property (nonatomic, strong) NSString *msgTypeContent;

/// The content of a message.
@property (nonatomic, strong) NSString *msgContent;

/// The formatted date and time.
@property (nonatomic, strong) NSString *dateTime;

/// The timestamp of a message.
@property (nonatomic, assign) NSInteger time;

/// The icon of a message.
@property (nonatomic, strong) NSString *icon;

/// A list of attachments.
@property (nonatomic, strong) NSArray<ThingSmartMessageAttachModel *> *attachPicList;

@property (nonatomic, assign) BOOL hasNotRead;

/// The device ID. Only alert messages support this field.
@property (nonatomic, strong) NSString  *msgSrcId;

///  Valid values: `1` means an alert message. `2` means an automation message. Only alert messages support this field to distinguish between alert messages and automation messages. The home messages and notifications are ignored.
@property (nonatomic, assign) NSInteger  alarmType;

/// The type of message. Valid values: `0` means system messages. `1` means that new devices are added. `2` means that new friends are added. `4` means device alerts.
@property (nonatomic, assign) NSInteger msgType;

/// The code of message
@property (nonatomic, copy) NSString *msgCode;

/// The ID of the current home.
@property (nonatomic, assign) long long homeID;

/// The name of the current home.
@property (nonatomic, copy) NSString *homeName;

/// Is it necessary to pull the key to decrypt attachPicList. If isNeedPullEncKey is true, you need to get the decryption key by calling fetchMessageDecryptKeyWithEncryptRequestModel: success: failure:
@property (nonatomic, assign) BOOL isNeedPullEncKey;

/// Not all information will be available, some messages will return the orientation of the image, etc
@property (nonatomic, strong, nullable) ThingSmartMessageListModelExtend *extendParams;

/// The URL to navigate to when the message is clicked.
@property (nonatomic, strong) NSString *actionURL;

/// Attachments (e.g., image.jpg; video.mp4; video.jpg; etc.)
@property (nonatomic, strong) NSString *attachPics;

@end

/// The model of a Authorization.
@interface ThingSmartMessageAuthorizationModel : NSObject

/// The  status of marketing push.
@property (nonatomic, assign) BOOL marketingPush;

/// The  status of data authorization.
@property (nonatomic, assign) BOOL dataAuthorization;

/// The User has set up data authorization status.The Default Value is NO.
@property (nonatomic, assign) BOOL alreadySet;

@end

/// The model of a Encrypt
@interface ThingSmartMessageDecryptModel : NSObject

/// The message number.
@property (nonatomic, copy) NSString *businessNo;
/// The encrypt key.
@property (nonatomic, copy) NSString *businessKey;

@end

NS_ASSUME_NONNULL_END
