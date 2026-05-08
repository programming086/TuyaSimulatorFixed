
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>
#import <ThingSmartCameraKit/ThingSmartCameraKit.h>

@interface ThingSmartDeviceModel (IPCSDK)

/// Whether device is an IPC
- (BOOL)isIPCDevice;

/// Whether device is a low power device
- (BOOL)isLowPowerDevice;

/// p2p type of the ipc device
- (NSInteger)p2pType;

- (NSArray *)rangeForEnumDpName:(ThingSmartCameraDPKey)dpName;

- (ThingSmartSchemaModel *)schemaModelForDpName:(ThingSmartCameraDPKey)dpName;

- (NSArray *)rangeForEnumDpCode:(ThingSmartCameraDPKey)dpCode;

- (ThingSmartSchemaModel *)schemaModelForDpCode:(ThingSmartCameraDPKey)dpCode;

- (NSString *)dpCodeWithDpId:(NSString *)dpId;

- (NSString *)dpIdWithDpCode:(NSString *)dpCode;

/// Whether device is support multi play
- (BOOL)isSupportMultiPlay;

- (NSDictionary *)cameraDeviceFeatures;

- (BOOL)isSupportDirectly;

- (NSString *)directlyDeviceSecKey;

- (BOOL)isDoorbellDevice;

@end

