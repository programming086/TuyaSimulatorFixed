
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



@interface ThingAnalyticsKit : NSObject

/**
 * Key for the event identifier in the notification's userInfo dictionary.
 */
extern NSString *const ThingAnalyticsEventKey;

/**
 * Key for the event attributes in the notification's userInfo dictionary.
 */
extern NSString *const ThingAnalyticsAttributesKey;

/**
 * Notification name for Thing Analytics events.
 * The notification's userInfo dictionary contains the following keys:
 * - ThingAnalyticsEventKey: A string representing the event identifier.
 * - ThingAnalyticsAttributesKey: A dictionary containing event-specific attributes.
 *
 * Example:
 * NSDictionary *userInfo = @{
 *     ThingAnalyticsEventKey: @"user_signup",
 *     ThingAnalyticsAttributesKey: @{@"username": @"john_doe", @"age": @30}
 * };
 * [[NSNotificationCenter defaultCenter] postNotificationName:ThingAnalyticsEventNotification object:nil userInfo:userInfo];
 */
extern NSString *const ThingAnalyticsEventNotification;

/// This method should be called to enable or disable event tracking in the SDK.
/// - Parameter enable: YES to enable event tracking, NO to disable it.
+ (void)enable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
