
#import <Foundation/Foundation.h>
#import <ThingSmartStreamChannelKit/ThingSmartStreamChannelKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingStreamRecorderExtendConfig : NSObject
/// ANC strength in range \[0, 10\], `ancModelPath` is required, default `3`
@property (nonatomic, assign) NSUInteger ancLevel __deprecated_msg("Legacy denoise configuration may negatively impact ASR results. Deprecated.");

/// Path to the DeepFilter model file. If `nil` or file not exist, deepFilter anc is disabled.
@property (nonatomic, copy, nullable) NSString *ancModelPath __deprecated_msg("Legacy denoise configuration may negatively impact ASR results. Deprecated.");

/// Path to the Silero VAD model file, If `nil` or file not exist, deepFilter Silero VAD is disabled.
@property (nonatomic, copy, nullable) NSString *vadModelPath;

/// VAD decision interval in milliseconds. Recommended 500~1000ms. **Default = 700ms.**
@property (nonatomic, assign) NSUInteger vadInterval;

/// Automatic Gain Control. **Defualt = NO**
@property (nonatomic, assign) BOOL enableAGC;

/// recoder codec type. **Default = ThingStreamAttributeAudioCodecPCM**
/// - Note: Only support `ThingStreamAttributeAudioCodecPCM` and `ThingStreamAttributeAudioCodecOpus`.
@property (nonatomic, assign) ThingStreamAttributeAudioCodec codec;

/// Original frame duration in milliseconds. **Default = 40ms**
/// - Note: Only avaliable when `codec != ThingStreamAttributeAudioCodecPCM`
///     - `ThingStreamAttributeAudioCodecOpus`: only support input [40, 60, 80, 100, 120]
@property (nonatomic, assign) NSInteger frameDuration;

/// The max voice length in ms. **Default = 200ms**
/// - Note: If use `codec = ThingStreamAttributeAudioCodecOpus`, please input **integer multiples** of `frameDuration` value,
///     - Example1: If `frameDuration` = 40, the `maxVoiceInMs` available in [40, 80, 120, 160, 200....]
///     - Example2: If `frameDuration` = 60, the `maxVoiceInMs` avaliable in [60,120,180,....]
///     - If you pass parameters that do not meet the requirements, we will automatically correct them before recording.
@property (nonatomic, assign) NSInteger maxVoiceInMS;

/// Bitrate. **Default = 48000**
/// - Note: Only avaliable when use `codec = ThingStreamAttributeAudioCodecOpus`
@property (nonatomic, assign) uint32_t bitrate;

/// Get default pcm config.
/// - Note: Defautl value is
///     - `codec` is `ThingStreamAttributeAudioCodecPCM`
///     - `maxVoiceInMS` is `200`
///     - `ancModelPath` is `nil`
///     - `vadModelPath` is `nil`
///     - `vadInterval` is `700`
///     - `enableAGC` is `NO`
/// - Returns: A default configuration instance.
+ (instancetype)defaultConfig;

/// Get default opus config.
/// - Note: Defautl value is
///     - `codec` is `ThingStreamAttributeAudioCodecOPUS`
///     - `maxVoiceInMS` is `200`
///     - `ancModelPath` is `nil`
///     - `vadModelPath` is `nil`
///     - `vadInterval` is `700`
///     - `enableAGC` is `NO`
///     - `bitrate` is `48000`
/// - Returns: A default configuration instance.
+ (instancetype)defaultOpusConfig;

@end

NS_ASSUME_NONNULL_END
