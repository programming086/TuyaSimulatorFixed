//
//  TYAuthToolLocalNetwork.h
//  TYAuthInterface
//
//  Created by 尼诺 on 2022/5/6.
//

#import <Foundation/Foundation.h>
#import <TYAuthorizationServices/TYAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYAuthToolLocalNetwork : NSObject

+ (TYLocalNetworkAuthorizationStatus)localNetworkAuthorizationStatus;

+ (void)getLocalNetworkAuthorizationStatusWithCompletionHandler:(void (^)(TYLocalNetworkAuthorizationStatus status))completionHandler;

+ (void)requestLocalNetworkAuthorization;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYLocalNetworkAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
