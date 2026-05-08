
#import <Foundation/Foundation.h>
#import "ThingSmartStreamDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingStreamConnectInfo : NSObject

@property (nonatomic, assign) ThingSmartStreamClientType clientType;

@property (nonatomic, strong) NSArray<NSString *> *hosts;
@property (nonatomic, strong) NSArray<NSString *> *domains;
@property (nonatomic, assign) NSInteger tcpport;
@property (nonatomic, assign) NSInteger udpport;
@property (nonatomic, assign) NSInteger udpport_backup;
@property (nonatomic, strong) NSString *derived_client_id;
@property (nonatomic, strong) NSString *rsa_public_key;

@property (nonatomic, strong) NSString *username;
@property (nonatomic, assign) NSInteger expire;

/// Device localkey OR user sessionId OR other key.
@property (nonatomic, strong) NSString *authKey;

/// After connect success.
@property (nonatomic, strong) NSString *connectionId;
@end

NS_ASSUME_NONNULL_END
