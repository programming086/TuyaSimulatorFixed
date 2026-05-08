
#import <Foundation/Foundation.h>
#import <HomeKit/HomeKit.h>


NS_ASSUME_NONNULL_BEGIN

/// `HMAccessory`'s wrapped classes, defined some Thing Inc HomeKit Device properties
@interface ThingSmartHomeKitDevice : NSObject

/// A Boolean value indicating whether the accessory can be communicated with in the current network environment.
@property (assign, nonatomic, readonly, getter = isReachable) BOOL reachable;
/*!
 * @brief This property indicates whether this accessory is behind a bridge. If it is TRUE,
 *        the accessory cannot be removed from the home directly. Only the bridge that owns
 *        this accessory can be removed and removing the bridge will remove this accessory
 *        from the home.
 */
@property (assign, nonatomic, readonly, getter = isBridged) BOOL bridged;

/// A Boolean value indicating whether the device is Thing Inc Device.
@property (assign, nonatomic, readonly) BOOL isThingDevice;

/// Device id, only generated after the cloud binding
/// @note Invoke `readValueWithCompletionHandler:` get the latest value.
@property (nonatomic, strong, readonly) HMCharacteristic *devId;

/// Identification of equipment categories.
/// @note Invoke `readValueWithCompletionHandler:` get the latest value.
@property (strong, nonatomic, readonly) HMCharacteristic *productID;

/// Unique identification of the device.
/// @note Invoke `readValueWithCompletionHandler:` get the latest value.
@property (nonatomic, strong, readonly) HMCharacteristic *UUID;

/// Token for configuring the device to connect to the cloud.
/// @note String value. If not confige to the cloud will nil. Invoke `readValueWithCompletionHandler:` get the latest value. Invoke `writeValue:completionHandler:` to start configuring.
@property (strong, nonatomic, readonly) HMCharacteristic *token;

/// Status for configuring the device to connect to the cloud.
/// @note Int Value. 0 is device not configured, 1 is device is start configuring. Invoke `readValueWithCompletionHandler:` get the latest value.
@property (strong, nonatomic, readonly) HMCharacteristic *active;

/// The BLE device mac address.
@property (nonatomic, strong, readonly) HMCharacteristic *mac;

/// The BLE device link type value is "BLE".
@property (nonatomic, strong, readonly) HMCharacteristic *linkType;

///  The BLE Adv
@property (nonatomic, strong, readonly) HMCharacteristic *bleAdv;

/// A Boolean value indicating whether the device is Matter Device.
@property (assign, nonatomic, readonly) BOOL isMatterDevice;

/// The node identifier used to identify the device on Apple’s Matter fabric.
@property (nullable, readonly, copy, nonatomic) NSNumber *matterNodeID;

/// Accessory is passed in through the `initWithAccessory:`
@property (strong, nonatomic, readonly) HMAccessory *accessory;

/// Wrapped with `HMAccessory` object, init Tuy Inc Device characteristics
/// @param accessory A home automation accessory, like a garage door opener or a thermostat.
- (instancetype)initWithAccessory:(HMAccessory *)accessory;

/// Update all HMCharacteristic propertys.
/// @param handler All update completed.
/// @note HMCharacteristic property should update to get the latest values.
- (void)updateWithCompletionHandler:(void (^)(NSError * _Nullable error))handler;

- (BOOL)isBLELinkType;

@end

NS_ASSUME_NONNULL_END
