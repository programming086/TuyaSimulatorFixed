
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingActivatorFactoryConfig : NSObject
@property (nonatomic, copy) NSString *ssid; ///< SSID
@property (nonatomic, copy) NSString *password; ///< Password
@property (nonatomic, copy) NSString *gwId; ///< Used for sub-devices
@property (nonatomic, copy) NSString *token; ///< Token
@property (nonatomic, strong) NSError *error; ///< Network configuration error
@property (nonatomic, copy, nullable) NSDictionary *qrCodeParams; ///< Parameters for scanning QR code
@property (nonatomic, copy, nullable) NSDictionary *securityConfig; ///< Security certificate configuration for PSK AP network configuration
@property (nonatomic, copy, nullable) NSDictionary *routeParams; ///< Routing parameters
@property (nonatomic, copy, nullable) NSDictionary *commonParam; ///< common parameters

#pragma mark - Static IP (required for static IP pairing)
/// Static IP address, e.g. "192.168.1.200". Required when pairing with static IP.
@property (nonatomic, copy, nullable) NSString *ip;
/// Subnet mask, e.g. "255.255.255.0"
@property (nonatomic, copy, nullable) NSString *mask;
/// Gateway, e.g. "192.168.1.1"
@property (nonatomic, copy, nullable) NSString *gw;
/// DNS, e.g. "8.8.8.8"
@property (nonatomic, copy, nullable) NSString *dns;
@end

NS_ASSUME_NONNULL_END
