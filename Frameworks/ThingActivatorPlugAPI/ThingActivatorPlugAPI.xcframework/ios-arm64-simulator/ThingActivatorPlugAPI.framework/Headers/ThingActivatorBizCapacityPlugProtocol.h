
#import <Foundation/Foundation.h>
#import "ThingActivatorLinkModeDefine.h"
#import "ThingActivatorLinkModeInfo.h"

NS_ASSUME_NONNULL_BEGIN
@class ThingSmartDeviceModel, ThingSmartDeviceCategoryModel;
/*
 * his protocol is called by the business side to provide an interface to the pairing network capability
 */
@protocol ThingActivatorBizCapacityPlugProtocol <NSObject>
/*
 * Select gateway
 * @param linkMode zigbee or 433
 * @param selectHandler gateway selection callback
 * @param configHandler gateway configuration callback
 * @param cancelBlcok cancellation callback
 */
- (void)showGatewaySelectAlertView:(ThingLinkMode)linkMode
                     selectGateway:(void(^)(ThingSmartDeviceModel * _Nullable selectModel))selectHandler
                     configGateway:(void(^)(ThingSmartDeviceCategoryModel * _Nullable categoryModel))configHandler
                       cancelBlock:(dispatch_block_t)cancelBlock;


/*
 * Register a custom pairing process
 * @param factoryInfos Pass in an array of custom process constructs.
 * @discussion Support to add LinkMode corresponding to the pairing process, replace the existing process, do not support the deletion of the process
 * Currently supported LinkMode. https://wiki.thing-inc.com:7799/page/1537370846127988811
 * Example:
 *
 * {
 *  // Add a new router pairing process
 *  ThingActivatorLinkModeInfo *broadband = [[ThingActivatorLinkModeInfo alloc] init];
 *  broadband.linkModeKey = @"broadband";
 *  broadband.factoryClass = NSClassFromString(@"ThingActivatorBroadbandFactory");
 *
 *  // Replacement of the EZ distribution process
 *  ThingActivatorLinkModeInfo *ez = [[ThingActivatorLinkModeInfo alloc] init];
 *  ez.linkModeValue = ThingLinkModeEZ;
 *  ez.linkModeKey = NSStringFromTYLinkMode(ThingLinkModeEZ);
 *  ez.factoryClass = NSClassFromString(@"ThingActivatorCustomEZFactory");
 *
 *  [impl registerLinkModeFactory:@[broadband, ez]];
 * }
 */
- (void)registerLinkModeFactory:(NSArray <ThingActivatorLinkModeInfo*>*)factoryInfos;

/*
 * Starts the process with the specified linkMode.
 * @param factoryInfo The linkMode information to start the process.
 * @discussion Support to open a custom added pairing process, open a public supported pairing process, open a public supported pairing process after replacing the custom process.
 * 1. To open the allocation process corresponding to the newly added linkMode, first call registerLinkModeFactory: interface to register, * and then call startActivator.
 * Then call startActivatorProcessWithLinkMode: to start the process.
 *
 * 2, open the project has been supported by the linkMode corresponding to the pairing process, directly call startActivatorProcessWithLinkMode: start pairing process
 *
 *
 * Example:
 * {
 *
 *  // Add a new pairing process
 *  ThingActivatorLinkModeInfo *custom = [[ThingActivatorLinkModeInfo alloc] init];
 *  custom.linkModeKey = @"customLinkMode";
 *  custom.factoryClass = NSClassFromString(@"ThingActivatorCustomFactory");
 *  [impl registerLinkModeFactory:@[custom]];
 *  // Start the pairing process
 *  ThingActivatorProcessBuilder *builder = [[ThingActivatorProcessBuilder alloc] init];
 *  builder.linkModeKey = @"customLinkMode";
 *  [impl startActivatorProcessWithBuilder:builder];
 *
 *
 *  // Start the project's manual pairing process, with the entry reference being the third-level category detail categoryModel.
 *  ThingActivatorProcessBuilder *builder = [[ThingActivatorProcessBuilder alloc] init];
 *  builder.categoryModel = categoryModel;
 *  [impl startActivatorProcessWithBuilder:builder];
 *
 *  // // Enable a non-manual distribution process (not clicking in from a tertiary category)
 *  ThingActivatorProcessBuilder *builder = [[ThingActivatorProcessBuilder alloc] init];
 *  builder.linkModeValue = ThingLinkModeSUBPanel;
 *  [impl startActivatorProcessWithBuilder:builder];
 * }
 *
 */
- (void)startActivatorProcessWithBuilder:(ThingActivatorProcessBuilder *)builder;

@end

NS_ASSUME_NONNULL_END
