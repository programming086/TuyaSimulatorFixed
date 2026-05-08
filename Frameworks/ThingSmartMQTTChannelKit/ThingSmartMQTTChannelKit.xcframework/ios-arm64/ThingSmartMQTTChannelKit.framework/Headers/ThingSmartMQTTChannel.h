
#import <Foundation/Foundation.h>
#import "NSError+ThingMQTT.h"
#import "ThingSmartMQTTConfigModel.h"
#import <ThingSmartUtil/ThingSmartUtil.h>
#import "ThingSmartMQTTDefines.h"

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString * const kThingMQTTUniTagDefualt;

@class ThingSmartMQTTChannel;

@protocol ThingSmartMQTTChannelDelegate <NSObject>
@optional
/// The callback of changes in the MQTT connection channel states.
/// @param mqttChannel channel
/// @param connectState  mqtt connect state
/// @param error error
- (void)mqttChannel:(ThingSmartMQTTChannel *)mqttChannel
       connectState:(ThingSmartMqttConnectState)connectState
              error:(nullable NSError *)error;

/// Reveives the MQTT data.
/// @param mqttChannel channel
/// @param message messge data
/// @param topic messge topic
- (void)mqttChannel:(ThingSmartMQTTChannel *)mqttChannel
  didReceiveMessage:(ThingSmartResponseMessageModel *)message
              topic:(NSString *)topic;

/// Reveives the MQTT origin data.
/// Notice: You need dencrypt the data.
/// @param mqttChannel channel
/// @param data origin data
- (void)mqttChannel:(ThingSmartMQTTChannel *)mqttChannel didRecevieOriginData:(NSData *)data topic:(NSString *)topic;

- (nullable ThingSmartMQTTConfigModel *)mqttChannelWillReconnectAndChangeConfig:(ThingSmartMQTTChannel *)mqttChannel __deprecated_msg("please use `reconnectConfiger` and `ThingSmartMQTTChannelReconnectConfigProtocol` to handle reconnectAndChangeConfig");
- (void)degradeHost:(NSString *)host __deprecated_msg("please use `reconnectConfiger` and `ThingSmartMQTTChannelReconnectConfigProtocol` to handle degradeHost");
@end


@protocol ThingSmartMQTTSubscribeCorrectProtocol <NSObject>
- (void)correctDeviceInfo:(NSString *)gwId;
@end

@protocol ThingSmartMQTTChannelReconnectConfigProtocol <NSObject>
@optional
///  The callback of changes in the MQTT before reconnect action.
///  If you return ThingSmartMQTTConfigModel's object, channel will use the passed configuration.
///  If you return nil, channel will use the lastest config.
- (nullable ThingSmartMQTTConfigModel *)mqttChannelWillReconnectAndChangeConfig:(ThingSmartMQTTChannel *)mqttChannel;

/// Host needs to be downgraded.
- (void)degradeHost:(NSString *)host;
@end

@interface ThingSmartMQTTChannel : NSObject

@property (nonatomic, assign) BOOL quicEnabled;

/// Special reconnect enable while App’s state is Background Active.
/// Default is NO.
@property (nonatomic, assign) BOOL backgroundEnabled;

@property (nonatomic, assign) BOOL eventPubAckEnable;
@property (nonatomic, assign) BOOL eventRevEnable;
// Default NO. If YES may causing more power consumption.
@property (nonatomic, assign) BOOL backgroundAutoRec;

@property (nonatomic, weak) id<ThingSmartMQTTSubscribeCorrectProtocol> deviceCorrector;
/// In multi-channel cases, the `reconnectConfiger` is recommended to handle reconnection.
@property (nonatomic, weak) id<ThingSmartMQTTChannelReconnectConfigProtocol> reconnectConfiger;

@property (nonatomic, strong, readonly) NSString *uniTag;

/// Get a MQTT channel instance by `uniTag`
/// If not contain this tag's object , will create a new one.
/// - Parameter uniTag: the universal tag.
+ (nullable instancetype)getChannelByUniTag:(NSString *)uniTag;

/// Get all MQTT channel instances.
+ (nullable NSArray<ThingSmartMQTTChannel *> *)getAllChannels;

/// Will return the  **uniTag** = **default** instance.
+ (instancetype)sharedInstance;

