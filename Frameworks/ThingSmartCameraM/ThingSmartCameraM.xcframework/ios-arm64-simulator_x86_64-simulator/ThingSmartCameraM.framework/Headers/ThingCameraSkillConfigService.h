
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^ThingCameraSkillQueryCompletion)(NSDictionary *skill, BOOL cached);

@interface ThingCameraSkillConfigService : NSObject

@property (class, nonatomic, strong, readonly) ThingCameraSkillConfigService *sharedInstance;

- (nullable NSDictionary *)queryCachedSkillWithDevId:(NSString *)devId;
- (nullable NSDictionary *)querySkillWithDevId:(NSString *)devId completion:(nullable ThingCameraSkillQueryCompletion)completion;

- (BOOL)removeCachedSkillWithDevId:(NSString *)devId;

@end

NS_ASSUME_NONNULL_END
