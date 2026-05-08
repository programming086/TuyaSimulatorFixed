//
//  TYAuthToolLocation.h
//  TYAuthInterface
//
//  Created by 尼诺 on 2022/5/6.
//

#import <Foundation/Foundation.h>
#import <TYAuthorizationServices/TYAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYAuthToolLocation : NSObject

+ (BOOL)available;

+ (TYLocationAuthorizationStatus)locationAuthorizationStatus;

+ (void)requestLocationAuthorizationWithCompletionHandler:(void(^)(TYLocationAuthorizationStatus status))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYLocationAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
