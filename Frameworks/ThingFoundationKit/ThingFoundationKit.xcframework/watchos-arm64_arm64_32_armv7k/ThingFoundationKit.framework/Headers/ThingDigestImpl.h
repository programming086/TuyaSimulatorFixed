
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, ThingDigestType) {
    ThingDigestMD2Type,        // MD2 algorithm
    ThingDigestMD4Type,        // MD4 algorithm
    ThingDigestMD5Type,        // MD5 algorithm
    ThingDigestSHA1Type,       // SHA1 algorithm
    ThingDigestSHA224Type,     // SHA224 algorithm
    ThingDigestSHA256Type,     // SHA256 algorithm
    ThingDigestSHA384Type,     // SHA384 algorithm
    ThingDigestSHA512Type,     // SHA512 algorithm
};

typedef NS_ENUM(NSInteger, ThingHmacType) {
    ThingHmacMD5Type,          // MD5 algorithm
    ThingHmacSHA1Type,         // SHA1 algorithm
    ThingHmacSHA224Type,       // SHA224 algorithm
    ThingHmacSHA256Type,       // SHA256 algorithm
    ThingHmacSHA384Type,       // SHA384 algorithm
    ThingHmacSHA512Type,       // SHA512 algorithm
};

/*
 Implementation of digest algorithms
 */
@interface ThingDigestImpl : NSObject

// MD and SHA algorithms
+ (NSData *)digestWithData:(NSData *)data type:(ThingDigestType)digestType;

// HMAC algorithm
+ (NSData *)hmacWithData:(NSData *)data keyData:(NSData *)keyData type:(ThingHmacType)hmacType;

@end
