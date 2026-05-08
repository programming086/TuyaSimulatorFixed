
#import <Foundation/Foundation.h>
#import <ThingSecurityArmAbilityModuleServices/ThingSecurityModeSettingItemModel.h>

NS_ASSUME_NONNULL_BEGIN

/// the rule at mode 
@interface ThingSecurityModeSettingDeviceModel : NSObject

/// security gateway infomations
@property (nonatomic, strong) NSArray<ThingSecurityModeSettingItemModel *>*securityGateway;

/// virtual gateway infomations
@property (nonatomic, strong) NSArray<ThingSecurityModeSettingItemModel *>*virtualGateway;

/// camera devices infomations
@property (nonatomic, strong) NSArray<ThingSecurityModeSettingItemModel *>*ipcDevices;


@end

NS_ASSUME_NONNULL_END

