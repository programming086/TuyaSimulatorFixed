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

#import "TYActivatorFactoryConfig.h"
#import "TYActivatorPairingDeviceEditInfo.h"
#import "TYActivatorResultModel.h"
#import "TYActivatorExternalExtensionProtocol+Plug.h"
#import "TYActivatorFactoryPlugProtocol.h"
#import "TYActivatorProtocol+Plug.h"
#import "TYActivatorBTSearchDeviceStepProtocol.h"
#import "TYActivatorCreateTokenStepProtocol.h"
#import "TYActivatorQRPrepareStepProtocol.h"
#import "TYActivatorQuitEndStepProtocol.h"
#import "TYActivatorResultEndStepProtocol.h"
#import "TYActivatorSearchDeviceStepProtocol.h"
#import "TYActivatorSearchResultStepProtocol.h"
#import "TYActivatorSUBSearchDeviceStepProtocol.h"
#import "TYActivatorWCSearchDeviceStepProtocol.h"
#import "TYActivatorWifiInputStepProtocol.h"
#import "TYActivatorDefineStepHeader.h"
#import "TYActivatorFactoryProtocol.h"
#import "TYActivatorLinkModeDefine.h"
#import "TYActivatorStepProtocol.h"
#import "TYActivatorPlugAPI.h"

FOUNDATION_EXPORT double TYActivatorPlugAPIVersionNumber;
FOUNDATION_EXPORT const unsigned char TYActivatorPlugAPIVersionString[];

