
#import <Foundation/Foundation.h>
#import "ThingMiniAppExtApiContext.h"
#import "ThingMiniAppExtApiModelProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingMiniAppExtApiProtocol <NSObject>

@required
/// apiName
- (NSString *)apiName;

@optional
/// api can use in environment
- (BOOL)canIUseExtApi;

/// async api invoke
/// - Parameters:
///   - context: api context
///   - params: api params
///   - success: success callback
///   - fail: fail callback
- (void)invokeExtApi:(nonnull id<ThingMiniAppExtApiContext>)context
              params:(nullable NSDictionary *)params
             success:(nonnull ThingMiniExtApiResponseCallback)success
                fail:(nonnull ThingMiniExtApiResponseCallback)fail;

/// sync api invoke
/// - Parameters:
///   - context: api context
///   - params: api params
- (id<ThingMiniAppExtApiModelProtocol>)invokeExtApiSync:(nonnull id<ThingMiniAppExtApiContext>)context
                                                 params:(nullable NSDictionary *)params;

/// miniapp active
- (void)onMiniAppResume;

/// miniapp pause, eg: backgroud
- (void)onMiniAppPause;

/// miniapp destory
- (void)onMiniAppDestroy;

@end

NS_ASSUME_NONNULL_END
