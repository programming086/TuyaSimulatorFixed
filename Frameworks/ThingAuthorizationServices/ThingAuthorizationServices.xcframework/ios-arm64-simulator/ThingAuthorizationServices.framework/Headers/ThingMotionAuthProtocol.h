    

#import <Foundation/Foundation.h>
#import "ThingPrivacyAuthCustomConfig.h"

/** Authorization status
 *  ThingMotionAuthorizationStatusUnable：Not supported or available
 *  ThingMotionAuthorizationStatusNotDetermined：The user has never authorized anything before. The user will be prompted to authorize when accessing sports and fitness content for the first time.
 *  ThingMotionAuthorizationStatusRestricted：The application does not have relevant permissions, and the current user cannot change this permission, such as: parental control
 *  ThingMotionAuthorizationStatusDenied：User rejects
 *  ThingMotionAuthorizationStatusAuthorized：Authorized
 */
typedef NS_ENUM(NSInteger, ThingMotionAuthorizationStatus) {
    ThingMotionAuthorizationStatusUnable = -1,
    ThingMotionAuthorizationStatusNotDetermined = 0,
    ThingMotionAuthorizationStatusRestricted,
    ThingMotionAuthorizationStatusDenied,
    ThingMotionAuthorizationStatusAuthorized
};

//CMAuthorizationStatusNotDetermined = 0,
//CMAuthorizationStatusRestricted,
//CMAuthorizationStatusDenied,
//CMAuthorizationStatusAuthorized

NS_ASSUME_NONNULL_BEGIN

@protocol ThingMotionAuthProtocol <NSObject>

/// Singleton
+ (instancetype)shared;

/// Check the status of sports and fitness permissions: only check permissions, do not actively request permissions
+ (ThingMotionAuthorizationStatus)motionAuthorizationStatus;

/// Check the status of sports and fitness permissions: only check permissions, do not actively request permissions
- (ThingMotionAuthorizationStatus)motionAuthorizationStatus;

/// Request sports and fitness permissions (trigger system pop-up window)
/// @param completionHandler completionHandler
+ (void)requestMotionAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// Request sports and fitness permissions (trigger system pop-up window)
/// @param completionHandler completionHandler
- (void)requestMotionAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// Request sports and fitness permissions based on the source (trigger landing page)
/// @param source source
/// @param completionHandler complete callback
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingMotionAuthorizationStatus status))completionHandler;

- (void)requestAuthorizationWithSource:(NSString *)source
                                config:(nullable ThingPrivacyAuthCustomConfig *)config
                     completionHandler:(void(^)(ThingMotionAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
