
#ifndef ThingGroupManagerKit_h
#define ThingGroupManagerKit_h

#import "ThingGroupServiceProtocol.h"
#import "ThingGroupServiceMaker.h"
#import "ThingGroupMakerHelper.h"
#import "ThingGroupBaseError.h"
#import "ThingGroupDef.h"

#import "ThingGroupBaseService.h"
#import "ThingWiFiGroupService.h" // Regular WiFi group
#import "ThingStandardWiFiGroupService.h" // Standard WiFi group
#import "ThingZigbeeGroupService.h" // Regular Zigbee group
#import "ThingStandardZigbeeGroupService.h" // Standard Zigbee group
#import "ThingBLEMeshGroupService.h" // Regular private Mesh group
#import "ThingSIGMeshGroupService.h" // Regular SIGMesh group
#import "ThingStandardSIGMeshGroupService.h" // Standard SIGMesh group
#import "ThingGroupBeaconService.h" // Regular Beacon group
#import "ThingThreadGroupService.h" // Regular Thread group

#import "ThingZigbeeRemoteControlGroupService.h" // Zigbee remote control group
#import "ThingSIGMeshRemoteControlService.h" // SIGMesh remote control group
#import "ThingSIGMeshRemoteControlNewService.h" // SIGMesh remote control group -- Supports adding devices via gateway links and linking when adding low-power devices

#endif /* ThingGroupManagerKit_h */
