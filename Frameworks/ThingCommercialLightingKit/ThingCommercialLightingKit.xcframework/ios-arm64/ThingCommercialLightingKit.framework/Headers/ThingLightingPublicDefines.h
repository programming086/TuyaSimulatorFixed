//
// ThingLightingPublicDefines.h
// ThingCommercialLightingKit
//
// Copyright (c) 2014-2024 Thing Inc. (https://developer.thing.com/)

#import <Foundation/Foundation.h>

#pragma mark - DPCODE
FOUNDATION_EXPORT NSString *const THING_LIGHTING_DP_SWITCH;
FOUNDATION_EXPORT NSString *const THING_LIGHTING_DP_BRIGHT;
FOUNDATION_EXPORT NSString *const THING_LIGHTING_DP_WORK_MODE;
FOUNDATION_EXPORT NSString *const THING_LIGHTING_DP_SCENE_DATA;
FOUNDATION_EXPORT NSString *const THING_LIGHTING_DP_COLOUR_DATA;
FOUNDATION_EXPORT NSString *const THING_LIGHTING_DP_TEMP_VALUE;

#pragma mark - SCENE ID
FOUNDATION_EXPORT NSString *const THING_LIGHTING_SCENE_WORK;
FOUNDATION_EXPORT NSString *const THING_LIGHTING_SCENE_MEETING;
FOUNDATION_EXPORT NSString *const THING_LIGHTING_SCENE_SIESTA;
FOUNDATION_EXPORT NSString *const THING_LIGHTING_SCENE_OFF_DUTY;

#pragma mark - WORK MODE
FOUNDATION_EXPORT NSString *const THING_LIGHTING_MODE_WHITE;
FOUNDATION_EXPORT NSString *const THING_LIGHTING_MODE_COLOUR;
FOUNDATION_EXPORT NSString *const THING_LIGHTING_MODE_SCENE;

#pragma mark - GROUP OTA
FOUNDATION_EXPORT NSString *const THING_LIGHTING_GROUP_OTA_ONLY_MESH;     //Only mesh devices in the current home are being upgraded in batches.
FOUNDATION_EXPORT NSString *const THING_LIGHTING_GROUP_OTA_ONLY_ZIGBEE;   //Only zigbee devices in the current home are being upgraded in batches.
FOUNDATION_EXPORT NSString *const THING_LIGHTING_GROUP_OTA_MESHANDZIGBEE; //There are mesh and zigbee devices in the current home that are upgrading in batches
