
#import <Foundation/Foundation.h>
#import <ThingSmartDeviceCoreKit/ThingSmartDeviceCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingGroupHandleExtensionAPI <NSObject>

#pragma mark - 可定制实现

- (void)gotoGroupPanel:(ThingSmartGroupModel *)group;

@end

NS_ASSUME_NONNULL_END
