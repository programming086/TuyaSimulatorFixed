//
//  ThingSmartYuNetModuleProtocol.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import "ThingSmartModuleProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartYuNetModuleProtocol <ThingSmartModuleProtocol>

- (void)registerYuNet;

@end

@protocol ThingSmartYuNetChannelDelegate<NSObject>

@required

- (void)syncDevicStatusWithData:(NSDictionary *)data;

- (NSArray *)requireDirectlyConnectedDevice;

- (void)updateOnlineWithDevice:(NSSet <NSString *> *)devIds;

- (void)entry:(id)entry didReceivePublishData:(NSDictionary *)data;

- (void)entry:(id)entry didReceiveReportData:(NSDictionary *)data;
  
@end


@protocol ThingSmartYuNetRegEntry <ThingSmartModuleProtocol, ThingSmartYuNetChannelDelegate>

@required

- (void)registYuNetWithYuId:(NSString *)yuId yuKey:(NSString *)yuKey clientId:(NSString *)clientId delegate:(id<ThingSmartYuNetChannelDelegate>)delegate;

- (void)registerLocal;

- (void)registerCloud;

- (BOOL)hasYuLocalOnlineWithDevId:(NSString *)devId;

- (BOOL)hasYuCloudOnlineWithDevId:(NSString *)devId;

- (void)synchronousOnlineStatus;

- (void)synchronousDeviceOnlineStatus;

// [{"devId":"", dps: ""}]
- (void)publishMessageWithDeviceId:(NSString *)devId data:(NSArray *)data isCloud:(BOOL)isCloud success:(nullable void (^)(void))success failure:(nullable void (^)(NSError *))failure;

// [{"devId":"", dps: ""}]
- (void)reportMessageWithDeviceId:(NSString *)devId data:(NSArray *)data success:(nullable void (^)(void))success failure:(nullable void (^)(NSError *))failure;

- (void)closeLocalService;

- (void)closeCloudService;

- (NSInteger)getCurrentVersion;

// Adds a channel delegate.
- (void)addDelegate:(id<ThingSmartYuNetChannelDelegate>)delegate;

// Removes a channel delegate.
- (void)removeDelegate:(id<ThingSmartYuNetChannelDelegate>)delegate;

@end

NS_ASSUME_NONNULL_END
