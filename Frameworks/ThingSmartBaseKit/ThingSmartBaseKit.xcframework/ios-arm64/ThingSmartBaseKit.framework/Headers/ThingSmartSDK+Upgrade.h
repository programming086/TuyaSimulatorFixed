
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSDK (Upgrade)

/// Check if ThingSmartKit need to be upgrade to ThingSmartHomeKit.
/// @return Whether need to upgrade data.
- (BOOL)checkVersionUpgrade;


/// SDK data upgrade.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)upgradeVersion:(nullable ThingSuccessHandler)success
               failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
