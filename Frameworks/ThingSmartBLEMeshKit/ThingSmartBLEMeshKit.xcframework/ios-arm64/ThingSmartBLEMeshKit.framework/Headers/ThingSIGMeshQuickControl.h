
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSIGMeshQuickControl : NSObject

/// Set the broadcast duration.
/// - Parameter duration: duration
- (void)setAdvDuration:(CGFloat)duration;

/// Turn on the device.
/// - Parameter mac: The device's mac.
- (void)on:(NSString *)mac;

/// Shut down the device.
/// - Parameter mac: The device's mac.
- (void)off:(NSString *)mac;

/// Reverse switch state.
/// - Parameter mac: The device's mac.
- (void)reverse:(NSString *)mac;

/// Make the device flash.
/// - Parameters:
///   - mac: The device's mac.
///   - duration: Flash duration.
- (void)flash:(NSString *)mac duration:(NSInteger)duration;

@end

NS_ASSUME_NONNULL_END
