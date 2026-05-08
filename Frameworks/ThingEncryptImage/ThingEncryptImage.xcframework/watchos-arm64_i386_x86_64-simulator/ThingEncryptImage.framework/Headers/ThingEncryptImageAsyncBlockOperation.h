
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingEncryptImageAsyncBlockOperation;
typedef void (^ThingEncryptImageAsyncBlock)(ThingEncryptImageAsyncBlockOperation * __nonnull asyncOperation);

/// A async block operation, success after you call `complete` (not like `NSBlockOperation` which is for sync block, success on return)
@interface ThingEncryptImageAsyncBlockOperation : NSOperation

- (nonnull instancetype)initWithBlock:(nonnull ThingEncryptImageAsyncBlock)block;
+ (nonnull instancetype)blockOperationWithBlock:(nonnull ThingEncryptImageAsyncBlock)block;
- (void)complete;
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
