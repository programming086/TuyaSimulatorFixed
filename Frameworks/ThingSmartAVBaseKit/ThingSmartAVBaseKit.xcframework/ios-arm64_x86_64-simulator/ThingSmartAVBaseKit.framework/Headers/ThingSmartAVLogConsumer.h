
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartAVLogConsumer <NSObject>

//offline log
- (void)offlineLogDidReceiveWithLogInfo:(NSDictionary *)logInfo;

// apm event
- (void)APMEventDidReceiveWithEventInfo:(NSDictionary *)eventInfo;

//full link event
- (void)fullLinkEventDidReceiveWithEventInfo:(NSDictionary *)eventInfo;

@end

NS_ASSUME_NONNULL_END
