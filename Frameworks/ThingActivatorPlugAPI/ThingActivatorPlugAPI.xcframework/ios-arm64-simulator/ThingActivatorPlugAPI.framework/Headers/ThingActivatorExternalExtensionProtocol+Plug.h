
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ThingActivatorResultModel.h"

NS_ASSUME_NONNULL_BEGIN
/*
 * This protocol is deprecated
 */
@protocol ThingActivatorExternalExtensionProtocol <NSObject>

@optional
/// Back action from category View Controller
/// Implement this when additional operations are needed
- (BOOL)categoryViewControllerCustomBackAction;

/// Go to custom result display view for network configuration success page
/// @param resultList List of networked devices
/// @param userInfo User info
/// Current business logic: partially successful auto-discovery will redirect to the result display page. If returning to network configuration is needed, simply return to the previous level. Other return logics can be handled freely.
/// If there are still some devices not yet networked on the auto-discovery page, userInfo = {@"hasUnactive" : @(1)}
- (void)gotoCustomResultPage:(NSArray<ThingActivatorResultModel *> *_Nonnull)resultList userInfo:(NSDictionary * _Nullable)userInfo;

/// Update resultList, only used for EZ
/// @param resultList New networked devices
- (void)updateResultLsit:(NSArray<ThingActivatorResultModel *> *_Nullable)resultList;

/// Go to custom failure feedback page
/// @param sourceType Source type 1: pop-up window 2: manual
/// @param userInfo Custom info
/// userInfo = @{@"linkMode":@(linkModeEZ),@"linkModel":linkModel,@"bluetoothModel",bluetoothModel,...}
- (void)gotoCustomFailurePage:(NSInteger)sourceType userInfo:(NSDictionary * _Nullable)userInfo;

/// Get the default serial index
/// Implement this when additional operations are needed
/// Custom default room selection
- (NSInteger)getDefaultIndexOfDeviceResult;

/// Go to custom View Controller from different pages
/// Implement this when additional operations are needed
/// Redirect to custom page from network configuration completion page, defaults to home page opening the device panel
/// @param userInfo Passable fields
///     1. Is it a virtual device: isVirtualDevice: NSNumber, not passing indicates real device
///     2. Device array: deviceArray: [ThingActivatorResultModel]
///     3. Number of devices failed to add: failureDeviceCount: NSNumber
///     4. Error prompts for devices failed to add: failureList: [ThingSmartActivatorModel]
///     5. Device ID array: devIDList: [NSString]
/// @return YES to not return to home page upon completion of network configuration; NO for default behavior (return to home page, if only one device, will then jump to panel)
- (BOOL)gotoCustomVC:(NSDictionary *_Nullable)userInfo;

@end
NS_ASSUME_NONNULL_END

