//
//  ThingSmartDeviceOTAModel.h
//  ThingSmartDeviceCoreKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// The device update status.
typedef enum : NSUInteger {
    /// Not updating.
    ThingSmartDeviceOTAModelUpgradeStatusNone = 0,
    /// Updating.
    ThingSmartDeviceOTAModelUpgradeStatusUpgrading = 2
} ThingSmartDeviceOTAModelUpgradeStatus;

typedef NS_ENUM(NSInteger, ThingSmartDeviceCapability){
    ThingSmartDeviceCapabilityOTAControlDP = 0,
    ThingSmartDeviceCapabilityUseLEOnline,
    ThingSmartDeviceCapabilityBeacon,
    ThingSmartDeviceCapabilityLinkEncrypt,
    ThingSmartDeviceCapabilityExtend,
    ThingSmartDeviceCapabilityTimer,
    ThingSmartDeviceCapabilityLinkBT = 6,
    ThingSmartDeviceCapabilityForceLink,
    ThingSmartDeviceCapabilitySupportPSK,
    ThingSmartDeviceCapabilitySupportFitting,
    ThingSmartDeviceCapabilityDiffOTA,
    ThingSmartDeviceCapabilityConnectivityGateway,
    ThingSmartDeviceCapabilityConnectivityIphone,
    ThingSmartDeviceCapabilityGatewayConnect,
    ThingSmartDeviceCapabilityOnlineType
};

typedef enum : NSUInteger {
    ThingSmartDeviceConnectivityTypeIphone = 0,
    ThingSmartDeviceConnectivityTypeGateWay = 1,
    ThingSmartDeviceConnectivityTypeIphoneAndGateWay = 2,
} ThingSmartDeviceConnectivityType;


@interface ThingSmartDeviceOTAModel : NSObject

/// The device ID.
@property (nonatomic, strong) NSString     *devId;

/// The status of device updates.
@property (nonatomic) ThingSmartDeviceOTAModelUpgradeStatus otaUpgradeStatus;
 
// Adds a beacon category for the Bluetooth LE beacon device.
@property (nonatomic, strong) NSString     *beaconCategory;

@property (nonatomic, strong) NSString *beaconKey;

@property (nonatomic, strong) NSString *bluetoothCapability;

//Bluetooth gateway sub-device ota capability
@property (nonatomic, strong) NSNumber *gwBTSubDevOtaCap;

@property (nonatomic, assign) BOOL zigbeeInstallCode;

- (BOOL)deviceCapabilitySupport:(ThingSmartDeviceCapability)capability;

- (BOOL)bluetoothCapabilityOfIndex:(NSInteger)index DEPRECATED_MSG_ATTRIBUTE("Please use deviceCapabilitySupport: instead");


/// if the current gateway supports sub-device upgrade, return YES.
/// - Parameter type: Only support `ThingSmartDeviceModelTypeBle` and `ThingSmartDeviceModelTypeSIGMeshSubDev`
- (BOOL)isGatewaySubDevOTASupported:(ThingSmartDeviceModelType)type;

- (ThingSmartDeviceConnectivityType)blueConnectivitySupport;
@end

NS_ASSUME_NONNULL_END
