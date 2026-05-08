
#ifndef ThingActivatorPlugAPI_h
#define ThingActivatorPlugAPI_h

/// old protocol
#import "ThingActivatorProtocol+Plug.h"
#import "ThingActivatorExternalExtensionProtocol+Plug.h"

/// plug protocol
#import "ThingActivatorConfigurePlugProtocol.h"
#import "ThingActivatorBizCapacityPlugProtocol.h"
#import "ThingActivatorFactoryPlugProtocol.h"

/// data definition
#import "ThingActivatorFactoryConfig.h"
#import "ThingActivatorLinkModeDefine.h"
#import "ThingActivatorPairingDeviceEditInfo.h"
#import "ThingActivatorResultModel.h"
#import "ThingActivatorLinkModeInfo.h"
#import "ThingActivatorFactorySwitchIntent.h"
#import "ThingActivatorSearchResultStepAction.h"
#import "ThingActivatorEntryConfig.h"

/// process protocol
#import "ThingActivatorFactoryContextProtocol.h"
#import "ThingActivatorFactoryProtocol.h"
#import "ThingActivatorStepProtocol.h"

/// step configuration
#import "ThingActivatorDefineStepHeader.h"
#import "ThingActivatorBTSearchDeviceStepConfigProtocol.h"
#import "ThingActivatorCreateTokenStepConfigProtocol.h"
#import "ThingActivatorQRPrepareStepConfigProtocol.h"
#import "ThingActivatorQuitEndStepConfigProtocol.h"
#import "ThingActivatorResultEndStepConfigProtocol.h"
#import "ThingActivatorSearchDeviceStepConfigProtocol.h"
#import "ThingActivatorSearchResultStepConfigProtocol.h"
#import "ThingActivatorWifiInputStepConfigProtocol.h"

#endif /* ThingActivatorPlugAPI_h */
