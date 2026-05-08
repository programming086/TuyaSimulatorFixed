
#import <Foundation/Foundation.h>
#import <ThingAuthorizationServices/ThingAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingAuthToolCamera : NSObject

+ (ThingCameraAuthorizationStatus)cameraAuthorizationStatus;

+ (void)requestCameraAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingCameraAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
