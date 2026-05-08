
#import <Foundation/Foundation.h>
#import "ThingEncryptWebImageCompat.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingImageSecurityLevel) {
    ThingImageSecurityLevelOne = 1,
    ThingImageSecurityLevelTwo = 2,
    ThingImageSecurityLevelThree = 3,
    ThingImageSecurityLevelFour = 4,
    ThingImageSecurityLevelFive = 5,
};


@interface ThingImageCoder : NSObject

#pragma mark - Decrypt
+ (nullable UIImage *)decryptImageWithData:(NSData *)data encryptKey:(NSString *)encryptKey;
+ (nullable NSData *)decryptWithData:(NSData *)data encryptKey:(NSString *)encryptKey;


#pragma mark - Encrypt
+ (NSData *)encryptImageWithImage:(UIImage *)image encryptKey:(NSString *)encryptKey securityLevel:(ThingImageSecurityLevel)securityLevel;
+ (NSData *)encryptData:(NSData *)data encryptKey:(NSString *)encryptKey securityLevel:(ThingImageSecurityLevel)securityLevel;
+ (NSData *)encryptImageWithImage:(UIImage *)image encryptKey:(NSString *)encryptKey;
+ (NSData *)encryptData:(NSData *)data encryptKey:(NSString *)encryptKey;


#pragma mark -  EncryptyKey
+ (NSString *)encryptKeyForImagePath:(NSString *)imagePath;
+ (void)setEncryptKey:(NSString *)encryptKey forImagePath:(NSString *)imagePath;


@end

NS_ASSUME_NONNULL_END
