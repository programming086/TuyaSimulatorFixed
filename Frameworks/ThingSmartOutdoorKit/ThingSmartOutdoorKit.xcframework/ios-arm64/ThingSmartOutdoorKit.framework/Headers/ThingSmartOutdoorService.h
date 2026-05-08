
#import <Foundation/Foundation.h>
#import <ThingSmartNetworkKit/ThingSmartNetworkKit.h>


NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(OutdoorService)
@interface ThingSmartOutdoorService : ThingSmartRequest

+ (void)fetchRankingInfoWithSuccess:(ThingSuccessInt)success failure:(ThingFailureError)failure;

+ (void)updateRankingInfoWithJoin:(NSInteger)join Success:(ThingSuccessBOOL)success failure:(ThingFailureError)failure;

+ (void)fetchRequestSiriWithApple:(NSString *)appId success:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure;

/** 
 * params structure：
 * - deviceId
 * - coordinate
 * - proSource
*/
+ (void)fetchRequestLocationWithDeviceId:(NSDictionary *)params success:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure;

/** 
 * params structure：
 * - coordinate
 * - originLon
 * - originLat
 * - destinationLon
 * - destinationLat
*/
+ (void)fetchRequestDistanceCoordinateType:(NSDictionary *)params success:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure;

+ (void)fetchGetPanelInfo:(NSString *)uiId success:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure;

/**
 * params structure：
 * - codes
 * - deviceId
*/
+ (void)fetchRequestProductAbilityWithDeviceID:(NSDictionary *)params success:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure;

/**
 * params structure：
 * - homeId
 * - cardIds
 * - weatherInfo : { "gid" : "" , "lat" : "" , "lon" : "",  "limit" : "" }
 * - options : { "tempUnit" : "" }
*/
+ (void)fetchrequestWeatherInfoWithCoordinate:(NSDictionary *)params success:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure;

/**
 * params structure：
 * - codes : "[\"w.thigh\",\"w.tlow\",\"w.conditionNum\",\"w.pop\",\"w.hour.7\"]"
 * - lat
 * - lon
*/
+ (void)fetchrequestWeatherHourForecastWithCoordinate:(NSDictionary *)params success:(nullable ThingSuccessID)success failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
