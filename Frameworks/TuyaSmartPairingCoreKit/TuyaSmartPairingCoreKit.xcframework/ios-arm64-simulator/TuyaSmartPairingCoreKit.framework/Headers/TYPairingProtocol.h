//
//  TYPairingProtocol.h
//  TuyaSmartPairingCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>
#import "TYPairingManager.h"

NS_ASSUME_NONNULL_BEGIN

@protocol TYPairingProtocol <NSObject>

@property (nonatomic, assign) BOOL isRunning;

@property (nonatomic, copy, nullable) NSString *registerString;

@property (nonatomic, copy, nullable) NSString *token;

@property (nonatomic, copy, nullable) NSString *step;

@property (nonatomic, weak) id<TuyaSmartPairingHandlerDelegate> delegate;

@property (nonatomic, strong) id<TuyaSmartPairConfiguration> config;

@property (nonatomic, strong) id<TuyaSmartLogTrackConfiguration> logTrack;

- (void)pairingWithConfiguration:(id<TuyaSmartPairConfiguration>)config;

- (void)pairingWithConfiguration:(id<TuyaSmartPairConfiguration>)config
                        logTrack:(nullable id<TuyaSmartLogTrackConfiguration>)logTrack;

@optional

- (void)searchDevice;

- (void)deviceActive:(NSString *)token;

- (void)deviceStatusCheck:(NSString *)devId;

- (void)stopPairing;

- (void)continueConfigSecurityLevelDevice;

@end

NS_ASSUME_NONNULL_END
