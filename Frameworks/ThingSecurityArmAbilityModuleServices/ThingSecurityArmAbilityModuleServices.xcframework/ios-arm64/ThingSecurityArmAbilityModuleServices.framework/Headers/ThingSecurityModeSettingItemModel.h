
#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface ThingSecurityModeSettingItemModel : NSObject

//// allow select
@property (nonatomic, assign) BOOL allowSelect;

/// device id
@property (nonatomic, copy) NSString *deviceId;

/// device name
@property (nonatomic, copy) NSString *name;

/// device icon
@property (nonatomic, copy) NSString *icon;

/// select state
@property (nonatomic, assign) BOOL selectState;

/// mode status
@property (nonatomic, strong) NSArray    *mode;

/// mode new Select status
@property (nonatomic, strong) NSString   *modeNewStatus;

/// isGetway device
@property (nonatomic, assign) BOOL  isMainGateway;

// deviceType 1-securityGateway 2-virtualGateway  3-ipcDevices
@property (nonatomic, assign) NSInteger deviceType;

/// super device
@property (nonatomic, strong) ThingSecurityModeSettingItemModel *superDevice;

/// gateway sub devices
@property (nonatomic, strong) NSArray<ThingSecurityModeSettingItemModel *>*subDevices;

/// config alarm rule
@property (nonatomic, assign) NSInteger configAlarmRule;

@end

NS_ASSUME_NONNULL_END

