
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingActivatorBTSearchDeviceStepConfigProtocol <NSObject>
@property (nonatomic, assign) NSTimeInterval timeout;//Timeout time, default 120 seconds
@property (nonatomic, assign) NSTimeInterval preTimeout;//Pre-timeout, default 10 seconds
@property (nonatomic, strong) NSArray *cycleTitles;
@end

NS_ASSUME_NONNULL_END
