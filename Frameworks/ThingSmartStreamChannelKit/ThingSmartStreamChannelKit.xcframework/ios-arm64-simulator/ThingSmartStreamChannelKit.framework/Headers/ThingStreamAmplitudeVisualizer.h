
#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface ThingStreamAmplitudeVisualizer : NSObject

@property (nonatomic, assign) int fftSize;

- (instancetype)initWithSampleRate:(int)sampleRate bitsPerSample:(int)bitsPerSample;

- (NSArray<NSNumber *> *)fft:(NSData *)buffer;

/// Resample PCM 16-bit depth、mono channel data from one sample rate to another.
/// - Parameters:
///   - pcmData: original PCM data.
///   - fromSampleRate: PCM data sample rate. (e.g. 220500, 32000, 44100.....).
///   - toSampleRate: PCM data target sample rate. (e.g. 16000, 8000).
+ (NSData *)resamplePcm16bitMono:(NSData *)pcmData from:(int)fromSampleRate to:(int)toSampleRate;

@end

NS_ASSUME_NONNULL_END
