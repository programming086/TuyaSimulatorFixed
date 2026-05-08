
#import <Foundation/Foundation.h>
#import "ThingMiniAppExtApiProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingMiniAppDevelopProtocol <NSObject>

/// ext api implementation
/// - Parameter impl: impl instance
- (void)addExtApiImpl:(id<ThingMiniAppExtApiProtocol>)impl;

@end

NS_ASSUME_NONNULL_END
