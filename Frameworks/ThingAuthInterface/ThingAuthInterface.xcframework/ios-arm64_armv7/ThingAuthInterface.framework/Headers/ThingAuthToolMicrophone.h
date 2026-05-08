
#import <Foundation/Foundation.h>
#import <ThingAuthorizationServices/ThingAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingAuthToolMicrophone : NSObject

+ (ThingMicrophoneAuthorizationStatus)microphoneAuthorizationStatus;

+ (void)requestMicrophoneAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingMicrophoneAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
