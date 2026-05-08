
#import <Foundation/Foundation.h>
#import "ThingPrivacyAuthCustomConfig.h"

/** Authorization status
 *  ThingPhotosAuthorizationStatusUnable：Not supported or available
 *  ThingPhotosAuthorizationStatusNotDetermined：The user has never authorized anything before. The user will be prompted to authorize when accessing the corresponding content for the first time.
 *  ThingPhotosAuthorizationStatusRestricted：The application does not have relevant permissions, and the current user cannot change this permission, such as: parental control
 *  ThingPhotosAuthorizationStatusDenied：User rejects
 *  ThingPhotosAuthorizationStatusAuthorized：Authorized
 */
typedef NS_ENUM(NSInteger, ThingPhotosAuthorizationStatus) {
    ThingPhotosAuthorizationStatusUnable = -1,
    ThingPhotosAuthorizationStatusNotDetermined = 0,
    ThingPhotosAuthorizationStatusRestricted,
    ThingPhotosAuthorizationStatusDenied,
    ThingPhotosAuthorizationStatusLimited,
    ThingPhotosAuthorizationStatusAuthorized
};

typedef NS_ENUM(NSInteger, ThingPHAccessLevel) {
    ThingPHAccessLevelAddOnly = 1,
    ThingPHAccessLevelReadWrite = 2,
};



NS_ASSUME_NONNULL_BEGIN

@protocol ThingPhotosAuthProtocol <NSObject>

/// Singleton
+ (instancetype)shared;

/// Get the album permission status: only check the permission, do not actively request permission
+ (ThingPhotosAuthorizationStatus)photosAuthorizationStatusForAccessLevel:(ThingPHAccessLevel)accessLevel;
- (ThingPhotosAuthorizationStatus)photosAuthorizationStatusForAccessLevel:(ThingPHAccessLevel)accessLevel;

/// Request photo album permission (trigger system pop-up window)
+ (void)requestPhotosAuthorization:(ThingPHAccessLevel)accessLevel
                 completionHandler:(void(^)(BOOL granted))completionHandler;

- (void)requestPhotosAuthorization:(ThingPHAccessLevel)accessLevel
                 completionHandler:(void(^)(BOOL granted))completionHandler;

/// Request photo album permission (trigger system pop-up window)
+ (void)requestPhotosAuthorization:(ThingPHAccessLevel)accessLevel
              completionWithStatus:(void(^)(ThingPhotosAuthorizationStatus status))completion;

- (void)requestPhotosAuthorization:(ThingPHAccessLevel)accessLevel
              completionWithStatus:(void(^)(ThingPhotosAuthorizationStatus status))completion;

/// Request album permissions based on source (trigger landing page）
/// @param source source
/// @param accessLevel accessLevel
/// @param completionHandler completionHandler
+ (void)requestAuthorizationWithSource:(NSString *)source
                           accessLevel:(ThingPHAccessLevel)accessLevel
                     completionHandler:(void(^)(ThingPhotosAuthorizationStatus status))completionHandler;

- (void)requestAuthorizationWithSource:(NSString *)source
                           accessLevel:(ThingPHAccessLevel)accessLevel
                     completionHandler:(void(^)(ThingPhotosAuthorizationStatus status))completionHandler;

- (void)requestAuthorizationWithSource:(NSString *)source
                           accessLevel:(ThingPHAccessLevel)accessLevel
                                config:(nullable ThingPrivacyAuthCustomConfig *)config
                     completionHandler:(void(^)(ThingPhotosAuthorizationStatus status))completionHandler;

#pragma mark - deprecated

/// Check album permission status: only check permissions, do not actively request permissions
///
/// Note: This interface does not return the ThingPhotosAuthorizationStatusLimited status. Please use the interface with accessLevel message.
+ (ThingPhotosAuthorizationStatus)photosAuthorizationStatus __deprecated_msg("This method is deprecated, Use -photosAuthorizationStatusForAccessLevel: instead");

/// Check album permission status: only check permissions, do not actively request permissions
///
/// Note: This interface does not return the ThingPhotosAuthorizationStatusLimited status. Please use the interface with accessLevel message.
- (ThingPhotosAuthorizationStatus)photosAuthorizationStatus __deprecated_msg("This method is deprecated, Use +photosAuthorizationStatusForAccessLevel: instead");

/// Request photo album permission (trigger system pop-up window)
/// @param completionHandler completionHandler
///
/// Note: This interface does not return the ThingPhotosAuthorizationStatusLimited status. Please use the interface with accessLevel message.
+ (void)requestPhotosAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler __deprecated_msg("This method is deprecated, Use -requestPhotosAuthorization:completionHandler: instead");

/// Request photo album permission (trigger system pop-up window)
/// @param completionHandler completionHandler
///
/// Note: This interface does not return the ThingPhotosAuthorizationStatusLimited status. Please use the interface with accessLevel message.
- (void)requestPhotosAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler  __deprecated_msg("This method is deprecated, Use +requestPhotosAuthorization:completionHandler: instead");

/// Request album permissions based on source (trigger landing page)
/// @param source source
/// @param completionHandler completionHandler
///
/// Note: This interface does not return the ThingPhotosAuthorizationStatusLimited status. Please use the interface with accessLevel message.
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingPhotosAuthorizationStatus status))completionHandler __deprecated_msg("This method is deprecated, Use -requestAuthorizationWithSource:accessLevel:completionHandler: instead");


/// Request album permissions based on source (trigger landing page)
/// @param source source
/// @param completionHandler completionHandler
///
/// Note: This interface does not return the ThingPhotosAuthorizationStatusLimited status. Please use the interface with accessLevel message.
+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingPhotosAuthorizationStatus status))completionHandler __deprecated_msg("This method is deprecated, Use +requestAuthorizationWithSource:accessLevel:completionHandler: instead");



@end

NS_ASSUME_NONNULL_END
