
#import <Foundation/Foundation.h>
#import <ThingBluetooth/ThingBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief The Bluetooth mesh device model that is used to scan for Bluetooth peripherals.
@interface ThingBleMeshDeviceModel : NSObject

/// The name of the device.
@property (nonatomic, strong) NSString *name;

/// The device.
@property (nonatomic, strong) ThingBLEPeripheral *device;

/// The address of the device.
@property (nonatomic, assign) uint32_t address;

/// The product ID.
@property (nonatomic, strong) NSString *productId;

/// The version of the device.
@property (nonatomic, strong) NSString *version;

/// The MAC address of the device.
@property (nonatomic, assign) uint32_t mac;

/// The UUID of the device.
@property (nonatomic, strong) NSString *uuid;

/// The type of device. It is also the device size class.
@property (nonatomic, assign) uint32_t type;

/// The vendor information.
@property (nonatomic, strong) NSString *vendorInfo;

@end

NS_ASSUME_NONNULL_END
