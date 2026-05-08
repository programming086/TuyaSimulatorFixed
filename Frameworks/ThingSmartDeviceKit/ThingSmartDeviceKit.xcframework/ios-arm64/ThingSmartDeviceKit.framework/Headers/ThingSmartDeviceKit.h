//
//  ThingSmartDeviceKit.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#ifndef ThingSmartDeviceKit_h
#define ThingSmartDeviceKit_h

/// The latest Internet communication protocol that is supported by clients.
//#define THING_CURRENT_GW_PROTOCOL_VERSION 2.2

/// The latest LAN communication protocol that is supported by clients.
//#define THING_CURRENT_LAN_PROTOCOL_VERSION 3.4

#import <ThingSmartBaseKit/ThingSmartBaseKit.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import <ThingSmartShareKit/ThingSmartShareKit.h>

#if TARGET_OS_IOS
    #import <ThingSmartMQTTChannelKit/ThingSmartMQTTChannelKit.h>
    #import <ThingSmartSocketChannelKit/ThingSmartSocketChannelKit.h>
#elif TARGET_OS_WATCH
    #define ThingSmartMQTTChannelDelegate NSObject
    #define ThingSmartSocketChannelDelegate NSObject
#endif

#import "ThingSmartHome.h"
#import "ThingSmartHome+Weather.h"
#import "ThingSmartHome+Stage.h"
#import "ThingSmartHome+ThingDeprecatedApi.h"
#import "ThingSmartWeatherModel.h"
#import "ThingSmartWeatherOptionModel.h"
#import "ThingSmartWeatherSketchModel.h"

#import "ThingSmartHomeManager.h"
#import "ThingSmartHomeMember.h"
#import "ThingSmartHomeInvitation.h"
#import "ThingSmartRoom.h"
#import "ThingSmartHomeDeviceShare.h"

#import "ThingSmartHomeMemberModel.h"
#import "ThingSmartHomeMemberRequestModel.h"
#import "ThingSmartHomeMember+ThingDeprecatedApi.h"

#import "ThingSmartGroup+DpCode.h"

#import "ThingSmartMultiControl.h"

#import "ThingSmartDeviceShareModel.h"
#import "ThingSmartHomeDeviceShare+ThingDeprecatedApi.h"

#import "ThingSmartDevice+Home.h"
#import "ThingSmartDeviceModel+Home.h"
#import "ThingSmartGroup+Home.h"
#import "ThingSmartGroupModel+Home.h"

#import "ThingSmartHome+BleMesh.h"
#import "ThingSmartHome+SIGMesh.h"

#import "ThingDeviceKitConfig.h"

#import "ThingHouseInformationBuildProtocol.h"
#import "ThingHomeDataBuildMonitor.h"

#import "ThingDiyHomeExtention.h"

#endif /* ThingSmartDeviceKit_h */
