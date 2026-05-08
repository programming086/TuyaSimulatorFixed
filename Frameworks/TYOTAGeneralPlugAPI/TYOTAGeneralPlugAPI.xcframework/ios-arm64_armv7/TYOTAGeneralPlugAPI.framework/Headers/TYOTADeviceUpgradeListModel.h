//
//  TYOTADeviceUpgradeListModel.h
//  TYOTAGeneralModule
//
//  Created by 萧然 on 2021/11/22.
//

#import <Foundation/Foundation.h>
#import <YYModel/YYModel.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartFirmwareUpgradeModel.h>
#import <TuyaSmartDeviceCoreKit/TuyaSmartDevice.h>

typedef enum : NSUInteger {
    TYOTADeviceUpgradeListDeviceStatusDefault,
    TYOTADeviceUpgradeListDeviceStatusUpgrading,
    TYOTADeviceUpgradeListDeviceStatusRetry,
    TYOTADeviceUpgradeListDeviceStatusSuccess
} TYOTADeviceUpgradeListDeviceStatus;

NS_ASSUME_NONNULL_BEGIN

@interface TYOTADeviceUpgradeListModel : NSObject <YYModel>

/// 设备 id
@property (nonatomic, copy) NSString *devId;

/// 设备 icon
@property (nonatomic, copy) NSString *icon;

/// 设备 name
@property (nonatomic, copy) NSString *name;

/// 升级固件 List
@property (nonatomic, strong) NSArray<TuyaSmartFirmwareUpgradeModel *> *upgradeList;

/// 对应的首页缓存设备（本地使用）
@property (nonatomic, strong) TuyaSmartDevice *device;

/// 有新版本的固件 List
@property (nonatomic, strong) NSMutableArray<TuyaSmartFirmwareUpgradeModel *> *needUpgradeFirmwares;

/// dp不满足提示
@property (nonatomic, copy) NSString *dpRemind;

/// dp是否满足升级
@property (nonatomic, assign) BOOL dpEnable;



/// 升级列表更新按钮状态
@property (nonatomic, assign) TYOTADeviceUpgradeListDeviceStatus upgradeButtonStatus;

/// 升级失败原因
@property (nonatomic, copy) NSString *upgradeFailedReason;

@end

NS_ASSUME_NONNULL_END
