
#import <Foundation/Foundation.h>
@class ThingNetworkMetric;

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSInteger, ThingSmartNetworkQuality) {
    ThingSmartNetworkQualityUnknown,   // Initial unknown state
    ThingSmartNetworkQualityExcellent, // Excellent
    ThingSmartNetworkQualityGood,      // Good
    ThingSmartNetworkQualityModerate,  // Moderate
    ThingSmartNetworkQualityPoor,      // Poor (weak network)
    ThingSmartNetworkQualityOffline    // Offline
};

@protocol ThingNetworkStateObserver <NSObject>

@optional
/**
 * Called on the main thread whenever the network quality changes.
 * @param newQuality The new network quality level.
 * @param oldQuality The previous network quality level.
 */
- (void)networkMonitorDidUpdateNetworkQuality:(ThingSmartNetworkQuality)newQuality fromQuality:(ThingSmartNetworkQuality)oldQuality;

/**
 * @brief Called on the main thread whenever the network idle state changes.
 * @param isIdle YES if the network has become idle, NO if it has become busy.
 */
- (void)didUpdateIdleState:(BOOL)isIdle;

@end


@interface ThingNetworkMonitor : NSObject

+ (instancetype)sharedMonitor;

/// The current network quality level.
/// This property is Key-Value Observing (KVO) compliant.
@property (nonatomic, assign, readonly) ThingSmartNetworkQuality currentQuality;

/// Checks if the network request queue is currently idle.
@property (nonatomic, assign, readonly) BOOL isNetworkIdle;

- (void)recordRequestWithRTT:(NSTimeInterval)rtt error:(nullable NSError *)error;

- (void)addObserver:(id<ThingNetworkStateObserver>)observer;

- (void)removeObserver:(id<ThingNetworkStateObserver>)observer;

- (void)updateIdleState:(BOOL)newIdleState;

@end


NS_ASSUME_NONNULL_END
