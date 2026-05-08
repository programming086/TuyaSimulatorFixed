
#import <Foundation/Foundation.h>
#import "ThingUpgradeConstants.h"
@class ThingUpgradeManager;

NS_ASSUME_NONNULL_BEGIN

@protocol ThingUpgradeManagerListener <NSObject>

- (void)upgradeManager:(ThingUpgradeManager *)manager statusDidChange:(ThingSmartFirmwareUpgradeStatusModel *)status;
- (void)upgradeManager:(ThingUpgradeManager *)manager shouldContinueUpgrade:(void(^)(BOOL))ContinueUpgrade;

@end

@interface ThingUpgradeManager : NSObject

@property (nonatomic, readonly) NSString *deviceId;
@property (nonatomic, weak) id<ThingUpgradeManagerListener> listener;
- (instancetype)initWithDeviceId:(NSString *)deviceId;

+ (BOOL)deviceSupportUpgrade:(NSString *)deviceId;
- (BOOL)supportUpgrade;


+ (void)getUpgradeInfoWithDeviceId:(NSString *)deviceId success:(void(^)(ThingUpgradeInfo *info))success failure:(void(^)(NSError *error))failure;
- (void)getUpgradeInfoWithSuccess:(void(^)(ThingUpgradeInfo *info))success failure:(void(^)(NSError *error))failure;


+ (void)getUpgradeStatusWithDeviceId:(NSString *)deviceId success:(void(^)(ThingSmartFirmwareUpgradeStatusModel *status))success failure:(void(^)(NSError *error))failure;
- (void)getUpgradeStatusWithSuccess:(void(^)(ThingSmartFirmwareUpgradeStatusModel *status))success failure:(void(^)(NSError *error))failure;


- (void)startUpgrade:(ThingUpgradeInfo *)info;
- (void)stopUpgrade;

@end

NS_ASSUME_NONNULL_END
