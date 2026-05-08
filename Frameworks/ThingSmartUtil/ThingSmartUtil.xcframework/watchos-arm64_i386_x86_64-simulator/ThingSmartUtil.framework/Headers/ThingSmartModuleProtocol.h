//
//  ThingSmartModuleProtocol.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartModuleProtocol <NSObject>

@property (nonatomic, weak) NSObject *moduleEntry;

@end


@protocol ThingSmartDeviceCoreEntry <ThingSmartModuleProtocol>

- (void)configSocketWithUniversal:(BOOL)universal uid:(NSString *)uid configKey:(nullable NSData *)configKey broadcastKey:(nullable NSData *)broadcastKey sendKey:(nullable NSData *)sendKey;

- (void)configMQTT:(id)configModel appKey:(NSString *)appKey appSecret:(NSString *)appSecret ecode:(NSString *)ecode partnerIdentity:(NSString *)partnerIdentity uuid:(NSString *)uuid sid:(NSString *)sid;

- (void)registerYuNetServiceWithMeshId:(NSString *)meshId meshKey:(NSString *)meshKey clientId:(NSString *)clientId;

- (void)unRegisterYuNetService;

@end


@protocol ThingSmartChannelRegEntry <ThingSmartModuleProtocol>

@required

- (void)registMQTT;

- (void)registSocket;

- (BOOL)disconnect;

- (BOOL)reconnect;

- (NSString *)getUserCountryCode;

@property (nonatomic, assign) BOOL manualRegister;

@end

NS_ASSUME_NONNULL_END
