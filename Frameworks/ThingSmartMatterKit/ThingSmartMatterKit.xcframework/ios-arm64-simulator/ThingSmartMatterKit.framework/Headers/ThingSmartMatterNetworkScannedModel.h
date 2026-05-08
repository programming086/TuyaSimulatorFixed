
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ThingMatterScannedWIFISecurityType){
    ThingMatterScannedWIFISecurityTypeUnencrypted            = 0,
    ThingMatterScannedWIFISecurityTypeWEP                    = 1,
    ThingMatterScannedWIFISecurityTypeWEPPersonal            = 2,
    ThingMatterScannedWIFISecurityTypeWPAPersonal            = 3,
    ThingMatterScannedWIFISecurityTypeWPA2Personal           = 4,
    ThingMatterScannedWIFISecurityTypeWPA3Personal           = 5,
    ThingMatterScannedWIFISecurityTypeUnknown                = 100,
};

typedef NS_ENUM(NSUInteger, ThingMatterScannedWIFIBandType){
    ThingMatterScannedWIFIBandType2G4                        = 0,
    ThingMatterScannedWIFIBandType3G65                       = 1,
    ThingMatterScannedWIFIBandType5G                         = 2,
    ThingMatterScannedWIFIBandType6G                         = 3,
    ThingMatterScannedWIFIBandType60G                        = 4,
};

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartMatterNetworkScannedModel : NSObject

//WIFI Security Type,like WPA2.
@property (nonatomic, assign) ThingMatterScannedWIFISecurityType securityType;

//WIFI SSID
@property (nonatomic, strong) NSString * ssid;

//WIFI Channel
@property (nonatomic, copy) NSNumber * channel;

//WiFi BAND, like 2.4g hz
@property (nonatomic, assign) ThingMatterScannedWIFIBandType wiFiBand;

//WIFI Rssi
@property (nonatomic, copy) NSNumber * rssi;


@end

NS_ASSUME_NONNULL_END
