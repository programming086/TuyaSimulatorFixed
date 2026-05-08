//
//  ThingSDKLogUtils.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>


@interface ThingSDKLogUtils : NSObject

// Prints bytes.
+ (void)thingsdk_logByte:(uint8_t *)bytes len:(int)len str:(NSString *)str;

+ (void)thingsdk_eventWithType:(NSString *)type attribute:(NSDictionary *)attribute;

+ (void)thingsdk_eventWithType:(NSString *)type attribute:(NSDictionary *)attribute identifier:(NSString *)identifier;

/* Starts an event that indicates a period.
 
 @params type The name of the event.
 @params attributes Common parameters of the event.
 @params infos The information about the event.
 @params identifier The ID of the event. The value is generated in the call of [xxx thing_apm_identifier].
 @params trackType The status of the tracked point. (trackType = @"begin" Begin / @"track" Send/ @"end" End)
 
 */
+ (void)thingsdk_eventWithType:(NSString *)type attribute:(NSDictionary *)attribute infos:(NSDictionary *)infos trackType:(NSString *)trackType identifier:(NSString *)identifier;

+ (NSString *)thingsdk_eventIdentifiter;


/// The data compression point.
///
/// @param type The unique name of the event.
/// @param attribute The parameters of the event.
/// @param identify The identifier of the event. The value is used to differentiate event tracking data.
/// @param maxCount The maximum number of entries that are compressed and collected. When the value is x, the handler is executed.
/// @param handler When the value is x, the handler is executed. The collected data is returned.
+ (void)thingsdk_eventWithType:(NSString *)type attribute:(NSDictionary *)attribute identify:(NSString *)identify maxCount:(int)maxCount handler:(NSDictionary *(^)(NSInteger index, NSArray * datas))handler;

@end
