//
//  NSData+ThingEncrypt.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/4/16.
//

#import <Foundation/Foundation.h>
#import "ThingRSAImpl.h"
#import "ThingAESImpl.h"
#import "ThingDigestImpl.h"

NS_ASSUME_NONNULL_BEGIN

@interface NSData (ThingDigestAlgorithm)

- (NSString *)thing_md5String;

- (NSString *)thing_sha1String;
@end



// AES encryption, only supports returning Hex String
@interface NSData (ThingAESEncrypt)
- (NSData *)thing_AES128EncryptWithKey:(NSString *)key;
- (NSData *)thing_AES128DecryptWithKey:(NSString *)key;

- (NSData *)thing_AES256EncryptWithKey:(NSString *)key;
- (NSData *)thing_AES256DecryptWithKey:(NSString *)key;
@end



@interface NSData (ThingRSAEncrypt)
/**
 RSA public key encryption, returns the encrypted data

 @param publicKey The public key, supports both header and non-header formats. Can be defined with config.keyWithHeader.
 @param config Encryption configuration, default: + [ThingRSAConfig defaultConfig]
 @return The encrypted data
 */
- (NSData *)thing_RSAEncryptWithPublicKey:(NSString *)publicKey;
- (NSData *)thing_RSAEncryptWithPublicKey:(NSString *)publicKey config:(ThingRSAConfig *)config;

/**
 RSA private key decryption, returns the decrypted data

 @param privateKey The private key, supports both header and non-header formats. Can be defined with config.keyWithHeader.
 @return The decrypted content
 */
- (NSData *)thing_RSADecryptWithPrivateKey:(NSString *)privateKey;
- (NSData *)thing_RSADecryptWithPrivateKey:(NSString *)privateKey config:(ThingRSAConfig *)config;
@end
NS_ASSUME_NONNULL_END
