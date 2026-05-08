
#import <Foundation/Foundation.h>
#import <ThingAuthorizationServices/ThingAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingAuthToolNotification : NSObject

+ (ThingUNAuthorizationStatus)notificationAuthorizationStatus;

+ (void)requestNotificationAuthorizationWithCompletionHandler:(void (^)(BOOL granted))completionHandler;

+ (void)requestNotificationAuthorizationWithOptions:(ThingUNAuthorizationOptions)options
                                  completionHandler:(void (^)(BOOL granted))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(ThingUNAuthorizationStatus status))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                               options:(ThingUNAuthorizationOptions)options
                     completionHandler:(void(^)(ThingUNAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
