//
//  TYBLEAudioVoiceToken.h
//  TuyaSmartBLEKit
//
//  Created by tjl on 2021/7/3.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    TYAudioTokenType_MD5Token = 0,
    TYAudioTokenType_MD5Tken_And_Token,
} TYAudioTokenType;

NS_ASSUME_NONNULL_BEGIN

@interface TYBLEAudioVoiceTokenModel : NSObject

@property (nonatomic, assign) TYAudioTokenType type;

@property (nonatomic, copy) NSString *md5Token;

@property (nonatomic, copy) NSString *token;

@end

NS_ASSUME_NONNULL_END
