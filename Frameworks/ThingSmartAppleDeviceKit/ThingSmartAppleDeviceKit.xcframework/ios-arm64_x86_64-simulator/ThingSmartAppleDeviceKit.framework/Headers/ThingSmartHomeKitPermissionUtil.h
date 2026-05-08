
#import <Foundation/Foundation.h>
#import <HomeKit/HomeKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^ThingSmartHomeKitPermissionCompletionHandler)(BOOL granted, HMHomeManager * _Nullable manager);

@interface ThingSmartHomeKitPermissionUtil : NSObject

/// Whether you have access to HomeKit privacy.
/// @param completionHandler Check results.
- (void)checkHomeKitPermissionWithCompletionHandler:(ThingSmartHomeKitPermissionCompletionHandler)completionHandler;

@end

NS_ASSUME_NONNULL_END
