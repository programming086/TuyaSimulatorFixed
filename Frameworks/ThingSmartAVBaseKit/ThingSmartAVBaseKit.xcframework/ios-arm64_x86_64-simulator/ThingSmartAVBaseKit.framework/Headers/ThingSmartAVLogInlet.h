
#import <Foundation/Foundation.h>

#import "ThingSmartAVLogMediator.h"
#import "ThingSmartAVLogConsumer.h"

NS_ASSUME_NONNULL_BEGIN

void ThingAVSDKLogger(NSInteger level, NSString *module, const char *file, const char *function, NSUInteger line, NSString *format, ...);

#undef ThingAVSDKLogDebug
#undef ThingAVSDKLogInfo
#undef ThingAVSDKLogWarn
#undef ThingAVSDKLogError
#undef ThingAVSDKLogP2PCamera
#undef ThingAVSDKLogP2PCameraError

#define ThingAVSDKLogDebug(...) \
    ThingAVSDKLogger(0, @"ThingSmartAVKit", "", __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define ThingAVSDKLogInfo(...) \
    ThingAVSDKLogger(1, @"ThingSmartAVKit", "", __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define ThingAVSDKLogWarn(...) \
    ThingAVSDKLogger(2, @"ThingSmartAVKit", "", __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define ThingAVSDKLogError(...) \
    ThingAVSDKLogger(3, @"ThingSmartAVKit", "", __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define ThingAVSDKLogP2PCamera(...) \
    ThingAVSDKLogger(4, @"ThingSmartAVKit", "", __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#define ThingAVSDKLogP2PCameraError(...) \
    ThingAVSDKLogger(5, @"ThingSmartAVKit", "", __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

@interface ThingSmartAVLogInlet : NSObject

@property (class, nonatomic, strong, readonly) ThingSmartAVLogInlet *logInlet;

@property (nonatomic, strong, readonly) id <ThingSmartAVLogMediator> logMediator;

/// Debug mode, default is false. Verbose log will print into console if opened, main switch.
@property (nonatomic, assign) BOOL debugMode;

/// AV log switch, default is false. Verbose AV log will print into console if opened, individual switch.
@property (nonatomic, assign) BOOL AVLogEnabled;

- (void)addLogConsumer:(id<ThingSmartAVLogConsumer>)logConsumer;
- (void)removeLogConsumer:(id<ThingSmartAVLogConsumer>)logConsumer;

@end

NS_ASSUME_NONNULL_END
