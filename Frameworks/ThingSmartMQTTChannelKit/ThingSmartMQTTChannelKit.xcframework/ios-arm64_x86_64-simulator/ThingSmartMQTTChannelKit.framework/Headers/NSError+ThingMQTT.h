//
//  ThingSmartMQTTChannel.h
//  ThingSmartMQTTChannelKit
//
//  Copyright (c) 2014-2024.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define ThingMQTTErrorDomain @"com.thingmqtt.www"

typedef NS_ENUM(NSUInteger, ThingMQTTErrorCode) {
    /// Publish | Subscribe | Unsubscribe failed, due to the MQTT channel not yet connected.
    ThingMQTTErrorCodeNotConnect = 6000,
    /// MQTT broker ack that subscription to the topic failed.
    ThingMQTTErrorCodeSubAckFail = 6001,
    /// Encode message data fail.
    ThingMQTTErrorCodeEncodeFail = 6002,
    /// Publish message fail due to a timeout for MQTT Broker Ack.
    ThingMQTTErrorCodePubAckTimeout = 6003,
    /// Publish message fail due to the topic not yet subscribed.
    ThingMQTTErrorCodePubFailNotSub = 6004,
    /// Publish message fail general reason. (see the `error.userInfo[NSUnderlyingErrorKey]`)
    ThingMQTTErrorCodePubFailGeneral = 6005,
    /// Subscribe fail general reason. (see the `error.userInfo[NSUnderlyingErrorKey]`)
    ThingMQTTErrorCodeSubFailGeneral = 6006,
};

@interface NSError (ThingMQTT)

+ (instancetype)thingsdk_MQTTError:(ThingMQTTErrorCode)code errorMsg:(nullable NSString *)msg;

+ (instancetype)thingsdk_MQTTError:(ThingMQTTErrorCode)code errorMsg:(nullable NSString *)msg reason:(nullable NSString *)reason;

+ (instancetype)thingsdk_MQTTError:(ThingMQTTErrorCode)code errorMsg:(nullable NSString *)msg innerError:(nullable NSError *)innerError;

@end

NS_ASSUME_NONNULL_END
