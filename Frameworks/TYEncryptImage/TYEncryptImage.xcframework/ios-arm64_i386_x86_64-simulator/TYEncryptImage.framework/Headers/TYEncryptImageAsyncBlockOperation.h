//
//  TYEncryptImageAsyncBlockOperation.h
//  TYEncryptImage
//
//  Created by Jake Hu on 2021/4/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class TYEncryptImageAsyncBlockOperation;
typedef void (^TYEncryptImageAsyncBlock)(TYEncryptImageAsyncBlockOperation * __nonnull asyncOperation);

/// A async block operation, success after you call `complete` (not like `NSBlockOperation` which is for sync block, success on return)
@interface TYEncryptImageAsyncBlockOperation : NSOperation

- (nonnull instancetype)initWithBlock:(nonnull TYEncryptImageAsyncBlock)block;
+ (nonnull instancetype)blockOperationWithBlock:(nonnull TYEncryptImageAsyncBlock)block;
- (void)complete;
- (void)cancel;

@end

NS_ASSUME_NONNULL_END
