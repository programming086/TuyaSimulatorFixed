
#import <Foundation/Foundation.h>
#import <ThingAuthorizationServices/ThingAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingAuthToolHomeKit : NSObject

+ (void)getHomeAuthorizationStatusWithCompletionHandler:(void(^)(ThingHMHomeManagerAuthorizationStatus status))completionHandler;

+ (ThingHMHomeManagerAuthorizationStatus)homeManagerAuthorizationStatus;

+ (void)requestHomeAccessWithCompletionHandler:(ThingHomeAccessCompletionHandler)completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingHMHomeManagerAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
