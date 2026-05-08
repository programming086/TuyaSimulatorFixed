
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartHomeKitCheckUtil : NSObject

/// Check HomeKit accessory setup view controller did load.
/// @param viewControllerDidLoad HomeKit accessory setup view controller did load call back.
- (void)startToCheckHomekitAccessorySetupViewControllerDidLoadHandler:(void (^)(void))viewControllerDidLoad;

/// Stop check.
- (void)stopCheckHomekitAccessoryAdding;

@end

NS_ASSUME_NONNULL_END
