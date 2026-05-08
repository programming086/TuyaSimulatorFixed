//
//  ThingSmartHome+Weather.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import "ThingSmartHome.h"

@class ThingSmartWeatherModel;
@class ThingSmartWeatherSketchModel;
@class ThingSmartWeatherOptionModel;

@interface ThingSmartHome (Weather)

/// The home location.
- (NSString *)geoName;

/// Returns brief weather parameters for the home. This request also returns brief weather parameters for the city where the home is located, such as the city name, weather conditions for the day (such as sunny, cloudy, and rainy), and weather picture information.
/// @param success Called when the task is finished. ThingSmartWeatherSketchModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomeWeatherSketchWithSuccess:(void(^)(ThingSmartWeatherSketchModel *))success
                                failure:(ThingFailureError)failure;


/// Returns detailed parameters of home weather, such as temperature, humidity, UV index, and air quality.
///
/// optionModel can be set to nil. If so, the parameter settings of the last successful request are returned. If only one unit setting is changed for the request, the remaining parameter settings of the last successful request are returned.
///
/// The functions that are enabled by weather services can vary based on different regions. Therefore, the response parameters may differ from region to region. In particular, if the current home account is located in China, information about the wind speed and barometric pressure is not returned.
///
/// @param optionModel The configurations of weather parameter units.
/// @param success Called when the task is finished. A list of ThingSmartWeatherModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomeWeatherDetailWithOption:(ThingSmartWeatherOptionModel *)optionModel
                         success:(void(^)(NSArray<ThingSmartWeatherModel *> *))success
                         failure:(ThingFailureError)failure;

@end
