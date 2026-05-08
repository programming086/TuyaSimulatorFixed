
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface ThingBLECentralManager : NSObject <CBCentralManagerDelegate>

/**
 *  Specifies whether to enable Bluetooth.
 */
@property (nonatomic, assign, readonly) BOOL isPoweredOn;

- (nullable instancetype)initWithAgentKey:(nonnull NSString *)agentKey;

@property (nonatomic, strong, nonnull) NSString *agentKey;
/**
 *  The CBCentralManager object.
 */
@property (nonatomic, strong, readonly, nullable) CBCentralManager *cbManager;

- (void)thingble_performSelector:(nonnull SEL)aSelector withObject:(nullable id)anArgument afterDelay:(NSTimeInterval)delay;

- (void)thingble_cancelPreviousPerformRequestsWithTarget:(nonnull id)aTarget selector:(nonnull SEL)aSelector object:(nullable id)anArgument;

@end
