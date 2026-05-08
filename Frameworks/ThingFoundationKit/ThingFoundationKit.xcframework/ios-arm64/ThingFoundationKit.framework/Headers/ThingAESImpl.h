
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ThingAESKeySize) {
    ThingAESKey128Bits,    // 128 bits
    ThingAESKey256Bits     // 256 bits
};

typedef NS_ENUM(NSInteger, ThingAESMode) {
    ThingAESModeP7ECB,     // ECB mode kCCOptionPKCS7Padding | kCCOptionECBMode
    ThingAESModeP7CBC      // CBC mode kCCOptionPKCS7Padding
};


@interface ThingAESConfig : NSObject

/**
 Key size, defaults to ThingAESKey128Bits.
 */
@property (nonatomic, assign) ThingAESKeySize keySize;

/**
 Encryption mode, defaults to ThingAESModeP7ECB.
 */
@property (nonatomic, assign) ThingAESMode mode;

/**
 Initialization vector used during ThingAESModeP7CBC encryption, defaults to empty.
 */
@property (nonatomic, strong) NSData *CBCIV;

+ (instancetype)default128Config;

+ (instancetype)default256Config;

@end


@interface ThingAESImpl : NSObject

/**
 AES encrypts data.
 
 @param data The content to encrypt.
 @param keyData The encryption key.
 @param config The encryption configuration. You can use + [ThingAESConfig defaultConfig] for the default.
 @return The encrypted content.
 */
+ (NSData *)encryptData:(NSData *)data keyData:(NSData *)keyData config:(ThingAESConfig *)config;

/**
 AES decrypts data.
 
 @param data The content to decrypt.
 @param keyData The decryption key.
 @param config The decryption configuration. You can use + [ThingAESConfig defaultConfig] for the default.
 @return The decrypted content.
 */
+ (NSData *)decryptData:(NSData *)data keyData:(NSData *)keyData config:(ThingAESConfig *)config;


# pragma mark - deprecated
// 128:ECB  256:CBC
+ (NSData *)encryptData:(NSData *)data keyData:(NSData *)keyData keySize:(ThingAESKeySize)keySize DEPRECATED_MSG_ATTRIBUTE("use encryptData:keyData:config: instead.");

// 128:ECB  256:CBC
+ (NSData *)decryptData:(NSData *)data keyData:(NSData *)keyData keySize:(ThingAESKeySize)keySize DEPRECATED_MSG_ATTRIBUTE("use decryptData:keyData:config: instead.");

@end
