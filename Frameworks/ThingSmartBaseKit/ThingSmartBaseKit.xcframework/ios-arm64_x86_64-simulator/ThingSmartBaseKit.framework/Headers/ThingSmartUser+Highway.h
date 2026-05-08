
#import "ThingSmartUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartUser (Highway)

/// Get highway gateway access token
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)requestHighwayTokenWithSuccess:(ThingSuccessID)success
                               failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
