
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class ThingASActivatorServiceAction;
/*
 * This protocol is implemented by the business side
 * 1. Extension of scanning and pairing interfaces
 * 2. Replacement of the network configuration homepage
 */
@protocol ThingActivatorConfigurePlugProtocol <NSObject>
@optional
/*
 * Returns extended behavior for the network configuration process
 */
- (NSDictionary<NSNumber *, ThingASActivatorServiceAction *> *)configureActivatorActions;

/*
 * Returns custom network configuration homepage
 */
- (UIViewController *)customizeActivatorRootVc;
@end

NS_ASSUME_NONNULL_END
