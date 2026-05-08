//
//  TuyaSmartSocketConfig.h
//  TuyaSmartDeviceCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)


#if TARGET_OS_IOS
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartSocketConfig : NSObject

- (void)registWithUniversal:(BOOL)universal uid:(NSString *)uid configKey:(nullable NSData *)configKey broadcastKey:(nullable NSData *)broadcastKey sendKey:(nullable NSData *)sendKey;

- (void)stop;

@end

NS_ASSUME_NONNULL_END
#endif
