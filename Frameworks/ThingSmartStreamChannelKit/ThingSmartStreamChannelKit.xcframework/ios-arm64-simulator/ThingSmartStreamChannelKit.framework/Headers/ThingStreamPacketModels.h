
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ThingStreamAttribute.h"

/// Packet Type
typedef NS_ENUM(uint8_t, ThingStreamPacketType) {
    ThingStreamPacketTypeClientHello = 1,
    ThingStreamPacketTypeAuthenticateRequest = 2,
    ThingStreamPacketTypeAuthenticateResponse = 3,
    ThingStreamPacketTypePing = 4,
    ThingStreamPacketTypePong = 5,
    ThingStreamPacketTypeConnectionClose = 6,
    ThingStreamPacketTypeSessionNew = 7,
    ThingStreamPacketTypeSessionClose = 8,
    ThingStreamPacketTypeConnectionRefreshRequest = 9,
    ThingStreamPacketTypeConnectionRefreshResponse = 10,
    ThingStreamPacketTypeSessionStateChange = 11,
    ThingStreamPacketTypeVideo = 30,
    ThingStreamPacketTypeAudio = 31,
    ThingStreamPacketTypeImage = 32,
    ThingStreamPacketTypeFile = 33,
    ThingStreamPacketTypeText = 34,
    ThingStreamPacketTypeEvent = 35
};

/// Event Packet Type
///     Normal process: Event Start ---> Video/Audio/Image/File/Text Start~ing~End ---> Event End
typedef NS_ENUM(uint16_t, ThingStreamPacketEventType) {
    /// Event start, a round of Chat starts
    ThingStreamPacketEventTypeStart = 0,
    /// **Deprecated API** Payloads end, it is deprecated.
    ThingStreamPacketEventTypePayloadEnd = 1,
    /// Event end, a round of Chat ends. The cloud will process multiple data streams in the large model
    ThingStreamPacketEventTypeEnd = 2,
    /// OneShot one-time event, used for small data volume situations
    ThingStreamPacketEventTypeOneShot = 3,
    /// ChatBreak interrupt event, can be initiated by the App or the cloud. After interruption, subsequent data of this round of Chat Event is discarded and no longer used
    ThingStreamPacketEventTypeChatBreak = 4,
    /// Server-side detects audio VAD. The server no longer processes subsequent audio of this Event. It is recommended that the Client stop transmitting data of this Event to the Server upon receiving this. If there is a new audio event, a new Event needs to be initiated
    ThingStreamPacketEventTypeServerVAD = 5,
    /// MCP Command
    ThingStreamPacketEventTypeMcpCmd = 1000,
    /// Server timeout
    ThingStreamPacketEventTypeServerTimeout = 1001,
    /// Use event to update session user data.
    ThingStreamPacketEventTypeUpdateContext = 1002,
    /// Use event to send user data to trigger business functions.
    ThingStreamPacketEventTypeEventTrigger = 1003,
    /// When unspoken audio is received for a long time, the server send `EventSleep` to notify app to stop send audio packet.
    ThingStreamPacketEventTypeEventSleep = 1004
};

/// Packet Stream Flag
typedef NS_ENUM(uint8_t, ThingStreamPacketStreamFlag) {
    ThingStreamPacketStreamFlagOnlyOne = 0,
    ThingStreamPacketStreamFlagStreamStart = 1,
    ThingStreamPacketStreamFlagStreaming = 2,
    ThingStreamPacketStreamFlagStreamEnd = 3,
};

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Send Packet
/// Video | Audio | Image | Text | File | Event Base Model
@interface ThingStreamPayloadDataPacketModel : NSObject
/// Packet Type.
@property (nonatomic, assign) ThingStreamPacketType packetType;
/// Session ID for Video | Audio | Image | Text | File Packt
@property (nonatomic, strong, nullable) NSArray<NSString *> *sessionIDList;
/// Session ID for Event | Video | Audio | Image | Text | File Packt
@property (nonatomic, strong, nullable) NSString *sessionID;
/// Payload data
@property (nonatomic, strong, nullable) NSData *payload;
/// Data Channel of video/audio/image/text/file.
@property (nonatomic, strong, nullable) NSString *dataChannel;
/// Stream Flag For Video | Audio | Image | Text | File Packet.
@property (nonatomic, assign) ThingStreamPacketStreamFlag streamFlag;
/// User data. (** Now use JSON string**)
@property (nonatomic, strong, nullable) NSString *userData;
/// Send File Packet Path, Receive Video/Audio/Image/File Packet Path
@property (nonatomic, strong, nullable) NSString *filePath;
/// Cached Video | Audio | Image | Text | File data on disk.
@property (nonatomic, assign) BOOL saved;

