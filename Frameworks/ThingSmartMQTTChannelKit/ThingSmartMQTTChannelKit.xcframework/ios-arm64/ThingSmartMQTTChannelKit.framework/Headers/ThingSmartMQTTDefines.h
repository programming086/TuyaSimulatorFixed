
#import <Foundation/Foundation.h>
#import "ThingSmartMQTTConfigModel.h"

NS_ASSUME_NONNULL_BEGIN

/**
 The MQTT connection state.
 */
typedef NS_ENUM (NSInteger, ThingSmartMqttConnectState){
    ThingSmartMqttConnectStateCreated,
    ThingSmartMqttConnectStateConnecting,
    ThingSmartMqttConnectStateConnected,
    ThingSmartMqttConnectStateDisconnecting,
    ThingSmartMqttConnectStateClose,
    ThingSmartMqttConnectStateError,
};

@interface ThingSmartPublishMessageModel : NSObject

@property (nonatomic, strong) NSString          *devId;

@property (nonatomic, assign) NSTimeInterval    time; // The timestamp.
@property (nonatomic, assign) NSInteger         protocol; // The protocol.
@property (nonatomic, assign) double            pv; // The version.
@property (nonatomic, strong) NSDictionary      *body; // The body.
@property (nonatomic, strong) NSString          *localKey; // The local key.
@property (nonatomic, assign) NSInteger         publishS;// The sequence.
@property (nonatomic, assign) NSInteger         publishR;// The publishing ID.

@end

@interface ThingSmartResponseMessageModel : NSObject

@property (nonatomic, strong) NSString          *devId;
@property (nonatomic, strong) id                message;  // The mesh array.
@property (nonatomic, assign) NSInteger         protocol; // The protocol.
@property (nonatomic, strong) NSString          *type;
@property (nonatomic, assign) NSInteger         responseS;// The sequence.
@property (nonatomic, assign) NSInteger         responseR;// The response ID.
@property (nonatomic, assign) NSTimeInterval    time;

@end


NS_ASSUME_NONNULL_END
