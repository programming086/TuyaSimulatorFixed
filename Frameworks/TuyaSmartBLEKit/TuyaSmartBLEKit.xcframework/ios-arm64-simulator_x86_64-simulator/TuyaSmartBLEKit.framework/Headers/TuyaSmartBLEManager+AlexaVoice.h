//
//  TuyaSmartBLEManager+AlexaVoice.h
//  TuyaSmartBLEKit
//
//  Created by milong on 2022/4/7.
//

#import <TuyaSmartBLECoreKit/TuyaSmartBLEManager.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartBLEManager (AlexaVoice)

/// alexa start speedch
/// @param status status
/// @param deviceId deviceId
/// @param dialogId dialog Id
- (void)publishAudioStartSpeech:(int)status deviceId:(NSString *)deviceId dialogId:(NSString *)dialogId;

/// alexa provide speech
/// @param deviceId device id
/// @param dialogId dialog id
- (void)publishAudioProvideSpeech:(NSString *)deviceId dialogId:(NSString *)dialogId;

/// alex speech state
/// @param state state
/// @param deviceId devic id
- (void)publishAudioSpeechState:(TuyaSmartAudioState)state deviceId:(NSString *)deviceId;

/// alexa audio endpoint
/// @param deviceId device id
/// @param dialogId dialog id
- (void)publishAudioEndpoint:(NSString *)deviceId dialogId:(NSString *)dialogId;
// 0 - result : NSString,  1 - result : TYBLEAudioWeatherModel,  2 - result : TYBLEAudioToDoListModel
/// alexa audio result
/// @param result result
/// @param type type
/// @param deviceId device id
- (void)publishAudioResult:(id)result type:(TYAudioResultType)type deviceId:(NSString *)deviceId;

/// alexa stop speech
/// @param errorCode error code
/// @param deviceId device Id
/// @param dialogId dialog Id
- (void)publishAudioStopSpeech:(TYAudioErrorCode)errorCode deviceId:(NSString *)deviceId dialogId:(NSString *)dialogId;

/// alexa set alarm clock
/// @param model clockModel
/// @param deviceId device id
/// @param success success
/// @param failure failure
- (void)setAlarmClockWithAlarmClockModel:(TYBLEAudioAlarmClockModel *)model deviceId:(NSString *)deviceId success:(TYSuccessHandler)success failure:(TYFailureError)failure;

/// alexa audio voice AuthorizationToken
/// @param type type
/// @param deviceId deviceId
/// @param success success
/// @param failure failure
- (void)getAudioVoiceAuthorizationToken:(TYAudioTokenType)type deviceId:(NSString *)deviceId success:(TYSuccessTokenModel)success failure:(TYFailureError)failure;

/// alexa md5 token
/// @param md5Token md5Token
/// @param token token
/// @param deviceId device id
- (void)publishAudioMD5Token:(NSString *)md5Token token:(NSString *)token deviceId:(NSString *)deviceId;

/// alexa clear AuthorizationToken
/// @param deviceId device id
/// @param success success
/// @param failure failure
- (void)clearAuthorizationToken:(NSString *)deviceId success:(TYSuccessHandler)success failure:(TYFailureError)failure;

// notifyFlag : 0 - invalid value； 1 - Have notice， 2 - Notification clear。
/// alexa notification status
/// @param notifyFlag notify Flag
/// @param isPermanentVision permanent vision
/// @param isPlayAudio play audio
/// @param deviceId device id
/// @param success success
/// @param failure failure
- (void)setNotificationStatus:(int)notifyFlag isPermanentVision:(BOOL)isPermanentVision isPlayAudio:(BOOL)isPlayAudio deviceId:(NSString *)deviceId success:(TYSuccessHandler)success failure:(TYFailureError)failure;


/// alexa success device id
/// @param deviceId device id
/// @param token token
- (void)sendAlexaSuccessWithDeviceId:(NSString *)deviceId andToken:(NSString *)token;

@end

NS_ASSUME_NONNULL_END
