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

#import "IndustryAPActivator.h"
#import "IndustryBLEActivator.h"
#import "IndustryBLEWIFIActivator.h"
#import "IndustryBLEWIFICloudActivator.h"
#import "IndustryEZActivator.h"
#import "IndustryQRCodeActivator.h"
#import "IndustryQRScanActivator.h"
#import "IndustryWiredGatewayActivator.h"
#import "IndustryZigbeeSubDeviceActivator.h"
#import "IndustryBLEDiscovery.h"
#import "IndustryBLEWIFIDiscovery.h"
#import "IndustryWiredDiscovery.h"
#import "IndustryActivatorQRCodeReportResult.h"
#import "IndustryActivatorToken.h"
#import "IndustryBLEAdvModel.h"
#import "IndustryDeviceRegistrationResult.h"

FOUNDATION_EXPORT double IndustryActivatorImplVersionNumber;
FOUNDATION_EXPORT const unsigned char IndustryActivatorImplVersionString[];

