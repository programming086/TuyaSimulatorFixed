//
//  TYEncryptWebImageOperation.h
//  TYEncryptImage
//
//  Created by Jake Hu on 2020/1/30.
//

#import "TYEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>
#import "TYEncryptImageCache.h"
#import "TYEncryptWebImageManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface TYEncryptWebImageOperation : NSOperation

@property (nonatomic, strong, readonly)           NSURLRequest      *request;  ///< The image URL request.
@property (nullable, nonatomic, strong, readonly) NSURLResponse     *response; ///< The response for request.
@property (nullable, nonatomic, strong, readonly) TYEncryptImageCache      *cache;    ///< The image cache.
@property (nonatomic, strong, readonly)           NSString          *cacheKey; ///< The image cache key.
@property (nonatomic, readonly)                   TYEncryptWebImageOptions options;   ///< The operation's option.

/**
 Whether the URL connection should consult the credential storage for authenticating
 the connection. Default is YES.
 
 @discussion This is the value that is returned in the `NSURLConnectionDelegate`
 method `-connectionShouldUseCredentialStorage:`.
 */
@property (nonatomic) BOOL shouldUseCredentialStorage;

/**
 The credential used for authentication challenges in `-connection:didReceiveAuthenticationChallenge:`.
 
 @discussion This will be overridden by any shared credentials that exist for the
 username or password of the request URL, if present.
 */
@property (nullable, nonatomic, strong) NSURLCredential *credential;

/**
 Creates and returns a new operation.
 
 You should call `start` to execute this operation, or you can add the operation
 to an operation queue.
 
 @param request    The Image request. This value should not be nil.
 @param options    A mask to specify options to use for this operation.
 @param cache      An image cache. Pass nil to avoid image cache.
 @param cacheKey   An image cache key. Pass nil to avoid image cache.
 @param progress   A block invoked in image fetch progress.
 @param completion A block invoked when image fetch finished or cancelled.
 
 @return The image request opeartion, or nil if an error occurs.
 */
- (instancetype)initWithRequest:(NSURLRequest *)request
                        options:(TYEncryptWebImageOptions)options
                          cache:(nullable TYEncryptImageCache *)cache
                       cacheKey:(nullable NSString *)cacheKey
                       progress:(nullable TYEncryptWebImageProgressBlock)progress
                     completion:(nullable TYEncryptWebImageCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
