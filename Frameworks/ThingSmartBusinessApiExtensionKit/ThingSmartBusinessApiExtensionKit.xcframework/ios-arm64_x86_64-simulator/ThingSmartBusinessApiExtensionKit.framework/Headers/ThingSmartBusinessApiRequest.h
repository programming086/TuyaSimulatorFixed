
#import <UIKit/UIKit.h>
#import <ThingSmartNetworkKit/ThingSmartNetworkKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface ThingSmartBusinessApiRequest : ThingSmartRequest

/**
 Get hourly DP statistics for device

 @param devId Device ID
 @param dpId DP point ID
 @param date Date time, format: 20210601
 @param correction Data correction mode: 0=fill with 0 for missing data, 1=use previous time point data for missing data, 2=fill with # for missing data
 @param type Statistical type, e.g., sum, max, min (lowercase letters)
 @param keepScalaPoint Whether to keep decimal places according to DP point scaling factor, e.g., if scaled by 1000, choosing true will keep 3 decimal places
 @param success Success callback
 @param failure Failure callback
 */
+ (void)getHourDpStatisticWithDevId:(NSString *)devId
                               dpId:(NSString *)dpId
                               date:(NSString *)date
                         correction:(NSUInteger)correction
                               type:(NSString *)type
                     keepScalaPoint:(BOOL)keepScalaPoint
                            success:(void(^)(NSDictionary *retData))success
                            failure:(void(^)(NSError *error))failure;

/**
 Get daily DP statistics for device

 @param devId Device ID
 @param dpId DP point ID
 @param startDay Start date, format: 20210601
 @param endDay End date, format: 20210605
 @param correction Data correction mode: 0=fill with 0 for missing data, 1=use previous time point data for missing data, 2=fill with # for missing data
 @param type Statistical type, e.g., sum, max, min (lowercase letters)
 @param keepScalaPoint Whether to keep decimal places according to DP point scaling factor, e.g., if scaled by 1000, choosing true will keep 3 decimal places
 @param success Success callback
 @param failure Failure callback
 */
+ (void)getDayDpStatisticWithDevId:(NSString *)devId
                              dpId:(NSString *)dpId
                          startDay:(NSString *)startDay
                            endDay:(NSString *)endDay
                        correction:(NSUInteger)correction
                              type:(NSString *)type
                    keepScalaPoint:(BOOL)keepScalaPoint
                           success:(void(^)(NSDictionary *retData))success
                           failure:(void(^)(NSError *error))failure;

/**
 Get monthly DP statistics for device

 @param devId Device ID
 @param dpId DP point ID
 @param startMonth Start month, format: 202105
 @param endMonth End month, format: 202107
 @param correction Data correction mode: 0=fill with 0 for missing data, 1=use previous time point data for missing data, 2=fill with # for missing data
 @param type Statistical type, e.g., sum, max, min (lowercase letters)
 @param keepScalaPoint Whether to keep decimal places according to DP point scaling factor, e.g., if scaled by 1000, choosing true will keep 3 decimal places
 @param success Success callback
 @param failure Failure callback
 */
+ (void)getMonthDpStatisticWithDevId:(NSString *)devId
                                dpId:(NSString *)dpId
                          startMonth:(NSString *)startMonth
                            endMonth:(NSString *)endMonth
                          correction:(NSUInteger)correction
                                type:(NSString *)type
                      keepScalaPoint:(BOOL)keepScalaPoint
                             success:(void(^)(NSDictionary *retData))success
                             failure:(void(^)(NSError *error))failure;

/**
 Get 15-minute DP statistics for device

 @param devId Device ID
 @param dpId DP point ID
 @param date Date time, format: 20210601
 @param corrention Data correction mode: 0=fill with 0 for missing data, 1=use previous time point data for missing data, 2=fill with # for missing data
 @param type Statistical type, e.g., sum, max, min (lowercase letters)
 @param keepScalaPoint Whether to keep decimal places according to DP point scaling factor, e.g., if scaled by 1000, choosing true will keep 3 decimal places
 @param success Success callback
 @param failure Failure callback
 */
+ (void)get15minDpStatisticWithDevId:(NSString *)devId
                                dpId:(NSString *)dpId
                                date:(NSString *)date
                          correction:(NSUInteger)correction
                                type:(NSString *)type
                      keepScalaPoint:(BOOL)keepScalaPoint
                             success:(void(^)(NSDictionary *retData))success
                             failure:(void(^)(NSError *error))failure;

@end

NS_ASSUME_NONNULL_END