+ (NSString *)stream_packetType_desc:(ThingStreamPacketType)packetType;
+ (NSString *)stream_eventType_desc:(ThingStreamPacketEventType)eventType;
- (NSString *)description;
@end

/// Video Packet Model
@interface ThingStreamVideoPacketModel : ThingStreamPayloadDataPacketModel
@property (nonatomic, assign) ThingStreamAttributeVideoCodec codecType;
@property (nonatomic, assign) uint8_t fps;
@property (nonatomic, assign) uint16_t width;
@property (nonatomic, assign) uint16_t height;
@property (nonatomic, assign) uint32_t sampleRate;
@property (nonatomic, assign) uint64_t timestamp;

/// Create a video packet data model.
///
/// **Note:**
/// When `streamFlag` == `StreamStart` or `OnlyOne`, the params `codecType`, `fps`, `width`, `height`, `sampleRate` **MUST** matches video related attributes.
///
/// @param payload Data payload
/// @param sessionID Session ID
/// @param dataChannel Data Channel of video. If only one video channel, it can be nil.
/// @param streamFlag Stream flag
/// @param codecType Video codec type
/// @param fps Frame rate
/// @param width Video width
/// @param height Video height
/// @param sampleRate Sample rate
+ (nullable instancetype)packetWithPayload:(nullable NSData *)payload
                                 sessionID:(NSString *)sessionID
                               dataChannel:(nullable NSString *)dataChannel
                                streamFlag:(ThingStreamPacketStreamFlag)streamFlag
                                 codecType:(ThingStreamAttributeVideoCodec)codecType
                                       fps:(uint8_t)fps
                                     width:(uint16_t)width
                                    height:(uint16_t)height
                                sampleRate:(uint32_t)sampleRate;

/// Create a video stream data model. For `streamFlag` == `Streaming` or `StreamEnd`
///
/// @param payload Data payload
/// @param sessionID Session ID
/// @param dataChannel Data Channel of video. If only one video channel, it can be nil.
/// @param streamFlag Stream flag
+ (nullable instancetype)packetWithPayload:(nullable NSData *)payload
                                 sessionID:(NSString *)sessionID
                               dataChannel:(nullable NSString *)dataChannel
                                streamFlag:(ThingStreamPacketStreamFlag)streamFlag;
@end

/// Audio Packet Model
@interface ThingStreamAudioPacketModel : ThingStreamPayloadDataPacketModel
@property (nonatomic, assign) ThingStreamAttributeAudioCodec codecType;
@property (nonatomic, assign) ThingStreamAttributeAudioChannels channels;
@property (nonatomic, assign) uint32_t sampleRate;
@property (nonatomic, assign) uint8_t bitDepth;
@property (nonatomic, assign) uint64_t timestamp;
/// Audio container, defualt = 0-raw
@property (nonatomic, assign) uint8_t container;
/// Bitrate, unit: bps, e.g: 48000.
/// - Note: If `codecType == ThingStreamAttributeAudioCodecOpus`, it's required.
@property (nonatomic, assign) uint32_t bitrate;
/// Frame duration.
/// - Note: If `codecType == ThingStreamAttributeAudioCodecOpus`, it's required, and the value must be within the range of [40, 60, 80, 100, 120].
@property (nonatomic, assign) uint16_t frameDuration;
/// Frame size, calculated by `bitrate` and `frameDuration`.
/// - Note: If `codecType == ThingStreamAttributeAudioCodecOpus`, it's required.
@property (nonatomic, assign) uint16_t frameSize;

