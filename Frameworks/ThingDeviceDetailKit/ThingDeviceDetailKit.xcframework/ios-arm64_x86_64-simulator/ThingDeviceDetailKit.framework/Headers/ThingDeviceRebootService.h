
#import <Foundation/Foundation.h>
#import "ThingDeviceRebootTimer.h"
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceRebootService : NSObject
@property (nonatomic, strong, readonly) ThingSmartDevice *device;
@property (nonatomic, copy, readonly) NSString *deviceId;

- (instancetype)initWithDeviceId:(NSString *)deviceId;

#pragma mark - timer reboot
- (void)addTimers:(NSArray<ThingDeviceRebootTimer *> *)timers success:(void(^)(NSArray<NSString *> *))success failure:(void(^)(NSError *error))failure;

- (void)updateTimer:(ThingDeviceRebootTimer *)timer success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

- (void)getTimersSuccess:(void(^)(NSArray<ThingDeviceRebootTimer *> *))success failure:(void(^)(NSError *error))failure;

- (void)getTimersCountSuccess:(void(^)(NSInteger count))success failure:(void(^)(NSError *error))failure;

- (void)removeTimers:(NSArray<NSString *> *)timers success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

#pragma mark - immediately reboot
- (void)rebootImmediatelySuccess:(void(^)(void))success failure:(void(^)(NSError *error))failure;


@end

NS_ASSUME_NONNULL_END
