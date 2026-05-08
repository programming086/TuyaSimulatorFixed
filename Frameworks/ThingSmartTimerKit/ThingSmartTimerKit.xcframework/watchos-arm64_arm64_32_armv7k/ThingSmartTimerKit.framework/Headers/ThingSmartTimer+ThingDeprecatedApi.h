
#ifndef ThingSmartTimer_ThingDeprecatedApi_h
#define ThingSmartTimer_ThingDeprecatedApi_h

#import "ThingSmartTimer.h"

/// @deprecated The old timer api, deprecated.
///
/// Can use ThingSmartTimer.h to set timer
///
@interface ThingSmartTimer (ThingDeprecatedApi)

/// Add a new task for timer.
/// @param task The name of task.
/// @param loops The count of loop for the timer task.
/// @param devId The device ID for which the timer task needs to run on.
/// @param time The specific time to trigger this task.
/// @param dps The data point dictionary.
/// @param timeZone The timezone of the device.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use ThingSmartTimer::addTimerWithTask:loops:bizId:bizType:time:dps:status:isAppPush:aliasName:success:failure: instead.
- (void)addTimerWithTask:(NSString *)task
                   loops:(NSString *)loops
                   devId:(NSString *)devId
                    time:(NSString *)time
                     dps:(NSDictionary *)dps
                timeZone:(NSString *)timeZone
                 success:(ThingSuccessHandler)success
                 failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartTimer addTimerWithTask:loops:bizId:bizType:time:dps:status:isAppPush:aliasName:success:failure:] instead");


/// Add timed tasks.
/// @param task The name of the task.
/// @param loops Number of cycles.
/// @param devId The device ID.
/// @param time Timed clocks under timed tasks
/// @param dps Command dictionary.
/// @param timeZone Time zone of the device +08:00, if the phone time zone is not taken.
/// @param isAppPush A Boolean value indicates whether to turn on the push notification.
/// @param aliasName The remark for the task.
/// @param success  Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use ThingSmartTimer::addTimerWithTask:loops:bizId:bizType:time:dps:status:isAppPush:aliasName:success:failure: instead.
- (void)addTimerWithTask:(NSString *)task
                   loops:(NSString *)loops
                   devId:(NSString *)devId
                    time:(NSString *)time
                     dps:(NSDictionary *)dps
                timeZone:(NSString *)timeZone
               isAppPush:(BOOL)isAppPush
               aliasName:(NSString *)aliasName
                 success:(ThingSuccessHandler)success
                 failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartTimer addTimerWithTask:loops:bizId:bizType:time:dps:status:isAppPush:aliasName:success:failure:] instead");


/// Update timer task status.
/// @param task The name of the task.
/// @param devId The device ID.
/// @param status Timing group status.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use ThingSmartTimer::updateTimerStatusWithTask:bizId:bizType:status:success:failure: instead instead.
- (void)updateTimerTaskStatusWithTask:(NSString *)task
                                devId:(NSString *)devId
                               status:(NSInteger)status
                              success:(ThingSuccessHandler)success
                              failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartTimer updateTimerStatusWithTask:bizId:bizType:status:success:failure:] instead");


/// Update timeclock status.
/// @param task The name of the timer task.
/// @param devId The device ID.
/// @param timerId The timer ID for the update process.
/// @param status Timing clock status.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use ThingSmartTimer::updateTimerStatusWithTimerId:bizId:bizType:status:success:failure: instead instead.
- (void)updateTimerStatusWithTask:(NSString *)task
                            devId:(NSString *)devId
                          timerId:(NSString *)timerId
                           status:(NSInteger)status
                          success:(ThingSuccessHandler)success
                          failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartTimer updateTimerStatusWithTimerId:bizId:bizType:status:success:failure:] instead");


/// Delete time clock.
/// @param task The name of the timer task.
/// @param devId The device ID.
/// @param timerId The timer ID for the update process.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use ThingSmartTimer::removeTimerWithTimerId:bizId:bizType:success:failure: instead.
- (void)removeTimerWithTask:(NSString *)task
                      devId:(NSString *)devId
                    timerId:(NSString *)timerId
                    success:(ThingSuccessHandler)success
                    failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartTimer removeTimerWithTimerId:bizId:bizType:success:failure:] instead");


/// Update the timer.
/// @param task The name of the timer task.
/// @param loops The count of loop for the timer task.
/// @param devId The device ID.
/// @param timerId The timer ID for the update process.
/// @param time Timed clocks under timed tasks
/// @param dps Command dictionary.
/// @param timeZone Time zone of the device +08:00.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use ThingSmartTimer::updateTimerWithTimerId:loops:bizId:bizType:time:dps:isAppPush:aliasName:success:failure: instead.
- (void)updateTimerWithTask:(NSString *)task
                      loops:(NSString *)loops
                      devId:(NSString *)devId
                    timerId:(NSString *)timerId
                       time:(NSString *)time
                        dps:(NSDictionary *)dps
                   timeZone:(NSString *)timeZone
                    success:(ThingSuccessHandler)success
                    failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartTimer updateTimerWithTimerId:loops:bizId:bizType:time:dps:isAppPush:aliasName:success:failure:] instead");


/// Update the timer.
/// @param task The name of the timer task.
/// @param loops The count of loop for the timer task.
/// @param devId The device ID.
/// @param timerId The timer ID for the update process.
/// @param time Timed clocks under timed tasks
/// @param dps Command dictionary.
/// @param timeZone Time zone of the device +08:00.
/// @param isAppPush A Boolean value indicates whether to turn on the push notification.
/// @param aliasName The remark for the task.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use ThingSmartTimer::updateTimerWithTimerId:loops:bizId:bizType:time:dps:isAppPush:aliasName:success:failure: instead.
- (void)updateTimerWithTask:(NSString *)task
                      loops:(NSString *)loops
                      devId:(NSString *)devId
                    timerId:(NSString *)timerId
                       time:(NSString *)time
                        dps:(NSDictionary *)dps
                   timeZone:(NSString *)timeZone
                  isAppPush:(BOOL)isAppPush
                  aliasName:(NSString *)aliasName
                    success:(ThingSuccessHandler)success
                    failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartTimer updateTimerWithTimerId:loops:bizId:bizType:time:dps:isAppPush:aliasName:success:failure:] instead");


/// Get all timer clocks under timer task.
/// @param task The name of the timer task.
/// @param devId The device ID.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
/// @deprecated This method is deprecated, Use ThingSmartTimer::getTimerListWithTask:bizId:bizType:success:failure: instead.
- (void)getTimerWithTask:(NSString *)task
                   devId:(NSString *)devId
                 success:(void(^)(NSArray<ThingTimerModel *> *list))success
                 failure:(ThingFailureError)failure __deprecated_msg("This method is deprecated, Use [ThingSmartTimer getTimerListWithTask:bizId:bizType:success:failure:] instead");


@end


#endif /* ThingSmartTimer_ThingDeprecatedApi_h */