/// Create an audio packet data model
///
/// **Note:**
/// When `streamFlag` == `StreamStart` or `OnlyOne`, the params `codecType`, `channels`, `sampleRate`, `bitDepth` **MUST** matches audio related attributes.
///
/// @param payload Data payload
/// @param sessionID Session ID
/// @param dataChannel Data Channel of audio. If only one audio channel, it can be nil.
/// @param streamFlag Stream flag
/// @param codecType Codec type
/// @param channels Audio channels
/// @param sampleRate Sample rate
/// @param bitDepth Bit depth
+ (nullable instancetype)packetWithPayload:(nullable NSData *)payload
                                 sessionID:(NSString *)sessionID
                               dataChannel:(nullable NSString *)dataChannel
                                streamFlag:(ThingStreamPacketStreamFlag)streamFlag
                                 codecType:(ThingStreamAttributeAudioCodec)codecType
                                  channels:(ThingStreamAttributeAudioChannels)channels
                                sampleRate:(uint32_t)sampleRate
                                  bitDepth:(uint8_t)bitDepth;

/// Create an audio stream data model. For `streamFlag` == `Streaming` or `StreamEnd`
///
/// @param payload Data payload
/// @param sessionID Session ID
/// @param dataChannel Data Channel of audio. If only one audio channel, it can be nil.
/// @param streamFlag Stream flag
+ (nullable instancetype)packetWithPayload:(nullable NSData *)payload
                                 sessionID:(NSString *)sessionID
                               dataChannel:(nullable NSString *)dataChannel
                                streamFlag:(ThingStreamPacketStreamFlag)streamFlag;
@end

/// Image Packet Model
@interface ThingStreamImagePacketModel : ThingStreamPayloadDataPacketModel
@property (nonatomic, assign) ThingStreamAttributeImageFormat format;
@property (nonatomic, assign) uint16_t width;
@property (nonatomic, assign) uint16_t height;
@property (nonatomic, assign) uint64_t timestamp;
@property (nonatomic, strong, nullable) NSString *imageUrl; // oss image url

/// Create an image packet data model. (The image is not compressed)
///
/// **Note:**
/// Large image size will lead to longer processing time, it is recommended to compress the resolution and clarity before sending.
/// It is recommended to compress the image data size below 1 mb, preferably around 200 kb, the maximum recommended pixel count is 896 * 896
///
/// @param sessionID Session ID
/// @param payload Data payload
/// @param dataChannel Data Channel of image. If only one image channel, it can be nil.
/// @param format Image format
/// @param width Width (optional)
/// @param height Height (optional)
+ (nullable instancetype)packetWithPayload:(nullable NSData *)payload
                                 sessionID:(NSString *)sessionID
                               dataChannel:(nullable NSString *)dataChannel
                                    format:(ThingStreamAttributeImageFormat)format
                                     width:(uint16_t)width
                                    height:(uint16_t)height;

/// Create an image packet data model. (The image will be compressed)
///
/// **NOTE**
/// Large image size will lead to longer processing time. When call this method, the image will be compressed into jpeg, maximum pixel width count is 896px.
///
/// @param image image
/// @param filePath image file path
/// @param sessionID Session ID
/// @param dataChannel Data Channel of image. If only one image channel, it can be nil.
+ (nullable instancetype)packetWithImage:(nullable UIImage *)image
                              orFilePath:(nullable NSString *)filePath
                               sessionID:(NSString *)sessionID
                             dataChannel:(nullable NSString *)dataChannel;

/// Create an image packet data model by image url.
///
/// **NOTE**
/// 1. You should upload image to oss before create image packet.
/// 2. Large image size will lead to longer processing time. When call this method, the image will be compressed into jpeg, maximum pixel width count is 896px.
///
/// @param imageURL image url
/// @param dataChannel Data Channel of image. If only one image channel, it can be nil.
/// @param format Image format
/// @param width Width (optional)
/// @param height Height (optional)
+ (nullable instancetype)packetWithImageURL:(nullable NSString*)imageURL
                                  sessionID:(NSString *)sessionID
                                dataChannel:(nullable NSString *)dataChannel
                                     format:(ThingStreamAttributeImageFormat)format
                                      width:(uint16_t)width
                                     height:(uint16_t)height;


