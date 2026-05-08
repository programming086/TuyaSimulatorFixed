
#ifndef ThingSmartHTTPDNS_h
#define ThingSmartHTTPDNS_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(int, ThingSmartHttpDNSStatus)
{
    ThingSmartHttpDNSStatusInvalid    = 0,
    ThingSmartHttpDNSStatusFirstUse,
    ThingSmartHttpDNSStatusInUse
};

@protocol ThingSmartHTTPDNSIntercepter <NSObject>

- (BOOL)shouldToInterceptDomain:(NSString *)domain ips:(nullable NSArray<NSString *> *)ips;

@end

/// @brief ThingSmartHTTPDNS is another solution for DNS query instead of system DNS service.
///
/// The DNS query can be done through http to prevent DNS cache pollution.
@interface ThingSmartHTTPDNS : NSObject

+ (instancetype)sharedInstance;

- (ThingSmartHttpDNSStatus)useHttpDNSWithError:(nullable NSError *)error;

/// Asynchronous resolution interface, first query the cache, if it exists then return the result, if not return nil and asynchronous domain name resolution to update the cache.
/// @param host Domain name (e.g. www.thing.com).
/// @return The resolution result corresponding to the domain name.
- (NSString *)getIpWithHost:(NSString *)host;


/// Set whether the domain name is downgraded or not.
/// @param host Domain Name.
/// @param enable Whether to downgrade.
- (void)setDegradationWithHost:(NSString *)host enable:(BOOL)enable;

- (void)enableHTTPDNS;

- (void)disableHTTPDNS;

- (ThingSmartHttpDNSStatus)disableHTTPDNSWithError:(nullable NSError *)error;

- (void)setHTTPDNSIntercepter:(id<ThingSmartHTTPDNSIntercepter>)intercepter;

@end

NS_ASSUME_NONNULL_END

#endif /* ThingSmartHTTPDNS_h */
