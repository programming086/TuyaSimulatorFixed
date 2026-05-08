//
//  ThingSmartLangsPackError.h
//  ThingSmartLangsPackKit
//
//  Created by Hemin Won on 2021/12/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSInteger const ThingSmartLangsPackErrorCode;

FOUNDATION_EXTERN NSErrorDomain const ThingSmartLangsPackErrorDomain;

FOUNDATION_EXTERN ThingSmartLangsPackErrorCode ThingSmartLangsPackErrorCodeDownloaderParamInvalid;

@interface ThingSmartLangsPackError : NSObject

+ (NSError *)errorWithCode:(NSInteger)code message:(nullable NSString *)message;

@end

NS_ASSUME_NONNULL_END
