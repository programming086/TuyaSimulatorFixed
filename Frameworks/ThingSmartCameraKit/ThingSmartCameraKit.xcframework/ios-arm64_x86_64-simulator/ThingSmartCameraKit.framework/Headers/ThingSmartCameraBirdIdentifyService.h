
#import <UIKit/UIKit.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    ThingCameraBirdIdentifyError_IdentifyFailed         = -2900,
    ThingCameraBirdIdentifyError_ImageUploadFail        = -2901,
    ThingCameraBirdIdentifyError_GetImageSignFail       = -2902,
    ThingCameraBirdIdentifyError_SnapShootFail          = -2903,
    ThingCameraBirdIdentifyError_IdentifyResultFail     = -2904,
    ThingCameraBirdIdentifyError_IdentifyTimeOut        = -2905,
    ThingCameraBirdIdentifyError_HasNoService           = -2910
}ThingCameraBirdIdentifyError;


@interface ThingBirdFetchFeatureFileUploadingSignParams : NSObject
@property (nonatomic, copy, nullable) NSString *businessType;
@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, copy) NSString *fileName;
@property (nonatomic, assign) long long fileSize;
@property (nonatomic, copy, nullable) NSString *contentType;
@property (nonatomic, assign) BOOL needSecret;
@property (nonatomic, copy) NSString *requestNo;

@end

@interface ThingBirdFetchFeatureFileUploadingSignResult : NSObject

@property (nonatomic, copy) NSString *bucket;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *filePath;
@property (nonatomic, copy) NSString *secretKey;
@property (nonatomic, copy) NSDictionary *headers;
@property (nonatomic, copy) NSString *requestNo;

- (instancetype)initSingResult:(NSDictionary *)dic;

@end

@interface ThingBirdIdentifyAIFeatureParams : NSObject

@property (nonatomic, copy) NSString *deviceId;
@property (nonatomic, copy) NSString *bucket;
@property (nonatomic, copy) NSString *filePath;
@property (nonatomic, copy) NSString *requestNo;

@end

typedef void (^ThingBirdAIFeatureFileRequestSuccess)(ThingBirdFetchFeatureFileUploadingSignResult *signResult);

@interface ThingSmartCameraBirdIdentifyService : ThingSmartRequest


/// query video days
/// - Parameters:
///   - devId: device id
///   - startDateString: start date string, such as "2025-03-08"
///   - days: days
///   - success: success
///   - failure: failure
- (void)queryVideoDays:(NSString *)devId
             startDate:(NSString *)startDateString
               preDays:(NSInteger)days
               success:(ThingSuccessID)success
               failure:(ThingFailureError)failure;

/// query bird category
/// - Parameters:
///   - devId: device id
///   - startDateString: start date string, such as "2025-03-08"
///   - endDateString: end date string, such as "2025-03-09"
///   - success: success
///   - failure: failure
- (void)queryBirdCategory:(NSString *)devId
             startDate:(NSString *)startDateString
                endDate:(NSString *)endDateString
                  success:(ThingSuccessID)success
                  failure:(ThingFailureError)failure;

/// query bird video message
/// - Parameters:
///   - devId: device id
///   - startTime: start time; unit:second
///   - endTime: end time; unit:second
///   - pageNum: page number
///   - pageSize: page size
///   - aiBird: is it only necessary to query the videos of bird detection
///   - birdCode: bird code 【nullable】
///   - success: success
///   - failure: failure
- (void)queryBirdVideoMesssage:(NSString *)devId
                     startTime:(NSTimeInterval)startTime
                       endTime:(NSTimeInterval)endTime
                       pageNum:(NSInteger)pageNum
                      pageSize:(NSInteger)pageSize
                        aiBird:(BOOL)aiBird
                        birdCode:(NSString *)birdCode
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
///   - devId: devcie id
///   - success: success
///   - failure: failure
- (void)queryDeviceBirdServiceSubscribeInfo:(NSString *)devId
                                    success:(ThingSuccessID)success
                                    failure:(ThingFailureError)failure;

/// query all camera device in current home
/// - Parameters:
///   - homeId: home id
///   - success: success
///   - failure: failure
- (void)queryCameraDevice:(long long)homeId
                  success:(ThingSuccessID)success
                  failure:(ThingFailureError)failure;

/// query device bird identify ability
/// - Parameters:
///   - devId: device id
///   - success: success
///   - failure: failure
- (void)fetchDeviceAdvancedAbilityConfigWithDevId:(NSString *)devId
                                          success:(ThingSuccessID)success
                                          failure:(ThingFailureError)failure;

/// check bird identify service
/// - Parameters:
///   - devId: device
///   - uuid: device uuid 【get devcie uuid frme deviceModel】
///   - serviceCode: servcieCode
///   - success: success
///   - failure: failure
- (void)checkBirdCloudServiceState:(NSString *)devId
                              uuid:(NSString *)uuid
                       serviceCode:(NSString *)serviceCode
                           success:(ThingSuccessID)success failure:(ThingFailureError)failure;

- (void)fetchFeatureFileUploadingSignWithParams:(ThingBirdFetchFeatureFileUploadingSignParams *)params success:(ThingBirdAIFeatureFileRequestSuccess)success failure:(ThingFailureError)failure;

- (void)identifyAIFeatureWithParams:(ThingBirdIdentifyAIFeatureParams *)params success:(ThingSuccessID)success failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
