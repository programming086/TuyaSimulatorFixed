
#import <Foundation/Foundation.h>
#import "ThingPrivacyAuthCustomConfig.h"

/** Authorization status
 *  ThingContactAuthorizationStatusUnable：Not supported or available
 *  ThingContactAuthorizationStatusNotDetermined：The user has never authorized anything before. The user will be prompted to authorize when accessing the address book for the first time.
 *  ThingContactAuthorizationStatusRestricted：The application does not have relevant permissions, and the current user cannot change this permission, such as: parental control
 *  ThingContactAuthorizationStatusDenied：User rejects
 *  ThingContactAuthorizationStatusAuthorized：Authorized
 */
typedef NS_ENUM(NSInteger, ThingContactAuthorizationStatus) {
    ThingContactAuthorizationStatusUnable = -1,
    ThingContactAuthorizationStatusNotDetermined = 0,
    ThingContactAuthorizationStatusRestricted,
    ThingContactAuthorizationStatusDenied,
    ThingContactAuthorizationStatusAuthorized
};

NS_ASSUME_NONNULL_BEGIN

@protocol ThingContactAuthProtocol <NSObject>

/// Singleton
+ (instancetype)shared;

/// Check the address book permission status: only check the permission, do not actively request permission
+ (ThingContactAuthorizationStatus)contactAuthorizationStatus;

/// Check the address book permission status: only check the permission, do not actively request permission
- (ThingContactAuthorizationStatus)contactAuthorizationStatus;

/// Request address book permission (trigger system pop-up window)
/// @param completionHandler completionHandler
+ (void)requestContactAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// Request address book permission (trigger system pop-up window)
/// @param completionHandler completionHandler
- (void)requestContactAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// Request address book permissions based on source (trigger landing page)
/// @param source source
/// @param completionHandler completionHandler
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingContactAuthorizationStatus status))completionHandler;

- (void)requestAuthorizationWithSource:(NSString *)source
                                config:(nullable ThingPrivacyAuthCustomConfig *)config
                     completionHandler:(void(^)(ThingContactAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
