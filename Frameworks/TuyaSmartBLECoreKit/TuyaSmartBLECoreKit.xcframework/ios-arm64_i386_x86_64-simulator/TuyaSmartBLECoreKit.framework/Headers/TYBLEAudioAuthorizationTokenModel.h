//
//  TYBLEAudioAuthorizationTokenModel.h
//  TuyaSmartBLEKit
//
//  Created by tjl on 2021/7/9.
//

#import <Foundation/Foundation.h>
#import "TYBLEAudioVoiceTokenModel.h"
#import "TuyaSmartBLEAudioManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TYBLEAudioAuthorizationTokenModel : NSObject

@property (nonatomic, copy) NSString *uuid __attribute__((deprecated("Use -deviceId."))); ;

@property (nonatomic, copy) NSString *deviceId;

@property (nonatomic, assign) TYAudioTokenType type;

@property (nonatomic, strong) TYBLEAudioVoiceTokenModel *tokenModel;

@property (nonatomic, copy) TYSuccessTokenModel successBlock;

@property (nonatomic, copy) TYFailureError failureBlock;

@end

NS_ASSUME_NONNULL_END
