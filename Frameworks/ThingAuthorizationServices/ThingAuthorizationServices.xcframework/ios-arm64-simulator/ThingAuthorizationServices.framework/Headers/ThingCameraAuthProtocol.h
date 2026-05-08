
#import <Foundation/Foundation.h>
#import "ThingPrivacyAuthCustomConfig.h"

/** 授权状态
 *  ThingCameraAuthorizationStatusUnable：不支持或不可用
 *  ThingCameraAuthorizationStatusNotDetermined：用户从未进行过授权等处理，首次访问相应内容会提示用户进行授权
 *  ThingCameraAuthorizationStatusRestricted：应用没有相关权限，且当前用户无法改变这个权限，比如:家长控制
 *  ThingCameraAuthorizationStatusDenied：用户拒绝
 *  ThingCameraAuthorizationStatusAuthorized：已授权
 */
typedef NS_ENUM(NSInteger, ThingCameraAuthorizationStatus) {
    ThingCameraAuthorizationStatusUnable = -1,
    ThingCameraAuthorizationStatusNotDetermined = 0,
    ThingCameraAuthorizationStatusRestricted,
    ThingCameraAuthorizationStatusDenied,
    ThingCameraAuthorizationStatusAuthorized
};

NS_ASSUME_NONNULL_BEGIN

@protocol ThingCameraAuthProtocol <NSObject>

/// Singleton
+ (instancetype)shared;

/// Check camera permission status: only check permissions, do not actively request permissions
+ (ThingCameraAuthorizationStatus)cameraAuthorizationStatus;

/// Check camera permission status: only check permissions, do not actively request permissions
- (ThingCameraAuthorizationStatus)cameraAuthorizationStatus;

/// Request camera permission (trigger system pop-up window)
/// @param completionHandler completionHandler
+ (void)requestCameraAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// Request camera permission (trigger system pop-up window)
/// @param completionHandler completionHandler
- (void)requestCameraAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

/// Request camera permissions based on source (trigger landing page)
/// @param source source
/// @param completionHandler complete callback
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingCameraAuthorizationStatus status))completionHandler;

- (void)requestAuthorizationWithSource:(NSString *)source
                                config:(nullable ThingPrivacyAuthCustomConfig *)config
                     completionHandler:(void(^)(ThingCameraAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
