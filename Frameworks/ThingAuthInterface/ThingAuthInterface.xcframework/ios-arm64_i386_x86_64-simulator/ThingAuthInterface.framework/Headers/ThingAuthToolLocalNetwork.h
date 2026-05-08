
#import <Foundation/Foundation.h>
#import <ThingAuthorizationServices/ThingAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingAuthToolLocalNetwork : NSObject

+ (ThingLocalNetworkAuthorizationStatus)localNetworkAuthorizationStatus;

+ (void)getLocalNetworkAuthorizationStatusWithCompletionHandler:(void (^)(ThingLocalNetworkAuthorizationStatus status))completionHandler;

+ (void)requestLocalNetworkAuthorization;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingLocalNetworkAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
