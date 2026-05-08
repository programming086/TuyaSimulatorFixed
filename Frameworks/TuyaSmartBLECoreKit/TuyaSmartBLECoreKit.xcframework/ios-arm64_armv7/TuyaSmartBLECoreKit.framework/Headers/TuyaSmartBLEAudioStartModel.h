//
//  TuyaSmartBLEAudioStartModel.h
//  TuyaSmartBLEKit
//
//  Created by tjl on 2021/4/28.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    TY_PCM_L16_16KHZ_MONO = 0,
    TY_OPUS_16KHZ_32KBPS_CBR_0_20MS,
    TY_OPUS_16KHZ_16KBPS_CBR_0_20MS,
    TY_MSBC,
} TYAudioAudioFormat;

typedef enum : NSUInteger {
    TY_Audio_Profile_CLOSE_TALK = 0,
    TY_Audio_Profile_NEAR_FIELD,
    TY_Audio_Profile_FAR_FIELD,
} TYAudioAudioProfile;


typedef enum : NSUInteger {
    TuyaSmartAvsStateIdle = 0,
    TuyaSmartAvsStateListening,
    TuyaSmartAvsStateProcessing,
    TuyaSmartAvsStateSpeaking,
} TuyaSmartAudioState;

typedef enum : NSUInteger {
    TYAudioErrorCode_Success = 0,
    TYAudioErrorCode_Unknow,
    TYAudioErrorCode_Internal,
    TYAudioErrorCode_Unsupported,
    TYAudioErrorCode_UserCancelled,
    TYAudioErrorCode_NotFound,
    TYAudioErrorCode_Invalid,
    TYAudioErrorCode_Busy,
} TYAudioErrorCode;

typedef enum : NSUInteger {
    TYAudioResultType_Voice = 0,
    TYAudioResultType_Weather,
    TYAudioResultType_List,
    TYAudioResultType_Other,
} TYAudioResultType;

typedef enum : NSUInteger {
    TuyaSmartAvsCmdStartSpeech = 1,
    TuyaSmartAvsCmdProvideSpeech,
    TuyaSmartAvsCmdEndpointSpeech,
    TuyaSmartAvsCmdStopSpeech,
    TuyaSmartAvsCmdNotifySpeech,
    TuyaSmartAvsCmdStopSpeech_IsAck,
} TuyaSmartAudioCMD;

typedef enum : NSInteger {
    TYAudioCommonCmd_ClearToken = 0,
    TYAudioCommonCmd_NotificationStatus = 1,
} TYAudioCommonCmd;


NS_ASSUME_NONNULL_BEGIN



@interface TuyaSmartBLEAudioStartModel : NSObject

@property (nonatomic, assign) TYAudioAudioFormat audioFormat;

@property (nonatomic, assign) TYAudioAudioProfile audioProfile;
// NO : Play
@property (nonatomic, assign) BOOL isSuppressEarcon;

@property (nonatomic, assign) BOOL isPlayVoice;

@property (nonatomic, copy) NSString *dialogId;

@property (nonatomic, copy) NSString *uuid __attribute__((deprecated("Use -deviceId."))); ;

@property (nonatomic, copy) NSString *deviceId;

@end

@interface TuyaSmartBLEAudioProvideModel : NSObject

@property (nonatomic, assign) TYAudioAudioFormat audioFormat;

@property (nonatomic, assign) TYAudioAudioProfile audioProfile;

@property (nonatomic, copy) NSString *dialogId;

@property (nonatomic, copy) NSString *uuid __attribute__((deprecated("Use -deviceId."))); ;

@property (nonatomic, copy) NSString *deviceId;

@end


NS_ASSUME_NONNULL_END
