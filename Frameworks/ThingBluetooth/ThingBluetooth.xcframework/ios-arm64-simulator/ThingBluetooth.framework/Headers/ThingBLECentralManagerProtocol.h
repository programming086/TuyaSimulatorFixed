
#ifndef ThingBLECentralManagerProtocol_h
#define ThingBLECentralManagerProtocol_h

#import <CoreBluetooth/CoreBluetooth.h>

typedef NS_ENUM(NSInteger, ThingBLECentralManagerState) {
//    ThingBLECentralManagerStateUnknown = 0,
//    ThingBLECentralManagerStateResetting,
//    ThingBLECentralManagerStateUnsupported,
    ThingBLECentralManagerStateUnauthorized = 3, // The Bluetooth permissions are not granted.
    ThingBLECentralManagerStatePoweredOff, // The Bluetooth function is disabled.
    ThingBLECentralManagerStatePoweredOn, // The Bluetooth function is enabled.
};

@class ThingBLECentralManager;
@class ThingBLEPeripheral;
@protocol ThingBLECentralManagerDiscoveryDelegate <NSObject>

@property (nonatomic, copy, readonly) BOOL(^scanFilter)(NSDictionary *advertisementData, NSNumber *rssi);

- (void)centralManager:(ThingBLECentralManager *)central didUpdateState:(BOOL)isPoweredOn;

- (void)centralManager:(ThingBLECentralManager *)central didUpdateCentralState:(ThingBLECentralManagerState)state;

- (void)centralManager:(ThingBLECentralManager *)central didDiscoverPeripheral:(ThingBLEPeripheral *)peripheral advertisementData:(NSDictionary *)advertisementData RSSI:(NSNumber *)RSSI;

- (void)centralManager:(ThingBLECentralManager *)central didModifyPeripheral:(ThingBLEPeripheral *)peripheral didModifyServices:(NSArray *)invalidatedServices;
@end

@protocol ThingBLECentralManagerSessionDelegate <NSObject>

- (void)centralManager:(ThingBLECentralManager *)central didConnectPeripheral:(ThingBLEPeripheral *)peripheral;
- (void)centralManager:(ThingBLECentralManager *)central didDisconnectPeripheral:(ThingBLEPeripheral *)peripheral error:(NSError *)error;
- (void)centralManager:(ThingBLECentralManager *)central didFailToConnectPeripheral:(ThingBLEPeripheral *)peripheral error:(NSError *)error;

@end

#endif /* ThingBLECentralManagerProtocol_h */
