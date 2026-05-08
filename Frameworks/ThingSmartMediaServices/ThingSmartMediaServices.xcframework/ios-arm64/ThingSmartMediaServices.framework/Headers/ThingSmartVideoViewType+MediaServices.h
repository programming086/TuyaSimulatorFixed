
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ThingSmartVideoViewType <NSObject>

/**
 [^en]
 set it YES, video image will stretch to fill the video view.
 [$en]

 */
@property (nonatomic, assign) BOOL scaleToFill;

/**
 [^en]
 video scale factory
 [$en]

 @param scaled [^en]scale factory[$en]
 */
- (void)thing_setScaled:(float)scaled;

/**
 [^en]
 video offset
 [$en]

 @param offset [^en]offset point[$en]
 */
- (void)thing_setOffset:(CGPoint)offset;

/**
 [^en]
 clear video content, and reset scale and offset
 [$en]

 */
- (void)thing_clear;

/**
 [^en]
 get a screenshot from current video frame
 [$en]


 
 @return [^en]screenshot image[$en]
 */
- (UIImage *)screenshot;

@optional

- (void)startPlay;
- (void)stopPlay;
- (void)glLayerRenderSize:(CGSize)size needLayout:(BOOL)needLayout;
/**
 Render YUV
 */
- (void)displayPixelBuffer:(CVPixelBufferRef)pixelBuffer;

- (void)displayPixelBuffer:(CVPixelBufferRef)pixelBuffer featureRect:(CGRect)rect;

- (void)thing_setRotate:(float)rotateZ;

- (void)enableFeatureTracking:(BOOL)enabled animated:(BOOL)animated;

- (void)thing_setStretchSize:(CGSize)stretchSize;

@end

NS_ASSUME_NONNULL_END
