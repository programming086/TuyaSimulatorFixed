//
//  TYBLECentralManager.h
//  TuyaSmartPublic
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

@interface TYBLECentralManager : NSObject <CBCentralManagerDelegate>

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

- (void)tyble_performSelector:(nonnull SEL)aSelector withObject:(nullable id)anArgument afterDelay:(NSTimeInterval)delay;

- (void)tyble_cancelPreviousPerformRequestsWithTarget:(nonnull id)aTarget selector:(nonnull SEL)aSelector object:(nullable id)anArgument;

@end
