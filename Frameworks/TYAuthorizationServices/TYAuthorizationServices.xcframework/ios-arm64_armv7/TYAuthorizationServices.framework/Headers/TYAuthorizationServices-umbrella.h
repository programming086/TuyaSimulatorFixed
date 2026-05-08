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

#import "TYPrivacyAuthCheckProtocol.h"
#import "TYPrivacyAuthConfig.h"
#import "TYPrivacyAuthProtocol.h"
#import "TYBluetoothAuthProtocol.h"
#import "TYCameraAuthProtocol.h"
#import "TYContactAuthProtocol.h"
#import "TYHomeKitAuthProtocol.h"
#import "TYLocalNetworkAuthProtocol.h"
#import "TYLocationAuthProtocol.h"
#import "TYMicrophoneAuthProtocol.h"
#import "TYNotificationsAuthProtocol.h"
#import "TYPhotosAuthProtocol.h"
#import "TYAuthorizationServices.h"

FOUNDATION_EXPORT double TYAuthorizationServicesVersionNumber;
FOUNDATION_EXPORT const unsigned char TYAuthorizationServicesVersionString[];

