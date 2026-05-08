
#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
NS_ASSUME_NONNULL_BEGIN


@class ThingSmartHomeKitActivator;
@protocol ThingSmartHomeKitActivatorDelegate <NSObject>

/// Configures callbacks of network status updates.
/// @param activator The instance.
/// @param deviceModel The device model.
/// @param error An error occurs while processing the request.
- (void)homeKitActivator:(ThingSmartHomeKitActivator *)activator didReceiveHomeKitDevice:(ThingSmartDeviceModel *)deviceModel error:(NSError *)error;
@end

@interface ThingSmartHomeKitActivator : NSObject

///Returns the singleton instance of the class.
+ (instancetype)sharedInstance __attribute__((unavailable("Must use -[[ThingSmartActivator alloc] init] instead.")));

@property (nonatomic, weak) id<ThingSmartHomeKitActivatorDelegate> delegate;

/// Returns the pairing token for HomeKit devices.
/// @param success Called when the task is finished. ThingSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getTokenSuccess:(ThingSuccessString)success failure:(ThingFailureError)failure;


/// Scans for HomeKit devices.
/// @param timeout The timeout value.
/// @param token The pairing token.
/// @param success Called when the task is finished. ThingSmartDeviceModel is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverHomeKitDeviceWithTimeout:(NSTimeInterval)timeout token:(NSString *)token success:(void (^)(ThingSmartDeviceModel *))success failure:(ThingFailureError)failure;


/// Scans for HomeKit devices.
/// @param timeout The timeout value.
/// @param success Called when the task is finished. ThingSuccessString is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)startDiscoverHomeKitDeviceWithTimeout:(NSTimeInterval)timeout success:(ThingSuccessString)success failure:(ThingFailureError)failure;


/// Returns device information by product ID.
/// @param productId The product ID.
/// @param success Called when the task is finished. ThingSuccessDict is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomekitDeviceInfoWithProductId:(NSString *)productId success:(ThingSuccessDict)success failure:(ThingFailureError)failure;


/// Returns device information by product ID.
/// @param productId The product ID.
/// @param uuid The device UUID.
/// @param success Called when the task is finished. ThingSuccessDict is returned.
/// @param failure Called when the task is interrupted by an error.
- (void)getHomekitDeviceInfoWithProductId:(NSString *)productId uuid:(nullable NSString *)uuid success:(ThingSuccessDict)success failure:(ThingFailureError)failure;


/// Stops scanning for devices.
- (void)stopDiscover;

@end

NS_ASSUME_NONNULL_END
