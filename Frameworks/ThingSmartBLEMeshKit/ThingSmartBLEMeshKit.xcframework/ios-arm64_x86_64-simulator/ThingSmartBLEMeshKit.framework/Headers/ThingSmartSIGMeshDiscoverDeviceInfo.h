
#import <Foundation/Foundation.h>
#import <ThingBluetooth/ThingBLEAgent.h>
#import "ThingMeshBeaconAdverstingQuickFrame.h"

/// The type of Bluetooth mesh node to be scanned.
typedef NS_ENUM(NSUInteger, SIGMeshNodeProvisionType) {
    
    /// An unknown device.
    SIGMeshNodeUnknow,
    
    /// A new device.
    SIGMeshNodeUnprovision,
    
    /// A provisioned device.
    SIGMeshNodeProvisioned,
    
    /// A device that can be connected and controlled through a proxy.
    SIGMeshNodeProxyed,
};

/// The activator type of the Bluetooth mesh node.
typedef enum : NSUInteger {
    /// Standard pairing.
    ThingSIGMeshNodeActivatorTypeStandard = 0,
    
    /// Wi-Fi Easy Connect.
    ThingSIGMeshNodeActivatorTypeQuick = 1 << 0,
    
    /// Beacon Mesh
    ThingSIGMeshNodeActivatorTypeBeacon = 2 << 0,
} ThingSIGMeshNodeActivatorType;

NS_ASSUME_NONNULL_BEGIN

#define kQuickVersion @"kQuickVersion"
#define kMCUVersion @"kMCUVersion"

/// @brief The Bluetooth LE mesh device model that is used to scan a Bluetooth peripheral.
@interface ThingSmartSIGMeshDiscoverDeviceInfo : NSObject

/// The Bluetooth peripheral to be scanned.
@property (nonatomic, strong) ThingBLEPeripheral *peripheral;

/// The type of node.
@property (nonatomic, assign) SIGMeshNodeProvisionType provisionType;

/// The type of activator.
@property (nonatomic, assign) ThingSIGMeshNodeActivatorType activatorType;

@property (nonatomic, strong) ThingMeshBeaconAdverstingQuickFrame *quickFrame;

@property (nonatomic, strong) NSData *meshCategroy;

/// The MAC address of the `Powered by Thing` device node.
@property (nonatomic, copy) NSString *mac;

/// The product category code (PCC) value of the `Powered by Thing` device node.
@property (nonatomic, copy) NSString *type;

///The type of device.
@property (nonatomic, assign) NSInteger deviceType;

///The type of product.
@property (nonatomic, assign) NSInteger productType;

/// The product ID for `Powered by Thing` device node.
@property (nonatomic, copy) NSString *productId;

/// Applies to over-the-air (OTA) updates.
@property (nonatomic, copy) NSString *nodeId;

/// Indicates whether the pairing operation in Wi-Fi Easy Connect mode is successful. Valid values: `YES` and `NO`. This value is used as the extension information.
@property (nonatomic, strong) NSDictionary *extendInfo;

/// Device version
@property (nonatomic, copy) NSString *firmwareVersion;

@end

NS_ASSUME_NONNULL_END
