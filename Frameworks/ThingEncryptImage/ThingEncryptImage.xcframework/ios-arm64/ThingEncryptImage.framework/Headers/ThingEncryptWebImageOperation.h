
#import "ThingEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>
#import "ThingEncryptImageCache.h"
#import "ThingEncryptWebImageManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingEncryptWebImageOperation : NSOperation

@property (nonatomic, strong, readonly)           NSURLRequest      *request;  ///< The image URL request.
@property (nullable, nonatomic, strong, readonly) NSURLResponse     *response; ///< The response for request.
@property (nullable, nonatomic, strong, readonly) ThingEncryptImageCache      *cache;    ///< The image cache.
@property (nonatomic, strong, readonly)           NSString          *cacheKey; ///< The image cache key.
@property (nonatomic, readonly)                   ThingEncryptWebImageOptions options;   ///< The operation's option.

/**
 Whether the URL connection should consult the credential storage for authenticating
 the connection. Default is YES.
 
 @discussion This is the value that is returned in the `NSURLConnectionDelegate`
 method `-connectionShouldUseCredentialStorage:`.
 */
@property (nonatomic) BOOL shouldUseCredentialStorage;


@property (nonatomic, assign) BOOL shouldCancelRequestWhenDealloc;

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
 @param scaledWidth  The image will be scaled to the specified width, and the height will be adjusted proportionally.
 @param progress   A block invoked in image fetch progress.
 @param completion A block invoked when image fetch finished or cancelled.
 
 @return The image request opeartion, or nil if an error occurs.
 */
- (instancetype)initWithRequest:(NSURLRequest *)request
                        options:(ThingEncryptWebImageOptions)options
                          cache:(nullable ThingEncryptImageCache *)cache
                       cacheKey:(nullable NSString *)cacheKey
                    scaledWidth:(NSInteger)scaledWidth
                       progress:(nullable ThingEncryptWebImageProgressBlock)progress
                     completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
