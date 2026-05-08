//
//  ThingSmartHotSpotCredentialManager.h
//  Pods
//
//  Created by 余豪 on 2023/2/9.
//

#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartHotSpotCredentialManager : NSObject

+ (void)connectWifiWithSSID:(NSString *)ssid password:(NSString *)password completionHandler:(void (^ __nullable)(NSError * __nullable error))completionHandler;

+ (void)connectWifiWithSSIDPrefix:(NSString *)SSIDPrefix password:(NSString *)password completionHandler:(void (^ __nullable)(NSError * __nullable error))completionHandler;

+ (void)disconnectWifiWithSSID:(NSString *)ssid;

@end

NS_ASSUME_NONNULL_END
