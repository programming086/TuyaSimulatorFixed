
#import <Foundation/Foundation.h>

@class ThingSmartMQTTMessageModel;

typedef void(^ThingMQTTMessageCallback)(ThingSmartMQTTMessageModel *mesageModel);

@interface ThingCameraP2pCommandProxy : NSObject

+ (instancetype)sharedInstance;

- (void)setMQTTCallback:(ThingMQTTMessageCallback)callback forProtocol:(int)protocol deviceId:(NSString *)devId;

- (void)removeMQTTCallbackForProtocol:(int)protocol deviceId:(NSString *)devId;


@end
