
#import <Foundation/Foundation.h>
@class ThingSubDeviceReplaceManager;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingSubDeviceReplaceRole) {
    ThingSubDeviceReplacer, // Works as a replacer, typically meaning this is a good device
    ThingSubDeviceReplacee, // Works as a replacee, typically meaning this is a faulty device
};

typedef NS_ENUM(NSInteger, ThingSubDeviceReplaceStatus) {
    ThingSubDeviceReplaceFailure = -1, // Replacement failed
    ThingSubDeviceReplacing = 0, // Replacement in progress
    ThingSubDeviceReplaceSuccess = 1, // Replacement succeeded
};


@interface ThingSubDeviceReplaceResult : NSObject
@property (nonatomic, assign) ThingSubDeviceReplaceStatus status;
@property (nonatomic, copy) NSString *failReason;
@end

@protocol ThingSubDeviceReplaceManagerListener <NSObject>
- (void)manager:(ThingSubDeviceReplaceManager *)manager replaceDidCompleteWithResult:(BOOL)success error:(nullable NSError *)error;
@end



@interface ThingSubDeviceReplaceManager : NSObject

/// Initialization method
/// - Parameters:
///   - deviceId: The ID of the entry device
///   - role: The role of the device
/// - Note: Regarding `role`, it's typically determined by whether the entry device is faulty. If the entry device is not faulty, it's generally used to replace other devices (`role` is usually `replacer`). Conversely, if the entry device is faulty, it's generally replaced by another device (`role` is usually `replacee`)
- (instancetype)initWithDeviceId:(NSString *)deviceId role:(ThingSubDeviceReplaceRole)role;


/// Check if the entry device supports sub-device replacement
/// - Parameters:
///   - success: Success callback, returns true if supported, false otherwise
///   - failure: Failure callback
- (void)supportReplaceWithSuccess:(void(^)(BOOL result))success failure:(void(^)(NSError *error))failure;


/// Get list of compatible devices
/// - Parameters:
///   - success: Success callback, returns array of compatible device IDs
///   - failure: Failure callback
- (void)getCompatibleSubDevicesWithSuccess:(void(^)(NSArray<NSString *> * result))success failure:(void(^)(NSError *error))failure;


/// Perform sub-device replacement
/// - Parameters:
///   - deviceId: The device ID of the sub-device to be used for replacement. If `role` is `replacer`, this device will be replaced by the entry device. If `role` is `replacee`, this device will replace the entry device.
///   - timeout: Timeout in seconds (minimum 30 seconds, defaults to 30 if less than 30)
///   - success: Success callback, returns replacement ID
///   - failure: Failure callback
- (void)replaceWithOtherDevice:(NSString *)deviceId timeout:(NSInteger)timeout success:(void(^)(NSString *replaceId))success failure:(void(^)(NSError *error))failure;


/// Query replacement result
/// - Parameters:
///   - replaceId: The replacement ID
///   - success: Success callback, returns replacement result
///   - failure: Failure callback
/// - Note: Normally you won't need this method as you can listen for results via `addListener`. This method is provided for cases when network issues cause MQ message loss and the listener doesn't get called.
- (void)replaceResultWithReplaceId:(NSString *)replaceId success:(void(^)(ThingSubDeviceReplaceResult *result))success failure:(void(^)(NSError *error))failure;

/// Add listener
- (void)addListener:(id<ThingSubDeviceReplaceManagerListener>)listener;

/// Remove listener
- (void)removeListener:(id<ThingSubDeviceReplaceManagerListener>)listener;


@end

NS_ASSUME_NONNULL_END
