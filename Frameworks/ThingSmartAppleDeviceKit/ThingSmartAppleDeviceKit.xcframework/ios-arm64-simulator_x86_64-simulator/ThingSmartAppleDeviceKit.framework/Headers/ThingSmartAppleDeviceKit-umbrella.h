#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "ThingSmartDeviceModel+ThingSmartHomeKit.h"
#import "ThingSmartHomeKitDevice.h"
#import "ThingSmartHomeKitProductInfo.h"
#import "ThingSmartHomeKitProductInfoRequestModel.h"
#import "ThingSmartHomeKitSetupCodeInfo.h"
#import "ThingSmartHomeKitSetupCodeRequestModel.h"
#import "ThingSmartHomeKitDeviceService.h"
#import "ThingSmartAppleDeviceKit.h"
#import "ThingSmartHomeKitConfigBleUtil.h"
#import "ThingSmartHomeKitConfigProtocol.h"
#import "ThingSmartHomeKitConfigWifiUtil.h"
#import "ThingSmartHomeKitPermissionUtil.h"
#import "ThingSmartHomeKitUtil.h"
#import "ThingSmartHomeKitCheckUtil.h"

FOUNDATION_EXPORT double ThingSmartAppleDeviceKitVersionNumber;
FOUNDATION_EXPORT const unsigned char ThingSmartAppleDeviceKitVersionString[];

