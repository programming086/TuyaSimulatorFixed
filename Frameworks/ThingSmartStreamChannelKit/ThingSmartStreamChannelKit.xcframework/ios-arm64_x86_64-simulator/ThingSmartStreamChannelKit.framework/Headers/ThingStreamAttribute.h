
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// User data attribute type defines.
typedef NS_ENUM(uint16_t, ThingStreamAttributeUserDataType) {
    /// type = string
    ThingStreamAttributeUserDataTypeLanguage = 1001,
    /// type = uint16
    ThingStreamAttributeUserDataTypePayloadsEndDataID = 1002,
    /// type = string
    ThingStreamAttributeUserDataTypeAIChatUserData = 1003,
    /// type = string
    ThingStreamAttributeUserDataTypeSupportedAudios = 1004,
    /// type = string
    ThingStreamAttributeUserDataTypeSupportedVideos = 1005,
};

// ConnectionStatusCode | ConnectionCloseErrorCode | SessionStatusCode | SessionCloseErrorCode | SessionStateChangeCode
typedef NS_ENUM(uint16_t, ThingStreamAttributeConnectionSessionCode) {
    ThingStreamAttributeConnectionSessionCodeOK = 200,                    // OK
    ThingStreamAttributeConnectionSessionCodeBadRequest = 400,            // Bad Request
    ThingStreamAttributeConnectionSessionCodeUnauthenticated = 401,       // Unauthenticated
    ThingStreamAttributeConnectionSessionCodeNotFound = 404,              // Not Found
    ThingStreamAttributeConnectionSessionCodeRequestTimeout = 408,        // Request Timeout
    ThingStreamAttributeConnectionSessionCodeInternalServerError = 500,   // Internal Server Error
    ThingStreamAttributeConnectionSessionCodeGatewayTimeout = 504,        // Gateway Timeout
    ThingStreamAttributeConnectionSessionCodeCloseByClient = 601,         // Close By Client
    ThingStreamAttributeConnectionSessionCodeCloseByReuse = 602,          // Close By Reuse
    ThingStreamAttributeConnectionSessionCodeCloseByIO = 603,             // Close By IO
    ThingStreamAttributeConnectionSessionCodeCloseByKeepalive = 604,      // Close By Keepalive
    ThingStreamAttributeConnectionSessionCodeCloseByExpire = 605,         // Close By Expire
    /// Session Full, one connection can only create limited sessions(current cloud limit is 20). You should close unnecessary sessions.
    ThingStreamAttributeConnectionSessionCodeSessionFull = 607,
    /// Agent Token Expired, need close seesion and retry `-queryAgentToken:` to get new one.
    ThingStreamAttributeConnectionSessionCodeAgentTokenExpired = 1001
};

// Video codec types
typedef NS_ENUM(uint16_t, ThingStreamAttributeVideoCodec) {
    ThingStreamAttributeVideoCodecMPEG4 = 0,
    ThingStreamAttributeVideoCodecH263 = 1,
    ThingStreamAttributeVideoCodecH264 = 2,
    ThingStreamAttributeVideoCodecMJPEG = 3,
    ThingStreamAttributeVideoCodecH265 = 4,
    ThingStreamAttributeVideoCodecYUV420 = 5,
    ThingStreamAttributeVideoCodecYUV422 = 6,
    ThingStreamAttributeVideoCodecMax = 99,
};

// Audio codec types
typedef NS_ENUM(uint16_t, ThingStreamAttributeAudioCodec) {
    ThingStreamAttributeAudioCodecADPCM = 100,
    ThingStreamAttributeAudioCodecPCM = 101,
    ThingStreamAttributeAudioCodecAACRaw = 102,
    ThingStreamAttributeAudioCodecAACADTS = 103,
    ThingStreamAttributeAudioCodecAACLATM = 104,
    ThingStreamAttributeAudioCodecG711U = 105,
    ThingStreamAttributeAudioCodecG711A = 106,
    ThingStreamAttributeAudioCodecG726 = 107,
    ThingStreamAttributeAudioCodecSPEEX = 108,
    ThingStreamAttributeAudioCodecMP3 = 109,
    ThingStreamAttributeAudioCodecG722 = 110,
    ThingStreamAttributeAudioCodecOpus = 111,
    ThingStreamAttributeAudioCodecMax = 199,
    ThingStreamAttributeAudioCodecInvalid = 200,
};

// Audio channels
typedef NS_ENUM(uint16_t, ThingStreamAttributeAudioChannels) {
    ThingStreamAttributeAudioChannelsMono = 1,
    ThingStreamAttributeAudioChannelsStereo = 2,
};

