//
//  ThingSmartWeatherOptionModel.h
//  ThingSmartDeviceKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    ThingSmartWeatherOptionPressureUnit_unknown = 0,
    ThingSmartWeatherOptionPressureUnit_hPa = 1,
    ThingSmartWeatherOptionPressureUnit_inHg = 2,
    ThingSmartWeatherOptionPressureUnit_mmHg = 3,
    ThingSmartWeatherOptionPressureUnit_mb = 4,
} ThingSmartWeatherOptionPressureUnit;

typedef enum : NSUInteger {
    ThingSmartWeatherOptionWindSpeedUnit_unknown = 0,
    ThingSmartWeatherOptionWindSpeedUnit_mph = 1,
    ThingSmartWeatherOptionWindSpeedUnit_m_s = 2,// m/s
    ThingSmartWeatherOptionWindSpeedUnit_kph = 3,
    ThingSmartWeatherOptionWindSpeedUnit_km_h = 4// km/h
} ThingSmartWeatherOptionWindSpeedUnit;

typedef enum : NSUInteger {
    ThingSmartWeatherOptionTemperatureUnit_unknown = 0,
    ThingSmartWeatherOptionTemperatureUnit_Centigrade = 1,// °C
    ThingSmartWeatherOptionTemperatureUnit_Fahrenheit = 2,// °F
} ThingSmartWeatherOptionTemperatureUnit;

NS_ASSUME_NONNULL_BEGIN

/// Returns the requested home weather entries.
@interface ThingSmartWeatherOptionModel : NSObject

/// The barometric unit.
@property (nonatomic, assign) ThingSmartWeatherOptionPressureUnit pressureUnit;

/// The wind speed unit.
@property (nonatomic, assign) ThingSmartWeatherOptionWindSpeedUnit windspeedUnit;

/// The temperature unit.
@property (nonatomic, assign) ThingSmartWeatherOptionTemperatureUnit temperatureUnit;

/// The number of requests for weather details. If you do not set the value, all requests are returned.
@property (nonatomic, assign) NSInteger limit;

@end

NS_ASSUME_NONNULL_END
