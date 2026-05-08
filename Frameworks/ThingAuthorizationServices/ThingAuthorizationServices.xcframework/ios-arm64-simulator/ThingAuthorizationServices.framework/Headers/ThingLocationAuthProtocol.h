
#import <Foundation/Foundation.h>
#import "ThingPrivacyAuthCustomConfig.h"

/** Locate authorization status
 *
 *  ThingLocationAuthorizationStatusUnable：Not supported or available
 *  ThingLocationAuthorizationStatusNotDetermined：The user has never authorized anything before. The user will be prompted to authorize when accessing the corresponding content for the first time.
 *  ThingLocationAuthorizationStatusRestricted：The application does not have relevant permissions, and the current user cannot change this permission, such as: parental control
 *  ThingLocationAuthorizationStatusDenied：User rejects
 *  ThingLocationAuthorizationStatusAuthorizedAlways：Always allow location access
 *  ThingLocationAuthorizationStatusAuthorizedWhenInUse：Allow positioning when in use
*/
typedef NS_ENUM(NSInteger, ThingLocationAuthorizationStatus) {
    ThingLocationAuthorizationStatusUnable = -1,
    ThingLocationAuthorizationStatusNotDetermined = 0,
    ThingLocationAuthorizationStatusRestricted,
    ThingLocationAuthorizationStatusDenied,
    ThingLocationAuthorizationStatusAuthorizedAlways,
    ThingLocationAuthorizationStatusAuthorizedWhenInUse,
};

NS_ASSUME_NONNULL_BEGIN

/// Notification after the user authorizes the pop-up window operation in the APP location
/// userInfo["status"] = `ThingLocationAuthorizationStatus`
extern NSString *const ThingLocationAuthenticatedNotification;

@protocol ThingLocationAuthProtocol <NSObject>

/// Singleton
+ (instancetype)shared;

/// positioning status available
+ (BOOL)available;

/// Check location permission status: only check permissions, do not actively request permissions
+ (ThingLocationAuthorizationStatus)locationAuthorizationStatus;

/// Check location permission status: only check permissions, do not actively request permissions
- (ThingLocationAuthorizationStatus)locationAuthorizationStatus;

/// Request location permission (trigger system pop-up window)
/// @param completionHandler completionHandler
+ (void)requestLocationAuthorizationWithCompletionHandler:(void(^)(ThingLocationAuthorizationStatus status))completionHandler;

/// Request location permission (trigger system pop-up window)
/// @param completionHandler completionHandler
- (void)requestLocationAuthorizationWithCompletionHandler:(void(^)(ThingLocationAuthorizationStatus status))completionHandler;

/// Request location permissions based on source (trigger landing page)
/// @param source source
/// @param completionHandler completionHandler
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingLocationAuthorizationStatus status))completionHandler;

/// Request location permissions based on source (trigger landing page)
/// @param source source
/// @param config config
/// @param completionHandler completionHandler
- (void)requestAuthorizationWithSource:(NSString *)source
                                config:(nullable ThingPrivacyAuthCustomConfig *)config
                     completionHandler:(void(^)(ThingLocationAuthorizationStatus status))completionHandler;


@end

NS_ASSUME_NONNULL_END
