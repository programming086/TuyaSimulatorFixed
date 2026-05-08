
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSDK (LiveActivity)
- (void)registerLiveActivityWithId:(NSString *)activityId pushToken:(NSData *)token completion:(void(^)(NSError  * _Nullable error))completion;
@end

NS_ASSUME_NONNULL_END
