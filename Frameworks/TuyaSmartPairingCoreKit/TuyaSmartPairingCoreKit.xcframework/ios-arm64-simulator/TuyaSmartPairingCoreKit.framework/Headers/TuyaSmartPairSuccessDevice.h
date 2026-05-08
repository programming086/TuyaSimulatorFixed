//
//  TuyaSmartPairSuccessDevice.h
//  TuyaSmartPairingCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TuyaSmartPairSuccessDevice : NSObject

@property (nonatomic, copy) NSString *devId;

@property (nonatomic, strong) id device;

@end

NS_ASSUME_NONNULL_END
