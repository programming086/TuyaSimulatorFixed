
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceKit/ThingSmartDeviceKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartThingLinkActivator : NSObject

/// Bind the ThingLink Device to home.
/// @param code The ThingLink Device QRCode content string.
/// @param homeId The home ID
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)bindThingLinkDeviceWithQRCode:(NSString *)code
                              homeId:(long long)homeId
                             success:(void (^)(ThingSmartDeviceModel *deviceModel))success
                             failure:(ThingFailureError)failure;

@end

NS_ASSUME_NONNULL_END
