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

#import "TYDeviceSyncPlugAPI.h"
#import "TYDeviceSyncPlugAPIModel.h"

FOUNDATION_EXPORT double TYDeviceSyncPlugAPIVersionNumber;
FOUNDATION_EXPORT const unsigned char TYDeviceSyncPlugAPIVersionString[];

