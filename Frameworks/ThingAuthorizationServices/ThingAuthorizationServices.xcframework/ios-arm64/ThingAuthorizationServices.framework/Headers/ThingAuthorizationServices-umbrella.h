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

#import "ThingPrivacyAuthCheckProtocol.h"
#import "ThingPrivacyAuthConfig.h"
#import "ThingPrivacyAuthCustomConfig.h"
#import "ThingPrivacyAuthProtocol.h"
#import "ThingBluetoothAuthProtocol.h"
#import "ThingCameraAuthProtocol.h"
#import "ThingContactAuthProtocol.h"
#import "ThingHomeKitAuthProtocol.h"
#import "ThingLocalNetworkAuthProtocol.h"
#import "ThingLocationAuthProtocol.h"
#import "ThingMicrophoneAuthProtocol.h"
#import "ThingMotionAuthProtocol.h"
#import "ThingNotificationsAuthProtocol.h"
#import "ThingPhotosAuthProtocol.h"
#import "ThingPrivacyAuthABPtotocol.h"
#import "ThingAuthorizationServices.h"

FOUNDATION_EXPORT double ThingAuthorizationServicesVersionNumber;
FOUNDATION_EXPORT const unsigned char ThingAuthorizationServicesVersionString[];

