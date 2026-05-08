//
// TuyaSmartBLEMeshKit.h
// TuyaSmartBLEMeshKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartBLEMeshKit_h
#define TuyaSmartBLEMeshKit_h

#import <TuyaSmartDeviceCoreKit/TuyaSmartDeviceCoreKit.h>
#import <TuyaSmartActivatorCoreKit/TuyaSmartActivatorCoreKit.h>

#import "TuyaSmartUser+BleMesh.h"

#import "TuyaSmartBleMesh.h"
#import "TuyaSmartBleMesh+SIGMesh.h"

#import "TuyaSmartBleMeshGroup.h"

#import "TYBleMeshDeviceModel.h"
#import "TYBLEMeshManager.h"

#import "TuyaSmartBleMesh+SIGMesh.h"
#import "TuyaSmartSIGMeshManager.h"
#import "TuyaSmartSIGMeshManager+Activator.h"
#import "TuyaSmartSIGMeshManager+Config.h"
#import "TuyaSmartSIGMeshManager+Group.h"
#import "TuyaSmartSIGMeshManager+OTA.h"
#import "TuyaSmartSIGMeshDiscoverDeviceInfo.h"

#import "TuyaSmartActivator+BleMesh.h"
#import "TuyaSIGMeshSceneModel.h"

#undef TYLog
#undef TYSDKLogDebug
#undef TYSDKLogInfo
#undef TYSDKLogWarn
#undef TYSDKLogError
#define TYSDKLogDebug(...)         TYSDKLog(0, @"TuyaSmartBLEMeshKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define TYSDKLogInfo(...)         TYSDKLog(1, @"TuyaSmartBLEMeshKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define TYSDKLogWarn(...)         TYSDKLog(2, @"TuyaSmartBLEMeshKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define TYSDKLogError(...)         TYSDKLog(3, @"TuyaSmartBLEMeshKit", __FILE__, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

#endif /* TuyaSmartBLEMeshKit_h */
