
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartSocketChannelConfig : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, strong) NSData *zigbeeActiveKey;
@property (nonatomic, strong) NSData *broadcastKey;
@property (nonatomic, strong) NSData *sendKey;

@end

NS_ASSUME_NONNULL_END
