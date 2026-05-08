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

#import "ThingActivatorMatterInterfaceProtocol.h"
#import "ThingActivatorMatterNetworkScannedModel.h"
#import "ThingConnectDeviceBuilder.h"
#import "ThingMatterDeviceModel.h"
#import "ThingMatterSetupPayload.h"
#import "ThingMatterAttributeBasicInfo.h"
#import "ThingMatterBasicInfoProtocol.h"
#import "ThingMatterBLEManagerInterfaceProtocol.h"
#import "ThingMatterManagerInterfaceProtocol.h"
#import "ThingMatterShareManagerInterfaceProtocol.h"
#import "ThingSmartMatterACLSyncStatusModel.h"
#import "ThingSmartMatterNodeModel.h"
#import "ThingMatterMultipleFabricInfoModel.h"
#import "ThingMatterMultipleFabricPasscodeModel.h"
#import "ThingMatterShareInterfaceAPI.h"
#import "ThingSmartMatterInterfaceAPI.h"

FOUNDATION_EXPORT double ThingSmartMatterInterfaceAPIVersionNumber;
FOUNDATION_EXPORT const unsigned char ThingSmartMatterInterfaceAPIVersionString[];

