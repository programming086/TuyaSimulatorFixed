#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class ThingBLEService;

typedef void(^ThingBLECentralPeripheralDiscoverServicesCallback)(NSArray *services, NSError *error);
typedef void(^ThingBLECentralPeripheralRSSIValueCallback)(NSNumber *RSSI, NSError *error);


@interface ThingBLEPeripheral : NSObject <CBPeripheralDelegate>

/**
 *  The internal cbPeripheral object.
 */
@property (strong, atomic, readonly) CBPeripheral *cbPeripheral;
/**
 *  A list of service UUIDs.
 */
@property (strong, nonatomic, readonly) NSArray *services;
/**
 *  The UUID string of the peripheral.
 */
@property (copy, atomic, readonly) NSString *UUIDString;

/**
 * The signal strength of the peripheral.
 */
@property (assign, nonatomic) NSInteger RSSI;

/**
 * The advertisement data that was tracked from the peripheral.
 */
@property (strong, nonatomic) NSDictionary *advertisingData;

@property (nonatomic, assign) BOOL isConnectedNotOpenApp;
@property (nonatomic, assign) BOOL isModifyServices;
@property (nonatomic, assign) BOOL isSupportConnectKeep;
/**
 *  The connection flag.
 */
@property (nonatomic, assign) BOOL isConnected;
/**
 *  Specifies whether to restore the connection status of the device.
 */
@property (nonatomic, assign) BOOL isWillRestoreState;

/**
 *  Lastest scan time
 */
@property (nonatomic, assign) long long lastScanTime;

/**
 *  Creates a ThingBLEPeripheral object.
 *
 *  @param p The CBPeripheral object.
 *
 *  @return The ThingBLEPeripheral object.
 */
- (instancetype)initWithCBPeripheral:(CBPeripheral *)p;

/**
 *  Discovers all supported services.
 *
 *  @param block The callback.
 */
- (void)discoverServicesWithCompletion:(ThingBLECentralPeripheralDiscoverServicesCallback)block;

/**
 *  Discovers the service with a specific UUID.
 *
 *  @param serviceUUIDs The service UUID
 *  @param block        The callback.
 */
- (void)discoverServices:(NSArray *)serviceUUIDs
              completion:(ThingBLECentralPeripheralDiscoverServicesCallback)block;

/**
 *  Reads the Received Signal Strength Indicator (RSSI) value.
 *
 *  @param aCallback The callback.
 */
- (void)readRSSIValueCompletion:(ThingBLECentralPeripheralRSSIValueCallback)aCallback;
/**
 *  Discovers the service with a specific UUID.
 *
 *  @param uuid The UUID to be discovered.
 *
 *  @return The ThingBLEService object.
 */
- (ThingBLEService *)retrieveServiceByUUID:(NSString *)uuid;

/**
 * Update current cbPeripheral when find new service;
 */
- (void)updatecbPeripheral:(CBPeripheral *)cbPeripheral;

@property (nonatomic, copy) void(^readyToSendWriteWithoutResponseBlock)(CBPeripheral *p);
@property (nonatomic, copy) void(^didModifyServicesBlock)(CBPeripheral *p,NSArray *invalidatedServices);
@end


