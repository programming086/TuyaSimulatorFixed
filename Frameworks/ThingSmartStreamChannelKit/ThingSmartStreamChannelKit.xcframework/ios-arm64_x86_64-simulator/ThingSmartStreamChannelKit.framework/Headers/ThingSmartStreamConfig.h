
#import <Foundation/Foundation.h>
#import <ThingSmartUtil/ThingSmartUtil.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartStreamConfig : NSObject

ThingSDK_SINGLETON

@property (nonatomic, assign) BOOL verboseLog;
@property (nonatomic, assign) BOOL dumpRecAudioSend;
@property (nonatomic, assign) BOOL dumpRevAudioDecode;
@property (nonatomic, copy, readonly) NSString *baseDumpSendDir;
@property (nonatomic, copy, readonly) NSString *baseDumpRecvDir;

@end

NS_ASSUME_NONNULL_END
