
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingAESCoder : NSObject

+ (NSData *)aes128CbcDecryptData:(NSData *)data key:(NSData *)key iv:(NSData *)iv;
+ (NSData *)aes128CbcEncryptData:(NSData *)data key:(NSData *)key iv:(NSData *)iv;

+ (NSData *)aes128GcmDecryptData:(NSData *)data key:(NSData *)key iv:(NSData *)iv;
+ (NSData *)aes128GcmEncryptData:(NSData *)data key:(NSData *)key iv:(NSData *)iv;

@end

NS_ASSUME_NONNULL_END
