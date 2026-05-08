
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartDevice (ThingSmartOutdoor)

/// send DP with code
/// @param code DP code
/// @param DPValue the DP original value (NSString, NSNumber, NSDictionary)
/// @param success Called when the task finishes successfully.
/// @param failure Called when the task is interrupted by an error.
- (void)tsod_publishDPWithCode:(NSString *)code
                       DPValue:(id)DPValue
                       success:(nullable ThingSuccessHandler)success
                       failure:(nullable ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
