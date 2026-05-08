//
//  TYBLEAudioWeatherModel.h
//  TuyaSmartBLEKit
//
//  Created by tjl on 2021/7/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYBLEAudioDailyDayModel : NSObject

@property (nonatomic, assign) int weatherType;

@property (nonatomic, assign) int lowTemperature;

@property (nonatomic, assign) int highTemperature;

@property (nonatomic, copy) NSString *date;

@property (nonatomic, copy) NSString *day;

@property (nonatomic, copy) NSString *descriptionContent;

@end

@interface TYBLEAudioWeatherModel : NSObject

@property (nonatomic, copy) NSString *mainTitle;

@property (nonatomic, copy) NSString *subTitle;
// 0 - centigrade, 1 - Fahrenheit degree.
@property (nonatomic, assign) int temperatureUnit;
// Whether contain current temperature ?
@property (nonatomic, assign) BOOL flag;

@property (nonatomic, assign) int weatherType;

@property (nonatomic, assign) int currentTemperature;

@property (nonatomic, assign) int lowTemperature;

@property (nonatomic, assign) int highTemperature;

@property (nonatomic, copy) NSString *ttsContent;

@property (nonatomic, copy) NSString *descriptionContent;

@property (nonatomic, copy) NSMutableArray<TYBLEAudioDailyDayModel *> *dailyDayArray;

@end

NS_ASSUME_NONNULL_END
