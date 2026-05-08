
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Thing HomeKit device product info.
@interface ThingSmartHomeKitProductInfo : NSObject

/// Unique identification of the device.
@property (nonatomic, copy) NSString *UUID;

/// Identification of equipment categories.
@property (nonatomic, copy) NSString *productID;

/// Icon of the device.
@property (nonatomic, copy) NSString *iconURL;

/// Name of the device.
@property (nonatomic, copy) NSString *name;

@end

NS_ASSUME_NONNULL_END
