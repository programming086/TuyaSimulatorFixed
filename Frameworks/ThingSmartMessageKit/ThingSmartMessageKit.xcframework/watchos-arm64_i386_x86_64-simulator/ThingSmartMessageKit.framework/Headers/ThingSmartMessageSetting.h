
#import <Foundation/Foundation.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>
#import "ThingSmartMessageRequestModel.h"
#import "ThingSmartMessageListModel.h"
#import "ThingSmartMessageDNDListEntity.h"
#import "ThingSmartMessageOnceDNDRequestModel.h"
#import "ThingSmartMessageDNDTimerModel.h"

NS_ASSUME_NONNULL_BEGIN


/// @brief ThingSmartMessageSetting provides methods to manage the Do Not Disturb (DND) mode for devices.
///
@interface ThingSmartMessageSetting : NSObject

/// Sets the DND status for devices.
/// @param flags The switching status.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. ThingFailureError is returned.
- (void)setDeviceDNDSettingStatus:(BOOL)flags success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Returns the DND status for devices.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. ThingFailureError is returned.
- (void)getDeviceDNDSettingstatusSuccess:(ThingSuccessBOOL)success failure:(ThingFailureError)failure;

/// Returns a list of DND settings.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. ThingFailureError is returned.
- (void)getDNDListSuccess:(ThingSuccessList)success failure:(ThingFailureError)failure;

/// Returns a list of devices.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. ThingFailureError is returned.
- (void)getDNDDeviceListSuccess:(ThingSuccessList)success failure:(ThingFailureError)failure;

/// Adds DND time for devices.
/// @param requestModel The model of a DND request.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. ThingFailureError is returned.
- (void)addDNDWithDNDRequestModel:(ThingSmartMessageSettingDNDRequestModel *)requestModel success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Modifies DND time for devices.
/// @param timerID The ID of the timer.
/// @param requestModel The model of a DND request.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. ThingFailureError is returned.
- (void)modifyDNDWithTimerID:(long)timerID DNDRequestModel:(ThingSmartMessageSettingDNDRequestModel *)requestModel success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Removes DND time.
/// @param timerID The ID of the timer.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. ThingFailureError is returned.
- (void)removeDNDWithTimerID:(long)timerID success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// Get privacy authorization status.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. ThingFailureError is returned.
- (void)getPrivacyAuthorizationStatusSuccess:(void(^)(ThingSmartMessageAuthorizationModel *model))success failure:(ThingFailureError)failure;

/// Update status of privacy authorization.
/// @param model The model of a authorization request.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. ThingFailureError is returned.
- (void)updatePrivacyAuthorizationStatusWithModel:(ThingSmartMessageAuthorizationRequestModel *)model Success:(ThingSuccessID)success failure:(ThingFailureError)failure;

/// Returns a list of DND settings.Includes weekly periodic do-not-disturb and one-time do-not-disturb.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. ThingFailureError is returned.
- (void)getAllDNDListWithSuccess:(void(^)(ThingSmartMessageDNDListEntity * _Nullable result))success failure:(ThingFailureError)failure;

/// Adds one-time DND time for devices.
/// @param requestModel The model of a DND request.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. ThingFailureError is returned.
- (void)addOnceDNDWithRequestModel:(ThingSmartMessageOnceDNDRequestModel *)requestModel
                           success:(ThingSuccessHandler)success
                           failure:(ThingFailureError)failure;

/// Modifies one-time DND time for devices.
/// @param timerID The ID of the timer.
/// @param requestModel The model of a DND request.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error. ThingFailureError is returned.
- (void)modifyOnceDNDWithTimerID:(long)timerID
               requestModel:(ThingSmartMessageOnceDNDRequestModel *)requestModel
                           success:(ThingSuccessHandler)success
                           failure:(ThingFailureError)failure;


@end

NS_ASSUME_NONNULL_END
