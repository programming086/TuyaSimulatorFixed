
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingDeviceOfflineReminderManager : NSObject


/// get the offline reminder support status of device
/// - Parameters:
///   - productId: the id of the device
///   - success: support if status is true, otherwise not support
///   - failure: error happen
+ (void)getOfflineReminderSupportStatusWithDeviceId:(NSString *)deviceId success:(void(^)(BOOL status))success failure:(void(^)(NSError *error))failure;


/// get the offline reminder status of device
/// - Parameters:
///   - deviceId: the id of the device
///   - success: open if status is true, otherwise close
///   - failure: error happen
+ (void)getOfflineReminderStatusWithDeviceId:(NSString *)deviceId success:(void(^)(BOOL status))success failure:(void(^)(NSError *error))failure;


/// update the offline reminder status of device
/// - Parameters:
///   - deviceId: the id of the device
///   - status: the offline reminder status
///   - success: update success
///   - failure: error happen
+ (void)updateOfflineReminderStatusWithDeviceId:(NSString *)deviceId status:(BOOL)status success:(void(^)(void))success failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
