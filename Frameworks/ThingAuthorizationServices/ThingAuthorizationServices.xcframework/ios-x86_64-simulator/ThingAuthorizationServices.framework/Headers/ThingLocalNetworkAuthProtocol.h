
#import <Foundation/Foundation.h>
#import "ThingPrivacyAuthCustomConfig.h"

typedef NS_ENUM(NSInteger, ThingLocalNetworkAuthorizationStatus) {
    
    // not yet made a choice
    ThingLocalNetworkAuthorizationStatusNotDetermined,
    
    // Local network not connected (Wi-Fi adapter can't get IP address)
    ThingLocalNetworkAuthorizationStatusNotConnected,
    
    // User has explicitly denied authorization for this application
    ThingLocalNetworkAuthorizationStatusDenied,
    
    // User has granted authorization to use their local network only while they are using your app.
    ThingLocalNetworkAuthorizationStatusAuthorized,
};

NS_ASSUME_NONNULL_BEGIN

@protocol ThingLocalNetworkAuthProtocol <NSObject>

/// Singleton
+ (instancetype)shared;

+ (ThingLocalNetworkAuthorizationStatus)localNetworkAuthorizationStatus;

- (ThingLocalNetworkAuthorizationStatus)localNetworkAuthorizationStatus;

/**
    Returns the current authorization status of the calling application (beta).
 */
+ (void)getLocalNetworkAuthorizationStatusWithCompletionHandler:(void (^)(ThingLocalNetworkAuthorizationStatus status))completionHandler;

- (void)getLocalNetworkAuthorizationStatusWithCompletionHandler:(void (^)(ThingLocalNetworkAuthorizationStatus status))completionHandler;

/**
    Request "Local Network" authorization (beta)
 
    When Wi-Fi is connected, calling this method will start the process of requesting "Local Network" authorization from the user. The authorization prompt will only appear once until App uninstalled.
    Currently we can't get authorization change callback for this request.
 */

/// Request local network permissions based on the source (trigger system pop-up window)
+ (void)requestLocalNetworkAuthorization;

/// Request local network permissions based on the source (trigger system pop-up window)
- (void)requestLocalNetworkAuthorization;
- (void)requestLocalNetworkAuthorizationWithCompletionHandler:(void(^)(ThingLocalNetworkAuthorizationStatus status))completionHandler;

/// Request local network permissions based on the source (trigger landing page)
/// @param source source
/// @param completionHandler completionHandler
- (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingLocalNetworkAuthorizationStatus status))completionHandler;

- (void)requestAuthorizationWithSource:(NSString *)source
                                config:(nullable ThingPrivacyAuthCustomConfig *)config
                     completionHandler:(void(^)(ThingLocalNetworkAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
