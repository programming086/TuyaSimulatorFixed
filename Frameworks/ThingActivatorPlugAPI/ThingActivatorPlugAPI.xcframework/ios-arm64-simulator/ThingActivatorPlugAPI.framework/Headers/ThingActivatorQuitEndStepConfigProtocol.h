
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingActivatorQuitEndStepConfigProtocol <NSObject>
@property (nonatomic, weak, nullable) UIViewController *popToVc; // Pop to the specified VC when exiting the network configuration process, defaults to returning to the previous page
@end

NS_ASSUME_NONNULL_END
