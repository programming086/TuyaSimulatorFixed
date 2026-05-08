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

#import "ThingCameraUtil.h"
#import "ThingSmarCameraLiteCloudManager.h"
#import "ThingSmartCameraCloudDelegate.h"
#import "ThingSmartCameraDevice.h"
#import "ThingSmartCameraDeviceDataSource.h"
#import "ThingSmartCameraKitLite.h"
#import "ThingSmartCameraTypeProtocol.h"

FOUNDATION_EXPORT double ThingSmartCameraKitLiteVersionNumber;
FOUNDATION_EXPORT const unsigned char ThingSmartCameraKitLiteVersionString[];

