
#ifndef ThingDeviceSyncPlugAPI_h
#define ThingDeviceSyncPlugAPI_h

NS_ASSUME_NONNULL_BEGIN

@protocol ThingDeviceSyncProtocol <NSObject>

#pragma  mark - dual control association
/**
 Whether the device supports dual control association

 @param devId The devId of the master device.
 */
- (BOOL)isDeviceSupportDoubleControlWithDevId:(NSString *)devId;

/**
 Jump to the dual-control associated device centre

 @param devId The devId of the master device.
 */
- (void)gotoDeviceSyncListViewControllerWithDevId:(NSString *)devId;

#pragma  mark - Multiple control association
/**
 Whether the device supports multi-control association

 @param devId The devId of the master device.
 */
- (BOOL)isDeviceSupportMultiControlWithDevId:(NSString *)devId;

/**
 Jump to the Multi-Control Associated Device Centre

 @param devId The devId of the device.
 */
- (void)gotoDeviceBindViewControllerWithDevId:(NSString *)devId;
   
#pragma  mark - Synchronised control of device
/**
 Whether the device supports device synchronisation control

 @param devId devId of the master device
 */
- (BOOL)isDeviceSupportSyncControlWithDevId:(NSString *)devId;

/**
 Jump to device synchronisation control

 @param devId The devId of the device.
 */
- (void)gotoDeviceSyncControControllerWithDevId:(NSString *)devId;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingDeviceSyncPlugAPI_h */
