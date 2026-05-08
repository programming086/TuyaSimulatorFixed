
#import <Foundation/Foundation.h>
#import "ThingSmartMatterDiscoveryModel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartMatterDiscoveryDelegate <NSObject>

/// Called when a Matter device is discovered.
/// - Parameter model: instance of `ThingSmartMatterDiscoveryModel`
- (void)discoveryedDevice:(ThingSmartMatterDiscoveryModel *)model;

@end

/// Discover the Matter device which wait to be configuration.
/// Notice: Currently, only Thing Matter device can be discovered. Third-party Matter device discovery will be supported later.
@interface ThingSmartMatterDiscoveryActivator : NSObject

@property (nonatomic, weak) id<ThingSmartMatterDiscoveryDelegate> delegate;

/// All Matter devices found in one scan.
/// Notice: It will be cleared the next time `- startDiscovery` is called
@property (nonatomic, strong , readonly) NSMutableArray <ThingSmartMatterDiscoveryModel *> *discoveryModelList;

/// Share instance.
+ (instancetype)sharedInstance;

/// Start discovering Matter device.
- (void)startDiscovery;

/// Stop discovering Matter device.
- (void)stopDiscovery;

@end

NS_ASSUME_NONNULL_END
