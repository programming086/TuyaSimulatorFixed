
#import "ThingEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>
#import "ThingEncryptImageDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class ThingEncryptWebImageOperation,ThingEncryptImageCache;

@interface ThingEncryptWebImageManager : NSObject

/**
 The image cache used by image operation.
 You can set it to nil to avoid image cache.
 */
@property (nullable, nonatomic, strong) ThingEncryptImageCache *cache;

/**
 The image HTTP request header. Default is "Accept:image/webp,image/\*;q=0.8".
 */
@property (nullable, nonatomic, copy) NSDictionary<NSString *, NSString *> *headers;

/*
 Whether downloading images is executed serially
 */
@property (nonatomic, assign) BOOL isSerial;

+ (instancetype)sharedManager;

/**
 Creates a manager with an image cache and operation queue.
 
 @param cache  Image cache used by manager (pass nil to avoid image cache).
 @return A new manager.
 */
- (instancetype)initWithCache:(nullable ThingEncryptImageCache *)cache queue:(NSOperationQueue *)queue;

/**
Returns the cache key for a specified URL.

@param url A specified URL
@return Cache key used in ThingEncryptImageCache.
*/

- (NSString *)cacheKeyForURL:(NSURL *)url;

/**
 The image request timeout interval in seconds. Default is 15.
 */
@property (nonatomic) NSTimeInterval timeout;

/**
 The username used by NSURLCredential, default is nil.
 */
@property (nullable, nonatomic, copy) NSString *username;

/**
 The password used by NSURLCredential, default is nil.
 */
@property (nullable, nonatomic, copy) NSString *password;

/**
 A block which will be invoked for each image HTTP request to do additional
 HTTP header process. Default is nil.
 
 Use this block to add or remove HTTP header field for a specified URL.
 */
@property (nullable, nonatomic, copy) NSDictionary<NSString *, NSString *> *(^headersFilter)(NSURL *url, NSDictionary<NSString *, NSString *> * _Nullable header);

/**
 A block which will be invoked for each image operation. Default is nil.
 
 Use this block to provide a custom image cache key for a specified URL.
 */
@property (nullable, nonatomic, copy) NSString *(^cacheKeyFilter)(NSURL *url);

/**
 Creates and returns a new image operation, the operation will start immediately.
 
 @param url        The image url (remote or local file path).
 @param progress   Progress block
 @param completion Completion block
 @return A new image operation.
 */
- (ThingEncryptWebImageOperation *)requestImageWithURL:(NSURL *)url
                                           progress:(nullable ThingEncryptWebImageProgressBlock)progress
                                         completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

/**
 Creates and returns a new image operation, the operation will start immediately.
 
 @param url        The image url (remote or local file path).
 @param options    The options to control image operation.
 @param progress   Progress block
 @param completion Completion block
 @return A new image operation.
 */
- (ThingEncryptWebImageOperation *)requestImageWithURL:(NSURL *)url
                                            options:(ThingEncryptWebImageOptions)options
                                           progress:(nullable ThingEncryptWebImageProgressBlock)progress
                                         completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

/**
 Creates and returns a new image operation, the operation will start immediately.
 
 @param url        The image url (remote or local file path).
 @param scaledWidth  The image will be scaled to the specified width, and the height will be adjusted proportionally.
 @param options    The options to control image operation.
 @param progress   Progress block
 @param completion Completion block
 @return A new image operation.
 */
- (ThingEncryptWebImageOperation *)requestImageWithURL:(NSURL *)url
                                           scaledWidth:(NSInteger)scaledWidth
                                            options:(ThingEncryptWebImageOptions)options
                                           progress:(nullable ThingEncryptWebImageProgressBlock)progress
                                         completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

/**
 * Assign list of URLs to let ThingEncryptWebImageManager to queue the prefetching.
 * Attention that call this will not cancel previous fetched urls.
 *
 * @param urls list of URLs to prefetch
 */
- (void)prefetchURLs:(nullable NSArray<NSURL *> *)urls DEPRECATED_MSG_ATTRIBUTE("Please use [[ThingEncryptWebImagePrefetcher sharedImagePrefetcher] prefetchURLs:] instead");

/**
 Clear all cached files
 */
- (void)clearAllCache;

@end

NS_ASSUME_NONNULL_END
