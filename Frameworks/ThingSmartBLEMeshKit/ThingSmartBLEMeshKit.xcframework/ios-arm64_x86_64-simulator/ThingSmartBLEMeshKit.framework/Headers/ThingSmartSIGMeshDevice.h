
NS_ASSUME_NONNULL_BEGIN

/// @brief The Bluetooth mesh device supports the operation class of Thing Bluetooth devices.
///
/// This API is integrated with the basic smart device class and provides certain basic capabilities of the device method.
///
@interface ThingSmartSIGMeshDevice : ThingSmartDevice

+ (BOOL)canHandleSigmeshMessage:(ThingSmartDeviceModel *)model;

@end

NS_ASSUME_NONNULL_END
