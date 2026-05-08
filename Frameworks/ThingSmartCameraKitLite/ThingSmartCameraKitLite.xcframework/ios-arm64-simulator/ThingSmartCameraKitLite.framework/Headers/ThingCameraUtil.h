//
//  ThingCameraUtil.h
//  ThingSmartCameraKitLite
//
//  Created by MokZF on 2025/1/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingCameraUtil : NSObject

+ (NSString *)md5WithString:(NSString *)string;

+ (NSString *)generateRandomStringWithLength:(NSUInteger)length;

+ (id)thingsdk_objectFromJSONString:(NSString *)string;

+ (NSString *)thing_jsonStringFromDictionary:(NSDictionary *)dictionary;

+ (NSData *)thing_dataFromDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
