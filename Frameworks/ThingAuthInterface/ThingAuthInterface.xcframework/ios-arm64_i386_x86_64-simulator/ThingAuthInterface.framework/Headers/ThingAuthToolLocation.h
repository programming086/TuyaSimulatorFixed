
#import <Foundation/Foundation.h>
#import <ThingAuthorizationServices/ThingAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingAuthToolLocation : NSObject

+ (BOOL)available;

+ (ThingLocationAuthorizationStatus)locationAuthorizationStatus;

+ (void)requestLocationAuthorizationWithCompletionHandler:(void(^)(ThingLocationAuthorizationStatus status))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingLocationAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
