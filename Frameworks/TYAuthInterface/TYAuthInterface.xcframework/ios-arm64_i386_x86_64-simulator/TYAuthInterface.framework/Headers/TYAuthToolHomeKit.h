//
//  TYAuthToolHomeKit.h
//  TYAuthInterface
//
//  Created by 尼诺 on 2022/5/6.
//

#import <Foundation/Foundation.h>
#import <TYAuthorizationServices/TYAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYAuthToolHomeKit : NSObject

+ (void)getHomeAuthorizationStatusWithCompletionHandler:(void(^)(TYHMHomeManagerAuthorizationStatus status))completionHandler;

+ (TYHMHomeManagerAuthorizationStatus)homeManagerAuthorizationStatus;

+ (void)requestHomeAccessWithCompletionHandler:(TYHomeAccessCompletionHandler)completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYHMHomeManagerAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
