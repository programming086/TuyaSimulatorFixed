//
//  TuyaSmartBLEAudioManager.h
//  TuyaSmartBLEKit
//
//  Created by tjl on 2021/4/10.
//

#import <Foundation/Foundation.h>
#import "TuyaSmartBLEAudioStartModel.h"
#import "TYBLEAudioVoiceTokenModel.h"
#import "TYBLEAudioAlarmClockModel.h"
#import "TYBLEAudioToDoListModel.h"
#import "TYBLEAudioWeatherModel.h"
#import "TuyaSmartBLEAudioStartModel.h"
#import "TuyaSmartBLEAudioStartModel.h"


NS_ASSUME_NONNULL_BEGIN

typedef void (^TYSuccessTokenModel)(TYBLEAudioVoiceTokenModel *tokenModel);

@protocol TuyaSmartBLEAudioManagerDelegate <NSObject>

- (void)audioStartSpeech:(TuyaSmartBLEAudioStartModel *)model;

- (void)audioProvideSpeech:(TuyaSmartBLEAudioProvideModel *)model;

- (void)audioStopSpeech:(NSString *)dialogId uuid:(NSString *)uuid errorCode:(TYAudioErrorCode)error;

- (void)audioData:(NSData *)data uuid:(NSString *)uuid audioFormat:(TYAudioAudioFormat)audioFormat;

//token

@end

@interface TuyaSmartBLEAudioManager : NSObject

/// Single instance.
+ (instancetype)sharedInstance;

@property (nonatomic, weak) id<TuyaSmartBLEAudioManagerDelegate> delegate;

- (void)publishAudioStartSpeech:(int)status uuid:(NSString *)uuid dialogId:(NSString *)dialogId;

- (void)publishAudioProvideSpeech:(NSString *)uuid dialogId:(NSString *)dialogId;

- (void)publishAudioSpeechState:(TuyaSmartAudioState)state uuid:(NSString *)uuid;

- (void)publishAudioEndpoint:(NSString *)uuid dialogId:(NSString *)dialogId;
// 0 - result : NSString,  1 - result : TYBLEAudioWeatherModel,  2 - result : TYBLEAudioToDoListModel
- (void)publishAudioResult:(id)result type:(TYAudioResultType)type uuid:(NSString *)uuid;

- (void)publishAudioStopSpeech:(TYAudioErrorCode)errorCode uuid:(NSString *)uuid dialogId:(NSString *)dialogId;

- (void)setAlarmClockWithAlarmClockModel:(TYBLEAudioAlarmClockModel *)model uuid:(NSString *)uuid success:(TYSuccessHandler)success failure:(TYFailureError)failure;

- (void)getAudioVoiceAuthorizationToken:(TYAudioTokenType)type uuid:(NSString *)uuid success:(TYSuccessTokenModel)success failure:(TYFailureError)failure;

- (void)publishAudioMD5Token:(NSString *)md5Token token:(NSString *)token uuid:(NSString *)uuid;

- (void)clearAuthorizationToken:(NSString *)uuid success:(TYSuccessHandler)success failure:(TYFailureError)failure;

// notifyFlag : 0 - invalid value； 1 - Have notice， 2 - Notification clear。
- (void)setNotificationStatus:(int)notifyFlag isPermanentVision:(BOOL)isPermanentVision isPlayAudio:(BOOL)isPlayAudio uuid:(NSString *)uuid success:(TYSuccessHandler)success failure:(TYFailureError)failure;



@end

NS_ASSUME_NONNULL_END
