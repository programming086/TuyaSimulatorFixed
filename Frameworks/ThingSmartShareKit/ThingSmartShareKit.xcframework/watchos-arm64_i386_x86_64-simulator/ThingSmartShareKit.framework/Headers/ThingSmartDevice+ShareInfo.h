
#import <ThingSmartDeviceCoreKit/ThingSmartDevice.h>

@class ThingSmartReceivedShareUserModel;

/// Thing smart device share function
@interface ThingSmartDevice (ShareInfo)

/// Get users for device sharing.
/// @param success Called when the task finishes successfully. ThingSmartReceivedShareUserModel will be returned.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)getShareInfoWithSuccess:(void(^)(ThingSmartReceivedShareUserModel *model))success
                       failure:(ThingFailureError)failure;

/// Remove Received Shared.
/// @param success Called when the task finishes successfully.
/// @param failure If error occurred while adding the task, this block will be called.
- (void)removeReceiveDeviceShareWithSuccess:(ThingSuccessHandler)success
                                    failure:(ThingFailureError)failure;


@end
