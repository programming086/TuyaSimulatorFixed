//
//  NSDate+TYOffset.h
//  TYFoundationKit
//
//  Created by TuyaInc on 2019/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (TYOffset)

/// offset years from the current date
/// @param numYears years
- (NSDate *)ty_offsetYears:(int)numYears;

/// offset years from the specific date, if specific date is nil, return nil
/// @param numYears years
/// @param fromDate specific date
+ (NSDate *)ty_offsetYears:(int)numYears fromDate:(NSDate *)fromDate;

/// offset months from the current date
/// @param numMonths months
- (NSDate *)ty_offsetMonths:(int)numMonths;

/// offset months from the specific date, if specific date is nil, return nil
/// @param numMonths months
/// @param fromDate specific date
+ (NSDate *)ty_offsetMonths:(int)numMonths fromDate:(NSDate *)fromDate;

/// offset days from the current date
/// @param numDays days
- (NSDate *)ty_offsetDays:(int)numDays;

/// offset days from the specific date, if specific date is nil, return nil
/// @param numDays days
/// @param fromDate specific date
+ (NSDate *)ty_offsetDays:(int)numDays fromDate:(NSDate *)fromDate;

/// offset hours from the current date
/// @param numHours hours
- (NSDate *)ty_offsetHours:(int)numHours;

/// offset hours from the specific date, if specific date is nil, return nil
/// @param numHours hours
/// @param fromDate specific date
+ (NSDate *)ty_offsetHours:(int)numHours fromDate:(NSDate *)fromDate;

/// offset minutes from the current date
/// @param numMinutes minutes
- (NSDate *)ty_offsetMinutes:(int)numMinutes;

/// offset minutes from the specific date, if specific date is nil, return nil
/// @param numMinutes minutes
/// @param fromDate specific date
+ (NSDate *)ty_offsetMinutes:(int)numMinutes fromDate:(NSDate *)fromDate;

/// offset seconds from the current date
/// @param numSeconds seconds
- (NSDate *)ty_offsetSeconds:(int)numSeconds;

/// offset seconds from the specific date, if specific date is nil, return nil
/// @param numSeconds seconds
/// @param fromDate specific date
+ (NSDate *)ty_offsetSeconds:(int)numSeconds fromDate:(NSDate *)fromDate;

#pragma mark - time interval

/// The start of the current minute, i.e. 0 seconds
- (NSDate *_Nullable)ty_startOfCurrentMinute;

/// The end of the current minute, i.e. 59 seconds
- (NSDate *_Nullable)ty_endOfCurrentMinute;

/// Range of the current minute, including start and end
- (NSArray<NSDate*> *_Nullable)ty_secondsDurationsAtCurrentMinute;

/// The start of the current hour, i.e. 0 minutes and 0 seconds
- (NSDate *_Nullable)ty_startOfCurrentHour;

/// The end of the current hour, i.e. 59 minutes and 59 seconds
- (NSDate *_Nullable)ty_endOfCurrentHour;

/// Range of the current hour, including start and end
- (NSArray<NSDate*> *_Nullable)ty_minuteDurationsAtCurrentHour;

/// The start of the current day, i.e. 00:00:00
- (NSDate *_Nullable)ty_startOfCurrentDay;

/// The end of the  current day, i.e. 23:59:59
- (NSDate *_Nullable)ty_endOfCurrentDay;

/// Range for the current day, including start and end
- (NSArray<NSDate*> *_Nullable)ty_hourDurationsAtCurrentDay;

/// The start of the current month, e.g. January 1st 00:00:00
- (NSDate *_Nullable)ty_startOfCurrentMonth;

/// The end of the current month, e.g. January 31st 23:59:59
- (NSDate *_Nullable)ty_endOfCurrentMonth;

/// Range for the current month, including start and end
- (NSArray<NSDate*> *_Nullable)ty_dayDurationsAtCurrentMonth;

/// The start of the current year, i.e. January 1st 00:00:00
- (NSDate *_Nullable)ty_startOfCurrentYear;

/// The end of the current year, i.e. December 31st 23:59:59
- (NSDate *_Nullable)ty_endOfCurrentYear;

/// Range for the current year, including start and end
- (NSArray<NSDate*> *_Nullable)ty_monthDurationsAtCurrentYear;

/// Determines whether the current date is included in the specified time interval
/// @param startDate specified start date
/// @param endDate specified end date
- (BOOL)ty_containtsFromStartDate:(NSDate *_Nonnull)startDate endDate:(NSDate *_Nonnull)endDate;

@end

NS_ASSUME_NONNULL_END
