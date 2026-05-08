
#import <Foundation/Foundation.h>
#import "ThingPrivacyAuthCustomConfig.h"

/** Authorization status
 *  ThingMicrophoneAuthorizationStatusUnable：Not supported or available
 *  ThingMicrophoneAuthorizationStatusNotDetermined：The user has never authorized anything before. The user will be prompted to authorize when accessing the corresponding content for the first time.
 *  ThingMicrophoneAuthorizationStatusRestricted：The application does not have relevant permissions, and the current user cannot change this permission, such as: parental control
 *  ThingMicrophoneAuthorizationStatusDenied：User rejects
 *  ThingMicrophoneAuthorizationStatusAuthorized：Authorized
 */
typedef NS_ENUM(NSInteger, ThingMicrophoneAuthorizationStatus) {
    ThingMicrophoneAuthorizationStatusUnable = -1,
    ThingMicrophoneAuthorizationStatusNotDetermined = 0,
    ThingMicrophoneAuthorizationStatusRestricted,
    ThingMicrophoneAuthorizationStatusDenied,
    ThingMicrophoneAuthorizationStatusAuthorized
};

NS_ASSUME_NONNULL_BEGIN

@protocol ThingMicrophoneAuthProtocol <NSObject>

/// Singleton
+ (instancetype)shared;

/// Check microphone permission status: only check permissions, do not actively request permissions
+ (ThingMicrophoneAuthorizationStatus)microphoneAuthorizationStatus;

/// Check microphone permission status: only check permissions, do not actively request permissions
- (ThingMicrophoneAuthorizationStatus)microphoneAuthorizationStatus;

/// Request microphone permission (trigger system pop-up window)
/// @param completionHandler completionHandler
+ (void)requestMicrophoneAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// Request microphone permission (trigger system pop-up window)
/// @param completionHandler completionHandler
- (void)requestMicrophoneAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// Request microphone permission based on source (trigger landing page)
/// @param source source
/// @param completionHandler complete callback
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingMicrophoneAuthorizationStatus status))completionHandler;

- (void)requestAuthorizationWithSource:(NSString *)source
                                config:(nullable ThingPrivacyAuthCustomConfig *)config
                     completionHandler:(void(^)(ThingMicrophoneAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
