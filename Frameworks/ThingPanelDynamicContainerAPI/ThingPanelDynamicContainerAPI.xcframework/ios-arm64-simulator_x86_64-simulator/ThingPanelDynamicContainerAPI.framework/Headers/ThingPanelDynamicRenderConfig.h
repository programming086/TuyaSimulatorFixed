
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSInteger ThingPanelDynamicRenderMode;
FOUNDATION_EXPORT ThingPanelDynamicRenderMode const ThingPanelDynamicRenderModeEmbed;
FOUNDATION_EXPORT ThingPanelDynamicRenderMode const ThingPanelDynamicRenderModeCover;

@interface ThingPanelDynamicRenderConfig : NSObject

/**
 * url or entryCode must be set, but not both, default is NO
 */
@property (nonatomic, assign) BOOL useSameContainer;

/**
 * when rendering, always show loading page, default is NO
 */
@property (nonatomic, assign) BOOL alwaysShowLoading;
@property (nonatomic, copy, nullable) NSString *url;
@property (nonatomic, copy, nullable) NSString *entryCode;
@property (nonatomic, copy, nullable) NSDictionary *initialProps;
@property (nonatomic, copy, nullable) NSString *backgroundDarkImage;
@property (nonatomic, copy, nullable) NSString *backgroundLightImage;

/**
 * render mode, default is ThingPanelDynamicRenderModeEmbed
 */
@property (nonatomic, assign) ThingPanelDynamicRenderMode renderMode;

@end

NS_ASSUME_NONNULL_END
