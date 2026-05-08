
#import <Foundation/Foundation.h>
#import <ThingSmartStreamChannelKit/ThingSmartStreamDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingStreamPlayerSupportAudioCodec) {
    /// PCM (101)
    ThingStreamPlayerSupportAudioCodecPCM = ThingStreamAttributeAudioCodecPCM,
    /// MP3 (109)
    ThingStreamPlayerSupportAudioCodecMP3 = ThingStreamAttributeAudioCodecMP3,
    /// WAV with PCM format
    ThingStreamPlayerSupportAudioCodecWAV_PCM = 1000,
};

@class ThingStreamPlayer;
@protocol ThingStreamPlayerDelegate <NSObject>

@optional
- (void)audioPlayerDidFinishPlaying:(ThingStreamPlayer *)player;
- (void)audioPlayer:(ThingStreamPlayer *)player didEncounterError:(NSError *)error;
- (void)audioPlayerDidStartBuffering:(ThingStreamPlayer *)player;
- (void)audioPlayerDidStopBuffering:(ThingStreamPlayer *)player;
@end

/// **Warning: Now only support PCM data.**
/// # Play audio data while receiving
///     `init` -> `configSampleRate` -> `-play` -> `-feedData:isLast:` -> `-stop`
/// # Play the complete audio file
///     `init` -> `configSampleRate` -> `-playFilePath:isFileUpdating:` -> `-stop`
/// # Play audio file while receiving
///     `init` -> `configSampleRate` -> `-playFilePath:isFileUpdating:` -> `-onPlayingFileDataUpdate:isFinish:` -> `-stop`
@interface ThingStreamPlayer : NSObject

@property (nonatomic, weak, nullable) id<ThingStreamPlayerDelegate> delegate;
@property (nonatomic, copy, nullable, readonly) NSString *filePath;
@property (nonatomic, assign, readonly) BOOL isPlaying;

/// Support play while recording.(Defualt is NO)
/// - No: Recorder and player have influence on each other. Example: If you are recording, please stop the recorder before playing.
/// - Yes: can start/stop play while recording.
@property (nonatomic, assign) BOOL supportPlayWhileRecord;

/// Init player
- (instancetype)init;

#pragma mark - Config player
/// Config player parameters
///
/// Note: now only support `PCM` and `WAV_PCM` codec type.
///
/// - Parameters:
///   - sampleRate: sample rate
///   - channels: channels
///   - bitDepth: bit depth
///   - codecType: audio codec type
- (BOOL)configSampleRate:(UInt32)sampleRate
                channels:(ThingStreamAttributeAudioChannels)channels
                bitDepth:(UInt32)bitDepth
               codecType:(ThingStreamPlayerSupportAudioCodec)codecType;

#pragma mark - Play audio data directly
/// Start play. (supportPlayWhenRecording = NO，when play，the record need stop)
- (void)play;

/// Feed audio data to play.
/// - Parameters:
///   - data: audio data.
///   - isLast: is last audio package.
- (void)feedData:(NSData *)data isLast:(BOOL)isLast;

#pragma mark - Play audio file
/// Play audio file.
/// - Parameters:
///   - filePath: file path
///   - isFileUpdating: is file updating.
- (BOOL)playFilePath:(NSString *)filePath isFileUpdating:(BOOL)isFileUpdating;

/// Update playing audio file content.
/// - Parameters:
///   - filePath: file path.
///   - isFinish: is file finish updating.
- (void)onPlayingFileDataUpdate:(NSString *)filePath isFinish:(BOOL)isFinish;

#pragma mark - Stop play
/// Stop play
- (void)stop;

/// Dostory player
- (void)destory;

@end

NS_ASSUME_NONNULL_END
