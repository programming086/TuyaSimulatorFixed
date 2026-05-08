//
//  TYBLEDataManager.h
//  TuyaSmartBLEKit
//
//  Created by tjl on 2021/7/2.
//

#import <Foundation/Foundation.h>
#import "TYBLEDeviceInfoProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface TYBLEDataManager : NSObject

TYSDK_SINGLETON

- (void)handleNotifyData:(NSData *)data deviceInfo:(id<TYBLEDeviceInfoProtocol>)deviceInfo type:(TYBLEConfigType)type completion:(void(^)(NSData *resultData))completion;

- (void)handleNotifyData:(NSData *)data deviceInfo:(id<TYBLEDeviceInfoProtocol>)deviceInfo type:(TYBLEConfigType)type ackHeadData:(nullable NSData *)ackHeadData completion:(void(^)(NSData *resultData))completion;

@end

NS_ASSUME_NONNULL_END
