
#import <Foundation/Foundation.h>

// HID Unlock
/// automatic lock
FOUNDATION_EXTERN NSString * const dpod_auto_lock;
/// automatic unlock
FOUNDATION_EXPORT NSString * const dpod_auto_unlock;
/// armed distance record - bool
FOUNDATION_EXTERN NSString * const dpod_fortify_distance_record;
/// disarm distance record - bool
FOUNDATION_EXTERN NSString * const dpod_disarm_distance_record;
///  HID binding, an enumeration type (Enum) with the enumeration values: bind, unbind.
FOUNDATION_EXTERN NSString * const dpod_hid_bind;
// BT Unlock
/// Seamless Unlock 3.0 device pairing status (character 1 + 2 + 28)
FOUNDATION_EXPORT NSString * const dpod_induction_bind_status;
/// Is Seamless Unlock 3.0 pairing enabled?
FOUNDATION_EXPORT NSString * const dpod_induction_broadcast;
/// Remove corresponding paired device for Seamless Unlock 3.0
FOUNDATION_EXPORT NSString * const dpod_induction_delete;

@interface ThingODUnlockDPConstants : NSObject

@end




