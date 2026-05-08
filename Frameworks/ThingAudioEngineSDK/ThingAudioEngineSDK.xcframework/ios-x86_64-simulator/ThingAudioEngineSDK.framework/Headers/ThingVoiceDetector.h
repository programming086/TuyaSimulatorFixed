
#import <Foundation/Foundation.h>
#include "ThingAudioDefines.h"

@protocol ThingVoiceDetectorDelegate ;
@protocol ThingPlayerDelegate;

@interface ThingVoiceDetector : NSObject

@property (nonatomic,weak) id<ThingVoiceDetectorDelegate> delegate;
@property (nonatomic,weak) id<ThingPlayerDelegate> player_delegate;
- (instancetype)init NS_UNAVAILABLE;
/**
    sharedInstance.
 */
+ (instancetype)sharedInstance ;


/*
    create the vad engine.
 */
-(int) create ;

/**
    set the vad engine parameters.
 @param sampleRate              sample rate for audio record. 8000、16000 and 32000 supported only.
 @param channels                   channels for audio record.   1 supported only.
 @param level                          vad level . See the VAD_LEVEL .
 @param maxVoiceInMS           the max voice length in ms.
 */
-(int) setParametersWithSampleRate:(int)sampleRate channels:(int)channels level:(VAD_LEVEL)level maxVoiceInMS:(int)maxVoiceInMS ;

/**
    set the vad engine parameters.
@param sampleRate              sample rate for audio record. 8000、16000 and 32000 supported only.
@param channels                   channels for audio record.   1 supported only.
@param level                          vad level . See the VAD_LEVEL .
@param maxVoiceInMS           the max voice length in ms.
@param noVoiceInMs             The max time in Ms  We think the conversation is over.
 */
-(int) setParametersWithSampleRate:(int)sampleRate channels:(int)channels codec:(AUDIO_TYPE)codec level:(VAD_LEVEL)level maxVoiceInMS:(int)maxVoiceInMS noVoiceInMs:(int)noVoiceInMs ;



/**
    set the vad engine parameters.
@param sampleRate              sample rate for audio record. 8000、16000 and 32000 supported only.
@param channels                   channels for audio record.   1 supported only.
@param level                          vad level . See the VAD_LEVEL .
@param maxVoiceInMS           the max voice length in ms.
@param noVoiceInMs             The max time in Ms  We think the conversation is over.
@param audioInputSource  audio input source. See the AUDIO_SOURCE .
@param systemMode            system mode. See the SYSTEMMODE .
 */
-(int) setParametersWithSampleRate:(int)sampleRate channels:(int)channels codec:(AUDIO_TYPE)codec level:(VAD_LEVEL)level maxVoiceInMS:(int)maxVoiceInMS noVoiceInMs:(int)noVoiceInMs  audioInputSource:(AUDIO_SOURCE)audioInputSource systemMode:(SYSTEMMODE)systemMode ;


/**
    set the vad engine parameters.
@param sampleRate              sample rate for audio record. 8000、16000 and 32000 supported only.
@param channels                   channels for audio record.   1 supported only.
@param level                          vad level . See the VAD_LEVEL .
@param maxVoiceInMS           the max voice length in ms.
@param noVoiceInMs             The max time in Ms  We think the conversation is over.
@param audioInputSource  audio input source. See the AUDIO_SOURCE .
 */
-(int) setParametersWithSampleRate:(int)sampleRate channels:(int)channels codec:(AUDIO_TYPE)codec level:(VAD_LEVEL)level maxVoiceInMS:(int)maxVoiceInMS noVoiceInMs:(int)noVoiceInMs audioInputSource:(AUDIO_SOURCE)audioInputSource;

/**
    set the vad engine parameters.
@param arithMeticSetttingJson
    * {
        "anc": {
            "Enable": true,//是否开启降噪
            "Level": 1 //降噪等级目前从低到高支持（0，1，2，3）
        },
        "agc": {
            "Enable": true//是否开始增益
        },
        "aec": {
            "Enable": true//是否开启回声消除
        }
    } 
      * @return
     *          0       success
     *          < 0     error              
 */
-(int) enableAudioArichmeticWithArithMeticSetttingJson:(NSString *)arithMeticSetttingJson;

/**
    start VAD engine.
 */
-(int) start ;

/**
    stop vad engine.
 */
-(int) stop ;


/**
    start VAD engine palyback.
 */
-(int) startPlayback ;

/**
    stop vad engine palyback.
 */
-(int) stopPlayback ;

-(int) StopStepPlayback ;

/**
    destroy vad engine ;
 */
-(int) destroy ;

-(int) stopstep ;

@end


@protocol ThingVoiceDetectorDelegate <NSObject>
@required
- (void)voiceDetectorDidVoiceDetected:(ThingVoiceDetector *)engine;
- (void)voiceDetector:(ThingVoiceDetector *)engine didErrorHappendedWithError:(int)error ;
- (void)voiceDetector:(ThingVoiceDetector *)engine didVoiceDataRecvedWithVoiceData:(unsigned char*)voiceData length:(int)length tpye:(AUDIO_TYPE)type;
- (void)voiceDetectorDidVoiceEnd:(ThingVoiceDetector *)engine;
@end

@protocol ThingPlayerDelegate <NSObject>
@required
- (int)voiceDetector:(ThingVoiceDetector*)engine onPlayerAudioGetWithAudioData:(short*)audioData length:(int)length ;
@end