// ImageFormat
typedef NS_ENUM(uint16_t, ThingStreamAttributeImageFormat) {
    ThingStreamAttributeImageFormatJPEG = 1,
    ThingStreamAttributeImageFormatPNG = 2,
};

// File formats
typedef NS_ENUM(uint16_t, ThingStreamAttributeFileFormat) {
    ThingStreamAttributeFileFormatMP4 = 1,
    ThingStreamAttributeFileFormatOGG_OPUS = 2,
    ThingStreamAttributeFileFormatPDF = 3,
    ThingStreamAttributeFileFormatJSON = 4,
    ThingStreamAttributeFileFormatIPC_LOG = 5,
    ThingStreamAttributeFileFormatSweeperMap = 6,
};

typedef NSString *ThingStreamUserDataAttributeKey;
/// UserData json key = "language", use in create session
FOUNDATION_EXPORT ThingStreamUserDataAttributeKey const ThingStreamUserDataAttributeKeyLanguage;
/// UserData json key = "sessionAttributes", use in create session, default value = "{\"tts.order.supports\": \"[{\\\"container\\\":\\\"pcm\\\",\\\"channels\\\":1,\\\"bitDepth\\\":\\\"16\\\",\\\"bitRate\\\":\\\"32000\\\",\\\"format\\\":\\\"mp3\\\",\\\"sampleRate\\\":16000}]\"}"
FOUNDATION_EXPORT ThingStreamUserDataAttributeKey const ThingStreamUserDataAttributeKeySessionAttributes;
/// UserData json key = "chatAttributes", use in event start, default value = {\"asr.enableVad\":false,\"processing.interrupt\":false}}`
FOUNDATION_EXPORT ThingStreamUserDataAttributeKey const ThingStreamUserDataAttributeKeyChatAttributes;
/// UserData json key = "breakAttributes", use in chat break
FOUNDATION_EXPORT ThingStreamUserDataAttributeKey const ThingStreamUserDataAttributeKeyBreakAttributes;

typedef NS_ENUM(uint8_t, ThingStreamAttributePayloadType) {
    ThingStreamAttributePayloadTypeUInt8  = 0x01,
    ThingStreamAttributePayloadTypeUInt16 = 0x02,
    ThingStreamAttributePayloadTypeUInt32 = 0x03,
    ThingStreamAttributePayloadTypeUInt64 = 0x04,
    ThingStreamAttributePayloadTypeBytes  = 0x05,
    ThingStreamAttributePayloadTypeString = 0x06
};

DEPRECATED_MSG_ATTRIBUTE("This class was deprecated. now the `userData` is using json string format, The API will be deleted in the future.")
@interface ThingStreamAttribute : NSObject
@property (nonatomic, assign) int type;
@property (nonatomic, assign) ThingStreamAttributePayloadType payloadType;
@property (nonatomic, strong) id value; // int 8 ~ int 64 -> @(), byte -> NSData, string -> NSString

/// **Deprecated**
+ (instancetype)attributeWithType:(uint16_t)type stringValue:(NSString *)value __deprecated_msg("deprecated, now `UserData` is using JSON string format, The API will be deleted in the future.");

/// Covert **deprecated user data attributes** to **user data json string**.
/// Only support covert:
///     - `ThingStreamAttributeUserDataTypeLanguage(1001)`
///     - `ThingStreamAttributeUserDataTypeAIChatUserData(1003)`
///     - `ThingStreamAttributeUserDataTypeSupportedAudios(1004)`
+ (nullable NSString *)userDataJsonFromUserDatas:(NSArray<ThingStreamAttribute *> *)userDatas;

/// **Deprecated**
/// Only `enableVad` is valiable.
/// Note: the chat attributes json format is `{\"chatAttributes\":{\"asr.enableVad\":true,\"processing.interrupt\":true}}`
+ (instancetype)uda_chatAttributesWithEnableVad:(BOOL)enableVad
                                      enableASR:(BOOL)enableASR
                                      enableLLM:(BOOL)enableLLM
                                      enableTTS:(BOOL)enableTTS __deprecated_msg("deprecated, now `UserData` is using JSON string format, The API will be deleted in the future.");

/// **Deprecated**
/// Only `enableVad` and `enableInterrupt` is valiable.
/// Note: the chat attributes json format is `{\"chatAttributes\":{\"asr.enableVad\":true,\"processing.interrupt\":true}}`
+ (instancetype)uda_chatAttributesWithEnableVad:(BOOL)enableVad
                                      enableASR:(BOOL)enableASR
                                      enableLLM:(BOOL)enableLLM
                                      enableTTS:(BOOL)enableTTS
                                enableInterrupt:(BOOL)enableInterrupt __deprecated_msg("deprecated, now `UserData` is using JSON string format, The API will be deleted in the future.");
@end

NS_ASSUME_NONNULL_END
