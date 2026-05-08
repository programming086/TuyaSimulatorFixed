#ifdef __OBJC__
#import <Foundation/Foundation.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "ThingMachRegister.h"
#import "ThingMachRegisterDebugger.h"
#import "ThingMachRegisterDefine.h"
#import "ThingMachRegisterDefineExt.h"
#import "ThingMachRegisterManager.h"

FOUNDATION_EXPORT double ThingMachRegisterVersionNumber;
FOUNDATION_EXPORT const unsigned char ThingMachRegisterVersionString[];

