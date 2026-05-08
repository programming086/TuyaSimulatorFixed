//
//  TuyaSmartModuleProtocol.h
//  TuyaSmartUtil
//
//  Created by 余豪 on 2021/12/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TuyaSmartModuleProtocol <NSObject>

@property (nonatomic, weak) NSObject *moduleEntry;

@end


@protocol TuyaSmartDeviceCoreEntry <TuyaSmartModuleProtocol>

- (void)configSocketWithUniversal:(BOOL)universal uid:(NSString *)uid configKey:(nullable NSData *)configKey broadcastKey:(nullable NSData *)broadcastKey sendKey:(nullable NSData *)sendKey;

- (void)configMQTT:(id)configModel appKey:(NSString *)appKey appSecret:(NSString *)appSecret ecode:(NSString *)ecode partnerIdentity:(NSString *)partnerIdentity uuid:(NSString *)uuid sid:(NSString *)sid;

@end


@protocol TuyaSmartChannelRegEntry <TuyaSmartModuleProtocol>

@required

- (void)registMQTT;

- (void)registSocket;

- (BOOL)disconnect;

- (BOOL)reconnect;

@end

NS_ASSUME_NONNULL_END
