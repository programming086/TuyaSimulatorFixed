//
//  IndustryLinkSDK.h
//  IndustryLinkSDK
//
//  Created by ThingIndustry on 2022/8/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface IndustryLinkSDK : NSObject

@property (nonatomic, assign, class) BOOL debugMode;

/// The host of the project
@property (nonatomic, copy, class) NSString *host;

/// Initializes the SDK.
/// @param appKey Appkey
/// @param appSecret AppSecretKey
/// @param clientId The value of `Access ID` or `Client ID` of your application. You can get the value from the [Tuya IoT Development Platform](https://iot.tuya.com/cloud/).
/// @param clientSecret The value of `Access Secret` or `Client Secret of your application. You can get the value from the [Tuya IoT Development Platform](https://iot.tuya.com/cloud/).
+ (void)initializeWithAppKey:(NSString *)appKey
                   appSecret:(NSString *)appSecret
                    clientId:(NSString *)clientId
                clientSecret:(NSString *)clientSecret;

@end

NS_ASSUME_NONNULL_END
