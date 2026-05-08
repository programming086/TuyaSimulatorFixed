
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import <Foundation/Foundation.h>

@interface ThingSmartDevice (offlineSupport)

- (void)requestCachedDps:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (void)pushDpsWithHttp:(NSDictionary *)dps success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

@end

