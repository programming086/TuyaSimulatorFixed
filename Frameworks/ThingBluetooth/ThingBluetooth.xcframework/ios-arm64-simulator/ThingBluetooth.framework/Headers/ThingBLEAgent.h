
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@class ThingBLECentralManager;
@class ThingBLEPeripheral;

typedef void(^ThingBLEAgentCentralNotifyCallback)(NSData *data, NSError *error);
typedef void(^ThingBLEAgentCentralReadCallback)(NSData *data, NSError *error);
typedef void(^ThingBLEAgentCentralWriteCallback)(NSError *error);
typedef void(^ThingBLEAgentCentralDiscoverCallback)(ThingBLEPeripheral *peripheral, NSError *error);
typedef void(^ThingBLEAgentCentralConnectionCallback)(ThingBLEPeripheral *peripheral, NSError *error) ;

typedef NS_ENUM(int, ThingBLEAgentRole)
{
    kThingBLEAgentDiscovery    = 0x01, // Discovers devices.
    kThingBLEAgentSession      = 0x10, // Communicates with devices.
    kThingBLEAgentBoth         = 0x11, // Discovers and communicates with devices.
};


@protocol ThingBLEAgent <NSObject>

@optional

- (void)onCentralDidDisconnecteFromPeripheral:(ThingBLEPeripheral *)peripheral;
- (void)onCentralDidDisconnectFromPeripheral:(ThingBLEPeripheral *)peripheral error:(NSError *)error;
- (void)onCentralDidUpdateState:(BOOL)isPoweredOn;
- (void)onBLECentralDidUpdateState:(ThingBLECentralManagerState)state;
- (void)onModifyPeripheral:(ThingBLEPeripheral *)peripheral didModifyServices:(NSArray *)invalidatedServices;

@end


@interface ThingBLEAgent : NSObject

@property (nonatomic, assign, readonly) ThingBLEAgentRole role;

@property (nonatomic, copy, readonly) BOOL(^scanFilter)(NSDictionary *advertisementData, NSNumber *rssi);

/**
 *  Specifies whether to enable Bluetooth.
 */
@property (nonatomic, assign, readonly) BOOL isPoweredOn;

/**
 Adds a delegate.
 
 @param delegate The delegate.
 */
- (void)addDelegate:(id<ThingBLEAgent>)delegate;

/**
 Removes a delegate.
 
 @param delegate The delegate.
 */
- (void)removeDelegate:(id<ThingBLEAgent>)delegate;

@property (nonatomic, assign, readonly) BOOL scanerRunning;


//- (instancetype)initWithType:(ThingBLEAgentRole)role;

////////////////////////////////////////////////////////////////////////////////////
#pragma mark - central  methods

/**
 Discovers Bluetooth devices.

 @param services The UUIDs of services.
 @param options The discovery parameters. 
 @param scanFilter The filtering criteria for discovery.
 @param aCallback The callback of discovered devices that meet the filtering criteria.
 */
- (void)discoverServiceUUID:(NSArray<NSString *> *)services
                    options:(NSDictionary<NSString *,id> *)options
                 scanFilter:(BOOL(^)(NSDictionary *advertisementData, NSNumber *rssi))scanFilter
                 completion:(ThingBLEAgentCentralDiscoverCallback)aCallback;


/**
 Discovers Bluetooth devices.

 @param scanFilter The filtering criteria for discovery.
 @param aCallback The callback of discovered devices that meet the filtering criteria.
 */
- (void)discoverWithScanFilter:(BOOL(^)(NSDictionary *advertisementData, NSNumber *rssi))scanFilter
                    completion:(ThingBLEAgentCentralDiscoverCallback)aCallback;

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
- (void)stopDiscovering;

/**
 *  Connects to a discovered Bluetooth device.
 *
 *  @param peripheral      The Bluetooth device to be connected.
 *  @param aCharacteristic The characteristic UUID.
 *  @param aService        The service UUID.
 *  @param aCallback       The callback.
 */