/**
 *  Connects to the MQTT host.
 *
 *  @param mqttConfig The configuration of the MQTT connection.
 */
- (void)startConnectToHostWithMqttConfig:(ThingSmartMQTTConfigModel *)mqttConfig;

/**
 *  Disconnects from the MQTT host.
 */
- (void)close;

/**
 *  The MQTT connection state.
 */
- (ThingSmartMqttConnectState)connectState;

/**
 *  Subscribes to a topic.
 *
 *  @param topic   The topic.
 *  @param success Called when the task is finished.
 *  @param failure Called when the task is interrupted by an error.
 */
- (void)subscribeToTopic:(NSString *)topic
                 devInfo:(nullable NSDictionary *)devInfo
                 success:(nullable ThingSuccessHandler)success
                 failure:(nullable ThingFailureError)failure;

/**
 *  Unsubscribes from a topic.
 *
 *  @param topic   The topic.
 *  @param success Called when the task is finished.
 *  @param failure Called when the task is interrupted by an error.
 */
- (void)unsubscribeToTopic:(NSString *)topic
                   success:(nullable ThingSuccessHandler)success
                   failure:(nullable ThingFailureError)failure;

/// Batch subscribe some topics.
///
/// @param topics The topic list.
/// @param devInfos Device info list.
/// @param handler Called when the task is interrupted by an error.
- (void)batchSubscribeTopics:(NSArray<NSString *> *)topics
                    devInfos:(nullable NSArray<NSDictionary *> *)devInfos
                     handler:(nullable void(^)(NSArray *sucTopics, NSArray *failTopics, NSError * _Nullable failError))handler;

/// Batch unsubscribe some topics.
///
/// @param topics The topic list.
/// @param success Called when the task is finished.
/// @param failure Called when the task is interrupted by an error.
- (void)batchUnsubscribeTopics:(NSArray<NSString *> *)topics
                       success:(nullable ThingSuccessHandler)success
                       failure:(nullable ThingFailureError)failure;

/**
 *  Publishes the MQTT data. (QoS = 1)
 *
 *  @param data    The data.
 *  @param topic   The topic.
 *  @param success Called when the task is finished.
 *  @param failure Called when the task is interrupted by an error.
 *  @return The message identifier of the published message. A value of `zero` is returned at the QoS level 0. A message identifier is returned at the QoS level 1 or 2.
 */
- (UInt16)publishMessage:(NSData *)data
                   topic:(NSString *)topic
                 success:(nullable ThingSuccessHandler)success
                 failure:(nullable ThingFailureError)failure;

/**
 *  Publishes the MQTT data. (Custom QoS = 0, 1, or 2)
 *
 *  @param data    The data.
 *  @param topic   The topic.
 *  @param qos     The QoS level. The value can be: 0 - AtMostOnce, 1 - AtLeastOnce, 2 - ExactlyOnce
 *  @param success Called when the task is finished.
 *  @param failure Called when the task is interrupted by an error.
 *  @return The message identifier of the published message. A value of `zero` is returned at the QoS level 0. A message identifier is returned at the QoS level 1 or 2.
 */
- (UInt16)publishMessage:(NSData *)data
                   topic:(NSString *)topic
                     qos:(int)qos
                 success:(ThingSuccessHandler)success
                 failure:(ThingFailureError)failure;

/**
 *  Publishes MQTT data.
 *
 *  @param messageModel The message model.
 *  @param topic        The topic.
 *  @param success      Called when the task is finished.
 *  @param failure      Called when the task is interrupted by an error.
 */
- (void)publishMessageWithMessageModel:(ThingSmartPublishMessageModel *)messageModel
                                 topic:(NSString *)topic
                               success:(nullable ThingSuccessHandler)success
                               failure:(nullable ThingFailureError)failure;

/**
 *  Adds an MQTT channel delegate.
 *
 *  @param delegate Delegate
 */
- (void)addDelegate:(id<ThingSmartMQTTChannelDelegate>)delegate;

/**
 *  Removes an MQTT channel delegate.
 *
 *  @param delegate The delegate.
 */
- (void)removeDelegate:(id<ThingSmartMQTTChannelDelegate>)delegate;


/// Whether MQTT channel has subscribed to a topic.
/// @param topic topic
- (BOOL)hasSubscribedTopic:(NSString *)topic;

@end

NS_ASSUME_NONNULL_END
