
#import "ThingSmartRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartRequest (TokenRefresh)

/// Custom Token Refresh
/// @param customDomain customDomain
/// @param apiName API name.
/// @param params  API params.
/// @param commonParams Common params.
/// @param httpMethod httpMethod
/// @param success success
/// @param failure failure
- (void)customTokenRefreshWithDomain:(nullable NSString *)customDomain
                             apiName:(NSString *)apiName
                              params:(nullable NSDictionary *)params
                        commonParams:(nullable NSDictionary *)commonParams
                          httpMethod:(NSString *)httpMethod
                             success:(nullable ThingSuccessID)success
                             failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
