
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSocketThreadTool : NSObject

@property (nonatomic, class, readonly) ThingSmartSocketThreadTool *sharedInstance;

- (void)dispatchOnSocketQueue:(dispatch_block_t)block async:(BOOL)async;

@end

NS_ASSUME_NONNULL_END
