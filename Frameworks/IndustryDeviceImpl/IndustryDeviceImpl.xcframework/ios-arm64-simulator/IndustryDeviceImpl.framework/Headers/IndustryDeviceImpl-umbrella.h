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

#import "IndustryDevice+BLE.h"
#import "IndustryDevice.h"
#import "IndustryFirmwareUpgradeModel.h"
#import "IndustryFirmwareUpgradeStatusModel.h"

FOUNDATION_EXPORT double IndustryDeviceImplVersionNumber;
FOUNDATION_EXPORT const unsigned char IndustryDeviceImplVersionString[];

