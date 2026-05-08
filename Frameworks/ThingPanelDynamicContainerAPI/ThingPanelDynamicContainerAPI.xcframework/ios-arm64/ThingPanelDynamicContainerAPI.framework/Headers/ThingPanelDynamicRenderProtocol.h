
#import <Foundation/Foundation.h>
#import "ThingPanelDynamicRenderConfig.h"
#import "ThingPanelDynamicGenericProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ThingPanelDynamicRenderProtocol <ThingPanelDynamicGenericProtocol>

/// render default image
/// - Parameters:
///   - image: image instance
///   - initialProps: initialProps
- (void)renderDefaultImage:(nonnull UIImage *)image initialProps:(nullable NSDictionary *)initialProps;

/// render smart miniprogram
/// - Parameters:
///   - url: miniprogram url, eg: godzilla://id/path
///   - initialProps: initialProps
- (void)renderMiniprogramWithUrl:(nonnull NSString *)url initialProps:(nullable NSDictionary *)initialProps;

/// render smart miniprogram
/// - Parameters:
///   - entryCode: entryCode
///   - initialProps: initialProps
- (void)renderMiniprogramWithEntryCode:(nonnull NSString *)entryCode initialProps:(nullable NSDictionary *)initialProps;

/// render smart miniprogram with render config
/// - Parameter renderConfig: ThingPanelDynamicRenderConfig instance
- (void)renderMiniprogramWithRenderConfig:(nonnull ThingPanelDynamicRenderConfig *)renderConfig;

/// render device panel
/// - Parameters:
///   - deviceId: deviceId
///   - groupId: groupId
///   - initialProps: initialProps
///   - contextProps: contextProps
- (void)renderPanelWithDeviceId:(nonnull NSString *)deviceId groupId:(nullable NSString *)groupId
                   initialProps:(nullable NSDictionary *)initialProps contextProps:(nullable NSDictionary *)contextProps;

@end

NS_ASSUME_NONNULL_END
