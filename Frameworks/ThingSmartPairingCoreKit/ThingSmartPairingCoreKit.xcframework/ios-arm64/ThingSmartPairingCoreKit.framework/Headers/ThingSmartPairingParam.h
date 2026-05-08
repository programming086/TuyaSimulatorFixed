
#import <Foundation/Foundation.h>
#import <ThingSmartPairingCoreKit/ThingSmartPairingHeader.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ThingPairingErrorCode) {
    ThingPairingErrorCodeSuccess = 0,
    ThingPairingErrorInvalidParamters = 1,
    ThingPairingErrorNotInPairing = 2,
    ThingPairingErrorOnlyAPPairingSupported = 3,
    ThingPairingErrorAPDirectNotSupported = 4,
    ThingPairingErrorInvalidDeviceUUID = 5,
    ThingPairingErrorDeviceNotSupported = 6,
    ThingPairingErrorDeviceIPNotFound = 7,
    ThingPairingErrorFailedToConnectWiFi = 8,
    ThingPairingErrorTimeout = 9,
};

FOUNDATION_EXPORT NSString *ThingSmartPairingConnectWiFiFailedErrorDomain;

#pragma mark - NSError (ThingPairingCore)

@interface NSError (ThingPairingCore)
+ (NSError*)thingsdk_pcErrorWithCode:(NSInteger)code message:(NSString*)message;
@end


#pragma mark - ThingSmartPairingResumeConfigWiFiParam

@interface ThingSmartPairingResumeConfigWiFiParam : NSObject <NSCopying>
@property (nonatomic, assign) ThingActivatorMode mode;
@property (nonatomic, strong) NSString *ssid;
@property (nonatomic, strong) NSString *password;
@end

#pragma mark - wifi scan

@interface ThingSmartPairingWiFiInfo : NSObject <NSCopying>
@property (nonatomic, strong) NSString *ssid;
@property (nonatomic, strong) NSNumber *rssi;
@property (nonatomic, strong) NSNumber *sec;
@end

@interface ThingSmartPairingScanWiFiListParam : NSObject<NSCopying>
@property (nonatomic, assign) NSInteger limit;
@property (nonatomic, assign) NSTimeInterval timeInterval;
@end

@interface ThingSmartPairingParam : NSObject

@end

NS_ASSUME_NONNULL_END
