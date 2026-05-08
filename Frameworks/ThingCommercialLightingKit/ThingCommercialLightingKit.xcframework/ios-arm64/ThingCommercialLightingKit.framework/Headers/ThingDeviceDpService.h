//
//  ThingDeviceDpService.h
//  ThingSmartDeviceCoreKit
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceDpServiceModel : NSObject

@property (nonatomic, strong) NSMutableDictionary *dps;

@property (nonatomic, assign) double dpsTime;

@end

@interface ThingDeviceDpService : NSObject

ThingSDK_SINGLETON

- (void)saveDpsWithDevId:(NSString *)devId dps:(NSDictionary *)dps;

- (NSDictionary *)filterServerBleDps:(ThingSmartDeviceModel *)deviceModel;

@end

NS_ASSUME_NONNULL_END
