//
//  NSError+ThingCameraSDKDomain.h
//  ThingSmartCameraBase
//
//  Created by Aaron on 2023/5/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXTERN NSString * const ThingSmartCameraErrorCodeDomain;

@interface NSError (ThingCameraSDKDomain)

+ (instancetype)thingcamera_errorWithErrorCode:(NSInteger)errorCode errorMsg:(NSString *)errorMsg;

@end

NS_ASSUME_NONNULL_END
