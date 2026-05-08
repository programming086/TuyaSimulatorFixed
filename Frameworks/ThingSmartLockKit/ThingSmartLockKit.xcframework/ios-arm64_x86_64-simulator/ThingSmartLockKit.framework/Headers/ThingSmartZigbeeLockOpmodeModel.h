
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
// Unlocking Method
typedef enum : NSInteger {
    ThingRemotePermissionType_NonePwd_Admin = 0, // No Password - Admin
    ThingRemotePermissionType_NonePwd_All = 1, // No Password - All Users
    ThingRemotePermissionType_Pwd_Admin = 2, // With Password - Admin
    ThingRemotePermissionType_Pwd_All = 3, // With Password - All Users
} ThingRemotePermissionType;

@interface ThingSmartZigbeeLockOpmodeModel : NSObject

@property (nonatomic, strong) NSString *unlockId; // Unlock method ID
@property (nonatomic, assign) NSUInteger unlockAttr; // Unlock method attribute: 1 - Hijack, 0 - Non-Hijack
@property (nonatomic, strong) NSString *opmodeId; // Unlock method cloud serial number
@property (nonatomic, strong) NSString *uid;
@property (nonatomic, assign) NSUInteger sourceAttribute;
@property (nonatomic, assign) NSInteger channelId;
@property (nonatomic, assign) NSInteger allocateFlag;
@property (nonatomic, strong) NSString *unlockName; // Unlock method name
@property (nonatomic, assign) NSInteger photoUnlock;
@property (nonatomic, assign) NSInteger voiceAttr;
@property (nonatomic, assign) NSInteger phase; // 1 - Pending Creation, 2 - Normal, 3 - Frozen, 4 - Deleted, 5 - Creation Failed
@property (nonatomic, assign) NSUInteger userType;
@property (nonatomic, strong) NSString *userName; // Associated user nickname
@property (nonatomic, strong) NSString *userId; // Associated user ID
@property (nonatomic, strong) NSString *userTimeSet;
@property (nonatomic, strong) NSString *opmodeValue; // Unlock method device-side ID, equivalent to SN
@property (nonatomic, assign) long long lockUserId; // Lock member ID
@property (nonatomic, strong) NSString *opmode; // Unlock method: 1 - Fingerprint, 2 - Password, 3 - Access Card

@end

NS_ASSUME_NONNULL_END
