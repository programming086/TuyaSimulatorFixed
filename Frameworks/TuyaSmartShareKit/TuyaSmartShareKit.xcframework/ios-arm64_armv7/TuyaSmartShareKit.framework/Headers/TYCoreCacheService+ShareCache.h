//
//  TYCoreCacheService+ShareCache.h
//  TuyaSmartShareKit
//
//  Created by  神威 on 2022/1/5.
//

#import <TuyaSmartDeviceCoreKit/TYCoreCacheService.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYCoreCacheService (ShareCache)

#pragma mark - shared device and group

/// Returns a list of shared devices.
/// The synchronous queue.
- (NSArray <TuyaSmartDeviceModel *> *)getSharedDeviceList;

/// Returns a list of shared groups.
/// The synchronous queue.
- (NSArray <TuyaSmartGroupModel *> *)getSharedGroupList;

/// Updates the device sharing list.
/// The asynchronous queue.
///
/// @param deviceList The device sharing list.
- (void)updateSharedDeviceList:(NSArray <TuyaSmartDeviceModel *> *)deviceList;

/// Updates the group sharing list.
/// The asynchronous queue.
///
/// @param groupList The group sharing list.
- (void)updateSharedGroupList:(NSArray <TuyaSmartGroupModel *> *)groupList;

/// This is a type of device that supports special sharing, such as sharing the home and sharing the device at the same time.
- (NSArray <NSString *> *)getSpecialSharedDevIds;



@end

NS_ASSUME_NONNULL_END
