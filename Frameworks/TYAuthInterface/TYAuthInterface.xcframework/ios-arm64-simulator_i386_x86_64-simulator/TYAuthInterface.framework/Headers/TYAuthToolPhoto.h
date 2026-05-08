//
//  TYAuthToolPhoto.h
//  TYAuthInterface
//
//  Created by 尼诺 on 2022/5/6.
//

#import <Foundation/Foundation.h>
#import <TYAuthorizationServices/TYAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYAuthToolPhoto : NSObject

+ (TYPhotosAuthorizationStatus)photosAuthorizationStatus;

+ (void)requestPhotosAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYPhotosAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
