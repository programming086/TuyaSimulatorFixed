//
//  NSObject+ThingSDKEncrypt.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

//#if TARGET_OS_IOS
//#if __has_include(<ThingSmartOpenSSL/NSData+ThingSDKGCMEncrypt.h>)
//#import <ThingSmartOpenSSL/NSData+ThingSDKGCMEncrypt.h>
//#elif __has_include("NSData+ThingSDKGCMEncrypt.h")
//#import "NSData+ThingSDKGCMEncrypt.h"
//#endif
//#endif


@interface NSString (ThingSDKEnCrypt)

- (NSString *)thingsdk_sha1String;

- (NSString *)thingsdk_md5String;

- (NSString *)thingsdk_sha256String;

- (NSString *)thingsdk_aes128EncryptWithKey:(NSString *)key;

- (NSString *)thingsdk_aes128CBCEncryptWithKey:(NSString *)key iv:(NSString *)iv;

- (NSString *)thingsdk_aes128NoPaddingEncryptWithKey:(NSString *)key;

- (NSString *)thingsdk_aes128DecryptWithKey:(NSString *)key;

- (NSString *)thingsdk_aes128CBCDecryptWithKey:(NSString *)key iv:(NSString *)iv;

- (NSString *)thingsdk_aes128NoPaddingDecryptWithKey:(NSString *)key;

- (NSString *)thingsdk_aes256EncryptWithKey:(NSString *)key;

- (NSString *)thingsdk_aes256DecryptWithKey:(NSString *)key;

- (NSString *)thingsdk_hexRSAEncryptWithPublicKey:(NSString *)publicKey;

- (NSString *)thingsdk_hexRSANoPaddingEncryptWithPublicKey:(NSString *)publicKey;

- (NSString *)thingsdk_hmacSHA256StringWithKey:(NSString *)key;

@end


@interface NSData (ThingSDKEncrypt)

- (NSString *)thingsdk_md5String;

- (NSString *)thingsdk_sha256String;

- (NSData *)thingsdk_aes128EncryptWithKeyData:(NSData *)keyData;

- (NSData *)thingsdk_aes128CBCEncryptWithKeyData:(NSData *)key iv:(NSData *)iv;

- (NSData *)thingsdk_aes128NoPaddingEncryptWithKeyData:(NSData *)keyData;

- (NSData *)thingsdk_aes128DecryptWithKeyData:(NSData *)keyData;

- (NSData *)thingsdk_aes128CBCDecryptWithKeyData:(NSData *)keyData iv:(NSData *)iv;

- (NSData *)thingsdk_aes128NoPaddingDecryptWithKeyData:(NSData *)keyData;

- (NSData *)thingsdk_aes256EncryptWithKeyData:(NSData *)keyData;

- (NSData *)thingsdk_aes256DecryptWithKeyData:(NSData *)keyData;

- (NSData *)thingsdk_hmacSHA256DataWithKey:(NSString *)key;

- (NSData *)thingsdk_hmacSHA256DataWithKeyData:(NSData *)keyData;

- (NSData *)thingsdk_encryptAes128GcmWithKey:(NSData *)key iv:(NSData *)iv add:(NSData *)add;

- (NSData *)thingsdk_decryptAes128GcmWithKey:(NSData *)key iv:(NSData *)iv add:(NSData *)add;

#if TARGET_OS_IOS

- (NSData *)thingsdk_aes128GCMDencryptWithKeyData:(NSData *)keyData iv:(NSData *)ivData add:(NSData *)addData error:(NSError **)error;

- (NSData *)thingsdk_aes128GCMEncryptWithKeyData:(NSData *)keyData iv:(NSData *)ivData add:(NSData *)addData error:(NSError **)error;
#endif

@end
