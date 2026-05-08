
#import <Foundation/Foundation.h>
#import <HomeKit/HomeKit.h>
#import "ThingSmartHomeKitDevice.h"


NS_ASSUME_NONNULL_BEGIN

typedef void(^ThingSmartHomeKitDataCompletionHandler)(HMHomeManager * _Nullable manager);

typedef void(^ThingSmartHomeKitHomesUpdatedHandler)(HMHomeManager * _Nullable manager);

@interface ThingSmartHomeKitUtil : NSObject <HMHomeDelegate>

@property (nonatomic, strong, readonly) HMHomeManager *homeManager;

/// When HomeKit data has loaded.
/// @param completionHandler Call back until the homeManagerDidUpdateHomes: delegate method has been invoked.
/// @note If the homeManagerDidUpdateHomes: delegate method has been invoked, completionHandler will be called directly.
/// @note HomeKit data is empty when homeManager is created for the first time.
/// @note This method needs to be called once to ensure that the data can be retrieved successfully.
- (void)homeKitDataCompletionHandler:(ThingSmartHomeKitDataCompletionHandler)completionHandler;

/// When HomeKit homes has udpated.
/// @param updateHandler Call back handler.
/// @note When HomeKit  homes update, will call back this handler. see <HMHomeManagerDelegate>
- (void)homesUpdatedHandler:(ThingSmartHomeKitHomesUpdatedHandler)updateHandler;

/// The primary home in HomeKit.
/// @return the primary home
- (HMHome *)primaryHome;

/// Enumerate all Homes
/// @discussion When a new home manager is created, this array is inialized as an empty array. It is
/// not guaranteed to be filled with the list of homes, represented as HMHome objects,
/// until the homeManagerDidUpdateHomes: delegate method has been invoked.
/// @return Find all Homes  in HomeKit.
- (NSArray<HMHome *> *)homes;

/// Enumerate all Thing devices
/// @discussion When a new home manager is created, this array is inialized as an empty array. It is
/// not guaranteed to be filled with the list of devices, represented as ThingSmartHomeKitDevice objects,
/// until the homeManagerDidUpdateHomes: delegate method has been invoked.
/// @return Find all Thing device in HomeKit.
- (NSArray<ThingSmartHomeKitDevice *> *)devices;

/// Enumerate all Thing device.
/// @param manager Any HMHomeManager object.
/// @return Find all Thing device in HomeKit.
+ (NSArray<ThingSmartHomeKitDevice *> *)devicesForHomeManager:(HMHomeManager *)manager;

/// Enumerate Home devices
/// @return Find Home devices in HomeKit.
- (NSArray<ThingSmartHomeKitDevice *> *)devicesForHome:(HMHome *)home;

/// Enumerate Home devices and Matter devices
/// @return Find Home devices and Matter devices in HomeKit.
- (NSArray<ThingSmartHomeKitDevice *> *)thingAndMatterDevicesForHome:(HMHome *)home;

/// Adding accessory to primary home.
/// @param completion Accessory addition result call back handler.
- (void)addAccessoryToPrimaryHomeCompletionHandler:(void (^)(NSError * __nullable error))completion;

/// Display the HomeKit setup code of the device when adding accessory to primary home.
/// @param viewControllerDidLoad HomeKit Accessory setup view controller did load.
/// @param completion Accessory addition result call back handler.
- (void)addAccessoryToPrimaryHomeWithSetupViewControllerDidLoadHandler:(void (^)(void))viewControllerDidLoad completionHandler:(void (^)(NSError * __nullable error))completion;

/// Adding accessory to designated home.
/// @param home The designated home.
/// @param completion Accessory addition result call back handler.
- (void)addAccessoryToHome:(HMHome *)home completionHandler:(void (^)(NSError * __nullable error))completion;

/// Adding accessory to designated home.
/// @param home The designated home.
/// @param viewControllerDidLoad HomeKit Accessory setup view controller did load.
/// @param completion Accessory addition result call back handler.
- (void)addAccessoryToHome:(HMHome *)home setUpViewControllerDidLoadHandler:(void (^)(void))viewControllerDidLoad completionHandler:(void (^)(NSError * __nullable error))completion;

/// remove accessory from designated home.
/// @param accessory The accessory to be removed.
/// @param home The designated home.
/// @param completion Call back handler.
- (void)removeAccessory:(HMAccessory *)accessory fromHome:(HMHome *)home completionHandler:(void (^)(NSError * __nullable error))completion;

@end

NS_ASSUME_NONNULL_END