- (void)connectPeripheral:(ThingBLEPeripheral *)peripheral
              CharactUUID:(NSString *)aCharacteristic
              serviceUUID:(NSString *)aService
               completion:(ThingBLEAgentCentralConnectionCallback)aCallback;

/**
 *  Connects to a discovered Bluetooth device.
 *
 *  @param peripheral      The Bluetooth device to be connected.
 *  @param aCharacteristic The characteristic UUID.
 *  @param aService        The service UUID.
 *  @param timeout         The connection timed out.
 *  @param aCallback       The callback.
 */
- (void)connectPeripheral:(ThingBLEPeripheral *)peripheral
              CharactUUID:(NSString *)aCharacteristic
              serviceUUID:(NSString *)aService
                  timeout:(NSTimeInterval)timeout
               completion:(ThingBLEAgentCentralConnectionCallback)aCallback;

/**
 *  Disconnects from a Bluetooth device.
 *
 *  @param peripheral The connected Bluetooth device.
 */
- (void)disconnectPeripheral:(ThingBLEPeripheral *)peripheral;

/**
 Disconnects from a Bluetooth device.

 @param peripheral The connected Bluetooth device.
 @param timeout The disconnection timed out.
 */
- (void)disconnectPeripheral:(ThingBLEPeripheral *)peripheral timeout:(NSTimeInterval)timeout;

/**
 Disconnects from a Bluetooth device.

 @param peripheral The connected Bluetooth device.
 @param aCallback The callback.
 */
- (void)disconnectPeripheral:(ThingBLEPeripheral *)peripheral
                  completion:(ThingBLEAgentCentralConnectionCallback)aCallback
                     timeout:(NSTimeInterval)timeout;

/**
 *  Writes to a Bluetooth device.
 *
 *  @param aData           The binary data to be written.
 *  @param aPeripheral     The Bluetooth device to which data is written.
 *  @param aCharacteristic The characteristic UUID.
 *  @param aService        The service UUID.
 *  @param aCallback       The callback.
 */
- (void)writeData:(NSData *)aData
     toPeripheral:(ThingBLEPeripheral *)aPeripheral
      charactUUID:(NSString *)aCharacteristic
      serviceUUID:(NSString *)aService
       completion:(ThingBLEAgentCentralWriteCallback)aCallback;

/**
 *  Reads from a Bluetooth device.
 *
 *  @param aPeripheral     The Bluetooth device from which data is read.
 *  @param aCharacteristic The characteristic UUID.
 *  @param aService        The service UUID.
 *  @param aCallback       The callback.
 */
- (void)readDataFromPeriphreral:(ThingBLEPeripheral *)aPeripheral
                    CharactUUID:(NSString *)aCharacteristic
                    serviceUUID:(NSString *)aService
                     completion:(ThingBLEAgentCentralReadCallback)aCallback;

/**
 *  Receives data that is pushed by the Bluetooth device.
 *
 *  @param b               The switch that enables or disables data transfers.
 *  @param aPeripheral     The connected Bluetooth device.
 *  @param aCharacteristic The characteristic UUID.
 *  @param aService        The service UUID.
 *  @param aCallback       The callback.
 */
- (void)notifyData:(BOOL)b
     FromPeriphral:(ThingBLEPeripheral *)aPeripheral
       CharactUUID:(NSString *)aCharacteristic
       serviceUUID:(NSString *)aService
        completion:(ThingBLEAgentCentralNotifyCallback)aCallback;

/// Receives data from custom notify channel that is pushed by the Bluetooth device.
/// @param b The switch that enables or disables data transfers.
/// @param aPeripheral The connected Bluetooth device.
/// @param aCharacteristic The characteristic UUID.
/// @param aService The service UUID.
/// @param aCallback The callback.
- (void)customNotifyData:(BOOL)b fromPeriphral:(ThingBLEPeripheral *)aPeripheral CharactUUID:(NSString *)aCharacteristic serviceUUID:(NSString *)aService completion:(ThingBLEAgentCentralNotifyCallback)aCallback;



/**
 Clears the discovery cache.
 */
- (void)cleanScanedCache:(NSString *)service;


- (void)cleanScanedCacheWithServices:(NSArray<NSString *> *)services;

@end
