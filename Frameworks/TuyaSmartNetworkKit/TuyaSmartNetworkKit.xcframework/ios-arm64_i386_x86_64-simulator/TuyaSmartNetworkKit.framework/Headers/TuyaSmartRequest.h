//
// TuyaSmartRequest.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#ifndef TuyaSmartRequest_h
#define TuyaSmartRequest_h

#import <TuyaSmartUtil/TuyaSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TuyaSmartRequestIntercepterInfo <NSObject>

@property (nonatomic, strong, nullable) NSString *domain;
@property (nonatomic, strong) NSString *apiName;
@property (nonatomic, strong) NSString *version;
@property (nonatomic, strong) NSString *httpMethod;
@property (nonatomic, strong, nullable) NSDictionary *postData;
@property (nonatomic, strong, nullable) NSDictionary *getData;

@property (nonatomic, copy, nullable) id(^successExtHandler)(id result);
@property (nonatomic, copy, nullable) NSError *(^failureExtHandler)(NSError *error);

@end

@protocol TuyaSmartRequestIntercepter <NSObject>

+ (id<TuyaSmartRequestIntercepterInfo>)interceptRequestWithDomain:(nullable NSString *)domain
                                                          apiName:(NSString *)apiName
                                                          version:(NSString *)version
                                                       httpMethod:(NSString *)httpMethod
                                                         postData:(nullable NSDictionary *)postData
                                                          getData:(nullable NSDictionary *)getData;

@end

@protocol TuyaSmartTokenRefreshDelegate <NSObject>

- (void)refreshWithRefreshToken:(NSString *)refreshToken success:(TYSuccessHandler)success;

@end

/// @brief TuyaSmartRequest is used for invoke Tuya Cloud API.
///
/// All of the Tuya Cloud API (atop) is made from this class.
///
/// Usually, a request need these params:
///   - API name.
///   - API version.
///   - API params (aka postData). A serializable dictionary object.
///   - Common params (aka getData). A serializable dictionary object. Optional.
///
/// And a response will be back through `success` or `failure` callback.
/// A success callback will give any kind of object, which depends on the specific API.
/// An error callback will give an error object, `error.userInfo[NSLocalizedFailureReasonErrorKey]` is for Tuya error code, `error.localizedDescription` is for detailed reasons.
///
/// @warning The `error.localizedDescription` is not recommend for display, please handle every possible error types and prepare the error messages for your own.
///
@interface TuyaSmartRequest : NSObject

+ (void)registerIntercepterClass:(Class<TuyaSmartRequestIntercepter>)cls;

+ (void)unregisterIntercepterClass:(Class<TuyaSmartRequestIntercepter>)cls;

/// config highway accessToken & refreshToken
/// @param token token
/// @param refreshToken refreshToken
+ (void)configAccessToken:(NSString *)token refreshToken:(NSString *)refreshToken;

+ (void)clearToken;

+ (NSString *)requestToken;

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
                  tokenDelegate:(id<TuyaSmartTokenRefreshDelegate>)delegate
                        success:(nullable TYSuccessID)success
                        failure:(nullable TYFailureError)failure;

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
                        success:(nullable TYSuccessID)success
                        failure:(nullable TYFailureError)failure;

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
                        success:(nullable TYSuccessID)success
                        failure:(nullable TYFailureError)failure;

/// Network request for Tuya server API.
/// @param apiName API name.
/// @param params API params.
/// @param httpMethod HTTP request method
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                    params:(nullable NSDictionary *)params
                   version:(nullable NSString *)version
                httpMethod:(NSString *)httpMethod
                   success:(nullable TYSuccessID)success
                   failure:(nullable TYFailureError)failure;

/// Network request for Tuya server API.
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
                   success:(nullable TYSuccessID)success
                   failure:(nullable TYFailureError)failure;

/// Network request for Tuya server API.
/// @param apiName API name.
/// @param postData API params.
/// @param version  API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestWithApiName:(NSString *)apiName
                  postData:(nullable NSDictionary *)postData
                   version:(NSString *)version
                   success:(nullable TYSuccessID)success
                   failure:(nullable TYFailureError)failure;


/// Network request for Tuya server API.
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
                   success:(nullable TYSuccessID)success
                   failure:(nullable TYFailureError)failure;

/// Cancel network request.
- (void)cancel;

/// Remove network cache.
+ (void)removeAllCache;

@end


@interface TuyaSmartRequest (ApiMerge)

/// Invoke multiple api in one network request.
/// @param apiName API name.
/// @param postData API params.
/// @param version API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)addMergeRequestWithApiName:(NSString *)apiName
                          postData:(nullable NSDictionary *)postData
                           version:(NSString *)version
                           success:(nullable TYSuccessID)success
                           failure:(nullable TYFailureError)failure;


/// Send multiple api request.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendMergeRequestWithSuccess:(nullable TYSuccessList)success
                            failure:(nullable TYFailureError)failure;


/// Send multiple api request.
/// @param getData Common params.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)sendMergeRequestWithGetData:(nullable NSDictionary *)getData
                            success:(nullable TYSuccessList)success
                            failure:(nullable TYFailureError)failure;


/// Remove all multiple api request.
- (void)removeAllMergeRequest;

@end

@interface TuyaSmartRequest (Encryption)

/// Network request for Tuya server API with post data encrypt.
/// @param apiName API name.
/// @param postData API params.
/// @param version API version.
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)requestPostDataEncryptWithApiName:(NSString *)apiName
                                 postData:(nullable NSDictionary *)postData
                                  version:(NSString *)version
                                  success:(nullable TYSuccessID)success
                                  failure:(nullable TYFailureError)failure;

@end

@interface TuyaSmartRequest (Speech)

- (void)requestPostDataEncryptWithApiName:(NSString *)apiName
                                parameter:(nullable NSDictionary *)param
                                voiceData:(nullable NSData *)data
                                  version:(NSString *)version
                                  success:(nullable TYSuccessID)success
                                  failure:(nullable TYFailureError)failure;

@end

NS_ASSUME_NONNULL_END

#endif /* TuyaSmartRequest_h */
