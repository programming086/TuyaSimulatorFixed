
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Request model for fetch Thing HomeKit device product info.
@interface ThingSmartHomeKitProductInfoRequestModel : NSObject

/// Unique identification of the device.
@property (nonatomic, copy) NSString *UUID;

/// Identification of equipment categories.
@property (nonatomic, copy) NSString *productID;

@end

NS_ASSUME_NONNULL_END
