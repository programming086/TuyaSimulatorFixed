//
//  NSError+ThingSmartCallSDKDomain.h
//  ThingSmartCallChannelKit
//
//  Created by Aaron on 2023/10/31.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSError (ThingSmartCallSDKDomain)

+ (instancetype)thingcall_errorWithErrorCode:(NSInteger)errorCode errorMsg:(NSString *)errorMsg;

+ (instancetype)thingcall_errorWithErrorCode:(NSInteger)errorCode errorMsg:(NSString *)errorMsg extra:(nullable NSDictionary *)extra;

+ (instancetype)nonexistentDeviceError;

@end

NS_ASSUME_NONNULL_END
