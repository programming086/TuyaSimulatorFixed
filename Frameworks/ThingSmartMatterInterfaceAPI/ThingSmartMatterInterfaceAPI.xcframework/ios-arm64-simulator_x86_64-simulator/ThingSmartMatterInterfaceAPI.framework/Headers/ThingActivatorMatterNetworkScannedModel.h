
#import <Foundation/Foundation.h>
typedef NS_ENUM(NSUInteger, ThingActivatorMatterScannedWIFISecurityType){
    ThingActivatorMatterScannedWIFISecurityTypeUnencrypted            = 0,
    ThingActivatorMatterScannedWIFISecurityTypeWEP                    = 1,
    ThingActivatorMatterScannedWIFISecurityTypeWEPPersonal            = 2,
    ThingActivatorMatterScannedWIFISecurityTypeWPAPersonal            = 3,
    ThingActivatorMatterScannedWIFISecurityTypeWPA2Personal           = 4,
    ThingActivatorMatterScannedWIFISecurityTypeWPA3Personal           = 5,
    ThingActivatorMatterScannedWIFISecurityTypeUnknown                = 100,
    
};

typedef NS_ENUM(NSUInteger, ThingActivatorMatterScannedWIFIBandType){
    ThingActivatorMatterScannedWIFIBandType2G4                        = 0,
    ThingActivatorMatterScannedWIFIBandType3G65                       = 1,
    ThingActivatorMatterScannedWIFIBandType5G                         = 2,
    ThingActivatorMatterScannedWIFIBandType6G                         = 3,
    ThingActivatorMatterScannedWIFIBandType60G                        = 4,
};



NS_ASSUME_NONNULL_BEGIN

@interface ThingActivatorMatterNetworkScannedModel : NSObject
//WIFI Security Type,like WPA2.
@property (nonatomic, assign) ThingActivatorMatterScannedWIFISecurityType securityType;

//WIFI SSID
@property (nonatomic, strong) NSString * ssid;

//WIFI Channel
@property (nonatomic, copy) NSNumber * channel;

//WiFi BAND, like 2.4g hz
@property (nonatomic, assign) ThingActivatorMatterScannedWIFIBandType wiFiBand;

//WIFI Rssi
@property (nonatomic, copy) NSNumber * rssi;

@end

NS_ASSUME_NONNULL_END
