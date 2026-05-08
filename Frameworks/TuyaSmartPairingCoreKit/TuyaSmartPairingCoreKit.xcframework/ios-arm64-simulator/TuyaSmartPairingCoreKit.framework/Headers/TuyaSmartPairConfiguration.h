//
//  TuyaSmartPairConfiguration.h
//  TuyaSmartPairingCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TuyaSmartPairConfiguration <NSObject>

@property (nonatomic, copy, nullable) NSString *registerString;

@optional
@property (nonatomic, copy, nullable) NSString *ssid;
@property (nonatomic, copy, nullable) NSString *password;
@property (nonatomic, copy, nullable) NSString *token;
@property (nonatomic, copy, nullable) NSString *gwId;
@property (nonatomic, copy, nullable) NSString *productId;
@property (nonatomic, copy, nullable) NSString *ecode;
@property (nonatomic, copy, nullable) NSString *uid;
@property (nonatomic, copy, nullable) NSDictionary *domainDic;
@property (nonatomic, copy, nullable) NSString *gwHost;
@property (nonatomic, copy, nullable) NSString *localKey;
@property (nonatomic, assign) BOOL isApEncrypted;

@property (nonatomic, assign) BOOL isApDirect;

@property (nonatomic, assign) BOOL slApDisable;
@end

@interface TuyaSmartPairConfiguration : NSObject <TuyaSmartPairConfiguration>

@end

NS_ASSUME_NONNULL_END
