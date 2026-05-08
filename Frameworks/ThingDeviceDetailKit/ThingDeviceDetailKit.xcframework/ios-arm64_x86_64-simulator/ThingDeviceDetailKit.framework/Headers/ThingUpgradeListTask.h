
#import <Foundation/Foundation.h>
#import "ThingUpgradeTask.h"
#import "ThingUpgradeConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingUpgradeListTask : NSObject <ThingUpgradeTask>

- (instancetype)initWithTaskId:(NSString *)taskId family:(long long)familyId success:(void (^)(NSArray<ThingUpgradeListInfo *> * list))success failure:(void (^)(NSError *error))failure completed:(void (^)(NSString *taskId))completed;

- (void)run;

@end

NS_ASSUME_NONNULL_END
