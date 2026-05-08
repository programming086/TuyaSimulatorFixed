//
//  TYEncryptWebImagePrefetch.h
//  TYEncryptImage
//
//  Created by TuyaInc on 2021/4/19.
//

#import <Foundation/Foundation.h>
#import "TYEncryptWebImageManager.h"
#import "TYEncryptImageDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class TYEncryptWebImagePrefetcher;

@interface TYEncryptWebImagePrefetchToken : NSObject

/**
 * Cancel the current prefetching.
 */
- (void)cancel;

/**
 list of URLs of current prefetching.
 */
@property (nonatomic, copy, readonly, nullable) NSArray<NSURL *> *urls;

@end



@protocol TYEncryptWebImagePrefetcherDelegate <NSObject>

@optional


/**
 * Called when an image was prefetched. Which means it's called when one URL from any of prefetching finished.
 *
 * @param imagePrefetcher The current image prefetcher
 * @param imageURL        The image url that was prefetched
 * @param finishedCount   The total number of images that were prefetched (successful or not)
 * @param totalCount      The total number of images that were to be prefetched
 */
- (void)encryptImagePrefetcher:(nonnull TYEncryptWebImagePrefetcher *)imagePrefetcher didPrefetchURL:(nullable NSURL *)imageURL finishedCount:(NSUInteger)finishedCount totalCount:(NSUInteger)totalCount;

/**
 * Called when all images are prefetched. Which means it's called when all URLs from all of prefetching finished.
 * @param imagePrefetcher The current image prefetcher
 * @param totalCount      The total number of images that were prefetched (whether successful or not)
 * @param skippedCount    The total number of images that were skipped
 */
- (void)encryptImagePrefetcher:(nonnull TYEncryptWebImagePrefetcher *)imagePrefetcher didFinishWithTotalCount:(NSUInteger)totalCount skippedCount:(NSUInteger)skippedCount;

@end

typedef void(^TYEncryptImagePrefetcherProgressBlock)(NSUInteger noOfFinishedUrls, NSUInteger noOfTotalUrls);
typedef void(^TYEncryptPrefetcherCompletionBlock)(NSUInteger noOfFinishedUrls, NSUInteger noOfSkippedUrls);

@interface TYEncryptWebImagePrefetcher : NSObject

/**
 * The web image manager used by prefetcher to prefetch images.
 * @note You can specify a standalone manager with custom configuration suitable for image prefetching.
 */
@property (strong, nonatomic, readonly, nonnull) TYEncryptWebImageManager *manager;

/**
 * Maximum number of URLs to prefetch at the same time. Defaults to 3.
 */
@property (nonatomic, assign) NSUInteger maxConcurrentPrefetchCount;

/**
 * Queue options for prefetcher when call the progressBlock, completionBlock and delegate methods. Defaults to Main Queue.
 * @note The call is asynchronously to avoid blocking target queue.
 * @note The delegate queue should be set before any prefetching start and may not be changed during prefetching to avoid thread-safe problem.
 */
@property (strong, nonatomic, nonnull) dispatch_queue_t delegateQueue;

/**
 * The delegate for the prefetcher. Defaults to nil.
 */
@property (weak, nonatomic, nullable) id <TYEncryptWebImagePrefetcherDelegate> delegate;

/**
 * Returns the global shared image prefetcher instance. It use a standalone manager which is different from shared manager.
 */
@property (nonatomic, class, readonly, nonnull) TYEncryptWebImagePrefetcher *sharedImagePrefetcher;

/**
 * Allows you to instantiate a prefetcher with any arbitrary image manager.
 */
- (nonnull instancetype)initWithImageManager:(nonnull TYEncryptWebImageManager *)manager NS_DESIGNATED_INITIALIZER;

/**
 * Assign list of URLs to let TYEncryptWebImagePrefetcher to queue the prefetching. It based on the image manager so the image may from the cache and network according to the `options` property.
 * Prefetching is separate to each other, which means the progressBlock and completionBlock you provide is bind to the prefetching for the list of urls.
 * Attention that call this will not cancel previous fetched urls. You should keep the token return by this to cancel or cancel all the prefetch.
 *
 * @param urls list of URLs to prefetch
 * @return the token to cancel the current prefetching.
 */
- (nullable TYEncryptWebImagePrefetchToken *)prefetchURLs:(nullable NSArray<NSURL *> *)urls;

/**
 * Assign list of URLs to let TYEncryptWebImagePrefetcher to queue the prefetching. It based on the image manager so the image may from the cache and network according to the `options` property.
 * Prefetching is separate to each other, which means the progressBlock and completionBlock you provide is bind to the prefetching for the list of urls.
 * Attention that call this will not cancel previous fetched urls. You should keep the token return by this to cancel or cancel all the prefetch.
 *
 * @param urls            list of URLs to prefetch
 * @param progressBlock   block to be called when progress updates;
 *                        first parameter is the number of completed (successful or not) requests,
 *                        second parameter is the total number of images originally requested to be prefetched
 * @param completionBlock block to be called when the current prefetching is completed
 *                        first param is the number of completed (successful or not) requests,
 *                        second parameter is the number of skipped requests
 * @return the token to cancel the current prefetching.
 */
- (nullable TYEncryptWebImagePrefetchToken *)prefetchURLs:(nullable NSArray<NSURL *> *)urls
                                          progress:(nullable TYEncryptImagePrefetcherProgressBlock)progressBlock
                                         completed:(nullable TYEncryptPrefetcherCompletionBlock)completionBlock;

/**
 * Remove and cancel all the prefeching for the prefetcher.
 */
- (void)cancelPrefetching;


@end

NS_ASSUME_NONNULL_END
