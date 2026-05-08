//
//  TUNIAPIManagerUtil.h
//  TUNIAPIManagerKit
//
//  Created by rong huang on 2021/12/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TUNIAPIManagerUtil : NSObject

+ (nullable id)getModelWithParams:(nonnull NSDictionary *)params
                           plugin:(nonnull NSString *)plugin;
+ (nullable id)paramsJsonStringToModel:(nonnull NSString *)moduleName
                           paramString:(nonnull NSString *)paramString;

+ (NSString *)getSelectorWithMethod:(NSString *)method
                             params:(nullable NSDictionary *)params
                             isSync:(BOOL)isSync ;
+ (NSString *)handleInvokeMethod:(NSString *)aMethodName
                       hasParams:(BOOL)hasParams ;
+ (NSString *)handleInvokeMethodSync:(NSString *)aMethodName
                           hasParams:(BOOL)hasParams ;
@end

NS_ASSUME_NONNULL_END
