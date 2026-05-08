
#ifndef ThingSmartRequest_h
#define ThingSmartRequest_h

#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN
@class ThingApiMergeModel;

@protocol ThingSmartRequestIntercepterInfo <NSObject>

@property (nonatomic, strong, nullable) NSString *domain;
@property (nonatomic, strong) NSString *apiName;
@property (nonatomic, strong) NSString *version;
@property (nonatomic, strong) NSString *httpMethod;
@property (nonatomic, strong, nullable) NSDictionary *postData;
@property (nonatomic, strong, nullable) NSDictionary *getData;
@property (nonatomic, strong, nullable) NSDictionary *headerData;
@property (nonatomic, strong, nullable) NSDictionary *extCommonData;

@property (nonatomic, copy, nullable) id(^successExtHandler)(id result);
@property (nonatomic, copy, nullable) NSError *(^failureExtHandler)(NSError *error);

@end

@protocol ThingSmartRequestIntercepter <NSObject>
@optional
+ (id<ThingSmartRequestIntercepterInfo>)interceptRequestWithDomain:(nullable NSString *)domain
                                                           apiName:(NSString *)apiName
                                                           version:(NSString *)version
                                                        httpMethod:(NSString *)httpMethod
                                                        headerData:(NSDictionary *)headerData
                                                          postData:(nullable NSDictionary *)postData
                                                           getData:(nullable NSDictionary *)getData;

+ (id<ThingSmartRequestIntercepterInfo>)interceptRequestWithDomain:(nullable NSString *)domain
                                                           apiName:(NSString *)apiName
                                                           version:(NSString *)version
                                                        httpMethod:(NSString *)httpMethod
                                                          postData:(nullable NSDictionary *)postData
                                                           getData:(nullable NSDictionary *)getData;

+ (void)interceptApiMergeServiceResponse:(NSArray<ThingApiMergeModel *> *)responseList;
@end

@protocol ThingSmartTokenRefreshDelegate <NSObject>

- (void)refreshWithRefreshToken:(NSString *)refreshToken success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

@end

/// @brief ThingSmartRequest is used for invoke Thing Cloud API.
///
/// All of the Thing Cloud API (atop) is made from this class.
///
/// Usually, a request need these params:
///   - API name.
///   - API version.
///   - API params (aka postData). A serializable dictionary object.
///   - Common params (aka getData). A serializable dictionary object. Optional.
///
/// And a response will be back through `success` or `failure` callback.
/// A success callback will give any kind of object, which depends on the specific API.
/// An error callback will give an error object, `error.userInfo[NSLocalizedFailureReasonErrorKey]` is for Thing error code, `error.localizedDescription` is for detailed reasons.
///
/// @warning The `error.localizedDescription` is not recommend for display, please handle every possible error types and prepare the error messages for your own.
///
@interface ThingSmartRequest : NSObject

+ (void)registerIntercepterClass:(Class<ThingSmartRequestIntercepter>)cls;

+ (void)unregisterIntercepterClass:(Class<ThingSmartRequestIntercepter>)cls;

/// config highway accessToken & refreshToken
/// @param token token
/// @param refreshToken refreshToken
+ (void)configAccessToken:(NSString *)token refreshToken:(NSString *)refreshToken;

+ (void)clearToken;

+ (NSString *)requestToken;

- (void)highwayRequestWithDomain:(nullable NSString *)domain
                        pathName:(NSString *)pathName
                    headerParams:(nullable NSDictionary *)headerParams
                     queryParams:(nullable NSDictionary *)queryParams
                      bodyParams:(nullable NSDictionary *)bodyParams
                      httpMethod:(NSString *)httpMethod
                         success:(nullable ThingSuccessID)success
                         failure:(nullable ThingFailureError)failure;

/// request Api
/// @param customDomain customDomain
/// @param apiName API name.
/// @param params  API params.
/// @param commonParams Common params.
/// @param httpMethod httpMethod
/// @param delegate token invalid delegate
/// @param success success
/// @param failure failure
- (void)requestWithCustomDomain:(nullable NSString *)customDomain
                        apiName:(NSString *)apiName
                         params:(nullable NSDictionary *)params
                   commonParams:(nullable NSDictionary *)commonParams
                     httpMethod:(NSString *)httpMethod
                  tokenDelegate:(id<ThingSmartTokenRefreshDelegate>)delegate
                        success:(nullable ThingSuccessID)success
                        failure:(nullable ThingFailureError)failure;


