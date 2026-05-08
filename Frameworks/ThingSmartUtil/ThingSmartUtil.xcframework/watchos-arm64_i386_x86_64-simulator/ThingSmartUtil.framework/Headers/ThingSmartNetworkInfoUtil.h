//
//  ThingSmartNetworkInfoUtil.h
//  ThingSmartUtil
//
//  Copyright (c) 2014-2024 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>
#import <Network/Network.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartIPInfo : NSObject

@property (nonatomic, copy) NSString *ip;
@property (nonatomic, copy) NSString *dst;

@end

@interface ThingSmartNetworkInfoUtil : NSObject

/// Get current IP address of the phone.
/// - Parameters:
///   - type: Interface types represent the underlying media for a network link, such as Wi-Fi or Cellular.
///   - handler: handler
+ (void)getIpAddressWithType:(nw_interface_type_t)type handler:(void(^)(ThingSmartIPInfo *ipInfo))handler;

@end

NS_ASSUME_NONNULL_END
