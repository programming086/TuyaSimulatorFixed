
#import <Foundation/Foundation.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>
#import "ThingSmartPushSettingRequestModel.h"
#import "ThingSmartDeviceAlarmPurchaseEntity.h"
#import "ThingSmartDeviceAlarmServiceInfoEntity.h"
#import "ThingSmartDeviceAlarmListEntity.h"

@interface ThingSmartMessagePushSetting : NSObject
/**
 * Retrieve the current status of the message push switch for a given type.
 *
 * @param type The type of message switch.
 * @param success A block that will be called with a BOOL indicating the current status.
 * @param failure A block that will be called if an error occurs, passing an NSError object.
 */
- (void)getMessagePushSwitchStatusWithType:(ThingSmartMessagePushSwitchType)type
                            success:(ThingSuccessBOOL _Nullable)success
                            failure:(ThingFailureError _Nullable)failure;

/**
 * Set the status of the message push switch using a request model.
 *
 * @param requestModel The request model containing the new status.
 * @param success A block that will be called if the operation is successful.
 * @param failure A block that will be called if an error occurs, passing an NSError object.
 */
- (void)setMessagePushSwitchStatusWithRequestModel:(ThingSmartMessagePushSwitchRequestModel *_Nonnull)requestModel
                    success:(__nullable ThingSuccessHandler)success
                    failure:(__nullable ThingFailureError)failure;

/**
 * Retrieve the current status of device alarm for a specific push channel.
 *
 * @param pushChannel The push channel.
 * @param success A block that will be called with a BOOL indicating the current status.
 * @param failure A block that will be called if an error occurs, passing an NSError object.
 */
- (void)getDeviceAlarmSwitchStatusWithPushChannel:(ThingSmartDeviceAlarmPushChannel)pushChannel
success:(ThingSuccessBOOL _Nullable)success
failure:(ThingFailureError _Nullable)failure;

/**
 * Set the alarm switch status using a request model.
 *
 * @param requestModel The request model containing the new status.
 * @param success A block that will be called if the operation is successful.
 * @param failure A block that will be called if an error occurs, passing an NSError object.
 */
- (void)setDeviceAlarmSwitchStatusWithRequestModel:(ThingSmartDeviceAlarmSwitchRequestModel *_Nonnull)requestModel
success:(__nullable ThingSuccessHandler)success
failure:(__nullable ThingFailureError)failure;

/**
 * Retrieve the current throttle time for device alarms on a specific push channel.
 *
 * @param pushChannel The push channel.
 * @param success A block that will be called with an integer indicating the current throttle time.
 * @param failure A block that will be called if an error occurs, passing an NSError object.
 */
- (void)getDeviceAlarmThrottleTimeWithPushChannel:(ThingSmartDeviceAlarmPushChannel)pushChannel
                                      success:(ThingSuccessInt _Nullable )success
                                      failure:(ThingFailureError _Nullable )failure;

/**
 * Set the throttle time for device alarms using a request model.
 *
 * @param requestModel The request model containing the new throttle time.
 * @param success A block that will be called if the operation is successful, returning a BOOL.
 * @param failure A block that will be called if an error occurs, passing an NSError object.
 */
- (void)setDeviceAlarmThrottleTimeWithRequestModel:(ThingSmartDeviceAlarmThrottleTimeRequestModel *_Nonnull)requestModel
                           success:(__nullable ThingSuccessBOOL)success
                           failure:(__nullable ThingFailureError)failure;

/**
 * Retrieve detailed information for device alarms using a request model.
 *
 * @param requestModel The request model .
 * @param success A block that will be called with an array of device alarm details.
 * @param failure A block that will be called if an error occurs, passing an NSError object.
 */
- (void)getDeviceAlarmServiceInfoWithRequestModel:(ThingSmartDeviceAlarmServiceRequestModel *_Nonnull)requestModel
                                      success:(void(^_Nullable)(NSArray <ThingSmartDeviceAlarmServiceInfoEntity *>* _Nullable result))success
                                      failure:(ThingFailureError _Nullable )failure;

/**
 * Update the service information for device alarms using a request model.
 *
 * @param requestModel The request model containing the new service information.
 * @param success A block that will be called if the operation is successful, returning a BOOL.
 * @param failure A block that will be called if an error occurs, passing an NSError object.
 */
- (void)setDeviceAlarmServiceInfoWithRequestModel:(ThingSmartDeviceAlarmServiceUpdateRequestModel *_Nonnull)requestModel
                                      success:(ThingSuccessBOOL _Nullable )success
                                      failure:(ThingFailureError _Nullable )failure;
                            
/**
 * Retrieve the purchase information for device alarms on a specific push channel.
 *
 * @param pushChannel The push channel.
 * @param success A block that will be called with purchase result.
 * @param failure A block that will be called if an error occurs, passing an NSError object.
 */
- (void)getDeviceAlarmPurchaseInfoWithPushChannel:(ThingSmartDeviceAlarmPushChannel)pushChannel
                                                 success:(void(^_Nullable)(ThingSmartDeviceAlarmPurchaseEntity * _Nullable result))success
                                             failure:(ThingFailureError _Nullable )failure;

/**
 * Retrieve a list of device alarms based on a request model.
 *
 * @param requestModel The request model.
 * @param success A block that will be called with device list.
 * @param failure A block that will be called if an error occurs, passing an NSError object.
 */
- (void)getDeviceAlarmListWithRequestModel:(ThingSmartDeviceAlarmListRequestModel *_Nonnull)requestModel
                             success:(void(^_Nullable)(ThingSmartDeviceAlarmListEntity * _Nullable result))success
                             failure:(ThingFailureError _Nullable )failure;
@end


