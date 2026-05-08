
#import <Foundation/Foundation.h>
#import <Security/Security.h>

@class ThingRSAConfig;

@interface ThingRSAConfig : NSObject
/**
 Type of RSA encryption padding, default is kSecPaddingPKCS1.

 kSecPaddingPKCS1: The most common padding mode, adds randomness so even with the same key the encrypted result differs each time.
 Input: The content to be encrypted must be at least 11 bytes shorter than the RSA key modulus (modulus - 11). If the plaintext is too long, it must be split and padded.
 Corresponding Java Padding: RSA/ECB/PKCS1Padding

 kSecPaddingOAEP: Adds randomness so even with the same key the encrypted result differs each time.
 Input: RSA_size(rsa) - 41
 Corresponding Java Padding: RSA/NONE/OAEPWithSHA1AndMGF1Padding

 kSecPaddingNone: No padding, encrypted content with the same key will be identical each time.
 Input: Can be as long as the RSA key modulus. If the plaintext is too long, it must be split and padded.
 Corresponding Java Padding: RSA
 */
@property (nonatomic, assign) SecPadding paddingType;

/**
 The difference in bytes between each encryption block and the public key size.

 PKCS1_PADDING: 11, OAEP_PADDING: 41, NONE: 0
 */
@property (nonatomic, assign, readonly) int blockInterval;

/**
 Indicates if the public/private key includes headers and trailers, default is NO.

 Public Key:
        -----BEGIN PUBLIC KEY-----
        -----END PUBLIC KEY-----

 Private Key:
        -----BEGIN RSA PRIVATE KEY-----
        -----END RSA PRIVATE KEY-----
 */
@property (nonatomic, assign) BOOL keyWithHeader;

/**
 Returns the default configuration instance.
 */
+ (instancetype)defaultConfig;

@end


typedef NS_ENUM(NSInteger, ThingRSAKeySize) {
    ThingRSAKey512Bits  = 512,     // 512 bits
    ThingRSAKey1024Bits = 1024,    // 1024 bits
    ThingRSAKey2048Bits = 2048     // 2048 bits
};

// This class is used only for encrypting/decrypting data of NSData type. The conversion of input parameters and return values is handled by higher-level classes (e.g., NSString+ThingSecurity\NSData+ThingSecurity).
@interface ThingRSAImpl : NSObject

/**
 Performs RSA encryption.

 @param data The data to be encrypted.
 @param publicKey The public key, supports both headered and non-headered formats, which can be defined by config.keyWithHeader.
 @param config Encryption configuration, you can use + [ThingRSAConfig defaultConfig] for default settings.
 @return The encrypted data.
 */
+ (NSData *)encryptData:(NSData *)data publicKey:(NSString *)publicKey config:(ThingRSAConfig *)config;

/**
 Performs RSA decryption.

 @param data The data to be decrypted.
 @param privateKey The private key, supports both headered and non-headered formats, which can be defined by config.keyWithHeader.
 @param config Decryption configuration, you can use + [ThingRSAConfig defaultConfig] for default settings.
 @return The decrypted data.
 */
+ (NSData *)decryptData:(NSData *)data privateKey:(NSString *)privateKey config:(ThingRSAConfig *)config;

/**
 Generates a public and private key pair.

 @param keySize The size of the key in bits.
 @param pair A callback block to provide the generated public and private keys.
 */
+ (void)generateKeyPairWithSize:(ThingRSAKeySize)keySize keyPair:(void(^)(SecKeyRef publicKeyRef, SecKeyRef privateKeyRef))pair;

@end
