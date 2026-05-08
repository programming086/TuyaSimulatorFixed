
#import <Foundation/Foundation.h>
#import "ThingActivatorFactoryProtocol.h"
NS_ASSUME_NONNULL_BEGIN

@protocol ThingActivatorStepProtocol <NSObject>

@property (nonatomic, weak) id<ThingActivatorFactoryProtocol>factory;

@property (nonatomic, strong) NSString *identifier;

@required
/// Go to current step
/// @param reset is from reset distribution process
- (void)stepIn:(BOOL)reset;

@optional
/// Exit current step
- (void)stepOut;

/// Exit the pairing process, giving the current step a chance to intercept the exit
/// Does not execute this method, defaults to exit directly
- (void)quitProcessInStep:(void(^)(BOOL canQuit))completion;
@end

NS_ASSUME_NONNULL_END
