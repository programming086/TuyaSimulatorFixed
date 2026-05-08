
#ifndef ThingSmartCameraM_h
#define ThingSmartCameraM_h

#import <Foundation/Foundation.h>

#define ThingSmartCameraM_version @"7.5.1"

#import "ThingSmartCloudVideoPlayer.h"
#import "ThingSmartP2pConfigService.h"
#import "ThingSmartNVR.h"
#import "ThingSmartCameraAdvancedConfig.h"

FOUNDATION_EXPORT void EnableConsoleLog(bool enabled);

/// Call this when network status did changed
/// @param status network status, "unknown", "unreachable", "2G", "3G", "4G", "wifi"
FOUNDATION_EXPORT void SetNetworkStatus(NSString* status);

#endif /* ThingSmartCameraM_h */
