
#ifndef ThingSmartSDK_h
#define ThingSmartSDK_h

#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

/// Server environment.
typedef NS_ENUM(NSInteger, ThingEnv) {
    ThingEnvDaily,
    ThingEnvPrepare,
    ThingEnvRelease,
    ThingEnvNeutralPrepare,
    ThingEnvNeutralRelease
};

/// @brief ThingSmartSDK is an entry for using the Thing SDK.
///
/// Before using the SDK, please go to Thing IoT Platform (https://iot.thing.com) create a SDK App.
/// We need 4 things from the Platform to initialize the SDK:
///     - Thing App Key.
///     - Thing App Secret.
///     - Security Image. Rename to `t_s.bmp` and put it in your project as a resource.
///     - Bundle ID. Must equal to your App's bundle ID.
///
/// If you need to set some params (appGroupId, env, appVersion, lang, etc...) in this class, be sure to set them before initialize the SDK.
///
/// Finally, call this method to initialize the SDK:
///     `[ThingSmartSDK.sharedInstance startWithAppKey:@"YOUR_APP_KEY" secretKey:@"YOUR_APP_SECRET"];`.
///
@interface ThingSmartSDK : NSObject

/// Returns the singleton of the class.
+ (instancetype)sharedInstance;

/// Application group identifier.
/// If you want to use the SDK in app extension, set `appGroupId` before SDK initialized both in app & app extension.
@property (nonatomic, strong) NSString *appGroupId;

/// Positioning switch.
/// True means include latitude and longitude in common parameters, while false means no include.
/// Default is true.
@property (nonatomic, assign) BOOL locationSwitch;

/// Latitude of the location.
@property (nonatomic, assign) double latitude;

/// Longitude of the location.
@property (nonatomic, assign) double longitude;

/// Server environment, defaults is ThingEnvRelease. Please do not set in production environment.
@property (nonatomic, assign) ThingEnv env;

/// Request need SSL Pinning, default is `YES`.
@property (nonatomic, assign) BOOL useSSLPinning;

/// Request need Https dns, default is `NO`.
@property (nonatomic, assign) BOOL useHTTPSDNS;

/// Whether to remove keys with `NSNull` values from response JSON. Defaults to `YES`.
@property (nonatomic, assign) BOOL removesKeysWithNullValues;

/// ThingSmart AppKey.
@property (nonatomic, strong, readonly) NSString *appKey;

/// ThingSmart SecretKey.
@property (nonatomic, strong, readonly) NSString *secretKey;

/// Channel.
@property (nonatomic, strong) NSString *channel;

/// UUID of the iOS/watchOS device. Will be created at app first launch.
@property (nonatomic, strong, readonly) NSString *uuid;

/// App version, default value is from Info.plist -> CFBundleShortVersionString.
@property (nonatomic, strong) NSString *appVersion;

/// Device product name. For example: iPhone XS Max.
@property (nonatomic, strong) NSString *deviceProductName;

/// App SDK lang, default value is from mainBundle -> preferredLocalizations -> [0].
@property (nonatomic, strong) NSString *lang;

@property (nonatomic, strong, readonly) NSString *appEnv;

@property (nonatomic, strong, readonly) NSString *mbUrl;

@property (nonatomic, strong, readonly) NSString *gwHost;
@property (nonatomic, strong, readonly) NSString *mbHost;
@property (nonatomic, assign, readonly) int port;
@property (nonatomic, assign, readonly) BOOL useSSL;

@property (nonatomic, strong, readonly) NSString *quicHost;
@property (nonatomic, assign, readonly) int quicPort;
@property (nonatomic, assign, readonly) BOOL useQUIC;

@property (nonatomic, strong, readonly) NSString *appSupportUrl;
@property (nonatomic, strong, readonly) NSString *regionCode;

@property (nonatomic, assign) BOOL bExecNeutralDomain;

@property (nonatomic, assign) BOOL bLangDebug;

/// Low-latency network links are preferred, default is `YES`.
@property (nonatomic, assign) BOOL autoSelectNetworkLink;

/// Initialize ThingSmart SDK.
/// @param appKey ThingSmart AppKey.
/// @param secretKey ThingSmart SecretKey.
- (void)startWithAppKey:(NSString *)appKey secretKey:(NSString *)secretKey;


/// Report location if needed.
/// @param latitude Latitude.
/// @param longitude Longitude.
- (void)updateLatitude:(double)latitude longitude:(double)longitude;

@end

@interface ThingSmartSDK (CountryCode)
/// Set env to this country code
/// @param countryCode link 86 for china
+ (void)setCountryCode:(NSString *)countryCode;

+ (NSString *)getCountryCode;

+ (NSString *)getCountryNumWithCountryCode:(NSString *)countryCode;

/// Set network interface request priority.
/// - Parameters:
///   - highList: high priority request api list
///   - lowList:  low priority request api list
- (void)addNetworkRequestPriorityWithHighList:(NSArray *)highList lowList:(NSArray *)lowList;

@end


NS_ASSUME_NONNULL_END

#endif /* ThingSmartSDK_h */
