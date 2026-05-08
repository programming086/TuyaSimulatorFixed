
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingMatterDeviceBoardingType){
    kMatterDeviceBoardingTypePairing = 0,   //Pairing Device
    kMatterDeviceBoardingTypeSharing = 1    //Sharing Device
};

typedef NS_ENUM(NSUInteger, ThingMatterDevicePayloadStringType){
    kMatterPayloadStringTypeQRCode     = 0,     //QR Code
    kMatterPayloadStringTypeManualCode = 1,     //Manual Code
};

typedef NS_ENUM(NSUInteger, ThingMatterDeviceActivatorType){
    kThingMatterDeviceActivatorTypeNormal          = 0,     //Normal Thing activator
    kThingMatterDeviceActivatorTypeMatterSupport   = 1,     //Matter Support activator
};

typedef NS_ENUM(NSUInteger, ThingMatterDeviceStepType){
    ThingMatterDeviceStepTypePase          = 0,     //Pase step
    ThingMatterDeviceStepTypeCase          = 1,     //Case step
};

typedef NS_ENUM(NSUInteger, ThingMatterRoutingType){
    ThingMatterRoutingTypeThing             = 0,    //Thing router
    ThingMatterRoutingTypeSupport           = 1,    //Matter Support rouer
    ThingMatterRoutingTypeShare             = 2,    //Share
};

typedef NS_ENUM(NSUInteger, ThingRendezvousInformationFlags) {
    kRendezvousInformationNone = 0, // Device does not support any method for rendezvous
    kRendezvousInformationSoftAP = 1 << 0, // Device supports WiFi softAP
    kRendezvousInformationBLE = 1 << 1, // Device supports BLE
    kRendezvousInformationOnNetwork = 1 << 2, // Device supports On Network setup

    kRendezvousInformationAllMask = kRendezvousInformationSoftAP | kRendezvousInformationBLE | kRendezvousInformationOnNetwork,
};

typedef NS_ENUM(NSUInteger, ThingCommissioningFlow) {
    kCommissioningFlowStandard = 0, // Device automatically enters pairing mode upon power-up
    kCommissioningFlowUserActionRequired = 1, // Device requires a user interaction to enter pairing mode
    kCommissioningFlowCustom = 2, // Commissioning steps should be retrieved from the distributed compliance ledger
    kCommissioningFlowInvalid = 3,
};

typedef NS_ENUM(NSUInteger, ThingOptionalQRCodeInfoType) {
    kOptionalQRCodeInfoTypeUnknown,
    kOptionalQRCodeInfoTypeString,
    kOptionalQRCodeInfoTypeInt32
};


typedef NS_ENUM(NSUInteger, ThingSmartMatterDeviceType) {
    ThingSmartMatterDeviceTypeUnknow             = 0,   //unkonw Device
    ThingSmartMatterDeviceTypeThread             = 1,   //Thread Device
    ThingSmartMatterDeviceTypeWIFI               = 2,   //WIFI+BLE Device
    ThingSmartMatterDeviceTypeOnNetwork          = 3,   //On network Device
    ThingSmartMatterDeviceTypeAP                 = 4,   //AP Device
    ThingSmartMatterDeviceTypeWIFISupport5G      = 5,   //WIFI+BLE & Supprort5GWIFI Device
    ThingSmartMatterDeviceTypeThreadSupportBLE   = 6,   //Thread+BLE & Support Only BLE Active
};

typedef NS_ENUM(NSUInteger, ThingMatterStatus){
    ThingMatterStatusDiscovery              = 0,    //Discovering device
    ThingMatterStatusConnecting             = 1,    //Connecting device
    ThingMatterStatusNOCSigning             = 2,    //Generating NOC sign
    ThingMatterStatusCommissioning          = 3,    //Establishing case session
    ThingMatterStatusActiving               = 4,    //Activating on the cloud
};

@interface ThingMatterOptionalQRCodeInfo : NSObject
@property (nonatomic, assign) ThingOptionalQRCodeInfoType infoType;
@property (nonatomic, strong) NSNumber * tag;
@property (nonatomic, strong) NSNumber * integerValue;
@property (nonatomic, strong) NSString * stringValue;
@end

@class WTLSetupPayload,MTRSetupPayload;

/// Matter Setup Payload.
@interface ThingSmartMatterSetupPayload : NSObject

@property (nonatomic, strong) NSNumber * version;
@property (nonatomic, strong) NSNumber * vendorID;
@property (nonatomic, strong) NSNumber * productID;
@property (nonatomic, assign) ThingCommissioningFlow commissioningFlow;
@property (nonatomic, assign) ThingRendezvousInformationFlags rendezvousInformation;
@property (nonatomic, strong) NSNumber * discriminator;
@property (nonatomic, strong) NSString * realDis;
@property (nonatomic, strong) NSNumber * setUpPINCode;

@property (nonatomic, strong) NSString * serialNumber;

@property (nonatomic, strong) NSString * onboardingPayload;

@property (nonatomic, strong) NSArray<ThingMatterOptionalQRCodeInfo *> * allQRCodeInfoArray;

@property (nonatomic, strong) NSString *devId; //!< deprecated, alaways nil

@property (nonatomic, strong) WTLSetupPayload *payload;

@property (nonatomic, assign) ThingMatterDeviceBoardingType boardingType;

@property (nonatomic, assign) ThingMatterDevicePayloadStringType codeType;

@property (nonatomic, assign) ThingMatterDeviceActivatorType activtorType;

@property (nonatomic, assign) ThingMatterDeviceStepType stepType;

@property (nonatomic, assign) ThingSmartMatterDeviceType deviceType;

@property (nonatomic, assign) BOOL isActive;

@property (nonatomic, assign) BOOL isThingBLE;

@property (nonatomic, assign) BOOL isLiteBLE;

@property (nonatomic, assign) BOOL isSuperCase;

@property (nonatomic, assign) BOOL isCaseJump;

@property (nonatomic, assign) BOOL willConnectBLE;

@property (nonatomic, assign) int publishVersion;

@property (nonatomic, assign) BOOL isSupportBLE;

@property (nonatomic, assign) BOOL isBLEActived;

@property (nonatomic, assign) BOOL support5G;

@property (nonatomic, assign) BOOL isDualNetwork;

- (instancetype)init NS_UNAVAILABLE;
- (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithWTLPayload:(WTLSetupPayload *)payLoad;

+ (MTRSetupPayload * _Nullable)generatePayloadWithOnboardingString:(NSString *)onboardingString;

- (nullable NSArray<ThingMatterOptionalQRCodeInfo *> *)getAllOptionalVendorData:(NSError * __autoreleasing *)error;

@end

NS_ASSUME_NONNULL_END
