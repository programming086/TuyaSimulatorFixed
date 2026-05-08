//
//  TYAuthToolCamera.h
//  TYAuthInterface
//
//  Created by 尼诺 on 2022/5/6.
//

#import <Foundation/Foundation.h>
#import <TYAuthorizationServices/TYAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYAuthToolCamera : NSObject

+ (TYCameraAuthorizationStatus)cameraAuthorizationStatus;

+ (void)requestCameraAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYCameraAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
