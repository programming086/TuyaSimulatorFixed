
#ifndef ThingApiMergeService_h
#define ThingApiMergeService_h

#import "ThingApiMergeModel.h"
#import "ThingSmartRequest.h"

NS_ASSUME_NONNULL_BEGIN

/// @brief ThingApiMergeService is used for making several requests in one HTTP request.
///
/// This class is used for reduce the number of network requests. Use it with the following steps:
///     1. Create a ThingApiMergeService instance
///     2. Add several request by `-[ThingApiMergeService addApiRequest:postData:version:]`
///     3. SendRequests by `- [ThingApiMergeService sendRequest:success:failure]`. requests will be sent and received together.
///
/// @discussion Due to HTTP/2 multiplexing technology, it is not recommend for use now.
///
@interface ThingApiMergeService : ThingSmartRequest

@property (nonatomic, strong) ThingSDKSafeMutableArray *requestList;


/// Add api request.
/// @param apiName Api name.
/// @param postData Post data.
/// @param version Version.
- (void)addApiRequest:(NSString *)apiName postData:(NSDictionary *)postData version:(NSString *)version;


/// Send request.
/// @param getData Get data.
/// @param success Called when the task finishes successfully. A list of ThingApiMergeModel will be returned.
/// @param failure Called when the task is interrupted by an error.
- (void)sendRequest:(NSDictionary *)getData success:(nullable void (^)(NSArray <ThingApiMergeModel *> *list))success failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingApiMergeService_h */
