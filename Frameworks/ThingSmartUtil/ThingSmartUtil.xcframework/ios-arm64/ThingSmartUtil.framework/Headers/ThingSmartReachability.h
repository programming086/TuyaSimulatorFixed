

#if TARGET_OS_IOS
#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>


/** 
 * Create NS_ENUM macro if it does not exist on the required version for iOS or OS X.
 *
 * @see http://nshipster.com/ns_enum-ns_options/
 **/
#ifndef NS_ENUM
#define NS_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#endif

extern NSString *const kThingSmartReachabilityChangedNotification;

typedef NS_ENUM(NSInteger, ThingSDKNetworkStatus) {
    // Apple NetworkStatus compatible names.
    ThingSDKNotReachable = 0,
    ThingSDKReachableViaWiFi = 2,
    ThingSDKReachableViaWWAN = 1
};

@class ThingSmartReachability;

typedef void (^ThingSmartNetworkReachable)(ThingSmartReachability * reachability);
typedef void (^ThingSmartNetworkUnreachable)(ThingSmartReachability * reachability);


@interface ThingSmartReachability : NSObject

@property (nonatomic, copy) ThingSmartNetworkReachable    reachableBlock;
@property (nonatomic, copy) ThingSmartNetworkUnreachable  unreachableBlock;

@property (nonatomic, assign) BOOL reachableOnWWAN;


+(ThingSmartReachability*)reachabilityWithHostname:(NSString*)hostname;
// This is identical to the preceding function but is used to provide
//compatibility with Apples original code. (see .m)
+(ThingSmartReachability*)reachabilityWithHostName:(NSString*)hostname;
+(ThingSmartReachability*)reachabilityForInternetConnection;
+(ThingSmartReachability*)reachabilityWithAddress:(void *)hostAddress;
+(ThingSmartReachability*)reachabilityForLocalWiFi;

-(ThingSmartReachability *)initWithReachabilityRef:(SCNetworkReachabilityRef)ref;

-(BOOL)startNotifier;
-(void)stopNotifier;

-(BOOL)isReachable;
-(BOOL)isReachableViaWWAN;
-(BOOL)isReachableViaWiFi;

// WWAN might be available, but not active until a connection has been established.
// Wi-Fi might require a connection to enable VPN On Demand.
-(BOOL)isConnectionRequired; // Identical DDG variant.
-(BOOL)connectionRequired; // Apple's routine.
// Indicates whether a dynamic on-demand connection is used.
-(BOOL)isConnectionOnDemand;
// Indicates whether user intervention is required.
-(BOOL)isInterventionRequired;

-(ThingSDKNetworkStatus)currentReachabilityStatus;
-(SCNetworkReachabilityFlags)reachabilityFlags;
-(NSString*)currentReachabilityString;
-(NSString*)currentReachabilityFlags;

@end

#endif
