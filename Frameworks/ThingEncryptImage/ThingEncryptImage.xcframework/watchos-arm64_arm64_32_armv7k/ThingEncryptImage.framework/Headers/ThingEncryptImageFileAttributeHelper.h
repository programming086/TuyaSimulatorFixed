
#import <Foundation/Foundation.h>
#import "ThingEncryptWebImageCompat.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingEncryptImageFileAttributeHelper : NSObject

+ (nullable NSArray<NSString *> *)extendedAttributeNamesAtPath:(nonnull NSString *)path traverseLink:(BOOL)follow error:(NSError * _Nullable * _Nullable)err;
+ (BOOL)hasExtendedAttribute:(nonnull NSString *)name atPath:(nonnull NSString *)path traverseLink:(BOOL)follow error:(NSError * _Nullable * _Nullable)err;
+ (nullable NSData *)extendedAttribute:(nonnull NSString *)name atPath:(nonnull NSString *)path traverseLink:(BOOL)follow error:(NSError * _Nullable * _Nullable)err;
+ (BOOL)setExtendedAttribute:(nonnull NSString *)name value:(nonnull NSData *)value atPath:(nonnull NSString *)path traverseLink:(BOOL)follow overwrite:(BOOL)overwrite error:(NSError * _Nullable * _Nullable)err;
+ (BOOL)removeExtendedAttribute:(nonnull NSString *)name atPath:(nonnull NSString *)path traverseLink:(BOOL)follow error:(NSError * _Nullable * _Nullable)err;

@end

NS_ASSUME_NONNULL_END
