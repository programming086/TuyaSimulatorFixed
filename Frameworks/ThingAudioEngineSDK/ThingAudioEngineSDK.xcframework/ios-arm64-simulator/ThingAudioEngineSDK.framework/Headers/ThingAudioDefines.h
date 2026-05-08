
#ifndef Defines_h
#define Defines_h


#define ThingAudioEngine_version "1.8.21.1"



#define   PROC_SAMPLE_RATE     (16000)
#define   PROC_FRAME_MS        (10)


typedef enum{
    VERY_LOW = 0 ,
    LOW,
    MEDIUM,
    HIGH,
    VZERO              // no vad
}VAD_LEVEL;

typedef enum{
    AUDIO_PCM = 0 ,
    AUDIO_PCMU = 1 ,
}AUDIO_TYPE ;

typedef enum{
    AUDIO_SOURCE_DEFAULT = 0 ,
    AUDIO_BLUETOOTH = 1 ,
    AUDIO_MIC = 2 ,
    AUDIO_SIMULTANEOUS_INTERPRETATIONS = 3 ,
}AUDIO_SOURCE ;

typedef enum{
    AUDIO_SYSTEMMODE_DEFAULT = 0 ,
    AUDIO_SYSTEMMODE_ASR = 1 ,
    AUDIO_SYSTEMMODE_RTC = 2 ,
}SYSTEMMODE ;

typedef enum {
    FILE_WAV = 0 ,
    
}FILE_TYPE;

typedef enum{
    SILERO_VAD_MODEL = 0 ,
    DTLN_AEC_MODEL,
    DEEP_FILTER_MODEL,
}MODEL_TYPE;

typedef enum{
    kThingVADErrCode_NoErr                   =  0,       // no error
    kThingVADErrCode_DetectedErr             = -10001 ,  // error while vad
}ThingVADErrCode;

#endif /* Defines_h */
