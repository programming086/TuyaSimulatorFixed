
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, ThingSmartMatterDeviceBoardingType){
    kSmartMatterDeviceBoardingTypePairing = 0,   //Pairing Device
    kSmartMatterDeviceBoardingTypeSharing = 1    //Sharing Device
};

typedef NS_ENUM(NSUInteger, ThingSmartMatterRendezvousFlags) {
    ThingSmartMatterRendezvousNone = 0, // Device does not support any method for rendezvous
    ThingSmartMatterRendezvousSoftAP = 1 << 0, // Device supports WiFi softAP
    ThingSmartMatterRendezvousBLE = 1 << 1, // Device supports BLE
    ThingSmartMatterRendezvousOnNetwork = 1 << 2, // Device supports On Network setup

    ThingSmartMatterRendezvousAllMask = ThingSmartMatterRendezvousSoftAP | ThingSmartMatterRendezvousBLE | ThingSmartMatterRendezvousOnNetwork,
};

typedef NS_ENUM(NSUInteger, ThingSmartMatterRoutingType){
    ThingSmartMatterRoutingTypeThing             = 0,
    ThingSmartMatterRoutingTypeSupport           = 1,
    ThingSmartMatterRoutingTypeShare             = 2,
};


@interface ThingMatterSetupPayload : NSObject

@property (nonatomic, strong) NSNumber * version; 
@property (nonatomic, strong) NSNumber * vendorID; 
@property (nonatomic, strong) NSNumber * productID; 
@property (nonatomic, strong) NSNumber * discriminator;
@property (nonatomic, strong) NSString * serialNumber;  
@property (nonatomic, strong) NSNumber * setUpPINCode;
@property (nonatomic, strong) NSString * devId; 

@property (nonatomic, assign) ThingSmartMatterRendezvousFlags rendezvousInformation;
@property (nonatomic, assign) NSInteger accessType; 
@property (nonatomic, strong) NSString *thingProductId;

@property (nonatomic, assign) ThingSmartMatterDeviceBoardingType boardingType;

@property (nonatomic, assign) ThingSmartMatterRoutingType routingType;

@property (nonatomic, strong) id originalPayload;  

@end


NS_ASSUME_NONNULL_END
