
#import <Foundation/Foundation.h>
#import "ThingSmartMQTTChannel.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartMQTTIntercepterInfo <NSObject>
/// real mqtt channel uniTag
@property (nonatomic, strong) NSString *uniTag;


/**
 ** {
 **     "uniTag1" : ["topic1", "topic2"],
 **     "uniTag2" : ["topic3", "topic1"]
 ** };
 */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSArray *> *uniTagForTopics;

@property (nonatomic, assign) BOOL isNeedBothSubscribe __deprecated_msg("please use `uniTagForTopics`");
@end

@protocol ThingSmartMQTTIntercepter <NSObject>

/// Subscribes from some topics.
/// use `uniTagForTopics`
+ (id<ThingSmartMQTTIntercepterInfo>)intercepter_batchSubscribeToTopics:(NSArray *)topics;

/// Unsubscribes from some topics.
/// use `uniTagForTopics`
+ (id<ThingSmartMQTTIntercepterInfo>)intercepter_batchUnsubscribeToTopics:(NSArray *)topics;

/// Publishes the MQTT data.
/// use `uniTag`
+ (id<ThingSmartMQTTIntercepterInfo>)intercepter_publishMessage:(NSData *)data topic:(NSString *)topic;

/// Publishes MQTT data.
/// use `uniTag`
+ (id<ThingSmartMQTTIntercepterInfo>)intercepter_publishMessageWithMessageModel:(ThingSmartPublishMessageModel *)messageModel topic:(NSString *)topic;

/// Adds an MQTT channel delegate.
/// use `uniTag`
+ (id<ThingSmartMQTTIntercepterInfo>)intercepter_addDelegate:(id<ThingSmartMQTTChannelDelegate>)delegate;

/// Removes an MQTT channel delegate.
/// use `uniTag`
+ (id<ThingSmartMQTTIntercepterInfo>)intercepter_removeDelegate:(id<ThingSmartMQTTChannelDelegate>)delegate;

/// Subscribes from a topic.
+ (id<ThingSmartMQTTIntercepterInfo>)intercepter_subscribeToTopic:(NSString *)topic __deprecated_msg("please impl `+intercepter_batchSubscribeToTopics:`");

/// Unsubscribes from a topic.
+ (id<ThingSmartMQTTIntercepterInfo>)intercepter_unsubscribeToTopic:(NSString *)topic __deprecated_msg("please impl `+intercepter_batchUnsubscribeToTopics:`");

@end

@interface ThingSmartMQTTChannel(Intercepter)
+ (void)addIntercepter:(Class<ThingSmartMQTTIntercepter>)obj;
+ (void)removeIntercepter:(Class<ThingSmartMQTTIntercepter>)obj;
@end


NS_ASSUME_NONNULL_END
