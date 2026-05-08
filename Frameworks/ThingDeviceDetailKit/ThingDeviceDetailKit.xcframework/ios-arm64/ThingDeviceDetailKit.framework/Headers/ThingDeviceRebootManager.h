
#import <Foundation/Foundation.h>
#import "ThingDeviceRebootTimer.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceRebootManager : NSObject

- (instancetype)initWithDeviceId:(NSString *)deviceId;

@property (nonatomic, copy, readonly) NSString *deviceId;

#pragma mark - reboot support

/// Check if the device support reboot
/// - Parameters:
///   - success: success callback with support status, true if support, otherwise false
///   - failure: failure callback
- (void)supportRebootSuccess:(nullable void(^)(BOOL support))success failure:(nullable void(^)(NSError *))failure;



#pragma mark - immediately reboot

/// Reboot the device immediately
/// Should check the device support reboot first
/// - Parameters:
///   - success: success callback. It will be called when the message is sent successfully, but it does not mean the device can be rebooted successfully.
///   - failure: failure callback. It will be called when the message is sent failed.
- (void)rebootImmediatelySuccess:(nullable void(^)(void))success failure:(nullable void(^)(NSError *error))failure;


#pragma mark - timer reboot

/// Add a timer to reboot the device
/// Should check the device support reboot first
/// **Note:** Only one timer exists on the device site, so a new timer will cover the old one.
/// - Parameters:
///   - timer: the timer to reboot the device
///   - success: success callback with tid, the timer id
///   - failure: failure callback
- (void)addTimer:(ThingDeviceRebootTimer *)timer success:(nullable void(^)(NSString *tid))success failure:(nullable void(^)(NSError *error))failure;

- (void)addTimers:(NSArray<ThingDeviceRebootTimer *> *)timers success:(nullable void(^)(NSArray<NSString *> * _Nullable))success failure:(nullable void(^)(NSError *error))failure __attribute__((deprecated("Use addTimer:success:failure: instead")));;


/// Update the timer
/// Should check the device support reboot first
/// - Parameters:
///   - timer: the timer to reboot the device
///   - success: success callback
///   - failure: failure callback
- (void)updateTimer:(ThingDeviceRebootTimer *)timer success:(nullable void(^)(void))success failure:(nullable void(^)(NSError *error))failure;


/// Update the timer
/// Should check the device support reboot first
/// - Parameters:
///   - success: success callback with timer
///   - failure: failure callback
- (void)getTimerSuccess:(nullable void(^)(ThingDeviceRebootTimer * _Nullable))success failure:(nullable void(^)(NSError *error))failure;

- (void)getTimersSuccess:(nullable void(^)(NSArray<ThingDeviceRebootTimer *> *_Nullable))success failure:(nullable void(^)(NSError *error))failure __attribute__((deprecated("Use getTimerSuccess:failure: instead")));

- (void)getTimersCountSuccess:(void(^)(NSInteger count))success failure:(nullable void(^)(NSError *error))failure __attribute__((deprecated));


- (void)removeTimers:(NSArray<NSString *> *)timers success:(nullable void(^)(void))success failure:(nullable void(^)(NSError *error))failure __attribute__((deprecated));


@end

NS_ASSUME_NONNULL_END
