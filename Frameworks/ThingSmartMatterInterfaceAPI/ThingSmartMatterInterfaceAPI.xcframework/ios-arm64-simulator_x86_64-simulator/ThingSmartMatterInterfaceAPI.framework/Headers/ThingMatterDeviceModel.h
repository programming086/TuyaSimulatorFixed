
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceModel.h>
#import "ThingMatterSetupPayload.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingMatterDeviceType) {
    ThingMatterDeviceTypeUnknown = 0,
    ThingMatterDeviceTypeThread,
    ThingMatterDeviceTypeWifi,
    ThingMatterDeviceTypeOnNetwork,
    ThingMatterDeviceTypeAP,
    ThingMatterDeviceTypeWifiSupport5G,
    ThingMatterDeviceTypeThreadSupportBLE,
};

typedef NS_ENUM(NSUInteger, ThingMatterDeviceStatus){
    ThingMatterDeviceStatusDiscovery              = 0,    //Searching for a device
    ThingMatterDeviceStatusConnecting             = 1,    //Device being connected
    ThingMatterDeviceStatusNOCSigning             = 2,    //Vouchers being generated
    ThingMatterDeviceStatusCommissioning          = 3,    //Case session being established
    ThingMatterDeviceStatusActiving               = 4,    //Device being associated (cloud activation)
};

@interface ThingMatterDeviceModel : NSObject

@property (nonatomic, strong) ThingMatterSetupPayload *payload;
@property (nonatomic, strong) ThingSmartDeviceModel *deviceModel;
@property (nonatomic, assign) ThingMatterDeviceType deviceType;
@property (nonatomic, strong) NSString *thingProductId;
@property (nonatomic, assign) BOOL isOrigin;

//matter device Id
@property (nonatomic, assign) long long nodeId;

@property (nonatomic, assign) BOOL isOnline;

@property (nonatomic, strong) NSString *parentId;

@property (nonatomic, assign) long long parentNodeId;

@property (nonatomic, assign) long long parentFabricId;

@property (nonatomic, assign) long long spaceId;

@property (nonatomic, assign) BOOL withoutThread;

@property (nonatomic, strong) NSString *iconUrl;

@property (nonatomic, strong) NSString *deviceName;

@property (nonatomic, strong) id originalDevice;

@property (nonatomic, strong) NSString *uuid; //Exists only after the Commissioning Session


@property (nonatomic, assign) BOOL isThingDevice;

@property (nonatomic, strong) NSString *gatewayId;


@end

NS_ASSUME_NONNULL_END
