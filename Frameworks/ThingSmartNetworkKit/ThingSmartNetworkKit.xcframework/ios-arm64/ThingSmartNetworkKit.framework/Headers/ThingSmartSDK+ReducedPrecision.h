
#import <ThingSmartNetworkKit/ThingSmartNetworkKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSDK (ReducedPrecision)

/// Indicates whether the latitude and longitude should be represented with two decimal precision.
/// This property is read-only and its default value is NO.
@property (nonatomic, assign, readonly) BOOL latitudeLongitudeWithTwoDecimalPrecision;

/// Returns an NSNumber with the value of the original double, reduced to two decimal places if the latitudeLongitudeWithTwoDecimalPrecision property is set to YES.
/// @param originalValue The original double value.
/// @return An NSNumber with the reduced precision value.
- (NSNumber *)numberWithReducedPrecision:(double)originalValue;

/// Returns an NSString with the value of the original double, reduced to two decimal places if the latitudeLongitudeWithTwoDecimalPrecision property is set to YES.
/// @param originalValue The original double value.
/// @return An NSString with the reduced precision value.
- (NSString *)stringWithReducedPrecision:(double)originalValue;

/// Returns a double with the value of the original double, reduced to two decimal places if the latitudeLongitudeWithTwoDecimalPrecision property is set to YES.
/// @param originalValue The original double value.
/// @return A double with the reduced precision value.
- (double)doubleWithReducedPrecision:(double)originalValue;

@end

NS_ASSUME_NONNULL_END
