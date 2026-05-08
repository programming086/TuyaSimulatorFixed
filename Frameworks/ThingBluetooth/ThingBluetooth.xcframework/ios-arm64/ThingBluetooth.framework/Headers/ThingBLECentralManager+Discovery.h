
#import "ThingBLECentralManager.h"
#import "ThingBLECentralManagerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingBLECentralManager (Discovery)

/**
 The discovered devices.
 */
@property (nonatomic, strong, readonly) NSArray<ThingBLEPeripheral *> *discoveredDevices;

@property (nonatomic, assign) BOOL shouldAutoDiscoveryWhenCenteralPoweredOn;

/**
 Adds a discovery delegate.

 @param delegate The discovery delegate.
 */
- (void)addDiscoveryDelegate:(id<ThingBLECentralManagerDiscoveryDelegate>)delegate;

/**
 Removes a discovery delegate.

 @param delegate The discovery delegate.
 */
- (void)removeDiscoveryDelegate:(id<ThingBLECentralManagerDiscoveryDelegate>)delegate;

/**
 *  Discovers all Bluetooth devices.
 *
 *  @param timeout The discovery timed out.
 */
- (void)scanForPeripheralsWithServices:(nullable NSArray<CBUUID *> *)serviceUUIDs options:(nullable NSDictionary<NSString *, id> *)options timeout:(NSTimeInterval)timeout;

/**
 *  Discovers all Bluetooth devices.
 *
 *  @param timeout The discovery timed out.
 */
- (void)scanForPeripherals:(NSTimeInterval)timeout;

- (NSArray<CBPeripheral *> *)retrievePeripheralsWithIdentifiers:(NSArray<NSUUID *> *)identifiers;

/**
 *  Retrieve Connected Peripherals.
 *
 *  @param serviceUUIDs The service UUID.
 *
 *  @return The ThingBLEPeripheral array.
 */
- (NSArray<ThingBLEPeripheral *> *)retrieveConnectedPeripheralsWithServices:(NSArray<CBUUID *> *)serviceUUIDs;

/**
 *  Stops discovery.
 */
- (void)stopScan;

/**
 Clears the discovery cache.
 */
- (void)cleanScanedCache;

- (void)cleanScanedCache:(NSString *)service;

- (void)cleanScanedCacheWithServices:(NSArray<NSString *> *)services;

@end

NS_ASSUME_NONNULL_END
