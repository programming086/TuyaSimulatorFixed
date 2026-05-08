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

#import "ThingCameraAIDetectConfigModel.h"
#import "ThingSmartCameraAbility.h"
#import "ThingSmartCameraBirdIdentify.h"
#import "ThingSmartCameraBirdIdentifyService.h"
#import "ThingSmartCameraDPManager+DPCode.h"
#import "ThingSmartCameraDPManager+NVR.h"
#import "ThingSmartCameraDPManager.h"
#import "ThingSmartCameraKit.h"
#import "ThingSmartCameraLogManager.h"
#import "ThingSmartCameraMessage.h"
#import "ThingSmartCameraMessageMediaPlayer.h"
#import "ThingSmartCameraMessageModel.h"
#import "ThingSmartCameraMessageService.h"
#import "ThingSmartCameraSDK.h"
#import "ThingSmartCameraSkill.h"
#import "ThingSmartCameraVAS.h"
#import "ThingSmartCameraVASConstants.h"
#import "ThingSmartCameraVASModel.h"
#import "ThingSmartCloudManager.h"
#import "ThingSmartCloudModels.h"
#import "ThingSmartCloudService.h"
#import "ThingSmartDevice+doorbell.h"
#import "ThingSmartDevice+LowPowerDPPublish.h"
#import "ThingSmartDevice+offlineSupport.h"
#import "ThingSmartDeviceModel+CameraAdvancedAbility.h"
#import "ThingSmartDeviceModel+IPCSDK.h"
#import "ThingSmartDeviceModel+offlineSupport.h"
#import "ThingSmartDoorBellCallModel+Track.h"
#import "ThingSmartDoorBellManager.h"
#import "ThingSmartDoorBellTrack.h"
#import "ThingSmartPlaybackDate.h"
#import "ThingSmartPlaybackEventProtocol.h"
#import "ThingSmartPTZManager.h"

FOUNDATION_EXPORT double ThingSmartCameraKitVersionNumber;
FOUNDATION_EXPORT const unsigned char ThingSmartCameraKitVersionString[];

