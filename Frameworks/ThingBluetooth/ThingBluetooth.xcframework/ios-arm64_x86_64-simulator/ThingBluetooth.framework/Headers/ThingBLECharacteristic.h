
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>



typedef void (^ThingBLECentralCharacteristicReadCallback)  (NSData*data, NSError *error);
typedef void (^ThingBLECentralCharacteristicNotifyCallback)(NSData* data, NSError *error);
typedef void (^ThingBLECentralCharacteristicWriteCallback) (NSError *error);




@interface ThingBLECharacteristic : NSObject

/**
 * The CBCharacteristic object.
 */
@property (strong, nonatomic, readonly) CBCharacteristic *cbCharacteristic;

/**
 * The UUID string.
 */
@property (weak, nonatomic, readonly) NSString *UUIDString;

/**
 *  The characteristic value.
 */
@property (nonatomic, assign) CBCharacteristicProperties properties;

@property (nonatomic, copy  ) ThingBLECentralCharacteristicNotifyCallback notifyCallback;
@property (nonatomic, copy  ) ThingBLECentralCharacteristicReadCallback readCallback;
@property (nonatomic, copy  ) ThingBLECentralCharacteristicWriteCallback writeCallback;

/**
 *  Creates a ThingBLECharacteristic object.
 *
 *  @param aCharacteristic The CBCharacteristic object.
 *
 *  @return The ThingBLECharacteristic object.
 */
- (instancetype)initWithCharacteristic:(CBCharacteristic *)aCharacteristic;


/**
 *  Notifies the peripheral to push data to the central manager.
 *
 *  @param notifyValue The switch flag.
 *  @param aCallback   The callback.
 */
- (void)notifyValue:(BOOL)notifyValue
     Withcompletion:(ThingBLECentralCharacteristicNotifyCallback)aCallback;

/// Custom notifies the peripheral to push data to the central manager.
/// @param notifyValue The switch flag.
/// @param aCallback The callback.
- (void)customNotifyValue:(BOOL)notifyValue
           withcompletion:(ThingBLECentralCharacteristicNotifyCallback)aCallback;

/**
 *  Writes to the peripheral.
 *
 *  @param data      The binary streams to be written.
 *  @param aCallback The callback.
 */
- (void)writeData:(NSData *)data
   Withcompletion:(ThingBLECentralCharacteristicWriteCallback)aCallback;

/**
 *  Writes bytes to the peripheral.
 *
 *  @param aByte     The bytes to be written.
 *  @param aCallback The callback.
 */
- (void)writeByte:(int8_t)aByte
   Withcompletion:(ThingBLECentralCharacteristicWriteCallback)aCallback;

/**
 *  Reads from the peripheral.
 *
 *  @param aCallback The callback.
 */
- (void)readValueWithBlock:(ThingBLECentralCharacteristicReadCallback)aCallback;


@end

@interface ThingBLECharacteristic(ToolMethods)

// ----- Used for input events -----/

- (void)handleSetNotified:(NSData*)data WithError:(NSError *)anError;

- (void)handleReadValue:(NSData *)aValue error:(NSError *)anError;

- (void)handleWrittenValueWithError:(NSError *)anError;

- (void)handleNotfiyStateUpdate:(NSError *)anError;

@end



