
#import <Foundation/Foundation.h>
#import <ThingSmartBaseKit/ThingSmartBaseKit.h>

@interface ThingSmartCloudService : ThingSmartRequest

@property (nonatomic, strong) NSTimeZone *timeZone;

- (void)requestCloudStorageStateWithParams:(NSDictionary *)params success:(ThingSuccessString)success failure:(ThingFailureError)failure;

- (void)requestCloudStorageCountWithDeviceId:(NSString *)devId success:(ThingSuccessList)success failure:(ThingFailureError)failure;

- (void)requestCloudStorageSecretWithDeviceId:(NSString *)devId success:(ThingSuccessString)success failure:(ThingFailureError)failure;

- (void)requestCloudStoragePrefixsWithParams:(NSDictionary *)params success:(ThingSuccessID)success failure:(ThingFailureError)failure;

- (void)requestCloudStorageTimelineWithParams:(NSDictionary *)params success:(ThingSuccessList)success failure:(ThingFailureError)failure;

- (void)requestCloudStorageEventWithParams:(NSDictionary *)params success:(ThingSuccessList)success failure:(ThingFailureError)failure;

- (void)requestCloudStorageAIEventWithParams:(NSDictionary *)params success:(ThingSuccessList)success failure:(ThingFailureError)failure;

- (void)requestCloudStorageAuthorityWithDeviceId:(NSString *)devId success:(ThingSuccessID)success failure:(ThingFailureError)failure;

- (void)deleteCloudVideoWithDeviceId:(NSString *)deviceId startTime:(NSInteger)startTime endTime:(NSInteger)endTime success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

- (void)deleteAllDayCloudVideoWithDeviceId:(NSString *)deviceId startTime:(NSInteger)startTime endTime:(NSInteger)endTime success:(ThingSuccessHandler)success failure:(ThingFailureError)failure;

/// V2
- (void)requestCloudStorageAuthorityWithDeviceId:(NSString *)devId bukets:(NSString*)bukets success:(ThingSuccessID)success failure:(ThingFailureError)failure;

/// AI Cloud
- (void)enableAIDetect:(NSString *)devId
                 state:(BOOL)switchState
               success:(ThingSuccessBOOL)success
               failure:(ThingFailureError)failure;

- (void)queryAIDetectConfig:(NSString *)devId
                    success:(ThingSuccessID)success
                    failure:(ThingFailureError)failure;

- (void)updateIPCAIAnalyzeType:(NSString *)devId
                        aiCode:(NSString *)aiCode
                enableState:(BOOL)enableState
                    success:(void (^)(BOOL result))success
                       failure:(void (^)(NSError *error))failure;




@end

