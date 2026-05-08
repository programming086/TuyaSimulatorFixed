//
//  TuyaSmartLANAndMQTTVersionSupport.h
//  TuyaSmartDeviceCoreKit
//
//  Created by Tuya on 2022/6/21.
//

#import <Foundation/Foundation.h>
#import "TuyaSmartDeviceModel.h"
#import "TuyaSmartGroupModel.h"



/// Returns YES if the device supports the current LAN and MQTT protocol version
/// @param devIdOrGroupId devId Or groupId
/// @param isGroup If YES, the input id is groupId, otherwise it is devId
FOUNDATION_EXTERN BOOL IsDeviceOrGroupLanAndMQTTVersionSupport(NSString *devIdOrGroupId, BOOL isGroup);


@interface TuyaSmartDeviceModel (VersionSupport)
/// Returns YES if the device supports the current LAN and MQTT protocol version
- (BOOL)isLANAndMQTTVersionSupport;
@end



@interface TuyaSmartGroupModel (VersionSupport)
/// Returns YES if the device supports the current LAN and MQTT protocol version
- (BOOL)isLANAndMQTTVersionSupport;
@end
