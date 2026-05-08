
#import <Foundation/Foundation.h>
#import "ThingPanelDynamicRenderProtocol.h"
#import "ThingPanelDynamicContainerDelegate.h"

typedef UIViewController<ThingPanelDynamicRenderProtocol>* ThingPanelDynamicController;

NS_ASSUME_NONNULL_BEGIN

@protocol ThingPanelDynamicContainerProtocol <NSObject>

/// generate a new dynamic container instance
/// - Parameter containerTag: container tag flag
- (nonnull ThingPanelDynamicController)getDynamicContainerWithContainerTag:(nullable NSString *)containerTag;

/// generate a new dynamic container instance
/// - Parameter delegate: container's delegate
- (nonnull ThingPanelDynamicController)getDynamicContainerWithDelegate:(nullable id<ThingPanelDynamicContainerDelegate>)delegate;

/// generate a new dynamic container instance
/// - Parameters:
///   - delegate: container's delegate
///   - containerTag: container tag flag
- (nonnull ThingPanelDynamicController)getDynamicContainerWithDelegate:(nullable id<ThingPanelDynamicContainerDelegate>)delegate containerTag:(nullable NSString *)containerTag;

/// find the dynamic container which containerTag is match
/// - Parameter containerTag: container tag flag
- (nullable ThingPanelDynamicController)findDynamicContainerWithContainerTag:(nonnull NSString *)containerTag;

@end

NS_ASSUME_NONNULL_END
