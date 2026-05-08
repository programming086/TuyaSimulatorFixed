
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    ThingSmartLocalNetworkStateUnsupport,
    ThingSmartLocalNetworkStateAuthorized,
    ThingSmartLocalNetworkStateDenied,
} ThingSmartLocalNetworkState;

@interface ThingSmartLocalNetworkAuther : NSObject

/// Trigger local network Alert
extern void triggerLocalNetworkPrivacyAlertObjC(void);

/// Check local network permissions
/// - Parameter handler: handler
+ (void)checkLocalNetWorkPermissionWithHandler:(void(^)(ThingSmartLocalNetworkState state))handler;

@end

NS_ASSUME_NONNULL_END
