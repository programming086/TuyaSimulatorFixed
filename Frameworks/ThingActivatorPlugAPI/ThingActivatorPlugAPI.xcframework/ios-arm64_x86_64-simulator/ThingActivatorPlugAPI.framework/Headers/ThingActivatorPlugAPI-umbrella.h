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

#import "ThingActivatorEntryConfig.h"
#import "ThingActivatorFactoryConfig.h"
#import "ThingActivatorFactorySwitchIntent.h"
#import "ThingActivatorLinkModeDefine.h"
#import "ThingActivatorLinkModeInfo.h"
#import "ThingActivatorPairingDeviceEditInfo.h"
#import "ThingActivatorResultModel.h"
#import "ThingActivatorSearchResultStepAction.h"
#import "ThingActivatorBizCapacityPlugProtocol.h"
#import "ThingActivatorConfigurePlugProtocol.h"
#import "ThingActivatorExternalExtensionProtocol+Plug.h"
#import "ThingActivatorFactoryPlugProtocol.h"
#import "ThingActivatorProtocol+Plug.h"
#import "ThingActivatorBTSearchDeviceStepConfigProtocol.h"
#import "ThingActivatorCreateTokenStepConfigProtocol.h"
#import "ThingActivatorDefineStepHeader.h"
#import "ThingActivatorQRPrepareStepConfigProtocol.h"
#import "ThingActivatorQuitEndStepConfigProtocol.h"
#import "ThingActivatorResultEndStepConfigProtocol.h"
#import "ThingActivatorSearchDeviceStepConfigProtocol.h"
#import "ThingActivatorSearchResultStepConfigProtocol.h"
#import "ThingActivatorWifiInputStepConfigProtocol.h"
#import "ThingActivatorFactoryContextProtocol.h"
#import "ThingActivatorFactoryProtocol.h"
#import "ThingActivatorStepProtocol.h"
#import "ThingActivatorPlugAPI.h"

FOUNDATION_EXPORT double ThingActivatorPlugAPIVersionNumber;
FOUNDATION_EXPORT const unsigned char ThingActivatorPlugAPIVersionString[];

