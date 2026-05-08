
#ifndef ThingSmartHomeKitConfigProtocol_h
#define ThingSmartHomeKitConfigProtocol_h

@class ThingSmartHomeKitDevice;
@class ThingSmartDeviceModel;

@protocol ThingSmartHomeKitConfigProtocol <NSObject>


/// Configure devices to connect to the cloud.
/// @param device should not nil, device should be reachable and is Thing Inc device.
/// @param timeout typically 90-120 seconds
/// @param homeId ID of `ThingSmartHomeModel`
/// @param success device is online
/// @param failure there may be multiple reasons for failure
/// @note If want access to HomeKit, must have privacy permission first, can invoke `[ThingSmartHomeKitUtil checkHomeKitPermissionWithCompletionHandler]` to detect permission.
- (void)startConfigDevice:(ThingSmartHomeKitDevice *)device
                   bleAdv:(NSData *)bleAdv
                  timeout:(NSTimeInterval)timeout
                   homeId:(long long)homeId
                  success:(void (^)(ThingSmartDeviceModel *deviceModel))success
                  failure:(void (^)(NSError *error))failure;

/// Stop configuring device to cloud.
- (void)stopConfigDevice;

@optional

/// configout bleDeice is pairable
/// @parm bleAdv advertisingData
- (BOOL)isBLEDevicePairable:(NSData *)advertisingData;

@end

#endif /* ThingSmartHomeKitConfigProtocol_h */
