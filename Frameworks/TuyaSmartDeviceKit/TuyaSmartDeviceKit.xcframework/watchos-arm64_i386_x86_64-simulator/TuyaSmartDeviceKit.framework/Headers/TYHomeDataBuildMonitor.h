//
//  TYHomeDataSetupServices.h
//  TuyaSmartDeviceKit
//
//  Created by Hiraeth on 2022/2/7.
//

#import <Foundation/Foundation.h>
#import <TuyaSmartUtil/TuyaSmartUtil.h>

#import "TYHouseInformationBuildProtocol.h"

NS_ASSUME_NONNULL_BEGIN

typedef void (^TYHIResultHandler)(void);

@interface TYHomeDataBuildMonitor : NSObject <TYHouseInformationBuildProtocol>

TYSDK_SINGLETON

- (void)registerProvider:(id<TYHouseInformationBuildProtocol>)provider;

- (void)unRegisterProvider:(id<TYHouseInformationBuildProtocol>)provider;

@end

NS_ASSUME_NONNULL_END
