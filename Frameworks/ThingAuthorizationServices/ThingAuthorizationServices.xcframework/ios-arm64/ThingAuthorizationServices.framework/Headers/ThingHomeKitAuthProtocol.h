
#import <Foundation/Foundation.h>
#import "ThingPrivacyAuthCustomConfig.h"

typedef NS_OPTIONS(NSUInteger, ThingHMHomeManagerAuthorizationStatus) {
    ThingHMHomeManagerAuthorizationStatusNotDetermined,
    ThingHMHomeManagerAuthorizationStatusDenied,
    ThingHMHomeManagerAuthorizationStatusAuthorized,
} ;

/// granted:bool
/// manager:HMHomeManager
typedef void(^ThingHomeAccessCompletionHandler)(BOOL granted);

NS_ASSUME_NONNULL_BEGIN

@protocol ThingHomeKitAuthProtocol <NSObject>

/// Singleton
+ (instancetype)shared;

+ (void)getHomeAuthorizationStatusWithCompletionHandler:(void(^)(ThingHMHomeManagerAuthorizationStatus status))completionHandler;

- (void)getHomeAuthorizationStatusWithCompletionHandler:(void(^)(ThingHMHomeManagerAuthorizationStatus status))completionHandler;

+ (ThingHMHomeManagerAuthorizationStatus)homeManagerAuthorizationStatus;

- (ThingHMHomeManagerAuthorizationStatus)homeManagerAuthorizationStatus;

/// Request family permissions (trigger system pop-up window)
/// @param completionHandler completionHandler
+ (void)requestHomeAccessWithCompletionHandler:(ThingHomeAccessCompletionHandler)completionHandler;

/// Request family permissions (trigger system pop-up window)
/// @param completionHandler completionHandler
- (void)requestHomeAccessWithCompletionHandler:(ThingHomeAccessCompletionHandler)completionHandler;

/// Request family data permissions based on the source (trigger landing page)
/// @param source source
/// @param completionHandler  complete callback
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingHMHomeManagerAuthorizationStatus status))completionHandler;

- (void)requestAuthorizationWithSource:(NSString *)source
                                config:(nullable ThingPrivacyAuthCustomConfig *)config
                     completionHandler:(void(^)(ThingHMHomeManagerAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
