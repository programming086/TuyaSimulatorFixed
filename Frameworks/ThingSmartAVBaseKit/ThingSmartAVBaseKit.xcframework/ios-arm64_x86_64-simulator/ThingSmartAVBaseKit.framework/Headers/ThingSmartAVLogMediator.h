
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ThingSmartAVLogType) {
    ThingSmartAVLogTypeOfflieLog,
    ThingSmartAVLogTypeAPMEvent,
    ThingSmartAVLogTypeFullLink,
    ThingSmartAVLogTypeCamearOnlineLog,
    ThingSmartAVLogTypeCameraOnlineErrorLog
};

@protocol ThingSmartAVLogTaskControl <NSObject>

@required
- (BOOL)allowP2PLogUploading;

@end

@protocol ThingSmartAVAPMEventDataSource <NSObject>

@required
- (nullable NSDictionary *)appendedStreamEventParamsForEventInfo:(NSDictionary *)eventInfo;

@end

@protocol ThingSmartAVLogMediator <NSObject>

@required
- (BOOL)excuteLogTaskWithLogType:(ThingSmartAVLogType)logType logInfo:(NSDictionary *)logInfo;

@optional
@property (nonatomic, strong) id <ThingSmartAVLogTaskControl> logTaskControl;
@property (nonatomic, strong) id <ThingSmartAVAPMEventDataSource> eventDataSource;

- (void)p2pSendMqData:(NSString *)signal;
- (void)p2pReceiveMqData:(NSDictionary *)dict;

@end


NS_ASSUME_NONNULL_END
