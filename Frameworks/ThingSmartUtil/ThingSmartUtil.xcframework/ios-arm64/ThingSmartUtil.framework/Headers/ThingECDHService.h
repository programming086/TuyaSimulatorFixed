//
//  ThingECDHService.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingECDHService : NSObject

- (NSData *)pubKeyHexData __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

- (NSString *)base64EncodedPubKey __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

- (NSData *)ecdhWithServerPubKey:(NSData *)serverPubKeyData __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

- (SecKeyRef)convertDataToSecKeyRef:(NSData *)data __IOS_AVAILABLE(10.0) __WATCHOS_AVAILABLE(3.0);

- (NSData *)aesCTRDecryptData:(NSData *)dataIn
                           iv:(NSData *)iv
                          key:(NSData *)key
                        error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
