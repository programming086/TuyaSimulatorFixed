
#import <Foundation/Foundation.h>
#import <ThingSmartMediaServices/ThingSmartMediaServices.h>
#import <ThingSmartCameraBase/ThingSmartMultiCameraViewType.h>

typedef NS_ENUM(NSInteger, ThingSmartCameraVideoViewScaleMode) {
    ThingSmartCameraVideoViewScaleModeAuto = -1,
    ThingSmartCameraVideoViewScaleModeFixedWidth,
    ThingSmartCameraVideoViewScaleModeFixedHeight
};

typedef NS_ENUM(NSUInteger, ThingSmartCameraVideoViewDoubleTapZoomMode) {
    ThingSmartCameraVideoViewDoubleTapZoomModeScaleToFill,  // exchange scale mode to fill the container,
    ThingSmartCameraVideoViewDoubleTapZoomModeToFixedScale, // zoom to the value of the video's aspect ratio
};

NS_ASSUME_NONNULL_BEGIN

@interface ThingSmartCameraVideoView : UIView<ThingSmartVideoViewType>

@property (nonatomic, weak) id<ThingSmartCameraVideoViewDelegate> delegate;
@property (nonatomic, weak) id<ThingSmartCameraVideoViewDataSource> dataSource;

@property (nonatomic, assign) BOOL allowsZoom;
@property (nonatomic, assign) CGFloat zoomScale;
@property (nonatomic, assign) CGFloat maxZoomScale;
@property (nonatomic, assign) ThingSmartCameraVideoViewScaleMode scaleMode;
@property (nonatomic, assign) ThingSmartCameraVideoViewDoubleTapZoomMode doubleTapZoomMode;

@property (nonatomic, assign) CGFloat rotateZ;
@property (nonatomic, assign) CGSize videoFrameSize;

@property (nonatomic, assign) BOOL enableSwipeGestures;
@property (nonatomic, assign) BOOL enableFeatureTracking;
@property (nonatomic, assign) BOOL enablePanoramaView;
@property (nonatomic, strong) NSDictionary *rockerDirectionsParams;

@property (nonatomic, assign, readonly) BOOL isScrolling;

@property (nonatomic, strong, nullable) NSDictionary *customParams;

- (instancetype)init;

- (void)renderPanoramaVideoFrame:(CVPixelBufferRef)pixelBuffer;

- (void)setZoomScale:(CGFloat)scale animated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
