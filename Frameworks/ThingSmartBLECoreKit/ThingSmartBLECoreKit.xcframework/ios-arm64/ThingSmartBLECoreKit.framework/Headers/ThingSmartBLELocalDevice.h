
#import <Foundation/Foundation.h>
#import "ThingBLEDeviceInfoProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartBLELocalDevice : NSObject

@property (nonatomic, strong) id<ThingBLEDeviceInfoProtocol> deviceInfo;

- (void)disconnect;

@end

NS_ASSUME_NONNULL_END
