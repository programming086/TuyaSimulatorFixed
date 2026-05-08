
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingLockUnlockType) {
    ThingLockUnlockTypeFingerprint, // Fingerprint Unlock
    ThingLockUnlockTypePassword,    // Password Unlock
    ThingLockUnlockTypeTemporary,   // Temporary Password Unlock
    ThingLockUnlockTypeDynamic,     // Dynamic Password Unlock
    ThingLockUnlockTypeCard,        // Card Unlock
    ThingLockUnlockTypeFace,        // Facial Recognition Unlock
    ThingLockUnlockTypeKey,         // Key Unlock
    ThingLockUnlockTypeFingerVein,  // Finger Vein Unlock
    ThingLockUnlockTypeHand,        // Palm Print Unlock
    ThingLockUnlockTypeEye,         // Iris Unlock
    ThingLockUnlockTypeRemote,      // App Remote Unlock
};

@interface ThingSmartLockRelationModel : NSObject

@property (nonatomic, assign) ThingLockUnlockType unlockType; // Unlock Method
@property (nonatomic, assign) NSInteger sn; // Associated Password Number, range 0 - 999

@end

NS_ASSUME_NONNULL_END
