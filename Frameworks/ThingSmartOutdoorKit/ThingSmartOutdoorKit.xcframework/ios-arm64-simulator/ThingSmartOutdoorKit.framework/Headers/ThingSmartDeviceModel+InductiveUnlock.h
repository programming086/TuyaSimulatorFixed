
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, InductiveUnlockType) {
    InductiveUnlockTypeNone =   0,       // unsupport InductiveUnlock
    InductiveUnlockTypeBLEHID = 1 << 0,  // InductiveUnlock2.0 device ability: BLE HID
    InductiveUnlockTypeBT =     1 << 1,  // InductiveUnlock3.0 device ability: BT
};

@interface ThingSmartDeviceModel (InductiveUnlock)

/// inductive unlock type, only DP Detection
@property (nonatomic, assign, readonly) InductiveUnlockType tsod_inductiveUnlockType;

@end

NS_ASSUME_NONNULL_END
