
#import <Foundation/Foundation.h>
#import "ThingStreamRecorderExtendConfig.h"
#import <ThingSmartStreamChannelKit/ThingSmartStreamChannelKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingStreamRecorderDelegate <NSObject>
@optional
/// Record voice.
/// - Note: only callback PCM audio data.
/// - Parameter voiceData: PCM data
- (void)recorderDidRecVoice:(NSData *)voiceData;

/// Record voice packet.
/// - Note:
///     - Due to ASR only supports 16kHz sample rate, if a higher sample rate is used during recording, it will be resampled to 16kHz in this callback function.
///     - If use `extendConfig.codec = ThingStreamAttributeAudioCodecOPUS`, must implement this protocol, the `packet.payload` is opus data
///     - If use `extendConfig.codec = ThingStreamAttributeAudioCodecPCM`, this `packet.payload` is pcm data
///     - You need to provide the `packet.sessionId` and `packet.dataChannel` infos before send it.
/// - Parameters:
///     - packet: Audio packet. which `streamFlag == ThingStreamPacketStreamFlagStreaming`
- (void)recorderDidRecVoicePacket:(ThingStreamAudioPacketModel *)packet;

/// Recorder did stop
- (void)recorderDidStop;


/// Recorder did happend error
/// - Parameter error: error.
- (void)recorderDidHappendedError:(NSError *)error;

/// Recordeer did VAD.
/// Note: only called when config `ThingStreamRecorderExtendConfig.vadModelPath`.
- (void)recorderDidVAD;

/// Recordeer did detect voice.
- (void)recorderDidDetected;
@end

@interface ThingStreamRecorder : NSObject

@property (nonatomic, assign, readonly) BOOL isRecording;
@property (nonatomic, copy, nullable) NSString *baseSavePath;

/// Sample Rate, unit: Hz. e.g. 8000, 16000, 44100. default `16000`.
@property (nonatomic, assign, readonly) int sampleRate;
/// Channels, default `0(Mono)`.
@property (nonatomic, assign, readonly) int channels;
/// Bit Depth, defualt `16`.
@property (nonatomic, assign, readonly) int bitDepth;

/// Creat a recorder.
- (instancetype)initWithDelegate:(id<ThingStreamRecorderDelegate>)delegate;

/// Extend config for recorder.
/// - Note: please call before `-initVoiceDetector` / `-initVoiceDetector:`.
- (void)updateRecorderExtendConfig:(ThingStreamRecorderExtendConfig *)extendConfig;

/// Init voice detector.
/// - Note: SamoleRate = 16000, channels = 1(Mono), BitDepth = 16, Format = PCM,  Interval = 200 ms.
- (BOOL)initVoiceDetector;

/// Init voice detector, support custom sample rate.
/// - Note: Channels = 1(Mono), BitDepth = 16, Format = PCM,  Interval = 200 ms
/// - Parameters:
///   - sampleRate: sampleRate, unit: Hz. e.g. 8000, 16000, 22050, 24000, 44100
- (BOOL)initVoiceDetector:(int)sampleRate;

/// Start recod, not save record voice file
- (BOOL)startRecorder;

/// Start recorder with save record voice file.
/// - Parameter needSaveRecFile: need save record voice file or not.
- (BOOL)startRecorder:(BOOL)needSaveRecFile;

/// Stop record.
/// @return The path of the saved record voice file, if not saved, return nil.
- (nullable NSString *)stopRecorder;

/// Destory recorder.
- (void)destory;

/// Generate the first audio packet based on the recorder parameters.
/// @Note You need need to provide the `packet.sessionId` and `packet.dataChannel` infos before send it.
/// @return Audio packet model,  which `streamFlag == ThingStreamPacketStreamFlagStreamStart`
- (ThingStreamAudioPacketModel *)firstAudioPacket;

@end

NS_ASSUME_NONNULL_END
