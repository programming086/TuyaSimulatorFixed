//
//  ThingHomeDataBuildMonitor.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

#import "ThingHouseInformationBuildProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^ThingHIResultHandler)(void);

@interface ThingHomeDataBuildMonitor : NSObject <ThingHouseInformationBuildProtocol>

ThingSDK_SINGLETON

- (void)registerProvider:(id<ThingHouseInformationBuildProtocol>)provider;

- (void)unRegisterProvider:(id<ThingHouseInformationBuildProtocol>)provider;

@end

NS_ASSUME_NONNULL_END
