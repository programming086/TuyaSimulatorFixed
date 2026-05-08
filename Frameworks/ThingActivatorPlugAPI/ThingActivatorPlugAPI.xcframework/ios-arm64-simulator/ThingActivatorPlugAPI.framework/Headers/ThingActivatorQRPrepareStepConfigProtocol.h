
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void(^ThingActivatorBindTokenDeviceSuccess)(NSString *devId, NSString *uuid);;
@protocol ThingActivatorQRPrepareStepConfigProtocol <NSObject>
@property (nonatomic, copy, nullable) ThingActivatorBindTokenDeviceSuccess bindDeviceSuccess;
@end

NS_ASSUME_NONNULL_END
