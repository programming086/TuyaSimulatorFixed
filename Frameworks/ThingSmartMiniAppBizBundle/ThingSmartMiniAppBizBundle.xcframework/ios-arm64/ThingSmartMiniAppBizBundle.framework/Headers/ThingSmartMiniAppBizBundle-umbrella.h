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

#import "ThingMiniAppClient.h"
#import "ThingMiniAppCoreProtocol.h"
#import "ThingMiniAppDebugProtocol.h"
#import "ThingMiniAppDevelopProtocol.h"
#import "ThingMiniAppExtApiContext.h"
#import "ThingMiniAppExtApiModelProtocol.h"
#import "ThingMiniAppExtApiProtocol.h"
#import "ThingMiniAppInitialProtocol.h"
#import "ThingMiniAppWidgetProtocol.h"
#import "ThingSmartMiniAppBizBundle.h"

FOUNDATION_EXPORT double ThingSmartMiniAppBizBundleVersionNumber;
FOUNDATION_EXPORT const unsigned char ThingSmartMiniAppBizBundleVersionString[];

