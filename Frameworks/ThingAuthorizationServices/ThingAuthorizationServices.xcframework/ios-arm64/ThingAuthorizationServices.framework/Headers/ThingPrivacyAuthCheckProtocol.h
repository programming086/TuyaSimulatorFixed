
#import <Foundation/Foundation.h>
#import "ThingPrivacyAuthConfig.h"

@protocol ThingPrivacyAuthCheckProtocol <NSObject>

/// Singleton
+ (instancetype)shared;

/// Permission request downgrade scheme, controlled by configuration center fields https://wiki.thing-inc.com:7799/page/1466253746303418386
@property (atomic, copy) BOOL(^isRestorePermissionRequestAction)(void);

/// Privacy permission verification
/// @param config Permission configuration
/// @param completionBlock Verification completion callback (may be triggered multiple times)
- (void)checkWithAuthConfig:(ThingPrivacyAuthConfig *)config
            completionBlock:(ThingPrivacyAuthCheckCompletionBlock)completionBlock;

- (void)dismiss;

@end
