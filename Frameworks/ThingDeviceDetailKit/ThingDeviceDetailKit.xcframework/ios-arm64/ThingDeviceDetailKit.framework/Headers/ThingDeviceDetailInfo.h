
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingDeviceInfoConnectAbility) {
    ThingDeviceInfoConnectAbilityUnknown = 0,
    ThingDeviceInfoConnectAbilityPhone = 1,
    ThingDeviceInfoConnectAbilityGateway = 2,
    ThingDeviceInfoConnectAbilityPhoneAndGateway = 3,
};

@interface ThingDeviceDetailInfo : NSObject <NSCopying>

/// the id of the device
@property (nonatomic, copy) NSString *devId;

/// iccid
@property (nonatomic, copy, nullable) NSString *iccid;

/// netStrength
@property (nonatomic, copy, nullable) NSString *netStrength;

/// lan ip address
@property (nonatomic, copy, nullable) NSString *lanIp;

/// ip address
@property (nonatomic, copy, nullable) NSString *ip;

/// mac address
@property (nonatomic, copy, nullable) NSString *mac;

/// timezone
@property (nonatomic, copy, nullable) NSString *timezone;

/// channel
@property (nonatomic, copy, nullable) NSString *channel;

/// setChannelCapability
@property (nonatomic, assign) NSInteger setChannelCapability;

/// rsrp
@property (nonatomic, strong, nullable) NSNumber *rsrp;

/// signal
@property (nonatomic, strong, nullable) NSNumber *wifiSignal;

/// homekit code
@property (nonatomic, copy, nullable) NSString *homekitCode;

/// connect ability
@property (nonatomic, assign) ThingDeviceInfoConnectAbility connectAbility;

/// the name of vendor
@property (nonatomic, copy, nullable) NSString *vendorName;

/// matter active code
@property (nonatomic, copy, nullable) NSString *matterActiveCode;

// matter qr code
@property (nonatomic, copy, nullable) NSString *matterQrCode;

@property (nonatomic, copy, nullable) NSString *imei;


@property (nonatomic, copy, nullable) NSDictionary *meta;

@end

NS_ASSUME_NONNULL_END
