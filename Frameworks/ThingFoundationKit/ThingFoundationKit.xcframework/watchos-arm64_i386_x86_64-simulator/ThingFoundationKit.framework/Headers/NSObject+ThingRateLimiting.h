//
//  NSObject+ThingRateLimiting.h
//  ThingFoundationKit
//
//  Created by 
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (ThingRateLimiting)

/// Throttle: Limits the frequency of executing the given selector action. 
/// Ensures the action is not called more often than the specified duration.
/// @param action The selector to be throttled.
/// @param object The object to pass to the action.
/// @param duration The minimum time interval between successive calls.
- (void)thing_throttle:(nonnull SEL)action withObject:(nullable id)object duration:(NSTimeInterval)duration;

/// Debounce: Ensures the given selector action is only called after the specified duration 
/// has passed since the last attempt to call it. Useful to limit execution of actions that are 
/// triggered by fast, consecutive events.
/// @param action The selector to be debounced.
/// @param object The object to pass to the action.
/// @param duration The time interval to wait before executing the action after the last attempt.
- (void)thing_debounce:(nonnull SEL)action withObject:(nullable id)object duration:(NSTimeInterval)duration;

@end

NS_ASSUME_NONNULL_END
