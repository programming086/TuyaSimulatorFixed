
#ifndef ThingSmartBLEMeshKit_h
#define ThingSmartBLEMeshKit_h

#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import <ThingSmartActivatorCoreKit/ThingSmartActivatorCoreKit.h>

#import "ThingSmartUser+BleMesh.h"

#import "ThingSmartBleMesh.h"
#import "ThingSmartBleMesh+SIGMesh.h"

#import "ThingSmartBleMeshGroup.h"

#import "ThingBleMeshDeviceModel.h"
#import "ThingBLEMeshManager.h"

#import "ThingSmartBleMesh+SIGMesh.h"
#import "ThingSmartSIGMeshManager.h"
#import "ThingSmartSIGMeshManager+Activator.h"
#import "ThingSmartSIGMeshManager+Config.h"
#import "ThingSmartSIGMeshManager+Group.h"
#import "ThingSmartSIGMeshManager+OTA.h"
#import "ThingSmartSIGMeshDiscoverDeviceInfo.h"

#import "ThingSmartActivator+BleMesh.h"
#import "ThingSIGMeshConfigModel.h"
#import "ThingSIGMeshDpActionModel.h"
#import "ThingSIGMeshSceneModel.h"
#import "ThingSIGMeshDCSLinkageModel.h"
#import "ThingSIGMeshFittingMsgModel.h"
#import "ThingSIGMeshQueryDpsModel.h"
#import "ThingSIGMeshDCSLinkageConstants.h"
#import "ThingSIGMeshErrorCode.h"

#import "ThingSIGMeshQuickControl.h"

#undef ThingLog
#undef ThingSDKLogDebug
#undef ThingSDKLogInfo
#undef ThingSDKLogWarn
#undef ThingSDKLogError
#define ThingSDKLogDebug(...)         ThingSDKLog(0, @"ThingSmartBLEMeshKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define ThingSDKLogInfo(...)         ThingSDKLog(1, @"ThingSmartBLEMeshKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define ThingSDKLogWarn(...)         ThingSDKLog(2, @"ThingSmartBLEMeshKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define ThingSDKLogError(...)         ThingSDKLog(3, @"ThingSmartBLEMeshKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

#endif /* ThingSmartBLEMeshKit_h */
