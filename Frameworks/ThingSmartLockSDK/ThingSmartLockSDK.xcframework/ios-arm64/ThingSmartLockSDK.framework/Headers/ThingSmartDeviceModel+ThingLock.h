//
//  ThingSmartDeviceModel+ThingLock.h
//  ThingSmartLockSDK
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDeviceModel (ThingLock)

@property (nonatomic, assign, readonly) BOOL isBLEProLock;

- (BOOL)isZigbeeLockDps:(NSDictionary *)dps;

- (BOOL)isZigbeeLockOpenedWithDps:(NSDictionary *)dps;

- (ThingSmartSchemaModel *)schemaByDpCode:(NSString *)dpCode;


@end

NS_ASSUME_NONNULL_END
