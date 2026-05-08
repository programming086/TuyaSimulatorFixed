//
//  IndustryActivatorToken.h
//  IndustryActivatorImpl
//
//  Created by 后主 on 2022/8/11.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IndustryActivatorToken : NSObject

/// The token retrieved from the server. Use it to polling the registration result.
@property (nonatomic, copy) NSString *token;

/// The expired time of the token.
@property (nonatomic, assign) int expireTime;

/// Current usable region. Support AY, EU, US. AY represents Alibaba Cloud in China.
@property (nonatomic, copy) NSString *region;

/// The returned secret for device encryption and decryption.
@property (nonatomic, copy) NSString *secret;


- (NSString *)pairingToken;

@end

NS_ASSUME_NONNULL_END

