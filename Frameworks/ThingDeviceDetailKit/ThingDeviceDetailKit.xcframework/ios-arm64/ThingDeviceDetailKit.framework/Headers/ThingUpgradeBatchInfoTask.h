
#import <Foundation/Foundation.h>
#import "ThingUpgradeTask.h"
#import "ThingUpgradeConstants.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingUpgradeBatchInfoTask : NSObject <ThingUpgradeTask>

- (instancetype)initWithTaskId:(NSString *)taskId deviceId:(NSString *)deviceId success:(void (^)(ThingSmartFirmwareCheckResult *info))success failure:(void (^)(NSError *error))failure completed:(void (^)(NSString *taskId))completed;

- (void)run;

@end

NS_ASSUME_NONNULL_END
