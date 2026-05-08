//
//  TYAuthToolMicrophone.h
//  TYAuthInterface
//
//  Created by 尼诺 on 2022/5/6.
//

#import <Foundation/Foundation.h>
#import <TYAuthorizationServices/TYAuthorizationServices.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYAuthToolMicrophone : NSObject

+ (TYMicrophoneAuthorizationStatus)microphoneAuthorizationStatus;

+ (void)requestMicrophoneAuthorizationWithCompletionHandler:(void(^)(BOOL granted))completionHandler;

+ (void)requestAuthorizationWithSource:(NSString *)source
                     completionHandler:(void(^)(TYMicrophoneAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
