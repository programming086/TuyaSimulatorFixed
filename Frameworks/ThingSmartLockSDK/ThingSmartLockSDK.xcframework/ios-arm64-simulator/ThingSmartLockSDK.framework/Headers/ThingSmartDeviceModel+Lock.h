//
//  ThingSmartDeviceModel+Lock.h
//  Thin/Users/lingchen/Documents/Tuya/Modules/SDK/ThingSmartLockSDK/ThingSmartLockSDK/Classes/Public/ThingLockFingerprintModel.hgSmartLockSDK
//
//  Copyright (c) 2014-2024 Thing Inc. (https://developer.tuya.com/)
//

#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>


typedef NS_ENUM(NSUInteger, ThingLockReverseLockState) {
    ThingLockReverseLockNoneState = 0,
    ThingLockReverseLockOpendedState,
    ThingLockReverseLockClosedState,
};


typedef NS_ENUM(NSUInteger, ThingLockDoorState) {
    ThingLockDoorUnknownState = 0,
    ThingLockDoorOpenedState,
    ThingLockDoorClosedState,
};

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDeviceModel (Lock)

/// Whether the lock has been unlocked
@property (nonatomic, assign, readonly) BOOL isUnlocked;


/// Whether the lock is automatic lock
@property (nonatomic, assign, readonly) BOOL isAutomaticLock;


/// Whether automatic locking is supported
@property (nonatomic, assign, readonly) BOOL isSupportAutomaticLock;


/// Whether manual lock is supported
@property (nonatomic, assign, readonly) BOOL isSupportManualLock;


/// Reverse Llock state
@property (nonatomic, assign, readonly) ThingLockReverseLockState reverseLockState;


/// Door state
@property (nonatomic, assign, readonly) ThingLockDoorState doorState;


@end

NS_ASSUME_NONNULL_END
