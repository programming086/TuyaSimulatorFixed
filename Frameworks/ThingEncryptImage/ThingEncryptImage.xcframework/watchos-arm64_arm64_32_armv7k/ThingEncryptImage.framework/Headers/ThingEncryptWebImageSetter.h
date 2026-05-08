
#import "ThingEncryptWebImageCompat.h"
#import <Foundation/Foundation.h>
#import <pthread.h>

#import "ThingEncryptWebImageManager.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Submits a block for execution on a main queue and waits until the block completes.
 */
static inline void _thing_dispatch_sync_on_main_queue(void (^block)(void)) {
    if (pthread_main_np()) {
        block();
    } else {
        dispatch_sync(dispatch_get_main_queue(), block);
    }
}

/**
 Private class used by web image categories.
 Thingpically, you should not use this class directly.
 */
@interface ThingEncryptWebImageSetter : NSObject
/// Current image url.
@property (nullable, nonatomic, readonly) NSURL *imageURL;
/// Current sentinel.
@property (nonatomic, readonly) int32_t sentinel;

@property (nonatomic, assign) BOOL shouldCancelRequestWhenDealloc;

/// Create new operation for web image and return a sentinel value.
- (int32_t)setOperationWithSentinel:(int32_t)sentinel
                                url:(nullable NSURL *)imageURL
                        scaledWidth:(NSInteger)scaledWidth
                            options:(ThingEncryptWebImageOptions)options
                            manager:(ThingEncryptWebImageManager *)manager
                           progress:(nullable ThingEncryptWebImageProgressBlock)progress
                         completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

/// Cancel and return a sentinel value. The imageURL will be set to nil.
- (int32_t)cancel;

/// Cancel and return a sentinel value. The imageURL will be set to new value.
- (int32_t)cancelWithNewURL:(nullable NSURL *)imageURL;

/// A queue to set operation.
+ (dispatch_queue_t)setterQueue;

/// Create new operation for web image, use for download manage
- (void)setOperationWithUrl:(nullable NSURL *)imageURL
                    options:(ThingEncryptWebImageOptions)options
                    manager:(ThingEncryptWebImageManager *)manager
                   progress:(nullable ThingEncryptWebImageProgressBlock)progress
                 completion:(nullable ThingEncryptWebImageCompletionBlock)completion;

@end

NS_ASSUME_NONNULL_END
