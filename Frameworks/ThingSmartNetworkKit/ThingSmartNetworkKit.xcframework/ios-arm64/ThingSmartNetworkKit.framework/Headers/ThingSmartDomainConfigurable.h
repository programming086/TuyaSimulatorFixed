
#ifndef ThingSmartApiConfigurable_h
#define ThingSmartApiConfigurable_h

@protocol ThingSmartDomainConfigurable <NSObject,NSCopying>

@property(nonatomic, strong) NSString  *aispeechHttpsUrl;
@property(nonatomic, strong) NSString  *gwApiUrl;
@property(nonatomic, strong) NSString  *gwMqttUrl;
@property(nonatomic, strong) NSString  *mobileApiUrl;
@property(nonatomic, strong) NSString  *mobileMqttUrl;
@property(nonatomic, strong) NSString  *mobileMqttsUrl;
@property(nonatomic, strong) NSString  *mobileMediaMqttUrl;
@property(nonatomic, strong) NSString  *pxApiUrl;
@property(nonatomic, strong) NSString  *regionCode;
@property(nonatomic, strong) NSString  *mqttQuicUrl;
@property(nonatomic, strong) NSString  *mobileQuicUrl;
@property(nonatomic, strong) NSString  *thingAppUrl;
@property(nonatomic, strong) NSString  *thingImagesUrl;
@property(nonatomic, strong) NSString  *fusionUrl;

@end

@interface ThingSmartSDK (DomainConfigurable)

@property (nonatomic, strong, readonly) id<ThingSmartDomainConfigurable> domain;

@property (nonatomic, strong, readonly) NSString *ecode;
@property (nonatomic, strong, readonly) NSString *sid;

@end

@protocol ThingSmartSDKEvent <NSObject>

- (void)didLoadFinish;

- (void)didReceivedSessionInvalidEvent;

@end

@interface ThingSmartSDK (Event)

@property (nonatomic, strong, readonly) id<ThingSmartSDKEvent> eventHandler;

@end

#endif /* ThingSmartApiConfigurable_h */
