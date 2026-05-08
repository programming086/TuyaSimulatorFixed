//
//  TYAuthToolNotification.h
//  TYAuthInterface
//
//  Created by 尼诺 on 2022/5/6.
//

#import <Foundation/Foundation.h>
#import <TYAuthorizationServices/TYAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYAuthToolNotification : NSObject

+ (TYUNAuthorizationStatus)notificationAuthorizationStatus;

+ (void)requestNotificationAuthorizationWithCompletionHandler:(void (^)(BOOL granted))completionHandler;

+ (void)requestNotificationAuthorizationWithOptions:(TYUNAuthorizationOptions)options
                                  completionHandler:(void (^)(BOOL granted))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYUNAuthorizationStatus status))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                               options:(TYUNAuthorizationOptions)options
                     completionHandler:(void(^)(TYUNAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
