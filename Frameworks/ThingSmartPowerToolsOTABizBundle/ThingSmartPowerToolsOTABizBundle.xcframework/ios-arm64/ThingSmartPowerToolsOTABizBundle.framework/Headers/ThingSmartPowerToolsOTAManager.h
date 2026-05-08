//
//  ThingSmartPowerToolsOTAManager.h
//
//  Auto-Created on 2022/05/19.
//  Copyright © 2022年 Tuya. All rights reserved.
//

#import "ThingSmartPowerToolsOTAConstant.h"

#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartFirmwareUpgradeModel.h>


NS_ASSUME_NONNULL_BEGIN

@class ThingSmartPowerToolsOTATransferProgress;

typedef void(^ThingSmartPowerToolsOTATransferProgressBlock)(ThingSmartPowerToolsOTATransferProgress *);

/**
 * Result class for version check, containing information about necessary and all firmware upgrades.
 */
@interface ThingSmartPowerToolsOTACheckVersionResult : NSObject
@property (nonatomic, strong) NSArray<ThingSmartFirmwareUpgradeModel *> *needUpgrades; ///< List of firmware that need upgrades
@property (nonatomic, strong) NSArray<ThingSmartFirmwareUpgradeModel *> *all; ///< List of all firmware
@end

/**
 * Progress class for download operations.
 */
@interface ThingSmartPowerToolsOTADownloadProgress : NSObject
@property (nonatomic, strong) NSNumber *progress; ///< Download progress
@end

/**
 * Result class for download operations, containing the file path and upgrade package data.
 */
@interface ThingSmartPowerToolsOTADownloadResult : NSObject
@property (nonatomic, strong) NSString *filePath; ///< Path to the downloaded file
@property (nonatomic, strong) NSData *upgradePackage; ///< Data of the upgrade package
@end

/**
 * Progress class for transfer operations.
 */
@interface ThingSmartPowerToolsOTATransferProgress : NSObject
@property (nonatomic, strong) NSString *devId; ///< Device ID
@property (nonatomic, strong) NSNumber *progress; ///< Transfer progress
@end

/**
 * Manager class for power tools OTA operations, providing firmware version check, download, and transfer functionalities.
 */
@interface ThingSmartPowerToolsOTAManager : NSObject

/**
 * Check the firmware version of a device.
 * @param devId Device ID ( Power Tools）
 * @param success Callback on successful version check, returning the result
 * @param fail Callback on failure, returning an error
 */
- (void)checkVersion:(NSString*)devId
             success:(void(^)(ThingSmartPowerToolsOTACheckVersionResult *result))success
                fail:(void(^_Nullable)(ThingSmartPowerToolsOTAError *error))fail;

/**
 * Download an upgrade package.
 * @param upgradeInfo upgradeInfo Information about the upgrade. This parameter should come from the
 * needUpgrades property of the ThingSmartPowerToolsOTACheckVersionResult returned by the checkVersion:success:fail: method.
 * @param progress Callback for download progress
 * @param success Callback on successful download, returning the result
 * @param fail Callback on failure, returning an error
 */
- (void)downloadUpgradePackageWithUpgradeInfo:(ThingSmartFirmwareUpgradeModel*)upgradeInfo
                                     progress:(void(^_Nullable)(ThingSmartPowerToolsOTADownloadProgress *))progress
                                      success:(void(^)(ThingSmartPowerToolsOTADownloadResult *))success
                                         fail:(void(^_Nullable)(ThingSmartPowerToolsOTAError *error))fail;

/**
 * Transfer an upgrade package to a device.
 * @param upgradePackage Data of the upgrade package. This parameter should come from the
 * upgradePackage property of the ThingSmartPowerToolsOTADownloadResult returned by the
 * downloadUpgradePackageWithUpgradeInfo:progress:success:fail: method.
 * @param pid Product ID ( Power Tools）
 * @param devId Device ID ( Battery）
 * @param upgradeInfo Information about the upgrade
 * @param progress Callback for transfer progress
 * @param success Callback on successful transfer
 * @param fail Callback on failure, returning an error
 */
- (void)transferUpgradePackage:(NSData*)upgradePackage
                           pid:(NSString*)pid
                         devId:(NSString*)devId
                   upgradeInfo:(ThingSmartFirmwareUpgradeModel*)upgradeInfo
                      progress:(ThingSmartPowerToolsOTATransferProgressBlock _Nullable)progress
                       success:(void(^)(BOOL success))success
                          fail:(void(^_Nullable)(ThingSmartPowerToolsOTAError *error))fail;

@end

NS_ASSUME_NONNULL_END
