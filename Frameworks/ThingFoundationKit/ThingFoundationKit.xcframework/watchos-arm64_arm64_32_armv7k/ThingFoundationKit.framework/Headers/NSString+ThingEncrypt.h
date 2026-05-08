//
//  NSString+ThingEncrypt.h
//  ThingFoundationKit
//
//  Created by ThingInc on 2019/4/16.
//

#import <Foundation/Foundation.h>
#import "ThingDigestImpl.h"
#import "ThingRSAImpl.h"
#import "ThingAESImpl.h"

@interface NSString (ThingDigestAlgorithm)

- (NSString *)thing_md5String;

- (NSString *)thing_sha1String;

- (NSData *)thing_hmacWithKey:(NSString *)key type:(ThingHmacType)type;
@end



// AES encryption, only supports returning Hex String
@interface NSString (ThingAESEncrypt)

// AES128 encryption and decryption, key length must be less than or equal to 16, otherwise encryption will fail
- (NSString *)thing_AES128EncryptWithKey:(NSString *)key;
- (NSString *)thing_AES128DecryptWithKey:(NSString *)key;

// AES256 encryption and decryption, key length must be less than or equal to 32, otherwise encryption will fail
- (NSString *)thing_AES256EncryptWithKey:(NSString *)key;
- (NSString *)thing_AES256DecryptWithKey:(NSString *)key;
@end



@interface NSString (ThingRSAEncrypt)

#pragma mark - 加密

/**
 RSA public key encryption, returns Base64 encoded ciphertext

 @param publicKey The public key, supports both header and non-header formats. Can be defined with config.keyWithHeader.
 @param config Encryption configuration, default: + [ThingRSAConfig defaultConfig]
 @return Base64 encoded ciphertext
 */
- (NSString *)thing_base64RSAEncryptWithPublicKey:(NSString *)publicKey;
- (NSString *)thing_base64RSAEncryptWithPublicKey:(NSString *)publicKey config:(ThingRSAConfig *)config;

/**
 RSA public key encryption, returns Hexadecimal encoded ciphertext

 @param publicKey The public key, supports both header and non-header formats. Can be defined with config.keyWithHeader.
 @param config Encryption configuration, default: + [ThingRSAConfig defaultConfig]
 @return Hexadecimal encoded ciphertext
 */
- (NSString *)thing_hexRSAEncryptWithPublicKey:(NSString *)publicKey;
- (NSString *)thing_hexRSAEncryptWithPublicKey:(NSString *)publicKey config:(ThingRSAConfig *)config;


#pragma mark - 解密

/**
 RSA private key decryption of Hexadecimal ciphertext, returns decrypted content

 @param privateKey The private key, supports both header and non-header formats. Can be defined with config.keyWithHeader.
 @return Decrypted content
 */
- (NSString *)thing_RSADecryptHexWithPrivateKey:(NSString *)privateKey;
- (NSString *)thing_RSADecryptHexWithPrivateKey:(NSString *)privateKey config:(ThingRSAConfig *)config;

/**
 RSA private key decryption of Base64 ciphertext, returns decrypted content

 @param privateKey The private key, supports both header and non-header formats. Can be defined with config.keyWithHeader.
 @return Decrypted content
 */
- (NSString *)thing_RSADecryptBase64WithPrivateKey:(NSString *)privateKey;
- (NSString *)thing_RSADecryptBase64WithPrivateKey:(NSString *)privateKey config:(ThingRSAConfig *)config;

@end
