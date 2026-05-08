
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Channel connect Info configuration
@interface ThingSmartMQTTConfigModel : NSObject <NSMutableCopying>

@property (nonatomic, strong) NSString *clientId;
@property (nonatomic, strong) NSString *userName;
@property (nonatomic, strong) NSString *password;

@property (nonatomic, strong) NSString *mbHost;
@property (nonatomic, strong) NSString *mbIp;
@property (nonatomic, assign) int port;
@property (nonatomic, assign) BOOL useSSL;

@property (nonatomic, strong, nullable) NSString *quicHost;
@property (nonatomic, strong, nullable) NSString *quicIp;
@property (nonatomic, assign) int quicPort;
@property (nonatomic, assign) BOOL useQUIC;
@property (nonatomic, assign) BOOL quicEnabled;

@end

/// Channel behavior configuration
@interface ThingSmartMQTTChannelConfig : NSObject

+ (instancetype)sharedInstance;
@property (nonatomic, assign) NSInteger pubAckTimeoutMaxCnt;
@property (nonatomic, assign) NSInteger pubAckTimeoutInterval;
@property (nonatomic, assign) NSTimeInterval dupTime;
@property (nonatomic, assign) BOOL disableDupOnlyOnce;
@property (nonatomic, assign) NSInteger connectTimeout; // default 0, off
@end

NS_ASSUME_NONNULL_END
