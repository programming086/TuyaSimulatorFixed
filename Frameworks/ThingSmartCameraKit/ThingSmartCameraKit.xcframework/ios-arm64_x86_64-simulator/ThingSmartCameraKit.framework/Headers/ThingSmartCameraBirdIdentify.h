
#import <Foundation/Foundation.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartCameraBirdIdentify : NSObject

/// instance
/// - Parameter devId: device id
- (instancetype)initWithDeviceId:(NSString *)devId;

/// query video days
/// - Parameters:
///   - startDateString: start date string, such as "2025-03-08"
///   - days: days
///   - success: success
///   - failure: failure
- (void)queryVideoWithStartDate:(NSString *)startDateString
                        preDays:(NSInteger)days
                        success:(ThingSuccessID)success
                        failure:(ThingFailureError)failure;

/// query bird category
/// - Parameters:
///   - startDateString: start date string, such as "2025-03-08"
///   - endDateString: end date string, such as "2025-03-09"
///   - success: success
///   - failure: failure
- (void)queryBirdCategoryWithStartDate:(NSString *)startDateString
                               endDate:(NSString *)endDateString
                               success:(ThingSuccessID)success
                               failure:(ThingFailureError)failure;

/// query bird video message
/// - Parameters:
///   - startTime: start time; unit:second
///   - endTime: end time; unit:second
///   - pageNum: page number
///   - pageSize: page size
///   - aiBird: is it only necessary to query the videos of bird detection
///   - birdCode: bird code 【nullable】
///   - success: success
///   - failure: failure
- (void)queryBirdVideoMesssageWithStartTime:(NSTimeInterval)startTime
                                    endTime:(NSTimeInterval)endTime
                                    pageNum:(NSInteger)pageNum
                                   pageSize:(NSInteger)pageSize
                                     aiBird:(BOOL)aiBird
                                   birdCode:(nullable NSString *)birdCode
                                    success:(ThingSuccessID)success
                                    failure:(ThingFailureError)failure;

/// query user bird identify service subscriber infomation
/// - Parameters:
///   - success: success
///   - failure: failure
- (void)queryUserBirdServiceSubscribeInfo:(ThingSuccessID)success
                                  failure:(ThingFailureError)failure;

/// query device bird identify service subscriber infomation
/// - Parameters:
///   - success: success
///   - failure: failure
- (void)queryDeviceBirdServiceSubscribeInfoSuccess:(ThingSuccessID)success
                                           failure:(ThingFailureError)failure;

/// query all camera device in current home
/// - Parameters:
///   - homeId: home id
///   - success: success
///   - failure: failure
- (void)queryCameraDevice:(long long)homeId
                  success:(ThingSuccessID)success
                  failure:(ThingFailureError)failure;

/// query deivce has bird identify ability
/// - Parameters:
///   - success: success
///   - failure: failire
- (void)hasBirdIdentifyAbility:(ThingSuccessBOOL)success
                       failure:(ThingFailureError)failure;

/// query device has bird identify service
/// - Parameters:
///   - uuid: device model‘s  uuid
///   - success: success
///   - failure: failure
- (void)hasBirdIdentifyService:(NSString *)uuid
                       success:(ThingSuccessString)success
                       failure:(ThingFailureError)failure;


/// start identify birds
/// - Parameters:
///   - image: image
///   - identificateId: identificate id;【You can use current timestamp】
///   - success: success
///   - failure: failure
- (void)startIdentifyingBirdsImage:(nullable UIImage *)image
               identificateId:(nullable NSString *)identificateId
                      success:(ThingSuccessID)success
                      failure:(ThingFailureError)failure;

/// cancel indentify birds
/// - Parameters:
///   - identificateId: identificate id
- (void)cancelIdentifyIdentificateId:(NSString *)identificateId;

@end

NS_ASSUME_NONNULL_END
