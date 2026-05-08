
#import <Foundation/Foundation.h>
#import <ThingAuthorizationServices/ThingAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingAuthToolPhoto : NSObject

+ (ThingPhotosAuthorizationStatus)photosAuthorizationStatus;

+ (void)requestPhotosAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingPhotosAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
