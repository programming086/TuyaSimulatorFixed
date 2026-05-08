
#import <Foundation/Foundation.h>
#import "ThingBLECentralManager.h"
#import "ThingBLECentralManagerProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingBLEPeripheral;
@interface ThingBLECentralManager (Connection)

/**
 Adds a connection delegate.

 @param delegate The delegate.
 */
- (void)addConnectionDelegate:(id<ThingBLECentralManagerSessionDelegate>)delegate;

/**
 Removes a connection delegate.

 @param delegate The delegate.
 */
- (void)removeConnectionDelegate:(id<ThingBLECentralManagerSessionDelegate>)delegate;

/**
 *  Connects to a peripheral.
 *
 *  @param peripheral The peripheral to be connected.
 *  @param timeout The connection timed out.
 */
- (void)connectPeripheral:(ThingBLEPeripheral *)peripheral timeout:(NSTimeInterval)timeout;

/**
 Connects to a peripheral.

 @param peripheral The peripheral to be connected.
 @param options The connection parameters.
 @param timeout The connection timed out.
 */
- (void)connectPeripheral:(ThingBLEPeripheral *)peripheral options:(nullable NSDictionary<NSString *, id> *)options timeout:(NSTimeInterval)timeout;

/**
 Disconnects from a peripheral.
 
 @param peripheral The connected peripheral.
 @param timeout The disconnection timed out.
 */
- (void)disconnectPeripheral:(ThingBLEPeripheral *)peripheral timeout:(NSTimeInterval)timeout;

/**
 *  Disconnects from all peripherals.
 */
- (void)disconnectAllPeripherals;

- (void)cancelConnectionTimer:(ThingBLEPeripheral *)peripheral;

@end

NS_ASSUME_NONNULL_END
