//
//  TuyaSmartPairingHeader.h
//  TuyaSmartPairingCoreKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com/)
//

#import <Foundation/Foundation.h>

#ifndef TuyaSmartPairingHeader_h
#define TuyaSmartPairingHeader_h

typedef NS_ENUM(NSUInteger, TYActivatorMode) {
    TYActivatorModeEZ,///< smart config mode
    TYActivatorModeAP,///< access point mode
    TYActivatorModeQRCode,///< QR Code mode
    TYActivatorModeWired, ///< wired mode
    TYActivatorModeEZMulti,///< EZ
    TYActivatorModeWiredGateway, ///
    TYActivatorModeELink, /// Non-inductive
};

typedef NS_ENUM(NSUInteger, TYActivatorStep) {
    TYActivatorStepFound = 1,///< device found
    TYActivatorStepRegisted = 2,///< device registered
    TYActivatorStepIntialized = 3,///< device initialized
    TYActivatorStepTimeOut = 4, ///< device config timeout
};

#endif /* TuyaSmartPairingHeader_h */