/// request Api
/// @param customDomain customDomain
/// @param apiName API name.
/// @param params  API params.
/// @param version  API version.
/// @param httpMethod httpMethod
/// @param success success
/// @param failure failure
- (void)requestWithCustomDomain:(NSString *)customDomain
                        apiName:(NSString *)apiName
                         params:(nullable NSDictionary *)params
                        version:(nullable NSString *)version
                     httpMethod:(NSString *)httpMethod
                        success:(nullable ThingSuccessID)success
                        failure:(nullable ThingFailureError)failure;

/// request Api
/// @param customDomain customDomain
/// @param apiName API name.
/// @param params  API params.
/// @param commonParams Common params.
/// @param version  API version.
/// @param httpMethod httpMethod
/// @param success success
/// @param failure failure
- (void)requestWithCustomDomain:(NSString *)customDomain
                        apiName:(NSString *)apiName
                         params:(nullable NSDictionary *)params
                   commonParams:(NSDictionary *)commonParams
                        version:(nullable NSString *)version
                     httpMethod:(NSString *)httpMethod
                        success:(nullable ThingSuccessID)success
                        failure:(nullable ThingFailureError)failure;

/// Network request for Thing server API.
/// @param apiName API name.
/// @param params API params.
/// @param httpMethod HTTP request method
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                    params:(nullable NSDictionary *)params
                   version:(nullable NSString *)version
                httpMethod:(NSString *)httpMethod
                   success:(nullable ThingSuccessID)success
                   failure:(nullable ThingFailureError)failure;

/// Network request for Thing server API.
/// @param apiName API name.
/// @param params API params.
/// @param commonParams Common params.
/// @param httpMethod HTTP request method
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                    params:(nullable NSDictionary *)params
              commonParams:(nullable NSDictionary *)commonParams
                httpMethod:(NSString *)httpMethod
                   success:(nullable ThingSuccessID)success
                   failure:(nullable ThingFailureError)failure;

/// Network request for Thing server API.
/// @param apiName API name.
/// @param postData API params.
/// @param version  API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                  postData:(nullable NSDictionary *)postData
                   version:(NSString *)version
                   success:(nullable ThingSuccessID)success
                   failure:(nullable ThingFailureError)failure;

/// Network request for Thing server API.
/// @param apiName API name.
/// @param headerData header params.
/// @param postData API params.
/// @param getData Common params.
/// @param version API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                headerData:(nullable NSDictionary *)headerData
                  postData:(nullable NSDictionary *)postData
                   getData:(nullable NSDictionary *)getData
                   version:(NSString *)version
                   success:(nullable ThingSuccessID)success
                   failure:(nullable ThingFailureError)failure;

/// Network request for Thing server API.
/// @param apiName API name.
/// @param postData API params.
/// @param getData Common params.
/// @param version API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                  postData:(nullable NSDictionary *)postData
                   getData:(nullable NSDictionary *)getData
                   version:(NSString *)version
                   success:(nullable ThingSuccessID)success
                   failure:(nullable ThingFailureError)failure;

/// Cancel network request.
- (void)cancel;

/// Remove network cache.
+ (void)removeAllCache;

@end


@interface ThingSmartRequest (ApiMerge)

/// Invoke multiple api in one network request.
/// @param apiName API name.
/// @param postData API params.
/// @param version API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addMergeRequestWithApiName:(NSString *)apiName
                          postData:(nullable NSDictionary *)postData
                           version:(NSString *)version
                           success:(nullable ThingSuccessID)success
                           failure:(nullable ThingFailureError)failure;


/// Send multiple api request.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendMergeRequestWithSuccess:(nullable ThingSuccessList)success
                            failure:(nullable ThingFailureError)failure;


/// Send multiple api request.
/// @param getData Common params.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendMergeRequestWithGetData:(nullable NSDictionary *)getData
                            success:(nullable ThingSuccessList)success
                            failure:(nullable ThingFailureError)failure;


/// Remove all multiple api request.
- (void)removeAllMergeRequest;

@end

@interface ThingSmartRequest (Encryption)

/// Network request for Thing server API with post data encrypt.
/// @param apiName API name.
/// @param postData API params.
/// @param version API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestPostDataEncryptWithApiName:(NSString *)apiName
                                 postData:(nullable NSDictionary *)postData
                                  version:(NSString *)version
                                  success:(nullable ThingSuccessID)success
                                  failure:(nullable ThingFailureError)failure;

@end

@interface ThingSmartRequest (Speech)

- (void)requestPostDataEncryptWithApiName:(NSString *)apiName
                                parameter:(nullable NSDictionary *)param
                                voiceData:(nullable NSData *)data
                                  version:(NSString *)version
                                  success:(nullable ThingSuccessID)success
                                  failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingSmartRequest_h */
