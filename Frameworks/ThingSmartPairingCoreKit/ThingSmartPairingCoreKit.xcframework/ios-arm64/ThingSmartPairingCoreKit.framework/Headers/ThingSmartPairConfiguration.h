
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartPairConfiguration <NSObject>
@optional
@property (nonatomic, copy, nullable) NSString *token;
@property (nonatomic, copy, nullable) NSString *registerString DEPRECATED_MSG_ATTRIBUTE("Use token instead");
@property (nonatomic, copy, nullable) NSString *ssid;
@property (nonatomic, copy, nullable) NSString *password;
@property (nonatomic, copy, nullable) NSString *gwId;
@property (nonatomic, copy, nullable) NSString *productId;
@property (nonatomic, copy, nullable) NSString *ecode;
@property (nonatomic, copy, nullable) NSString *uid;
@property (nonatomic, copy, nullable) NSDictionary *domainDic;
@property (nonatomic, copy, nullable) NSString *gwHost;
@property (nonatomic, copy, nullable) NSString *localKey;

@property (nonatomic, copy, nullable) NSString *oper;
@property (nonatomic, copy, nullable) NSString *apn;
@property (nonatomic, copy, nullable) NSString *username;

/**
 Static IP Network Configuration Information
 */
/// The static IP to be configured for the device， for example, "192.168.1.200"
@property (nonatomic, copy, nullable) NSString *ip;
/// Subnet Mask for Static IP， for example, "255.255.255.0"
@property (nonatomic, copy, nullable) NSString *mask;
/// Gateway for static IP， for example, "192.168.1.1"
@property (nonatomic, copy, nullable) NSString *gw;
/// DNS, for example, "8.8.8.8"
@property (nonatomic, copy, nullable) NSString *dns;

@property (nonatomic, copy, nullable) NSString *uuid;
@property (nonatomic, copy, nullable) NSString *pin;

@property (nonatomic, copy, nullable) NSString *gid;

@property (nonatomic, copy, nullable) NSString *ccode;

@property (nonatomic, strong) NSDictionary *pskRegInfo;

@property (nonatomic, strong, nullable) NSDictionary *extendParams;

@property (nonatomic, assign) BOOL isApEncrypted;

@property (nonatomic, assign) BOOL isApDirect;

@property (nonatomic, assign) BOOL slApDisable;

@property (nonatomic, assign) BOOL enableEzDual;

@end

@interface ThingSmartPairConfiguration : NSObject <ThingSmartPairConfiguration>

@end

NS_ASSUME_NONNULL_END
