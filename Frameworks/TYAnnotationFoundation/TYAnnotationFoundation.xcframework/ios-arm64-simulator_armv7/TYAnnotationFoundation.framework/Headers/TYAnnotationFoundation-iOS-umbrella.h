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

#import "TYAnnotationFoundation.h"
#import "TYAPIAnnotation.h"
#import "TYBaseAnnotation.h"
#import "TYLaunchAnnotation.h"
#import "TYRegisterAPIProtocol.h"
#import "TYRegisterLaunchProtocol.h"
#import "TYRegisterRouterProtocol.h"
#import "TYRouterAnnotation.h"
#import "TYUITestAnnotation.h"
#import "TYUITestContext.h"

FOUNDATION_EXPORT double TYAnnotationFoundationVersionNumber;
FOUNDATION_EXPORT const unsigned char TYAnnotationFoundationVersionString[];

