
#import <Foundation/Foundation.h>
#import "ThingPrivacyAuthCustomConfig.h"

typedef NS_OPTIONS(NSUInteger, ThingUNAuthorizationOptions) {
    ThingUNAuthorizationOptionBadge   = (1 << 0),
    ThingUNAuthorizationOptionSound   = (1 << 1),
    ThingUNAuthorizationOptionAlert   = (1 << 2),
    ThingUNAuthorizationOptionCarPlay = (1 << 3),
    ThingUNAuthorizationOptionCriticalAlert __API_AVAILABLE(ios(12.0)) = (1 << 4),
    ThingUNAuthorizationOptionProvidesAppNotificationSettings __API_AVAILABLE(ios(12.0)) = (1 << 5),
    ThingUNAuthorizationOptionProvisional __API_AVAILABLE(ios(12.0)) = (1 << 6),
    ThingUNAuthorizationOptionAnnouncement __API_AVAILABLE(ios(13.0)) = (1 << 7),
} ;

typedef NS_ENUM(NSInteger, ThingUNAuthorizationStatus) {
    ThingUNAuthorizationStatusNotDetermined = 0,
    ThingUNAuthorizationStatusDenied,
    ThingUNAuthorizationStatusAuthorized,
    ThingUNAuthorizationStatusProvisional __API_AVAILABLE(ios(12.0)),
    ThingUNAuthorizationStatusEphemeral __API_AVAILABLE(ios(14.0))
};

NS_ASSUME_NONNULL_BEGIN

@protocol ThingNotificationsAuthProtocol <NSObject>

/// Singleton
+ (instancetype)shared;

- (ThingUNAuthorizationStatus)notificationAuthorizationStatus;

- (void)requestNotificationAuthorizationWithCompletionHandler:(void (^)(BOOL granted))completionHandler;

- (void)requestNotificationAuthorizationWithOptions:(ThingUNAuthorizationOptions)options
                                  completionHandler:(void (^)(BOOL granted))completionHandler;

+ (ThingUNAuthorizationStatus)notificationAuthorizationStatus;

/// Request notification permission based on the source (trigger system pop-up window)
/// @param completionHandler completionHandler
+ (void)requestNotificationAuthorizationWithCompletionHandler:(void (^)(BOOL granted))completionHandler;

/// Request notification permission based on the source (trigger system pop-up window)
/// @param options options
/// @param completionHandler completionHandler
+ (void)requestNotificationAuthorizationWithOptions:(ThingUNAuthorizationOptions)options
                                  completionHandler:(void (^)(BOOL granted))completionHandler;

/// Request notification permissions based on the source (trigger landing page)
/// @param source source
/// @param completionHandler completionHandler
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingUNAuthorizationStatus status))completionHandler;

- (void)requestAuthorizationWithSource:(NSString *)source
                                config:(nullable ThingPrivacyAuthCustomConfig *)config
                     completionHandler:(void(^)(ThingUNAuthorizationStatus status))completionHandler;

/// Request notification permissions based on the source (trigger landing page)
/// @param source source
/// @param options options
/// @param completionHandler completionHandler
- (void)requestAuthorizationWithSource:(NSString *)source
                               options:(ThingUNAuthorizationOptions)options
                     completionHandler:(void(^)(ThingUNAuthorizationStatus status))completionHandler;

- (void)requestAuthorizationWithSource:(NSString *)source
                               options:(ThingUNAuthorizationOptions)options
                                config:(nullable ThingPrivacyAuthCustomConfig *)config
                     completionHandler:(void(^)(ThingUNAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
