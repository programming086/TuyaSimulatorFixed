
#import <UIKit/UIKit.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#import <ThingSmartMediaServices/ThingSmartMediaServices.h>

NS_ASSUME_NONNULL_BEGIN

@class ThingSmartMediaVideoView;
typedef void(^ThingVideoViewBackgroundWrappedHandler)(ThingSmartMediaVideoView *videoView);

@interface ThingSmartMediaVideoView : UIView <ThingSmartVideoViewType>

+ (void)configurateGlobalBackgroundWrappedHandler:(nullable ThingVideoViewBackgroundWrappedHandler)backgroundWrappedHandler;
@property (nonatomic, copy, nullable) ThingVideoViewBackgroundWrappedHandler backgroundWrappedHandler;

@property (nonatomic, assign) BOOL scaleToFill;

@property (nonatomic, assign) BOOL enableFeatureTracking;

- (void)startPlay;
- (void)stopPlay;

- (void)thing_setScaled:(float)scaled;

- (void)thing_setOffset:(CGPoint)offset;

- (void)thing_setRotate:(float)rotateZ;

- (void)thing_clear;

- (UIImage *)screenshot;

- (void)displayPixelBuffer:(CVPixelBufferRef)pixelBuffer;

- (void)displayPixelBuffer:(CVPixelBufferRef)pixelBuffer featureRect:(CGRect)rect;

- (void)enableFeatureTracking:(BOOL)enabled animated:(BOOL)animated;

- (void)glLayerRenderSize:(CGSize)size needLayout:(BOOL)needLayout;

@end

NS_ASSUME_NONNULL_END
