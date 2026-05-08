
#import <Foundation/Foundation.h>

#ifndef ThingSmartPairingHeader_h
#define ThingSmartPairingHeader_h

typedef NS_ENUM(NSUInteger, ThingActivatorMode) {
    ThingActivatorModeEZ,///< smart config mode
    ThingActivatorModeAP,///< access point mode
    ThingActivatorModeQRCode,///< QR Code mode
    ThingActivatorModeWired, ///< wired mode
    ThingActivatorModeEZMulti,///< EZ
    ThingActivatorModeWiredGateway, ///
    ThingActivatorModeELink, /// Non-inductive
    ThingActivatorModeAPPlus,
    ThingActivatorModeMQTTDirectly,
    ThingActivatorModeAP4GGateway, /// AP 4G gateway mode
};

typedef NS_ENUM(NSUInteger, ThingActivatorStep) {
    ThingActivatorStepFound = 1,///< device found
    ThingActivatorStepRegisted = 2,///< device registered
    ThingActivatorStepIntialized = 3,///< device initialized
    ThingActivatorStepTimeOut = 4, ///< device config timeout
    ThingActivatorStepStartDialUp = 41, ///< 4G gateway start dialing
    ThingActivatorStepConnectSuccess = 42, ///< 4G gateway connect success
};

#endif /* ThingSmartPairingHeader_h */
