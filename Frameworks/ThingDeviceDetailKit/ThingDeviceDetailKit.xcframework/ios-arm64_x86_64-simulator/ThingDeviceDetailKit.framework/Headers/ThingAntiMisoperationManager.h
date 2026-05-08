    

#import <Foundation/Foundation.h>
@class ThingAntiMisoperationManager;

NS_ASSUME_NONNULL_BEGIN

@protocol ThingAntiMisoperationManagerListener <NSObject>
@optional
- (void)antiMisoperationManager:(ThingAntiMisoperationManager *)manager statusDidUpdate:(BOOL)status;

@end


@interface ThingAntiMisoperationManager : NSObject

- (instancetype)initWithDeviceId:(NSString *)deviceId;

- (void)addListener:(id<ThingAntiMisoperationManagerListener>)listener;
- (void)removeListener:(id<ThingAntiMisoperationManagerListener>)listener;


/// Validate the device whether support anti-misoperation or not
/// - Parameters:
///   - success: Success callback with BOOL value, support if true, otherwise not support
///   - failure: Failure callback with error
- (void)isSupportWithSuccess:(nullable void(^)(BOOL support))success failure:(nullable void(^)(NSError *error))failure;


/// Get the status of the anti-misoperation setting of the device
/// - Parameters:
///   - success: Success callback with BOOL value, enabled if true, otherwise disabled
///   - failure: Failure callback with error
- (void)getStatusWithSuccess:(nullable void(^)(BOOL status))success failure:(nullable void(^)(NSError *error))failure;


/// Update the status of the anti-misoperation setting of the device
/// - Parameters:
///   - deviceId: The id of the device
///   - status: The status of the anti-misoperation setting, enabled if true, otherwise disabled
///   - success: Success callback with BOOL value, enabled if true, otherwise disabled
///   - failure: Failure callback with error
- (void)updateStatusWithStatus:(BOOL)status success:(nullable void(^)(BOOL status))success failure:(nullable void(^)(NSError *error))failure;

/// Get the status of the anti-misoperation setting of the device
/// The status will be returned by the listener
- (void)getStatus;


/// Update the status of the anti-misoperation setting of the device
/// - Parameter status: The status of the anti-misoperation setting, enabled if true, otherwise disabled
/// The status will be returned by the listener
- (void)updateStatus:(BOOL)status;

@end

NS_ASSUME_NONNULL_END