/// Resize the image to a suitable size for the AI-Agent.
/// @param image image
/// @param outputSize processed image size.
+ (NSData *)resizeImage:(UIImage *)image outputSize:(nullable CGSize *)outputSize;
@end

/// Text Packet Model
@interface ThingStreamTextPacketModel : ThingStreamPayloadDataPacketModel
/// Will be transferred to `NSData*` type property `payload`.
@property (nonatomic, strong, nullable) NSString *text;

/// Create a text packet data model
///
/// @param text Text content
/// @param sessionID Session ID
/// @param dataChannel Data Channel of text. If only one text channel, it can be nil.
+ (instancetype)packetWithText:(NSString *)text
                     sessionID:(NSString *)sessionID
                   dataChannel:(nullable NSString *)dataChannel;
@end

/// File Packet Model
@interface ThingStreamFilePacketModel : ThingStreamPayloadDataPacketModel
@property (nonatomic, assign) ThingStreamAttributeFileFormat fileFormat;
@property (nonatomic, strong, nullable) NSString *fileName;

/// Create a file packet data model
///
/// @param sessionID Session ID
/// @param dataChannel Data Channel of file. If only one file channel, it can be nil.
/// @param fileFormat File format
/// @param filePath File path
/// @param fileName File name
+ (nullable instancetype)packetWitFilePath:(nonnull NSString *)filePath
                                 sessionID:(NSString *)sessionID
                               dataChannel:(nullable NSString *)dataChannel
                                fileFormat:(ThingStreamAttributeFileFormat)fileFormat
                                  fileName:(nullable NSString *)fileName;
@end

/// Event Packet Model
@interface ThingStreamEventPacketModel : ThingStreamPayloadDataPacketModel
@property (nonatomic, assign) ThingStreamPacketEventType eventType;
@property (nonatomic, strong) NSString *eventId;

/// Create a event start packet model
/// - Parameters:
///   - sessionID: Session ID
///   - eventId: Event ID. If it is nil, one will be auto generated and assigned to `self.eventId`
+ (instancetype)eventStartPacketWithSessionID:(NSString *)sessionID
                                      eventId:(nullable NSString *)eventId;

/// Create a event end packet model
/// - Parameters:
///   - sessionID: Session ID
///   - eventId: Event ID. Same as event start
+ (instancetype)eventEndPacketWithSessionID:(NSString *)sessionID
                                    eventId:(NSString *)eventId;


/// Create a chat break packet model
/// Note: You can break either during sending or during receiving
/// - Parameters:
///   - sessionID: Session ID
///   - eventId: Event ID. Same as event start
+ (instancetype)eventChatBreakPacketWithSessionID:(NSString *)sessionID
                                          eventId:(NSString *)eventId;

/// Generate a event id use a prefix.
/// return  $prefix_event_$timestamp
+ (NSString *)genEventIdWithPrefix:(nullable NSString *)prefix;

/// Generate a event id use a prefix and sessionId.
/// return  $prefix_event_$sessionId.sub(12,8)_$timestamp
+ (NSString *)genEventIdWithPrefix:(nullable NSString *)prefix sid:(nullable NSString *)sid;

/// Extend event.
/// - Parameters:
///   - sessionID: sessionId
///   - eventId: eventId
///   - eventType: event type, use uin16 number value or `ThingStreamPacketEventType`
///     - 1000 / ThingStreamPacketEventTypeMcpCmd: McpCmd
///     - 1002 / ThingStreamPacketEventTypeServerTimeout: UpdataContext
///     - 1003 / ThingStreamPacketEventTypeEventTrigger: EventTrigger
///     - ......
///   - userData: user data
+ (instancetype)eventWithSessionId:(NSString *)sessionID
                           eventId:(NSString *)eventId
                         eventType:(uint16_t)eventType
                          userData:(nullable NSString *)userData;

@end

@interface ThingStreamEventPacketModel(Deprecated)
/// Create a event paload end packet model. (**Deprecated**)
/// There is no need to send event paylod end now.
+ (instancetype)eventPayloadEndPacketWithSessionID:(NSString *)sessionID
                                       dataChannel:(NSString *)dataChannel
                                           eventId:(NSString *)eventId __deprecated_msg("There is no need to send event paylod end now.");
@end


NS_ASSUME_NONNULL_END
